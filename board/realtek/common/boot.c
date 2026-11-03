// SPDX-License-Identifier: GPL-2.0-only
/*
 * Boot and recovery entry, shared by every board on this platform.
 *
 * The environment a board starts from is compiled in and identical everywhere:
 * one boot command and, when the web failsafe is built in, one recovery
 * command. Nothing in the boot path depends on a value left in NAND by a
 * previous firmware, so a board with erased or unreadable environment still
 * boots.
 */
#include <asm/global_data.h>
#include <config.h>
#include <command.h>
#include <env.h>
#include <event.h>
#include <image.h>
#include <rtk_board.h>
#ifdef CONFIG_RTK_WEB_FAILSAFE
#include <failsafe/failsafe.h>
#endif
#include <ubi_uboot.h>
#include <asm/arch/soc.h>

DECLARE_GLOBAL_DATA_PTR;

static int rtk_board_env_init(void)
{
	bool repair;

	env_set("mtdids", NULL);

	repair = gd->env_valid == ENV_INVALID ||
		 ((gd->flags & GD_FLG_ENV_READY) && !env_get("bootcmd"));
	if (repair) {
		env_set_default(NULL, 0);
		if (env_save())
			printf("Environment save failed; using built-in defaults.\n");
	}

	return 0;
}

void rtk_board_late_env(void)
{
	rtk_board_env_init();
}

void rtk_board_preboot(void)
{
	rtl9617c_ni_stop_all();
	rtl9617c_xram_restore();
}

static int rtk_boot_system(void)
{
	const struct rtk_boot_layout *l = rtk_boot_layout();
	ulong address = env_get_ulong("unzip_src", 16, CONFIG_SYS_LOAD_ADDR);

	if (ubi_part((char *)l->ubi_part, NULL))
		return CMD_RET_FAILURE;
	if (ubi_volume_read((char *)l->firmware_volume, (char *)address, 0, 0)) {
		printf("No system image in %s.\n", l->firmware_volume);
		return CMD_RET_FAILURE;
	}
	if (fit_check_format((const void *)address, IMAGE_SIZE_INVAL)) {
		printf("Invalid system image in %s.\n", l->firmware_volume);
		return CMD_RET_FAILURE;
	}
	if (l->overlay_volume && !ubi_volume_exists(l->overlay_volume)) {
		ulong max = env_get_ulong("rootfs_data_max", 0, 0);

		if ((!max || ubi_volume_create(l->overlay_volume, max, true)) &&
		    ubi_volume_create(l->overlay_volume, 0, true))
			printf("No overlay volume; the system stays read-only.\n");
	}

	env_set_hex("unzip_src", address);

	return run_commandf("bootm 0x%lx", address);
}

static int do_rtk_boot(struct cmd_tbl *cmdtp, int flag, int argc,
		       char *const argv[])
{
	int ret;

	ret = rtk_boot_system();
	if (ret) {
		printf("System boot failed (%d);\n",
		       ret);
#ifdef CONFIG_RTK_WEB_FAILSAFE
		printf("Starting the recovery service\n");
		ret = rtk_start_failsafe();
#endif
	}

	return ret;
}

U_BOOT_CMD(rtk_boot, 1, 0, do_rtk_boot,
	   "boot the system from the firmware volume", "");
