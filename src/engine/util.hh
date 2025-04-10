// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <filesystem>
#include <string>

namespace AL {

std::filesystem::path getResource(const std::string& file);

} // namespace AL
