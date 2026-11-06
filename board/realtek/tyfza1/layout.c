// SPDX-License-Identifier: GPL-2.0+
/*
 * TYFZA1 flash layout.
 *
 * The shared platform code (board/realtek/common) contains no volume name
 * or device tree string: everything product specific is here.
 */
#include <config.h>
#include <linux/kernel.h>
#include <rtk_recovery.h>

static const struct rtk_ubi_volume tyfza1_volumes[] = {
	{ "factory", RTK_VOL_DATA, RTK_FACTORY_IMAGE_SIZE, false },
	{ "fit", RTK_VOL_FIRMWARE, 0, true },
};

const struct rtk_recovery_layout *rtk_recovery_layout(void)
{
	static const struct rtk_recovery_layout layout = {
		.boot_mtd = "boot",
		.nand_dev = "nand0",
		.ubi_part = "ubi_device",
		.ubi_mtd = 4,
		.flash_size = 0x10000000,

		.firmware_volume = "fit",

		.overlay_volume = "rootfs_data",
		.volumes = tyfza1_volumes,
		.nr_volumes = ARRAY_SIZE(tyfza1_volumes),
	};

	return &layout;
}
