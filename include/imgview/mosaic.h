#ifndef _IMGVIEW_MOSAIC_H_
#define _IMGVIEW_MOSAIC_H_

#include "imgview/global.h"
#include "imgview/image.h"
#include <list>
#include <algorithm>

namespace imgview {

/// container for each part of mosaic
class Tessera {
public:
  Tessera(float x, float y, float width, float height, Image* image)
    : x_(x),
      y_(y),
      width_(width),
      height_(height),
      image_(image)
  {}

  float         x_;
  float         y_;
  float         width_;
  float         height_;
  Image*        image_;
}; // class Tessera

/*
 * Collection of multiple images that are to be displayed
 *
 * (0, 1)             (1, 1)
 *    +-----------------+
 *    |                 |
 *    .                 .
 *    .                 .
 *    .                 .
 *    |                 |
 *    +-----------------+
 * (0, 0)            (1, 0)
 *
 */

class Mosaic {
public:
  Mosaic() =default;
 ~Mosaic();

  void add(Tessera* tessera);
  void add(Image* image,
    float x,      // from bottom left
    float y,      // from bottom left
    float width,  // along width
    float height  // along height
  );

private:
  std::list<Tessera*>  tesserae_;
}; // class Mosaic

} // namespace imgview

#endif
