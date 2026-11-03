// SPDX-License-Identifier: GPL-2.0+
/*
 * Realtek RTL9617C SoC support: MMU map, DRAM
 * discovery, watchdog and packet memory hand-off.
 */
#include <config.h>
#include <init.h>
#include <stdio.h>
#include <stddef.h>
#include <asm/global_data.h>
#include <asm/io.h>
#include <asm/armv8/mmu.h>
#include <linux/arm-smccc.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/psci.h>
#include <asm/arch/registers.h>
#include <asm/arch/soc.h>

DECLARE_GLOBAL_DATA_PTR;

/*
 * DRAM is trained by BL2, which publishes the population it brought up in
 * RTL9617C_BL2_DRAM_MB. Boards of this platform ship with DDR3L or DDR4 and in
 * different densities, so the size is a run-time property: U-Boot only sizes
 * its banks and its MMU map from it. Below the minimum the BL31 window would
 * not fit; above the maximum the DRAM would run into the SoC's device space,
 * which starts at 2 GiB.
 */
#define RTL9617C_DRAM_MIN_MB	256U
#define RTL9617C_DRAM_MAX_MB	2048U

static struct mm_region rtl9617c_mem_map[] = {
	{ .virt = 0, .phys = 0, .size = 0x20000000,
	  .attrs = PTE_BLOCK_MEMTYPE(MT_NORMAL) | PTE_BLOCK_INNER_SHARE },
	{ .virt = 0x80000000UL, .phys = 0x80000000UL, .size = 0x580000000UL,
	  .attrs = PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) | PTE_BLOCK_NON_SHARE |
		   PTE_BLOCK_PXN | PTE_BLOCK_UXN },
	{ 0 }
};
struct mm_region *mem_map = rtl9617c_mem_map;

static u32 original_xram[0x2000 / sizeof(u32)];

/* A DDR3L or DDR4 population BL2 has brought up, a power of two of MiB. */
static int rtl9617c_dram_population_valid(u32 mb)
{
	return mb >= RTL9617C_DRAM_MIN_MB && mb <= RTL9617C_DRAM_MAX_MB &&
	       !(mb & (mb - 1));
}

/*
 * Weak so a board with a different DRAM population can override them; both
 * boards of this platform accept whatever BL2 trained.
 */
__weak int dram_init(void)
{
	u32 mb = rtl9617c_dram_size_mb();

	if (!rtl9617c_dram_population_valid(mb)) {
		printf("DRAM: BL2 reports %u MiB, expected 256..2048 MiB\n", mb);
		return -EINVAL;
	}
	gd->ram_size = (phys_size_t)mb << 20;

	return 0;
}

__weak int dram_init_banksize(void)
{
	phys_addr_t size = gd->ram_size;

	if (!size)
		size = (phys_addr_t)rtl9617c_dram_size_mb() << 20;
	/* The BL31 window is a property of the platform firmware, not of the
	 * board, so the banks are split around it at any population. */
	gd->bd->bi_dram[0].start = 0;
	gd->bd->bi_dram[0].size = min_t(phys_addr_t, size,
					RTL9617C_SECURE_DRAM_START);
	gd->bd->bi_dram[1].start = RTL9617C_SECURE_DRAM_END;
	gd->bd->bi_dram[1].size = size > RTL9617C_SECURE_DRAM_END ?
				  size - RTL9617C_SECURE_DRAM_END : 0;
	/* One normal region for the whole population, as before; the banks keep
	 * allocations out of the secure window. */
	rtl9617c_mem_map[0].size = size;

	return 0;
}

u32 rtl9617c_dram_size_mb(void)
{
	return readl(RTL9617C_BL2_DRAM_MB);
}

void rtl9617c_early_init(void)
{
	unsigned int i;

	/* Also covers entry from RAM without the compressed BL33 wrapper. */
	writel(0, PER_WDT_CTRL);
	writel(1, RTL9617C_BOOT_SCRATCH);
	for (i = 0; i < ARRAY_SIZE(original_xram); i++)
		original_xram[i] = readl(NI_XRAM_BASE + i * 4);
}

void rtl9617c_xram_restore(void)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(original_xram); i++)
		writel(original_xram[i], NI_XRAM_BASE + i * 4);
}

int print_cpuinfo(void)
{
	puts("CPU:   Realtek RTL9617C, Cortex-A55\n");
	return 0;
}

void reset_cpu(void)
{
	struct arm_smccc_res res;

	arm_smccc_smc(PSCI_0_2_FN_SYSTEM_RESET, 0, 0, 0, 0, 0, 0, 0, &res);
}

/*
 * Memory the platform keeps for itself. An uploaded image must not be placed
 * over any of it: the exception vectors, the window the boot hand-off uses,
 * the packet memory the NI MAC DMAs from, and the region BL31 owns.
 */
static const struct {
	ulong begin;
	ulong end;
} rtl9617c_reserved[] = {
	{ 0x00000000, 0x00001000 },	/* exception vectors */
	{ 0x02000000, 0x02400000 },	/* boot hand-off window */
	{ 0x09000000, 0x0aa50000 },	/* NI packet memory, non-cached alias */
	{ 0x0bc48000, 0x0bc58000 },	/* NI coherent buffers */
	{ RTL9617C_SECURE_DRAM_START, RTL9617C_SECURE_DRAM_END },	/* secure mailboxes and BL31 */
};

bool rtl9617c_memory_is_reserved(ulong start, size_t size)
{
	unsigned int i;

	if (!size || start + size < start)
		return true;
	for (i = 0; i < ARRAY_SIZE(rtl9617c_reserved); i++)
		if (start < rtl9617c_reserved[i].end &&
		    start + size > rtl9617c_reserved[i].begin)
			return true;

	return false;
}

/* Stop every NI MAC before the hand-off, as the stock firmware does. */
void rtl9617c_ni_stop_all(void)
{
	unsigned int i;

	for (i = 0; i < 6; i++)
		clrbits_le32(0xf430a5c8 + i * 0x90, 1);
}
