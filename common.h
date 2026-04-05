#ifndef COMMON
#define COMMON

#include <glad/glad.h>
#include <GLFW/glfw3.h>

extern void error(const char *fmt, ...);
extern void callback_error(int desc, const char *warning);
extern void framebuffer(GLFWwindow *window,GLint width, GLint height);
#endif
