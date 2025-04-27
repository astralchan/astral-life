// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <cstdint>
#include <memory>
#include <string>

#include "pch/glfw.hh"

namespace AL::Core {

class Window {
public:
  Window(uint32_t width = 800, uint32_t height = 600,
         const std::string& title = "",
         const std::shared_ptr<GLFWmonitor>& monitor = nullptr,
         const std::shared_ptr<GLFWwindow>& share = nullptr);
  ~Window() = default;

  [[nodiscard]] uint32_t getWidth() const;
  [[nodiscard]] uint32_t getHeight() const;
  [[nodiscard]] std::string getTitle() const;

  void makeContextCurrent() const;
  void swapBuffers() const;

  [[nodiscard]] bool shouldClose() const;
  void setShouldClose(bool shouldClose) const;
private:
  std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> m_handle;
  uint32_t m_width;
  uint32_t m_height;
  std::string m_title;
  std::shared_ptr<GLFWmonitor> m_monitor;
  std::shared_ptr<GLFWwindow> m_share;
}; // class Window

} // namespace AL::Core
