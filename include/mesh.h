#ifndef MESH_H
#define MESH_H

#include "common.h"

typedef struct Mesh Mesh;

struct Mesh
{
  GLuint VAO,VBO,EBO;
};

extern Mesh mesh_init(const float *vertices, size_t size);
extern Mesh mesh_tri(float *, size_t);
extern Mesh quad(float *,GLuint *, size_t,size_t);

#endif
