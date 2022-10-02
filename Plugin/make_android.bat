@echo off

set proj=%cd%
rd build_android /s /q

md build_android\armeabi & pushd build_android\armeabi
cmake -DTARGET_PLATFORM=Android -DCMAKE_BUILD_TYPE=Release -DANDROID_ABI="armeabi-v7a" %proj%
popd

md build_android\arm64 & pushd build_android\arm64
cmake -DTARGET_PLATFORM=Android -DCMAKE_BUILD_TYPE=Release -DANDROID_ABI="arm64-v8a" %proj%
popd

md build_android\x86 & pushd build_android\x86
cmake -DTARGET_PLATFORM=Android -DCMAKE_BUILD_TYPE=Release -DANDROID_ABI="x86" %proj%
popd

cmake --build build_windows\armeabi --config Release
cmake --build build_windows\arm64 --config Release
cmake --build build_windows\x86 --config Release