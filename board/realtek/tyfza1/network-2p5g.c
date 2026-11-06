// SPDX-License-Identifier: GPL-2.0+
/*
 * TYFZA1 network board code.
 *
 * The 2.5G variant powers its RTL8221B through a GPIO and PMU sequence and
 * remaps the switch ports: the MAC driver only knows about the SoC, so the
 * board supplies this through the taurus_ni_ops hooks.
 */
#include <config.h>
#include <dm.h>
#include <phy.h>
#include <asm/io.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <taurus_ni.h>
#include <asm/arch/soc.h>

static int tyfza1_ni_prepare(struct udevice *dev)
{
	struct cortina_ni_priv *priv = dev_get_priv(dev);
	u32 value;

	/* Original PORT_REMAPPING is 4,2,1,0; port3 has no external jack. */
	priv->maps[3].phy_id = -1;
	priv->maps[4].phy_id = 7;
	priv->maps[5].phy_id = -1;
	priv->maps[4].sds_mode = AAL_SDS_MODE_SGMII;
	/* Preserve the MDC divider, but explicitly select software MDIO control. */
	setbits_le32(0xf4329118, BIT(0));
	taurus_gpio_output(128, false);
	mdelay(30);
	taurus_gpio_output(128, true);
	mdelay(300);
	taurus_gpio_output(14, true);
	mdelay(300);
	/* Original S3 power and mux sequence; preserve adjacent USB/PCIe controls. */
	value = readl(0xf43200c4);
	writel((value | BIT(25)) & ~BIT(26), 0xf43200c4);
	value = readl(0xf432036c);
	writel((value | 0xc0080000) & ~0x6020, 0xf432036c);
	writel(0x5359, 0xf460001c);
	writel(0x30, 0xf43200d0);
	writel(0x34200248, 0xf43200d4);

	return 0;
}

static int tyfza1_ni_port_speed(struct cortina_ni_priv *priv,
				struct phy_device *phy)
{
	/* Only port 4 runs through the external 2.5G PHY. */
	if (priv->active_port != 4)
		return 0;

	return taurus_ni_sgmii_speed(phy->speed);
}

const struct taurus_ni_ops *taurus_ni_board_ops(void)
{
	static const struct taurus_ni_ops ops = {
		.prepare = tyfza1_ni_prepare,
		.port_speed = tyfza1_ni_port_speed,
	};

	return &ops;
}
