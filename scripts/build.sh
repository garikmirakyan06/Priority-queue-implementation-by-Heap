#!/bin/bash

TOTAL_CORES=$(nproc)
CORES_34=$(( (TOTAL_CORES * 3) / 4 ))

cd ./app

rm -rf bin
rm -rf build
mkdir build 
cd build
cmake ..
make -j "$CORES_34"


