// SPDX-License-Identifier: GPL-2.0+

/*
 * Copyright (C) 2022 Realtek Semiconductor Corp.
 *
 * Ethernet MAC driver for the Realtek RTL9617C
 */

#ifndef __RTL9617C_NI_PRIV_H
#define __RTL9617C_NI_PRIV_H

#include <asm/types.h>
#include <asm/io.h>
#include <asm/arch/soc.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <config.h>
#include <rtl9617c_ni.h>

struct udevice;
struct phy_device;
#include <linux/ethtool.h>

//#define ETH_NI_DBG 1

#ifdef CS_BIG_ENDIAN
#	define CRCPOLY_BE 0x04c11db7
#else /* CS_LITTLE_ENDIAN */
#	define CRCPOLY_LE 0xedb88320
#endif

#define CS_SWAP32(x) \
	(((x & 0xFF000000) >> 24) | ((x & 0xFF0000) >> 8) | ((x & 0xFF00) << 8) | \
	 ((x & 0xFF) << 24))

#define CA_IN
#define CA_OUT

#define CA_E_OK		0
#define CA_E_PARAM	(-22)
#define CA_E_PORT_ID	(-34)
#define CA_E_TIMEOUT	(-110)

#define PHY_ID_RTL8201 0x001cc810
#define PHY_ID_RTL8211 0x001cc910
#define PHY_ID_RTL8214 0x001cc940
#define PHY_ID_RTL8211_G3_ASIC 0x001cc980
#define PHY_ID_RTL8211_SATURN_ASIC 0x001cc900
#define PHY_ID_QCA8337 0x004dd035
#define PHY_ID_MASK 0xFFFFFFF0

#define GE_MAC_INTF_GMII 0x0
#define GE_MAC_INTF_MII 0x1
#define GE_MAC_INTF_RGMII_1000 0x2
#define GE_MAC_INTF_RGMII_100 0x3
#define GE_MAC_INTF_QSGMII_1000 0x4
#define GE_MAC_INTF_RMII 0x5

#define NI_TOP_NI_RTH_MAC_10M 1
#define NI_TOP_NI_RTH_MAC_100M 0
#define NI_TOP_NI_RTH_MAC_HALF 1
#define NI_TOP_NI_RTH_MAC_FULL 0

/* Defines the base and top address in CPU XRAM for packets to cpu instance 0 */
#define RX_TOP_ADDR 0x02FF /* 0x300 * 8-byte = 6K-byte */
#define RX_BASE_ADDR 0x0000

/* Defines the base and top address in CPU XRAM for packets from cpu instance
 * 0.*/
#define TX_TOP_ADDR 0x03FF /* 0x100 * 8-byte = 2K-byte */
#define TX_BASE_ADDR 0x0300

#define RX_0_CPU_PKT_DIS (1 << 0)
#define TX_0_CPU_PKT_DIS (1 << 9)

#define PHY_POLL_TIMES 0x200

#define PORT_MAX 6


typedef enum {
	AAL_SDS_SPEED_DEFAULT = 0,      /* No speed specified */
	AAL_SDS_SPEED_100M = 1,
	AAL_SDS_SPEED_1G = 2,
	AAL_SDS_SPEED_2G5 = 3,
	AAL_SDS_SPEED_5G = 4,
	AAL_SDS_SPEED_10G = 5,
	AAL_SDS_SPEED_10M = 6,
	AAL_SDS_SPEED_END
} aal_sds_speed_t;


struct port_phy_map_t {
	int8_t phy_id;
	int8_t sds_mode;
};

struct rtl9617c_ni_priv {
	unsigned int rx_xram_base_adr;
	unsigned int rx_xram_end_adr;
	unsigned short rx_xram_start;
	unsigned short rx_xram_end;
	unsigned int tx_xram_base_adr;
	unsigned int tx_xram_end_adr;
	unsigned short tx_xram_start;
	unsigned short tx_xram_end;

	struct phy_device *phydev; /* current active phydev */
	struct mii_dev *bus_int;

	struct rtl9617c_ni_port maps[RTL9617C_NI_PORTS];
	int8_t active_port;
	uint8_t rxmode;
	uint8_t active_scan;
	uint8_t is_phyinited; /* for phy detect */
	uint8_t is_qxsgmii;
	unsigned long link_polled;

	uint8_t rst_gpio_count;
	struct gpio_desc rst_gpios[PORT_MAX];

	int (*aal_mode_sync)(unsigned int port, aal_sds_mode_t, struct phy_device *);
	void (*aal_set_active_port)(unsigned int port);
};

typedef volatile union {
	struct {
		u32 next_link : 10; /* bits  9: 0 */
		u32 bytes_valid : 4; /* bits 13:10 */
		u32 reserved : 16; /* bits 29:14 */
		u32 hdr_a : 1; /* bits 30:30 */
		u32 ownership : 1; /* bits 31:31 */
	} bf;
	u32 wrd;
} NI_HEADER_X_T;

typedef volatile union {
	struct {
		u32 packet_size : 14; /* bits 13:0 */
		u32 byte_valid : 4; /* bits 17:14 */
		u32 pfc : 1; /* bits 18:18 */
		u32 valid : 1; /* bits 19:19 */
		u32 drop : 1; /* bits 20:20 */
		u32 runt : 1; /* bits 21:21 */
		u32 oversize : 1; /* bits 22:22 */
		u32 jumbo : 1; /* bits 23:23 */
		u32 link_status : 1; /* bits 24:24 */
		u32 jabber : 1; /* bits 25:25 */
		u32 crc_error : 1; /* bits 26:26 */
		u32 pause : 1; /* bits 27:27 */
		u32 oam : 1; /* bits 28:28 */
		u32 unknown_opcode : 1; /* bits 29:29 */
		u32 multicast : 1; /* bits 30:30 */
		u32 broadcast : 1; /* bits 31:31 */
	} bf;
	u32 wrd;
} NI_PACKET_STATUS_T;

#if (defined(CONFIG_TARGET_PRESIDIO_ASIC) || defined(CONFIG_TARGET_SATURN_ASIC) || defined(CONFIG_TARGET_VENUS) || defined(CONFIG_SOC_RTL9617C) || defined(CONFIG_TARGET_RTK_ELNATH)) && !defined(CONFIG_RTK_V7_FPGA_PLATFORM)

#	if defined(CONFIG_TARGET_PRESIDIO_ASIC)
#		define CA_NI_MDIO_REG_BASE 0xF4338
#	else
#		if defined(CONFIG_TARGET_VENUS)
#			define CA_NI_MDIO_REG_BASE 0xF4339
#		elif defined(CONFIG_SOC_RTL9617C)
#			define CA_NI_MDIO_REG_BASE 0xF4600
#		elif defined(CONFIG_TARGET_RTK_ELNATH)
#			define CA_NI_MDIO_REG_BASE 0xF4600
#		else
#			define CA_NI_MDIO_REG_BASE 0xD000B
#		endif

#	endif

typedef volatile union {
	struct {
		u32 reserved : 2; /* bits  1:0 */
		u32 reg_off : 5; /* bits  6:2 */
		u32 phy_addr : 5; /* bits 11:7 */
		u32 reg_base : 20; /* bits 31:12 */
	} bf;
	u32 wrd;
} NI_MDIO_OPER_T;

#endif

#define NI_PORT_0 0
#define NI_PORT_1 1
#define NI_PORT_2 2
#define NI_PORT_3 3
#define NI_PORT_4 4
#define NI_PORT_5 5
#define NI_PORT_6 6
#define NI_PORT_7 7

#define CA_NE_SGMII_LP_REG_READ CA_REG_READ
#define CA_NE_SGMII_LP_REG_WRITE CA_REG_WRITE
#define AAL_GLB_REG_READ CA_REG_READ
#define AAL_GLB_REG_WRITE CA_REG_WRITE
#define CORTINA_CA_REG_READ(off)                CA_REG_READ(off)
#define CORTINA_CA_REG_WRITE(data, off)         CA_REG_WRITE(data, off)

#if defined(CONFIG_TARGET_SATURN_FPGA) || defined(CONFIG_TARGET_SATURN_ASIC)
#	define NI_READ_POLL_COUNT 1000000
#else
#	define NI_READ_POLL_COUNT 1000
#endif

#define __MDIO_WR_FLAG (0)
#define __MDIO_RD_FLAG (1)
#define __MDIO_ACCESS_TIMEOUT (1000000)
#define __MDIO_PER_CLK (62500)
#define CA_MDIO_ADDR_MIN (1)
#define CA_MDIO_ADDR_MAX (31)
#define CA_MDIO_CLOCK_MIN (1)
#define CA_MDIO_CLOCK_MAX (20000)

#define __MDIO_ADDR_CHK(addr) \
	do { \
		if ((addr) < CA_MDIO_ADDR_MIN || (addr) > CA_MDIO_ADDR_MAX) { \
			return CA_E_PARAM; \
		} \
	} while (0)

#define CA_ASSERT(x) \
	do { \
		if (!(x)) return CA_E_PARAM; \
	} while (0)

static inline int _to_qx_ability_speed(int speed) /* map to 4 bit speed */
{
	switch (speed) {
	case SPEED_2500:
		return 3;

	case SPEED_1000:
		return 2;

	case SPEED_100:
		return 1;

	case SPEED_10:
		return 0;

	default:
		return -1;
	}
}

static inline int _to_aal_speed(int speed)
{
	switch (speed) {
	case SPEED_10000:
		return AAL_SDS_SPEED_10G;

	case SPEED_2500:
		return AAL_SDS_SPEED_2G5;

	case SPEED_1000:
		return AAL_SDS_SPEED_1G;

	case SPEED_100:
		return AAL_SDS_SPEED_100M;

	case SPEED_10:
		return AAL_SDS_SPEED_10M;

	case 0:
		return AAL_SDS_SPEED_DEFAULT;

	default:
		return -1;
	}
}


#endif /* __RTL9617C_NI_PRIV_H */
