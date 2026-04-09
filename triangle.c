#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

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

  /*Checking for compilation*/
  int success;
  char infoLog[SIZE];

  /*Vertex Shading*/

  GLuint VertShader = glCreateShader(GL_VERTEX_SHADER);
  const char *VertShaderSource = read_file("script.vert");
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
  const char *FragShaderSource = read_file("script.frag");
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
  GLuint Program = glCreateProgram();
  glAttachShader(Program,VertShader);
  glAttachShader(Program, FragShader);
  glLinkProgram(Program);
  glGetProgramiv(Program, GL_LINK_STATUS, &success);
  if (!success)
    {
      glGetProgramInfoLog(Program, SIZE, NULL, infoLog);
      error("Program failed");
    }
  else printf("[+] Program shader successful\n");

  /*-------------------------------------------------------------------------------------
    NOTE:I still have yet fully master how rendering pipeline vbo,vao and ebo work
  --------------------------------------------------------------------------------------*/

  // Basic Vertex Buffer Object (VBO)

  GLuint VAO, VBO;
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  // Drawing the window
  while (!glfwWindowShouldClose(window))
    {
      // Drawing a triangle
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
      glUseProgram(Program);
      glBindVertexArray(VAO);
      glDrawArrays(GL_TRIANGLES, 0, 3);

      /*This is all you will need to draw a plain window*/
      glfwSwapBuffers(window);
      glfwPollEvents();
    }

  /* while (!glfwWindowShouldClose(window)) */
  /*   { */
  /*     glClearColor(0.1f, 0.1f, 0.1f, 1.0f); */
  /*     glClear(GL_COLOR_BUFFER_BIT); */

  /*     glUseProgram(Program); */
  /*     glBindVertexArray(VAO); */
  /*     glDrawArrays(GL_TRIANGLES, 0, 3); */

  /*     glfwSwapBuffers(window); */
  /*     glfwPollEvents(); */
  /*   } */

  glDeleteShader(VertShader);
  glDeleteShader(FragShader);

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
  glViewport(0,0,width,height);
}
