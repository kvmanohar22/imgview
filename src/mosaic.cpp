#include "imgview/mosaic.h"

namespace imgview {


Mosaic::~Mosaic() {
  std::for_each(tesserae_.begin(), tesserae_.end(), [&](Tessera* tessera) {
    delete tessera;
  });
}

void Mosaic::add(Tessera* tessera) {
  tesserae_.push_back(tessera);
}

void Mosaic::add(Image* image,
  float x, float y,
  float width, float height)
{
  auto new_tessera = new Tessera(x, y, width, height, image);
  tesserae_.push_back(new_tessera);
}

} // namespace imgview
