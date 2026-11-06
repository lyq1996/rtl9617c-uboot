// SPDX-License-Identifier: GPL-2.0-only
/*
 * Tianyi TYFZA1 (RTL9617CVW).
 *
 * Everything that can be shared - the boot policy, the environment, the lamps,
 * the packet memory hand-off - lives in board/realtek/common. What is left
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
#include <taurus_ni.h>
#include <linux/errno.h>

DECLARE_GLOBAL_DATA_PTR;

int board_init(void)
{
	taurus_early_init();
	rtk_board_reset_latch();
	/* Both variants use the internal GPHYs for their GE ports. */
	taurus_ni_gphy_setup();

	return 0;
}

void board_preboot_os(void)
{
	rtk_board_preboot();
}

int board_late_init(void)
{
	rtk_board_late_env();

	return 0;
}
