// SPDX-License-Identifier: GPL-2.0-only
#include <config.h>
#include <malloc.h>
#include <memalign.h>
#include <mapmem.h>
#include <mtd.h>
#include <stdio.h>
#include <string.h>
#include <ubi_uboot.h>
#include <rtk_recovery.h>

static const struct rtk_recovery_layout *layout(void)
{
	return rtk_recovery_layout();
}

#define RESTORE_CHUNK (4U * 1024 * 1024)
static struct rtk_restore_status state;
static struct mtd_info *restore_mtd;
static unsigned char *boot_image;
static u32 generation;

const struct rtk_restore_status *rtk_restore_status(void)
{
	return &state;
}

static void restore_release(void)
{
	free(boot_image);
	boot_image = NULL;
	if (restore_mtd) put_mtd_device(restore_mtd);
	restore_mtd = NULL;
	memset(&state, 0, sizeof(state));
}

static int restore_begin(ulong address, size_t size, size_t total,
			 const char *kind, const char *target)
{
	const void *data;
	bool partition = kind && !strcmp(kind, "mtd");
	int ret;

	if (state.active) return -EBUSY;
	if (partition) {
		if (!target || !strcmp(target, "boot") ||
		    !size || size > RESTORE_CHUNK || size % 0x20000)
			return -EINVAL;
	} else {
		if (size != RTK_BOOT_SIZE || total != layout()->flash_size)
			return -EINVAL;
		ret = rtk_validate_loader(address, size);
		if (ret) return ret;
	}
	mtd_probe_devices();
	restore_mtd = get_mtd_device_nm(partition ? target : layout()->nand_dev);
	if (IS_ERR(restore_mtd)) {
		ret = PTR_ERR(restore_mtd); restore_mtd = NULL; return ret;
	}
	if (restore_mtd->size != total || restore_mtd->erasesize != 0x20000 ||
	    restore_mtd->writesize != 0x800) { ret = -EINVAL; goto fail; }
	if (partition) {
		boot_image = NULL;
	} else {
		boot_image = malloc_cache_aligned(RTK_BOOT_SIZE);
		if (!boot_image) { ret = -ENOMEM; goto fail; }
		data = map_sysmem(address, size);
		memcpy(boot_image, data, size);
		unmap_sysmem(data);
	}
	ret = ubi_detach();
	if (ret) goto fail;
	if (!++generation) generation++;
	state = (struct rtk_restore_status) {
		.active = true, .id = generation,
		.next = partition ? 0 : RTK_BOOT_SIZE, .total = total
	};
	if (partition)
		printf("Partition '%s' restore started; every chunk is written and verified as it arrives.\n", target);
	else
		puts("Full NAND restore started; boot remains untouched until every data chunk is verified.\n");
	return 0;
fail:
	restore_release();
	return ret;
}

static int restore_chunk(ulong address, size_t size, size_t offset, void (*poll)(void))
{
	const unsigned char *input;
	unsigned char *check;
	size_t at, done;
	int ret = 0;
	if (!size || size > RESTORE_CHUNK || offset != state.next ||
	    (boot_image && offset < RTK_BOOT_SIZE) ||
	    size > state.total - state.next || offset % restore_mtd->erasesize ||
	    size % restore_mtd->erasesize) return -EINVAL;
	check = malloc_cache_aligned(restore_mtd->erasesize);
	if (!check) return -ENOMEM;
	input = map_sysmem(address, size);
	/* Keep physical bad-block gaps in place, matching main-area NAND backups. */
	for (at = 0; at < size; at += restore_mtd->erasesize) {
		struct erase_info erase = { .mtd = restore_mtd, .addr = offset + at,
			.len = restore_mtd->erasesize };
		ret = mtd_block_isbad(restore_mtd, offset + at);
		if (ret < 0) break;
		if (ret > 0) { ret = 0; poll(); continue; }
		ret = mtd_erase(restore_mtd, &erase);
		if (ret) break;
		ret = mtd_write(restore_mtd, offset + at, restore_mtd->erasesize,
				&done, input + at);
		if (ret || done != restore_mtd->erasesize) { ret = ret ? ret : -EIO; break; }
		ret = mtd_read(restore_mtd, offset + at, restore_mtd->erasesize, &done, check);
		if (ret == -EUCLEAN && done == restore_mtd->erasesize) ret = 0;
		if (ret || done != restore_mtd->erasesize || memcmp(check, input + at, done)) {
			ret = ret ? ret : -EIO;
			break;
		}
		poll();
	}
	if (!ret) state.next += size;
	unmap_sysmem(input);
	free(check);
	return ret;
}

int rtk_restore_job(const char *operation, ulong address, size_t size,
		    size_t total, size_t offset, u32 id, void (*poll)(void),
		    const char *kind, const char *target)
{
	int ret;
	if (!strcmp(operation, "restore-start")) {
		ret = restore_begin(address, size, total, kind, target);
		if (ret) return ret;
		if (boot_image) return 0;
		return restore_chunk(address, size, state.next, poll);
	}
	if (!state.active || id != state.id) return -ESTALE;
	if (!strcmp(operation, "restore-cancel")) { restore_release(); return 0; }
	if (!strcmp(operation, "restore-chunk")) return restore_chunk(address, size, offset, poll);
	if (!strcmp(operation, "restore-finish")) {
		if (state.next != state.total) return -EINVAL;
		if (boot_image) {
			ret = rtk_install_loader((ulong)boot_image, RTK_BOOT_SIZE, poll);
			if (ret) return ret;
			puts("Full NAND restore complete; both boot FIPs written last and read back.\n");
		} else {
			printf("Partition restore complete; %zu bytes written and verified.\n",
			       state.total);
		}
		restore_release();
		return 0;
	}
	return -EINVAL;
}
