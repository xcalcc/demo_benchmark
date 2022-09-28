#!/bin/sh

rm -rf xvsa-scan-build.log xcal_basic

make clean

xcalmake -o xcal_basic make 2>&1 | tee xvsa-scan-build.log

