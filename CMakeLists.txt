# SPDX-License-Identifier: GPL-3.0-or-later

cmake_minimum_required(VERSION 3.24)
project(AstralLife CXX)

set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cc")
file(GLOB_RECURSE HEADER_FILES "${SRC_DIR}/*.hh")

set(TARGET_NAME "astral-life")
add_executable(${TARGET_NAME} ${SRC_FILES} ${HEADER_FILES})

include(${CMAKE_CURRENT_LIST_DIR}/cmake/common.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/cmake/deps.cmake)
