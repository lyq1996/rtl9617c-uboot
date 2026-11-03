// SPDX-License-Identifier: GPL-2.0-only
/*
 * Status lamps and the reset key, shared by the boards on this platform.
 *
 * A board lists its lamps once, in the order they sit on the front panel. What
 * they show is the same everywhere and runs along that order: a runner while
 * the recovery page waits, a progress bar while Flash is written, and a result
 * that stays until the next operation. Only the number of lamps differs.
 */
#include <config.h>
#include <time.h>
#include <string.h>
#include <cortina_nand.h>
#include "desc.h"
#include "led.h"
#include <asm/arch/soc.h>
#include <asm/io.h>
#include <linux/delay.h>
#include <linux/kernel.h>

#define BOOT_SWEEP_MS	600

static struct rtl9617c_gpio_group lamps;
static u32 lamp_bits[RTL9617C_GPIO_BANK_PINS];
static unsigned int lamp_nr;
static u32 lamp_inverted;
static enum rtk_led_state lamp_state;
static ulong lamp_since;
static size_t lamp_done, lamp_total;
static u32 lamp_lit;

static int lamp_select(void)
{
	const struct rtk_board_variant *variant = rtk_board_desc()->variant;
	unsigned int pins[RTL9617C_GPIO_BANK_PINS];
	unsigned int i;

	if (!variant || !variant->nr_lamps ||
	    variant->nr_lamps > RTL9617C_GPIO_BANK_PINS)
		return -1;
	lamp_nr = variant->nr_lamps;
	for (i = 0; i < lamp_nr; i++)
		pins[i] = variant->lamp[i].pin;
	rtl9617c_led_release();
	if (rtl9617c_gpio_group_select(&lamps, pins, lamp_nr))
		return -1;
	lamp_inverted = 0;
	for (i = 0; i < lamp_nr; i++) {
		lamp_bits[i] = BIT(pins[i] % RTL9617C_GPIO_BANK_PINS);
		if (variant->lamp[i].active_low)
			lamp_inverted |= lamp_bits[i];
	}
	lamp_lit = 0;

	return 0;
}

static void lamp_release(void)
{
	rtl9617c_gpio_group_release(&lamps);
}

/* Polled on every NAND page, so touch GPIO only when the pattern changes. */
static void lamp_show(u32 lit)
{
	if (lit == lamp_lit)
		return;
	lamp_lit = lit;
	rtl9617c_gpio_group_write(&lamps, lit ^ lamp_inverted);
}

void rtk_board_boot_leds(void)
{
	unsigned int i;

	if (lamp_state != RTK_LEDS_OFF || lamp_select())
		return;
	rtl9617c_gpio_group_claim(&lamps, lamp_inverted);
	for (i = 0; i < lamp_nr; i++) {
		lamp_show(lamp_bits[i]);
		mdelay(BOOT_SWEEP_MS / lamp_nr);
	}
	lamp_show(0);
	lamp_release();
	rtk_board_leds(RTK_LEDS_IDLE);
}

static u32 lamp_heartbeat(ulong t)
{
	t %= 2000;

	return t < 100 || (t >= 250 && t < 350) ? lamps.mask : 0;
}

/* One lamp runs along the panel, the one it just left still glowing. */
static u32 lamp_runner(ulong t)
{
	unsigned int step = t / 150 % lamp_nr;

	return step ? lamp_bits[step] | lamp_bits[step - 1] : lamp_bits[0];
}

/* The lamps before the current step stay on, the current one blinks. */
static u32 lamp_bar(ulong t)
{
	unsigned int step = lamp_total ?
		min_t(size_t, lamp_done * lamp_nr / lamp_total, lamp_nr - 1) : 0;
	u32 lit = 0;
	unsigned int i;

	for (i = 0; i < step; i++)
		lit |= lamp_bits[i];
	if (t / 300 % 2 == 0)
		lit |= lamp_bits[step];

	return lit;
}

/* Every other lamp, swapping places. */
static u32 lamp_alternate(ulong t)
{
	unsigned int i, phase = t / 150 % 2;
	u32 lit = 0;

	for (i = phase; i < lamp_nr; i += 2)
		lit |= lamp_bits[i];

	return lit;
}

/* Also called from NAND page loops, so a stalled write freezes the pattern. */
void rtk_board_leds_poll(void)
{
	ulong t;
	u32 lit = 0;

	if (lamp_state == RTK_LEDS_OFF)
		return;
	t = get_timer(lamp_since);
	switch (lamp_state) {
	case RTK_LEDS_HELD:
		lit = lamps.mask;
		break;
	case RTK_LEDS_IDLE:
		lit = lamp_runner(t);
		break;
	case RTK_LEDS_UPLOAD:
		if (t / 50 % 2 == 0)
			lit = lamp_bits[0];
		break;
	case RTK_LEDS_BUSY:
		lit = lamp_bar(t);
		break;
	case RTK_LEDS_DONE:
		lit = t < 2000 ? lamps.mask : lamp_heartbeat(t - 2000);
		break;
	case RTK_LEDS_FAILED:
		lit = lamp_alternate(t);
		break;
	default:
		break;
	}
	lamp_show(lit);
}

void rtk_board_leds(enum rtk_led_state state)
{
	if (state == RTK_LEDS_OFF) {
		if (lamp_state != RTK_LEDS_OFF)
			lamp_release();
		lamp_state = RTK_LEDS_OFF;
		return;
	}
	if (lamp_state == RTK_LEDS_OFF) {
		if (lamp_select())
			return;
		rtl9617c_gpio_group_claim(&lamps, lamp_inverted);
	} else if (state == lamp_state) {
		return;
	} else if (state == RTK_LEDS_IDLE &&
		   (lamp_state == RTK_LEDS_DONE ||
		    lamp_state == RTK_LEDS_FAILED)) {
		/* Results stay until the next upload or write replaces them. */
		return;
	}
	lamp_state = state;
	lamp_since = get_timer(0);
	rtk_board_leds_poll();
}

void rtk_board_leds_busy(size_t done, size_t total)
{
	if (lamp_state != RTK_LEDS_BUSY)
		lamp_done = lamp_total = 0;
	if (total) {
		lamp_done = min(done, total);
		lamp_total = total;
	}
	rtk_board_leds(RTK_LEDS_BUSY);
}

void rtk_board_leds_progress(size_t bytes)
{
	if (lamp_state == RTK_LEDS_BUSY)
		lamp_done += bytes;
}

/* Status lamps for long NAND operations (see include/cortina_nand.h). */
void cortina_nand_poll(void)
{
	rtk_board_leds_poll();
}

void cortina_nand_progress(size_t bytes)
{
	rtk_board_leds_progress(bytes);
}
