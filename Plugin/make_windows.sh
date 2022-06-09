#!/bin/bash

proj=$(pwd)
rm -rf build_windows

mkdir -p build_windows/32 && cd build_windows/32
cmake -DTARGET_PLATFORM=Windows -G "Visual Studio 16 2019" $proj
cd -

mkdir -p build_windows/64 && cd build_windows/64
cmake -DTARGET_PLATFORM=Windows -G "Visual Studio 16 2019" $proj -A x64
cd -

cmake --build build_windows/32 --config Release

# cmake --build build_windows/64 --target clean

cmake --build build_windows/64 --config Release