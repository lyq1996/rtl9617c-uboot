/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __RTK_STORAGE_H
#define __RTK_STORAGE_H

#include <linux/types.h>
#include "storage_job.h"

struct mtd_info;

bool rtk_storage_name_valid(const char *name);
int rtk_mtd_write(struct mtd_info *mtd, u64 offset, const void *data,
		  size_t size, const struct storage_job *job,
		  size_t progress_base, size_t progress_total, bool skip_bad);
int rtk_mtd_read(struct mtd_info *mtd, u64 offset, void *buf, size_t len);
int rtk_nand_scrub(const struct storage_job *job);

int rtk_ubi_ensure(void);
int rtk_ubi_write(const char *volume, const void *data, size_t size,
		  const struct storage_job *job);
int rtk_ubi_crc(const char *volume, size_t size, void *scratch,
		size_t scratch_size, u32 *crc, const struct storage_job *job);

#endif
