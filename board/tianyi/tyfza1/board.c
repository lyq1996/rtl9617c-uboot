// SPDX-License-Identifier: GPL-2.0-only
/*
 * Tianyi TYFZA1 (RTL9617CVW).
 *
 * Everything that can be shared - the boot policy, the environment, the lamps,
 * the packet memory hand-off - lives in board/tianyi/tyfza1/common.
 * What is left
 * here is the board itself: the DRAM banks it wires.
 */
#include <config.h>
#include <init.h>
#include <stdio.h>
#include <asm/global_data.h>
#include <asm/io.h>
#include <asm/arch/registers.h>
#include <asm/arch/soc.h>
#include <rtk_board.h>
#ifdef CONFIG_RTK_WEB_FAILSAFE
#include <failsafe/failsafe.h>
#endif

#include <rtl9617c_ni.h>
#include <linux/errno.h>

DECLARE_GLOBAL_DATA_PTR;

int board_init(void)
{
	rtl9617c_early_init();
#ifdef CONFIG_RTK_WEB_FAILSAFE
	rtk_board_reset_latch();
#endif
	/* Both variants use the internal GPHYs for their GE ports. */
	rtl9617c_ni_gphy_setup();

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
