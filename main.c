#include <shader.h>
#include <mesh.h>
#include <texture.h>

GLuint width = 800;
GLuint height = 600;

int main(int argc, char **argv)
{

  glfwInit();

  GLFWwindow *window =
    glfwCreateWindow(width, height, "Learn OpenGL", NULL, NULL);
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
      glfwTerminate();
      exit(EXIT_FAILURE);
    }

  glfwSwapInterval(1);
  glfwSetFramebufferSizeCallback(window, framebuffer);

  // configuring and linking vertex and fragment shader program
  // CompileShader("glsl/texel.vert","glsl/texel.frag");

  float vertices[] =
  {
    // positions        // colors   // texture coords
    0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
    0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
    -0.5f, 0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // top left
  };

  unsigned int indices[] =
  {
    0,1,3,
    1,2,3
  };

  Texture texel = texture_load("assets/naruto-art.jpg");
  Shader *s = CompileShader("glsl/texel.vert","glsl/texel.frag");
  Mesh mesh =  quad(vertices, indices,sizeof(vertices),sizeof(indices));
  GLuint vao = mesh.VAO;

  use(s);
  glUniform1i(glGetUniformLocation(s->ID, "texel"), 0);

  while (!glfwWindowShouldClose(window))
    {
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
      glActiveTexture(GL_TEXTURE0);
      glBindTexture(GL_TEXTURE_2D, texel.texture);
      use(s);
      glBindVertexArray(vao);
      glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
      glfwSwapBuffers(window);
      glfwPollEvents();
    }

  free(s);
  glfwTerminate();
  return 0;
}


void framebuffer(GLFWwindow *window, GLint width, GLint height)
{
  glfwGetFramebufferSize(window,&width,&height );
  glViewport(0, 0, width, height);
}
