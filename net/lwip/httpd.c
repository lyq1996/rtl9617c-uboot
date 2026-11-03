// SPDX-License-Identifier: GPL-2.0+
/*
 * HTTP core of the browser service, on top of the lwIP raw httpd.
 *
 * GET requests become fs_open_custom() calls, POST requests the
 * httpd_post_*() callbacks. Both are handed to one application. A POST the
 * application refuses is still read to its end before the reply is sent, so
 * the browser always gets the reason instead of a reset connection.
 */
#include <console.h>
#include <env.h>
#include <malloc.h>
#include <net.h>
#include <net-lwip.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <vsprintf.h>
#include <linux/kernel.h>
#include <lwip/apps/fs.h>
#include <lwip/apps/httpd.h>
#include <lwip/pbuf.h>
#include <lwip/priv/tcp_priv.h>
#include <net/httpd.h>

#define HTTPD_POSTS		4
#define HTTPD_HEAD_MAX		320
#define HTTPD_REPLY_URI		"/.reply/"
#define HTTPD_BUSY_URI		"/.busy"

struct httpd_post {
	void *conn;
	bool accepted;
	bool discard;
	size_t got;
	u8 *dst;
	struct httpd_request req;
	struct httpd_reply reply;
	char small[HTTPD_BODY_MAX + 1];
};

struct httpd_file {
	struct httpd_reply reply;
	char *data;
	char head[HTTPD_HEAD_MAX];
	size_t head_len;
};

static const struct httpd_app *app;
static struct httpd_post posts[HTTPD_POSTS];
static struct httpd_reply handoff[HTTPD_POSTS];
static bool serving, quitting, in_rx;
static struct udevice *http_eth;
static struct netif *http_netif;
static ulong serviced;

static void reply_free(struct httpd_reply *reply)
{
	if (reply->streamed && reply->stream.close)
		reply->stream.close(reply->stream.priv, false);
	free(reply->body);
	memset(reply, 0, sizeof(*reply));
}

void httpd_reply_json(struct httpd_reply *reply, int code, const char *json)
{
	reply_free(reply);
	reply->body = strdup(json);
	reply->len = reply->body ? strlen(reply->body) : 0;
	reply->code = reply->body ? code : 500;
}

void httpd_reply_error(struct httpd_reply *reply, int code,
		       const char *fmt, ...)
{
	char text[192], json[400];
	const unsigned char *p;
	size_t n = 0;
	va_list args;

	va_start(args, fmt);
	vsnprintf(text, sizeof(text), fmt, args);
	va_end(args);
	n += snprintf(json, sizeof(json), "{\"error\":\"");
	for (p = (const unsigned char *)text; *p && n + 8 < sizeof(json); p++) {
		if (*p == '"' || *p == '\\')
			n += snprintf(json + n, sizeof(json) - n, "\\%c", *p);
		else if (*p < 32)
			n += snprintf(json + n, sizeof(json) - n, "\\u%04x",
				      *p);
		else
			json[n++] = *p;
	}
	snprintf(json + n, sizeof(json) - n, "\"}");
	httpd_reply_json(reply, code, json);
}

void httpd_reply_stream(struct httpd_reply *reply,
			const struct httpd_stream *stream)
{
	reply_free(reply);
	reply->streamed = true;
	reply->stream = *stream;
	reply->code = 200;
}

bool httpd_query_uint(const char *query, const char *key, u64 *value)
{
	size_t len = strlen(key);
	const char *p = query;
	char *end;

	while (p && *p) {
		if (!strncmp(p, key, len) && p[len] == '=') {
			*value = simple_strtoull(p + len + 1, &end, 10);
			return end != p + len + 1 && (!*end || *end == '&');
		}
		p = strchr(p, '&');
		if (p)
			p++;
	}

	return false;
}

static int request_parse(struct httpd_request *req, const char *uri)
{
	const char *query = strchr(uri, '?');
	size_t len = query ? (size_t)(query - uri) : strlen(uri);

	memset(req, 0, sizeof(*req));
	if (len >= sizeof(req->path) ||
	    (query && strlen(query + 1) >= sizeof(req->query)))
		return -EINVAL;
	memcpy(req->path, uri, len);
	if (query)
		strcpy(req->query, query + 1);

	return 0;
}

static const char *reason(int code)
{
	switch (code) {
	case 200:
		return "OK";
	case 202:
		return "Accepted";
	case 400:
		return "Bad Request";
	case 404:
		return "Not Found";
	case 409:
		return "Conflict";
	case 413:
		return "Payload Too Large";
	case 503:
		return "Service Unavailable";
	default:
		return "Internal Server Error";
	}
}

static int file_open(struct fs_file *file, struct httpd_reply *reply)
{
	struct httpd_file *f = calloc(1, sizeof(*f));
	u64 total;

	if (!f) {
		reply_free(reply);
		return 0;
	}
	if (!reply->code)
		httpd_reply_error(reply, 500, "no reply");
	f->reply = *reply;
	memset(reply, 0, sizeof(*reply));
	file->flags = FS_FILE_FLAGS_HEADER_INCLUDED;
	file->pextension = f;
	if (f->reply.streamed) {
		f->head_len = snprintf(f->head, sizeof(f->head),
			"HTTP/1.1 200 OK\r\n"
			"Content-Type: application/octet-stream\r\n"
			"Content-Length: %llu\r\n"
			"%s%s%s"
			"Cache-Control: no-store\r\nConnection: close\r\n\r\n",
			(unsigned long long)f->reply.stream.length,
			f->reply.stream.filename ?
			"Content-Disposition: attachment; filename=\"" : "",
			f->reply.stream.filename ? f->reply.stream.filename : "",
			f->reply.stream.filename ? "\"\r\n" : "");
		total = f->head_len + f->reply.stream.length;
		if (total > INT_MAX) {
			reply_free(&f->reply);
			httpd_reply_error(&f->reply, 500, "reply too large");
		} else {
			file->data = NULL;
			file->len = total;
			file->index = 0;
			return 1;
		}
	}
	f->head_len = snprintf(f->head, sizeof(f->head),
			       "HTTP/1.1 %d %s\r\n"
			       "Content-Type: application/json\r\n"
			       "Content-Length: %zu\r\n"
			       "Cache-Control: no-store\r\nConnection: close\r\n\r\n",
			       f->reply.code, reason(f->reply.code),
			       f->reply.len);
	f->data = malloc(f->head_len + f->reply.len);
	if (!f->data) {
		reply_free(&f->reply);
		free(f);
		file->pextension = NULL;
		return 0;
	}
	memcpy(f->data, f->head, f->head_len);
	memcpy(f->data + f->head_len, f->reply.body, f->reply.len);
	file->data = f->data;
	file->len = f->head_len + f->reply.len;
	file->index = file->len;

	return 1;
}

int fs_open_custom(struct fs_file *file, const char *name)
{
	struct httpd_reply reply = {};
	struct httpd_request req;
	size_t len = strlen(HTTPD_REPLY_URI);
	ulong slot;

	if (!app)
		return 0;
	file->pextension = NULL;
	if (!strncmp(name, HTTPD_REPLY_URI, len)) {
		slot = simple_strtoul(name + len, NULL, 10);
		if (slot >= HTTPD_POSTS)
			return 0;
		reply = handoff[slot];
		memset(&handoff[slot], 0, sizeof(reply));
		return file_open(file, &reply);
	}
	if (!strcmp(name, HTTPD_BUSY_URI)) {
		httpd_reply_error(&reply, 503, "too many requests at once");
		return file_open(file, &reply);
	}
	if (!strcmp(name, "/") || !strcmp(name, "/index.html")) {
		file->data = app->page;
		file->len = app->page_size;
		file->index = app->page_size;
		file->flags = FS_FILE_FLAGS_HEADER_INCLUDED;
		return 1;
	}
	if (request_parse(&req, name))
		httpd_reply_error(&reply, 400, "request line too long");
	else if (app->get(&req, &reply) && !reply.code)
		return 0;

	return file_open(file, &reply);
}

int fs_read_custom(struct fs_file *file, char *buffer, int count)
{
	struct httpd_file *f = file->pextension;
	size_t n;

	if (!f || !f->reply.streamed || file->index >= file->len)
		return FS_READ_EOF;
	count = min(count, file->len - file->index);
	if ((size_t)file->index < f->head_len) {
		n = min_t(size_t, count, f->head_len - file->index);
		memcpy(buffer, f->head + file->index, n);
		file->index += n;
		return n;
	}
	if (f->reply.stream.read(f->reply.stream.priv,
				 file->index - f->head_len, buffer, count))
		return FS_READ_EOF;
	file->index += count;

	return count;
}

void fs_close_custom(struct fs_file *file)
{
	struct httpd_file *f = file->pextension;

	if (!f)
		return;
	if (f->reply.streamed && f->reply.stream.close) {
		f->reply.stream.close(f->reply.stream.priv,
				      file->index >= file->len);
		f->reply.streamed = false;
	}
	reply_free(&f->reply);
	free(f->data);
	free(f);
	file->pextension = NULL;
}

static struct httpd_post *post_find(void *conn)
{
	int i;

	for (i = 0; i < HTTPD_POSTS; i++)
		if (posts[i].conn == conn)
			return &posts[i];

	return NULL;
}

err_t httpd_post_begin(void *connection, const char *uri,
		       const char *http_request, u16_t http_request_len,
		       int content_len, char *response_uri,
		       u16_t response_uri_len, u8_t *post_auto_wnd)
{
	struct httpd_post *p = app && connection ? post_find(NULL) : NULL;
	void *dst = NULL;

	if (!p) {
		strlcpy(response_uri, HTTPD_BUSY_URI, response_uri_len);
		return ERR_ARG;
	}
	memset(p, 0, sizeof(*p));
	p->conn = connection;
	*post_auto_wnd = 1;
	if (content_len < 0 || request_parse(&p->req, uri)) {
		httpd_reply_error(&p->reply, 400, "invalid request");
		p->discard = true;
		return ERR_OK;
	}
	p->req.length = content_len;
	if (app->post(&p->req, &p->reply, &dst)) {
		if (!p->reply.code)
			httpd_reply_error(&p->reply, 400, "request refused");
		p->discard = true;
		return ERR_OK;
	}
	p->accepted = true;
	if (dst) {
		p->dst = dst;
	} else if (p->req.length > HTTPD_BODY_MAX) {
		httpd_reply_error(&p->reply, 413, "request body too large");
		p->discard = true;
	} else {
		p->dst = (u8 *)p->small;
		p->req.body = p->small;
	}

	return ERR_OK;
}

err_t httpd_post_receive_data(void *connection, struct pbuf *pb)
{
	struct httpd_post *p = connection ? post_find(connection) : NULL;
	u16_t len = pb->tot_len;

	if (!p) {
		pbuf_free(pb);
		return ERR_ARG;
	}
	if (!p->discard && len > p->req.length - p->got) {
		httpd_reply_error(&p->reply, 400, "body longer than announced");
		p->discard = true;
	}
	if (!p->discard)
		pbuf_copy_partial(pb, p->dst + p->got, len, 0);
	p->got += len;
	pbuf_free(pb);

	return ERR_OK;
}

void httpd_post_finished(void *connection, char *response_uri,
			 u16_t response_uri_len)
{
	struct httpd_post *p = connection ? post_find(connection) : NULL;
	bool complete;
	int slot;

	if (!p) {
		strlcpy(response_uri, HTTPD_BUSY_URI, response_uri_len);
		return;
	}
	slot = p - posts;
	if (p->accepted) {
		complete = !p->discard && p->got == p->req.length;
		if (p->req.body)
			p->small[min_t(size_t, p->got, HTTPD_BODY_MAX)] = '\0';
		app->posted(&p->req, &p->reply, complete);
		if (!complete && !p->reply.code)
			httpd_reply_error(&p->reply, 400,
					  "request body incomplete");
	}
	reply_free(&handoff[slot]);
	handoff[slot] = p->reply;
	memset(p, 0, sizeof(*p));
	snprintf(response_uri, response_uri_len, HTTPD_REPLY_URI "%d", slot);
}

static int rx_once(void)
{
	int ret;

	in_rx = true;
	ret = net_lwip_rx(http_eth, http_netif);
	in_rx = false;

	return ret;
}

void httpd_service(void)
{
	if (!serving || in_rx || get_timer(serviced) < 5)
		return;
	serviced = get_timer(0);
	rx_once();
}

void httpd_quit(void)
{
	quitting = true;
}

bool httpd_is_serving(void)
{
	return serving;
}

/* Replies close from this side; their TIME_WAIT sockets would block the next bind. */
static void release_port(void)
{
	struct tcp_pcb *pcb, *next;

	for (pcb = tcp_tw_pcbs; pcb; pcb = next) {
		next = pcb->next;
		if (pcb->local_port == HTTPD_SERVER_PORT)
			tcp_abort(pcb);
	}
}

int httpd_serve(const struct httpd_app *application, bool with_dhcp)
{
	const char *addr, *mask;
	int i, ret;

	if (serving)
		return -EBUSY;
	addr = env_get("httpd_ipaddr");
	if (!addr || !*addr)
		addr = CONFIG_HTTPD_SERVER_IP;
	env_set("ipaddr", addr);
	mask = env_get("httpd_netmask");
	if (!mask || !*mask)
		mask = CONFIG_HTTPD_SERVER_NETMASK;
	env_set("netmask", mask);

	ret = net_lwip_eth_start();
	if (ret)
		return ret;
	http_eth = eth_get_dev();
	http_netif = net_lwip_new_netif(http_eth);
	if (!http_netif) {
		net_lwip_eth_stop();
		return -ENODEV;
	}

	app = application;
	memset(posts, 0, sizeof(posts));
	memset(handoff, 0, sizeof(handoff));
	serving = true;
	quitting = false;
	httpd_init();
	if (with_dhcp) {
		ret = uboot_httpd_dhcp_start(http_netif);
		if (ret)
			printf("DHCP server start failed: %d\n", ret);
	}
	printf("HTTP management: http://%s/  (%s)\n", env_get("ipaddr"),
	       with_dhcp ? "DHCP enabled" : "static address");
	puts("Press Ctrl-C to return to the serial console.\n");
	clear_ctrlc();
	if (app->started)
		app->started();

	ret = 0;
	while (!quitting && !ctrlc()) {
		ret = rx_once();
		if (ret == -ENETDOWN || ret == -ENOLINK || ret == -EAGAIN)
			ret = 0;
		if (ret < 0)
			break;
		if (app->poll)
			app->poll();
	}

	uboot_httpd_dhcp_stop();
	httpd_stop();
	release_port();
	for (i = 0; i < HTTPD_POSTS; i++) {
		reply_free(&posts[i].reply);
		reply_free(&handoff[i]);
		posts[i].conn = NULL;
	}
	if (app->stopped)
		app->stopped();
	net_lwip_remove_netif(http_netif);
	net_lwip_eth_stop();
	http_netif = NULL;
	http_eth = NULL;
	app = NULL;
	serving = false;
	clear_ctrlc();

	return ret < 0 ? ret : 0;
}
