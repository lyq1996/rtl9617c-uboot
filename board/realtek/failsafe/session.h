/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __RTK_SESSION_H
#define __RTK_SESSION_H

#include <net/httpd.h>

struct fs_write_state {
	u32 id;
	const char *op;
	const char *target;
	const char *state;
	size_t size, next, chunk;
	const char *error;
};

int fs_write_open(const char *op, const char *target, u64 size,
		  struct httpd_reply *reply);
int fs_write_chunk_begin(u32 id, u64 offset, size_t length,
			 struct httpd_reply *reply, void **dst);
void fs_write_chunk_end(struct httpd_reply *reply, bool complete);
int fs_write_commit(u32 id, struct httpd_reply *reply);
int fs_write_abort(u32 id, struct httpd_reply *reply);
bool fs_write_active(void);
void fs_write_status(struct fs_write_state *st);
void fs_write_poll(void);
void fs_write_stop(void);

#endif /* __RTK_SESSION_H */
