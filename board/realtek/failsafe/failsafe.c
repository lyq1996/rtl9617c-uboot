// SPDX-License-Identifier: GPL-2.0-only
#include <config.h>
#include <stdio.h>
#include <linux/delay.h>
#include <asm/arch/soc.h>
#include "failsafe.h"
#include "desc.h"
#include "led.h"

void board_autoboot_fail(void)
{
	printf("Boot failed; starting the recovery service\n");
	rtk_start_failsafe();
}

static bool rtk_board_reset_held(void)
{
	const struct rtk_board_desc *desc = rtk_board_desc();
	unsigned int i;

	if (!desc || desc->reset_pin < 0)
		return false;
	rtl9617c_gpio_input(desc->reset_pin);
	/* Sample before PHY discovery, so releasing Reset during it is harmless. */
	for (i = 0; i < 3; i++) {
		bool level = rtl9617c_gpio_get(desc->reset_pin);
		if (level != !desc->reset_active_low)
			return false;
		udelay(1000);
	}

	return true;
}

static bool reset_latched;
void rtk_board_reset_latch(void)
{
	reset_latched = rtk_board_reset_held();
}

int rtk_start_failsafe(void)
{
	int ret = rtk_web_failsafe_start();

	if (ret)
		printf("Web failsafe service failed (%d).\n", ret);

	return ret;
}

int rtk_board_failsafe_spy(void)
{
	int ret;

	if (!reset_latched) {
		puts("Reset released: normal boot\n");
		return 0;
	}
	if (reset_latched)
		rtk_board_leds(RTK_LEDS_HELD);

	rtk_board_boot_leds();
	puts("Reset held: starting the web failsafe service\n");
	ret = rtk_start_failsafe();
	rtk_board_leds(RTK_LEDS_OFF);
	if (ret)
		printf("Web failsafe service failed (%d).\n", ret);

	return 0;
}