#!/usr/bin/env python3
"""Pack the recovery page into the complete HTTP response the board serves.

usage: pack-page.py page.html page.bin
"""
import gzip
import pathlib
import sys

src, dst = map(pathlib.Path, sys.argv[1:3])
body = gzip.compress(src.read_bytes(), 9, mtime=0)
head = ("HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html; charset=utf-8\r\n"
        "Content-Encoding: gzip\r\n"
        "Cache-Control: no-store\r\n"
        "Connection: close\r\n"
        "Content-Length: %d\r\n\r\n" % len(body))
dst.write_bytes(head.encode("ascii") + body)
