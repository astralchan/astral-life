#!/bin/sh

# SPDX-License-Identifier: GPL-3.0-or-later

TOOLCHAIN_FILE=
for arg; do
  case "$arg" in
    --debug) BUILD_TYPE=Debug ;;
    --release) BUILD_TYPE=Release ;;
    --vcpkg) TOOLCHAIN_FILE="${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" ;;
    *)
      printf >&2 "Error: Unknown argument %s\n" "$arg"
      printf >&2 "Usage: %s [--debug | --release] [--vcpkg]\n" "$0"
      exit 1
      ;;
  esac
done

: "${BUILD_TYPE=Release}"

CMAKE_CMD="cmake -B build -DCMAKE_BUILD_TYPE=$BUILD_TYPE"
if [ "$TOOLCHAIN_FILE" ]; then
  CMAKE_CMD="$CMAKE_CMD -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN_FILE"
fi

CMAKE_BUILD_CMD="cmake --build build --config $BUILD_TYPE"

case "$(uname)" in
  Darwin | *BSD)
    CMAKE_BUILD_CMD="$CMAKE_BUILD_CMD --parallel $(sysctl -n hw.ncpu)"
    ;;
  Linux)
    CMAKE_BUILD_CMD="$CMAKE_BUILD_CMD --parallel $(nproc --all)"
    ;;
esac

$CMAKE_CMD
$CMAKE_BUILD_CMD

exit 0
