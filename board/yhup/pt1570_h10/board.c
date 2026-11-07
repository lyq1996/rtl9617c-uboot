// SPDX-License-Identifier: GPL-2.0-only
/*
 * Youhua PT1570-H10 (RTL9617C).
 *
 * A third product on the same SoC, and deliberately a small board file: the
 * boot policy, the environment, the lamps and the key all come from
 * board/realtek, and the flash layout is in layout.c. Like the PT1500, its
 * four LAN ports are driven by external RTL8211 PHYs that sit at the same
 * MDIO addresses, so the internal GPHY wrappers are left alone.
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
