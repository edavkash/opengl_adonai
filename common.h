#ifndef COMMON
#define COMMON

#define SIZE 512

// Header declaration for glad,glfw and other common library
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void error(const char *fmt, ...);
extern void callback_error(int desc, const char *warning);
extern void framebuffer(GLFWwindow *window, GLint width, GLint height);
extern char *read_file(const char *path);
extern char *load_shader_content(const char *pathname);
#endif
