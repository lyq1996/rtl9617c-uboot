.. SPDX-License-Identifier: GPL-2.0+

Flash Partitions
================

Flash partitions are described by the board device tree using the standard
``fixed-partitions`` binding. A board DTS should describe only the regions
that are owned by U-Boot or required by the board boot flow.

Partition labels are part of the board interface. The environment settings,
boot commands and recovery or update code must use the same labels and
boundaries as the device tree.

The partition layout is board-specific. Do not copy offsets from another
board unless the flash device, erase geometry and firmware layout are the
same. Changes to a partition boundary can invalidate existing environment or
firmware data and must be coordinated with the platform image format.

The SoC DTSI provides the storage controller node. The board DTS adds the
partition table and any board-specific flash nodes.
