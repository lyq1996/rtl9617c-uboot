.. SPDX-License-Identifier: GPL-2.0+

Boot Flow
=========

The Realtek boards use the standard U-Boot boot flow. Earlier firmware stages
perform the platform-specific low-level initialization and transfer control to
U-Boot. U-Boot initializes the device model, exposes the devices described by
the board device tree, and executes the configured boot command.

The board device tree must describe the UART, storage, Ethernet, GPIO and
reserved-memory regions that are visible to U-Boot. Board-specific nodes and
aliases belong in the board DTS; SoC nodes belong in the SoC DTSI.

The U-Boot image may be loaded by a preceding firmware stage or from the
platform boot medium. The load address, memory reservations and hand-off
interfaces must match the preceding stage and the board device tree.

For boards with multiple firmware stages, the platform integration is
responsible for packaging those stages. This packaging is outside the U-Boot
board implementation.
