// SPDX-License-Identifier: GPL-2.0-only
/*
 * BL33 LZMA self-decompressor for the Realtek RTL9617C boards.
 *
 * BL2 loads this image and jumps to it with the BL31 handoff in x0-x3.  The
 * stub (see start.S) has already moved itself to EXEC_ADDR; loader_main()
 * decompresses the U-Boot image embedded in the payload to RUN_ADDR, the
 * boards' CONFIG_TEXT_BASE, and enters it with the handoff preserved.
 * Compressing is what lets the recovery service live inside the fixed BL33
 * slot; build.sh at the top of the tree does the packing.
 *
 * Integrity: the stream must decode to exactly PLAIN_SIZE bytes and match
 * PLAIN_CRC, the CRC32 of the plain image computed at build time.  The size
 * field inside the .lzma header is deliberately not trusted: xz writes
 * "unknown" there.  Any failure prints one line on the debug UART and parks
 * the core with wfe - a half-decoded image must never be entered.
 */
#include <stddef.h>
#include <stdint.h>
#include "loader-config.h"
#include "LzmaDec.h"

/* Debug UART, identical on both boards: uart0 in arch/arm/dts/rtl9617c.dtsi. */
#define UART_BASE	0xf43291b0
#define UART_TX_DATA	0x10
#define UART_INFO	0x18
#define UART_TX_FULL	(1u << 2)

/* BL2 can leave its short boot watchdog armed; clear it before decompressing. */
#define WDT_CLEAR	0xf432901c

/* Probability table for one LZMA1 stream with lc=3/lp=0; dict lives in RAM. */
static unsigned char workspace[65536] __attribute__((aligned(16)));

extern const unsigned char payload_start[], payload_end[];
extern void loader_sync_code(uintptr_t address, size_t size);

void *memcpy(void *dest, const void *src, size_t size)
{
	unsigned char *to = dest;
	const unsigned char *from = src;
	while (size--) *to++ = *from++;
	return dest;
}

void *memset(void *dest, int value, size_t size)
{
	unsigned char *to = dest;
	while (size--) *to++ = (unsigned char)value;
	return dest;
}

static void serial_puts(const char *s)
{
	volatile uint32_t *data = (void *)(uintptr_t)(UART_BASE + UART_TX_DATA);
	volatile uint32_t *status = (void *)(uintptr_t)(UART_BASE + UART_INFO);
	while (*s) {
		unsigned int timeout = 1000000;
		while ((*status & UART_TX_FULL) && --timeout) {}
		if (!timeout) return;
		*data = (unsigned char)*s++;
	}
}

static void *alloc_probs(ISzAllocPtr allocator, size_t size)
{
	(void)allocator;
	return size <= sizeof(workspace) ? workspace : NULL;
}

static void free_probs(ISzAllocPtr allocator, void *address)
{
	(void)allocator;
	(void)address;
}

static uint32_t crc32(const unsigned char *data, size_t size)
{
	uint32_t crc = 0xffffffff;
	unsigned int bit;
	while (size--) {
		crc ^= *data++;
		for (bit = 0; bit < 8; bit++)
			crc = (crc >> 1) ^ (0xedb88320U & -(crc & 1));
	}
	return ~crc;
}

static __attribute__((noreturn)) void failed(void)
{
	serial_puts("bl33: integrity/decompression failed\r\n");
	for (;;) __asm__ volatile("wfe");
}

__attribute__((noreturn)) void loader_main(unsigned long a0, unsigned long a1,
					   unsigned long a2, unsigned long a3)
{
	const ISzAlloc allocator = { alloc_probs, free_probs };
	SizeT source_size = payload_end - payload_start;
	SizeT output_size = PLAIN_SIZE;
	ELzmaStatus status;
	int ret;

	*(volatile uint32_t *)(uintptr_t)WDT_CLEAR = 0;
	__asm__ volatile("dsb sy" : : : "memory");

	serial_puts("BL33: loader started\r\n");

	/* lc=3 lp=0 pb=2, as build_bl33.sh produces it; reject anything else. */
	if (source_size < 13 || payload_start[0] != 0x5d) failed();

	source_size -= 13;
	ret = LzmaDecode((void *)(uintptr_t)RUN_ADDR, &output_size,
			 payload_start + 13, &source_size, payload_start, 5,
			 LZMA_FINISH_END, &status, &allocator);
	if (ret != SZ_OK) failed();
	/*
	 * xz emits no end marker, so an exact-size stream that consumed its
	 * whole input comes back LZMA_STATUS_NOT_FINISHED.  Only the
	 * "unspecified" status means the decoder gave up on its own; the
	 * exact-size and CRC32 checks below catch every other way the image
	 * could be wrong.
	 */
	if (status == LZMA_STATUS_NOT_SPECIFIED) failed();
	if (output_size != PLAIN_SIZE) failed();
	if (source_size != (SizeT)(payload_end - payload_start - 13)) failed();
	if (crc32((void *)(uintptr_t)RUN_ADDR, output_size) != PLAIN_CRC) failed();

	loader_sync_code(RUN_ADDR, output_size);
	serial_puts("BL33: decompressed and verified\r\n");
	((void (*)(unsigned long, unsigned long, unsigned long, unsigned long))
	 (uintptr_t)RUN_ADDR)(a0, a1, a2, a3);
	failed();
}
