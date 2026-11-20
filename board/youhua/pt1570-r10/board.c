// SPDX-License-Identifier: GPL-2.0-only
/*
 * Youhua PT1570-R10 (RTL9617C, 10G EPON).
 *
 * Board policy, environment, lamps and the reset key come from
 * board/realtek; the flash volume layout is in layout.c. Unlike the H10,
 * the four GE LAN ports sit on the SoC internal GPHY wrapper, and the
 * stock BL2/BL31 used to build this image is taken from the R10 OEM mtd0.
 */
#include <config.h>
#include <init.h>
#include <asm/global_data.h>
#include <asm/arch/soc.h>
#include <rtk_board.h>
#ifdef CONFIG_RTK_WEB_FAILSAFE
#include <failsafe/failsafe.h>
#endif
#include <linux/errno.h>

DECLARE_GLOBAL_DATA_PTR;

int board_init(void)
{
	rtl9617c_early_init();
#ifdef CONFIG_RTK_WEB_FAILSAFE
	rtk_board_reset_latch();
#endif

	return 0;
}

void board_preboot_os(void)
{
	rtk_board_preboot();
}

int board_late_init(void)
{
	rtk_board_late_env();
#ifdef CONFIG_RTK_WEB_FAILSAFE
	rtk_board_failsafe_spy();
#endif

	return 0;
}
