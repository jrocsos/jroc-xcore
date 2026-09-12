#!/usr/bin/env bash
set -e

cd /workspaces/jroc-xcore

echo "J-Roc XCore System Check"
echo

test -f boot/entry.asm
echo "BOOT: OK"

test -f kernel/kernel.c
echo "KERNEL: OK"

test -f config/linker.ld
echo "LINKER: OK"

test -f config/grub/grub.cfg
echo "GRUB: OK"

test -d xcore
echo "XCORE: OK"

test -d storage
echo "STORAGE: OK"

test -d network
echo "NETWORK: OK"

test -d security
echo "SECURITY: OK"

test -d userspace
echo "USERSPACE: OK"

test -d desktop
echo "DESKTOP: OK"

test -d sdk
echo "SDK: OK"

test -d apps
echo "APPS: OK"

test -d frontend
echo "FRONTEND: OK"

test -d backend
echo "BACKEND: OK"

echo

if [ -f build/jroc.iso ]; then
    echo "ISO: OK"
    ls -lh build/jroc.iso
else
    echo "ISO: NOT BUILT"
fi

echo
echo "SYSTEM CHECK PASSED"
