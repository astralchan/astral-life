// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <memory>
#include <string>

#include <GLFW/glfw3.h>

namespace AL {

class Window {
public:
    Window(int width = 800, int height = 600, const std::string& title = "",
            const std::shared_ptr<GLFWmonitor>& monitor = nullptr,
            const std::shared_ptr<GLFWwindow>& share = nullptr);
    ~Window() = default;

    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] std::string getTitle() const;
    [[nodiscard]] std::shared_ptr<GLFWmonitor> getMonitor() const;
    [[nodiscard]] std::shared_ptr<GLFWwindow> getShare() const;

    void setSize(int width, int height);
    void setTitle(const std::string& title);

    void makeContextCurrent() const;
    void swapBuffers() const;

    [[nodiscard]] bool shouldClose() const;
    void setShouldClose(bool shouldClose);
private:
    std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> m_window;
    int m_width;
    int m_height;
    std::string m_title;
    std::shared_ptr<GLFWmonitor> m_monitor;
    std::shared_ptr<GLFWwindow> m_share;
}; // class Window

} // namespace AL
