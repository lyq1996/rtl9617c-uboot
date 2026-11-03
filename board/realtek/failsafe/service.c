// SPDX-License-Identifier: GPL-2.0-only
/*
 * The web failsafe service: routes, status, and the single job slot.
 *
 * Request handlers run inside the network stack and only validate, queue a
 * job and answer. The queued job runs from the service loop with the console
 * captured into the log the page shows; while it works it keeps the network
 * serviced, so the page can poll its progress, and every request that would
 * start other work is answered 409.
 */
#include <config.h>
#include <command.h>
#include <console.h>
#include <env.h>
#include <limits.h>
#include <lmb.h>
#include <malloc.h>
#include <mapmem.h>
#include <mtd.h>
#include <stdio.h>
#include <stdio_dev.h>
#include <string.h>
#include <time.h>
#include <ubi_volume.h>
#include <version_string.h>
#include <asm/global_data.h>
#include <asm/arch/soc.h>
#include <dm/ofnode.h>
#include <linux/kernel.h>
#include <linux/sizes.h>
#include <net/httpd.h>
#include <net/httpd-json.h>
#include "backup.h"
#include "desc.h"
#include "failsafe.h"
#include "led.h"
#include "recovery.h"
#include "service.h"
#include "session.h"
#include "storage.h"

DECLARE_GLOBAL_DATA_PTR;

#define FS_PROTOCOL	3
#define FS_LOG_SIZE	(64 * 1024)
#define FS_LOG_PIECE	(4 * 1024)
#define FS_JSON_SIZE	(40 * 1024)
#define FS_ALLOCS	4

extern const char rtk_failsafe_page[];
extern const size_t rtk_failsafe_page_size;

enum job_state {
	JOB_IDLE,
	JOB_QUEUED,
	JOB_RUNNING,
	JOB_DONE,
};

static const char *const job_states[] = {
	"idle", "queued", "running", "done",
};

static const char *const job_phases[] = {
	"", "erase", "write", "verify",
};

static struct {
	u32 id;
	char op[24];
	enum job_state state;
	int code;
	char error[192];
	enum storage_phase phase;
	size_t done, total;
	bool writes;
	fs_work_fn work;
} job;

static u32 job_ids;

static struct {
	char name[32];
	char new_name[32];
	char value[512];
	u64 size;
	bool dynamic;
} args;

static struct {
	void *ptr;
	phys_addr_t addr;
	size_t size;
} allocs[FS_ALLOCS];

static char log_buf[FS_LOG_SIZE];
static size_t log_len;
static u32 log_gen;
static bool log_cut;
static struct stdio_dev *log_tee;
static char saved_out[32], saved_err[32];
static char json_buf[FS_JSON_SIZE];

static phys_addr_t mem_top(void)
{
	return min_t(phys_addr_t, gd->ram_base + gd->ram_size,
		     gd->start_addr_sp);
}

void *fs_mem_alloc(size_t size)
{
	phys_addr_t addr = mem_top();
	int i;

	for (i = 0; i < FS_ALLOCS && allocs[i].size; i++)
		;
	if (i == FS_ALLOCS || !size)
		return NULL;
	if (lmb_alloc_mem(LMB_MEM_ALLOC_MAX, 4096, &addr, size, LMB_NONE))
		return NULL;
	if (addr + size > mem_top() ||
	    rtl9617c_memory_is_reserved(addr, size)) {
		lmb_free(addr, size, LMB_NONE);
		return NULL;
	}
	allocs[i].addr = addr;
	allocs[i].size = size;
	allocs[i].ptr = map_sysmem(addr, size);

	return allocs[i].ptr;
}

void fs_mem_free(void *ptr)
{
	int i;

	for (i = 0; ptr && i < FS_ALLOCS; i++) {
		if (allocs[i].ptr != ptr)
			continue;
		unmap_sysmem(ptr);
		lmb_free(allocs[i].addr, allocs[i].size, LMB_NONE);
		memset(&allocs[i], 0, sizeof(allocs[i]));
		return;
	}
}

size_t fs_mem_capacity(void)
{
	size_t lo = 0, hi = gd->ram_size, mid;
	phys_addr_t addr;

	while (hi - lo > SZ_1M) {
		mid = (lo + (hi - lo) / 2) & ~(size_t)(SZ_1M - 1);
		if (mid <= lo)
			break;
		addr = mem_top();
		if (!lmb_alloc_mem(LMB_MEM_ALLOC_MAX, 4096, &addr, mid,
				   LMB_NONE)) {
			lmb_free(addr, mid, LMB_NONE);
			lo = mid;
		} else {
			hi = mid;
		}
	}

	return lo;
}

static void log_putc(struct stdio_dev *dev, const char c)
{
	if (log_len + 1 < FS_LOG_SIZE) {
		log_buf[log_len++] = c;
		log_buf[log_len] = '\0';
	} else {
		log_cut = true;
	}
	if (log_tee && log_tee->putc)
		log_tee->putc(log_tee, c);
}

static void log_puts(struct stdio_dev *dev, const char *s)
{
	while (*s)
		log_putc(dev, *s++);
}

static void log_reset(void)
{
	log_len = 0;
	log_buf[0] = '\0';
	log_cut = false;
	log_gen++;
}

static int log_register(void)
{
	struct stdio_dev dev = {
		.flags = DEV_FLAGS_OUTPUT,
		.putc = log_putc,
		.puts = log_puts,
	};

	if (stdio_get_by_name("webconsole"))
		return 0;
	strlcpy(dev.name, "webconsole", sizeof(dev.name));

	return stdio_register(&dev);
}

static void capture_end(void)
{
	console_assign(stdout, saved_out);
	console_assign(stderr, saved_err);
	log_tee = NULL;
}

static bool capture_begin(void)
{
	strlcpy(saved_out, stdio_devices[stdout]->name, sizeof(saved_out));
	strlcpy(saved_err, stdio_devices[stderr]->name, sizeof(saved_err));
	if (!strcmp(saved_out, "webconsole"))
		return false;
	log_tee = stdio_get_by_name(saved_out);
	if (console_assign(stdout, "webconsole") ||
	    console_assign(stderr, "webconsole")) {
		capture_end();
		return false;
	}

	return true;
}

u32 fs_job_start(const char *op, fs_work_fn work, bool writes)
{
	if (fs_job_active())
		return 0;
	memset(&job, 0, sizeof(job));
	job.id = ++job_ids;
	strlcpy(job.op, op, sizeof(job.op));
	job.state = JOB_QUEUED;
	job.work = work;
	job.writes = writes;

	return job.id;
}

bool fs_job_active(void)
{
	return job.state == JOB_QUEUED || job.state == JOB_RUNNING;
}

static void fs_service(void)
{
	httpd_service();
	rtk_board_leds_poll();
}

static void job_progress(void *priv, enum storage_phase phase, size_t done,
			 size_t total)
{
	job.phase = phase;
	job.done = done;
	job.total = total;
	if (job.writes)
		rtk_board_leds_busy(phase == STORAGE_PHASE_VERIFY ? total : done,
				    total);
}

void fs_job_context(struct storage_job *ctx)
{
	ctx->service = fs_service;
	ctx->progress = job_progress;
	ctx->priv = NULL;
}

void fs_job_progress(size_t done, size_t total)
{
	job_progress(NULL, STORAGE_PHASE_WRITE, done, total);
}

int fs_fail(int ret, const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	vsnprintf(job.error, sizeof(job.error), fmt, args);
	va_end(args);
	printf("%s\n", job.error);

	return ret;
}

void fs_reply_job(struct httpd_reply *reply, u32 id, u32 session,
		  size_t chunk)
{
	char text[96];

	if (!id) {
		httpd_reply_error(reply, 409, "busy: %s is running", job.op);
		return;
	}
	snprintf(text, sizeof(text), "{\"job\":%u,\"id\":%u,\"chunk\":%zu}",
		 id, session, chunk);
	httpd_reply_json(reply, 202, text);
}

static bool fs_busy(void)
{
	return fs_job_active() || fs_write_active() || fs_backup_active();
}

static void job_run(void)
{
	struct fs_write_state st;
	bool captured;
	int ret;

	if (job.state != JOB_QUEUED)
		return;
	job.state = JOB_RUNNING;
	if (job.writes)
		rtk_board_leds_busy(0, 0);
	captured = capture_begin();
	ret = job.work();
	if (captured)
		capture_end();
	job.code = ret;
	if (ret && !job.error[0])
		snprintf(job.error, sizeof(job.error), "%s failed (%d)",
			 job.op, ret);
	job.state = JOB_DONE;

	fs_write_status(&st);
	if (ret && job.writes)
		rtk_board_leds(RTK_LEDS_FAILED);
	else if (fs_write_active())
		rtk_board_leds_busy(st.next, st.size);
	else if (job.writes)
		rtk_board_leds(RTK_LEDS_DONE);
	else
		rtk_board_leds(RTK_LEDS_IDLE);
}

static int ubi_required(struct httpd_reply *reply)
{
	if (rtk_ubi_attached())
		return 0;
	httpd_reply_error(reply, 400, "UBI is not attached; attach %s first",
			  rtk_recovery_layout()->boot->ubi_part);

	return -ENODEV;
}

static int volume_name(struct http_json_request *r, const char *key,
		       char *out, size_t size, struct httpd_reply *reply)
{
	if (json_text(r, key, out, size) || !rtk_storage_name_valid(out)) {
		httpd_reply_error(reply, 400, "invalid volume name");
		return -EINVAL;
	}

	return 0;
}

static int job_ubi_attach(void)
{
	int ret = rtk_ubi_attach();

	if (!ret)
		printf("UBI attached on %s.\n", rtk_recovery_layout()->boot->ubi_part);

	return ret;
}

static int job_ubi_detach(void)
{
	int ret = rtk_ubi_detach(false);

	if (!ret)
		puts("UBI detached.\n");

	return ret;
}

static int job_ubi_create(void)
{
	return rtk_ubi_create(args.name, args.size, args.dynamic);
}

static int job_ubi_remove(void)
{
	return rtk_ubi_remove(args.name);
}

static int job_ubi_rename(void)
{
	return rtk_ubi_rename(args.name, args.new_name);
}

static int job_ubi_rebuild(void)
{
	struct storage_job ctx;

	fs_job_context(&ctx);

	return rtk_rebuild_ubi(&ctx);
}

static int job_nand_scrub(void)
{
	struct storage_job ctx;

	fs_job_context(&ctx);

	return rtk_nand_scrub(&ctx);
}

static int job_env_set(void)
{
	if (env_set(args.name, args.value[0] ? args.value : NULL) ||
	    env_save())
		return fs_fail(-EIO, "saving %s failed", args.name);

	return 0;
}

static int job_env_default(void)
{
	env_set_default(NULL, 0);

	return env_save() ? fs_fail(-EIO, "saving the environment failed") : 0;
}

static int job_command(void)
{
	int ret = run_command(args.value, 0);

	return ret ? fs_fail(-EIO, "command returned %d", ret) : 0;
}

static int job_boot(void)
{
	run_command("rtk_boot", 0);

	return fs_fail(-EIO, "starting the system failed");
}

static int job_reset(void)
{
	run_command("reset", 0);

	return fs_fail(-EIO, "reset failed");
}

static int job_exit(void)
{
	puts("Leaving the recovery service.\n");
	httpd_quit();

	return 0;
}

static int check_ubi_create(struct http_json_request *r,
			    struct httpd_reply *reply)
{
	u64 dynamic;

	if (ubi_required(reply) ||
	    volume_name(r, "name", args.name, sizeof(args.name), reply))
		return -EINVAL;
	if (json_uint(r, "size", &args.size) ||
	    json_uint(r, "dynamic", &dynamic) || dynamic > 1) {
		httpd_reply_error(reply, 400, "invalid size or type");
		return -EINVAL;
	}
	args.dynamic = dynamic;
	if (ubi_volume_exists(args.name)) {
		httpd_reply_error(reply, 400, "volume %s already exists",
				  args.name);
		return -EEXIST;
	}

	return 0;
}

static int check_ubi_volume(struct http_json_request *r,
			    struct httpd_reply *reply)
{
	if (ubi_required(reply) ||
	    volume_name(r, "name", args.name, sizeof(args.name), reply))
		return -EINVAL;
	if (!ubi_volume_exists(args.name)) {
		httpd_reply_error(reply, 400, "UBI has no volume %s", args.name);
		return -ENOENT;
	}

	return 0;
}

static int check_ubi_rename(struct http_json_request *r,
			    struct httpd_reply *reply)
{
	if (check_ubi_volume(r, reply) ||
	    volume_name(r, "new_name", args.new_name, sizeof(args.new_name),
			reply))
		return -EINVAL;
	if (ubi_volume_exists(args.new_name)) {
		httpd_reply_error(reply, 400, "volume %s already exists",
				  args.new_name);
		return -EEXIST;
	}

	return 0;
}

static int check_env_set(struct http_json_request *r,
			 struct httpd_reply *reply)
{
	if (json_text(r, "name", args.name, sizeof(args.name)) ||
	    !args.name[0] || strchr(args.name, '=') ||
	    json_text(r, "value", args.value, sizeof(args.value))) {
		httpd_reply_error(reply, 400, "invalid variable");
		return -EINVAL;
	}

	return 0;
}

static int check_command(struct http_json_request *r,
			 struct httpd_reply *reply)
{
	if (json_text(r, "command", args.value, sizeof(args.value)) ||
	    !args.value[0]) {
		httpd_reply_error(reply, 400, "empty command");
		return -EINVAL;
	}

	return 0;
}

static const struct {
	const char *op;
	fs_work_fn work;
	bool writes;
	int (*check)(struct http_json_request *r, struct httpd_reply *reply);
} job_table[] = {
	{ "ubi-attach",	 job_ubi_attach,	false,	NULL },
	{ "ubi-detach",	 job_ubi_detach,	false,	NULL },
	{ "ubi-create",	 job_ubi_create,	false,	check_ubi_create },
	{ "ubi-remove",	 job_ubi_remove,	false,	check_ubi_volume },
	{ "ubi-rename",	 job_ubi_rename,	false,	check_ubi_rename },
	{ "ubi-rebuild", job_ubi_rebuild,	true,	NULL },
	{ "env-set",	 job_env_set,		false,	check_env_set },
	{ "env-default", job_env_default,	false,	NULL },
	{ "command",	 job_command,		false,	check_command },
	{ "nand-scrub",	 job_nand_scrub,	true,	NULL },
	{ "boot",	 job_boot,		false,	NULL },
	{ "reset",	 job_reset,		false,	NULL },
	{ "exit",	 job_exit,		false,	NULL },
};

static bool busy_reply(struct httpd_reply *reply)
{
	struct fs_write_state st;

	if (fs_job_active()) {
		httpd_reply_error(reply, 409, "busy: %s is running", job.op);
	} else if (fs_write_active()) {
		fs_write_status(&st);
		httpd_reply_error(reply, 409,
				  "busy: write session %u is open; finish or abort it",
				  st.id);
	} else if (fs_backup_active()) {
		httpd_reply_error(reply, 409,
				  "busy: a backup is waiting to be downloaded");
	} else {
		return false;
	}

	return true;
}

static void post_job(struct http_json_request *r, struct httpd_reply *reply)
{
	char op[24];
	unsigned int i;
	u64 id = 0;

	if (json_text(r, "op", op, sizeof(op))) {
		httpd_reply_error(reply, 400, "missing op");
		return;
	}
	if (json_uint(r, "id", &id) || id > U32_MAX) {
		httpd_reply_error(reply, 400, "invalid id");
		return;
	}
	if (!strcmp(op, "write-commit")) {
		fs_write_commit(id, reply);
		return;
	}
	if (!strcmp(op, "write-abort")) {
		fs_write_abort(id, reply);
		return;
	}
	if (!strcmp(op, "backup-cancel")) {
		fs_backup_cancel(reply);
		return;
	}
	for (i = 0; i < ARRAY_SIZE(job_table); i++)
		if (!strcmp(op, job_table[i].op))
			break;
	if (i == ARRAY_SIZE(job_table)) {
		httpd_reply_error(reply, 400, "unknown op %s", op);
		return;
	}
	if (busy_reply(reply))
		return;
	memset(&args, 0, sizeof(args));
	if (job_table[i].check && job_table[i].check(r, reply))
		return;
	log_reset();
	fs_reply_job(reply, fs_job_start(op, job_table[i].work,
					 job_table[i].writes), 0, 0);
}

static void post_write(struct http_json_request *r, struct httpd_reply *reply)
{
	char op[16], target[64] = "";
	u64 size;

	if (busy_reply(reply))
		return;
	if (json_text(r, "op", op, sizeof(op)) ||
	    (json_field(r, "target") &&
	     json_text(r, "target", target, sizeof(target))) ||
	    json_uint(r, "size", &size)) {
		httpd_reply_error(reply, 400, "invalid write request");
		return;
	}
	log_reset();
	fs_write_open(op, target, size, reply);
}

static void post_backup(struct http_json_request *r,
			struct httpd_reply *reply)
{
	char kind[8], target[64];

	if (busy_reply(reply))
		return;
	if (json_text(r, "kind", kind, sizeof(kind)) ||
	    json_text(r, "target", target, sizeof(target))) {
		httpd_reply_error(reply, 400, "invalid backup request");
		return;
	}
	log_reset();
	fs_backup_open(kind, target, reply);
}

static int reply_built(struct httpd_reply *reply, struct http_json *j)
{
	if (j->overflow) {
		httpd_reply_error(reply, 500, "reply too large");
		return -ENOSPC;
	}
	httpd_reply_json(reply, 200, j->data);

	return 0;
}

static int reply_status(struct httpd_reply *reply)
{
	struct http_json j = { json_buf, sizeof(json_buf), 0, false };
	struct fs_write_state ws;
	struct fs_backup_state bs;
	struct ubi_volume_entry vi;
	bool attached = rtk_ubi_attached();
	bool comma = false;
	int slot;

	fs_write_status(&ws);
	fs_backup_status(&bs);
	json_printf(&j, "{\"protocol\":%d,\"busy\":%s,\"job\":{\"id\":%u,\"op\":",
		    FS_PROTOCOL, fs_busy() ? "true" : "false", job.id);
	json_string(&j, job.op);
	json_printf(&j, ",\"state\":\"%s\",\"code\":%d,\"error\":",
		    job_states[job.state], job.code);
	json_string(&j, job.error);
	json_printf(&j, ",\"phase\":\"%s\",\"done\":%zu,\"total\":%zu},",
		    job_phases[job.phase], job.done, job.total);
	json_printf(&j, "\"write\":{\"id\":%u,\"op\":", ws.id);
	json_string(&j, ws.op);
	json_printf(&j, ",\"target\":");
	json_string(&j, ws.target);
	json_printf(&j, ",\"state\":\"%s\",\"size\":%zu,\"next\":%zu,"
		    "\"chunk\":%zu,\"error\":", ws.state, ws.size, ws.next,
		    ws.chunk);
	json_string(&j, ws.error);
	json_printf(&j, "},\"backup\":{\"id\":%u,\"state\":\"%s\",\"name\":",
		    bs.id, bs.state);
	json_string(&j, bs.name);
	json_printf(&j, ",\"size\":%llu,\"sent\":%llu},",
		    (unsigned long long)bs.size, (unsigned long long)bs.sent);
	json_printf(&j, "\"ubi\":{\"attached\":%s,\"part\":",
		    attached ? "true" : "false");
	json_string(&j, rtk_recovery_layout()->boot->ubi_part);
	json_printf(&j, ",\"free\":%llu,\"volumes\":[",
		    attached ? (unsigned long long)ubi_free_bytes() : 0ULL);
	for (slot = attached ? ubi_volume_next(0, &vi) : -1; slot >= 0;
	     slot = ubi_volume_next(slot + 1, &vi)) {
		json_printf(&j, "%s{\"name\":", comma ? "," : "");
		json_string(&j, vi.name);
		json_printf(&j, ",\"size\":%zu,\"reserved\":%zu,\"dynamic\":%s}",
			    vi.used_bytes, vi.reserved_bytes,
			    vi.dynamic ? "true" : "false");
		comma = true;
	}
	json_printf(&j, "]},\"log\":{\"gen\":%u,\"len\":%zu,\"cut\":%s}}",
		    log_gen, log_len, log_cut ? "true" : "false");

	return reply_built(reply, &j);
}

static int reply_info(struct httpd_reply *reply)
{
	struct http_json j = { json_buf, sizeof(json_buf), 0, false };
	const struct rtk_recovery_layout *l = rtk_recovery_layout();
	const struct rtk_board_desc *desc = rtk_board_desc();
	const char *model = ofnode_read_string(ofnode_root(), "model");
	struct mtd_info *mtd;
	bool comma = false;
	unsigned int i;

	json_printf(&j, "{\"protocol\":%d,\"model\":", FS_PROTOCOL);
	json_string(&j, model ? model : "unknown");
	json_printf(&j, ",\"version\":");
	json_string(&j, version_string);
	json_printf(&j, ",\"board\":{\"name\":");
	json_string(&j, desc ? desc->name : "");
	json_printf(&j, ",\"version\":");
	json_string(&j, desc ? desc->version : "");
	json_printf(&j, ",\"ports\":");
	json_string(&j, desc && desc->variant ? desc->variant->ports : "");
	json_printf(&j, "},\"ram_bytes\":%llu,\"flash_bytes\":%zu,",
		    (unsigned long long)gd->ram_size, l->flash_size);
	json_printf(&j, "\"limits\":{\"chunk\":%u,\"ram_max\":%zu,\"boot_bytes\":%u},",
		    FS_CHUNK, fs_mem_capacity(), RTK_BOOT_SIZE);
	json_printf(&j, "\"names\":{\"boot\":");
	json_string(&j, l->boot_mtd);
	json_printf(&j, ",\"nand\":");
	json_string(&j, l->nand_dev);
	json_printf(&j, ",\"ubi\":");
	json_string(&j, l->boot->ubi_part);
	json_printf(&j, ",\"fit\":");
	json_string(&j, l->boot->firmware_volume);
	json_printf(&j, ",\"overlay\":");
	json_string(&j, l->boot->overlay_volume);
	json_printf(&j, "},\"mtd\":[");
	mtd_probe_devices();
	mtd_for_each_device(mtd) {
		if (!rtk_storage_name_valid(mtd->name))
			continue;
		json_printf(&j, "%s{\"name\":", comma ? "," : "");
		json_string(&j, mtd->name);
		json_printf(&j, ",\"size\":%llu,\"erasesize\":%u,\"whole\":%s}",
			    (unsigned long long)mtd->size, mtd->erasesize,
			    mtd_is_partition(mtd) ? "false" : "true");
		comma = true;
	}
	json_printf(&j, "],\"board_data\":[");
	comma = false;
	for (i = 0; i < l->nr_volumes; i++) {
		if (l->volumes[i].policy != RTK_VOL_DATA ||
		    l->volumes[i].dynamic)
			continue;
		json_printf(&j, "%s{\"name\":", comma ? "," : "");
		json_string(&j, l->volumes[i].name);
		json_printf(&j, ",\"size\":%llu}",
			    (unsigned long long)l->volumes[i].size);
		comma = true;
	}
	json_printf(&j, "]}");

	return reply_built(reply, &j);
}

static int reply_log(struct httpd_request *req, struct httpd_reply *reply)
{
	struct http_json j = { json_buf, sizeof(json_buf), 0, false };
	char piece[FS_LOG_PIECE + 1];
	u64 from = 0;
	size_t n;

	httpd_query_uint(req->query, "from", &from);
	if (from > log_len)
		from = 0;
	n = min_t(size_t, log_len - from, FS_LOG_PIECE);
	memcpy(piece, log_buf + from, n);
	piece[n] = '\0';
	json_printf(&j, "{\"gen\":%u,\"from\":%llu,\"next\":%llu,\"len\":%zu,\"cut\":%s,\"text\":",
		    log_gen, (unsigned long long)from,
		    (unsigned long long)(from + n), log_len,
		    log_cut ? "true" : "false");
	json_string(&j, piece);
	json_printf(&j, "}");

	return reply_built(reply, &j);
}

static int reply_env(struct httpd_reply *reply)
{
	static const char *const keys[] = {
		"httpd_ipaddr", "httpd_netmask", "httpd_dhcp",
		"httpd_dhcp_start", "httpd_dhcp_end", "ipaddr", "netmask",
		"serverip", "bootcmd",
	};
	struct http_json j = { json_buf, sizeof(json_buf), 0, false };
	unsigned int i;

	json_printf(&j, "{");
	for (i = 0; i < ARRAY_SIZE(keys); i++) {
		json_printf(&j, "%s", i ? "," : "");
		json_string(&j, keys[i]);
		json_printf(&j, ":");
		json_string(&j, env_get(keys[i]));
	}
	json_printf(&j, "}");

	return reply_built(reply, &j);
}

static int fs_get(struct httpd_request *req, struct httpd_reply *reply)
{
	char *end;
	ulong id;

	if (!strcmp(req->path, "/api/status"))
		return reply_status(reply);
	if (!strcmp(req->path, "/api/info"))
		return reply_info(reply);
	if (!strcmp(req->path, "/api/log"))
		return reply_log(req, reply);
	if (!strcmp(req->path, "/api/env"))
		return reply_env(reply);
	if (!strncmp(req->path, "/api/backup/", 12)) {
		id = simple_strtoul(req->path + 12, &end, 10);
		if (*end || !id) {
			httpd_reply_error(reply, 404, "no such backup");
			return -ENOENT;
		}
		return fs_backup_get(id, reply);
	}
	if (!strncmp(req->path, "/api/", 5))
		httpd_reply_error(reply, 404, "unknown API");

	return -ENOENT;
}

static int fs_post(struct httpd_request *req, struct httpd_reply *reply,
		   void **dst)
{
	u64 offset;
	char *end;
	ulong id;

	if (!strncmp(req->path, "/api/write/", 11)) {
		id = simple_strtoul(req->path + 11, &end, 10);
		if (*end || !id) {
			httpd_reply_error(reply, 404, "no such write session");
			return -ENOENT;
		}
		if (!httpd_query_uint(req->query, "offset", &offset)) {
			httpd_reply_error(reply, 400, "missing offset");
			return -EINVAL;
		}
		return fs_write_chunk_begin(id, offset, req->length, reply,
					    dst);
	}
	if (!strcmp(req->path, "/api/job") ||
	    !strcmp(req->path, "/api/write") ||
	    !strcmp(req->path, "/api/backup"))
		return 0;
	httpd_reply_error(reply, 404, "unknown API");

	return -ENOENT;
}

static void fs_posted(struct httpd_request *req, struct httpd_reply *reply,
		      bool complete)
{
	struct http_json_request r;

	if (!strncmp(req->path, "/api/write/", 11)) {
		fs_write_chunk_end(reply, complete);
		return;
	}
	if (!complete)
		return;
	if (!req->body || json_request_init(&r, req->body)) {
		httpd_reply_error(reply, 400, "the body must be a flat JSON object");
		return;
	}
	if (!strcmp(req->path, "/api/job"))
		post_job(&r, reply);
	else if (!strcmp(req->path, "/api/write"))
		post_write(&r, reply);
	else
		post_backup(&r, reply);
}

static void fs_started(void)
{
	log_register();
	memset(&job, 0, sizeof(job));
	log_reset();
	rtk_board_leds(RTK_LEDS_IDLE);
}

static void fs_poll(void)
{
	job_run();
	fs_write_poll();
	fs_backup_poll();
	rtk_board_leds_poll();
}

static void fs_stopped(void)
{
	int i;

	if (job.state == JOB_QUEUED)
		job.state = JOB_IDLE;
	fs_write_stop();
	fs_backup_stop();
	for (i = 0; i < FS_ALLOCS; i++)
		fs_mem_free(allocs[i].ptr);
	rtk_board_leds(RTK_LEDS_OFF);
}

static const struct httpd_app fs_app = {
	.page = rtk_failsafe_page,
	.started = fs_started,
	.get = fs_get,
	.post = fs_post,
	.posted = fs_posted,
	.poll = fs_poll,
	.stopped = fs_stopped,
};

int rtk_web_failsafe_start(void)
{
	struct httpd_app app = fs_app;

	if (httpd_is_serving())
		return 0;
	app.page_size = rtk_failsafe_page_size;

	return httpd_serve(&app, env_get_yesno("httpd_dhcp") != 0);
}

static int do_rtk_recovery(struct cmd_tbl *cmdtp, int flag, int argc,
			   char *const argv[])
{
	return rtk_web_failsafe_start() ? CMD_RET_FAILURE : CMD_RET_SUCCESS;
}

U_BOOT_CMD(rtk_recovery, 1, 0, do_rtk_recovery,
	   "start the web recovery service", "");
