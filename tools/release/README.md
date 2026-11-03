# Boot Release Tools

These tools build the product boot image for the supported Realtek boards.
They are product tooling and are separate from the upstream U-Boot board
support.

## Build

Run the commands from the repository root:

    ./build.sh all
    ./build.sh <board>
    ./build.sh <board> bl33
    ./build.sh <board> pack
    ./build.sh <board> verify

The supported board names are:

    pt1500-h10-2p5g
    tyfza1-2p5g
    tyfza1-4ge

Each board uses its ordinary U-Boot defconfig. There is no separate Web or
plain defconfig. `build_bl33.sh` builds `output/<board>/bl33.bin` from the
selected defconfig, compresses U-Boot with LZMA, and places it in a small
self-decompressing BL33 image.

## BL2, BL31 and BL33

The product boot partition contains a FIP in each of two slots. The release
process does not rebuild BL2 or BL31. It reads both images from the stock boot
partition and keeps them byte-for-byte unchanged.

The stages use the standard TF-A FIP roles:

| FIP role | Stage | Source and handling |
| --- | --- | --- |
| `tb_fw` | BL2 | Extracted from the stock FIP |
| `soc_fw` | BL31 | Extracted from the stock FIP |
| `nt_fw` | BL33 | Replaced with `output/<board>/bl33.bin` |

The assembly is performed as follows:

1. `build_bl33.sh` builds the U-Boot BL33 image.
2. `pack_boot.py` verifies the stock `mtd0` image and parses both FIP copies.
3. The stock BL2 and BL31 payloads are extracted without modification.
4. A new certificate chain is generated for the unchanged BL2/BL31 and the
   replacement BL33.
5. TF-A `fiptool` creates a new FIP containing BL2, BL31, BL33 and the
   generated certificates.
6. The new FIP is written to both slots and padded with `0xff` to the slot
   capacity.
7. The full boot image and the main-slot FIP slice are written to
   `output/<board>/`.

The FIP payload roles are identified by the UUIDs in the board JSON files.
`tb_fw`, `soc_fw` and `nt_fw` correspond to BL2, BL31 and BL33 respectively.
The certificate entries are retained in the same FIP and cover the trusted
world, secure-world and non-secure-world payloads.

## Boot Partition

All three supported boards use a 2 MiB boot partition:

| Region | Start | Size | End | Description |
| --- | ---: | ---: | ---: | --- |
| boot | `0x000000` | `0x200000` | `0x1fffff` | Two FIP slots |
| unused | `0x200000` | `0x080000` | `0x27ffff` | Reserved gap |
| env | `0x280000` | `0x040000` | `0x2bffff` | Primary environment |
| env2 | `0x2c0000` | `0x040000` | `0x2fffff` | Redundant environment |
| static_conf | `0x300000` | `0x040000` | `0x33ffff` | Static configuration |
| ubi_device | `0x340000` | `0x0f5c0000` | `0xf8fffff` | UBI storage |
| unused | `0xf900000` | `0x0700000` | `0xffffff` | Unallocated flash |

The UBI partition starts at `0x340000` and ends at `0xf8fffff`. The remaining
`0x700000` bytes at the end of the 256 MiB flash are not assigned to a named
partition. The partition labels and offsets are defined in the board DTS
files and must match the board layout code.

## FIP Slots

Both slots have a capacity of `0xc0000` bytes:

| Slot | Start in boot partition | End | FIP slice |
| --- | ---: | ---: | --- |
| Slot 0 | `0x040000` | `0x0fffff` | Main slot and generated `.fip.bin` |
| Slot 1 | `0x100000` | `0x1bffff` | Redundant slot |

The remaining area from `0x1c0000` through `0x1fffff` is not part of either
FIP slot.

## FIP Payload Layout

Offsets below are offsets inside each FIP, not offsets from the beginning of
`mtd0`. The values come from the stock images and are preserved when the FIP
is rebuilt.

### PT1500-H10 2.5G

| Payload | Offset | Size |
| --- | ---: | ---: |
| BL2 (`tb_fw`) | `0x01a0` | `0x020680` |
| BL31 (`soc_fw`) | `0x20820` | `0x01e4d8` |
| BL33 (`nt_fw`) | `0x3ecf8` | `0x0704b9` |

Certificate entries begin at `0xaf1b1`. The entry sizes are `0x60e`, `0x4da`,
`0x4ea`, `0x46f`, `0x3e9` and `0x3f9` in FIP order.

### TYFZA1 2.5G and 4GE

Both TYFZA1 variants use the same FIP layout:

| Payload | Offset | Size |
| --- | ---: | ---: |
| BL2 (`tb_fw`) | `0x01a0` | `0x020718` |
| BL31 (`soc_fw`) | `0x208b8` | `0x01e5a0` |
| BL33 (`nt_fw`) | `0x3ee58` | `0x071fa6` |

Certificate entries begin at `0xb0dfe`. The entry sizes are `0x60e`, `0x4da`,
`0x4ea`, `0x46f`, `0x3e9` and `0x3f9` in FIP order.

The BL33 size limits recorded by the board definitions are 459,961 bytes for
PT1500-H10 and 466,854 bytes for both TYFZA1 variants.

## Product Inputs

The board JSON files record the stock image digest, FIP geometry, entry UUIDs,
board identifier and BL33 size limit. The matching stock boot partition is
stored under `tools/release/stocks/<board>/`.

`tools/release/tf-a/` carries only the two TF-A tools the build runs,
`cert_create` and `fiptool`, with their sources and the make helpers they
need; the rest of TF-A is not vendored. Signing keys are generated under
`tools/release/keys/` and must not be committed.

The full boot image is used by the product flashing process. The exact
transport used to write the image is platform-specific and is outside the
U-Boot source tree.
