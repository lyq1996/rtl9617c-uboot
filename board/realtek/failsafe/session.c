// SPDX-License-Identifier: GPL-2.0-only
/*
 * Write sessions of the web failsafe.
 *
 * Every image the page sends - system, U-Boot, factory data, a UBI volume, an
 * MTD partition, the whole NAND or a RAM boot image - goes through one
 * session: open (checked before any data moves), chunks in order, then commit
 * or abort. Streaming targets are written as each chunk arrives, so only one
 * chunk is held in RAM; the small images that must be checked as a whole are
 * staged in RAM first.
 */
#include <config.h>
#include <command.h>
#include <env.h>
#include <image.h>
#include <malloc.h>
#include <memalign.h>
#include <mapmem.h>
#include <mtd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ubi_volume.h>
#include <vsprintf.h>
#include <u-boot/crc.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include <linux/libfdt.h>
#include "fip.h"
#include "led.h"
#include "recovery.h"
#include "service.h"
#include "session.h"
#include "storage.h"

enum write_op {
	W_FIRMWARE,
	W_UBOOT,
	W_FACTORY,
	W_UBI,
	W_MTD,
	W_NAND,
	W_RAM,
};

static const struct {
	const char *name;
	bool staged;
} write_ops[] = {
	[W_FIRMWARE]	= { "firmware", false },
	[W_UBOOT]	= { "uboot", true },
	[W_FACTORY]	= { "factory", true },
	[W_UBI]		= { "ubi", false },
	[W_MTD]		= { "mtd", false },
	[W_NAND]	= { "nand", false },
	[W_RAM]		= { "ram", true },
};

enum write_stage {
	W_NONE,
	W_OPENING,
	W_OPEN,
	W_FAILED,
	W_DONE,
};

static const char *const write_stages[] = {
	"none", "opening", "open", "failed", "done",
};

static struct {
	u32 id;
	enum write_op op;
	enum write_stage stage;
	char target[64];
	char staging[72];
	size_t size, next, chunk;
	u8 *buf;
	bool receiving;
	size_t pending;
	bool updating;
	struct mtd_info *mtd;
	u8 *boot;
	u32 crc;
	ulong touched;
	char error[192];
} w;

static u32 write_ids;

static const struct rtk_recovery_layout *layout(void)
{
	return rtk_recovery_layout();
}

static bool staged(void)
{
	return write_ops[w.op].staged;
}

static int fail(int ret, const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	vsnprintf(w.error, sizeof(w.error), fmt, args);
	va_end(args);
	w.stage = W_FAILED;

	return fs_fail(ret, "%s", w.error);
}

static void write_release(void)
{
	fs_mem_free(w.buf);
	w.buf = NULL;
	free(w.boot);
	w.boot = NULL;
	if (w.mtd)
		put_mtd_device(w.mtd);
	w.mtd = NULL;
	w.receiving = false;
	w.pending = 0;
}

static size_t volume_reserved(const char *name)
{
	size_t reserved = 0;

	if (!name || !ubi_volume_exists(name) ||
	    ubi_volume_get_size(name, NULL, &reserved))
		return 0;

	return reserved;
}

static int remove_volume(const char *name)
{
	if (!name || !ubi_volume_exists(name))
		return 0;
	printf("Removing volume %s.\n", name);

	return ubi_volume_remove(name) ? -EIO : 0;
}

static const struct rtk_ubi_volume *board_volume(const char *name)
{
	const struct rtk_recovery_layout *l = layout();
	unsigned int i;

	for (i = 0; name && i < l->nr_volumes; i++)
		if (l->volumes[i].policy == RTK_VOL_DATA &&
		    !l->volumes[i].dynamic && !strcmp(l->volumes[i].name, name))
			return &l->volumes[i];

	return NULL;
}

static int open_firmware(void)
{
	const struct rtk_recovery_layout *l = layout();
	u64 room;

	if (rtk_ubi_ensure())
		return fail(-ENODEV, "UBI on %s cannot be attached; rebuild UBI first",
			    l->boot->ubi_part);
	snprintf(w.staging, sizeof(w.staging), "%s.new", l->boot->firmware_volume);
	room = ubi_free_bytes() + volume_reserved(l->boot->firmware_volume) +
	       volume_reserved(l->boot->overlay_volume) +
	       volume_reserved(w.staging);
	if (w.size > room)
		return fail(-ENOSPC, "a %zu byte system does not fit; UBI can hold %llu bytes",
			    w.size, (unsigned long long)room);

	return 0;
}

static int open_volume(void)
{
	if (rtk_ubi_ensure())
		return fail(-ENODEV, "UBI on %s cannot be attached; rebuild UBI first",
			    layout()->boot->ubi_part);
	if (!ubi_volume_exists(w.target))
		return fail(-ENOENT, w.op == W_FACTORY ?
			    "UBI has no %s volume; rebuild UBI first" :
			    "UBI has no volume %s", w.target);
	if (w.size > volume_reserved(w.target))
		return fail(-ENOSPC, "%zu bytes do not fit in volume %s (%zu bytes)",
			    w.size, w.target, volume_reserved(w.target));

	return 0;
}

static int open_mtd(void)
{
	const struct rtk_recovery_layout *l = layout();
	struct mtd_info *mtd;

	mtd_probe_devices();
	mtd = get_mtd_device_nm(w.target);
	if (IS_ERR(mtd))
		return fail(-ENODEV, "no MTD device %s", w.target);
	w.mtd = mtd;
	if (w.op == W_MTD && !mtd_is_partition(mtd))
		return fail(-EINVAL, "%s is the whole device; use the full NAND restore",
			    mtd->name);
	if (w.op == W_MTD && !strcmp(mtd->name, l->boot_mtd))
		return fail(-EPERM, "%s is written by the U-Boot update or a full NAND restore",
			    mtd->name);
	if (w.op == W_NAND && mtd_is_partition(mtd))
		return fail(-EINVAL, "%s is not a whole device", mtd->name);
	if (w.size != mtd->size)
		return fail(-EINVAL, "the image must be exactly %llu bytes, the size of %s",
			    (unsigned long long)mtd->size, mtd->name);
	if (!mtd->erasesize || w.chunk % mtd->erasesize ||
	    w.size % mtd->erasesize)
		return fail(-EINVAL, "%s cannot be written in %zu byte chunks",
			    mtd->name, w.chunk);
	if (w.op == W_NAND) {
		w.boot = malloc_cache_aligned(RTK_BOOT_SIZE);
		if (!w.boot)
			return fail(-ENOMEM, "no memory for the boot area");
	}
	if ((w.op == W_NAND || !strcmp(mtd->name, l->boot->ubi_part)) &&
	    rtk_ubi_attached()) {
		puts("Detaching UBI before the raw write.\n");
		rtk_ubi_detach(true);
	}

	return 0;
}

static int write_open(void)
{
	size_t want = staged() ? w.size : w.chunk;
	int ret;

	w.buf = fs_mem_alloc(want);
	if (!w.buf)
		ret = fail(-ENOMEM, "not enough free RAM for %zu bytes (largest free block %zu bytes)",
			   want, fs_mem_capacity());
	else if (w.op == W_FIRMWARE)
		ret = open_firmware();
	else if (w.op == W_FACTORY || w.op == W_UBI)
		ret = open_volume();
	else if (w.op == W_MTD || w.op == W_NAND)
		ret = open_mtd();
	else
		ret = 0;
	if (ret) {
		write_release();
		w.stage = W_NONE;
		return ret;
	}
	w.stage = W_OPEN;
	w.touched = get_timer(0);
	printf("Ready to receive %zu bytes (%s %s).\n", w.size,
	       write_ops[w.op].name, w.target);

	return 0;
}

int fs_write_open(const char *op, const char *target, u64 size,
		  struct httpd_reply *reply)
{
	const struct rtk_recovery_layout *l = layout();
	const struct rtk_ubi_volume *spec;
	unsigned int i;
	u32 job;

	for (i = 0; i < ARRAY_SIZE(write_ops); i++)
		if (op && !strcmp(op, write_ops[i].name))
			break;
	if (i == ARRAY_SIZE(write_ops)) {
		httpd_reply_error(reply, 400, "unknown write operation");
		return -EINVAL;
	}
	if (!size || size > SIZE_MAX) {
		httpd_reply_error(reply, 400, "invalid image size");
		return -EINVAL;
	}
	switch (i) {
	case W_FIRMWARE:
		target = l->boot->firmware_volume;
		break;
	case W_UBOOT:
		if (size != RTK_BOOT_SIZE) {
			httpd_reply_error(reply, 400,
					  "a U-Boot image is the whole %s: %u bytes, not %llu",
					  l->boot_mtd, RTK_BOOT_SIZE,
					  (unsigned long long)size);
			return -EINVAL;
		}
		target = l->boot_mtd;
		break;
	case W_NAND:
		if (size != l->flash_size) {
			httpd_reply_error(reply, 400,
					  "a full NAND image is exactly %zu bytes, not %llu",
					  l->flash_size, (unsigned long long)size);
			return -EINVAL;
		}
		target = l->nand_dev;
		break;
	case W_FACTORY:
		spec = board_volume(target);
		if (!spec) {
			httpd_reply_error(reply, 400,
					  "%s is not a board data volume",
					  target ? target : "");
			return -EINVAL;
		}
		if (size != spec->size) {
			httpd_reply_error(reply, 400,
					  "the %s image must be exactly %llu bytes, not %llu",
					  spec->name,
					  (unsigned long long)spec->size,
					  (unsigned long long)size);
			return -EINVAL;
		}
		break;
	case W_RAM:
		target = "";
		break;
	default:
		if (!rtk_storage_name_valid(target)) {
			httpd_reply_error(reply, 400, "invalid target");
			return -EINVAL;
		}
		break;
	}

	write_release();
	memset(&w, 0, sizeof(w));
	w.id = ++write_ids;
	w.op = i;
	w.stage = W_OPENING;
	strlcpy(w.target, target, sizeof(w.target));
	w.size = size;
	w.chunk = FS_CHUNK;
	w.touched = get_timer(0);
	job = fs_job_start("write-open", write_open, false);
	if (!job)
		w.stage = W_NONE;
	fs_reply_job(reply, job, w.id, w.chunk);

	return job ? 0 : -EBUSY;
}

static int session_check(u32 id, struct httpd_reply *reply)
{
	if (!w.id || id != w.id || w.stage == W_NONE || w.stage == W_DONE) {
		httpd_reply_error(reply, 409, "write session %u is not open", id);
		return -ENOENT;
	}
	if (w.stage == W_FAILED) {
		httpd_reply_error(reply, 409, "%s", w.error);
		return -EIO;
	}
	if (w.stage != W_OPEN || w.receiving || fs_job_active()) {
		httpd_reply_error(reply, 409,
				  "write session %u is busy; try again", id);
		return -EBUSY;
	}

	return 0;
}

int fs_write_chunk_begin(u32 id, u64 offset, size_t length,
			 struct httpd_reply *reply, void **dst)
{
	int ret = session_check(id, reply);

	if (ret)
		return ret;
	if (offset != w.next) {
		httpd_reply_error(reply, 409, "expected offset %zu, not %llu",
				  w.next, (unsigned long long)offset);
		return -EINVAL;
	}
	if (!length || length > w.chunk || length > w.size - w.next ||
	    (w.mtd && length % w.mtd->erasesize)) {
		httpd_reply_error(reply, 400, "invalid chunk of %zu bytes",
				  length);
		return -EINVAL;
	}
	*dst = staged() ? w.buf + w.next : w.buf;
	w.receiving = true;
	w.pending = length;
	w.touched = get_timer(0);

	return 0;
}

static int ubi_begin(const char *name, const u8 *data, size_t len)
{
	w.updating = true;
	if (ubi_volume_begin_write((char *)name, (void *)data, len, w.size))
		return fail(-EIO, "starting the update of %s failed", name);

	return 0;
}

static int ubi_more(const char *name, const u8 *data, size_t len)
{
	if (ubi_volume_continue_write((char *)name, (void *)data, len))
		return fail(-EIO, "writing %s at %zu failed", name, w.next);

	return 0;
}

static int firmware_begin(const u8 *data, size_t len)
{
	const struct rtk_recovery_layout *l = layout();

	if (fdt_check_header(data) || fdt_totalsize(data) > w.size)
		return fail(-EINVAL, "not a FIT image: no device tree header at the start");
	if (remove_volume(w.staging) || remove_volume(l->boot->overlay_volume) ||
	    remove_volume(l->boot->firmware_volume))
		return fail(-EIO, "removing the old system failed");
	if (ubi_volume_create(w.staging, w.size, true))
		return fail(-ENOSPC, "creating volume %s failed", w.staging);

	return ubi_begin(w.staging, data, len);
}

static int nand_chunk(const u8 *data, size_t at, size_t len,
		      const struct storage_job *ctx)
{
	size_t skip = 0;
	int ret;

	if (at < RTK_BOOT_SIZE) {
		if (at || len < RTK_BOOT_SIZE)
			return fail(-EINVAL, "the first chunk must hold the whole boot area");
		memcpy(w.boot, data, RTK_BOOT_SIZE);
		if (rtk_validate_loader(w.boot, RTK_BOOT_SIZE))
			return fail(-EINVAL, "the boot area of this image does not belong to this device");
		skip = RTK_BOOT_SIZE;
	}
	if (len == skip)
		return 0;
	ret = rtk_mtd_write(w.mtd, at + skip, data + skip, len - skip, ctx,
			    at + skip, w.size, true);
	if (ret)
		return fail(ret, "writing %s at 0x%zx failed (%d)", w.target,
			    at + skip, ret);

	return 0;
}

static int write_chunk(void)
{
	const u8 *data = staged() ? w.buf + w.next : w.buf;
	size_t at = w.next, len = w.pending;
	struct storage_job ctx;
	int ret = 0;

	fs_job_context(&ctx);
	switch (w.op) {
	case W_FIRMWARE:
		ret = at ? ubi_more(w.staging, data, len) :
			   firmware_begin(data, len);
		break;
	case W_UBI:
		ret = at ? ubi_more(w.target, data, len) :
			   ubi_begin(w.target, data, len);
		break;
	case W_MTD:
		ret = rtk_mtd_write(w.mtd, at, data, len, &ctx, at, w.size,
				    true);
		if (ret)
			ret = fail(ret, "writing %s at 0x%zx failed (%d)",
				   w.target, at, ret);
		break;
	case W_NAND:
		ret = nand_chunk(data, at, len, &ctx);
		break;
	default:
		break;
	}
	w.pending = 0;
	w.touched = get_timer(0);
	if (ret)
		return ret;
	if (w.op == W_FIRMWARE || w.op == W_UBI)
		w.crc = crc32_wd(w.crc, data, len, CHUNKSZ_CRC32);
	w.next += len;
	fs_job_progress(w.next, w.size);

	return 0;
}

void fs_write_chunk_end(struct httpd_reply *reply, bool complete)
{
	u32 job = 0;

	w.receiving = false;
	w.touched = get_timer(0);
	if (w.stage != W_OPEN) {
		httpd_reply_error(reply, 409, "write session %u is not open",
				  w.id);
		return;
	}
	if (!complete) {
		w.pending = 0;
		httpd_reply_error(reply, 400,
				  "chunk incomplete; send offset %zu again",
				  w.next);
		return;
	}
	job = fs_job_start("write-chunk", write_chunk, !staged());
	if (!job)
		w.pending = 0;
	fs_reply_job(reply, job, w.id, 0);
}

static int verify_volume(const char *name, const struct storage_job *ctx)
{
	u32 crc;
	int ret;

	ret = rtk_ubi_crc(name, w.size, w.buf, w.chunk, &crc, ctx);
	if (ret)
		return fail(ret, "reading %s back failed (%d)", name, ret);
	if (crc != w.crc)
		return fail(-EIO, "%s read back with CRC %08x, sent %08x",
			    name, crc, w.crc);

	return 0;
}

static int commit_firmware(const struct storage_job *ctx)
{
	const struct rtk_recovery_layout *l = layout();
	size_t head = min_t(size_t, w.size, w.chunk), total;
	void *fit;
	int ret;

	ret = verify_volume(w.staging, ctx);
	if (ret)
		return ret;
	if (ubi_volume_read_quiet(w.staging, (char *)w.buf, 0, head))
		return fail(-EIO, "reading %s back failed", w.staging);
	total = fdt_totalsize(w.buf);
	fit = w.buf;
	if (total > head) {
		fit = fs_mem_alloc(total);
		if (fit && ubi_volume_read_quiet(w.staging, fit, 0, total)) {
			fs_mem_free(fit);
			return fail(-EIO, "reading %s back failed", w.staging);
		}
	}
	if (fit) {
		ret = fit_check_format(fit, total);
		if (fit != w.buf)
			fs_mem_free(fit);
		if (ret)
			return fail(-EINVAL, "the image is not a bootable FIT");
	} else {
		printf("The FIT structure (%zu bytes) does not fit in free RAM; only its header was checked.\n",
		       total);
	}
	if (remove_volume(l->boot->firmware_volume))
		return fail(-EIO, "removing the old %s failed", l->boot->firmware_volume);
	if (ubi_volume_rename(w.staging, l->boot->firmware_volume))
		return fail(-EIO, "renaming %s to %s failed", w.staging,
			    l->boot->firmware_volume);
	w.updating = false;
	printf("System written to %s (%zu bytes).\n", l->boot->firmware_volume,
	       w.size);

	return 0;
}

static int boot_ram(void)
{
	ulong addr = map_to_sysmem(w.buf);

	if (fit_check_format(w.buf, w.size))
		return fail(-EINVAL, "the image is not a bootable FIT");
	env_set_hex("unzip_src", addr);
	run_commandf("bootm 0x%lx", addr);

	return fail(-EIO, "booting the image from RAM failed");
}

static int write_commit(void)
{
	struct storage_job ctx;
	int ret = 0;

	fs_job_context(&ctx);
	switch (w.op) {
	case W_FIRMWARE:
		ret = commit_firmware(&ctx);
		break;
	case W_UBI:
		ret = verify_volume(w.target, &ctx);
		if (!ret)
			printf("Volume %s written and verified (%zu bytes).\n",
			       w.target, w.size);
		break;
	case W_MTD:
		printf("%s written and verified (%zu bytes).\n", w.target,
		       w.size);
		break;
	case W_NAND:
		ctx.progress = NULL;
		ret = rtk_install_boot(w.boot, RTK_BOOT_SIZE, &ctx);
		if (!ret)
			puts("Full NAND restore complete; the boot area was written last.\n");
		break;
	case W_UBOOT:
		ret = rtk_install_boot(w.buf, w.size, &ctx);
		break;
	case W_FACTORY:
		ret = rtk_ubi_write(w.target, w.buf, w.size, &ctx);
		if (!ret)
			printf("%s written and verified (%zu bytes).\n",
			       w.target, w.size);
		break;
	case W_RAM:
		ret = boot_ram();
		break;
	}
	if (ret) {
		if (w.stage != W_FAILED)
			fail(ret, "%s failed (%d)", write_ops[w.op].name, ret);
		return ret;
	}
	w.updating = false;
	write_release();
	w.stage = W_DONE;

	return 0;
}

int fs_write_commit(u32 id, struct httpd_reply *reply)
{
	int ret = session_check(id, reply);
	u32 job;

	if (ret)
		return ret;
	if (w.next != w.size) {
		httpd_reply_error(reply, 409, "only %zu of %zu bytes received",
				  w.next, w.size);
		return -EINVAL;
	}
	job = fs_job_start("write-commit", write_commit, w.op != W_RAM);
	fs_reply_job(reply, job, w.id, 0);

	return job ? 0 : -EBUSY;
}

static void write_cleanup(void)
{
	const struct rtk_recovery_layout *l = layout();

	if (w.updating && w.op == W_FIRMWARE) {
		remove_volume(w.staging);
		if (!ubi_volume_exists(l->boot->firmware_volume))
			puts("No system is installed now; upload a firmware again.\n");
	} else if (w.updating) {
		printf("Volume %s was only partly written; write it again.\n",
		       w.target);
	} else if ((w.op == W_MTD || w.op == W_NAND) && w.next) {
		printf("%s was only partly written (%zu of %zu bytes).\n",
		       w.target, w.next, w.size);
	}
	w.updating = false;
	write_release();
	w.stage = W_NONE;
	printf("Write session %u closed.\n", w.id);
}

static int write_abort(void)
{
	write_cleanup();

	return 0;
}

int fs_write_abort(u32 id, struct httpd_reply *reply)
{
	u32 job;

	if (!w.id || id != w.id || w.stage == W_NONE || w.stage == W_DONE) {
		httpd_reply_json(reply, 200, "{\"job\":0}");
		return 0;
	}
	if (w.receiving || fs_job_active()) {
		httpd_reply_error(reply, 409,
				  "write session %u is busy; abort again when the current step ends",
				  id);
		return -EBUSY;
	}
	job = fs_job_start("write-abort", write_abort, false);
	fs_reply_job(reply, job, w.id, 0);

	return job ? 0 : -EBUSY;
}

bool fs_write_active(void)
{
	return w.stage == W_OPENING || w.stage == W_OPEN ||
	       w.stage == W_FAILED;
}

void fs_write_status(struct fs_write_state *st)
{
	st->id = w.id;
	st->op = w.id ? write_ops[w.op].name : "";
	st->target = w.target;
	st->state = write_stages[w.stage];
	st->size = w.size;
	st->next = w.next;
	st->chunk = w.chunk;
	st->error = w.error;
}

void fs_write_poll(void)
{
	if ((w.stage == W_OPEN || w.stage == W_FAILED) && !w.receiving &&
	    !fs_job_active() && get_timer(w.touched) > FS_SESSION_TIMEOUT) {
		printf("Write session %u timed out.\n", w.id);
		write_cleanup();
	}
}

void fs_write_stop(void)
{
	if (fs_write_active())
		write_cleanup();
	write_release();
}
