
/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Web failsafe backup internals. 
 */
#ifndef __RTK_BACKUP_PRIV_H
#define __RTK_BACKUP_PRIV_H

#include <net/httpd.h>

struct fs_backup_state {
	u32 id;
	const char *state;
	const char *name;
	u64 size, sent;
};

int fs_backup_open(const char *kind, const char *target,
		   struct httpd_reply *reply);
int fs_backup_get(u32 id, struct httpd_reply *reply);
int fs_backup_cancel(struct httpd_reply *reply);
bool fs_backup_active(void);
void fs_backup_status(struct fs_backup_state *st);
void fs_backup_poll(void);
void fs_backup_stop(void);

#endif /* __RTK_BACKUP_PRIV_H */