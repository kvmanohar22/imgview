#include "imgview/image.h"

namespace imgview {

Image::Image(const std::string filename) {
  int width, height, channels;
  stbi_set_flip_vertically_on_load(true);
  uint8_t* data = stbi_load(filename.c_str(), &width, &height, &channels, 0);
  if (!data) {
    std::cerr << "Couldn't load the image: " << filename << "\n";
  }
  width_ = width;
  height_ = height;
  channels_ = channels;
  data_ = data;
}

void Image::update(uint8_t* data) {
  for(size_t y=0; y<height_; ++y) {
    for(size_t x=0; x<width_; ++x) {
      for(size_t c=0; c<3; ++c)
        *(data_+y*width_+x+c) = *(data+y*width_+x+c);
    }
  }
}

} // namespace imgview
