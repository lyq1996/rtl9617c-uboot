// SPDX-License-Identifier: GPL-2.0-only
#include <rtk_recovery.h>
#include <string.h>

static uint64_t le64(const unsigned char *p)
{
	uint64_t n = 0;
	unsigned int i;
	for (i = 0; i < 8; i++)
		n |= (uint64_t)p[i] << (8 * i);
	return n;
}

static int zeros(const unsigned char *p, size_t size)
{
	while (size--)
		if (*p++) return 0;
	return 1;
}

int rtk_fip_parse(const void *data, size_t size, struct rtk_fip *out)
{
	static const unsigned char ids[3][16] = {
		{0x5f,0xf9,0xec,0x0b,0x4d,0x22,0x3e,0x4d,0xa5,0x44,0xc3,0x9d,0x81,0xc7,0x3f,0x0a},
		{0x47,0xd4,0x08,0x6d,0x4c,0xfe,0x98,0x46,0x9b,0x95,0x29,0x50,0xcb,0xbd,0x5a,0x00},
		{0xd6,0xd0,0xee,0xa7,0xfc,0xea,0xd5,0x4b,0x97,0x82,0x99,0x34,0xf2,0x34,0xb6,0xe4},
	};
	struct rtk_payload *payloads[] = { &out->bl2, &out->bl31, &out->bl33 };
	const unsigned char *p = data;
	size_t toc, pos, prev;
	unsigned int i, found = 0;

	memset(out, 0, sizeof(*out));
	if (size < 56 || memcmp(p, "\x01\x00\x64\xaa", 4)) return -1;
	for (toc = 16; toc <= size - 40 && toc < 16 + 32 * 40; toc += 40)
		if (zeros(p + toc, 16)) break;
	if (toc > size - 40 || toc >= 16 + 32 * 40) return -1;
	toc += 40;
	for (pos = 16; pos < toc - 40; pos += 40) {
		uint64_t off = le64(p + pos + 16), len = le64(p + pos + 24);
		if (!len || off < toc || off > size || len > size - off) return -1;
		for (prev = 16; prev < pos; prev += 40) {
			uint64_t old = le64(p + prev + 16), count = le64(p + prev + 24);
			if (!memcmp(p + pos, p + prev, 16) ||
			    (off < old + count && old < off + len)) return -1;
		}
		for (i = 0; i < 3; i++) {
			if (memcmp(p + pos, ids[i], 16)) continue;
			found |= 1U << i;
			payloads[i]->data = p + (size_t)off;
			payloads[i]->size = (size_t)len;
		}
	}
	return found == 7 ? 0 : -1;
}

int rtk_loader_parse(const void *data, size_t size, struct rtk_fip *out)
{
	const unsigned char *p = data;
	struct rtk_fip second;
	if (size != RTK_BOOT_SIZE || memcmp(p + 0x200, "EFI PART", 8) ||
	    memcmp(p + size - 512, "EFI PART", 8) ||
	    rtk_fip_parse(p + RTK_FIP0_OFFSET, RTK_FIP_SIZE, out) ||
	    rtk_fip_parse(p + RTK_FIP1_OFFSET, RTK_FIP_SIZE, &second)) return -1;
	if (out->bl2.size != second.bl2.size || out->bl31.size != second.bl31.size ||
	    out->bl33.size != second.bl33.size ||
	    memcmp(out->bl2.data, second.bl2.data, out->bl2.size) ||
	    memcmp(out->bl31.data, second.bl31.data, out->bl31.size) ||
	    memcmp(out->bl33.data, second.bl33.data, out->bl33.size)) return -1;
	return 0;
}

static uint32_t gpt_crc32(const unsigned char *data, size_t size)
{
	uint32_t crc = 0xffffffffU;
	unsigned int i;
	while (size--) {
		crc ^= *data++;
		for (i = 0; i < 8; i++)
			crc = (crc >> 1) ^ ((crc & 1) ? 0xedb88320U : 0);
	}
	return ~crc;
}

static uint32_t le32(const unsigned char *p)
{
	return (uint32_t)p[0] | (uint32_t)p[1] << 8 |
	       (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24;
}

static int gpt_checksums_valid(const unsigned char *data)
{
	unsigned char header[92];
	unsigned int i;
	for (i = 0; i < 2; i++) {
		size_t h = i ? RTK_BOOT_SIZE - 0x200 : 0x200;
		size_t e = i ? RTK_BOOT_SIZE - 0x4200 : 0x400;
		/* Validate the fixed GPT geometry used by the identity mask below. */
		if (memcmp(data + h, "EFI PART", 8) || le32(data + h + 12) != sizeof(header) ||
		    le64(data + h + 72) != e / 512 || le32(data + h + 80) != 128 ||
		    le32(data + h + 84) != 128) return 0;
		memcpy(header, data + h, sizeof(header));
		memset(header + 16, 0, 4);
		if (gpt_crc32(header, sizeof(header)) != le32(data + h + 16) ||
		    gpt_crc32(data + e, 0x4000) != le32(data + h + 88)) return 0;
	}
	return 1;
}

static int gpt_fip_sizes_valid(const unsigned char *data, const unsigned char *next)
{
	const size_t offsets[] = { RTK_FIP0_OFFSET, RTK_FIP1_OFFSET };
	const size_t tables[] = { 0x400, RTK_BOOT_SIZE - 0x4200 };
	unsigned int i, j;
	for (i = 0; i < 2; i++) {
		const unsigned char *fip = next + offsets[i];
		uint64_t used = 0;
		size_t pos;
		/* next has already passed rtk_loader_parse(), including ToC bounds. */
		for (pos = 16; !zeros(fip + pos, 16); pos += 40) {
			uint64_t end = le64(fip + pos + 16) + le64(fip + pos + 24);
			if (end > used) used = end;
		}
		for (j = 0; j < 2; j++) {
			const unsigned char *entry = data + tables[j] + i * 128;
			uint64_t first = le64(entry + 32), last = le64(entry + 40);
			if (first != offsets[i] / 512 || last < first ||
			    last >= (offsets[i] + RTK_FIP_SIZE) / 512 ||
			    last - first + 1 < (used + 511) / 512 ||
			    last != le64(data + tables[0] + i * 128 + 40)) return 0;
		}
	}
	return 1;
}

/* GUIDs/CRCs vary per device; bounded FIP lengths vary with the OEM build. */
static int gpt_variable(size_t off)
{
	static const size_t headers[] = { 0x200, RTK_BOOT_SIZE - 0x200 };
	static const size_t entries[] = { 0x400, RTK_BOOT_SIZE - 0x4200 };
	unsigned int i;
	for (i = 0; i < 2; i++) {
		size_t h = headers[i], e = entries[i];
		if ((off >= h + 0x10 && off < h + 0x14) || (off >= h + 0x38 && off < h + 0x48) ||
		    (off >= h + 0x58 && off < h + 0x5c) ||
		    (off >= e && off < e + 0x100 && (off - e) % 0x80 >= 0x28 && (off - e) % 0x80 < 0x30) ||
		    (off >= e && off < e + 0x4000 && (off - e) % 0x80 >= 0x10 && (off - e) % 0x80 < 0x20))
			return 1;
	}
	return 0;
}

static int same_boot_layout(const unsigned char *current, const unsigned char *next,
			    size_t start, size_t end)
{
	for (; start < end; start++)
		if (current[start] != next[start] && !gpt_variable(start)) return 0;
	return 1;
}

int rtk_loader_preserves_device(const void *next_data, size_t next_size,
			       const void *current_data, size_t current_size)
{
	const unsigned char *next = next_data, *current = current_data;
	const size_t offsets[] = { RTK_FIP0_OFFSET, RTK_FIP1_OFFSET };
	struct rtk_fip image, old;
	unsigned int i, matched = 0;
	if (current_size != RTK_BOOT_SIZE || rtk_loader_parse(next, next_size, &image) ||
	    !gpt_checksums_valid(current) || !gpt_checksums_valid(next) ||
	    !gpt_fip_sizes_valid(current, next) || !gpt_fip_sizes_valid(next, next) ||
	    !same_boot_layout(current, next, 0, RTK_FIP0_OFFSET) ||
	    !same_boot_layout(current, next, 0x1c0000, RTK_BOOT_SIZE)) return -1;
	/* An interrupted update may leave old/new BL33s or one invalid ToC. */
	for (i = 0; i < 2; i++) {
		if (rtk_fip_parse(current + offsets[i], RTK_FIP_SIZE, &old)) continue;
		if (old.bl2.size != image.bl2.size || old.bl31.size != image.bl31.size ||
		    memcmp(old.bl2.data, image.bl2.data, old.bl2.size) ||
		    memcmp(old.bl31.data, image.bl31.data, old.bl31.size)) continue;
		matched++;
	}
	return matched ? 0 : -1;
}
