.. SPDX-License-Identifier: GPL-2.0+

Porting
-------

The Realtek support is split into an architecture entry, a SoC target and a
board target.

Kconfig structure
-----------------

The architecture entry sources ``arch/arm/mach-realtek/Kconfig``. That file
holds the SoC-level metadata and sources the individual SoC directories:

.. code-block:: none

   config SYS_SOC
           default "realtek"

   config SYS_CONFIG_NAME
           default "rtl9617c"

   source "arch/arm/mach-realtek/rtl9617c/Kconfig"

The RTL9617C Kconfig defines the SoC selector and the products built on it.
The selector has no prompt: a product selects it, so a product can never be
built against a SoC it does not select:

.. code-block:: none

   config SOC_RTL9617C
           bool
           select ARM64

   config TARGET_TIANYI_TYFZA1_2P5G
           bool "Tianyi TYFZA1 2.5G"
           select SOC_RTL9617C

The product Kconfig then sources the board Kconfig files. A board Kconfig sets
``SYS_BOARD`` and ``SYS_VENDOR`` only; ``SYS_SOC`` and ``SYS_CONFIG_NAME`` come
from the SoC level, because every product of one SoC shares them.

The switch that applies to the whole product family, ``RTK_WEB_FAILSAFE``,
lives in ``board/realtek/Kconfig`` and is enabled by a product defconfig.

Directory structure
-------------------

SoC code belongs below ``arch/arm/mach-realtek/``. SoC headers and register
definitions belong below the corresponding ``arch/arm/include/asm/arch-*``
directory. SoC device-tree nodes belong in ``arch/arm/dts/*-<soc>.dtsi``.

Board code is organized by manufacturer and model, and the code every
product of the SoC shares sits directly below ``board/realtek``:

.. code-block:: none

   board/realtek/common/      boot policy
   board/realtek/failsafe/    browser based recovery: service, engine,
                              storage, board description, status lamps
   board/tianyi/tyfza1/
   board/youhua/pt1500-h10-ct/
   board/youhua/pt1570-h10-ct/

A board directory contains its Kconfig, Makefile, board initialization,
board-specific device data and environment file, and pulls in the shared
objects from ``board/realtek``. Board DTS files and ``configs/*_defconfig``
files use the same manufacturer and model naming.

Adding a board
--------------

1. Add a product target to the SoC Kconfig when the board uses an existing
   SoC.
2. Add ``board/<vendor>/<model>/Kconfig`` with the board metadata.
3. Add the board Makefile and board-specific sources.
4. Add a board DTS that includes the SoC DTSI.
5. Add a defconfig selecting the product target and default device tree.

Adding a SoC
------------

1. Add a SoC target and source entry below ``arch/arm/mach-realtek``.
2. Add the SoC implementation and its SoC-specific headers.
3. Add a SoC DTSI with only common SoC nodes.
4. Add driver dependencies only for IP blocks shared by the supported SoCs.
5. Add product targets and board directories separately from the SoC code.
