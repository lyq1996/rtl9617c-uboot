// SPDX-License-Identifier: GPL-2.0+
/*
 * PT1500 board description.
 *
 * The four status lamps are LED_EPHY0..3 of the OEM device tree (bank 0, bits
 * 4, 3, 1 and 0, all active low) and the reset key sits on bank 0 bit 8.
 */
#include <config.h>
#include <rtk_board.h>

static const struct rtk_board_variant pt1500_variant = {
	.lamp = {
		{ .pin = 4, .active_low = true },
		{ .pin = 3, .active_low = true },
		{ .pin = 1, .active_low = true },
		{ .pin = 0, .active_low = true },
		{ .pin = 11, .active_low = false },	/* LED_PWR_G */
	},
	.ports = "4×GE",
};

static const struct rtk_board_desc pt1500_desc = {
	.name = "PT1500",
	.version = "2026.07",
	.variant = &pt1500_variant,
	.reset_pin = 8,
	.reset_active_low = true,
};

const struct rtk_board_desc *rtk_board_desc(void)
{
	return &pt1500_desc;
}
