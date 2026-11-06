// SPDX-License-Identifier: GPL-2.0-only
/*
 * Boot and recovery entry, shared by every board on this platform.
 *
 * The environment a board starts from is compiled in and identical everywhere:
 * one boot command, one recovery command. Nothing in the boot path depends on
 * a value left in NAND by a previous firmware, so a board with erased or
 * unreadable environment still boots.
 */
#include <asm/global_data.h>
#include <config.h>
#include <command.h>
#include <env.h>
#include <event.h>
#include <net/httpd.h>
#include <image.h>
#include <rtk_board.h>
#include <rtk_recovery.h>
#include <ubi_uboot.h>
#include <asm/arch/soc.h>

DECLARE_GLOBAL_DATA_PTR;

/* Set by board_init() and reported by the lamps until the recovery starts. */
static bool reset_latched;

int rtk_board_env_init(void)
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

void rtk_board_reset_latch(void)
{
	reset_latched = rtk_board_reset_held();
}

void rtk_board_late_env(void)
{
	rtk_board_env_init();
	if (reset_latched)
		rtk_board_leds(RTK_LEDS_HELD);
}

void rtk_board_preboot(void)
{
	rtk_board_leds(RTK_LEDS_OFF);
	taurus_ni_stop_all();
	taurus_xram_restore();
}

/*
 * Read the system image - kernel and root filesystem in one volume - and
 * start it. Shared by the boot command and by the recovery service when it
 * boots an uploaded image.
 */
int rtk_boot_system(void)
{
	const struct rtk_recovery_layout *l = rtk_recovery_layout();
	ulong address = env_get_ulong("unzip_src", 16, CONFIG_SYS_LOAD_ADDR);

	if (ubi_part((char *)l->ubi_part, NULL))
		return CMD_RET_FAILURE;
	if (ubi_volume_read(l->firmware_volume, (char *)address, 0, 0)) {
		printf("No system image in %s.\n", l->firmware_volume);
		return CMD_RET_FAILURE;
	}
	if (fit_check_format((const void *)address, IMAGE_SIZE_INVAL)) {
		printf("Invalid system image in %s.\n", l->firmware_volume);
		return CMD_RET_FAILURE;
	}
	if (l->overlay_volume && !ubi_volume_exists(l->overlay_volume) &&
	    ubi_volume_create(l->overlay_volume, 0, true))
		printf("No overlay volume; the system stays read-only.\n");

	env_set_hex("unzip_src", address);

	return run_commandf("bootm 0x%lx", address);
}

static int rtk_start_recovery(void);

static int do_rtk_boot(struct cmd_tbl *cmdtp, int flag, int argc,
		       char *const argv[])
{
	int ret;

	ret = rtk_boot_system();
	if (ret) {
		printf("System boot failed (%d); starting the HTTP recovery\n",
		       ret);
		ret = rtk_start_recovery();
	}

	return ret;
}

U_BOOT_CMD(rtk_boot, 1, 0, do_rtk_boot,
	   "boot the system from the firmware volume", "");

void board_autoboot_fail(void)
{
	printf("Boot failed; starting the HTTP recovery\n");
	rtk_start_recovery();
}

/*
 * The recovery service is a build option: a board that leaves CONFIG_CMD_HTTPD
 * out still gets the command and the reset key, they just report that there is
 * no service to start.
 */
static int rtk_start_recovery(void)
{
	if (!IS_ENABLED(CONFIG_CMD_HTTPD)) {
		puts("This U-Boot was built without the HTTP recovery service.\n");
		return -ENOSYS;
	}

	return uboot_httpd_start(env_get_yesno("httpd_dhcp") != 0);
}

static int do_rtk_recovery(struct cmd_tbl *cmdtp, int flag, int argc,
			   char *const argv[])
{
	return rtk_start_recovery();
}

U_BOOT_CMD(rtk_recovery, 1, 0, do_rtk_recovery,
	   "start the recovery service using the saved httpd settings", "");

/*
 * The reset key is sampled once more at the last moment before bootcmd runs,
 * so a key pressed after power-on still enters recovery, and a released one
 * boots normally.
 */
static int rtk_board_recovery_spy(void)
{
	int ret;

	reset_latched |= rtk_board_reset_held();
	if (reset_latched)
		rtk_board_leds(RTK_LEDS_HELD);
	rtk_board_boot_leds();
	if (!reset_latched) {
		puts("Reset released: normal boot\n");
		return 0;
	}
	puts("Reset held: starting the HTTP recovery\n");
	ret = rtk_start_recovery();
	rtk_board_leds(RTK_LEDS_OFF);
	if (ret)
		printf("Recovery network failed (%d); use rtk_recovery to retry.\n",
		       ret);

	return 0;
}
EVENT_SPY_SIMPLE(EVT_POST_PREBOOT, rtk_board_recovery_spy);
