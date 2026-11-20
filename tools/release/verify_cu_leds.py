#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Static guard for the CU U-Boot status-lamp board description.

Runs before any compilation, so a bad lamp table can never reach the device:
  * one pin outside GPIO bank 0, or pin 8 (the reset key), makes
    rtl9617c_gpio_group_select()/the failsafe LED runner misbehave;
  * a wrong ORDER makes the boot sweep / IDLE runner / BUSY progress bar run
    across the panel in a scrambled zig-zag. failsafe/led.c walks lamp[0..n]
    strictly by array index, so the array order IS the physical left->right
    order. run #4 only checked the pin SET, not the ORDER, and shipped the
    PT1500 panel order (USB/phone/internet before the GE lamps) on a panel
    whose GE lamps physically sit before phone/internet/USB. The ordered
    PANEL_ORDER assertion below is what prevents that regression.

Usage:
    verify_cu_leds.py <cu-desc-2p5g.c> [upstream-ct-desc-2p5g.c]
"""
import pathlib
import re
import sys

# (pin, active_low) in FRONT-PANEL PHYSICAL ORDER, left -> right.
# Panel (13 positions, user-verified 2026-11-14); non-SoC positions are
# skipped (5G / 2.4G = PCIe WiFi card) or passed over in place (#9 2.5G jack
# lamp, PHY-driven); WPS pin5 is a REAL SoC GPIO lamp and is included since
# 2026-11-19, so the runner stays monotonic on the panel:
#   1 电源 11H  2 注册 9L  3 光信号 10L  [4 5G] [5 2.4G]
#   6 千兆口4 0L  7 千兆口3 1L  8 千兆口2 3L  [9 2.5G口 4L]
#  10 电话 12H  11 宽带 2L  12 WPS 5H  13 USB 7H
PANEL_ORDER = [
    (11, False),   #  1 电源    LED_PWR_G  (active high)
    (9,  True),    #  2 注册    LED_PON    (active low)
    (10, True),    #  3 光信号  LED_LOS    (active low)
    (0,  True),    #  6 千兆口4 LED_EPHY3  (active low)
    (1,  True),    #  7 千兆口3 LED_EPHY2  (active low)
    (3,  True),    #  8 千兆口2 LED_EPHY1  (active low)
    (4,  True),    #  9 2.5G口  LED_EPHY0  (active low, PHY-wired, long dark)
    (12, False),   # 10 电话    LED_FXS    (active high)
    (2,  True),    # 11 宽带    LED_PPP_G  (active low)
    (5,  False),   # 12 WPS     LED_WPS_G  (active high, real SoC GPIO lamp)
    (7,  False),   # 13 USB     LED_USB0   (active high)
]

# pin set / polarity, kept as a set-based double check alongside the order.
EXPECTED = dict(PANEL_ORDER)
RESET_PIN = 8
BANK_PINS = 32
# Pins that must NOT be claimed as failsafe lamps. pin5 is now claimed:
# DTS says LED_WPS_G (gpio0 active high) and the same platform proved on
# PT1570-R10 that buttons are 8/99/103, not pin5.
FORBIDDEN = {6, 8}   # 6 usb1(OS), 8 reset key


def ok(cond, msg):
    if not cond:
        raise SystemExit('ERROR: ' + msg)
    print('  OK   ' + msg)


def parse_lamps(text):
    body = re.search(r'static const struct rtk_led\s+\w+\[\]\s*=\s*\{(.*?)\n\};',
                     text, re.S)
    ok(body is not None, '找到 rtk_led 灯表')
    entries = []
    for line in body.group(1).splitlines():
        line = line.split('/*')[0].strip()
        m = re.search(r'\{\s*\.pin\s*=\s*(\d+)', line)
        if not m:
            continue
        entries.append((int(m.group(1)), '.active_low' in line))
    return entries


def main():
    cu = pathlib.Path(sys.argv[1]).read_text(encoding='utf-8')
    entries = parse_lamps(cu)

    ok(len(entries) == 11, '灯数 = 11（面板 13 位中 11 盏 U-Boot 可驱动灯，含 WPS）')
    pins = [p for p, _ in entries]
    ok(len(set(pins)) == len(pins), '无重复 pin')
    ok(all(p < BANK_PINS for p in pins), '全部 pin < 32（同一 GPIO bank 0）')
    ok(not (set(pins) & FORBIDDEN),
       '未占用 pin 6(usb1)/8(reset)，WPS 使用 pin5 作为真实状态灯')
    ok(dict(entries) == EXPECTED, 'pin/极性集合与面板映射逐项一致')

    # --- 核心：顺序断言（run #4 缺的就是这一条）---
    ok(entries == PANEL_ORDER,
       '灯表严格按面板物理左→右顺序（boot sweep / runner / 进度条不 zig-zag）')
    ok(entries[0] == (11, False), '第一盏是电源(11H)，runner 从面板最左起步')
    ok(entries[-1] == (7, False), '最后一盏是 USB(7H)，runner 收在面板最右')
    idx = {p: i for i, (p, _) in enumerate(entries)}
    ge = [idx[p] for p in (0, 1, 3, 4)]
    rear = [idx[p] for p in (12, 2, 5, 7)]
    ok(max(ge) < min(rear),
       'GE 网口灯(0/1/3/4) 全部排在 电话/宽带/WPS/USB(12/2/5/7) 之前'
       '（run #4 正是反的）')
    ok(ge == sorted(ge) and rear == sorted(rear),
       'GE 段与 电话/宽带/WPS/USB 段内部各自保持面板顺序')
    ok(idx[2] < idx[5] < idx[7],
       '宽带(2) -> WPS(5) -> USB(7) 严格按丝印次序（WPS 不再被跳过）')

    ok('.name = "Youhua PT1570-H10-CU"' in cu, '机型标识为 CU')
    ok('.ports = "2.5GE + 3×GE"' in cu, '恢复页网口描述 = 2.5GE + 3×GE')
    ok(re.search(r'\.reset_pin\s*=\s*8\s*,', cu) is not None, 'reset_pin = 8')
    ok('.reset_active_low = true' in cu, 'reset 低有效')
    ok('ARRAY_SIZE(' in cu and 'nr_lamps' in cu, 'nr_lamps 使用 ARRAY_SIZE')

    if len(sys.argv) > 2:
        ct = pathlib.Path(sys.argv[2]).read_text(encoding='utf-8')
        ok(ct.count('.name = "Youhua PT1570-H10-CT",') == 1,
           '上游 CT desc 名称锚点唯一（覆盖前）')
        ok(re.search(r'\{\s*\.pin\s*=\s*0\s*,', ct) is not None,
           '上游 CT desc 仍是旧的 4GE 映射（可安全整体覆盖）')

    print('CU_LEDS_OK=True lamps=11 PANEL_ORDER=%s (bank 0, reset/usb1 spared, WPS included)'
          % ','.join(str(p) for p in pins))


if __name__ == '__main__':
    if len(sys.argv) < 2:
        raise SystemExit(__doc__)
    main()
