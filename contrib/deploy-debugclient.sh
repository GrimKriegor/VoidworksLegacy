#!/bin/bash
set -e

SOURCE="examples/debugclient"
DESTINATION="/run/user/1000/gvfs/smb-share:server=console.lan,share=games/Development"

cores="$(cat /proc/cpuinfo | awk '/^processor/{print $3}' | wc -l)"
mkdir -p "$SOURCE/build/"
cd "$SOURCE/build"
cmake \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_CXX_COMPILER=/usr/bin/x86_64-w64-mingw32-g++ \
  ..
time make -j"$cores"
yes | cp -f "voidworks-debugclient.dll" "$DESTINATION/voidworks.dll"
