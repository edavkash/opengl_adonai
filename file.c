#include <stdio.h>
#include <stdlib.h>
#include "common.h"

char *read_file(const char *path)
{
  FILE *fp;
  fp = fopen(path, "rb");
  fseek(fp, 0, SEEK_END);
  ssize_t fsize = ftell(fp);
  rewind(fp);

  char *buffer = malloc(fsize + 1);
  fread(buffer, 1,fsize, fp);

  buffer[fsize] = 0;
  fclose(fp);
  return buffer;
}
