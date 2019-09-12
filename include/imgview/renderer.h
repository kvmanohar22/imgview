#ifndef _IMGVIEW_RENDERER_H_
#define _IMGVIEW_RENDERER_H_

#include "imgview/global.h"
#include "imgview/shader.h"
#include "imgview/mosaic.h"

namespace imgview {

class Renderer {
public:
  Shader* shader_;
  GLuint  VAO_;

  Renderer(Shader* shader)
    :  shader_(shader)
  {
    init();
  }
 ~Renderer();
  
  void init();
  void render(Tessera* tessera);
};

} // namespace imgview

#endif
