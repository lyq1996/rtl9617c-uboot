#!/bin/sh
# SPDX-License-Identifier: GPL-2.0-only
#
# Build the flashable BL33 stub for one board. The board id and the BL33
# byte budget come from tools/release/boards/<board>.json.
#
#   build_bl33.sh <board>
#
# What it does:
#   1. build U-Boot with the board defconfig (output/<board>/u-boot-dtb.bin)
#   2. compress it with LZMA1 (alone format, dict 1 MiB, lc3/lp0/pb2)
#   3. compile loader/ into the self-decompressing BL33 stub with the
#      payload embedded, and emit output/<board>/bl33.bin
#
# Requires: aarch64-linux-gnu- toolchain, xz, gzip, od, awk.
set -eu

REL=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
REPO=$(CDPATH= cd -- "$REL/../.." && pwd)
cd "$REPO"
CROSS_COMPILE=${CROSS_COMPILE:-aarch64-linux-gnu-}
export CROSS_COMPILE
CC=${CROSS_COMPILE}gcc
LD=${CROSS_COMPILE}ld
OBJCOPY=${CROSS_COMPILE}objcopy
NM=${CROSS_COMPILE}nm

EXEC_ADDR=0x08000000		# stub self-relocates here, decodes from here
RUN_ADDR=0x04000000		# CONFIG_TEXT_BASE of both boards
STACK_TOP=0x01000000
WINDOW=$((0x1000000))		# stub image + workspace must stay under 16 MiB

die() { echo "build_bl33: $1" >&2; exit 1; }

board_field() {
	python3 -c 'import json,sys; print(json.load(open(sys.argv[1]))[sys.argv[2]])' \
		"$REL/boards/$1.json" "$2"
}

build_board() {
	board=$1
	cfg=$REL/boards/$board.json
	[ -f "$cfg" ] || die "no board config: $cfg"
	defconfig=$(board_field "$board" defconfig)
	board_id=$(board_field "$board" board_id)
	budget=$(board_field "$board" bl33_budget)
	out=output/$board
	ldir=$out/loader
	log=$REPO/$out/build.log

	echo "==> $board: building U-Boot (log: $out/build.log)"
	mkdir -p "$ldir"
	make O="$out" "$defconfig" >"$log" 2>&1
	make O="$out" -j"$(nproc)" >>"$log" 2>&1
	bin=$out/u-boot-dtb.bin
	[ -f "$bin" ] || die "$bin not found - unexpected build output"
	plain_size=$(stat -c%s "$bin")

	echo "==> $board: compressing (LZMA1, dict 1MiB, lc3 lp0 pb2)"
	payload=$REPO/$ldir/payload.lzma
	xz --format=lzma --lzma1=preset=9e,dict=1MiB,lc=3,lp=0,pb=2 \
		-c "$bin" >"$payload"
	props=$(od -An -tx1 -N1 "$payload" | tr -d ' \n')
	[ "$props" = "5d" ] || die "unexpected LZMA props byte $props"
	lzma_size=$(stat -c%s "$payload")
	xz -dc "$payload" | cmp -s - "$bin" || die "LZMA roundtrip mismatch"

	# CRC32 of the plain image, straight out of the gzip footer.
	gzip -c "$bin" >"$ldir/plain.gz"
	crc=$(gzip -lv "$ldir/plain.gz" | awk 'NR==2 {print $2}')
	rm -f "$ldir/plain.gz"
	case "$crc" in ????????) ;; *) die "could not read CRC32 from gzip -lv" ;; esac

	echo "==> $board: building the BL33 stub"
	cat >"$ldir/loader-config.h" <<EOF
#define EXEC_ADDR ${EXEC_ADDR}
#define RUN_ADDR ${RUN_ADDR}
#define STACK_TOP ${STACK_TOP}
#define PLAIN_SIZE ${plain_size}
#define PLAIN_CRC 0x${crc}
#define STUB_BOARD "${board_id}"
EOF
	cat >"$ldir/payload.S" <<EOF
.section .rodata.payload,"a"
.balign 16
.global payload_start,payload_end
payload_start:
.incbin "$payload"
payload_end:
EOF
	$CC -E -P -x c -I "$REPO/$ldir" loader/linker.lds.S >"$ldir/linker.lds"

	# lib/lzma is written against the U-Boot environment; strip that away.
	mkdir -p "$ldir/lzma"
	for f in LzmaDec.h 7zTypes.h Compiler.h Precomp.h; do
		cp "lib/lzma/$f" "$ldir/lzma/$f"
	done
	sed -e '/#include <config.h>/d' \
	    -e '/#include <watchdog.h>/d' \
	    -e 's|#include <linux/string.h>|#include <string.h>|' \
	    -e 's|schedule();|((void)0);|' \
	    lib/lzma/LzmaDec.c >"$ldir/lzma/LzmaDec.c"

	# The stub is bare metal: no hosted libc may leak into it.  $ldir/lzma is
	# the first -I directory, so these shims win over any system header and
	# the build stops depending on how the toolchain lays out its sysroot.
	#   errno.h   7zTypes.h pulls it in but never uses it
	#   string.h  LzmaDec.c needs memcpy; main.c defines memcpy/memset
	cat >"$ldir/lzma/errno.h" <<'EOF'
/* Loader shim: 7zTypes.h includes <errno.h> but never uses errno. */
#ifndef LOADER_ERRNO_SHIM_H
#define LOADER_ERRNO_SHIM_H
#endif
EOF
	cat >"$ldir/lzma/string.h" <<'EOF'
/* Loader shim: the stub is freestanding; memcpy/memset come from main.c. */
#ifndef LOADER_STRING_SHIM_H
#define LOADER_STRING_SHIM_H
#include <stddef.h>
void *memcpy(void *dest, const void *src, size_t size);
void *memset(void *dest, int value, size_t size);
#endif
EOF

	cflags="-Os -ffreestanding -fno-builtin -fno-stack-protector -fno-pie \
-mgeneral-regs-only -mstrict-align -ffunction-sections -fdata-sections \
-Wall -Wextra -Werror -DZ7_LZMA_SIZE_OPT -I$REPO/$ldir -I$REPO/$ldir/lzma"
	for src in loader/start.S loader/main.c "$ldir/payload.S" \
			"$ldir/lzma/LzmaDec.c"; do
		obj=$ldir/$(basename "${src%.*}").o
		$CC $cflags -c "$src" -o "$obj"
	done
	elf=$ldir/bl33.elf
	$LD --gc-sections --build-id=none -T "$ldir/linker.lds" \
		"$ldir/start.o" "$ldir/main.o" "$ldir/payload.o" \
		"$ldir/LzmaDec.o" -o "$elf"
	$OBJCOPY -O binary "$elf" "$out/bl33.bin"

	# Geometry: the relocation copy and the decode output must not fight.
	addresses=$($NM "$elf" | awk '$3 ~ /^(__bss_end|_image_end)$/ {print $3"=0x"$1}')
	eval "$addresses"
	[ -n "${__bss_end:-}" ] && [ -n "${_image_end:-}" ] \
		|| die "loader symbols missing"
	bl33_size=$(stat -c%s "$out/bl33.bin")
	[ "$((_image_end - EXEC_ADDR))" = "$bl33_size" ] \
		|| die "image length does not match _image_end"
	[ $(($__bss_end - EXEC_ADDR)) -lt "$WINDOW" ] \
		|| die "stub workspace overflows the 16 MiB window"
	[ $((RUN_ADDR + plain_size - EXEC_ADDR)) -lt 0 ] \
		|| die "decompressed U-Boot would overwrite the stub at EXEC_ADDR"
	[ "$bl33_size" -le "$budget" ] \
		|| die "bl33 is $bl33_size bytes, budget is $budget"

	echo "==> $board: plain $plain_size, lzma $lzma_size, bl33 $bl33_size" \
		"(budget $budget)"
}

case "${1:-}" in
*/*|*.json) die "usage: $0 <board>" ;;
"") die "usage: $0 <board>" ;;
*) build_board "$1" ;;
esac
