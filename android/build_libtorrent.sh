#!/bin/bash
export ANDROID_NDK=/path/to/ndk
export TOOLCHAIN=$ANDROID_NDK/toolchains/llvm/prebuilt/linux-x86_64

# Для каждого ABI (arm64-v8a, armeabi-v7a, x86_64)
for ABI in arm64-v8a armeabi-v7a x86_64; do
    mkdir -p build/$ABI
    cd build/$ABI
    
    cmake -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN/cmake/android.toolchain.cmake \
          -DANDROID_ABI=$ABI \
          -DANDROID_PLATFORM=android-21 \
          -DBUILD_SHARED_LIBS=ON \
          -DCMAKE_INSTALL_PREFIX=../../install/$ABI \
          ../../libtorrent
    
    make -j$(nproc)
    make install
    cd ../..
done
