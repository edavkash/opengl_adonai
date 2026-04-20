#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "mesh.h"
#include "shader.h"

/* window coordinate*/
GLint x = 0;
GLint y = 0;

/*window length*/
GLint width = 800;
GLint height = 600;

/*triangle coordinate*/

const float vertices[] =
{
  0.5f, 0.5f, 0.0f,
  -0.5f, -0.5f, 0.0f,
  0.5f, -0.5f, 0.0f
};

int main(int argc, char **argv)
{

  /*Checking for errors*/
  glfwSetErrorCallback(callback_error);

  /*GLFW initialization*/
  if (!glfwInit())
    error("[-] Initialization failed");
  else printf("[+] GLFW initialized successful\n");

  /*Creating our window*/
  GLFWwindow *window =
    glfwCreateWindow(width, height, "Startup Window", NULL, NULL);

  if (!window)
    {
      error("[-] Window failed");
      glfwTerminate();
    }

  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer);

  /*Loading/Initializing glad*/
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
      glfwTerminate();
      error("[-] Glad failed to load");
      exit(EXIT_FAILURE);
    }
  else
    {
      printf("[+] GLAD Loaded successful\n");
    }

  CompileShader("vshader.vert", "fshader.frag");
  Shader *s = malloc(sizeof(Shader));
  Mesh m = mesh_init(vertices,sizeof(vertices));

  while (!glfwWindowShouldClose(window))
    {
      // Drawing a triangle
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
      use(s);
      glBindVertexArray(m.VAO);
      glDrawArrays(GL_TRIANGLES, 0, 3);

      /*This is all you will need to draw a plain window*/
      glfwSwapBuffers(window);
      glfwPollEvents();
    }

  glfwTerminate();
  free(s);
  return 0;
}

void error(const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  fprintf(stderr,"\n");
  va_end(ap);
  exit(EXIT_FAILURE);
}

void callback_error(int desc, const char *warning)
{
  error( "error: %d. %s",desc,warning);
}

void framebuffer(GLFWwindow *window, GLint width, GLint height)
{
  glViewport(0,0,width,height);
}
