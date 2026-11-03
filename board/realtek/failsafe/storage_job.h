/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef __STORAGE_JOB_H
#define __STORAGE_JOB_H

#include <linux/types.h>

enum storage_phase {
	STORAGE_PHASE_NONE = 0,
	STORAGE_PHASE_ERASE,
	STORAGE_PHASE_WRITE,
	STORAGE_PHASE_VERIFY,
};

/* Lets a long Flash operation keep the network and the lamps alive. */
struct storage_job {
	void (*service)(void);
	void (*progress)(void *priv, enum storage_phase phase, size_t done,
			 size_t total);
	void *priv;
};

#define STORAGE_CHUNK_SIZE	(1024 * 1024)

static inline void storage_job_service(const struct storage_job *job)
{
	if (job && job->service)
		job->service();
}

static inline void storage_job_report(const struct storage_job *job,
				      enum storage_phase phase, size_t done,
				      size_t total)
{
	if (job && job->progress)
		job->progress(job->priv, phase, done, total);
}

#endif
