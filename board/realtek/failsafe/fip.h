/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Realtek RTL9617C platform: on-flash boot image format.
 */

#ifndef __RTK_FIP_H
#define __RTK_FIP_H

#include <stddef.h>
#include "recovery.h"

/* fip.c - the on-flash boot image format. */
int rtk_fip_parse(const void *data, size_t size, struct rtk_fip *out);
int rtk_loader_parse(const void *data, size_t size, struct rtk_fip *out);
int rtk_loader_preserves_device(const void *next, size_t next_size,
				const void *current, size_t current_size);

#endif /* __RTK_FIP_H */
