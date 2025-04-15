# SPDX-License-Identifier: GPL-3.0-or-later

target_compile_features(${TARGET_NAME} PRIVATE cxx_std_17)
if(MSVC)
    target_compile_options(${TARGET_NAME} PRIVATE
        /W4 /permissive- /WX
    )
else()
    target_compile_options(${TARGET_NAME} PRIVATE
        -Wall -Wextra -Wpedantic -Werror
    )
endif()
