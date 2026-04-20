#include "mesh.h"

Mesh mesh_init(const float *vertices, size_t size)
{

  Mesh mesh;
  // Basic Vertex Buffer Object (VBO)
  glGenVertexArrays(1, &mesh.VAO);
  glBindVertexArray(mesh.VAO);

  glGenBuffers(1, &mesh.VBO);
  glBindBuffer(GL_ARRAY_BUFFER, mesh.VBO);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
  return mesh;
}
