#!/bin/bash

proj=$(pwd)
rm -rf build_android

mkdir -p build_android/armeabi && cd build_android/armeabi
cmake -DTARGET_PLATFORM=Android -DCMAKE_BUILD_TYPE=Release -DANDROID_ABI="armeabi-v7a" $proj
cd -

mkdir -p build_android/arm64 && cd build_android/arm64
cmake -DTARGET_PLATFORM=Android -DCMAKE_BUILD_TYPE=Release -DANDROID_ABI="arm64-v8a" $proj
cd -

mkdir -p build_android/x86 && cd build_android/x86
cmake -DTARGET_PLATFORM=Android -DCMAKE_BUILD_TYPE=Release -DANDROID_ABI="x86" $proj
cd -

cmake --build build_android/armeabi --config Release -- -j
cmake --build build_android/arm64 --config Release -- -j
cmake --build build_android/x86 --config Release -- -j