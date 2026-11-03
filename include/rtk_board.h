/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * What a board on this platform has to describe about itself.
 *
 * The status lamps, the reset key and the strings the recovery page shows are
 * the same logic on every board; only the pins, their polarity and the model
 * names differ. A board fills in struct rtk_board_desc once and returns it from
 * rtk_board_desc(); the board directory contains the rest.
 */
#ifndef __RTK_BOARD_H
#define __RTK_BOARD_H

/* What the boot path needs to find the system image. */
struct rtk_boot_layout {
	const char *ubi_part;		/* the single UBI partition */
	const char *firmware_volume;	/* kernel and root filesystem in one volume */
	const char *overlay_volume;
};

/* Provided by the board. */
const struct rtk_boot_layout *rtk_boot_layout(void);

/* Board lifecycle shared by every board of this platform. */
void rtk_board_late_env(void);
void rtk_board_preboot(void);

#endif /* __RTK_BOARD_H */
