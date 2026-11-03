/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Realtek RTL9617C platform: flash layout, boot and recovery.
 *
 * A board describes its flash once, in rtk_recovery_layout(); the shared code
 * here contains no volume name or device tree string.
 */
#ifndef __RTK_RECOVERY_H
#define __RTK_RECOVERY_H

#include <linux/types.h>
#include <stddef.h>
#include <stdint.h>
#include <rtk_board.h>
#include "storage_job.h"

/* Boot area: the platform firmware, in two identical FIP copies. */
#define RTK_BOOT_SIZE		0x200000U
#define RTK_FIP_SIZE		0xc0000U
#define RTK_FIP0_OFFSET		0x40000U
#define RTK_FIP1_OFFSET		0x100000U

#define RTK_FACTORY_IMAGE_SIZE	0x800000U

struct rtk_payload {
	const unsigned char *data;
	size_t size;
};

struct rtk_fip {
	struct rtk_payload bl2, bl31, bl33;
};

/* What a rebuild does to one UBI volume of the table. */
enum rtk_volume_policy {
	/*
	 * The system image: dropped on a rebuild and re-created as an empty
	 * dynamic volume covering every free eraseblock.
	 */
	RTK_VOL_FIRMWARE,
	/*
	 * Overlay data: dropped and re-created at the size below on a rebuild,
	 * so a layout migration can reserve room for a growing firmware image.
	 */
	RTK_VOL_DATA,
};

/* One UBI volume of the rebuild table. */
struct rtk_ubi_volume {
	const char *name;
	enum rtk_volume_policy policy;
	u64 size;		/* bytes; 0 means "all remaining space" */
	bool dynamic;
};

/*
 * What the platform code needs to know about a product.
 */
struct rtk_recovery_layout {
	/* Flash. */
	const char *boot_mtd;		/* partition holding the firmware */
	const char *nand_dev;		/* whole device, used by a full restore */
	const struct rtk_boot_layout *boot;
	unsigned int ubi_mtd;		/* kernel mtd index of the UBI partition */
	size_t flash_size;

	/* UBI rebuild table. */
	const struct rtk_ubi_volume *volumes;
	unsigned int nr_volumes;
};

/* Provided by the board. */
const struct rtk_recovery_layout *rtk_recovery_layout(void);



/* recovery.c - install engine. */
int rtk_validate_loader(const void *image, size_t size);
int rtk_install_boot(const void *image, size_t size,
		     const struct storage_job *job);
int rtk_rebuild_ubi(const struct storage_job *job);

/* UBI device and volume management; the device is the layout's ubi_part. */
bool rtk_ubi_attached(void);
int rtk_ubi_attach(void);
int rtk_ubi_detach(bool quick);
int rtk_ubi_create(const char *name, u64 size, bool dynamic);
int rtk_ubi_remove(const char *name);
int rtk_ubi_rename(const char *old_name, const char *new_name);

#endif /* __RTK_RECOVERY_H */
