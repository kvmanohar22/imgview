#ifndef _IMGVIEW_WINDOW_H_
#define _IMGVIEW_WINDOW_H_

#include "imgview/global.h"
#include "imgview/mosaic.h"
#include "imgview/renderer.h"
#include "imgview/shader.h"

#include <iostream>
#include <thread>
#include <mutex>

namespace imgview {

class Window {
public:
  Window() =default;
 ~Window();
  explicit Window(size_t width, size_t height, std::string name, Mosaic* mosaic)
    : width_(width),
      height_(height),
      name_(name),
      mosaic_(mosaic)
  {
    init();
  }

  bool init();
  bool show();
  bool render();

private:
  size_t      width_;
  size_t      height_;
  std::string name_;
  Mosaic*     mosaic_;
  Renderer*   renderer_;
  Shader*     shader_;

  GLFWwindow* window_;
  GLFWwindow* shared_window_;
  std::thread render_thread_;
}; // class Window

} // namespace imgview

#endif
