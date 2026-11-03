/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * What a board on this platform has to describe about itself.
 *
 * The status lamps, the reset key and the strings the recovery page shows are
 * the same logic on every board; only the pins, their polarity and the model
 * names differ. A board fills in struct rtk_board_desc once and returns it from
 * rtk_board_desc(); the board directory contains the rest.
 */
#ifndef __RTK_DESC_H
#define __RTK_DESC_H

#include <linux/types.h>

/* One status lamp, addressed by its global GPIO number. */
struct rtk_led {
	u8 pin;
	bool active_low;
};

/*
 * The lamp wiring and the strings the recovery page shows, fixed per image:
 * every variant is its own build. The lamps are listed in panel order and must
 * all sit in one GPIO bank.
 */
struct rtk_board_variant {
	const struct rtk_led *lamp;
	unsigned int nr_lamps;
	const char *ports;			/* shown by the recovery page */
};

struct rtk_board_desc {
	const char *name;			/* "TYFZA1", "PT1500" */
	const char *version;			/* port release, shown by the UI */
	const struct rtk_board_variant *variant;
	int reset_pin;				/* global pin, -1 when absent */
	bool reset_active_low;
};

/* Provided by the board. */
const struct rtk_board_desc *rtk_board_desc(void);

#endif /* __RTK_DESC_H */
