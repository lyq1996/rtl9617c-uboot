// SPDX-License-Identifier: GPL-2.0+

/*
 * Copyright (C) 2022 Realtek Semiconductor Corp.
 *
 * Ethernet MAC driver for the Realtek RTL9617C
 */

/***

	eth: ethnet@0xf4300000 {
		compatible = "eth_cortina";
		reg = <0x0 0xf4320000 0x34>,
			<0x0 0xf4329118 0x04>,
			<0x0 0xf4304000 0x04>;
		reset-gpios = <&gpio4 16 GPIO_ACTIVE_HIGH>;
		qxgmii-phy-base = <5>;
		p0-phy-config = <1 0>; // phy-address, sds-mode
		p1-phy-config = <2 0>;
		p2-phy-config = <3 0>;
		p3-phy-config = <4 0>;
		p4-phy-config = <20 0>;
		p5-phy-config = <21 0>;
	};
***/

#include <config.h>
#include <dm.h>
#include <env.h>
#include <init.h>
#include <stdio.h>
#include <vsprintf.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <asm/arch/registers.h>
#include <asm/arch/soc.h>
#include <linux/delay.h>
#include <command.h>
#include <malloc.h>
#include <net.h>
#include <log.h>
#include <miiphy.h>
#include <env.h>
#include <u-boot/crc.h>
#include <linux/iopoll.h>

#include <rtl9617c_ni.h>
#include "rtl9617c_ni_priv.h"

#include "rtl9617c_ni_regs.h"

#include "rtl9617c_sgmii.h"

#define MODULE_NAME "NI"

#define REG_TIMEOUT_US 500000 /* max 0.5s */
#define HEADER_A_SIZE	8

u8 eth_initialize_flag; // extra, to be removed

#define RDWRPTR_ADVANCE_ONE(x, base, max)       (((x + 1) >= (u32 *)(ulong)(max)) ? (u32 *)(ulong)base : x+1)



#ifdef CONFIG_MULTICAST_UPGRADE //realtek, rtk
void ni_enter_promiscuous_mode(void)
{
	/* empty */
}
#endif

#if 0
static void _dump_packet(const char *func, u8 *packet, int length)
{
	int i;

	for (i = 0; i < length; i++) {
		if (i % 8 == 0)
			printf("\n%p: ", &packet[i]);

		printf("%02x ", packet[i]);
	}

	printf("\n");
}
#endif

static inline int is_valid_port(struct rtl9617c_ni_priv *priv, int port)
{
	if ((port >= PORT_MAX) || (port < 0) || (priv->maps[port].phy_id < 0))
		return 0;
	else
		return 1;
}

static void ni_enable_tx_rx(int port, int enable)
{
	NI_HV_PT_RXMAC_CFG_t rxmac_cfg;
	NI_HV_PT_TXMAC_CFG_t txmac_cfg;

	/* Enable TX and RX functions */
	rxmac_cfg.wrd = CORTINA_CA_REG_READ((NI_HV_PT_RXMAC_CFG + APB0_NI_HV_PT_STRIDE *
					     port));
	rxmac_cfg.bf.rx_en = enable ? 1 : 0;
	CORTINA_CA_REG_WRITE(rxmac_cfg.wrd,
			     (NI_HV_PT_RXMAC_CFG + APB0_NI_HV_PT_STRIDE * port));

	txmac_cfg.wrd = CORTINA_CA_REG_READ((NI_HV_PT_TXMAC_CFG + APB0_NI_HV_PT_STRIDE *
					     port));
	txmac_cfg.bf.tx_en = enable ? 1 : 0;
	CORTINA_CA_REG_WRITE(txmac_cfg.wrd,
			     (NI_HV_PT_TXMAC_CFG + APB0_NI_HV_PT_STRIDE * port));
}

static void cortina_ni_reset(struct rtl9617c_ni_priv *priv)
{
	NI_HV_GLB_INIT_DONE_t init_done;
	GLOBAL_BLOCK_RESET_t	glb_blk_reset;

	/* NI global resets */
	glb_blk_reset.wrd = CORTINA_CA_REG_READ(GLOBAL_BLOCK_RESET);
	glb_blk_reset.bf.reset_ni = 1;
	CORTINA_CA_REG_WRITE(glb_blk_reset.wrd, GLOBAL_BLOCK_RESET);
	glb_blk_reset.bf.reset_ni = 0;
	CORTINA_CA_REG_WRITE(glb_blk_reset.wrd, GLOBAL_BLOCK_RESET);

	if (readl_poll_timeout(NI_HV_GLB_INIT_DONE, init_done.wrd,
			       init_done.bf.ni_init_done, REG_TIMEOUT_US))
		printf("%s: NI init done not ready, init_done.wrd=0x%x!!!\n", __func__,
		       init_done.wrd);

	priv->aal_set_active_port(priv->active_port);

	if (priv->is_qxsgmii)
		priv->aal_mode_sync(NI_PORT_6, AAL_SDS_MODE_QXGMII,
				    NULL); //ca_ni_p6_qxgmii_init();
}

static int rtl9617c_ni_phy_status(struct phy_device *phy);

static void ni_auto_scan_active_port(struct rtl9617c_ni_priv *priv)
{
	u8	i;

	if (!priv->active_scan)
		return;

	priv->active_port = -1;

	for (i = 0; i < PORT_MAX; i++) {
		struct rtl9617c_ni_port *map = &priv->maps[i];
		struct phy_device *phydev;

		if (!is_valid_port(priv, i))
			continue;

		phydev = priv->bus_int->phymap[map->phy_id];

		if (!phydev)
			continue;

		rtl9617c_ni_phy_status(phydev);

		if (phydev->link) {
			printf(MODULE_NAME ": auto scan, port %d active\n", i);
			priv->active_port = i;
			return;
		}
	}

	printf(MODULE_NAME ": auto scan, no port active\n");
}


#define NI_ETH_SPEED_100 0xFFFFFFFE
#define NI_ETH_DUPLEX_FULL 0xFFFFFFD
#define PHY_MODE_MFE_MAC (1 << 12)

#define NI_RX_ENB (1 << 2)
#define NI_TX_ENB (1 << 3)
#define FLOW_CNTL_RX_DSBL (1 << 8)
#define FLOW_CNTL_TX_DSBL (1 << 12)

static int __ca_mdio_c22_write(
	CA_IN       u32             addr,
	CA_IN       u32             offset,
	CA_IN       u16             data)
{
	PER_MDIO_ADDR_t  mdio_addr;
	PER_MDIO_CTRL_t  mdio_ctrl;
	u32      loop_wait = __MDIO_ACCESS_TIMEOUT; /* up to 10000 cycles*/

	mdio_addr.wrd            = 0;
	mdio_addr.bf.mdio_addr   = addr;
	mdio_addr.bf.mdio_offset = offset;
	mdio_addr.bf.mdio_rd_wr  = __MDIO_WR_FLAG;
	CORTINA_CA_REG_WRITE(mdio_addr.wrd, PER_MDIO_ADDR);
	CORTINA_CA_REG_WRITE(data, PER_MDIO_WRDATA);

#if ETH_NI_DBG
	printf("%s: mdio_addr.wrd=0x%x\n", __func__, mdio_addr.wrd);
#endif

	mdio_ctrl.wrd          = 0;
	mdio_ctrl.bf.mdiostart = 1;
	CORTINA_CA_REG_WRITE(mdio_ctrl.wrd, PER_MDIO_CTRL);

#if ETH_NI_DBG
	printf("%s: phy_addr=%d, offset=%d, data=0x%x\n", __func__, addr, offset, data);
#endif

	do {
		mdio_ctrl.wrd = CORTINA_CA_REG_READ(PER_MDIO_CTRL);

		if (mdio_ctrl.bf.mdiodone) {
			CORTINA_CA_REG_WRITE(mdio_ctrl.wrd, PER_MDIO_CTRL);
			return CA_E_OK;
		}
	} while (--loop_wait);

	printf("%s: PHY rite timeout!!!\n", __func__);
	return CA_E_TIMEOUT;
}

static int __ca_mdio_c22_read(
	CA_IN       u32             addr,
	CA_IN       u32             offset,
	CA_OUT      u16             *data)
{
	PER_MDIO_ADDR_t  mdio_addr;
	PER_MDIO_CTRL_t  mdio_ctrl;
	PER_MDIO_RDDATA_t  read_data;
	u32      loop_wait = __MDIO_ACCESS_TIMEOUT;

	mdio_addr.wrd            = 0;
	mdio_addr.bf.mdio_addr   = addr;
	mdio_addr.bf.mdio_offset = offset;
	mdio_addr.bf.mdio_rd_wr  = __MDIO_RD_FLAG;
	CORTINA_CA_REG_WRITE(mdio_addr.wrd, PER_MDIO_ADDR);

	mdio_ctrl.wrd          = 0;
	mdio_ctrl.bf.mdiostart = 1;
	CORTINA_CA_REG_WRITE(mdio_ctrl.wrd, PER_MDIO_CTRL);

	do {
		mdio_ctrl.wrd = CORTINA_CA_REG_READ(PER_MDIO_CTRL);

		if (mdio_ctrl.bf.mdiodone) {
			CORTINA_CA_REG_WRITE(mdio_ctrl.wrd, PER_MDIO_CTRL);
			read_data.wrd = CORTINA_CA_REG_READ(PER_MDIO_RDDATA);
			*data = read_data.bf.mdio_rddata;
			return CA_E_OK;
		}
	} while (--loop_wait);

	printf("%s: CA_E_TIMEOUT!!\n", __func__);
	return CA_E_TIMEOUT;
}


static int __ca_mdio_c45_write(u32 addr, u32 offset,
				       u16 addr1, u16 data);
static int __ca_mdio_c45_read(u32 addr, u32 offset,
				      u16 addr1, u16 *data);

static inline int is_internal_phy(int addr)
{
	return ((addr >= 1) && (addr <= 4));
}

static int ca_miiphy_read(struct mii_dev *bus, int addr, int devad, int reg)
{
	u16 value;
	int result;

	if (is_internal_phy(addr)) {
		NI_MDIO_OPER_T	mdio_oper;

		mdio_oper.wrd = 0;
		mdio_oper.bf.reg_off = reg;
		mdio_oper.bf.phy_addr = addr;
		mdio_oper.bf.reg_base = CA_NI_MDIO_REG_BASE;
		return CORTINA_CA_REG_READ(mdio_oper.wrd);
	}

	addr &= 0x1f;
	if (addr == 7 && devad == MDIO_DEVAD_NONE) return 0xffff;

	if (devad == MDIO_DEVAD_NONE)
		result = __ca_mdio_c22_read(addr, reg, &value);

	else
		result = __ca_mdio_c45_read(addr, devad, reg, &value);

	if (result != CA_E_OK)
		return result;

	return value;
}

static int ca_miiphy_write(struct mii_dev *bus, int addr, int devad, int reg,
			   u16 value)
{
	if (is_internal_phy(addr)) {
		NI_MDIO_OPER_T	mdio_oper;

		mdio_oper.wrd = 0;
		mdio_oper.bf.reg_off = reg;
		mdio_oper.bf.phy_addr = addr;
		mdio_oper.bf.reg_base = CA_NI_MDIO_REG_BASE;
		CORTINA_CA_REG_WRITE(value, mdio_oper.wrd);
		return 0;
	}

	addr &= 0x1f;

	if (devad == MDIO_DEVAD_NONE)
		return __ca_mdio_c22_write(addr, reg, value);
	else
		return __ca_mdio_c45_write(addr, devad, reg, value);
}

static struct phy_device *__get_curr_phydev(struct rtl9617c_ni_priv *priv)
{
	int phy_id;

	if (!is_valid_port(priv, priv->active_port))
		return NULL;

	phy_id = priv->maps[priv->active_port].phy_id;
	debug(MODULE_NAME ":current port = %d(phy=%d)\n",
	      priv->active_port, phy_id);

	return priv->bus_int->phymap[phy_id];
}

/* Clause 45 transactions through the SoC MDIO controller. */
static int rtl9617c_mdio_transfer(u32 address, u16 value, bool read)
{
	u32 status;
	unsigned int elapsed;

	writel(BIT(0), PER_MDIO_CTRL);
	writel(address, PER_MDIO_ADDR);
	if (!read)
		writel(value, PER_MDIO_WRDATA);
	writel(BIT(7), PER_MDIO_CTRL);
	for (elapsed = 0; elapsed < 50000; elapsed++) {
		status = readl(PER_MDIO_CTRL);
		if (status & BIT(0)) {
			value = read ? readl(PER_MDIO_RDDATA) & 0xffff : 0;
			writel(BIT(0), PER_MDIO_CTRL);
			return value;
		}
		udelay(1);
	}
	printf("MDIO transaction timed out: address=%08x status=%08x\n",
	       address, status);
	return -ETIMEDOUT;
}

static int __ca_mdio_c45_write(u32 addr, u32 devad,
				       u16 reg, u16 data)
{
	u32 address = addr | devad << 8 | BIT(16);
	int ret = rtl9617c_mdio_transfer(address, reg, false);

	if (ret < 0)
		return ret;
	return rtl9617c_mdio_transfer(address | 1U << 18, data, false);
}

static int __ca_mdio_c45_read(u32 addr, u32 devad,
				      u16 reg, u16 *data)
{
	u32 address = addr | devad << 8 | BIT(16);
	int ret = rtl9617c_mdio_transfer(address, reg, false);

	if (ret < 0)
		return ret;
	ret = rtl9617c_mdio_transfer(address | 3U << 18 | BIT(15), 0, true);
	if (ret < 0)
		return ret;
	*data = ret;
	return 0;
}

/*
 * The stock firmware leaves the link state in the MAC registers, so plain
 * phy_startup() is not enough here: BMSR has to be read twice and the generic
 * code decodes speed and duplex from it.
 */
static int rtl9617c_ni_phy_status(struct phy_device *phy)
{
	int value;

	if (!phy)
		return -ENODEV;
	if (phy->is_c45)
		return phy_startup(phy);
	phy->link = 0;
	value = phy_read(phy, MDIO_DEVAD_NONE, MII_BMSR);
	if (value < 0)
		return value;
	value = phy_read(phy, MDIO_DEVAD_NONE, MII_BMSR);
	if (value < 0)
		return value;
	if (!(value & BMSR_LSTATUS) || !(value & BMSR_ANEGCOMPLETE))
		return 0;
	value = genphy_parse_link(phy);
	if (!value)
		phy->link = 1;

	return value;
}

/* No board hooks unless a board provides them. */
__weak const struct rtl9617c_ni_ops *rtl9617c_ni_board_ops(void)
{
	return NULL;
}

/*
 * Program the serdes feeding the port that carries the external 2.5G PHY.
 * Only SoC registers are involved, so the board just decides when to call it.
 */
int rtl9617c_ni_sgmii_speed(int speed)
{
	if (speed != 10 && speed != 100 && speed != 1000 && speed != 2500)
		return -EINVAL;
	rtl_sgmii_link((void *)0xf43200c4, (void *)0xf43200a0,
		       (void *)0xf43200d4, (void *)0xf433b000, speed);

	return 0;
}

/* Re-read the active link every 250 ms and re-sync the switch port with it. */
static int rtl9617c_ni_refresh_link(struct rtl9617c_ni_priv *priv)
{
	const struct rtl9617c_ni_ops *ops = rtl9617c_ni_board_ops();
	struct phy_device *phy;
	int old_port = priv->active_port, speed = -1, duplex = -1, ret;

	if (!priv->is_phyinited || get_timer(priv->link_polled) < 250)
		return 0;
	priv->link_polled = get_timer(0);
	phy = __get_curr_phydev(priv);
	if (phy) {
		speed = phy->speed;
		duplex = phy->duplex;
	}
	ret = rtl9617c_ni_phy_status(phy);
	if (ret || !phy || !phy->link) {
		if (phy)
			phy->link = 0;
		ni_auto_scan_active_port(priv);
		phy = __get_curr_phydev(priv);
	}
	if (phy && phy->link && old_port == priv->active_port &&
	    speed == phy->speed && duplex == phy->duplex)
		return 0;
	if (old_port >= 0 && is_valid_port(priv, old_port))
		ni_enable_tx_rx(old_port, 0);
	if (!phy || !phy->link) {
		priv->phydev = NULL;
		return 0;
	}
	if (ops && ops->port_speed &&
	    (ret = ops->port_speed(priv->active_port, phy->speed)))
		return ret;
	ret = priv->aal_mode_sync(priv->active_port,
				  priv->maps[priv->active_port].sds_mode, phy);
	if (ret)
		return ret;
	priv->aal_set_active_port(priv->active_port);
	priv->phydev = phy;
	ni_enable_tx_rx(priv->active_port, 1);
	printf("Recovery link: port %d, %d Mbps\n", priv->active_port, phy->speed);

	return 0;
}

static int cortina_ni_start(struct udevice *dev)
{
	struct rtl9617c_ni_priv *priv = dev_get_priv(dev);
	NI_HV_XRAM_CPUXRAM_ADRCFG_RX_t  cpuxram_adrcfg_rx;
	NI_HV_XRAM_CPUXRAM_ADRCFG_TX_0_t  cpuxram_adrcfg_tx;
	NI_HV_XRAM_CPUXRAM_CFG_t	   cpuxram_cfg;
	//NI_HV_PT_PORT_STATIC_CFG_t	port_static_cfg;
	//NI_HV_PT_PORT_GLB_CFG_t	port_glb_cfg;
	const struct rtl9617c_ni_ops *ops = rtl9617c_ni_board_ops();
	struct phy_device *phydev;

	if (!priv->is_phyinited) {
		int i, val, usable = 0;

		for (i = 0; i < PORT_MAX; i++) {
			struct rtl9617c_ni_port *m;

			if (!is_valid_port(priv, i))
				continue;

			m = &priv->maps[i];

			phydev = phy_connect(priv->bus_int, m->phy_id, dev, PHY_INTERFACE_MODE_RGMII);

			if (!phydev) {
				printf("Recovery PHY missing: port %d, MDIO %d; disabling this port\n", i, m->phy_id);
				m->phy_id = -1;
				continue;
			}
			if (phydev) {
				printf("found %s(%x)@phyaddr %d\n", phydev->drv->name, phydev->phy_id,
				       m->phy_id);
				val = phy_config(phydev);
				if (val) {
					printf("Recovery PHY port %d initialization failed (%d); disabling this port\n", i, val);
					phydev->link = 0;
					m->phy_id = -1;
					continue;
				}
				if (phydev->is_c45) { usable++; continue; }

				val = phy_read(phydev, MDIO_DEVAD_NONE, MII_BMCR);
				if (val >= 0)
					val = phy_write(phydev, MDIO_DEVAD_NONE, MII_BMCR, val & ~BMCR_PDOWN);
				if (val < 0) {
					printf("Recovery PHY port %d resume failed (%d); disabling this port\n", i, val);
					phydev->link = 0;
					m->phy_id = -1;
					continue;
				}
				usable++;
			}
		}

		if (!usable) return -ENODEV;
		/* A failed manually selected port must not hide healthy recovery ports. */
		if (!is_valid_port(priv, priv->active_port)) priv->active_scan = 1;
		ni_auto_scan_active_port(priv);
		priv->is_phyinited = 1;
	} else {
		phydev = __get_curr_phydev(priv);

		if (phydev) {
			rtl9617c_ni_phy_status(phydev);

			if (!phydev->link)
				ni_auto_scan_active_port(priv);
		} else
			ni_auto_scan_active_port(priv);
	}

	/* RX XRAM ADDRESS CONFIG (start and end address) */
	cpuxram_adrcfg_rx.wrd = 0;
	cpuxram_adrcfg_rx.bf.rx_top_addr = RX_TOP_ADDR;
	cpuxram_adrcfg_rx.bf.rx_base_addr = RX_BASE_ADDR;
	CORTINA_CA_REG_WRITE(cpuxram_adrcfg_rx.wrd, NI_HV_XRAM_CPUXRAM_ADRCFG_RX);

	/* TX XRAM ADDRESS CONFIG (start and end address) */
	cpuxram_adrcfg_tx.wrd = 0;
	cpuxram_adrcfg_tx.bf.tx_top_addr = TX_TOP_ADDR;
	cpuxram_adrcfg_tx.bf.tx_base_addr = TX_BASE_ADDR;
	CORTINA_CA_REG_WRITE(cpuxram_adrcfg_tx.wrd, NI_HV_XRAM_CPUXRAM_ADRCFG_TX_0);

	priv->phydev = __get_curr_phydev(priv);

	if (priv->phydev) {
		struct phy_device *p = priv->phydev;
		rtl9617c_ni_phy_status(p);

		if (p->link)
			printf("PHY %s ID %x %dMbps %s-duplex. no config\n", p->drv->name, p->phy_id,
			       p->speed, p->duplex == DUPLEX_HALF ? "half" : "full");
		else
			printf("PHY %s ID %x link-down\n", p->drv->name, p->phy_id);

		if (ops && ops->port_speed && ops->port_speed(priv->active_port, p->speed))
			return -EIO;
		if (priv->aal_mode_sync(priv->active_port, priv->maps[priv->active_port].sds_mode, p))
			return -EIO;

		priv->aal_set_active_port(priv->active_port);
	} else
		puts("Recovery will wait for a LAN link.\n");

#if FOR_DEBUG
	/* Enable MFE ethernet interface */
	reg_value = CORTINA_CA_REG_READ(NI_TOP_NI_INTF_RST_CONFIG);
	reg_value = reg_value & ~(INTF_RST_GE);
	CORTINA_CA_REG_WRITE(reg_value, NI_TOP_NI_INTF_RST_CONFIG);
#endif
	/* Need to toggle the tx and rx cpu_pkt_dis bit */
	/* after changing Address config register.      */
	cpuxram_cfg.wrd = CORTINA_CA_REG_READ(NI_HV_XRAM_CPUXRAM_CFG);
	cpuxram_cfg.bf.xram_mgmt_promisc_mode = priv->rxmode;
	cpuxram_cfg.bf.rx_0_cpu_pkt_dis = 1;
	cpuxram_cfg.bf.tx_0_cpu_pkt_dis = 1;
	CORTINA_CA_REG_WRITE(cpuxram_cfg.wrd, NI_HV_XRAM_CPUXRAM_CFG);
	udelay(100);
	cpuxram_cfg.bf.rx_0_cpu_pkt_dis = 0;
	cpuxram_cfg.bf.tx_0_cpu_pkt_dis = 0;
	CORTINA_CA_REG_WRITE(cpuxram_cfg.wrd, NI_HV_XRAM_CPUXRAM_CFG);

	if (is_valid_port(priv, priv->active_port)) ni_enable_tx_rx(priv->active_port, 1);

	return 0;
}

static int cortina_ni_recv(struct udevice *dev, int flags,
			   uchar **packetp) //(struct eth_device *netdev)
{
	struct rtl9617c_ni_priv 	*priv = dev_get_priv(dev);
	NI_HEADER_X_T		header_x;
	u32			pktlen = 0;
	u32 			sw_rx_rd_ptr;
	u32 			hw_rx_wr_ptr;
	volatile u32 		*rx_xram_ptr;
	int			loop;
	u32	 		*data_ptr;

	NI_PACKET_STATUS_T	packet_status;
	NI_HV_XRAM_CPUXRAM_CPU_STA_RX_0_t cpuxram_cpu_sta_rx;
	NI_HV_XRAM_CPUXRAM_CPU_CFG_RX_0_t cpuxram_cpu_cfg_rx;

	if (rtl9617c_ni_refresh_link(priv)) return -EIO;

	/* get the hw write pointer */
	cpuxram_cpu_sta_rx.wrd = CORTINA_CA_REG_READ(NI_HV_XRAM_CPUXRAM_CPU_STA_RX_0);
	hw_rx_wr_ptr = cpuxram_cpu_sta_rx.bf.pkt_wr_ptr;

	/* get the sw read pointer */
	cpuxram_cpu_cfg_rx.wrd = CORTINA_CA_REG_READ(NI_HV_XRAM_CPUXRAM_CPU_CFG_RX_0);
	sw_rx_rd_ptr = cpuxram_cpu_cfg_rx.bf.pkt_rd_ptr;

	debug("%s: NI_HV_XRAM_CPUXRAM_CPU_STA_RX_0=0x%x, NI_HV_XRAM_CPUXRAM_CPU_CFG_RX_0=0x%x\n",
	      __func__,
	      NI_HV_XRAM_CPUXRAM_CPU_STA_RX_0, NI_HV_XRAM_CPUXRAM_CPU_CFG_RX_0);

	debug("%s : RX hw_wr_ptr=%d, sw_rd_ptr=%d\n", __func__, hw_rx_wr_ptr,
	      sw_rx_rd_ptr);

	if (sw_rx_rd_ptr != hw_rx_wr_ptr) {

		/* Point to the absolute memory address of XRAM where read pointer is */
		rx_xram_ptr = (u32 *)((ulong)NI_XRAM_BASE + sw_rx_rd_ptr * 8);

		/* Wrap around if required */
		if (rx_xram_ptr >= (u32 *)(ulong)(priv->rx_xram_end_adr))
			rx_xram_ptr = (u32 *)(ulong)(priv->rx_xram_base_adr);

		/* Checking header XR. Do not update the read pointer yet */
		//rx_xram_ptr++; 	/* skip unused 32-bit in Header XR */
		rx_xram_ptr = RDWRPTR_ADVANCE_ONE(rx_xram_ptr, priv->rx_xram_base_adr,
						  priv->rx_xram_end_adr);

		header_x = (NI_HEADER_X_T)(*rx_xram_ptr);   /* Header XR [31:0] */

		if (*rx_xram_ptr == 0xffffffff)
			printf("%s: XRAM Error !\n", __func__);

		debug("%s : RX next link %x(%d) \n", __func__,	header_x.bf.next_link,
		      header_x.bf.next_link);
		debug("%s : bytes_valid %x\n", __func__, header_x.bf.bytes_valid);

		if (header_x.bf.ownership == 0) {

			//rx_xram_ptr++;	/* point to Packet status [31:0] */
			rx_xram_ptr = RDWRPTR_ADVANCE_ONE(rx_xram_ptr, priv->rx_xram_base_adr,
							  priv->rx_xram_end_adr);

			packet_status = (NI_PACKET_STATUS_T)(*rx_xram_ptr);

			debug("%s: packet_status=0x%x\n", __func__, packet_status.wrd);

			if (packet_status.bf.valid == 0) {
				debug("%s: Invalid Packet !!, Packet status=0x%x, header_x.bf.next_link=%d\n",
				      __func__, packet_status.wrd, header_x.bf.next_link);

				/* Update the software read pointer */
				CORTINA_CA_REG_WRITE(header_x.bf.next_link, NI_HV_XRAM_CPUXRAM_CPU_CFG_RX_0);
				return 0;
			}

			if (packet_status.bf.drop || packet_status.bf.runt ||
			    packet_status.bf.oversize ||
			    packet_status.bf.jabber || packet_status.bf.crc_error ||
			    packet_status.bf.jumbo) {

				debug("%s: Error Packet !! Packet status=0x%x, header_x.bf.next_link=%d\n",
				      __func__, packet_status.wrd, header_x.bf.next_link);

				/* Update the software read pointer */
				CORTINA_CA_REG_WRITE(header_x.bf.next_link, NI_HV_XRAM_CPUXRAM_CPU_CFG_RX_0);
				return 0;
			}

			/* check whether packet size is larger than 1514 */
			if (packet_status.bf.packet_size > 1518 || packet_status.bf.packet_size < 18) {

				debug("%s: Error Packet !! Packet size=%d, larger than 1518, Packet status=0x%x, header_x.bf.next_link=%d\n",
				      __func__, packet_status.bf.packet_size, packet_status.wrd,
				      header_x.bf.next_link);

				/* Update the software read pointer */
				CORTINA_CA_REG_WRITE(header_x.bf.next_link, NI_HV_XRAM_CPUXRAM_CPU_CFG_RX_0);
				return 0;

			}

			rx_xram_ptr = RDWRPTR_ADVANCE_ONE(rx_xram_ptr, priv->rx_xram_base_adr,
							  priv->rx_xram_end_adr);

			pktlen = packet_status.bf.packet_size;

			debug("%s : rx packet length = %d\n", __func__, packet_status.bf.packet_size);

			rx_xram_ptr = RDWRPTR_ADVANCE_ONE(rx_xram_ptr, priv->rx_xram_base_adr,
							  priv->rx_xram_end_adr);

			data_ptr = (u32 *)net_rx_packets[0];

			/* Read out the packet */
			/* Data is in little endian form in the XRAM */

			/* Send the packet to upper layer */
			debug("%s: packet data[]=", __func__);

			for (loop = 0; loop <= pktlen / 4; loop++) {
				*data_ptr++ = *rx_xram_ptr++;

				/* Wrap around if required */
				if (rx_xram_ptr >= (u32 *)(ulong)(priv->rx_xram_end_adr))
					rx_xram_ptr = (u32 *)(ulong)(priv->rx_xram_base_adr);
			}

			/* Update the software read pointer */
			CORTINA_CA_REG_WRITE(header_x.bf.next_link, NI_HV_XRAM_CPUXRAM_CPU_CFG_RX_0);

			*packetp = net_rx_packets[0];
			return pktlen - 4;
		}
	}

	return 0;
}


static int cortina_ni_send(struct udevice *dev, void *packet, int length)
{
	struct rtl9617c_ni_priv *priv = dev_get_priv(dev);
	u32	hw_tx_rd_ptr;
	u32	sw_tx_wr_ptr;
	unsigned int	new_pkt_len;
	unsigned char 	valid_bytes = 0;
	u32	*tx_xram_ptr;
	u16  next_link = 0;
	unsigned char	*pkt_buf_ptr;
	unsigned int	loop;
	u32 	crc;
	NI_HEADER_X_T	hdr_xt;
	int  		pad = 0;
	static unsigned char   pkt_buf[2048];
	if (!priv->phydev || !priv->phydev->link) return -ENETDOWN;
	if (length < 0 || length > 1518) return -EMSGSIZE;
#ifdef CONFIG_RTK_V7_FPGA_PLATFORM //workaround writing 8 byte
	u64 	*data_ptr;
#else
	u32 	*data_ptr;
#endif

	NI_HV_XRAM_CPUXRAM_CPU_CFG_TX_0_t	cpuxram_cpu_cfg_tx;
#if ETH_NI_DBG
	u8 *ptr;
#endif

	if ((NULL == packet) || (length > 2032))
		return -1;

	/* Get the hardware read pointer */
	//cpuxram_cpu_stat_tx.wrd = CORTINA_CA_REG_READ(NI_HV_XRAM_CPUXRAM_CPU_STAT_TX_0);
	//hw_tx_rd_ptr = cpuxram_cpu_stat_tx.bf.pkt_rd_ptr;
	hw_tx_rd_ptr = CORTINA_CA_REG_READ(NI_HV_XRAM_CPUXRAM_CPU_STAT_TX_0);

	/* Get the software write pointer */
	//cpuxram_cpu_cfg_tx.wrd = CORTINA_CA_REG_READ(NI_HV_XRAM_CPUXRAM_CPU_CFG_TX_0);
	//sw_tx_wr_ptr = cpuxram_cpu_cfg_tx.bf.pkt_wr_ptr;
	sw_tx_wr_ptr = CORTINA_CA_REG_READ(NI_HV_XRAM_CPUXRAM_CPU_CFG_TX_0);

#if ETH_NI_DBG
#if defined(CONFIG_TARGET_SATURN_FPGA) || defined(CONFIG_TARGET_SATURN_ASIC)
	printf("%s: NI_HV_XRAM_CPUXRAM_CPU_STAT_TX_0=0x%x, NI_HV_XRAM_CPUXRAM_CPU_CFG_TX_0=0x%x\n",
	       __func__,
	       KSEG1_ATU_XLAT(NI_HV_XRAM_CPUXRAM_CPU_STAT_TX_0),
	       KSEG1_ATU_XLAT(NI_HV_XRAM_CPUXRAM_CPU_CFG_TX_0));
#else
	printf("%s: NI_HV_XRAM_CPUXRAM_CPU_STAT_TX_0=0x%x, NI_HV_XRAM_CPUXRAM_CPU_CFG_TX_0=0x%x\n",
	       __func__,
	       NI_HV_XRAM_CPUXRAM_CPU_STAT_TX_0, NI_HV_XRAM_CPUXRAM_CPU_CFG_TX_0);
#endif
	printf("%s : hw_tx_rd_ptr = %d\n", __func__, hw_tx_rd_ptr);
	printf("%s : sw_tx_wr_ptr = %d\n", __func__, sw_tx_wr_ptr);
#endif

	/* lwIP may send consecutive TCP ACKs before the previous frame drains. */
	for (loop = 0; hw_tx_rd_ptr != sw_tx_wr_ptr && loop < 10000; loop++) {
		udelay(1);
		hw_tx_rd_ptr = CORTINA_CA_REG_READ(NI_HV_XRAM_CPUXRAM_CPU_STAT_TX_0);
	}
	if (hw_tx_rd_ptr != sw_tx_wr_ptr) {
		printf("%s: TX timeout (read=%x write=%x)\n", __func__, hw_tx_rd_ptr, sw_tx_wr_ptr);
		return -ETIMEDOUT;
	}

	/* Keep Ethernet length unchanged; XRAM bytes_valid handles its last word. */

	memset(pkt_buf, 0x00, sizeof(pkt_buf));

	/* add 8-byte header_A at the beginning of packet */
	//memcpy(&(pkt_buf[0]), (const void *)packet, 8);
	memcpy(&(pkt_buf[HEADER_A_SIZE]), (const void *)packet, length);

	pad = 64 - (length + 4);	/* if packet length < 60 */
	pad = (pad < 0) ? 0 : pad;

#if ETH_NI_DBG
	printf("%s: length=%d, pad=%d\n", __func__, length, pad);
#endif

	new_pkt_len = length + pad ;	/* new packet length */

	pkt_buf_ptr = (unsigned char *)pkt_buf;

	/* Calculate the CRC32 */
	/* skip 8-byte header_A */
	crc = crc32(0, (u8 *)(pkt_buf_ptr + HEADER_A_SIZE), new_pkt_len);

#if ETH_NI_DBG
	printf("%s: crc32 is 0x%x \n", __func__, crc);
	printf("%s: ~crc32 is 0x%x \n", __func__, ~crc);
	printf("%s: pkt len %d \n", __func__, new_pkt_len);
#endif
	/* should add 8-byte header_! */
	/* CRC will re-calculated by hardware */
	memcpy((pkt_buf_ptr + new_pkt_len + HEADER_A_SIZE), (u8 *)(&crc), sizeof(crc));
	new_pkt_len = new_pkt_len + 4;	/* add CRC */

	valid_bytes = new_pkt_len % 8;
	valid_bytes = valid_bytes ? valid_bytes : 0;

#if ETH_NI_DBG
	printf("%s: valid_bytes %d\n", __func__, valid_bytes);
#endif

	/* should add 8-byte headerA */
	next_link = sw_tx_wr_ptr + (new_pkt_len + 7 + HEADER_A_SIZE) / 8
		    ; /* for headr XT */
	next_link = next_link + 1; /* add header */

	/* Wrap around if required */
	if (next_link > priv->tx_xram_end)
		next_link = priv->tx_xram_start + (next_link - (priv->tx_xram_end + 1));

#if ETH_NI_DBG
	printf("%s: TX next_link %x\n", __func__, next_link);
#endif

	hdr_xt.wrd = 0;
	hdr_xt.bf.ownership = 1;
	hdr_xt.wrd |= (u32)valid_bytes << 12;
	hdr_xt.bf.next_link = next_link;

	tx_xram_ptr = (u32 *)((ulong)NI_XRAM_BASE + sw_tx_wr_ptr * 8);

	/* Wrap around if required */
	if (tx_xram_ptr >= (u32 *)(ulong)(priv->tx_xram_end_adr))
		tx_xram_ptr = (u32 *)(ulong)(priv->tx_xram_base_adr);

	tx_xram_ptr = RDWRPTR_ADVANCE_ONE(tx_xram_ptr, priv->tx_xram_base_adr,
					  priv->tx_xram_end_adr);

	*tx_xram_ptr = hdr_xt.wrd;


	tx_xram_ptr = RDWRPTR_ADVANCE_ONE(tx_xram_ptr, priv->tx_xram_base_adr,
					  priv->tx_xram_end_adr);

	/* Now to copy the data . The first byte on the line goes first */
#ifdef CONFIG_RTK_V7_FPGA_PLATFORM //workaround writing 8 byte
	data_ptr = (u64 *)pkt_buf_ptr;
#else
	data_ptr = (u32 *)pkt_buf_ptr;
#endif

#if ETH_NI_DBG
	printf("%s: packet data[]=", __func__);
#endif

	/* copy header_A to XRAM */
#ifdef CONFIG_RTK_V7_FPGA_PLATFORM //workaround writing 8 byte

	for (loop = 0; loop <= (new_pkt_len + HEADER_A_SIZE) / 8; loop++)
#else
	for (loop = 0; loop <= (new_pkt_len + HEADER_A_SIZE) / 4; loop++)
#endif
	{

#if ETH_NI_DBG
		ptr = data_ptr;

		if ((loop % 4) == 0)
			printf("\n");

		printf("[0x%x]-[0x%x]-[0x%x]-[0x%x]-", ptr[0], ptr[1], ptr[2], ptr[3]);
#endif


		*tx_xram_ptr = *data_ptr++;
		tx_xram_ptr = RDWRPTR_ADVANCE_ONE(tx_xram_ptr, priv->tx_xram_base_adr,
						  priv->tx_xram_end_adr);
	}

#if ETH_NI_DBG
	printf("\n");
#endif

	/* Publish the write pointer */
	cpuxram_cpu_cfg_tx.bf.pkt_wr_ptr = next_link;
	CORTINA_CA_REG_WRITE(next_link/*cpuxram_cpu_cfg_tx.wrd*/,
			     NI_HV_XRAM_CPUXRAM_CPU_CFG_TX_0);

	return 0;
}

static int cortina_ni_write_hwaddr(struct udevice *dev)
{
	//struct rtl9617c_ni_priv *priv = dev_get_priv(dev);
	u8 *mac = ((struct eth_pdata *)dev_get_plat(dev))->enetaddr;
	u8 port;

	NI_HV_GLB_MAC_ADDR_CFG0_t	mac_addr_cfg0;
	NI_HV_GLB_MAC_ADDR_CFG1_t	mac_addr_cfg1;
	NI_HV_PT_PORT_STATIC_CFG_t	port_static_cfg;
	NI_HV_XRAM_CPUXRAM_CFG_t 	cpuxram_cfg;

	/* parsing ethaddr and set to NI registers. */
	debug(MODULE_NAME ": MAC=%pM\n", mac);

	/* The complete MAC address consists of {MAC_ADDR0_mac_addr0[0-3], MAC_ADDR1_mac_addr1[4],
	PT_PORT_STATIC_CFG_mac_addr6[5]}. */
	mac_addr_cfg0.bf.mac_addr0 = (mac[0] << 24) + (mac[1] << 16) +
				     (mac[2] << 8) + mac[3];
	CORTINA_CA_REG_WRITE(mac_addr_cfg0.wrd, NI_HV_GLB_MAC_ADDR_CFG0);
	mac_addr_cfg0.wrd = CORTINA_CA_REG_READ(NI_HV_GLB_MAC_ADDR_CFG0);

	mac_addr_cfg1.wrd = 0;
	mac_addr_cfg1.bf.mac_addr1 = mac[4];
	CORTINA_CA_REG_WRITE(mac_addr_cfg1.wrd, NI_HV_GLB_MAC_ADDR_CFG1);

	for (port = 0; port < PORT_MAX; port++) {
		port_static_cfg.wrd = CORTINA_CA_REG_READ((NI_HV_PT_PORT_STATIC_CFG +
							   APB0_NI_HV_PT_STRIDE * port));

		port_static_cfg.bf.mac_addr6 = mac[5];
		CORTINA_CA_REG_WRITE(port_static_cfg.wrd,
				     (NI_HV_PT_PORT_STATIC_CFG + APB0_NI_HV_PT_STRIDE * port));
	}

	return 0;
}


static void cortina_ni_stop(struct udevice *dev)
{
	struct rtl9617c_ni_priv *priv = dev_get_priv(dev);
	if (is_valid_port(priv, priv->active_port))
		ni_enable_tx_rx(priv->active_port, 0);
}

/* auto scan the first link up port as active_port */
#define AUTO_SCAN_TIMEOUT	3000		/* 3 seconds */

U_BOOT_PHY_DRIVER(rtl9617c_internal) = {
	.name = "Reaktek NI Internal",
	.uid = 0x001ccac4,
	.mask = 0xfffffff0,
	.features = PHY_GBIT_FEATURES,
	.mmds = (MDIO_MMD_PMAPMD | MDIO_MMD_PCS |
		 MDIO_MMD_PHYXS | MDIO_MMD_AN |
		 MDIO_MMD_VEND1),
	.config = genphy_config,
	.startup = genphy_startup,
	.shutdown = genphy_shutdown,
};

static void init_port_map(struct rtl9617c_ni_priv *priv)
{
	int i;

	for (i = 0; i < PORT_MAX; i++)
		priv->maps[i].phy_id = -1;
}

static void set_active_port(struct rtl9617c_ni_priv *priv, int port)
{
	if (!is_valid_port(priv, port)) {
		printf("Port %d not valid\n", port);
		return;
	}

	priv->active_port = port;
}

int __weak aal_mode_sync(unsigned int port, aal_sds_mode_t mode,
			 struct phy_device *phy)
{
	printk("WARNING: %s\n", __func__);
	return 0;
}

void __weak aal_set_active_port(unsigned int port)
{
	printk("WARNING: %s\n", __func__);
}

static int cortina_of_to_plat(struct udevice *dev)
{
	struct rtl9617c_ni_priv 	*priv = dev_get_priv(dev);
	int i, ret;
	u32 v, nums[2];
	static const char * const ids[] = { "p0-phy-config", "p1-phy-config",
					    "p2-phy-config", "p3-phy-config",
					    "p4-phy-config", "p5-phy-config" };

	init_port_map(priv);

	ret = dev_read_u32(dev, "qxgmii-phy-base", &v);

	if (!ret) {
		priv->is_qxsgmii = 1;

		for (i = 0; i < 4; i++)
			priv->maps[i].phy_id = v + i;
	}

	for (i = 0; i < ARRAY_SIZE(ids); i++) {
		ret = dev_read_u32_array(dev, ids[i], nums, ARRAY_SIZE(nums));

		if (ret)
			continue;

		priv->maps[i].phy_id = nums[0];
		priv->maps[i].sds_mode = nums[1];
	}

	ret = gpio_get_list_count(dev, "reset-gpios");

	if (ret > 0) {
		if (ret > ARRAY_SIZE(priv->rst_gpios)) {
			printf("Too many gpios!\n");
			ret = ARRAY_SIZE(priv->rst_gpios);
		}

		priv->rst_gpio_count = ret;

		for (i = 0; i < ret; i++)
			gpio_request_by_name(dev, "reset-gpios", i, &priv->rst_gpios[i], GPIOD_IS_OUT);
	}

	priv->rxmode = dev_read_u32_default(dev, "rx-mode", 0) & 0x3;

	priv->aal_mode_sync = aal_mode_sync;
	priv->aal_set_active_port = aal_set_active_port;

	return 0;
}

static int cortina_ni_probe(struct udevice *dev)
{
	struct rtl9617c_ni_priv 	*priv = dev_get_priv(dev);;
	const struct rtl9617c_ni_ops *ops = rtl9617c_ni_board_ops();
	char			*buf;
	int portid, active_scan;
	struct mii_dev *mdiodev;
	int i, ret;

	if (ops && ops->prepare) {
		ret = ops->prepare();
		if (ret)
			return ret;
	}
	printf("CA NI version 0.9(DM_ETH)\n");

	cortina_ni_reset(priv);



	/* bulk reset gpios */
	for (i = 0; i < priv->rst_gpio_count; i++) {
		if (dm_gpio_is_valid(&priv->rst_gpios[i]))
			dm_gpio_set_value(&priv->rst_gpios[i], 0);
	}

	mdelay(1);

	for (i = 0; i < priv->rst_gpio_count; i++) {
		if (dm_gpio_is_valid(&priv->rst_gpios[i]))
			dm_gpio_set_value(&priv->rst_gpios[i], 1);
	}

	mdelay(1000);

	priv->rx_xram_base_adr	= NI_XRAM_BASE + (RX_BASE_ADDR * 8);
	priv->rx_xram_end_adr	= NI_XRAM_BASE + ((RX_TOP_ADDR + 1) * 8);
	priv->rx_xram_start	= RX_BASE_ADDR;
	priv->rx_xram_end	= RX_TOP_ADDR;
	priv->tx_xram_base_adr	= NI_XRAM_BASE + (TX_BASE_ADDR * 8);
	priv->tx_xram_end_adr	= NI_XRAM_BASE + ((TX_TOP_ADDR + 1) * 8);
	priv->tx_xram_start	= TX_BASE_ADDR;
	priv->tx_xram_end	= TX_TOP_ADDR;

#if ETH_NI_DBG
	printf("%s: rx_base_addr:%x\t rx_top_addr %x\n", __func__, priv->rx_xram_start,
	       priv->rx_xram_end);
	printf("%s: tx_base_addr:%x\t tx_top_addr %x\n", __func__, priv->tx_xram_start,
	       priv->tx_xram_end);
	printf("%s: rx physical start address = %x end address = %x\n", __func__,
	       priv->rx_xram_base_adr, priv->rx_xram_end_adr);
	printf("%s: tx physical start address = %x end address = %x\n",	__func__,
	       priv->tx_xram_base_adr, priv->tx_xram_end_adr);
#endif

	mdiodev = mdio_alloc();

	if (!mdiodev)
		return -ENOMEM;

	strncpy(mdiodev->name, dev->name, MDIO_NAME_LEN);
	mdiodev->read = ca_miiphy_read;
	mdiodev->write = ca_miiphy_write;
	ret = mdio_register(mdiodev);

	if (ret < 0)
		return ret;

	priv->bus_int = mdiodev;

	set_active_port(priv, 0);

	if ((buf = env_get("active_port")) != 0) {
		portid = simple_strtoul(buf, NULL, 0);
		printf(MODULE_NAME": env active_port=%d\n", portid);

		if ((portid >= 0) && (portid < PORT_MAX))
			set_active_port(priv, portid);
		else
			printk("Invalid portid %d\n", portid);
	} else
		priv->active_scan = 1;

	if ((buf = env_get("auto_scan_active_port")) != 0) {
		active_scan = simple_strtoul(buf, NULL, 0);
		priv->active_scan = !!active_scan;
	}

#if (defined(CONFIG_TARGET_PRESIDIO_ASIC) || defined(CONFIG_TARGET_VENUS) || defined(CONFIG_SOC_RTL9617C) || defined(CONFIG_TARGET_RTK_ELNATH)) && !defined(CONFIG_RTK_V7_FPGA_PLATFORM)
	/* hardware settings for RGMII port */
	{
		//GLOBAL_GLOBAL_CONFIG_t  glb_config;
		GLOBAL_IO_DRIVE_CONTROL_t io_drive_control;

		/* Generating 25Mhz reference clock for switch */
		//glb_config.wrd = CORTINA_CA_REG_READ(GLOBAL_GLOBAL_CONFIG);
		//glb_config.bf.refclk_sel = 0x01;
		//glb_config.bf.ext_reset = 0x01;
		//CORTINA_CA_REG_WRITE(glb_config.wrd, GLOBAL_GLOBAL_CONFIG);
		//
		//mdelay(20);
		//
		///* should do a external reset */
		//glb_config.wrd = CORTINA_CA_REG_READ(GLOBAL_GLOBAL_CONFIG);
		//glb_config.bf.ext_reset = 0x0;
		//CORTINA_CA_REG_WRITE(glb_config.wrd, GLOBAL_GLOBAL_CONFIG);

		io_drive_control.wrd = CORTINA_CA_REG_READ(GLOBAL_IO_DRIVE_CONTROL);
		io_drive_control.bf.gmac_mode = 2;
		io_drive_control.bf.gmac_dn = 1;
		io_drive_control.bf.gmac_dp = 1;
		CORTINA_CA_REG_WRITE(io_drive_control.wrd, GLOBAL_IO_DRIVE_CONTROL);
		mdelay(1000);
	}
#endif

	return 0;
}

#if (defined(CONFIG_SOC_RTL9617C) || defined(CONFIG_TARGET_RTK_ELNATH)) && !defined(CONFIG_RTK_V7_FPGA_PLATFORM)
void rtl9617c_ni_gphy_setup(void)
{
	WRAP_GPHY_CTRL12_t wrap_gphy_ctrl12;
	WRAP_GPHY_CTRL13_t wrap_gphy_ctrl13;
	u8 phy_addr;
	u16 val;

	/* Set WRAP_GPHY_CTRL12 cfg_ocp_timeout to 0xff */
	wrap_gphy_ctrl12.wrd = CORTINA_CA_REG_READ(WRAP_GPHY_CTRL12);
	wrap_gphy_ctrl12.bf.cfg_ocp_timeout = 0xff;
	CORTINA_CA_REG_WRITE(wrap_gphy_ctrl12.wrd, WRAP_GPHY_CTRL12);

	/* Set WRAP_GPHY_CTRL13 patch_phy_done to 1 */
	wrap_gphy_ctrl13.wrd = CORTINA_CA_REG_READ(WRAP_GPHY_CTRL13);
	wrap_gphy_ctrl13.bf.patch_phy_done = 1;
	CORTINA_CA_REG_WRITE(wrap_gphy_ctrl13.wrd, WRAP_GPHY_CTRL13);

	for (phy_addr = 4; phy_addr > 0; phy_addr--) {
		/* REG31 write 0x0007, set to extension page */
		__ca_mdio_c22_write(phy_addr, 31, 0x0007);

		/* REG30 write 0x0A43, set to extension page 2627 */
		__ca_mdio_c22_write(phy_addr, 30, 0x0A43);

		/*
		 * REG24 write bit[7] =0
		 * fix half duplex unidirectional not wire speed.
		 * we should read REG24 and clear bit[7], and write back
		 */
		__ca_mdio_c22_read(phy_addr, 24, &val);
		val &= ~(1 << 7);
		__ca_mdio_c22_write(phy_addr, 24, val);
	}
}
#endif

enum {
	__NI_MIB_RX_UC_PKT_CNT = 0x0,
	__NI_MIB_RX_MC_FRM_CNT = 0x1,
	__NI_MIB_RX_BC_FRM_CNT = 0x2,
	__NI_MIB_RX_OAM_FRM_CNT = 0x3,
	__NI_MIB_RX_JUMBO_FRM_CNT = 0x4,
	__NI_MIB_RX_PAUSE_FRM_CNT = 0x5,
	__NI_MIB_RX_PFC_FRM_CNT = 0x6,
	__NI_MIB_RX_UNK_OPCODE_FRM_CNT = 0x7,
	__NI_MIB_RX_CRC_ERR_FRM_CNT = 0x8,
	__NI_MIB_RX_UNDER_SIZE_FRM_CNT = 0x9,
	__NI_MIB_RX_RUNT_FRM_CNT = 0xA,
	__NI_MIB_RX_OVSIZE_FRM_CNT = 0xB,
	__NI_MIB_RX_JABBER_FRM_CNT = 0xC,
	__NI_MIB_RX_INVALID_FRM_CNT = 0xD,
	__NI_MIB_RX_INVALID_FLOW_FRM_CNT = 0xE,
	__NI_MIB_RX_STATS_FRM_64_OCT = 0xF,
	__NI_MIB_RX_STATS_FRM_65_TO_127_OCT = 0x10,
	__NI_MIB_RX_STATS_FRM_128_TO_255_OCT = 0x11,
	__NI_MIB_RX_STATS_FRM_256_TO_511_OCT = 0x12,
	__NI_MIB_RX_STATS_FRM_512_TO_1023_OCT = 0x13,
	__NI_MIB_RX_STATS_FRM_1024_TO_1518_OCT = 0x14,
	__NI_MIB_RX_STATS_FRM_1519_TO_2100_OCT = 0x15,
	__NI_MIB_RX_STATS_FRM_2101_TO_9200_OCT = 0x16,
	__NI_MIB_RX_STATS_FRM_9201_TO_MAX_OCT = 0x17,
	__NI_MIB_RX_BYTE_CNT = 0x18,
	__NI_MIB_RX_ALL_BYTE_CNT = 0x19,
	__NI_MIB_RX_NUM
};

enum {
	__NI_MIB_TX_UC_PKT_CNT = 0x0,
	__NI_MIB_TX_MC_FRM_CNT = 0x1,
	__NI_MIB_TX_BC_FRM_CNT = 0x2,
	__NI_MIB_TX_OAM_FRM_CNT = 0x3,
	__NI_MIB_TX_JUMBO_FRM_CNT = 0x4,
	__NI_MIB_TX_NUM
};

struct hw_mib_stats {
	uint32_t counters32[0x19];
	uint32_t txcounters32[__NI_MIB_TX_NUM];
};

enum {
	__NI_MIB_OP_CODE_READ_ONLY = 0, /* ONLY read MIB counter, not clear */
	__NI_MIB_OP_CODE_READ_CLEAR_MSB = 1, /* read MIB counter and clear MSB */
	__NI_MIB_OP_CODE_READ_CLEAR_ALL = 2  /* read MIB counter and clear all */
};

static uint32_t __mib_access(int port_id, int read_clear, int id)
{
	NI_HV_GLB_RXMIB_ACCESS_t m;

	m.wrd = 0;
	m.bf.access  = 1;
	m.bf.rbw     = 0;
	m.bf.op_code = read_clear ? __NI_MIB_OP_CODE_READ_CLEAR_ALL :
		       __NI_MIB_OP_CODE_READ_ONLY;
	m.bf.port_id = port_id;
	m.bf.counter_id = id;
	writel(m.wrd, NI_HV_GLB_RXMIB_ACCESS);

	if (readl_poll_timeout(NI_HV_GLB_RXMIB_ACCESS, m.wrd, !m.bf.access,
			       REG_TIMEOUT_US)) {
		printf("MIB access timeout\n");
		return 0;
	}

	return readl(NI_HV_GLB_RXMIB_DATA0);
}


static uint32_t __txmib_access(int port_id, int read_clear, int id)
{
	NI_HV_GLB_TXMIB_ACCESS_t m;

	m.wrd = 0;
	m.bf.access  = 1;
	m.bf.rbw     = 0;
	m.bf.op_code = read_clear ? __NI_MIB_OP_CODE_READ_CLEAR_ALL :
		       __NI_MIB_OP_CODE_READ_ONLY;
	m.bf.port_id = port_id;
	m.bf.counter_id = id;
	writel(m.wrd, NI_HV_GLB_TXMIB_ACCESS);

	if (readl_poll_timeout(NI_HV_GLB_TXMIB_ACCESS, m.wrd, !m.bf.access,
			       REG_TIMEOUT_US)) {
		printf("MIB access timeout\n");
		return 0;
	}

	return readl(NI_HV_GLB_TXMIB_DATA0);

}

static void ni_mib_rx_get(int port_id, int readclear,
			  struct hw_mib_stats *stats)
{
	int mib;

	for (mib = __NI_MIB_RX_UC_PKT_CNT; mib < __NI_MIB_RX_ALL_BYTE_CNT; mib++)
		stats->counters32[mib] = __mib_access(port_id, readclear, mib);

	for (mib = __NI_MIB_TX_UC_PKT_CNT; mib < __NI_MIB_TX_NUM; mib++)
		stats->txcounters32[mib] = __txmib_access(port_id, readclear, mib);
}

static void __dump_mib(int port)
{
	struct hw_mib_stats s;

	ni_mib_rx_get(port, 0, &s);

	printf(
		"RxUC          %8x\n"
		"RxMC          %8x\n"
		"RxBC          %8x\n"
		"RxOAM         %8x\n"
		"RxJumbo       %8x\n"
		"RxPause       %8x\n"
		"RxPFC         %8x\n"
		"RxUnkOpcode   %8x\n"
		"RxCRCErr      %8x\n"
		"RxUnderSize   %8x\n"
		"RxRunt        %8x\n"
		"RxOvsize      %8x\n"
		"RxJabber      %8x\n"
		"RxInvalid     %8x\n"
		"RxInvalidFlow %8x\n"
		"\n"
		"TxUC          %8x\n"
		"TxMC          %8x\n"
		"TxBC          %8x\n"
		"TxOAM         %8x\n",
		s.counters32[__NI_MIB_RX_UC_PKT_CNT],
		s.counters32[__NI_MIB_RX_MC_FRM_CNT],
		s.counters32[__NI_MIB_RX_BC_FRM_CNT],
		s.counters32[__NI_MIB_RX_OAM_FRM_CNT],
		s.counters32[__NI_MIB_RX_JUMBO_FRM_CNT],
		s.counters32[__NI_MIB_RX_PAUSE_FRM_CNT],
		s.counters32[__NI_MIB_RX_PFC_FRM_CNT],
		s.counters32[__NI_MIB_RX_UNK_OPCODE_FRM_CNT],
		s.counters32[__NI_MIB_RX_CRC_ERR_FRM_CNT],
		s.counters32[__NI_MIB_RX_UNDER_SIZE_FRM_CNT],
		s.counters32[__NI_MIB_RX_RUNT_FRM_CNT],
		s.counters32[__NI_MIB_RX_OVSIZE_FRM_CNT],
		s.counters32[__NI_MIB_RX_JABBER_FRM_CNT],
		s.counters32[__NI_MIB_RX_INVALID_FRM_CNT],
		s.counters32[__NI_MIB_RX_INVALID_FLOW_FRM_CNT],
		s.txcounters32[__NI_MIB_TX_UC_PKT_CNT],
		s.txcounters32[__NI_MIB_TX_MC_FRM_CNT],
		s.txcounters32[__NI_MIB_TX_BC_FRM_CNT],
		s.txcounters32[__NI_MIB_TX_OAM_FRM_CNT]
	);
}

static int do_ni_mib(struct cmd_tbl *cmdtp, int flag, int argc,
		     char *const argv[])
{
	ulong port;

	if (argc < 2)
		return CMD_RET_USAGE;

	port = simple_strtoul(argv[1], NULL, 0);

	if ((port >= 0) && (port < PORT_MAX)) {
		printf("Port %ld MIB\n", port);
		__dump_mib(port);
	}

	return 0;
}

U_BOOT_CMD(
	ni_mib,   2,      0,      do_ni_mib,
	"dump NI MIB\n",
	" <port> - dump port MIB\n"
);

#if ETH_NI_DBG
int do_eth_rx(struct cmd_tbl *cmdtp, int flag, int argc, char *const argv[])
{
	cortina_ni_recv(dbg_dev);
	return 0;
}

U_BOOT_CMD(
	do_eth_rx,   2,      1,      do_eth_rx,
	"do_eth_rx\t- to test eth_rx \n",
	"None\n"
);

int do_read_phy(struct cmd_tbl *cmdtp, int flag, int argc, char *const argv[])
{
	unsigned int	phy_adr;
	unsigned int	reg_off;
	u16	reg_val;

	phy_adr = simple_strtoul(argv[1], NULL, 0);
	reg_off = simple_strtoul(argv[2], NULL, 0);
	__ca_mdio_c22_read(phy_adr, reg_off, &reg_val);
	printf("PHY_ADR = %d offset=%d reg_val=%x \n", phy_adr, reg_off, reg_val);
	return 0;
}

U_BOOT_CMD(
	ca_phy_read,   3,      1,      do_read_phy,
	"do_read_phy\t- to read PHY register \n",
	"None\n"
);

int do_write_phy(struct cmd_tbl *cmdtp, int flag, int argc, char *const argv[])
{
	unsigned int	phy_adr;
	unsigned int	reg_off;
	unsigned int	reg_val;

	phy_adr = simple_strtoul(argv[1], NULL, 0);
	reg_off = simple_strtoul(argv[2], NULL, 0);
	reg_val = simple_strtoul(argv[3], NULL, 0);
	__ca_mdio_c22_write(phy_adr, reg_off, reg_val);
	printf("PHY_ADR = %d offset=%d reg_val=%x \n", phy_adr, reg_off, reg_val);
	return 0;
}

U_BOOT_CMD(
	ca_phy_write,   4,      1,      do_write_phy,
	"do_write_phy\t- to write PHY register \n",
	"None\n"
);

#endif

static int do_phy_reg(struct cmd_tbl *cmdtp, int flag, int argc,
		      char *const argv[])
{
	int ret, i;
	u16 phy_addr, reg, val;

	if (argc < 2) {
		printf("Usage:\nphy_reg_value%s\n", cmdtp->usage);
		return -1;
	}

	phy_addr = simple_strtoul(argv[1], NULL, 10);

	if (argc == 2) {
		/* read the first 15 registers of the PHY */
		printf("PHY addr %d:\n", phy_addr);

		for (i = 0; i < 15; i++)
			printf("Reg 0x%04X = 0x%04X\n", i, ca_miiphy_read(NULL, phy_addr,
									  MDIO_DEVAD_NONE, i));

		return 0;
	}

	reg = simple_strtoul(argv[2], NULL, 10);

	if (argc == 3) {
		/* read cmd */
		val = ca_miiphy_read(NULL, phy_addr, MDIO_DEVAD_NONE, reg);
		printf("PHY addr %d Reg 0x%04X = 0x%04X\n", phy_addr, reg, val);
	} else {
		/* argc > 3*/
		/* write cmd */
		val = simple_strtoul(argv[3], NULL, 10);
		ret = ca_miiphy_write(NULL, phy_addr, MDIO_DEVAD_NONE, reg, val);

		if (!ret)
			printf("PHY addr %d Reg 0x%04X = 0x%04X\n", phy_addr, reg, val);

		else
			printf("Can't write PHY addr %d Reg 0x%04X as 0x%04X, ret = %d\n", phy_addr,
			       reg, val, ret);
	}

	return 0;
}

U_BOOT_CMD(
	phy_reg,	4,	1,	do_phy_reg,
	"read/write PHY register",
	"[PHY addr] [reg_valueaddr] ([value])\n"
	"PHY addr : 0-31\n"
);


static int do_phy_c45(struct cmd_tbl *cmdtp, int flag, int argc,
		      char *const argv[])
{
	u16 phy, reg, addr, val;

	if ((argc != 4) && (argc != 5)) {
		printf("Usage:\nphy_reg_value%s\n", cmdtp->usage);
		return -1;
	}

	phy = simple_strtoul(argv[1], NULL, 10);
	reg = simple_strtoul(argv[2], NULL, 10);
	addr = simple_strtoul(argv[3], NULL, 10);

	if (phy > 31) {
		printf("Usage:\nphy_reg_value%s\n", cmdtp->usage);
		return -1;
	}

	if (argc == 5) {
		val = simple_strtoul(argv[4], NULL, 10);

		if (__ca_mdio_c45_write(phy, reg, addr, val))
			printf("Write %x to phy %x reg %x addr %x failed\n", val, phy, reg, addr);
	} else {
		if (__ca_mdio_c45_read(phy, reg, addr, &val))
			printf("Read phy %x reg %x addr %x failed\n", phy, reg, addr);
		else
			printf("%x\n", val);
	}



	return 0;
}
U_BOOT_CMD(
	phy_c45,	5,	1,	do_phy_c45,
	"read/write PHY register",
	"[PHY addr] [reg_valueaddr] ([value])\n"
	"PHY addr : 0-31\n"
);


static const struct eth_ops cortina_ni_ops = {
	.start		= cortina_ni_start,
	.send		= cortina_ni_send,
	.recv		= cortina_ni_recv,
	//.free_pkt	= cortina_ni_free_pkt,
	.stop		= cortina_ni_stop,
	.write_hwaddr	= cortina_ni_write_hwaddr,
};

static const struct udevice_id cortina_ni_ids[] = {
	{ .compatible = "realtek,rtl9617c-ni" },
	{ .compatible = "eth_cortina" },
	{ }
};

U_BOOT_DRIVER(rtl9617c_ni) = {
	.name	= "rtl9617c_ni",
	.id	= UCLASS_ETH,
	.of_match = cortina_ni_ids,
	.of_to_plat = cortina_of_to_plat,
	.probe	= cortina_ni_probe,
	.ops	= &cortina_ni_ops,
	.priv_auto	= sizeof(struct rtl9617c_ni_priv),
	.plat_auto	= sizeof(struct eth_pdata),
};
