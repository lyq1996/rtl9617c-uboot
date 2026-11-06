// SPDX-License-Identifier: GPL-2.0-only
/*
 * Youhua PT1500-H10 (RTL9617C).
 *
 * A second product on the same SoC, and deliberately a small board file: the
 * boot policy, the environment, the lamps and the key all come from
 * board/realtek/common, and the flash layout is in layout.c. The only thing
 * this board does differently is leave the internal GPHY wrappers alone, because
 * its four LAN ports are driven by external RTL8211 PHYs that sit at the same
 * MDIO addresses.
 */
#include <config.h>
#include <init.h>
#include <asm/global_data.h>
#include <asm/arch/soc.h>
#include <rtk_board.h>
#include <linux/errno.h>

DECLARE_GLOBAL_DATA_PTR;

int board_init(void)
{
	taurus_early_init();
	rtk_board_reset_latch();

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
