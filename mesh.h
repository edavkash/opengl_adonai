#ifndef MESH_H
#define MESH_H

#include "common.h"

typedef struct Mesh Mesh;

struct Mesh
{
  GLuint VAO,VBO;
};

extern Mesh mesh_init(const float *vertices,size_t size);
#endif
