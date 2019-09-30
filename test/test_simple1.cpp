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

int main() {
  // Create window
  Mosaic* mosaic = new Mosaic();
  Window* window = new Window(512, 512, "viewer", mosaic);

  // Load image
  Image* image = new Image("../imgs/test.png");

  // Add some tesserae on mosaic
  mosaic->add(image, 0, 0, 512, 512);

  // Render
  window->show();

  // do anything that you want
  std::this_thread::sleep_for(std::chrono::milliseconds(100000));
}
