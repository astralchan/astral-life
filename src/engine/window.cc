// SPDX-License-Identifier: GPL-3.0-or-later

#include "window.hh"

#if !defined(NDEBUG)
#include <iostream>
#endif

#include <memory>
#include <stdexcept>
#include <string>

#include <GLFW/glfw3.h>

namespace AL {

Window::Window(int width, int height, const std::string& title,
        const std::shared_ptr<GLFWmonitor>& monitor,
        const std::shared_ptr<GLFWwindow>& share)
    : window(glfwCreateWindow(width, height, title.c_str(), monitor.get(),
            share.get()), glfwDestroyWindow), width(width), height(height),
            title(title), monitor(monitor), share(share) {
    if (window.get() == nullptr)
        throw std::runtime_error("Failed to create GLFW window");
#if !defined(NDEBUG)
    std::cerr << "Created window: " << title << " (" << width << ", " << height
        << ")" << std::endl;
#endif
}

void Window::makeContextCurrent() const {
    glfwMakeContextCurrent(window.get());
}

void Window::swapBuffers() const {
    glfwSwapBuffers(window.get());
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(window.get()) == GLFW_TRUE;
}

void Window::setShouldClose(bool value) const {
    glfwSetWindowShouldClose(window.get(), value ? GLFW_TRUE : GLFW_FALSE);
}

} // namespace AL
