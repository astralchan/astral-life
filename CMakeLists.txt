# SPDX-License-Identifer: GPL-3.0-or-later

cmake_minimum_required(VERSION 3.24)
project(AstralLife
  VERSION 0.0.0
  LANGUAGES CXX
)

set(TARGET_NAME astral-life)
add_executable(${TARGET_NAME})

target_compile_features(${TARGET_NAME} PRIVATE cxx_std_20)

if(MSVC)
  target_compile_options(${TARGET_NAME} PRIVATE
    /W4 /permissive- /WX
  )
else()
  target_compile_options(${TARGET_NAME} PRIVATE
    -Wall -Wextra -Wpedantic -Werror
  )
endif()

add_subdirectory(external)
add_subdirectory(src)
