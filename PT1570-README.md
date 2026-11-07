# PT1570-H10 adaptation files (commit 4c13f1b)

Files for Youhua PT1570-H10 (RTL9617C) on lyq1996/qwe-qaq rtl9617c-uboot,
synced to upstream main (9abafc0). Paths are repo-relative: extract this
archive over the repository root.

New files:
  board/yhup/pt1570_h10/            board dir (board.c desc.c layout.c env Kconfig Makefile)
  configs/pt1570-h10_defconfig
  arch/arm/dts/rtl9617c-pt1570-h10.dts
  doc/board/yhup/pt1570_h10.rst
  tools/release/boards/pt1570-h10.json            bl33 budget 459937, stock sha256 pinned
  tools/release/stocks/pt1570-h10/stock-mtd0.bin  the unit's own 2 MiB mtd0 backup

Modified files:
  arch/arm/mach-realtek/rtl9617c/Kconfig   + TARGET_YHUP_PT1570_H10, + source board Kconfig
  doc/board/yhup/index.rst                 + pt1570_h10 in the toctree

Build:  ./build.sh pt1570-h10   (or let GitHub Actions build it)
Flash:  write only fip1 (0x100000-0x1c0000) first; fip0 keeps the stock image.