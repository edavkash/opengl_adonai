#ifndef TEXTURE_H
#define TEXTURE_H

#include "shader.h"

typedef struct Texture Texture;

struct Texture
{
  GLuint texture;
};

extern Texture texture_load(const char*);

#endif
