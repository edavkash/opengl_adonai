#ifndef COMMON
#define COMMON

#define SIZE 512

// Library declaration for glad and glfw
#include <glad/glad.h>
#include <GLFW/glfw3.h>

extern void error(const char *fmt, ...);
extern void callback_error(int desc, const char *warning);
extern void framebuffer(GLFWwindow *window, GLint width, GLint height);
extern char *read_file(const char *path);
#endif
