#!/bin/sh
set -ex

WORKPATH=$(cd $(dirname $0); pwd)
echo $WORKPATH

SRC="$WORKPATH/secp256k1"
TEMPSRC="$WORKPATH/secp256k1-temp"

# 删除输出目录
rm -rf "$WORKPATH/build/ios"

# 生成目录
TARGETDIR_IPHONEOS="$WORKPATH/build/ios/iphoneos"
mkdir -p $TARGETDIR_IPHONEOS

TARGETDIR_SIMULATOR_X86_64="$WORKPATH/build/ios/simulator-x86_64"
mkdir -p $TARGETDIR_SIMULATOR_X86_64

TARGETDIR_SIMULATOR_ARM64="$WORKPATH/build/ios/simulator-arm64"
mkdir -p $TARGETDIR_SIMULATOR_ARM64

TARGETDIR_SIMULATOR="$WORKPATH/build/ios/simulator/lib"
mkdir -p $TARGETDIR_SIMULATOR

rm -rf $TEMPSRC
cp -rf $SRC $TEMPSRC
echo "$(pwd)"
(cd $TEMPSRC && ./autogen.sh)
echo "$(pwd)"

# 编译 iphoneos
(cd $TEMPSRC && ./configure --host=arm-apple-darwin CC=`xcrun -find clang` CFLAGS="-O3 -arch arm64 -isysroot `xcrun -sdk iphoneos --show-sdk-path` -fembed-bitcode -mios-version-min=8.0" CXX=`xcrun -find clang++` CXXFLAGS="-O3 -arch arm64 -isysroot `xcrun -sdk iphoneos --show-sdk-path` -fembed-bitcode -mios-version-min=8.0" --prefix=$TARGETDIR_IPHONEOS && make -j20 && make install && make clean)

# 编译 simulator-arm64
(cd $TEMPSRC && ./configure --host=arm-apple-darwin CC=`xcrun -find clang` CFLAGS="-O3 -arch arm64 -isysroot `xcrun -sdk iphonesimulator --show-sdk-path` -fembed-bitcode -mios-simulator-version-min=8.0" CXX=`xcrun -find clang++` CXXFLAGS="-O3 -arch arm64 -isysroot `xcrun -sdk iphonesimulator --show-sdk-path` -fembed-bitcode -mios-simulator-version-min=8.0" --prefix=$TARGETDIR_SIMULATOR_ARM64 && make -j20 && make install && make clean)

# 编译 simulator-x86_64
(cd $TEMPSRC && ./configure --host=x86_64-apple-darwin CC=`xcrun -find clang` CFLAGS="-O3 -arch x86_64 -isysroot `xcrun -sdk iphonesimulator --show-sdk-path` -fembed-bitcode -mios-simulator-version-min=8.0" CXX=`xcrun -find clang++` CXXFLAGS="-O3 -arch x86_64 -isysroot `xcrun -sdk iphonesimulator --show-sdk-path` -fembed-bitcode -mios-simulator-version-min=8.0" --prefix=$TARGETDIR_SIMULATOR_X86_64 && make -j20 && make install && make clean)

# 合成模拟器静态库 arm64 和 x86_64 
xcrun lipo -create "$TARGETDIR_SIMULATOR_X86_64/lib/libsecp256k1.a" \
                   "$TARGETDIR_SIMULATOR_ARM64/lib/libsecp256k1.a" \
                   -o "$TARGETDIR_SIMULATOR/libsecp256k1.a"

# 创建 xcframework
xcodebuild -create-xcframework \
    -library $TARGETDIR_IPHONEOS/lib/libsecp256k1.a \
    -headers $TARGETDIR_IPHONEOS/include \
    -library $TARGETDIR_SIMULATOR/libsecp256k1.a \
    -headers $TARGETDIR_IPHONEOS/include \
    -output $WORKPATH/build/ios/libsecp256k1.xcframework

rm -rf $TARGETDIR_IPHONEOS
rm -rf $TARGETDIR_SIMULATOR_ARM64
rm -rf $TARGETDIR_SIMULATOR_X86_64
TARGETDIR_SIMULATOR="$WORKPATH/build/ios/simulator"
rm -rf $TARGETDIR_SIMULATOR
rm -rf $TEMPSRC

exit 0
