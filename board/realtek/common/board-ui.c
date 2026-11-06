// SPDX-License-Identifier: GPL-2.0-only
/*
 * Status lamps and the reset key, shared by the boards on this platform.
 *
 * What the lamps show is the same on every board: a heartbeat while the
 * recovery page waits, a progress bar while Flash is written, and a result that
 * stays until the next operation. What differs is which pins drive them and how
 * they are wired, and the board says that once in struct rtk_board_desc.
 */
#include <config.h>
#include <time.h>
#include <string.h>
#include <cortina_nand.h>
#include <rtk_board.h>
#include <asm/arch/soc.h>
#include <asm/arch/registers.h>
#include <asm/io.h>
#include <linux/delay.h>
#include <linux/kernel.h>

static struct taurus_gpio_group lamps;
static u32 lamp_bits[RTK_BOARD_LAMPS];
static bool lamp_inverted[RTK_BOARD_LAMPS];
static enum rtk_led_state lamp_state;
static ulong lamp_since;
static size_t lamp_done, lamp_total;
static u32 lamp_lit;

static void lamp_hw_release(void)
{
	writel(0, GLOBAL_LED_CONTROL);
	writel(BIT(15), GLOBAL_LED_CONFIG_0);
	writel(BIT(15), GLOBAL_LED_CONFIG_1);
	writel(BIT(15), GLOBAL_LED_CONFIG_3);
	writel(BIT(15), GLOBAL_LED_CONFIG_4);
	writel(BIT(15), GLOBAL_LED_CONFIG_11);
}

static int lamp_select(void)
{
	const struct rtk_board_variant *variant = rtk_board_desc()->variant;
	unsigned int pins[RTK_BOARD_LAMPS];
	unsigned int i;

	if (!variant)
		return -1;
	lamp_hw_release();
	for (i = 0; i < RTK_BOARD_LAMPS; i++) {
		pins[i] = variant->lamp[i].pin;
		lamp_inverted[i] = variant->lamp[i].active_low;
	}
	if (taurus_gpio_group_select(&lamps, pins, RTK_BOARD_LAMPS))
		return -1;
	for (i = 0; i < RTK_BOARD_LAMPS; i++)
		lamp_bits[i] = BIT(pins[i] % TAURUS_GPIO_BANK_PINS);
	lamp_lit = 0;

	return 0;
}

/* Output levels for a set of lit lamps; unlit ones sit at their idle level. */
static u32 lamp_levels(u32 lit)
{
	u32 values = 0;
	unsigned int i;

	for (i = 0; i < RTK_BOARD_LAMPS; i++) {
		bool on = lit & lamp_bits[i];
		bool level = lamp_inverted[i] ? !on : on;

		if (level)
			values |= lamp_bits[i];
	}

	return values;
}

static void lamp_release(void)
{
	taurus_gpio_group_release(&lamps);
}

/* Polled on every NAND page, so touch GPIO only when the pattern changes. */
static void lamp_show(u32 lit)
{
	if (lit == lamp_lit)
		return;
	lamp_lit = lit;
	taurus_gpio_group_write(&lamps, lamp_levels(lit));
}

bool rtk_board_reset_held(void)
{
	const struct rtk_board_desc *desc = rtk_board_desc();
	unsigned int i;

	if (!desc || desc->reset_pin < 0)
		return false;
	taurus_gpio_input(desc->reset_pin);
	/* Sample before PHY discovery, so releasing Reset during it is harmless. */
	for (i = 0; i < 3; i++) {
		bool level = taurus_gpio_get(desc->reset_pin);

		if (level != !desc->reset_active_low)
			return false;
		udelay(1000);
	}

	return true;
}

void rtk_board_boot_leds(void)
{
	unsigned int i;

	if (lamp_state != RTK_LEDS_OFF || lamp_select())
		return;
	taurus_gpio_group_claim(&lamps, lamp_levels(0));
	for (i = 0; i < RTK_BOARD_LAMPS; i++) {
		lamp_show(lamp_bits[i]);
		mdelay(150);
		lamp_show(0);
	}
	lamp_release();
	rtk_board_leds(RTK_LEDS_IDLE);
}

static u32 lamp_heartbeat(ulong t)
{
	t %= 2000;

	return t < 100 || (t >= 250 && t < 350) ? lamps.mask : 0;
}

/* Power lamp stays on; the four LAN lamps run a chase. */
static u32 lamp_chase(ulong t)
{
	unsigned int step = (t / 200) % 4;

	return lamp_bits[4] | lamp_bits[step];
}

/* Also called from NAND page loops, so a stalled write freezes the pattern. */
void rtk_board_leds_poll(void)
{
	ulong t;
	u32 lit = 0;
	unsigned int i, step;

	if (lamp_state == RTK_LEDS_OFF)
		return;
	t = get_timer(lamp_since);
	switch (lamp_state) {
	case RTK_LEDS_HELD:
		lit = lamps.mask;
		break;
	case RTK_LEDS_IDLE:
		lit = lamp_chase(t);
		break;
	case RTK_LEDS_UPLOAD:
		if (t / 50 % 2 == 0)
			lit = lamp_bits[0];
		break;
	case RTK_LEDS_BUSY:
		step = lamp_total ? min_t(size_t, lamp_done * 4 / lamp_total, 3) : 0;
		for (i = 0; i < step; i++)
			lit |= lamp_bits[i];
		if (t / 300 % 2 == 0)
			lit |= lamp_bits[step];
		break;
	case RTK_LEDS_DONE:
		lit = t < 2000 ? lamps.mask : lamp_heartbeat(t - 2000);
		break;
	case RTK_LEDS_FAILED:
		i = t / 150 % 2;
		lit = lamp_bits[i] | lamp_bits[i + 2];
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
		taurus_gpio_group_claim(&lamps, lamp_levels(0));
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
	lamp_done = done;
	lamp_total = total;
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
