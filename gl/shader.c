#include "shader.h"
#include "common.h"

Shader *CompileShader(const char *vpath, const char *fpath)
{
  // dummy object

  Shader *shader = malloc(sizeof(Shader));
  const char *VertShaderSource = load_shader_content(vpath);
  const char *FragShaderSource = load_shader_content(fpath);

  /*Checking for compilation*/
  int success;
  char infoLog[SIZE];

  /*Vertex Shading*/

  GLuint VertShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(VertShader, 1, &VertShaderSource, NULL);
  glCompileShader(VertShader);
  glGetShaderiv(VertShader, GL_COMPILE_STATUS, &success);

  if (!success)
    {
      glGetShaderInfoLog(VertShader, SIZE, NULL, infoLog);
      error("[-] vertex shader failed");
    }
  else printf("[+] vertex shader successful\n");

  /*Fragment shading*/

  GLuint FragShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(FragShader, 1, &FragShaderSource, NULL);
  glCompileShader(FragShader);
  glGetShaderiv(FragShader, GL_COMPILE_STATUS, &success);

  if (!success)
    {
      glGetShaderInfoLog(FragShader, SIZE, NULL, infoLog);
      error("[-] Fragments shader failed");
    }
  else printf("[+] fragment shader successful\n");


  /*Combining both rendering pipeline*/
  shader->ID = glCreateProgram();
  glAttachShader(shader->ID,VertShader);
  glAttachShader(shader->ID, FragShader);
  glLinkProgram(shader->ID);
  glGetProgramiv(shader->ID, GL_LINK_STATUS, &success);
  if (!success)
    {
      glGetProgramInfoLog(shader->ID, SIZE, NULL, infoLog);
      error("Program failed");
    }
  else
    printf("[+] Program Linked successful\n");

  glDeleteShader(VertShader);
  glDeleteShader(FragShader);
  return shader;
}

void use(Shader *usage)
{
  if (!usage) return;
  else glUseProgram(usage->ID);
}
