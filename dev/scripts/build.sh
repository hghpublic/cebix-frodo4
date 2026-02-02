#!/bin/sh

clear

git clean -dxf

echo "Building project..."

./autogen.sh > ./dev/logs/autogen.sh.log 2>&1
make > ./dev/logs/make.log 2>&1