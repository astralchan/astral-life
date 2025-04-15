# SPDX-License-Identifier: GPL-3.0-or-later

if(WIN32 OR APPLE)
    include(FetchContent)
endif()

file(GLOB DEPS ${CMAKE_CURRENT_LIST_DIR}/deps/*.cmake)
foreach(DEP ${DEPS})
    include(${DEP})
endforeach()
