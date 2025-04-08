#!/bin/sh

# SPDX-License-Identifier: GPL-3.0-or-later

for arg; do
    case "$arg" in
        --debug) BUILD_TYPE="Debug" ;;
        --release) BUILD_TYPE="Release" ;;
        *)
            printf "Error: Unknown argument %s\n" "$arg"
            printf "Usage: %s [--debug | --release]\n" "$0"
            exit 1
    esac
done

: "${BUILD_TYPE:=Release}"

cmake -B build -DCMAKE_BUILD_TYPE=$BUILD_TYPE
cmake --build build --config $BUILD_TYPE --parallel $(nproc --all)
