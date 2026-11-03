/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Board interface of the RTL9617C NI Ethernet MAC driver.
 *
 * The MAC itself is SoC hardware, but what sits behind the switch ports is
 * board specific: an external PHY may need a power-up sequence, and a port
 * wired to a 2.5G PHY needs its SGMII rate programmed.
 * A board implements this structure and returns it from
 * rtl9617c_ni_board_ops(); the driver treats both callbacks as optional.
 */
#ifndef __RTL9617C_NI_H
#define __RTL9617C_NI_H

#include <linux/types.h>

#define RTL9617C_NI_PORTS	6

struct rtl9617c_ni_port {
	s8 phy_id;
	s8 sds_mode;
};

typedef enum {
	AAL_SDS_MODE_NONE = 0,
	AAL_SDS_MODE_SGMII = 1,         /* For SGMII/1G, HiSGMII/2.5G */
	AAL_SDS_MODE_FIBER = 2,         /* For 100BASE-X, 1000BASE-X, 2500BASE-X */
	AAL_SDS_MODE_XFI = 3,           /* For XFI/10G */
	AAL_SDS_MODE_USXGMII = 4,       /* For USXGMII/10G */
	AAL_SDS_MODE_RXAUI = 5,         /* For RXAUI/10G */
	AAL_SDS_MODE_RGMII = 6,         /* For RGMII/1G/100M */
	AAL_SDS_MODE_QXGMII = 7,        /* For QXGMII/10M/100M/1G/2.5G */
	AAL_SDS_MODE_END
} aal_sds_mode_t;

struct rtl9617c_ni_ops {
	/* Called once during probe, before the MAC is reset. */
	int (*prepare)(void);

	/* Program the serdes rate for the active port; return 0 to skip. */
	int (*port_speed)(int port, int speed);
};

/* Implemented by the board; NULL when the board needs no special handling. */
const struct rtl9617c_ni_ops *rtl9617c_ni_board_ops(void);

int rtl9617c_ni_sgmii_speed(int speed);

void rtl9617c_ni_gphy_setup(void);

#endif /* __RTL9617C_NI_H */
