// SPDX-License-Identifier: GPL-2.0+
/*
 * PT1500 board description.
 *
 * Ten status lamps, all on GPIO bank 0, listed in panel order from the power
 * lamp to the last USB lamp. The 2.5G port lamp is driven by its PHY and is
 * not listed. The reset key sits on bank 0 bit 8.
 */
#include <config.h>
#include <linux/kernel.h>
#include <failsafe/desc.h>

static const struct rtk_led pt1500_lamps[] = {
	{ .pin = 11 },				/* power */
	{ .pin = 9, .active_low = true },	/* pon */
	{ .pin = 10, .active_low = true },	/* los */
	{ .pin = 2, .active_low = true },	/* ppp */
	{ .pin = 12 },				/* fxs */
	{ .pin = 7 },				/* usb0 */
	{ .pin = 0, .active_low = true },	/* lan3 */
	{ .pin = 1, .active_low = true },	/* lan2 */
	{ .pin = 3, .active_low = true },	/* lan1 */
	//{ .pin = 6, .active_low = true },	/* usb1 */
};

static const struct rtk_board_variant pt1500_variant = {
	.lamp = pt1500_lamps,
	.nr_lamps = ARRAY_SIZE(pt1500_lamps),
	.ports = "2.5GE + 3×GE",
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
