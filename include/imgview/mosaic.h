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
  {
    generate();
  }

  void bind() const;
  void generate();

  float         x_;
  float         y_;
  float         width_;
  float         height_;
  Image*        image_;

  // Texture related
  unsigned int id_;
  GLuint internal_format_, image_format_;
  GLuint wrap_s_, wrap_t_;
  GLuint filter_min_, filter_max_;

}; // class Tessera

/*
 * Collection of multiple images that are to be displayed
 *
 * (-1, 1)             (1, 1)
 *    +-----------------+
 *    |                 |
 *    .                 .
 *    .                 .
 *    .                 .
 *    |                 |
 *    +-----------------+
 * (-1, -1)            (1, -1)
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

  std::list<Tessera*>  tesserae_;
}; // class Mosaic

} // namespace imgview

#endif
