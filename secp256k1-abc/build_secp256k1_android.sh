#!/bin/sh
set -ex

# git clone https://github.com/Bitcoin-ABC/secp256k1.git
# 与 viawallet_core 平行目录放置
SRC='../../secp256k1'
WORKPATH=$(cd $(dirname $0); pwd)
echo $SRC
echo $WORKPATH

# 删除输出目录
rm -rf "$WORKPATH/build"

################################ 编译安卓文件 ################################

# 定义安卓输出目录
ANDROID_DIR=$WORKPATH/build/android
echo $ANDROID_DIR

# 创建安卓输出目录
mkdir -p $ANDROID_DIR

# 定义 HOST TAG
HOST_TAG=darwin-x86_64

TOOLCHAIN=$ANDROID_HOME/ndk/24.0.8215888/toolchains/llvm/prebuilt/$HOST_TAG

ANDROID_ABI=(arm64-v8a armeabi-v7a x86 x86_64)
ANDROID_TARGET=(aarch64-linux-android armv7a-linux-androideabi i686-linux-android x86_64-linux-android)

for i in 0 1 2 3
do
  export CC=$TOOLCHAIN/bin/${ANDROID_TARGET[i]}29-clang
  export CXX=$TOOLCHAIN/bin/${ANDROID_TARGET[i]}29-clang++
  export CFLAGS=-fPIC
  export RANLIB=$TOOLCHAIN/bin/llvm-ranlib
  export AR=$TOOLCHAIN/bin/llvm-ar
  export AS=$TOOLCHAIN/bin/llvm-as
  export LD=$TOOLCHAIN/bin/ld
  export STRIP=$TOOLCHAIN/bin/llvm-strip
  # 每次编译需要一个纯净的源码
  rm -rf "$WORKPATH/secp256k1"
  cp -rf $SRC "$WORKPATH/"
  (cd secp256k1 && ./autogen.sh)
  (cd secp256k1 && ./configure --host ${ANDROID_TARGET[i]} --prefix="$ANDROID_DIR/${ANDROID_ABI[i]}" && make install)
done

export -n CC CXX CFLAGS RANLIB AR AS LD STRIP
export -p

################################ 编译iOS文件 ################################

#TARGETDIR_IPHONEOS="$WORKPATH/.build/iphoneos"
#mkdir -p "$TARGETDIR_IPHONEOS"
#
#TARGETDIR_SIMULATOR="$WORKPATH/.build/iphonesimulator"
#mkdir -p "$TARGETDIR_SIMULATOR"

TARGETDIR_MACOS="$WORKPATH/build/macos"
mkdir -p "$TARGETDIR_MACOS"

rm -rf "$WORKPATH/secp256k1"
cp -rf $SRC "$WORKPATH/"
echo "$(pwd)"
(cd secp256k1 && ./autogen.sh)
echo "$(pwd)"
(cd secp256k1 && ./configure --prefix="$TARGETDIR_MACOS" && make install)
#(cd secp256k1 && ./configure --host=x86_64-apple-darwin CC=`xcrun -find clang` CFLAGS="-O3 -arch x86_64 -isysroot `xcrun -sdk iphonesimulator --show-sdk-path` -fembed-bitcode-marker -mios-simulator-version-min=8.0" CXX=`xcrun -find clang++` CXXFLAGS="-O3 -arch x86_64 -isysroot `xcrun -sdk iphonesimulator --show-sdk-path` -fembed-bitcode-marker -mios-simulator-version-min=8.0" --prefix="$TARGETDIR_SIMULATOR" && make install)
#(cd secp256k1 && ./configure --host=arm-apple-darwin CC=`xcrun -find clang` CFLAGS="-O3 -arch armv7 -arch armv7s -arch arm64 -arch arm64e -isysroot `xcrun -sdk iphoneos --show-sdk-path` -fembed-bitcode -mios-version-min=8.0" CXX=`xcrun -find clang++` CXXFLAGS="-O3 -arch armv7 -arch armv7s -arch arm64 -arch arm64e -isysroot `xcrun -sdk iphoneos --show-sdk-path` -fembed-bitcode -mios-version-min=8.0" --prefix="$TARGETDIR_IPHONEOS" && make install)


#mkdir -p "$WORKPATH/build/ios/lib"
#xcrun lipo -create "$TARGETDIR_IPHONEOS/lib/libsecp256k1.a" \
#                   "$TARGETDIR_SIMULATOR/lib/libsecp256k1.a" \
#                   -o "$WORKPATH/build/ios/lib/libsecp256k1.a"

cp -rf $TARGETDIR_MACOS/include "$WORKPATH/../build/local"
cp -rf $TARGETDIR_MACOS/lib "$WORKPATH/../build/local"

#cp -rf $TARGETDIR_IPHONEOS/include "$WORKPATH/build/ios"

exit 0
