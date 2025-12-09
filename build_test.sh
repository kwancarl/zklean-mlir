#!/bin/sh

BUILD_SYSTEM="Ninja"
BUILD_DIR=./build-`echo ${BUILD_SYSTEM}| tr '[:upper:]' '[:lower:]'`

rm -rf $BUILD_DIR
mkdir $BUILD_DIR
pushd $BUILD_DIR

LLVM_BUILD_DIR=externals/llvm-project/build
cmake -G $BUILD_SYSTEM .. \
    -DLLVM_DIR="$LLVM_BUILD_DIR/lib/cmake/llvm" \
    -DMLIR_DIR="$LLVM_BUILD_DIR/lib/cmake/mlir" \
    -DBUILD_SHARED_LIBS="OFF" \
    -DBUILD_DEPS="ON" \
    -DCMAKE_BUILD_TYPE=Debug

popd

cmake --build $BUILD_DIR --target zklean-opt
cmake --build $BUILD_DIR --target check-zklean-opt
# TODO: Currently check-mlir-tutorial acts as a sanity check but a bit
# redundent, remove check-mlir-tutorial later
cmake --build $BUILD_DIR --target check-mlir-tutorial
