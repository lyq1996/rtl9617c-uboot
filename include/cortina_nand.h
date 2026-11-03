/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Board hooks for the Cortina/Realtek SPI NAND controller.
 *
 * Long erase and write loops in the controller driver call these so a board
 * can keep a watchdog or status LEDs alive. The driver provides no-op
 * definitions; a board that wants feedback overrides them.
 */
#ifndef __CORTINA_NAND_H
#define __CORTINA_NAND_H

#include <linux/types.h>

/* Called periodically inside long running operations. */
void cortina_nand_poll(void);

/* Called after each chunk of data has been written, for progress display. */
void cortina_nand_progress(size_t bytes);

#endif /* __CORTINA_NAND_H */
