// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

namespace AL {

class GLFWContext {
public:
    GLFWContext();
    ~GLFWContext();

    void pollEvents() const;
}; // class GLFWContext

} // namespace AL
