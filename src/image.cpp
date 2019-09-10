#include "imgview/image.h"

namespace imgview {

template <typename DTYPE>
void Image<DTYPE>::reserve() {
  assert(is_valid());
  data_ = new DTYPE[width_*height_*channels_];
}

template <typename DTYPE>
void Image<DTYPE>::update(DTYPE* data) {
  for(size_t y=0; y<height_; ++y) {
    for(size_t x=0; x<width_; ++x) {
      for(size_t c=0; c<3; ++c)
        *(data_+y*width_+x+c) = *(data+y*width_+x+c);
    }
  }
}

} // namespace imgview
