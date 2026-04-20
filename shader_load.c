/*Loading content of a GLSL file into a C program*/
#include "common.h"
#include <fcntl.h>
#include <unistd.h>

char *load_shader_content(const char *pathname)
{
  FILE *fp;
  long size = 0;
  // char buffer[SIZE];
  char *shaderContent;

  /*Read file to get size*/

  fp = fopen(pathname, "rb");

  if (!fp)
    {
      perror("can't read from file\n");
      exit(EXIT_FAILURE);
    }

  fseek(fp, 0L, SEEK_END);
  size = ftell(fp) + 1;
  fclose(fp);

  /*Read content of a file*/
  fp = fopen(pathname, "rb");
  shaderContent = memset(malloc(size), '\0', size);
  fread(shaderContent, 1, size - 1, fp);
  fclose(fp);
  return shaderContent;
}

