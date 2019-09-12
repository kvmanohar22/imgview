#include "imgview/renderer.h"
#include "glm/gtx/string_cast.hpp"

namespace imgview {

void Renderer::init() {
  float vertices[] = {
    // positions      // texture
   -1.0f,  0.0f, 0.0f, 0.0f, 0.0f,
    0.0f,  0.0f, 0.0f, 1.0f, 0.0f,
   -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,

    0.0f,  0.0f, 0.0f, 1.0f, 0.0f,
    0.0f,  1.0f, 0.0f, 1.0f, 1.0f,
   -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
  };

  unsigned int VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glGenVertexArrays(1, &VAO_);
  glBindVertexArray(VAO_);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)(3*sizeof(float)));
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

void Renderer::render(Tessera* tessera) {
  // Translate
  float dx = tessera->x_ + 1.0f;
  float dy = tessera->y_ - 1.0f;
  // Scale
  float sx = tessera->width_;
  float sy = tessera->height_;

  glm::mat4 model = glm::mat4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
  model = glm::translate(model, glm::vec3(dx, dy, 0.0f));

  shader_->use();
  shader_->setmat4("model", model);

  glActiveTexture(GL_TEXTURE0);
  tessera->bind();

  glBindVertexArray(VAO_);
  glDrawArrays(GL_TRIANGLES, 0, 6);
  glBindVertexArray(0);
}

} // namespace imgview
