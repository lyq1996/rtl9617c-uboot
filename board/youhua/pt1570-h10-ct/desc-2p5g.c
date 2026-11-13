// SPDX-License-Identifier: GPL-2.0+
/*
 * Youhua PT1570-H10-CT 2.5G board description.
 *
 * Read back from the OEM device tree this unit ships (rtk_gpio_led and
 * gpio-keys): all lamps sit on GPIO bank 0. Panel order follows the PT1500;
 * the four LAN lamps are LED_EPHY3..EPHY0 (descending pin), and the WPS lamp
 * (pin 5, active high) has no failsafe state and stays with the OS. The
 * reset key sits on bank 0 bit 8, active low.
 */
#include <config.h>
#include <linux/kernel.h>
#include <failsafe/desc.h>

static const struct rtk_led pt1570_h10_ct_2p5g_lamps[] = {
	{ .pin = 0, .active_low = true },	/* lan4, LED_EPHY3 */
	{ .pin = 1, .active_low = true },	/* lan3, LED_EPHY2 */
	{ .pin = 3, .active_low = true },	/* lan2, LED_EPHY1 */
	{ .pin = 4, .active_low = true },	/* lan1, LED_EPHY0 */
};

static const struct rtk_board_variant pt1570_h10_ct_2p5g_variant = {
	.lamp = pt1570_h10_ct_2p5g_lamps,
	.nr_lamps = ARRAY_SIZE(pt1570_h10_ct_2p5g_lamps),
	.ports = "2.5GE + 3×GE",
};

static const struct rtk_board_desc pt1570_h10_ct_2p5g_desc = {
	.name = "Youhua PT1570-H10-CT",
	.version = "2026.07",
	.variant = &pt1570_h10_ct_2p5g_variant,
	.reset_pin = 8,
	.reset_active_low = true,
};

const struct rtk_board_desc *rtk_board_desc(void)
{
	return &pt1570_h10_ct_2p5g_desc;
}
