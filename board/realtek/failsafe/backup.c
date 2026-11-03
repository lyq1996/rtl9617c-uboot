// SPDX-License-Identifier: GPL-2.0-only
/*
 * Backups of the web failsafe: one MTD device or UBI volume, sent to the
 * browser as a single download that is read from Flash while it streams.
 */
#include <config.h>
#include <malloc.h>
#include <memalign.h>
#include <mtd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ubi_volume.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include "backup.h"
#include "service.h"
#include "storage.h"

#define BACKUP_CACHE	(128 * 1024)

enum backup_stage {
	B_NONE,
	B_PREPARING,
	B_READY,
	B_STREAMING,
};

static const char *const backup_stages[] = {
	"none", "preparing", "ready", "streaming",
};

static struct {
	u32 id;
	enum backup_stage stage;
	bool ubi;
	char target[64];
	char name[96];
	u64 size, sent;
	struct mtd_info *mtd;
	u8 *cache;
	u64 cache_at;
	size_t cache_len;
	ulong touched;
} b;

static u32 backup_ids;

static void backup_release(void)
{
	free(b.cache);
	b.cache = NULL;
	b.cache_len = 0;
	if (b.mtd)
		put_mtd_device(b.mtd);
	b.mtd = NULL;
}

static int backup_fail(int ret, const char *what)
{
	backup_release();
	b.stage = B_NONE;

	return fs_fail(ret, "backup of %s: %s", b.target, what);
}

static int backup_open(void)
{
	struct mtd_info *mtd;
	size_t used = 0;

	if (b.ubi) {
		if (rtk_ubi_ensure())
			return backup_fail(-ENODEV, "UBI cannot be attached");
		if (!ubi_volume_exists(b.target) ||
		    ubi_volume_get_size(b.target, &used, NULL))
			return backup_fail(-ENOENT, "UBI has no such volume");
		if (!used)
			return backup_fail(-ENODATA, "the volume is empty");
		b.cache = malloc_cache_aligned(BACKUP_CACHE);
		if (!b.cache)
			return backup_fail(-ENOMEM, "no memory for the backup");
		b.size = used;
		snprintf(b.name, sizeof(b.name), "%s.bin", b.target);
	} else {
		mtd_probe_devices();
		mtd = get_mtd_device_nm(b.target);
		if (IS_ERR(mtd))
			return backup_fail(-ENODEV, "no such MTD device");
		b.mtd = mtd;
		b.size = mtd->size;
		snprintf(b.name, sizeof(b.name), "%s-main.bin", b.target);
	}
	b.stage = B_READY;
	b.touched = get_timer(0);
	printf("Backup of %s ready: %llu bytes.\n", b.target,
	       (unsigned long long)b.size);

	return 0;
}

int fs_backup_open(const char *kind, const char *target,
		   struct httpd_reply *reply)
{
	bool ubi = kind && !strcmp(kind, "ubi");
	u32 job;

	if (!ubi && (!kind || strcmp(kind, "mtd"))) {
		httpd_reply_error(reply, 400, "kind must be mtd or ubi");
		return -EINVAL;
	}
	if (!rtk_storage_name_valid(target)) {
		httpd_reply_error(reply, 400, "invalid target");
		return -EINVAL;
	}
	backup_release();
	memset(&b, 0, sizeof(b));
	b.id = ++backup_ids;
	b.stage = B_PREPARING;
	b.ubi = ubi;
	strlcpy(b.target, target, sizeof(b.target));
	job = fs_job_start("backup-open", backup_open, false);
	if (!job)
		b.stage = B_NONE;
	fs_reply_job(reply, job, b.id, 0);

	return job ? 0 : -EBUSY;
}

static int ubi_cached_read(u64 offset, u8 *out, size_t len)
{
	size_t n;

	while (len) {
		if (!b.cache_len || offset < b.cache_at ||
		    offset >= b.cache_at + b.cache_len) {
			b.cache_at = offset - offset % BACKUP_CACHE;
			b.cache_len = min_t(u64, BACKUP_CACHE,
					    b.size - b.cache_at);
			if (ubi_volume_read_quiet(b.target, (char *)b.cache,
						  b.cache_at, b.cache_len)) {
				b.cache_len = 0;
				return -EIO;
			}
		}
		n = min_t(u64, len, b.cache_at + b.cache_len - offset);
		memcpy(out, b.cache + (offset - b.cache_at), n);
		offset += n;
		out += n;
		len -= n;
	}

	return 0;
}

static int backup_read(void *priv, u64 offset, void *buf, size_t len)
{
	int ret;

	if (b.stage != B_STREAMING || offset > b.size ||
	    len > b.size - offset)
		return -EINVAL;
	b.touched = get_timer(0);
	if (b.mtd)
		ret = rtk_mtd_read(b.mtd, offset, buf, len);
	else
		ret = ubi_cached_read(offset, buf, len);
	if (ret)
		printf("Backup read at 0x%llx failed (%d).\n",
		       (unsigned long long)offset, ret);
	else if (offset + len > b.sent)
		b.sent = offset + len;

	return ret;
}

static void backup_close(void *priv, bool complete)
{
	if (b.stage != B_STREAMING)
		return;
	b.touched = get_timer(0);
	if (!complete) {
		b.stage = B_READY;
		return;
	}
	printf("Backup of %s sent (%llu bytes).\n", b.target,
	       (unsigned long long)b.size);
	backup_release();
	b.stage = B_NONE;
}

int fs_backup_get(u32 id, struct httpd_reply *reply)
{
	struct httpd_stream stream = {
		.read = backup_read,
		.close = backup_close,
	};

	if (!b.id || id != b.id || (b.stage != B_READY &&
				    b.stage != B_STREAMING)) {
		httpd_reply_error(reply, 404, "backup %u is not available", id);
		return -ENOENT;
	}
	if (b.stage == B_STREAMING) {
		httpd_reply_error(reply, 409, "backup %u is already downloading",
				  id);
		return -EBUSY;
	}
	stream.length = b.size;
	stream.filename = b.name;
	httpd_reply_stream(reply, &stream);
	b.stage = B_STREAMING;
	b.sent = 0;
	b.touched = get_timer(0);

	return 0;
}

int fs_backup_cancel(struct httpd_reply *reply)
{
	if (b.stage == B_STREAMING || b.stage == B_PREPARING) {
		httpd_reply_error(reply, 409,
				  "backup %u is busy; stop the download first",
				  b.id);
		return -EBUSY;
	}
	backup_release();
	b.stage = B_NONE;
	httpd_reply_json(reply, 200, "{\"job\":0}");

	return 0;
}

bool fs_backup_active(void)
{
	return b.stage != B_NONE;
}

void fs_backup_status(struct fs_backup_state *st)
{
	st->id = b.id;
	st->state = backup_stages[b.stage];
	st->name = b.name;
	st->size = b.size;
	st->sent = b.sent;
}

void fs_backup_poll(void)
{
	if (b.stage == B_READY &&
	    get_timer(b.touched) > FS_BACKUP_TIMEOUT) {
		printf("Backup %u expired.\n", b.id);
		backup_release();
		b.stage = B_NONE;
	}
}

void fs_backup_stop(void)
{
	backup_release();
	b.stage = B_NONE;
}
