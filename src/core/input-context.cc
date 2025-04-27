// SPDX-License-Identifier: GPL-3.0-or-later

#include "input-context.hh"

#include <stdexcept>

#include "pch/glfw.hh"

namespace AL::Core {

InputContext::InputContext() {
  if (glfwInit() != GLFW_TRUE)
    throw std::runtime_error("Failed to initialize GLFW");
}

InputContext::~InputContext() {
  glfwTerminate();
}

void InputContext::pollEvents() const {
  glfwPollEvents();
}

} // namespace AL::Core
