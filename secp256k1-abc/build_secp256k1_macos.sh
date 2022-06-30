#!/bin/sh
set -ex

WORKPATH=$(cd $(dirname $0); pwd)
echo $WORKPATH

# 定义目录
SRC="$WORKPATH/secp256k1"
TEMPSRC="$WORKPATH/secp256k1-temp"
TARGETDIR_MACOS="$WORKPATH/build/macos"

# 重新创建输出目录
rm -rf "$TARGETDIR_MACOS"
mkdir -p "$TARGETDIR_MACOS"

# 复制源码
rm -rf $TEMPSRC
cp -rf $SRC $TEMPSRC
echo "$(pwd)"
(cd $TEMPSRC && ./autogen.sh)
echo "$(pwd)"
AABB="$(date)"
(cd $TEMPSRC && ./configure --prefix="$TARGETDIR_MACOS" && make -j20 && make install)
echo $AABB "$(date)"

# cp -rfv $TARGETDIR_MACOS/include "$WORKPATH/../build/local"
# cp -rfv $TARGETDIR_MACOS/lib "$WORKPATH/../build/local"
rm -rf $TEMPSRC

exit 0
