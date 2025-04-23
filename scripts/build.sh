#!/bin/bash

TOTAL_CORES=$(nproc)
CORES_34=$(( (TOTAL_CORES * 3) / 4 ))
ROOT_DIR=$(dirname "$(dirname "$(realpath "$0")")")

cd "$ROOT_DIR" || exit

rm -rf bin
rm -rf build
mkdir build 
cd build || exit
cmake ..
make -j "$CORES_34"


