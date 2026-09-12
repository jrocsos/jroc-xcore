#!/usr/bin/env bash
set -e

cd /workspaces/jroc-xcore

echo "J-Roc 1.0 Release Check"
echo

test -f release/1.0/release_id.txt
test -f release/1.0/version.txt
test -f release/manifest/JROC-1.0-MANIFEST.md
test -f diagnostics/1.0/system_check.sh
test -f recovery/1.0/recovery.conf
test -f docs/STAGE-30.md

echo "Release metadata: OK"
echo "Diagnostics: OK"
echo "Recovery metadata: OK"
echo "Documentation: OK"

echo
echo "RELEASE CHECK PASSED"
