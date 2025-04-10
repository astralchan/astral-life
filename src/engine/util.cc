// SPDX-License-Identifier: GPL-3.0-or-later

#include "util.hh"

#include <filesystem>
#include <stdexcept>
#include <string>

namespace AL {

std::filesystem::path getResource(const std::string& file) {
    const std::filesystem::path paths[] = {
        "./res",
#if defined(_WIN32)
        "./",
#elif defined(__APPLE__) && defined(__MACH__)
        "/Applications/astral-life",
        "/usr/local/astral-life",
#elif defined(__unix__)
        "/usr/share/astral-life",
#endif
    };

    for (const auto& path : paths) {
        std::filesystem::path fullPath = path / file;
        if (std::filesystem::exists(fullPath) &&
                std::filesystem::is_regular_file(fullPath))
            return fullPath;
    }

    throw std::runtime_error("Could not find resource: " + file);
}

} // namespace AL
