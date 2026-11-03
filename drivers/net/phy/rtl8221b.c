// SPDX-License-Identifier: GPL-2.0-or-later
#include <config.h>
#include <phy.h>
#include <linux/delay.h>
#include <linux/iopoll.h>
#include <stdio.h>

#define phydev_err(phy, format, args...) printf("RTL8221B: " format, ##args)
#define phy_read_mmd_poll_timeout(phy, mmd, reg, value, condition, delay, timeout, sleep) ({ \
	int result = read_poll_timeout(phy_read_mmd, value, value < 0 || (condition), \
				      delay, timeout, phy, mmd, reg); \
	value < 0 ? value : result; \
})
#include "rtl8221b-init.h"

static int rtl8221b_read_mmd(struct phy_device *phy, int devad, int reg)
{
	if (!phy->is_c45 || devad < 0 || devad > 31 || reg < 0 || reg > 0xffff)
		return -EINVAL;
	return phy_read(phy, devad, reg);
}

static int rtl8221b_write_mmd(struct phy_device *phy, int devad, int reg, u16 value)
{
	if (!phy->is_c45 || devad < 0 || devad > 31 || reg < 0 || reg > 0xffff)
		return -EINVAL;
	return phy_write(phy, devad, reg, value);
}

static int rtl8221b_config(struct phy_device *phy)
{
	int ret, value;
	/* The driver is matched by PHY id; do not assume a board address. */
	if (!phy->is_c45) return -ENODEV;
	ret = rtl8221b_config_init(phy);
	if (ret) return ret;
	/* Advertise 10/100/1000/2500 full duplex and enable copper, after the mode latch. */
	ret = rtl8221b_update(phy, MDIO_MMD_VEND2, 0xa408, 0x1e0, 0x140);
	if (ret) return ret;
	ret = rtl8221b_update(phy, MDIO_MMD_VEND2, 0xa412, 0x300, 0x200);
	if (ret) return ret;
	ret = rtl8221b_update(phy, MDIO_MMD_VEND2, 0xa5d4, 0, BIT(7));
	if (ret) return ret;
	ret = rtl8221b_update(phy, MDIO_MMD_PMAPMD, MDIO_CTRL1, MDIO_CTRL1_LPOWER, 0);
	if (ret) return ret;
	value = phy_read_mmd(phy, MDIO_MMD_AN, MDIO_CTRL1);
	if (value < 0) return value;
	ret = phy_write_mmd(phy, MDIO_MMD_AN, MDIO_CTRL1,
			    value | MDIO_AN_CTRL1_ENABLE | MDIO_AN_CTRL1_RESTART);
	if (ret) return ret;
	ret = rtl8221b_wait_ready(phy);
	if (ret) return ret;
	ret = rtl8221b_check_bits(phy, MDIO_MMD_PMAPMD, MDIO_CTRL1, MDIO_CTRL1_LPOWER, 0);
	if (ret) return ret;
	puts("RTL8221B: HiSGMII mode read back; copper enabled, waiting for LAN link\n");
	return 0;
}

static int rtl8221b_startup(struct phy_device *phy)
{
	int status, value;
	phy->link = 0;
	/* Clause45 link status is latch-low; consume the old state before the live read. */
	status = phy_read_mmd(phy, MDIO_MMD_PMAPMD, MDIO_STAT1);
	if (status < 0) return status;
	status = phy_read_mmd(phy, MDIO_MMD_PMAPMD, MDIO_STAT1);
	if (status < 0) return status;
	if (!(status & MDIO_STAT1_LSTATUS)) return 0;
	value = phy_read_mmd(phy, MDIO_MMD_VEND2, 0xa434);
	if (value < 0) return value;
	switch (value & 0x630) {
	case 0: phy->speed = SPEED_10; break;
	case 0x10: phy->speed = SPEED_100; break;
	case 0x20: phy->speed = SPEED_1000; break;
	case 0x210: phy->speed = SPEED_2500; break;
	default: return -EINVAL;
	}
	phy->duplex = value & BIT(3) ? DUPLEX_FULL : DUPLEX_HALF;
	phy->link = 1;
	return 0;
}

U_BOOT_PHY_DRIVER(rtl8221b) = {
	.name = "Realtek RTL8221B",
	.uid = 0x001cc840,
	.mask = 0xfffffff0,
	.features = PHY_GBIT_FEATURES | SUPPORTED_2500baseX_Full,
	.mmds = BIT(MDIO_MMD_PMAPMD) | BIT(MDIO_MMD_PCS) | BIT(MDIO_MMD_AN) |
		BIT(MDIO_MMD_VEND1) | BIT(MDIO_MMD_VEND2),
	.config = rtl8221b_config,
	/* Generic MMD access in this U-Boot assumes only 10G PHYs use Clause45. */
	.read_mmd = rtl8221b_read_mmd,
	.write_mmd = rtl8221b_write_mmd,
	.startup = rtl8221b_startup,
	.shutdown = genphy_shutdown,
};
