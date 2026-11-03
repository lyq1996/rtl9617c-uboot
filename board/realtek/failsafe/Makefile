# SPDX-License-Identifier: GPL-2.0+
#
# Browser based recovery, not part of the upstream submission

obj-$(CONFIG_RTK_WEB_FAILSAFE) += failsafe.o led.o fip.o storage.o recovery.o
obj-$(CONFIG_RTK_WEB_FAILSAFE) += service.o session.o backup.o page.o

quiet_cmd_pack_page = PACK    $@
      cmd_pack_page = $(PYTHON3) $(srctree)/$(src)/pack-page.py $< $@

$(obj)/page.bin: $(srctree)/$(src)/page.html $(srctree)/$(src)/pack-page.py FORCE
	$(call if_changed,pack_page)

$(obj)/page.c: $(obj)/page.bin FORCE
	$(call if_changed,bin2c,rtk_failsafe_page)

targets += page.bin page.c
