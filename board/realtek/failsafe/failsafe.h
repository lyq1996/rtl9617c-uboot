/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __RTK_FAILSAFE_H
#define __RTK_FAILSAFE_H

void rtk_board_reset_latch(void);
int rtk_web_failsafe_start(void);
int rtk_start_failsafe(void);
int rtk_board_failsafe_spy(void);

#endif /* __RTK_FAILSAFE_H */
