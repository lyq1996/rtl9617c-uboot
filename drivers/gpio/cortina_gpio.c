// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2020 Cortina-Access
 *
 * GPIO Driver for Cortina Access CAxxxx Line of SoCs
 */

#include <dm.h>
#include <log.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <linux/bitops.h>
#include <linux/compat.h>
#include <linux/compiler.h>

/* GPIO Register Map */
#define CORTINA_GPIO_CFG	0x00
#define CORTINA_GPIO_OUT	0x04
#define CORTINA_GPIO_IN		0x08
#define CORTINA_GPIO_LVL	0x0C
#define CORTINA_GPIO_EDGE	0x10
#define CORTINA_GPIO_BOTHEDGE	0x14
#define CORTINA_GPIO_IE		0x18
#define CORTINA_GPIO_INT	0x1C
#define CORTINA_GPIO_STAT	0x20

/* Distance between the register sets of two consecutive banks. */
#define CORTINA_GPIO_BANK_STRIDE	0x24
#define CORTINA_GPIO_BANK_PINS		32

struct cortina_gpio_bank {
	void __iomem *base;
	void __iomem *mux;	/* optional pin mux block (second reg) */
};

/*
 * The controller has several banks of 32 pins; the uclass offset is the global
 * pin number, so the bank has to be decoded from it. The first reg covers every
 * bank's registers back to back, and the optional second reg is the matching
 * run of pin mux words.
 */
static u32 ca_gpio_bit(unsigned int offset)
{
	return BIT(offset % CORTINA_GPIO_BANK_PINS);
}

static void __iomem *ca_gpio_reg(struct cortina_gpio_bank *priv,
				 unsigned int offset, u32 reg)
{
	return priv->base +
	       (offset / CORTINA_GPIO_BANK_PINS) * CORTINA_GPIO_BANK_STRIDE + reg;
}

/*
 * The RTL9617C routes a GPIO through a mux block that has to be enabled
 * before the pad is usable. Older Cortina parts have no such block, so the
 * second reg is optional.
 */
static void ca_gpio_select(struct cortina_gpio_bank *priv, unsigned int offset)
{
	if (priv->mux)
		setbits_32(priv->mux + (offset / CORTINA_GPIO_BANK_PINS) * 4,
			   ca_gpio_bit(offset));
}

#ifdef CONFIG_DM_GPIO
static int ca_gpio_direction_input(struct udevice *dev, unsigned int offset)
{
	struct cortina_gpio_bank *priv = dev_get_priv(dev);

	ca_gpio_select(priv, offset);
	setbits_32(ca_gpio_reg(priv, offset, CORTINA_GPIO_CFG),
		   ca_gpio_bit(offset));
	return 0;
}

static int
ca_gpio_direction_output(struct udevice *dev, unsigned int offset, int value)
{
	struct cortina_gpio_bank *priv = dev_get_priv(dev);

	ca_gpio_select(priv, offset);
	if (value)
		setbits_32(ca_gpio_reg(priv, offset, CORTINA_GPIO_OUT),
			   ca_gpio_bit(offset));
	else
		clrbits_32(ca_gpio_reg(priv, offset, CORTINA_GPIO_OUT),
			   ca_gpio_bit(offset));
	clrbits_32(ca_gpio_reg(priv, offset, CORTINA_GPIO_CFG),
		   ca_gpio_bit(offset));
	return 0;
}

static int ca_gpio_get_value(struct udevice *dev, unsigned int offset)
{
	struct cortina_gpio_bank *priv = dev_get_priv(dev);

	return (readl(ca_gpio_reg(priv, offset, CORTINA_GPIO_IN)) &
		ca_gpio_bit(offset)) ? 1 : 0;
}

static int ca_gpio_set_value(struct udevice *dev, unsigned int offset,
			     int value)
{
	struct cortina_gpio_bank *priv = dev_get_priv(dev);

	if (value)
		setbits_32(ca_gpio_reg(priv, offset, CORTINA_GPIO_OUT),
			   ca_gpio_bit(offset));
	else
		clrbits_32(ca_gpio_reg(priv, offset, CORTINA_GPIO_OUT),
			   ca_gpio_bit(offset));
	return 0;
}

static int ca_gpio_get_function(struct udevice *dev, unsigned int offset)
{
	struct cortina_gpio_bank *priv = dev_get_priv(dev);

	if (readl(ca_gpio_reg(priv, offset, CORTINA_GPIO_CFG)) &
	    ca_gpio_bit(offset))
		return GPIOF_INPUT;
	else
		return GPIOF_OUTPUT;
}

static const struct dm_gpio_ops gpio_cortina_ops = {
	.direction_input = ca_gpio_direction_input,
	.direction_output = ca_gpio_direction_output,
	.get_value = ca_gpio_get_value,
	.set_value = ca_gpio_set_value,
	.get_function = ca_gpio_get_function,
};

static int ca_gpio_probe(struct udevice *dev)
{
	struct gpio_dev_priv *uc_priv = dev_get_uclass_priv(dev);
	struct cortina_gpio_bank *priv = dev_get_priv(dev);

	priv->base = dev_remap_addr_index(dev, 0);
	if (!priv->base)
		return -EINVAL;

	/* Optional second reg: the pin mux block on the RTL9617C. */
	priv->mux = dev_remap_addr_index(dev, 1);

	uc_priv->gpio_count = dev_read_u32_default(dev, "ngpios", 32);
	uc_priv->bank_name = dev->name;

	debug("Done Cortina GPIO init\n");
	return 0;
}

static const struct udevice_id ca_gpio_ids[] = {
	{.compatible = "cortina,ca-gpio"},
	{}
};

U_BOOT_DRIVER(cortina_gpio) = {
	.name = "cortina-gpio",
	.id = UCLASS_GPIO,
	.ops = &gpio_cortina_ops,
	.probe = ca_gpio_probe,
	.priv_auto	= sizeof(struct cortina_gpio_bank),
	.of_match = ca_gpio_ids,
};
#endif /* CONFIG_DM_GPIO */
