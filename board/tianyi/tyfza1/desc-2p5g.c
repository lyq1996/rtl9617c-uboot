// SPDX-License-Identifier: GPL-2.0+
#include <config.h>
#include <linux/kernel.h>
#include <failsafe/desc.h>

static const struct rtk_led tyfza1_2p5g_lamps[] = {
	{ .pin = 11 }, { .pin = 12 },
	{ .pin = 3, .active_low = true },
	{ .pin = 4, .active_low = true },
};

static const struct rtk_board_variant tyfza1_2p5g_variant = {
	.lamp = tyfza1_2p5g_lamps,
	.nr_lamps = ARRAY_SIZE(tyfza1_2p5g_lamps),
	.ports = "2.5GE + 3×GE",
};

static const struct rtk_board_desc tyfza1_2p5g_desc = {
	.name = "Tianyi TYFZA1",
	.version = "2026.07",
	.variant = &tyfza1_2p5g_variant,
	.reset_pin = 8,
	.reset_active_low = true,
};

const struct rtk_board_desc *rtk_board_desc(void)
{
	return &tyfza1_2p5g_desc;
}
