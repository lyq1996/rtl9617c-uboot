// SPDX-License-Identifier: GPL-2.0-only
/*
 * The recovery web interface, shared by the boards on this platform.
 *
 * The service in net/lwip/httpd.c knows nothing about a product; everything it
 * needs comes from here: the lamps, the extra fields of the status page, the
 * upload policy and the chunked whole-flash restore. The product specific data
 * is the layout (include/rtk_recovery.h) and the board descriptor
 * (include/rtk_board.h).
 */
#include <config.h>
#include <command.h>
#include <env.h>
#include <image.h>
#include <string.h>
#include <net/httpd-board.h>
#include <rtk_board.h>
#include <rtk_recovery.h>
#include <version_string.h>
#include <asm/arch/soc.h>

/* Restore session state; the service only forwards parsed requests. */
static char restore_operation[24];
static size_t restore_total, restore_offset;
static u32 restore_id;
static char restore_kind[8];
static char restore_target[64];

static void rtk_noop(void)
{
}

static void rtk_http_led(enum httpd_led_state state)
{
	switch (state) {
	case HTTPD_LED_OFF:
		rtk_board_leds(RTK_LEDS_OFF);
		break;
	case HTTPD_LED_BUSY:
		rtk_board_leds(RTK_LEDS_BUSY);
		break;
	case HTTPD_LED_DONE:
		rtk_board_leds(RTK_LEDS_DONE);
		break;
	case HTTPD_LED_FAILED:
		rtk_board_leds(RTK_LEDS_FAILED);
		break;
	case HTTPD_LED_IDLE:
	default:
		rtk_board_leds(RTK_LEDS_IDLE);
		break;
	}
}

static void rtk_http_led_busy(size_t done, size_t total)
{
	rtk_board_leds_busy(done, total);
}

static void rtk_http_poll(void)
{
	rtk_board_leds_poll();
}

static void rtk_http_info(struct http_json *json)
{
	const struct rtk_board_desc *desc = rtk_board_desc();
	const struct rtk_board_variant *variant = desc ? desc->variant : NULL;

	if (!desc)
		return;
	json_printf(json, ",\"project_version\":");
	json_string(json, desc->version);
	json_printf(json, ",\"build_commit\":");
	json_string(json, version_string);
	json_printf(json, ",\"ports\":");
	json_string(json, variant && variant->ports ? variant->ports : "");
}

static void rtk_http_status(struct http_json *json)
{
	const struct rtk_restore_status *state = rtk_restore_status();

	json_printf(json, ",\"restore_active\":%s,\"restore_id\":%u,"
		    "\"restore_offset\":%zu,\"restore_total\":%zu",
		    state->active ? "true" : "false", state->id, state->next,
		    state->total);
}

/* A whole-flash restore has its own endpoint; single uploads have a limit. */
static bool rtk_http_upload_allowed(const char *uri, int content_len)
{
	if (!strcmp(uri, "/api/upload-all-flash"))
		return false;
	if (rtk_restore_status()->active && !strcmp(uri, "/api/upload") &&
	    content_len > 0x400000)
		return false;

	return true;
}

static bool rtk_http_upload_safe(ulong address, size_t size)
{
	if (!size || address + size < address)
		return false;

	return !taurus_memory_is_reserved(address, size);
}

static int rtk_http_job_parse(struct http_json_request *request,
			      const char *operation, bool upload_ready)
{
	bool start = !strcmp(operation, "restore-start");
	bool chunk = !strcmp(operation, "restore-chunk");
	bool finish = !strcmp(operation, "restore-finish");
	bool cancel = !strcmp(operation, "restore-cancel");
	u64 total, offset, id;

	if (!start && !chunk && !finish && !cancel)
		return rtk_restore_status()->active ? -EBUSY : 1;
	if (json_uint(request, "total", &total) || total > SIZE_MAX ||
	    json_uint(request, "offset", &offset) || offset > SIZE_MAX ||
	    json_uint(request, "restore_id", &id) || id > 0xffffffffU)
		return -EINVAL;
	/* A chunk has to belong to the upload that was just received. */
	if ((start || chunk) && !upload_ready)
		return -EINVAL;
	strlcpy(restore_operation, operation, sizeof(restore_operation));
	restore_total = total;
	restore_offset = offset;
	restore_id = id;
	if (start) {
		if (json_field(request, "kind"))
			json_text(request, "kind", restore_kind, sizeof(restore_kind));
		else
			restore_kind[0] = 0;
		if (json_field(request, "target"))
			json_text(request, "target", restore_target, sizeof(restore_target));
		else
			restore_target[0] = 0;
	}

	return 0;
}

static int rtk_http_job_run(ulong address, size_t size,
			    void (*service)(void))
{
	const struct rtk_restore_status *state = rtk_restore_status();
	bool writes = !strcmp(restore_operation, "restore-chunk") ||
		      !strcmp(restore_operation, "restore-finish");
	int ret;

	if (writes && state->active)
		rtk_board_leds_busy(state->next, state->total);
	ret = rtk_restore_job(restore_operation, address, size,
			      restore_total, restore_offset, restore_id,
			      service, restore_kind, restore_target);
	state = rtk_restore_status();
	if (ret && writes)
		rtk_board_leds(RTK_LEDS_FAILED);
	else if (state->active)
		/* Power loss between restore chunks is unsafe: keep the bar up. */
		rtk_board_leds_busy(state->next, state->total);
	else if (writes)
		rtk_board_leds(RTK_LEDS_DONE);
	else
		/* Also reclaims the lamps if a failed boot action released them. */
		rtk_board_leds(RTK_LEDS_IDLE);

	return ret;
}

static void rtk_http_job_abort(void)
{
	const struct rtk_restore_status *state = rtk_restore_status();

	if (!state->active)
		return;
	rtk_restore_job("restore-cancel", 0, 0, 0, 0, state->id, rtk_noop,
			restore_kind, restore_target);
}

static int rtk_http_install_loader(ulong address, size_t size, bool bl2,
				   void (*service)(void))
{
	/* There is one boot area, not a separate preloader partition. */
	if (bl2)
		return -EINVAL;

	return rtk_install_loader(address, size, service);
}

/* Boot an image straight out of RAM, without touching Flash. */
static int rtk_http_boot_upload(ulong address, size_t size)
{
	if (fit_check_format((const void *)address, size)) {
		printf("Uploaded image is not a bootable FIT.\n");
		return -EINVAL;
	}
	env_set_hex("unzip_src", address);

	return run_commandf("bootm 0x%lx", address);
}

static size_t rtk_http_job_write_size(void)
{
	return rtk_loader_write_size();
}

static int rtk_http_set_bootcmd(void)
{
	return rtk_set_default_bootcmd();
}

const struct httpd_board_ops *httpd_board_ops(void)
{
	static struct httpd_board_ops ops;
	static bool ready;
	const struct rtk_recovery_layout *l = rtk_recovery_layout();

	if (ready)
		return &ops;

	ops.ubi_partition = l->ubi_part;
	ops.led = rtk_http_led;
	ops.led_busy = rtk_http_led_busy;
	ops.poll = rtk_http_poll;
	ops.info = rtk_http_info;
	ops.status = rtk_http_status;
	ops.upload_allowed = rtk_http_upload_allowed;
	ops.upload_safe = rtk_http_upload_safe;
	ops.job_parse = rtk_http_job_parse;
	ops.job_run = rtk_http_job_run;
	ops.job_abort = rtk_http_job_abort;
	ops.job_write_size = rtk_http_job_write_size;
	ops.boot_upload = rtk_http_boot_upload;
	ops.set_bootcmd = rtk_http_set_bootcmd;
	ops.install_loader = rtk_http_install_loader;
	ops.install_system = rtk_install_system;
	ops.rebuild_ubi = rtk_rebuild_ubi;
	ops.ubi_create = rtk_ubi_create;
	ops.ubi_remove = rtk_ubi_remove;
	ops.ubi_rename = rtk_ubi_rename;
	ops.ubi_attach = rtk_ubi_attach;
	ops.ubi_detach = rtk_ubi_detach;
	ready = true;

	return &ops;
}
