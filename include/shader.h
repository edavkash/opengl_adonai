#ifndef SHADER_H
#define SHADER_H

#include "common.h"

typedef struct Shader Shader;

struct Shader
{
  GLuint ID;
};
extern void use(Shader *usage);
extern Shader *CompileShader(const char *vpath, const char *fpath);
#endif
