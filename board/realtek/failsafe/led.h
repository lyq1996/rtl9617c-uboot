/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __RTK_LED_H
#define __RTK_LED_H

#include <linux/types.h>

/* States the lamps can show. */
enum rtk_led_state {
	RTK_LEDS_OFF,		/* pins returned to their previous owner */
	RTK_LEDS_HELD,		/* reset recognised: all on, safe to release */
	RTK_LEDS_IDLE,		/* waiting for a client: runner along the panel */
	RTK_LEDS_UPLOAD,	/* receiving into RAM: first lamp flickers */
	RTK_LEDS_BUSY,		/* writing Flash: progress bar along the panel */
	RTK_LEDS_DONE,		/* write succeeded: all on for two seconds */
	RTK_LEDS_FAILED,	/* write failed: odd and even lamps alternate */
};

void rtk_board_boot_leds(void);
void rtk_board_leds(enum rtk_led_state state);
void rtk_board_leds_busy(size_t done, size_t total);
void rtk_board_leds_progress(size_t bytes);
void rtk_board_leds_poll(void);

#endif /* __RTK_LED_H */
