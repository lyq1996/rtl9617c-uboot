/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Volume level access to the UBI device selected by the ubi command, for code
 * that does not need the UBI internals.
 */
#ifndef __UBI_VOLUME_H
#define __UBI_VOLUME_H

#include <linux/types.h>

struct ubi_volume_entry {
	const char *name;
	size_t used_bytes;
	size_t reserved_bytes;
	bool dynamic;
};

int ubi_part(char *part_name, const char *vid_header_offset);
int ubi_detach(void);
int ubi_detach_quick(void);
const char *ubi_part_name(void);
u64 ubi_free_bytes(void);
int ubi_volume_next(int slot, struct ubi_volume_entry *info);
bool ubi_volume_exists(const char *volume);
int ubi_volume_create(const char *volume, int64_t size, bool dynamic);
int ubi_volume_remove(const char *volume);
int ubi_volume_rename(const char *oldname, const char *newname);
int ubi_volume_get_size(const char *volume, size_t *used_bytes,
			size_t *reserved_bytes);
int ubi_volume_begin_write(char *volume, void *buf, size_t size,
			   size_t full_size);
int ubi_volume_continue_write(char *volume, void *buf, size_t size);
int ubi_volume_read(char *volume, char *buf, loff_t offset, size_t size);
int ubi_volume_read_quiet(char *volume, char *buf, loff_t offset, size_t size);

#endif
