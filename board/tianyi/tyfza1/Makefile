# SPDX-License-Identifier: GPL-2.0+
obj-y += ../../realtek/common/
obj-y += ../../realtek/failsafe/
obj-y += board.o
obj-y += layout.o
obj-$(CONFIG_TARGET_TIANYI_TYFZA1_2P5G) += network-2p5g.o
ifdef CONFIG_RTK_WEB_FAILSAFE
obj-$(CONFIG_TARGET_TIANYI_TYFZA1_2P5G) += desc-2p5g.o
obj-$(CONFIG_TARGET_TIANYI_TYFZA1_4GE) += desc-4ge.o
endif
