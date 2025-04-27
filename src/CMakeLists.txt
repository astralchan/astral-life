# SPDX-License-Identifer: GPL-3.0-or-later

add_subdirectory(core)

target_include_directories(${TARGET_NAME} PRIVATE .)

target_sources(${TARGET_NAME} PRIVATE
  astral-life.cc
)
