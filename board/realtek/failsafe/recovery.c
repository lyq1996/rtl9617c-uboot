// SPDX-License-Identifier: GPL-2.0-only
/*
 * Recovery engine: replace the boot area, rebuild the UBI device and manage
 * its volumes. Every product specific name comes from the layout.
 */
#include <config.h>
#include <malloc.h>
#include <memalign.h>
#include <mtd.h>
#include <stdio.h>
#include <string.h>
#include <ubi_volume.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include "fip.h"
#include "recovery.h"
#include "storage.h"

static const struct rtk_recovery_layout *layout(void)
{
	return rtk_recovery_layout();
}

static int ubi_errno(int ret)
{
	return ret > 0 ? -ret : ret;
}

static struct mtd_info *boot_mtd(void)
{
	struct mtd_info *mtd;

	mtd_probe_devices();
	mtd = get_mtd_device_nm(layout()->boot_mtd);
	if (IS_ERR(mtd))
		return NULL;
	if (mtd->size != RTK_BOOT_SIZE || mtd->erasesize != 0x20000 ||
	    mtd->writesize != 0x800) {
		printf("%s has an unexpected geometry.\n", mtd->name);
		put_mtd_device(mtd);
		return NULL;
	}

	return mtd;
}

int rtk_validate_loader(const void *image, size_t size)
{
	struct rtk_fip next;
	unsigned char *current;
	struct mtd_info *mtd;
	int ret;

	if (rtk_loader_parse(image, size, &next)) {
		printf("Not a %u byte boot image with two matching FIPs.\n",
		       RTK_BOOT_SIZE);
		return -EINVAL;
	}
	mtd = boot_mtd();
	if (!mtd)
		return -ENODEV;
	current = malloc_cache_aligned(RTK_BOOT_SIZE);
	if (!current) {
		put_mtd_device(mtd);
		return -ENOMEM;
	}
	ret = rtk_mtd_read(mtd, 0, current, RTK_BOOT_SIZE);
	if (!ret && rtk_loader_preserves_device(image, size, current,
						RTK_BOOT_SIZE)) {
		puts("Boot image must keep this device's GPT, BL2, BL31 and reserved bytes.\n");
		ret = -EINVAL;
	}
	free(current);
	put_mtd_device(mtd);

	return ret;
}

int rtk_install_boot(const void *image, size_t size,
		     const struct storage_job *job)
{
	static const struct {
		size_t offset, size;
	} order[] = {
		{ RTK_FIP1_OFFSET, RTK_FIP_SIZE },
		{ RTK_FIP0_OFFSET, RTK_FIP_SIZE },
		{ 0, RTK_FIP0_OFFSET },
		{ RTK_FIP1_OFFSET + RTK_FIP_SIZE,
		  RTK_BOOT_SIZE - RTK_FIP1_OFFSET - RTK_FIP_SIZE },
	};
	const unsigned char *input = image;
	struct mtd_info *mtd;
	size_t done = 0;
	unsigned int i;
	u64 offset;
	int ret;

	ret = rtk_validate_loader(image, size);
	if (ret)
		return ret;
	mtd = boot_mtd();
	if (!mtd)
		return -ENODEV;
	for (offset = 0; offset < RTK_BOOT_SIZE; offset += mtd->erasesize) {
		ret = mtd_block_isbad(mtd, offset);
		if (ret) {
			printf("%s has a bad block at 0x%llx; nothing written.\n",
			       mtd->name, (unsigned long long)offset);
			ret = ret < 0 ? ret : -EIO;
			goto out;
		}
	}
	/* Both FIPs go first: an interruption later still leaves one bootable. */
	for (i = 0; i < ARRAY_SIZE(order); i++) {
		ret = rtk_mtd_write(mtd, order[i].offset,
				    input + order[i].offset, order[i].size,
				    job, done, RTK_BOOT_SIZE, false);
		if (ret)
			goto out;
		done += order[i].size;
	}
	printf("%s written and read back (%u bytes).\n", mtd->name,
	       RTK_BOOT_SIZE);
out:
	put_mtd_device(mtd);

	return ret;
}

static int erase_ubi_mtd(const struct rtk_recovery_layout *l,
			 const struct storage_job *job)
{
	struct mtd_info *mtd;
	u64 offset;
	int ret = 0;

	mtd_probe_devices();
	mtd = get_mtd_device_nm(l->boot->ubi_part);
	if (IS_ERR(mtd))
		return PTR_ERR(mtd);
	if (!mtd_is_partition(mtd) || !mtd->erasesize ||
	    mtd->size % mtd->erasesize) {
		put_mtd_device(mtd);
		return -EINVAL;
	}
	storage_job_report(job, STORAGE_PHASE_ERASE, 0, mtd->size);
	for (offset = 0; offset < mtd->size; offset += mtd->erasesize) {
		struct erase_info erase = {
			.mtd = mtd, .addr = offset, .len = mtd->erasesize
		};

		ret = mtd_block_isbad(mtd, offset);
		if (ret < 0)
			break;
		if (ret) {
			printf("Bad block at 0x%08llx stays out of UBI.\n",
			       (unsigned long long)offset);
			ret = 0;
		} else {
			ret = mtd_erase(mtd, &erase);
			if (ret)
				break;
		}
		storage_job_report(job, STORAGE_PHASE_ERASE,
				   offset + mtd->erasesize, mtd->size);
		storage_job_service(job);
	}
	put_mtd_device(mtd);

	return ret;
}

int rtk_rebuild_ubi(const struct storage_job *job)
{
	const struct rtk_recovery_layout *l = layout();
	unsigned int i;
	int ret;

	if (rtk_ubi_attached()) {
		puts("Detaching UBI.\n");
		ubi_detach_quick();
	}
	printf("Erasing %s.\n", l->boot->ubi_part);
	ret = erase_ubi_mtd(l, job);
	if (ret) {
		printf("Erasing %s failed (%d).\n", l->boot->ubi_part, ret);
		return ret;
	}
	ret = rtk_ubi_attach();
	if (ret)
		return ret;
	for (i = 0; i < l->nr_volumes; i++) {
		const struct rtk_ubi_volume *spec = &l->volumes[i];

		if (spec->policy != RTK_VOL_DATA)
			continue;
		ret = ubi_errno(ubi_volume_create(spec->name, spec->size,
						  spec->dynamic));
		if (ret) {
			printf("Creating %s failed (%d).\n", spec->name, ret);
			return ret;
		}
		storage_job_service(job);
	}
	printf("UBI rebuilt on %s and left attached.\n", l->boot->ubi_part);
	puts("Factory is empty; import the factory image, then install a system.\n");

	return 0;
}

bool rtk_ubi_attached(void)
{
	const char *part = ubi_part_name();

	return part && !strcmp(part, layout()->boot->ubi_part);
}

static int rtk_ubi_require(void)
{
	if (rtk_ubi_attached())
		return 0;
	printf("UBI is not attached; attach %s first.\n", layout()->boot->ubi_part);

	return -ENODEV;
}

int rtk_ubi_create(const char *name, u64 size, bool dynamic)
{
	if (rtk_ubi_require())
		return -ENODEV;
	if (!rtk_storage_name_valid(name) || strlen(name) >= 32)
		return -EINVAL;
	if (ubi_volume_exists(name)) {
		printf("Volume %s already exists.\n", name);
		return -EEXIST;
	}

	return ubi_errno(ubi_volume_create(name, size, dynamic));
}

int rtk_ubi_remove(const char *name)
{
	if (rtk_ubi_require())
		return -ENODEV;
	if (!ubi_volume_exists(name))
		return -ENOENT;

	return ubi_errno(ubi_volume_remove(name));
}

int rtk_ubi_rename(const char *old_name, const char *new_name)
{
	if (rtk_ubi_require())
		return -ENODEV;
	if (!rtk_storage_name_valid(new_name) || strlen(new_name) >= 32)
		return -EINVAL;
	if (!ubi_volume_exists(old_name))
		return -ENOENT;
	if (ubi_volume_exists(new_name)) {
		printf("Volume %s already exists.\n", new_name);
		return -EEXIST;
	}

	return ubi_errno(ubi_volume_rename(old_name, new_name));
}

int rtk_ubi_attach(void)
{
	return rtk_ubi_ensure();
}

int rtk_ubi_detach(bool quick)
{
	if (!ubi_part_name())
		return 0;

	return ubi_errno(quick ? ubi_detach_quick() : ubi_detach());
}
