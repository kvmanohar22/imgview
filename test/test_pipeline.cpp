#include "imgview/global.h"
#include "imgview/window.h"
#include "imgview/mosaic.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <unistd.h>

using namespace imgview;

int main() {
  // Create window
  Mosaic* mosaic = new Mosaic();
  Window* window = new Window(900, 600, "viewer", mosaic);

  // Load image
  Image* image = new Image("../imgs/test.png");

  // Add some tesserae on mosaic
  mosaic->add(image, -1, 1, 1, 1);

  // Render
  window->show();

  // do anything that you want
  usleep(100000000);
}
