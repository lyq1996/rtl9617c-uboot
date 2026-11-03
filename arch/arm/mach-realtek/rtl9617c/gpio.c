// SPDX-License-Identifier: GPL-2.0+
/*
 * Realtek RTL9617C GPIO.
 *
 * The controller has five banks of 32 pins. Each bank owns a pin mux, a
 * direction and an output register, and the mux bit has to be set before a pad
 * is readable or drivable as GPIO. Pins are addressed globally here so a board
 * never has to know about the banking.
 */
#include <config.h>
#include <asm/io.h>
#include <linux/kernel.h>
#include <asm/arch/registers.h>
#include <linux/errno.h>
#include <asm/arch/soc.h>

struct rtl9617c_gpio_bank {
	unsigned long cfg;
	unsigned long out;
	unsigned long in;
	unsigned long mux;
};

static const struct rtl9617c_gpio_bank rtl9617c_gpio_banks[RTL9617C_GPIO_BANKS] = {
	{ PER_GPIO0_CFG, PER_GPIO0_OUT, PER_GPIO0_IN, GLOBAL_GPIO_MUX_0 },
	{ PER_GPIO1_CFG, PER_GPIO1_OUT, PER_GPIO1_IN, GLOBAL_GPIO_MUX_1 },
	{ PER_GPIO2_CFG, PER_GPIO2_OUT, PER_GPIO2_IN, GLOBAL_GPIO_MUX_2 },
	{ PER_GPIO3_CFG, PER_GPIO3_OUT, PER_GPIO3_IN, GLOBAL_GPIO_MUX_3 },
	{ PER_GPIO4_CFG, PER_GPIO4_OUT, PER_GPIO4_IN, GLOBAL_GPIO_MUX_4 },
};

static const struct rtl9617c_gpio_bank *bank_of(unsigned int pin)
{
	if (pin >= RTL9617C_GPIO_PINS)
		return NULL;

	return &rtl9617c_gpio_banks[pin / RTL9617C_GPIO_BANK_PINS];
}

void rtl9617c_led_release(void)
{
	writel(0, GLOBAL_LED_CONTROL);
	writel(BIT(15), GLOBAL_LED_CONFIG_0);
	writel(BIT(15), GLOBAL_LED_CONFIG_1);
	writel(BIT(15), GLOBAL_LED_CONFIG_3);
	writel(BIT(15), GLOBAL_LED_CONFIG_4);
	writel(BIT(15), GLOBAL_LED_CONFIG_11);
}

int rtl9617c_gpio_group_select(struct rtl9617c_gpio_group *group,
			     const unsigned int *pins, unsigned int count)
{
	unsigned int i;

	if (!count || count > RTL9617C_GPIO_BANK_PINS || !bank_of(pins[0]))
		return -EINVAL;

	group->bank = pins[0] / RTL9617C_GPIO_BANK_PINS;
	group->mask = 0;
	for (i = 0; i < count; i++) {
		/* A group is driven in one register write, so one bank only. */
		if (pins[i] >= RTL9617C_GPIO_PINS ||
		    pins[i] / RTL9617C_GPIO_BANK_PINS != group->bank)
			return -EINVAL;
		group->mask |= BIT(pins[i] % RTL9617C_GPIO_BANK_PINS);
	}

	return 0;
}

void rtl9617c_gpio_group_claim(struct rtl9617c_gpio_group *group, u32 values)
{
	const struct rtl9617c_gpio_bank *bank = &rtl9617c_gpio_banks[group->bank];

	group->mux = readl(bank->mux);
	group->cfg = readl(bank->cfg);
	group->out = readl(bank->out);

	setbits_le32(bank->mux, group->mask);
	clrsetbits_le32(bank->out, group->mask, values & group->mask);
	clrbits_le32(bank->cfg, group->mask);
}

void rtl9617c_gpio_group_write(struct rtl9617c_gpio_group *group, u32 values)
{
	const struct rtl9617c_gpio_bank *bank = &rtl9617c_gpio_banks[group->bank];

	clrsetbits_le32(bank->out, group->mask, values & group->mask);
}

void rtl9617c_gpio_group_release(struct rtl9617c_gpio_group *group)
{
	const struct rtl9617c_gpio_bank *bank = &rtl9617c_gpio_banks[group->bank];

	clrsetbits_le32(bank->out, group->mask, group->out & group->mask);
	clrsetbits_le32(bank->cfg, group->mask, group->cfg & group->mask);
	clrsetbits_le32(bank->mux, group->mask, group->mux & group->mask);
}

void rtl9617c_gpio_input(unsigned int pin)
{
	const struct rtl9617c_gpio_bank *bank = bank_of(pin);

	if (!bank)
		return;
	setbits_le32(bank->mux, BIT(pin % RTL9617C_GPIO_BANK_PINS));
	setbits_le32(bank->cfg, BIT(pin % RTL9617C_GPIO_BANK_PINS));
}

void rtl9617c_gpio_output(unsigned int pin, bool value)
{
	const struct rtl9617c_gpio_bank *bank = bank_of(pin);
	u32 bit;

	if (!bank)
		return;
	bit = BIT(pin % RTL9617C_GPIO_BANK_PINS);
	setbits_le32(bank->mux, bit);
	clrsetbits_le32(bank->out, bit, value ? bit : 0);
	clrbits_le32(bank->cfg, bit);
}

void rtl9617c_gpio_set(unsigned int pin, bool value)
{
	const struct rtl9617c_gpio_bank *bank = bank_of(pin);
	u32 bit;

	if (!bank)
		return;
	bit = BIT(pin % RTL9617C_GPIO_BANK_PINS);
	clrsetbits_le32(bank->out, bit, value ? bit : 0);
}

bool rtl9617c_gpio_get(unsigned int pin)
{
	const struct rtl9617c_gpio_bank *bank = bank_of(pin);

	if (!bank)
		return false;

	return readl(bank->in) & BIT(pin % RTL9617C_GPIO_BANK_PINS);
}
