// SPDX-License-Identifier: GPL-3.0-or-later

#include "glfw-context.hh"

#if !defined(NDEBUG)
#include <iostream>
#endif

#include <stdexcept>

#include <GLFW/glfw3.h>

namespace AL {

GLFWContext::GLFWContext() {
    if (glfwInit() != GLFW_TRUE)
        throw std::runtime_error("Failed to initialize GLFW");
#if !defined(NDEBUG)
    std::cerr << "Initialized GLFW context" << std::endl;
#endif
}

GLFWContext::~GLFWContext() {
    glfwTerminate();
}

void GLFWContext::pollEvents() const {
    glfwPollEvents();
}

} // namespace AL
