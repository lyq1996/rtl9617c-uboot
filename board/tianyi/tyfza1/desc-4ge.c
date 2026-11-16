// SPDX-License-Identifier: GPL-2.0+
#include <config.h>
#include <linux/kernel.h>
#include <failsafe/desc.h>

static const struct rtk_led tyfza1_4ge_lamps[] = {
	{ .pin = 4, .active_low = true },
	{ .pin = 3, .active_low = true },
	{ .pin = 1, .active_low = true },
	{ .pin = 0, .active_low = true },
};

static const struct rtk_board_variant tyfza1_4ge_variant = {
	.lamp = tyfza1_4ge_lamps,
	.nr_lamps = ARRAY_SIZE(tyfza1_4ge_lamps),
	.ports = "4×GE",
};

static const struct rtk_board_desc tyfza1_4ge_desc = {
	.name = "Tianyi TYFZA1",
	.version = "2026.07",
	.variant = &tyfza1_4ge_variant,
	.reset_pin = 8,
	.reset_active_low = true,
};

const struct rtk_board_desc *rtk_board_desc(void)
{
	return &tyfza1_4ge_desc;
}
