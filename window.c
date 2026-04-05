#include <stdarg.h>
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include "common.h"

/* window coordinate*/
GLint x = 0;
GLint y = 0;

/*window length*/
GLint width = 800;
GLint height = 600;

int main(int argc, char **argv)
{

  /*Checking for errors*/
  glfwSetErrorCallback(callback_error);

  /*GLFW initialization*/
  glfwInit();

  /*Creating our window*/
  GLFWwindow *window =
    glfwCreateWindow(width, height, "Startup Window", NULL, NULL);

  if (window == NULL)
    {
      error("Window failed");
      glfwTerminate();
    }

  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer);

  /*Loading/Initializing glad*/
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
      glfwTerminate();
      exit(EXIT_FAILURE);
    }

  /*Drawing the window*/
  while (!glfwWindowShouldClose(window))
    {
      /*This is all you will need to draw a plain window*/
      glfwSwapBuffers(window);
      glfwPollEvents();
    }

  glfwTerminate();
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
  glViewport(x,y,width,height);
}
