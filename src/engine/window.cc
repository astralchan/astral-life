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
    : m_window(glfwCreateWindow(width, height, title.c_str(), monitor.get(),
            share.get()), glfwDestroyWindow), m_width(width), m_height(height),
            m_title(title), m_monitor(monitor), m_share(share) {
    if (m_window.get() == nullptr)
        throw std::runtime_error("Failed to create GLFW window");

#if !defined(NDEBUG)
    std::cerr << "Created window (" << m_title << "): " << m_width << ", " <<
            m_height << std::endl;
#endif

    glfwSetWindowUserPointer(m_window.get(), this);
    glfwSetFramebufferSizeCallback(m_window.get(), [](GLFWwindow* window,
            int width, int height) {
        auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
        self->m_width = width;
        self->m_height = height;
    });
}

int Window::getWidth() const {
    return m_width;
}

int Window::getHeight() const {
    return m_height;
}

std::string Window::getTitle() const {
    return m_title;
}

std::shared_ptr<GLFWmonitor> Window::getMonitor() const {
    return m_monitor;
}

std::shared_ptr<GLFWwindow> Window::getShare() const {
    return m_share;
}

void Window::setSize(int width, int height) {
    glfwSetWindowSize(m_window.get(), width, height);
    m_width = width;
    m_height = height;
}

void Window::setTitle(const std::string& title) {
    glfwSetWindowTitle(m_window.get(), title.c_str());
    m_title = title;
}

void Window::makeContextCurrent() const {
    glfwMakeContextCurrent(m_window.get());
}

void Window::swapBuffers() const {
    glfwSwapBuffers(m_window.get());
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(m_window.get()) == GLFW_TRUE;
}

void Window::setShouldClose(bool shouldClose) {
    glfwSetWindowShouldClose(m_window.get(), shouldClose ? GLFW_TRUE :
            GLFW_FALSE);
}

} // namespace AL
