#ifndef _IMGVIEW_IMAGE_H_
#define _IMGVIEW_IMAGE_H_

#include <vector>
#include <stdio.h>
#include <stdlib.h>

namespace imgview {

/// WARNING: Does not check the bounds of the data
template <typename DTYPE>
class Image {
public:
  Image<DTYPE>()
    : width_(0),
      height_(0),
      channels_(0),
      data_(nullptr)
  {}

  Image<DTYPE>(size_t width, size_t height, size_t channels, DTYPE* data)
    : width_(width),
      height_(height),
      channels_(channels),
      data_(data)
  {
    reserve();
  }

 ~Image<DTYPE>() { delete data_; }

  inline size_t width()  const { return width_; }
  inline size_t height() const { return height_; }
  inline bool is_valid() const { return width_ != 0 && height_ != 0 && channels_ != 0; }

  void reserve();
  void update(DTYPE* data);

private:
  size_t width_;
  size_t height_;
  size_t channels_;
  DTYPE* data_;
}; // class Image

} // namespace imgview

#endif
