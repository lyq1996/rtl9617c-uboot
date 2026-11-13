// SPDX-License-Identifier: GPL-2.0+
/*
 * PT1570 flash layout.
 *
 * The physical partitioning is the platform one, byte-identical to the other
 * boards (measured on the unit: the stored mtdparts agrees). What is left
 * here is the volume table of the product - factory data first, then the
 * system image covering the rest.
 */
#include <config.h>
#include <linux/kernel.h>
#include <rtk_board.h>
#ifdef CONFIG_RTK_WEB_FAILSAFE
#include <failsafe/recovery.h>
#endif

static const struct rtk_boot_layout pt1570_boot = {
	.ubi_part = "ubi_device",
	.firmware_volume = "fit",
	.overlay_volume = "rootfs_data",
};

const struct rtk_boot_layout *rtk_boot_layout(void)
{
	return &pt1570_boot;
}

#ifdef CONFIG_RTK_WEB_FAILSAFE
static const struct rtk_ubi_volume pt1570_volumes[] = {
	{ "factory", RTK_VOL_DATA, CONFIG_RTK_FACTORY_SIZE, false },
	{ "fit", RTK_VOL_FIRMWARE, 0, true },
};

const struct rtk_recovery_layout *rtk_recovery_layout(void)
{
	static const struct rtk_recovery_layout layout = {
		.boot_mtd = "boot",
		.nand_dev = "nand0",
		.boot = &pt1570_boot,
		.ubi_mtd = 4,
		.flash_size = 0x10000000,

		.volumes = pt1570_volumes,
		.nr_volumes = ARRAY_SIZE(pt1570_volumes),
	};

	return &layout;
}
#endif
