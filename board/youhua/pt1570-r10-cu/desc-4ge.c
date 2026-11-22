// SPDX-License-Identifier: GPL-2.0+
/*
 * Youhua PT1570-R10 board description — status lamps in FRONT-PANEL
 * PHYSICAL ORDER (left -> right).
 *
 * Panel map (verified on the real unit, 2026-11-16, 13 lamp positions):
 *
 *   #   lamp        LED label     GPIO  active  driven by
 *   --  ----------  ------------  ----  ------  --------------------------
 *    1  电源        LED_PWR_G     11    high    SoC GPIO  [U-Boot]
 *    2  注册        LED_PON        9    low     SoC GPIO  [U-Boot]
 *    3  光信号      LED_LOS       10    low     SoC GPIO  [U-Boot]
 *    4  5G          5G WiFi       --    --      PCIe WiFi card  (off in U-Boot)
 *    5  2.4G        2.4G WiFi     --    --      PCIe WiFi card  (off in U-Boot)
 *    6  千兆口1     LED_EPHY3      0    low     SoC GPIO  [U-Boot]
 *    7  千兆口2     LED_EPHY2      1    low     SoC GPIO  [U-Boot]
 *    8  千兆口3     LED_EPHY1      3    low     SoC GPIO  [U-Boot]
 *    9  千兆口4     LED_EPHY0      4    low     SoC GPIO  [U-Boot]
 * (GE: EPHY numbering runs opposite to the silk-screen. Confirmed on-unit
 *  2026-11-19: a 4/3/1/0 runner sweeps the panel right-to-left 4->1 gigabit;
 *  matching the silk-screen 1->4 needs the 0/1/3/4 order below.)
 *   10  电话        LED_FXS       12    high    SoC GPIO  [U-Boot]
 *   11  宽带        LED_PPP_G      2    low     SoC GPIO  [U-Boot]
 *   12  WPS         LED_WPS_G      5    high    SoC GPIO  [U-Boot]
 *   13  USB         LED_USB0       7    high    SoC GPIO  [U-Boot]
 *
 * Positions that carry no SoC status GPIO are left out of the array:
 *   - #4/#5 (5G / 2.4G) hang off the PCIe radio cards and are dead during
 *     U-Boot. Claiming them would only insert dark frames into the runner.
 *   - pin 6 (LED_USB1) belongs to the OS; pin 8 is the reset key and must
 *     never be claimed. The real buttons are pin 8 (reset), 99 (wifi) and
 *     103 (led), so pin 5 is NOT a button - it is the WPS status lamp and is
 *     safely driven by the failsafe runner at panel position #12.
 * => 11 lamps = the real SoC GPIO status lamps, in exact panel order.
 *
 * Why the order matters (failsafe/led.c, do NOT "simplify" this):
 *   the boot beat (RTK_LEDS_BOOT) pulses the power lamp once a second;
 *   RTK_LEDS_IDLE runs lamp_runner() along the array (one lamp + its trailing
 *   neighbour, 150 ms/step); RTK_LEDS_BUSY fills lamp_bar() from index 0;
 *   DONE holds all on for 2 s; FAILED alternates odd/even indices.
 *   => the array order IS the on-panel left-to-right sweep order.
 *
 * History: the previous array used the PT1500 panel order (power, pon, los,
 * ppp, fxs, usb0, usb1, then the four LAN lamps). That put
 * broadband/phone/USB BEFORE the GE lamps, which is the opposite of this
 * panel (GE lamps sit at #6-9, phone/broadband/USB at #10-13), so the
 * runner zig-zagged across the panel. That was fixed by putting the lamps
 * in panel order. WPS (pin 5) was then dropped along with USB1 (pin 6) on the
 * assumption pin 5 might be a button; the 2026-11-16 FDT dump proved the
 * buttons are pins 8/99/103 and that pin 5 is the WPS lamp. It is now
 * restored at its panel position (#12, between broadband and USB) so the
 * boot sweep / IDLE runner follows the silk-screen lamp-for-lamp.
 * On-unit 2026-11-19 then showed the GE segment still swept 4->1 gigabit
 * (right-to-left) with the 4/3/1/0 order: EPHY numbering is opposite to the
 * panel silk-screen (EPHY3=1st gigabit/pin0, EPHY0=4th/pin4). The GE array is
 * therefore 0/1/3/4, matching the silk-screen 1->4, same as the H10-CU board
 * whose panel hardware is identical. WPS/polarities unchanged.
 *
 * Polarity / bank constraints:
 *   * struct rtk_led.pin is a GLOBAL GPIO number (u8) and active_low is the
 *     electrical polarity (OEM DTB led-gpio third cell: 1 = active low).
 *   * rtl9617c_gpio_group_select() rejects a lamp set spanning more than one
 *     32-pin bank; all eleven pins here live in bank 0 (pin < 32).
 *
 * Only this board description is replaced at build time; geometry, FIP UUIDs,
 * BL2/BL31 and the R10 stock GPT are untouched by the lamp change.
 */
#include <config.h>
#include <linux/kernel.h>
#include <failsafe/desc.h>

static const struct rtk_led pt1570_r10_CU_4GE_lamps[] = {
	{ .pin = 11 },				/*  1 电源    LED_PWR_G  (high) */
	{ .pin = 9,  .active_low = true },	/*  2 注册    LED_PON    (low)  */
	{ .pin = 10, .active_low = true },	/*  3 光信号  LED_LOS    (low)  */
	/*  4 5G / 5 2.4G: PCIe WiFi 卡驱动，U-Boot 阶段长灭，不占位 */
	{ .pin = 0,  .active_low = true },	/*  6 千兆口1 LED_EPHY3  (low)  */
	{ .pin = 1,  .active_low = true },	/*  7 千兆口2 LED_EPHY2  (low)  */
	{ .pin = 3,  .active_low = true },	/*  8 千兆口3 LED_EPHY1  (low)  */
	{ .pin = 4,  .active_low = true },	/*  9 千兆口4 LED_EPHY0  (low)  */
	{ .pin = 12 },				/* 10 电话    LED_FXS    (high) */
	{ .pin = 2,  .active_low = true },	/* 11 宽带    LED_PPP_G  (low)  */
	{ .pin = 5 },				/* 12 WPS     LED_WPS_G  (high) */
	{ .pin = 7 },				/* 13 USB     LED_USB0   (high) */
};

static const struct rtk_board_variant pt1570_r10_cu_4ge_variant = {
	.lamp = pt1570_r10_CU_4GE_lamps,
	.nr_lamps = ARRAY_SIZE(pt1570_r10_CU_4GE_lamps),
	.pwr = { .pin = 11 },
	.ports = "4xGE (internal GPHY)",
};

static const struct rtk_board_desc pt1570_r10_cu_4ge_desc = {
	.name = "Youhua PT1570-R10-CU",
	.version = "2026.07",
	.variant = &pt1570_r10_cu_4ge_variant,
	.reset_pin = 8,
	.reset_active_low = true,
};

const struct rtk_board_desc *rtk_board_desc(void)
{
	return &pt1570_r10_cu_4ge_desc;
}
