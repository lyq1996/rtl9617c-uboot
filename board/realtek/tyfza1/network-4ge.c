// SPDX-License-Identifier: GPL-2.0+
#include <dm.h>
#include <taurus_ni.h>

static int tyfza1_ni_prepare(struct udevice *dev)
{
	struct cortina_ni_priv *priv = dev_get_priv(dev);

	priv->maps[4].phy_id = -1;
	priv->maps[5].phy_id = -1;

	return 0;
}

const struct taurus_ni_ops *taurus_ni_board_ops(void)
{
	static const struct taurus_ni_ops ops = {
		.prepare = tyfza1_ni_prepare,
	};

	return &ops;
}
