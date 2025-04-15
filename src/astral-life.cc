// SPDX-License-Identifier: GPL-3.0-or-later

#include <cstdlib>
#include <exception>
#include <iostream>

#include "engine/glfw-context.hh"
#include "engine/window.hh"

int main() {
    try {
        AL::GLFWContext ctx;

        AL::Window win(1280, 720, "Astral Life");
        win.makeContextCurrent();

        while (!win.shouldClose()) {
            win.swapBuffers();
            ctx.pollEvents();
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
