# SPDX-License-Identifier: GPL-3.0-or-later

cmake_minimum_required(VERSION 3.24)
project(AstralLife CXX)

set(SRC_DIR "src")
file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cc")
file(GLOB_RECURSE HEADER_FILES "${SRC_DIR}/*.hh")

add_executable(astral-life ${SRC_FILES} ${HEADER_FILES})

include(cmake/common.cmake)
