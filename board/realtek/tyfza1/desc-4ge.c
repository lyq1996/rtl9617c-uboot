// SPDX-License-Identifier: GPL-2.0+
#include <config.h>
#include <rtk_board.h>

static const struct rtk_board_variant tyfza1_variant = {
	.lamp = {
		{ .pin = 4, .active_low = true },
		{ .pin = 3, .active_low = true },
		{ .pin = 1, .active_low = true },
		{ .pin = 0, .active_low = true },
	},
	.ports = "4×GE",
};

static const struct rtk_board_desc tyfza1_desc = {
	.name = "TYFZA1",
	.version = "2026.07",
	.variant = &tyfza1_variant,
	.reset_pin = 8,
	.reset_active_low = true,
};

const struct rtk_board_desc *rtk_board_desc(void)
{
	return &tyfza1_desc;
}
