# SPDX-License-Identifier: GPL-3.0-or-later

if(WIN32 OR APPLE)
    set(OPENAL_VERSION "1.24.3")

    FetchContent_Declare(openal
        URL "https://openal-soft.org/openal-releases/openal-soft-${OPENAL_VERSION}.tar.bz2"
        URL_HASH "SHA256=cb5e6197a1c0da0edcf2a81024953cc8fa8545c3b9474e48c852af709d587892"
    )

    FetchContent_MakeAvailable(openal)

    target_link_libraries(${TARGET_NAME} PRIVATE OpenAL::OpenAL)
else()
    find_package(OpenAL REQUIRED)
    target_link_libraries(${TARGET_NAME} PRIVATE OpenAL::OpenAL)
endif()
