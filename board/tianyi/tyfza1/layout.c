// SPDX-License-Identifier: GPL-2.0+
/*
 * TYFZA1 flash layout.
 *
 * The shared platform code (board/tianyi/tyfza1/common) contains no
 * volume name
 * or device tree string: everything product specific is here.
 */
#include <config.h>
#include <linux/kernel.h>
#include <rtk_board.h>
#ifdef CONFIG_RTK_WEB_FAILSAFE
#include <failsafe/recovery.h>
#endif

static const struct rtk_boot_layout tyfza1_boot = {
	.ubi_part = "ubi_device",
	.firmware_volume = "fit",
	.overlay_volume = "rootfs_data",
};

const struct rtk_boot_layout *rtk_boot_layout(void)
{
	return &tyfza1_boot;
}

#ifdef CONFIG_RTK_WEB_FAILSAFE
static const struct rtk_ubi_volume tyfza1_volumes[] = {
	{ "factory", RTK_VOL_DATA, RTK_FACTORY_IMAGE_SIZE, false },
	{ "fit", RTK_VOL_FIRMWARE, 0, true },
};

const struct rtk_recovery_layout *rtk_recovery_layout(void)
{
	static const struct rtk_recovery_layout layout = {
		.boot_mtd = "boot",
		.nand_dev = "nand0",
		.boot = &tyfza1_boot,
		.ubi_mtd = 4,
		.flash_size = 0x10000000,

		.volumes = tyfza1_volumes,
		.nr_volumes = ARRAY_SIZE(tyfza1_volumes),
	};

	return &layout;
}
#endif
