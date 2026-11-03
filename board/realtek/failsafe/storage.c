// SPDX-License-Identifier: GPL-2.0-only
/*
 * Flash primitives shared by the recovery engine and the web failsafe: block
 * by block MTD writes that read every block back, bad-block aware reads, and
 * whole-volume UBI updates checked by CRC.
 */
#include <config.h>
#include <image.h>
#include <malloc.h>
#include <memalign.h>
#include <mtd.h>
#include <stdio.h>
#include <string.h>
#include <ubi_volume.h>
#include <u-boot/crc.h>
#include <linux/ctype.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include "recovery.h"
#include "storage.h"

bool rtk_storage_name_valid(const char *name)
{
	const char *p;

	if (!name || !*name)
		return false;

	for (p = name; *p; p++) {
		if (!isalnum((unsigned char)*p) && *p != '_' && *p != '-' &&
		    *p != '.' && *p != ':' && *p != '@' && *p != ',' &&
		    *p != '+')
			return false;
	}

	return p - name < 64;
}

static int ubi_errno(int ret)
{
	return ret > 0 ? -ret : ret;
}

int rtk_ubi_ensure(void)
{
	const struct rtk_recovery_layout *l = rtk_recovery_layout();
	const char *part = ubi_part_name();

	if (part && !strcmp(part, l->boot->ubi_part))
		return 0;
	printf("Attaching UBI on %s.\n", l->boot->ubi_part);
	if (ubi_part((char *)l->boot->ubi_part, NULL)) {
		printf("Attaching UBI on %s failed.\n", l->boot->ubi_part);
		return -ENODEV;
	}

	return 0;
}

int rtk_ubi_crc(const char *volume, size_t size, void *scratch,
		size_t scratch_size, u32 *crc, const struct storage_job *job)
{
	size_t done, chunk;
	u32 value = 0;
	int ret;

	storage_job_report(job, STORAGE_PHASE_VERIFY, 0, size);
	for (done = 0; done < size; done += chunk) {
		chunk = min_t(size_t, scratch_size, size - done);
		ret = ubi_volume_read_quiet((char *)volume, scratch, done,
					    chunk);
		if (ret)
			return ubi_errno(ret);
		value = crc32_wd(value, scratch, chunk, CHUNKSZ_CRC32);
		storage_job_report(job, STORAGE_PHASE_VERIFY, done + chunk,
				   size);
		storage_job_service(job);
	}
	*crc = value;

	return 0;
}

int rtk_ubi_write(const char *volume, const void *data, size_t size,
		  const struct storage_job *job)
{
	const u8 *input = data;
	size_t done, chunk;
	u32 expected, actual;
	void *check;
	int ret;

	if (!size)
		return -EINVAL;
	expected = crc32_wd(0, input, size, CHUNKSZ_CRC32);
	storage_job_report(job, STORAGE_PHASE_WRITE, 0, size);
	for (done = 0; done < size; done += chunk) {
		chunk = min_t(size_t, STORAGE_CHUNK_SIZE, size - done);
		if (!done)
			ret = ubi_volume_begin_write((char *)volume,
						     (void *)input, chunk, size);
		else
			ret = ubi_volume_continue_write((char *)volume,
							(void *)(input + done),
							chunk);
		if (ret)
			return ubi_errno(ret);
		storage_job_report(job, STORAGE_PHASE_WRITE, done + chunk,
				   size);
		storage_job_service(job);
	}

	check = malloc_cache_aligned(STORAGE_CHUNK_SIZE);
	if (!check)
		return -ENOMEM;
	ret = rtk_ubi_crc(volume, size, check, STORAGE_CHUNK_SIZE, &actual,
			  job);
	free(check);
	if (ret)
		return ret;
	if (actual != expected) {
		printf("UBI readback CRC mismatch: %08x != %08x.\n", actual,
		       expected);
		return -EIO;
	}

	return 0;
}

int rtk_mtd_read(struct mtd_info *mtd, u64 offset, void *buf, size_t len)
{
	u8 *out = buf;
	size_t chunk, read;
	int ret;

	while (len) {
		chunk = min_t(u64, len, mtd->erasesize - offset % mtd->erasesize);
		ret = mtd_block_isbad(mtd, offset - offset % mtd->erasesize);
		if (ret < 0)
			return ret;
		if (ret) {
			memset(out, 0xff, chunk);
		} else {
			read = 0;
			ret = mtd_read(mtd, offset, chunk, &read, out);
			if (ret == -EUCLEAN && read == chunk)
				ret = 0;
			if (ret)
				return ret;
			if (read != chunk)
				return -EIO;
		}
		offset += chunk;
		out += chunk;
		len -= chunk;
	}

	return 0;
}

static bool mtd_uses_pages(const struct mtd_info *mtd)
{
	return mtd->type == MTD_NANDFLASH || mtd->type == MTD_MLCNANDFLASH;
}

int rtk_nand_scrub(const struct storage_job *job)
{
	struct mtd_info *mtd, *whole = NULL;
	struct erase_info erase;
	u64 addr;
	int ret = 0;

	mtd_probe_devices();
	mtd_for_each_device(mtd) {
		if (!mtd_is_partition(mtd) && mtd_uses_pages(mtd) &&
		    (!whole || mtd->size > whole->size))
			whole = mtd;
	}
	if (!whole)
		return -ENODEV;
	mtd = get_mtd_device_nm(whole->name);
	if (IS_ERR(mtd))
		return PTR_ERR(mtd);

	printf("NAND scrub: clearing bad block markers on %s (%llu bytes)\n",
	       mtd->name, (unsigned long long)mtd->size);
	storage_job_report(job, STORAGE_PHASE_ERASE, 0, mtd->size);
	memset(&erase, 0, sizeof(erase));
	erase.mtd = mtd;
	erase.len = mtd->erasesize;
	erase.scrub = 1;

	for (addr = 0; addr < mtd->size; addr += mtd->erasesize) {
		erase.addr = addr;
		ret = mtd_block_isbad(mtd, addr);
		if (ret > 0)
			printf("Scrubbing bad block at 0x%llx.\n",
			       (unsigned long long)addr);
		else if (ret < 0)
			goto out;
		ret = mtd_erase(mtd, &erase);
		if (ret)
			goto out;
		storage_job_report(job, STORAGE_PHASE_ERASE,
				   addr + mtd->erasesize, mtd->size);
		storage_job_service(job);
	}

out:
	put_mtd_device(mtd);

	return ret;
}

int rtk_mtd_write(struct mtd_info *mtd, u64 offset, const void *data,
		  size_t size, const struct storage_job *job,
		  size_t progress_base, size_t progress_total, bool skip_bad)
{
	const u8 *input = data;
	u8 *check;
	size_t at, done;
	unsigned int skipped = 0;
	int ret = 0;

	if (!size || offset % mtd->erasesize || size % mtd->erasesize)
		return -EINVAL;
	check = malloc_cache_aligned(mtd->erasesize);
	if (!check)
		return -ENOMEM;
	for (at = 0; at < size; at += mtd->erasesize) {
		struct erase_info erase = {
			.mtd = mtd, .addr = offset + at, .len = mtd->erasesize
		};

		ret = mtd_block_isbad(mtd, offset + at);
		if (ret < 0)
			break;
		if (ret > 0) {
			size_t i;

			for (i = 0; i < mtd->erasesize; i++)
				if (input[at + i] != 0xff)
					break;
			if (i < mtd->erasesize) {
				if (!skip_bad) {
					printf("Image has data at bad block 0x%llx; write refused.\n",
					       (unsigned long long)(offset + at));
					ret = -EINVAL;
					break;
				}
				skipped++;
			}
			ret = 0;
		} else {
			ret = mtd_erase(mtd, &erase);
			if (ret)
				break;
			done = 0;
			ret = mtd_write(mtd, offset + at, mtd->erasesize, &done,
					input + at);
			if (ret || done != mtd->erasesize) {
				ret = ret ? ret : -EIO;
				break;
			}
			done = 0;
			ret = mtd_read(mtd, offset + at, mtd->erasesize, &done,
				       check);
			if (ret == -EUCLEAN && done == mtd->erasesize)
				ret = 0;
			if (ret || done != mtd->erasesize ||
			    memcmp(check, input + at, done)) {
				printf("Readback mismatch at 0x%llx.\n",
				       (unsigned long long)(offset + at));
				ret = ret ? ret : -EIO;
				break;
			}
		}
		storage_job_report(job, STORAGE_PHASE_WRITE,
				   progress_base + at + mtd->erasesize,
				   progress_total);
		storage_job_service(job);
	}
	free(check);
	if (!ret && skipped)
		printf("%u bad blocks skipped.\n", skipped);

	return ret;
}
