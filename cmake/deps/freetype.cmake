# SPDX-License-Identifier: GPL-3.0-or-later

if(WIN32 OR APPLE)
    set(FREETYPE_VERSION "2-13-3")

    FetchContent_Declare(freetype
        URL "https://gitlab.freedesktop.org/freetype/freetype/-/archive/VER-${FREETYPE_VERSION}/freetype-VER-${FREETYPE_VERSION}.zip"
        URL_HASH "SHA256=6b40af9ea284135d6a5c905340d43b5003c799810b5804ffa8a2cf91ebe2cff5"
    )

    FetchContent_MakeAvailable(freetype)
else()
    find_package(Freetype REQUIRED)
endif()
