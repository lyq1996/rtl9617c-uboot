/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Minimal HTTP service on the lwIP raw httpd. The core only moves bytes: it
 * routes requests to one application, buffers or places POST bodies where the
 * application asks, and streams replies back. Everything runs in the single
 * U-Boot thread; long work belongs in the poll hook and may call
 * httpd_service() to keep the network alive.
 */
#ifndef __NET_HTTPD_H__
#define __NET_HTTPD_H__

#include <linux/errno.h>
#include <linux/types.h>

struct netif;

#define HTTPD_PATH_MAX		96
#define HTTPD_QUERY_MAX		160
#define HTTPD_BODY_MAX		2048

struct httpd_stream {
	u64 length;
	const char *filename;
	int (*read)(void *priv, u64 offset, void *buf, size_t len);
	void (*close)(void *priv, bool complete);
	void *priv;
};

struct httpd_reply {
	int code;
	char *body;
	size_t len;
	bool streamed;
	struct httpd_stream stream;
};

struct httpd_request {
	char path[HTTPD_PATH_MAX];
	char query[HTTPD_QUERY_MAX];
	size_t length;
	char *body;
};

struct httpd_app {
	const char *page;
	size_t page_size;
	void (*started)(void);
	/* Called from the network stack: answer at once, never block. */
	int (*get)(struct httpd_request *req, struct httpd_reply *reply);
	int (*post)(struct httpd_request *req, struct httpd_reply *reply,
		    void **dst);
	void (*posted)(struct httpd_request *req, struct httpd_reply *reply,
		       bool complete);
	/* Called from the service loop, outside the network stack. */
	void (*poll)(void);
	void (*stopped)(void);
};

void httpd_reply_json(struct httpd_reply *reply, int code, const char *json);
void httpd_reply_error(struct httpd_reply *reply, int code,
		       const char *fmt, ...)
	__attribute__ ((format (__printf__, 3, 4)));
void httpd_reply_stream(struct httpd_reply *reply,
			const struct httpd_stream *stream);
bool httpd_query_uint(const char *query, const char *key, u64 *value);

int httpd_serve(const struct httpd_app *app, bool with_dhcp);
void httpd_service(void);
void httpd_quit(void);
bool httpd_is_serving(void);

#if CONFIG_IS_ENABLED(HTTPD_DHCP_SERVER)
int uboot_httpd_dhcp_start(struct netif *netif);
void uboot_httpd_dhcp_stop(void);
#else
static inline int uboot_httpd_dhcp_start(struct netif *netif)
{
	return -ENOSYS;
}

static inline void uboot_httpd_dhcp_stop(void)
{
}
#endif

#endif
