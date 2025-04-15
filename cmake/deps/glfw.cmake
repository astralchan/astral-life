# SPDX-License-Identifier: GPL-3.0-or-later

if(WIN32 OR APPLE)
    set(GLFW_VERSION "3.4")

    FetchContent_Declare(glfw
        URL "https://github.com/glfw/glfw/releases/download/${GLFW_VERSION}/glfw-${GLFW_VERSION}.zip"
        URL_HASH "SHA256=b5ec004b2712fd08e8861dc271428f048775200a2df719ccf575143ba749a3e9"
    )

    FetchContent_MakeAvailable(glfw)

    target_link_libraries(${TARGET_NAME} PRIVATE glfw)
else()
    find_package(glfw3 REQUIRED)
    target_link_libraries(${TARGET_NAME} PRIVATE glfw)
endif()
