@echo off

:: SPDX-License-Identifier: GPL-3.0-or-later

for %%A in (%*) do (
    if "%%A"=="--debug" (
        set BUILD_TYPE=Debug
    ) else if "%%A"=="--release" (
        set BUILD_TYPE=Release
    ) else (
        echo Error: Unknown argument %%A
        echo Usage: %0 [--debug | --release]
        exit /b 1
    )
)

if not defined BUILD_TYPE set BUILD_TYPE=Release

cmake -B build -DCMAKE_BUILD_TYPE=%BUILD_TYPE%
cmake --build build --config %BUILD_TYPE% --parallel %NUMBER_OF_PROCESSORS%
