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

  const size_t h = image->height();
  const size_t w = image->width();
  const size_t c = image->channels();

  cout << "h = " << h << "\t"
       << "w = " << w << "\t"
       << "w = " << c << "\t"
       << "t = " << h*w*c << "\n";

  const uint8_t* data = image->data();
  uint8_t original_data[w*h*c];
  for(size_t y=0; y<h; ++y) {
    for(size_t x=0; x<w; ++x) {
      for(size_t c_=0; c_<c; ++c_)
        *(original_data+y*w+c*x+c_) = *(data+y*w+c*x+c_);
    }
  }

  uint8_t new_data[w*h*c];
  float alpha = 0.99;
  size_t total=0;
  for(size_t i=0; i<100000; ++i) {
    std::cout << "i = " << i << "alpha = " << alpha << std::endl;
    // update image data
    for(size_t y=0; y<h; ++y) {
      for(size_t x=0; x<w; ++x) {
        for(size_t c_=0; c_<c; ++c_) {
          // *(new_data+y*w+3*x+c) = static_cast<uint8_t>((float)*(original_data+y*w+3*x+c) * abs(cos(0.07*i*imgview::PI)));
          *(new_data+y*w+c*x+c_) = static_cast<uint8_t>((float)*(original_data+y*w+c*x+c_) * alpha);
          ++total;
        }
      }
    }
    cout << "total = " << total << std::endl;
    total = 0;
    alpha *= 0.9;
    image->update(new_data);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  std::this_thread::sleep_for(std::chrono::milliseconds(100000));
  // do anything that you want
}
