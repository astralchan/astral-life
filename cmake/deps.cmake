# SPDX-License-Identifier: GPL-3.0-or-later

if(WIN32 OR APPLE)
    include(FetchContent)
endif()

include(cmake/deps/glfw.cmake)
include(cmake/deps/freetype.cmake)
