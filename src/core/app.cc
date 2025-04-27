// SPDX-License-Identifier: GPL-3.0-or-later

#include "app.hh"

#include "core/input-context.hh"
#include "core/window.hh"

namespace AL::Core {

void App::run() {
  InputContext ctx;

  Window win(800, 600, "Astral Life");
  win.makeContextCurrent();

  while (!win.shouldClose()) {
    win.swapBuffers();
    ctx.pollEvents();
  }
}

} // namespace AL::Core
