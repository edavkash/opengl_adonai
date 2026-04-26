#include "texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


Texture texture_load(const char *image)
{

  GLint nrColor;
  GLenum format;
  GLint image_width, image_height;

  unsigned char *image_data;

  Texture t;
  glGenTextures(1, &t.texture);
  glBindTexture(GL_TEXTURE_2D, t.texture);


  stbi_set_flip_vertically_on_load(1);

  if (image_data)
    {
      format = (nrColor == 4) ? GL_RGBA : GL_RGB;
      image_data = stbi_load(image, &image_width, &image_height, &nrColor, 0);
      // Texture Wrapping
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

      // Texture Filtering and Mipmaps
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
      /* glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, */
      /*                 GL_LINEAR_MIPMAP_LINEAR); */
      /*GL_TEXTURE_MAG_FILTER doesn't have a GL_LINEAR_MIPMAP_LINEAR like  GL_TEXTURE_MIN_FILTER else it will return GL_INVALID_ENUM*/
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

      glTexImage2D(GL_TEXTURE_2D, 0, format, image_width, image_height, 0, format,
                   GL_UNSIGNED_BYTE,image_data);
      glGenerateMipmap(GL_TEXTURE_2D);
      printf("[+] 2D Image succeded to load...\n");
    }
  else
    {
      printf("[-] 2D Image failed to load\n");
      exit(EXIT_FAILURE);
    }

  stbi_image_free(image_data);
  return t;
}
