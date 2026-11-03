/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Linker script for the BL33 LZMA stub.  Preprocessed with cpp so EXEC_ADDR
 * comes from the same loader-config.h the C sources use; build.sh runs
 *   $(CROSS_COMPILE)gcc -E -P -x c -I<builddir> linker.lds.S -o linker.lds
 * and never edits this file.
 */
#include "loader-config.h"

OUTPUT_FORMAT("elf64-littleaarch64")
OUTPUT_ARCH(aarch64)
ENTRY(_start)
PHDRS { code PT_LOAD FLAGS(5); data PT_LOAD FLAGS(6); }
SECTIONS {
	. = EXEC_ADDR;
	.text : { KEEP(*(.text.start)) *(.text*) } :code
	.rodata : { KEEP(*(.rodata.stub_id)) *(.rodata*) } :code
	.data : { *(.data*) } :data
	.tail : { BYTE(0); . = ALIGN(16); } :data
	_image_end = .;
	.bss (NOLOAD) : { . = ALIGN(16); __bss_start = .; *(.bss*) *(COMMON) . = ALIGN(16); __bss_end = .; } :data
	/DISCARD/ : { *(.comment*) *(.note*) *(.eh_frame*) }
}
