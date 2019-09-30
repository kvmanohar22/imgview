#ifndef _IMGVIEW_IMAGE_H_
#define _IMGVIEW_IMAGE_H_

#include "imgview/global.h"
#include <stb_image.h>

#include <vector>
#include <mutex>
#include <stdio.h>
#include <stdlib.h>

namespace imgview {

/// WARNING: Does not check the bounds of the data
class Image {
public:
  Image()
    : width_(0),
      height_(0),
      channels_(0),
      data_(nullptr),
      updated_(false)
  {}

  Image(size_t width, size_t height, size_t channels, uint8_t* data)
    : width_(width),
      height_(height),
      channels_(channels),
      data_(data),
      updated_(false)
  {}

  Image(const std::string filename);

 ~Image() { stbi_image_free(data_); }

  inline const size_t width()  const { return width_; }
  inline const size_t height() const { return height_; }
  inline const size_t channels() const { return channels_; }
  inline bool is_valid() const { return width_ != 0 && height_ != 0 && channels_ != 0; }
  inline bool updated()  const { return updated_; }
  inline void set_update_false() { updated_ = false; }

  void update(uint8_t* data);
  inline const uint8_t* data() const { return data_; }
  inline uint8_t* mutable_data() { return data_; }

private:
  size_t width_;
  size_t height_;
  size_t channels_;
  uint8_t* data_;
  bool  updated_;
}; // class Image

} // namespace imgview

#endif
