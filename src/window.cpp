#include "imgview/window.h"

namespace imgview {

Window::~Window() {
  render_thread_.join();
}

bool Window::init() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_VISIBLE, GL_FALSE);

  window_ = glfwCreateWindow(1, 1, "", NULL, NULL);
  if (window_ == NULL) {
    std::cerr << "Failed to create GLFW window\n";
    glfwTerminate();
    return false;
  }

  glfwMakeContextCurrent(window_);
  glfwSwapInterval(1);
  gl3wInit();
  render_thread_ = std::thread(&Window::render, this);
  return true;
}

bool Window::render() {
  glfwWindowHint(GLFW_VISIBLE, GL_TRUE);
  shared_window_ = glfwCreateWindow(width_, height_, name_.c_str(), NULL, window_);
  if (shared_window_ == NULL) {
    std::cerr << "Failed to create GLFW window\n";
    glfwTerminate();
    return false;
  }

  glfwMakeContextCurrent(shared_window_);
  glfwSetWindowUserPointer(shared_window_, this);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_MULTISAMPLE);
  glEnable(GL_PROGRAM_POINT_SIZE);

  // render mosaic!
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  while(!glfwWindowShouldClose(shared_window_)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(shared_window_);
    glfwPollEvents();
  }
  return true;
}

} // namespace imgview
