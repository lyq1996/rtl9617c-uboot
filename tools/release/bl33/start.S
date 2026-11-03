/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * BL33 stub entry.  BL2 loads this image and jumps to _start with the BL31
 * handoff in x0-x3.  The load address is whatever the FIP entry says, so the
 * first thing we do is copy ourselves to EXEC_ADDR and continue from there;
 * that keeps the decompression target (RUN_ADDR) free to overwrite wherever
 * BL2 put us.  x0-x3 survive in x19-x22 across relocation, BSS setup and the
 * call into loader_main().
 */
#include "loader-config.h"

.section .text.start, "ax"
.global _start
_start:
	/* Preserve the BL31 handoff across relocation and decompression. */
	mov x19, x0
	mov x20, x1
	mov x21, x2
	mov x22, x3
	adr x23, _start
	ldr x24, =EXEC_ADDR
	cmp x23, x24
	b.eq .Lrelocated
	adrp x25, _image_end
	add x25, x25, :lo12:_image_end
	sub x25, x25, x23
	mov x9, x23
	mov x10, x24
	mov x11, x25
.Lcopy:
	ldrb w12, [x9], #1
	strb w12, [x10], #1
	subs x11, x11, #1
	b.ne .Lcopy
	mov x0, x24
	mov x1, x25
	bl loader_sync_code
	adr x9, .Lrelocated
	sub x9, x9, x23
	add x9, x9, x24
	br x9
.Lrelocated:
	ldr x9, =STACK_TOP
	mov sp, x9
	adrp x9, __bss_start
	add x9, x9, :lo12:__bss_start
	adrp x10, __bss_end
	add x10, x10, :lo12:__bss_end
.Lclear:
	cmp x9, x10
	b.hs .Lenter
	str xzr, [x9], #8
	b .Lclear
.Lenter:
	mov x0, x19
	mov x1, x20
	mov x2, x21
	mov x3, x22
	bl loader_main
.Lhalt:
	wfe
	b .Lhalt

/*
 * x0 = first address, x1 = byte count; no stack or absolute data accesses.
 * Runs before the MMU is touched, straight after byte-by-byte self-copy.
 */
.global loader_sync_code
loader_sync_code:
	mrs x2, ctr_el0
	ubfx x3, x2, #16, #4
	mov x4, #4
	lsl x3, x4, x3
	sub x5, x3, #1
	bic x6, x0, x5
	add x1, x0, x1
.Ldcache:
	dc cvau, x6
	add x6, x6, x3
	cmp x6, x1
	b.lo .Ldcache
	dsb sy
	and x2, x2, #15
	lsl x3, x4, x2
	sub x5, x3, #1
	bic x6, x0, x5
.Licache:
	ic ivau, x6
	add x6, x6, x3
	cmp x6, x1
	b.lo .Licache
	dsb sy
	isb
	ret

/*
 * Identity for the flashing tools: the migration tool refuses files that do
 * not look like a plain U-Boot, so a stub names itself and its board here
 * instead (STUB_BOARD comes from loader-config.h). Never executed.
 */
	.section .rodata.stub_id, "a"
	.global stub_id
stub_id:
	.asciz "RTL9-BL33-LZMA-STUB:", STUB_BOARD
