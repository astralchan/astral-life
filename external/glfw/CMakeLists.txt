# SPDX-License-Identifer: GPL-3.0-or-later

find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(${TARGET_NAME} PRIVATE glfw)
