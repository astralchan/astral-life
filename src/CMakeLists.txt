# SPDX-License-Identifer: GPL-3.0-or-later

add_subdirectory(pch)
add_subdirectory(core)

target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(${TARGET_NAME} PRIVATE
  astral-life.cc
)
