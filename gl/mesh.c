#include <mesh.h>
#include <common.h>

Mesh mesh_tri(float *vertices,size_t size)
{
  Mesh m;
  glGenVertexArrays(1, &m.VAO);
  glGenBuffers(1, &m.VBO);
// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
  glBindVertexArray(m.VAO);

  glBindBuffer(GL_ARRAY_BUFFER, m.VBO);
  // glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
//Position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  //Color attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
  glEnableVertexAttribArray(1);

  // texture attribute
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
  glEnableVertexAttribArray(2);

  // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  return m;
}


Mesh quad(float *vertices, GLuint *indices, size_t size_v, size_t size_i)
{
  Mesh quad;
  glGenVertexArrays(1, &quad.VAO);
  glGenBuffers(1, &quad.VBO);
  glGenBuffers(1, &quad.EBO);
  glBindVertexArray(quad.VAO);
  glBindBuffer(GL_ARRAY_BUFFER, quad.VBO);
  glBufferData(GL_ARRAY_BUFFER, size_v, vertices, GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,quad.EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_i, indices, GL_STATIC_DRAW);

  // position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  // color attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  // texture coord attribute
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
  glEnableVertexAttribArray(2);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  return quad;
}

