#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0-only
"""Pack a flashable boot image around a freshly signed BL33.

Board geometry, FIP UUIDs and the stock digest live in boards/<board>.json.
The stock backup pins BL2/BL31 byte for byte; only BL33 is replaced and
the TBBR chain is re-signed with local keys (ROTPK is undeployed on
these units, so the chain only has to be self-consistent).

Everything the packer needs lives inside this repository:
  boards/<board>.json         geometry, UUIDs, budget, stock digest
  stocks/<board>/stock-mtd0.bin
  tf-a/tools/{cert_create,fiptool}
  keys/                       generated on first use, never committed

Outputs output/<board>/:
  <board>.boot.bin       full boot partition, the normal flash path
  <board>.fip.bin        main-slot slice for the BL2 Xmodem 'F' rescue
  <board>.manifest.json  digests of every input and output

Usage:
  pack_boot.py pack   --board B [--bl33 F] [--stock F] [--skip-verify]
  pack_boot.py verify --board B --image F --stock F
"""
import argparse
import base64
import datetime
import hashlib
import json
import os
import struct
import subprocess
from pathlib import Path

from cryptography import x509
from cryptography.hazmat.primitives import serialization

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[1]

KEYS = ("rot-key", "trusted-world-key", "non-trusted-world-key", "scp-fw-key",
        "soc-fw-key", "tos-fw-key", "nt-fw-key")
CERT_ROLES = ("trusted_key_cert", "soc_fw_key_cert", "nt_fw_key_cert",
              "tb_fw_cert", "soc_fw_cert", "nt_fw_cert")
PAYLOAD_ROLES = ("tb_fw", "soc_fw", "nt_fw")

OID_TRUSTED_WORLD_PK = "1.3.6.1.4.1.4128.2100.302"
OID_NON_TRUSTED_WORLD_PK = "1.3.6.1.4.1.4128.2100.303"
OID_SOC_FW_CONTENT_PK = "1.3.6.1.4.1.4128.2100.501"
OID_NT_FW_CONTENT_PK = "1.3.6.1.4.1.4128.2100.1101"
OID_BL2_HASH = "1.3.6.1.4.1.4128.2100.201"
OID_BL31_HASH = "1.3.6.1.4.1.4128.2100.603"
OID_BL33_HASH = "1.3.6.1.4.1.4128.2100.1201"


def log(msg):
    print(msg, flush=True)


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def load_board(boards_dir, name):
    path = boards_dir / f"{name}.json"
    cfg = json.loads(path.read_text())
    lay = cfg.get("layout", {})
    for field in ("boot_size", "fip_slot_offsets", "fip_slot_capacity",
                  "toc_magic_hex", "toc_header_size", "toc_entry_size"):
        if field not in lay:
            raise SystemExit(f"{path}: layout missing {field}")
    if len(lay["fip_slot_offsets"]) != 2:
        raise SystemExit(f"{path}: exactly two FIP slots expected")
    missing = [r for r in (*PAYLOAD_ROLES, *CERT_ROLES)
               if r not in cfg.get("fip_uuids", {})]
    if missing:
        raise SystemExit(f"{path}: fip_uuids missing {missing}")
    return cfg


def uuid_of(raw):
    a, b, c = struct.unpack("<IHH", raw[:8])
    d = raw[8:16]
    return "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x" % (
        a, b, c, d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7])


class Board:
    def __init__(self, cfg):
        self.cfg = cfg
        lay = cfg["layout"]
        self.name = cfg["board"]
        self.boot_size = lay["boot_size"]
        self.fip_offsets = tuple(lay["fip_slot_offsets"])
        self.fip_size = lay["fip_slot_capacity"]
        self.toc_magic = bytes.fromhex(lay["toc_magic_hex"])
        self.toc_header_size = lay["toc_header_size"]
        self.toc_entry_size = lay["toc_entry_size"]
        self.uuid_map = {u: r for r, u in cfg["fip_uuids"].items()}
        self.bl33_budget = cfg["bl33_budget"]

    def parse_fip(self, slot):
        if slot[:4] != self.toc_magic[:4]:
            raise SystemExit("FIP ToC magic missing")
        entries = {}
        cursor = self.toc_header_size
        while cursor < 0x400:
            raw = slot[cursor:cursor + self.toc_entry_size]
            if raw[:16] == bytes(16):
                break
            name = self.uuid_map.get(uuid_of(raw[:16]), uuid_of(raw[:16]))
            entries[name] = struct.unpack_from("<QQ", raw, 16)
            cursor += self.toc_entry_size
        return entries


class Image:
    def __init__(self, board, data):
        self.data = data
        slot0 = board.fip_offsets[0]
        self.entries = board.parse_fip(data[slot0:slot0 + board.fip_size])

    def payload(self, board, role):
        off, size = self.entries[role]
        return self.data[board.fip_offsets[0] + off:board.fip_offsets[0] + off + size]

    def cert(self, board, role):
        off, size = self.entries[role]
        return x509.load_der_x509_certificate(
            self.data[board.fip_offsets[0] + off:board.fip_offsets[0] + off + size])


def ensure_tools(tools_dir):
    for tool in ("cert_create/cert_create", "fiptool/fiptool"):
        path = tools_dir / tool
        if not path.exists():
            sub = tools_dir / tool.split("/")[0]
            log(f"==> building TF-A tool in {sub}")
            subprocess.run(["make", "-C", str(sub)], check=True,
                           stdout=subprocess.DEVNULL)
        if not path.exists():
            raise SystemExit(f"{path} still missing after make")


def ensure_keys(key_dir):
    key_dir.mkdir(parents=True, exist_ok=True, mode=0o700)
    for name in KEYS:
        path = key_dir / (name + ".pem")
        if not path.exists():
            subprocess.run(["openssl", "genrsa", "-out", str(path), "2048"],
                           check=True, stdout=subprocess.DEVNULL)
            os.chmod(path, 0o600)


# ---------------------------------------------------------------- verify --

def spki_ext(value, oid):
    for extension in value.extensions:
        if extension.oid.dotted_string == oid:
            b64 = base64.encodebytes(extension.value.value).decode()
            pem = "-----BEGIN PUBLIC KEY-----\n" + b64 + "-----END PUBLIC KEY-----\n"
            return serialization.load_pem_public_key(pem.encode())
    return None


def digest_ext(value, oid):
    # The hash extensions wrap a full sha256 DigestInfo: SEQUENCE over
    # the AlgorithmIdentifier and a 32-byte OCTET STRING, 51 bytes total.
    for extension in value.extensions:
        if extension.oid.dotted_string != oid:
            continue
        raw = getattr(extension.value, "value", None)
        if isinstance(raw, bytes) and len(raw) >= 34:
            return raw[-32:]
    return None


def check_sig(child, parent_key, label):
    try:
        parent_key.verify(child.signature, child.tbs_certificate_bytes,
                          child.signature_algorithm_parameters,
                          child.signature_hash_algorithm)
        print("  PASS  " + label)
    except Exception as error:
        raise SystemExit("  FAIL  %s: %r" % (label, error))


def report(ok, label):
    print("  %s  %s" % ("PASS" if ok else "FAIL", label))
    if not ok:
        raise SystemExit(1)


def run_verify(board, image_path, stock_path):
    image = Image(board, image_path.read_bytes())
    stock = Image(board, stock_path.read_bytes())
    slot0, slot1 = board.fip_offsets
    tail_start = max(board.fip_offsets) + board.fip_size

    print("== layout ==")
    report(image.data[:slot0] == stock.data[:slot0],
           f"GPT area 0x0-0x{slot0:x} identical to stock")
    report(image.data[tail_start:] == stock.data[tail_start:],
           f"reserved tail 0x{tail_start:x}-0x{len(image.data):x} identical to stock")
    report(board.parse_fip(image.data[slot1:slot1 + board.fip_size]) == image.entries,
           "both FIP slots carry the same ToC")

    print("== payloads pinned to stock ==")
    report(image.payload(board, "tb_fw") == stock.payload(board, "tb_fw"),
           "BL2 byte-identical to stock")
    report(image.payload(board, "soc_fw") == stock.payload(board, "soc_fw"),
           "BL31 byte-identical to stock")

    print("== certificate chain ==")
    tkey = image.cert(board, "trusted_key_cert")
    check_sig(tkey, tkey.public_key(), "trusted key cert self-signature (ROTPK undeployed skips it)")
    check_sig(image.cert(board, "tb_fw_cert"), tkey.public_key(),
              "tb fw cert <- trusted key cert subject key")
    check_sig(image.cert(board, "soc_fw_key_cert"), spki_ext(tkey, OID_TRUSTED_WORLD_PK),
              "soc fw key cert <- trusted world key")
    check_sig(image.cert(board, "nt_fw_key_cert"), spki_ext(tkey, OID_NON_TRUSTED_WORLD_PK),
              "nt fw key cert <- non-trusted world key")
    check_sig(image.cert(board, "soc_fw_cert"),
              spki_ext(image.cert(board, "soc_fw_key_cert"), OID_SOC_FW_CONTENT_PK),
              "soc fw content cert <- soc fw key cert key")
    check_sig(image.cert(board, "nt_fw_cert"),
              spki_ext(image.cert(board, "nt_fw_key_cert"), OID_NT_FW_CONTENT_PK),
              "nt fw content cert <- nt fw key cert key")

    print("== content hashes ==")
    report(digest_ext(image.cert(board, "tb_fw_cert"), OID_BL2_HASH)
           == hashlib.sha256(image.payload(board, "tb_fw")).digest(),
           "tb fw content cert hash == BL2 sha256")
    report(digest_ext(image.cert(board, "soc_fw_cert"), OID_BL31_HASH)
           == hashlib.sha256(image.payload(board, "soc_fw")).digest(),
           "soc fw content cert hash == BL31 sha256")
    report(digest_ext(image.cert(board, "nt_fw_cert"), OID_BL33_HASH)
           == hashlib.sha256(image.payload(board, "nt_fw")).digest(),
           "nt fw content cert hash == BL33 sha256")

    print("== stock baseline sanity ==")
    stock_tkey = stock.cert(board, "trusted_key_cert")
    check_sig(stock.cert(board, "tb_fw_cert"), stock_tkey.public_key(),
              "stock tb fw cert <- stock trusted key cert key")
    report(digest_ext(stock.cert(board, "tb_fw_cert"), OID_BL2_HASH)
           == hashlib.sha256(stock.payload(board, "tb_fw")).digest(),
           "stock tb fw hash == stock BL2")
    report(digest_ext(stock.cert(board, "soc_fw_cert"), OID_BL31_HASH)
           == hashlib.sha256(stock.payload(board, "soc_fw")).digest(),
           "stock soc fw hash == stock BL31")
    report(digest_ext(stock.cert(board, "nt_fw_cert"), OID_BL33_HASH)
           == hashlib.sha256(stock.payload(board, "nt_fw")).digest(),
           "stock nt fw hash == stock BL33 (proves this is the BL33 gate)")

    print("== extension OID sets match the stock profile ==")
    for role in CERT_ROLES:
        new_oids = sorted(e.oid.dotted_string for e in image.cert(board, role).extensions)
        old_oids = sorted(e.oid.dotted_string for e in stock.cert(board, role).extensions)
        report(new_oids == old_oids, role + (" " + str(new_oids) if new_oids != old_oids else ""))

    print("ALL CHECKS PASSED")


# ------------------------------------------------------------------ pack --

def cmd_pack(args):
    board = Board(load_board(HERE / "boards", args.board))
    name = board.name

    stock_path = args.stock or (HERE / "stocks" / name / "stock-mtd0.bin")
    stock = stock_path.read_bytes()
    if len(stock) != board.boot_size:
        raise SystemExit(f"stock backup must be {board.boot_size} bytes, got {len(stock)}")
    stock_digest = sha256(stock)
    if stock_digest != board.cfg["stock_sha256"]:
        if not args.force_stock:
            raise SystemExit(
                f"stock sha256 {stock_digest} does not match boards/{name}.json "
                f"({board.cfg['stock_sha256']}); pass --force-stock to override")
        log("WARNING: stock digest mismatch accepted (--force-stock)")

    bl33_path = args.bl33 or (REPO / "output" / name / "bl33.bin")
    if not bl33_path.exists():
        raise SystemExit(f"BL33 not found at {bl33_path}; run ./build.sh {name} bl33 first")
    bl33 = bl33_path.read_bytes()

    slot0, slot1 = board.fip_offsets
    first = board.parse_fip(stock[slot0:slot0 + board.fip_size])
    second = board.parse_fip(stock[slot1:slot1 + board.fip_size])
    if first != second:
        raise SystemExit("the two stock FIP copies disagree")
    for role in PAYLOAD_ROLES:
        if role not in first:
            raise SystemExit(f"stock FIP lacks a {role} entry")
    bl2_off, bl2_size = first["tb_fw"]
    bl31_off, bl31_size = first["soc_fw"]
    bl33_off, bl33_size = first["nt_fw"]
    if len(bl33) + bl2_size + bl31_size + 6 * 1024 > board.fip_size:
        raise SystemExit(f"replacement payloads cannot fit a {board.fip_size}-byte FIP slot")
    if len(bl33) > board.bl33_budget:
        log(f"WARNING: bl33 is {len(bl33)} B, board budget is {board.bl33_budget} B")
    stock_bl33 = stock[slot0 + bl33_off:slot0 + bl33_off + bl33_size]
    if stock_bl33 == bl33:
        raise SystemExit("the replacement BL33 equals the stock one; nothing to do")
    log(f"stock BL2 {bl2_size} B, BL31 {bl31_size} B, BL33 {bl33_size} B -> "
        f"replacement {len(bl33)} B")

    work = args.out_root / name
    work.mkdir(parents=True, exist_ok=True)
    (work / "bl2.bin").write_bytes(stock[slot0 + bl2_off:slot0 + bl2_off + bl2_size])
    (work / "bl31.bin").write_bytes(stock[slot0 + bl31_off:slot0 + bl31_off + bl31_size])
    (work / "bl33.bin").write_bytes(bl33)

    ensure_tools(args.tfa_tools)
    ensure_keys(args.keys)
    key_args = []
    for key in KEYS:
        key_args += ["--" + key, str(args.keys / (key + ".pem"))]
    cert_args = []
    for role in CERT_ROLES:
        cert_args += ["--" + role.replace("_", "-"), str(work / (role.replace("_", "-") + ".der"))]

    subprocess.run([str(args.tfa_tools / "cert_create" / "cert_create"),
                    "--key-alg", "rsa", "--key-size", "2048", "--hash-alg", "sha256",
                    "--tfw-nvctr", "0", "--ntfw-nvctr", "0",
                    "--tb-fw", str(work / "bl2.bin"),
                    "--soc-fw", str(work / "bl31.bin"),
                    "--nt-fw", str(work / "bl33.bin"),
                    *key_args, *cert_args], check=True, stdout=subprocess.DEVNULL)

    fip = work / "rtl9617c.fip"
    subprocess.run([str(args.tfa_tools / "fiptool" / "fiptool"), "create",
                    "--tb-fw", str(work / "bl2.bin"),
                    "--soc-fw", str(work / "bl31.bin"),
                    "--nt-fw", str(work / "bl33.bin"),
                    *cert_args, str(fip)], check=True, stdout=subprocess.DEVNULL)
    packed = fip.read_bytes()
    if len(packed) > board.fip_size:
        raise SystemExit(f"FIP {len(packed)} exceeds slot capacity {board.fip_size}")

    new_entries = board.parse_fip(packed)
    if new_entries.get("tb_fw") != (bl2_off, bl2_size) or \
       new_entries.get("soc_fw") != (bl31_off, bl31_size):
        raise SystemExit("rebuilt FIP lost the stock BL2/BL31 placement")
    n_off, n_size = new_entries["nt_fw"]
    if packed[n_off:n_off + n_size] != bl33:
        raise SystemExit("rebuilt FIP BL33 payload mismatch")

    image = bytearray(stock)
    for start in board.fip_offsets:
        image[start:start + board.fip_size] = packed + b"\xff" * (board.fip_size - len(packed))
    image = bytes(image)
    for start in board.fip_offsets:
        if board.parse_fip(image[start:start + board.fip_size]) != new_entries:
            raise SystemExit(f"slot at 0x{start:x} does not verify after assembly")

    boot_out = work / f"{name}.boot.bin"
    fip_out = work / f"{name}.fip.bin"
    boot_out.write_bytes(image)
    slice_ = image[slot0:slot0 + board.fip_size]
    if slice_[:len(packed)] != packed:
        raise SystemExit("main-slot slice does not match the packed FIP")
    fip_out.write_bytes(slice_)

    manifest = {
        "board": name,
        "board_id": board.cfg.get("board_id"),
        "created_utc": datetime.datetime.now(datetime.timezone.utc).isoformat(timespec="seconds"),
        "stock": {"file": str(stock_path), "sha256": stock_digest},
        "bl33": {"file": str(bl33_path), "size": len(bl33), "sha256": sha256(bl33),
                 "budget": board.bl33_budget},
        "payloads": {"bl2": sha256((work / "bl2.bin").read_bytes()),
                     "bl31": sha256((work / "bl31.bin").read_bytes()),
                     "bl33": sha256(bl33)},
        "certificates": {role: sha256((work / (role.replace("_", "-") + ".der")).read_bytes())
                         for role in CERT_ROLES},
        "outputs": {"boot": {"file": str(boot_out), "sha256": sha256(image)},
                    "fip": {"file": str(fip_out), "sha256": sha256(slice_),
                            "note": f"image[0x{slot0:x}:0x{slot0 + board.fip_size:x}]"}},
    }
    (work / f"{name}.manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")

    log(f"boot image: {boot_out} ({len(image)} bytes)")
    log(f"  sha256 {sha256(image)}")
    log(f"fip slice: {fip_out} ({len(slice_)} bytes)")
    log(f"  sha256 {sha256(slice_)}")

    if not args.skip_verify:
        log("== verifying the rebuilt chain ==")
        run_verify(board, boot_out, stock_path)


def cmd_verify(args):
    board = Board(load_board(HERE / "boards", args.board))
    if len(args.image.read_bytes()) != board.boot_size:
        raise SystemExit(f"image must be {board.boot_size} bytes")
    run_verify(board, args.image, args.stock)


def main():
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    sub = parser.add_subparsers(dest="cmd", required=True)

    p_pack = sub.add_parser("pack", help="build the signed boot image and rescue slice")
    p_pack.add_argument("--board", required=True)
    p_pack.add_argument("--bl33", type=Path,
                        help="BL33 stub; default output/<board>/bl33.bin")
    p_pack.add_argument("--stock", type=Path,
                        help="stock mtd0 backup; default stocks/<board>/stock-mtd0.bin")
    p_pack.add_argument("--out-root", type=Path, default=REPO / "output")
    p_pack.add_argument("--keys", type=Path, default=HERE / "keys")
    p_pack.add_argument("--tfa-tools", type=Path, default=HERE / "tf-a" / "tools")
    p_pack.add_argument("--skip-verify", action="store_true")
    p_pack.add_argument("--force-stock", action="store_true",
                        help="accept a stock digest that differs from the board record")
    p_pack.set_defaults(func=cmd_pack)

    p_verify = sub.add_parser("verify", help="verify an existing image against its stock")
    p_verify.add_argument("--board", required=True)
    p_verify.add_argument("--image", required=True, type=Path)
    p_verify.add_argument("--stock", required=True, type=Path)
    p_verify.set_defaults(func=cmd_verify)

    args = parser.parse_args()
    args.func(args)


if __name__ == "__main__":
    main()
