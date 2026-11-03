#!/bin/sh
# SPDX-License-Identifier: GPL-2.0-only
#
# One-stop boot build: BL33 stub -> signed FIP -> flashable images.
# Board definitions live in tools/release/boards/<board>.json; every
# input (stock backup, TF-A tools, signing keys) is inside the repo.
#
#   ./build.sh all              every board, end to end
#   ./build.sh <board>          one board, end to end
#   ./build.sh <board> bl33     just the BL33 stub
#   ./build.sh <board> pack     just the signed images (needs bl33.bin)
#   ./build.sh <board> verify   just verify the existing images
#
# Outputs per board in output/<board>/:
#   <board>.boot.bin       full mtd0 image, the normal flash path
#   <board>.fip.bin        main-slot slice for the BL2 Xmodem 'F' rescue
#   <board>.manifest.json  digests of every input and output
set -eu

REPO=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
REL=$REPO/tools/release

usage() {
	echo "usage: $0 all | <board> [bl33|pack|verify]" >&2
	exit 1
}

case "${1:-}" in
"" | -h | --help)
	usage
	;;
all)
	found=0
	for cfg in "$REL"/boards/*.json; do
		[ -e "$cfg" ] && found=1
		b=$(basename "$cfg" .json)
		echo "==> $b: end-to-end"
		"$0" "$b"
	done
	[ "$found" = 1 ] || usage
	;;
*)
	board=$1
	[ -f "$REL/boards/$board.json" ] || {
		echo "unknown board: $board (no tools/release/boards/$board.json)" >&2
		usage
	}
	step=${2:-all}
	case $step in
	bl33)
		exec "$REL/build_bl33.sh" "$board"
		;;
	pack)
		exec python3 "$REL/pack_boot.py" pack --board "$board"
		;;
	verify)
		exec python3 "$REL/pack_boot.py" verify --board "$board" \
			--image "$REPO/output/$board/$board.boot.bin" \
			--stock "$REL/stocks/$board/stock-mtd0.bin"
		;;
	all)
		"$REL/build_bl33.sh" "$board"
		python3 "$REL/pack_boot.py" pack --board "$board"
		;;
	*)
		usage
		;;
	esac
	;;
esac
