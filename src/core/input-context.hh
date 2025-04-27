// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

namespace AL::Core {

class InputContext {
public:
  InputContext();
  ~InputContext();

  void pollEvents() const;
}; // class InputContext

} // namespace AL::Core
