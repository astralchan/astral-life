# SPDX-License-Identifier: GPL-3.0-or-later

if(WIN32 OR APPLE)
    set(FREETYPE_VERSION "2.13.3")

    FetchContent_Declare(freetype
        URL "https://download.savannah.gnu.org/releases/freetype/freetype-${FREETYPE_VERSION}.tar.gz"
        URL_HASH "SHA256=5c3a8e78f7b24c20b25b54ee575d6daa40007a5f4eea2845861c3409b3021747"
    )

    FetchContent_MakeAvailable(freetype)

    target_link_libraries(${TARGET_NAME} PRIVATE freetype)
else()
    find_package(Freetype REQUIRED)
    target_link_libraries(${TARGET_NAME} PRIVATE Freetype::Freetype)
endif()
