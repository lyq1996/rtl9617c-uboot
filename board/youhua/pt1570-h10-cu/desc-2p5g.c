// SPDX-License-Identifier: GPL-2.0+
/*
 * Youhua PT1570-H10-CU (Unicom) 2.5G board description — status lamps in
 * FRONT-PANEL PHYSICAL ORDER (left -> right).
 *
 * Panel map (verified on the real unit, 2026-11-14, 13 lamp positions):
 *
 *   #   lamp        LED label     GPIO  active  driven by
 *   --  ----------  ------------  ----  ------  --------------------------
 *    1  电源        LED_PWR_G     11    high    SoC GPIO  [U-Boot]
 *    2  注册        LED_PON        9    low     SoC GPIO  [U-Boot]
 *    3  光信号      LED_LOS       10    low     SoC GPIO  [U-Boot]
 *    4  5G          5G WiFi       --    --      PCIe WiFi card  (off in U-Boot)
 *    5  2.4G        2.4G WiFi     --    --      PCIe WiFi card  (off in U-Boot)
 *    6  千兆口4     LED_EPHY3      0    low     SoC GPIO  [U-Boot]
 *    7  千兆口3     LED_EPHY2      1    low     SoC GPIO  [U-Boot]
 *    8  千兆口2     LED_EPHY1      3    low     SoC GPIO  [U-Boot]
 *    9  2.5G口      LED_EPHY0      4    low     RTL8221B PHY  (long off)
 *   10  电话        LED_FXS       12    high    SoC GPIO  [U-Boot]
 *   11  宽带        LED_PPP_G      2    low     SoC GPIO  [U-Boot]
 *   12  WPS         LED_WPS_G      5    high    SoC GPIO  [U-Boot] (2026-11-19 补入)
 *   13  USB         LED_USB0       7    high    SoC GPIO  [U-Boot]
 *
 * The user reports #4/#5 (5G, 2.4G) and #9 (2.5G jack) are "permanently dark".
 * WPS (#12) used to be in that list too, but that was a wrong diagnosis:
 *   - #4/#5 (5G / 2.4G) are PCIe radio-card LEDs with no SoC GPIO in U-Boot,
 *     so they are physically impossible to drive at this stage. They are
 *     skipped (no dark frames).
 *   - #12 WPS is a REAL SoC GPIO LED: DTS defines gpio0 pin5 active-high
 *     LED_WPS_G, and the same RTL9617C platform (PT1570-R10) proved by real
 *     hardware on 2026-11-19 that buttons are pin8/pin99/pin103 while pin5 is
 *     the WPS lamp. Claiming pin5 does NOT steal a button. It is therefore
 *     added back at its physical panel index (between 宽带 and USB) so the
 *     boot sweep / IDLE runner / progress bar light it in order.
 *   - #9 (2.5G jack) is a real SoC GPIO (pin 4, LED_EPHY0) wired to the
 *     external RTL8221B PHY, so that step may read dark. It is kept in place
 *     so the runner does not skip a physical position.
 * Net effect: 11 lamps = 10 SoC GPIO status lamps + 1 PHY-wired may-dark, in
 * exact panel order. Only 5G / 2.4G (and possibly the 2.5G jack) remain dark
 * in U-Boot; those are hardware limits, not something this build can fix.
 *
 * Why the order matters (failsafe/led.c, do NOT "simplify" this):
 *   rtk_board_boot_leds() sweeps lamp[0..n] once at power-on;
 *   RTK_LEDS_IDLE runs lamp_runner() along the array (one lamp + its trailing
 *   neighbour, 150 ms/step); RTK_LEDS_BUSY fills lamp_bar() from index 0;
 *   DONE holds all on for 2 s; FAILED alternates odd/even indices.
 *   => the array order IS the on-panel left-to-right sweep order. The run #4
 *   build reused the PT1500 panel order (power, pon, los, ppp, fxs, usb,
 *   then the four LAN lamps), which put USB/phone/internet BEFORE the GE
 *   lamps — the exact opposite of this Unicom panel (GE lamps sit at #6-8,
 *   phone/internet/USB at #10-13). That is why the runner looked "out of
 *   order" on the device even though more lamps lit up. This file puts every
 *   lamp at its true physical index.
 *
 * Polarity / bank constraints:
 *   * struct rtk_led.pin is a GLOBAL GPIO number (u8) and active_low is the
 *     electrical polarity (DTSI: &gpio0 <N> <1=low/0=high>).
 *   * rtl9617c_gpio_group_select() rejects a lamp set spanning more than one
 *     32-pin bank; all eleven pins here live in bank 0 (pin < 32).
 *   * The ten original pins/polarities are unchanged from run #4; the only
 *     addition is pin5 (WPS, active high), which is a real LED and does not
 *     touch reset pin8 or usb1 pin6. BL33 size, geometry, FIP UUIDs and the
 *     CU stock GPT are unaffected.
 *
 * Only this board description is replaced at build time; geometry, FIP UUIDs,
 * BL2/BL31 and the CU stock GPT are untouched by the lamp change.
 */
#include <config.h>
#include <linux/kernel.h>
#include <failsafe/desc.h>

static const struct rtk_led pt1570_h10_cu_2p5g_lamps[] = {
	{ .pin = 11 },				/*  1 电源    LED_PWR_G  (high) */
	{ .pin = 9,  .active_low = true },	/*  2 注册    LED_PON    (low)  */
	{ .pin = 10, .active_low = true },	/*  3 光信号  LED_LOS    (low)  */
	/*  4 5G / 5 2.4G: PCIe WiFi 卡驱动，U-Boot 阶段长灭，不占位 */
	{ .pin = 0,  .active_low = true },	/*  6 千兆口4 LED_EPHY3  (low)  */
	{ .pin = 1,  .active_low = true },	/*  7 千兆口3 LED_EPHY2  (low)  */
	{ .pin = 3,  .active_low = true },	/*  8 千兆口2 LED_EPHY1  (low)  */
	{ .pin = 4,  .active_low = true },	/*  9 2.5G口  LED_EPHY0  (PHY, 长灭) */
	{ .pin = 12 },				/* 10 电话    LED_FXS    (high) */
	{ .pin = 2,  .active_low = true },	/* 11 宽带    LED_PPP_G  (low)  */
	{ .pin = 5 },				/* 12 WPS     LED_WPS_G  (high) */
	{ .pin = 7 },				/* 13 USB     LED_USB0   (high) */
};

static const struct rtk_board_variant pt1570_h10_cu_2p5g_variant = {
	.lamp = pt1570_h10_cu_2p5g_lamps,
	.nr_lamps = ARRAY_SIZE(pt1570_h10_cu_2p5g_lamps),
	.ports = "2.5GE + 3×GE",
};

static const struct rtk_board_desc pt1570_h10_cu_2p5g_desc = {
	.name = "Youhua PT1570-H10-CU",
	.version = "2026.07",
	.variant = &pt1570_h10_cu_2p5g_variant,
	.reset_pin = 8,
	.reset_active_low = true,
};

const struct rtk_board_desc *rtk_board_desc(void)
{
	return &pt1570_h10_cu_2p5g_desc;
}
