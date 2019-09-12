#include "imgview/mosaic.h"

namespace imgview {

void Tessera::generate() {
  internal_format_ = GL_RGB;
  image_format_    = GL_RGB;

  wrap_s_ = GL_REPEAT;
  wrap_t_ = GL_REPEAT;

  filter_min_ = GL_LINEAR;
  filter_max_ = GL_LINEAR;

  const uint8_t* data = image_->data();
  glGenTextures(1, &id_);
  glBindTexture(GL_TEXTURE_2D, id_);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s_);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_t_);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter_min_);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter_max_);
  glTexImage2D(GL_TEXTURE_2D, 0, internal_format_, image_->width(), image_->height(), 0, image_format_, GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, 0);
}

void Tessera::bind() const {
  glBindTexture(GL_TEXTURE_2D, id_);
}

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
