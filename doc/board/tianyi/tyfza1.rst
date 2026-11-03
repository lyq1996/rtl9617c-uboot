.. SPDX-License-Identifier: GPL-2.0+

Tianyi TYFZA1
=============

The Tianyi TYFZA1 is based on the Realtek RTL9617C SoC. The supported
variants are:

* ``tyfza1-2p5g``: three gigabit Ethernet ports and one 2.5-Gigabit Ethernet
  port.
* ``tyfza1-4ge``: four gigabit Ethernet ports.

Build targets
-------------

.. code-block:: bash

   make tyfza1-2p5g_defconfig
   make tyfza1-4ge_defconfig

The default device trees are:

.. code-block:: none

   rtl9617c-tyfza1-2p5g
   rtl9617c-tyfza1-4ge

Board files
-----------

The board implementation is under ``board/tianyi/tyfza1/``. The board Kconfig
sets the Tianyi vendor and TYFZA1 model metadata. Variant-specific Ethernet
initialization and board descriptions are selected by the product target.

The common SoC nodes are provided by ``arch/arm/dts/rtl9617c.dtsi`` and the
TYFZA1 board nodes by ``arch/arm/dts/rtl9617c-tyfza1.dtsi``. The final DTS
selects the variant model and Ethernet configuration.
