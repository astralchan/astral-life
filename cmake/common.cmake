# SPDX-License-Identifier: GPL-3.0-or-later

if(MSVC)
    target_compile_options(astral-life PRIVATE
        /W4 /permissive- /WX
    )
else()
    target_compile_options(astral-life PRIVATE
        -Wall -Wextra -Wpedantic -Werror
    )
endif()

if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(astral-life PRIVATE NDEBUG)
endif()

include(cmake/deps.cmake)

if(WIN32 OR APPLE)
target_link_libraries(astral-life PRIVATE
    glfw
    freetype
)
else()
target_link_libraries(astral-life PRIVATE
    glfw
    Freetype::Freetype
)
endif()

file(COPY res DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
