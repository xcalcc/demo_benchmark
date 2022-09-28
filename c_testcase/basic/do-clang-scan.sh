#!/bin/sh

rm -rf clang-scan-build.log clang-scan-result
make clean

scan-build -o clang-scan-result make 2>&1 | tee clang-scan-build.log

scan_view_cmd=`tail -n 1 clang-scan-build.log | awk -F\' '{print $2}'`
$scan_view_cmd


