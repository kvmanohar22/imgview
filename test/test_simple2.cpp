#include "imgview/global.h"
#include "imgview/window.h"
#include "imgview/mosaic.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <math.h>
#include <thread>
#include <chrono>

using namespace imgview;
using namespace std;

static constexpr size_t h = 512;
static constexpr size_t w = 512;

int main() {
  // Create window
  Mosaic* mosaic = new Mosaic();
  Window* window = new Window(w, h, "viewer", mosaic);

  // Load image
  Image* image = new Image("../imgs/test.png");

  // Horizontal split
  mosaic->add(image, 0, 0, w/2, h/2);
  mosaic->add(image, w/2, h/2, w/2, h/2);
  mosaic->add(image, w/2, 0, w/2, h/2);
  mosaic->add(image, 0, h/2, w/2, h/2);

  // Render
  window->show();

  // do anything that you want
  std::this_thread::sleep_for(std::chrono::milliseconds(100000));
}
