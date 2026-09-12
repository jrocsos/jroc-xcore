#!/usr/bin/env bash
set -e

required_dirs=(
    kernel
    memory
    network
    security
    services
    userspace
    desktop
    frontend
    apps
    sdk
    integration
    release
)

for dir in "${required_dirs[@]}"
do
    if [ ! -d "$dir" ]; then
        echo "MISSING DIRECTORY: $dir"
        exit 1
    fi

    echo "OK DIRECTORY: $dir"
done

required_files=(
    integration/init/system_init.c
    integration/status/system_status.c
    release/release.conf
    release/manifest/release.manifest
)

for file in "${required_files[@]}"
do
    if [ ! -f "$file" ]; then
        echo "MISSING FILE: $file"
        exit 1
    fi

    echo "OK FILE: $file"
done

echo "TREE CHECK PASSED"
