// SPDX-License-Identifier: GPL-3.0-or-later

#include "window.hh"

#include <cstdint>
#include <memory>
#include <stdexcept>
#include <string>

#include "pch/glfw.hh"

namespace AL::Core {

Window::Window(uint32_t width, uint32_t height, const std::string& title,
               const std::shared_ptr<GLFWmonitor>& monitor,
               const std::shared_ptr<GLFWwindow>& share)
    : m_handle(
          glfwCreateWindow(static_cast<int>(width),
                           static_cast<int>(height), title.c_str(),
                           monitor.get(), share.get()),
          glfwDestroyWindow),
      m_width(width),
      m_height(height),
      m_title(title),
      m_monitor(monitor),
      m_share(share) {

  if (m_handle.get() == nullptr)
    throw std::runtime_error("Failed to create window");

  glfwSetWindowUserPointer(m_handle.get(), this);

  glfwSetWindowSizeCallback(
      m_handle.get(), [](GLFWwindow* window, int width, int height) {
        Window* self = static_cast<Window*>(glfwGetWindowUserPointer(window));

        self->m_width = width;
        self->m_height = height;
  });
}

uint32_t Window::getWidth() const {
  return m_width;
}

uint32_t Window::getHeight() const {
  return m_height;
}

std::string Window::getTitle() const {
  return m_title;
}

void Window::makeContextCurrent() const {
  glfwMakeContextCurrent(m_handle.get());
}

void Window::swapBuffers() const {
  glfwSwapBuffers(m_handle.get());
}

bool Window::shouldClose() const {
  return glfwWindowShouldClose(m_handle.get()) == GLFW_TRUE;
}

void Window::setShouldClose(bool shouldClose) const {
  glfwSetWindowShouldClose(m_handle.get(),
                           shouldClose ? GLFW_TRUE : GLFW_FALSE);
}

} // namespace AL::Core
