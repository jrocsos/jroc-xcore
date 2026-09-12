#!/usr/bin/env bash
set -e

cd /workspaces/jroc-xcore

CFLAGS="-m32 -ffreestanding -fno-pie -fno-stack-protector -fno-builtin \
-nostdlib -nostartfiles -nodefaultlibs"

rm -rf build/mega-check
mkdir -p build/mega-check

COUNT=0

while IFS= read -r src; do
    base="$(echo "$src" | tr '/' '_')"
    obj="build/mega-check/${base%.c}.o"

    gcc $CFLAGS -c "$src" -o "$obj"
    COUNT=$((COUNT + 1))
done < <(
    find xcore storage network security services userspace desktop apps sdk \
         packages ai cloud developer installer diagnostics \
         -type f -name '*.c' | sort
)

echo
echo "=============================================="
echo "       J-ROC MEGA COMPILE CHECK PASSED"
echo "=============================================="
echo "C modules checked: $COUNT"
echo
echo "Working kernel remains protected."
echo "Run 'jroc build' to build the bootable ISO."
