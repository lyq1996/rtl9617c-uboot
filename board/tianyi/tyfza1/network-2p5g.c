// SPDX-License-Identifier: GPL-2.0+
/*
 * TYFZA1 network board code.
 *
 * The 2.5G variant powers its RTL8221B through a GPIO and PMU sequence; the
 * port map itself lives in the board device tree.
 */
#include <config.h>
#include <asm/io.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <rtl9617c_ni.h>
#include <asm/arch/soc.h>

static int tyfza1_ni_prepare(void)
{
	u32 value;

	/* Preserve the MDC divider, but explicitly select software MDIO control. */
	setbits_le32(0xf4329118, BIT(0));
	rtl9617c_gpio_output(128, false);
	mdelay(30);
	rtl9617c_gpio_output(128, true);
	mdelay(300);
	rtl9617c_gpio_output(14, true);
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

static int tyfza1_ni_port_speed(int port, int speed)
{
	/* Only port 4 runs through the external 2.5G PHY. */
	if (port != 4)
		return 0;

	return rtl9617c_ni_sgmii_speed(speed);
}

const struct rtl9617c_ni_ops *rtl9617c_ni_board_ops(void)
{
	static const struct rtl9617c_ni_ops ops = {
		.prepare = tyfza1_ni_prepare,
		.port_speed = tyfza1_ni_port_speed,
	};

	return &ops;
}
