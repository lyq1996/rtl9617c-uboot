/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __RTK_SERVICE_H
#define __RTK_SERVICE_H

#include <net/httpd.h>
#include "storage_job.h"

#define FS_CHUNK		(4U << 20)
#define FS_SESSION_TIMEOUT	120000
#define FS_BACKUP_TIMEOUT	60000

typedef int (*fs_work_fn)(void);

/* service.c */
u32 fs_job_start(const char *op, fs_work_fn work, bool writes);
bool fs_job_active(void);
void fs_job_context(struct storage_job *ctx);
void fs_job_progress(size_t done, size_t total);
int fs_fail(int ret, const char *fmt, ...)
	__attribute__ ((format (__printf__, 2, 3)));
void fs_reply_job(struct httpd_reply *reply, u32 job, u32 id, size_t chunk);
void *fs_mem_alloc(size_t size);
void fs_mem_free(void *ptr);
size_t fs_mem_capacity(void);

#endif /* __RTK_SERVICE_H */
