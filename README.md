# RTL9617C U-Boot With Web Failsafe

## Supported Boards

- Tianyi TYFZA1 2.5G
- Tianyi TYFZA1 4GE
- Youhua PT1500-H10-CT 2.5G
- Youhua PT1570-H10-CT 2.5G

## Build Dependencies

On Ubuntu, install the cross compiler and release-tool dependencies:

```sh
sudo apt-get update
sudo apt-get install -y \
    build-essential \
    gcc-aarch64-linux-gnu \
    binutils-aarch64-linux-gnu \
    python3-cryptography \
    python3-pip \
    xz-utils \
    gzip \
    openssl \
    uuid-dev \
    libssl-dev
```

The release tools use the TF-A programs under `tools/release/tf-a/tools/`.
They must contain executable `cert_create` and `fiptool` programs.

## Build U-Boot

Set the cross compiler and build one board:

```sh
export CROSS_COMPILE=aarch64-linux-gnu-
make O=output/tianyi-tyfza1-2p5g tianyi-tyfza1-2p5g_defconfig
make O=output/tianyi-tyfza1-2p5g -j"$(nproc)"
```

Use these defconfig and device-tree combinations:

| Board | Defconfig | Device tree |
| --- | --- | --- |
| Tianyi TYFZA1 2.5G | `tianyi-tyfza1-2p5g_defconfig` | `rtl9617c-tianyi-tyfza1-2p5g` |
| Tianyi TYFZA1 4GE | `tianyi-tyfza1-4ge_defconfig` | `rtl9617c-tianyi-tyfza1-4ge` |
| Youhua PT1500-H10-CT 2.5G | `youhua-pt1500-h10-ct-2p5g_defconfig` | `rtl9617c-youhua-pt1500-h10-ct-2p5g` |
| Youhua PT1570-H10-CT 2.5G | `youhua-pt1570-h10-ct-2p5g_defconfig` | `rtl9617c-youhua-pt1570-h10-ct-2p5g` |

## Build Release Images

Build and verify all supported boards:

```sh
./build.sh all
```

Build one board through the complete release flow:

```sh
./build.sh tianyi-tyfza1-2p5g
```

Run individual stages when the earlier output already exists:

```sh
./build.sh tianyi-tyfza1-2p5g bl33
./build.sh tianyi-tyfza1-2p5g pack
./build.sh tianyi-tyfza1-2p5g verify
```

The generated files are placed under `output/<board>/`:

- `u-boot-dtb.bin`: U-Boot image with the device tree.
- `bl33.bin`: compressed self-decompressing BL33 image.
- `<board>.fip.bin`: rebuilt FIP slot image.
- `<board>.boot.bin`: complete boot partition image.
- `<board>.manifest.json`: payload and output digests.

The release process keeps the stock BL2 and BL31 payloads, replaces BL33,
rebuilds the FIP certificate chain, writes both FIP slots and verifies the
result. See `tools/release/README.md` for the partition map and FIP offsets.

## How to Flash
### Notice
Please backup your parition before uboot flash.

### Flash from migration tool
https://github.com/lyq1996/rtl9617c-migration-tools

### Flash from BL2 XModem
Write the fip image that contains the uboot to slot fip0.  
Then Flash the whole <board>.uboot.bin via uboot in fip0.

0. Power on
1. Continue Press ????? during booting.
2. Enter M
3. Enter F
4. Upload `<board>.fip.bin` via xmodem
5. Wating it auto reboot
6. Goto web failsafe and upload a full `<board>.boot.bin` in Uboot update page.

**Notes**  
In some case, it will auto boot to fip1 rather than fip0, 
so you will need to perfrom a power cycle to boot to fip0.
