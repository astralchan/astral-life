// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <memory>
#include <string>

#include <GLFW/glfw3.h>

namespace AL {

class Window final {
public:
    Window(int width = 800, int height = 600, const std::string& title = "",
            const std::shared_ptr<GLFWmonitor>& monitor = nullptr,
            const std::shared_ptr<GLFWwindow>& share = nullptr);
    ~Window() = default;

    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] const std::string& getTitle() const;
    [[nodiscard]] const std::shared_ptr<GLFWmonitor>& getMonitor() const;
    [[nodiscard]] const std::shared_ptr<GLFWmonitor>& getShare() const;

    void setSize(int width, int height);
    void setTitle(const std::string& title);

    void makeContextCurrent() const;
    void swapBuffers() const;

    [[nodiscard]] bool shouldClose() const;
    void setShouldClose(bool value) const;
private:
    std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> window;
    int width;
    int height;
    std::string title;
    std::shared_ptr<GLFWmonitor> monitor;
    std::shared_ptr<GLFWwindow> share;
}; // class Window

} // namespace AL
