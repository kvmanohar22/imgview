#include "imgview/global.h"
#include "imgview/window.h"
#include "imgview/mosaic.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <unistd.h>

using namespace imgview;

int main() {
  // load image
  Image* image = new Image("../imgs/test.png");

  // Add some tesserae on mosaic
  Mosaic* mosaic = new Mosaic();
  mosaic->add(image, 0, 0, 1, 1);

  // create window
  Window* window = new Window(800, 600, "viewer", mosaic);

  // do anything that you want
  usleep(100000000);
}
