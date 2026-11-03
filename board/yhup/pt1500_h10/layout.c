// SPDX-License-Identifier: GPL-2.0+
/*
 * PT1500 flash layout.
 *
 * The physical partitioning is now the same on every board of this platform:
 * firmware, environment, one UBI device. What is left here is the volume table
 * of the product - no FPGA volume, and the configuration volumes at the end.
 */
#include <config.h>
#include <linux/kernel.h>
#include <rtk_board.h>
#ifdef CONFIG_RTK_WEB_FAILSAFE
#include <failsafe/recovery.h>
#endif

static const struct rtk_boot_layout pt1500_boot = {
	.ubi_part = "ubi_device",
	.firmware_volume = "fit",
	.overlay_volume = "rootfs_data",
};

const struct rtk_boot_layout *rtk_boot_layout(void)
{
	return &pt1500_boot;
}

#ifdef CONFIG_RTK_WEB_FAILSAFE
static const struct rtk_ubi_volume pt1500_volumes[] = {
	{ "factory", RTK_VOL_DATA, RTK_FACTORY_IMAGE_SIZE, false },
	{ "fit", RTK_VOL_FIRMWARE, 0, true },
};

const struct rtk_recovery_layout *rtk_recovery_layout(void)
{
	static const struct rtk_recovery_layout layout = {
		.boot_mtd = "boot",
		.nand_dev = "nand0",
		.boot = &pt1500_boot,
		.ubi_mtd = 4,
		.flash_size = 0x10000000,

		.volumes = pt1500_volumes,
		.nr_volumes = ARRAY_SIZE(pt1500_volumes),
	};

	return &layout;
}
#endif
