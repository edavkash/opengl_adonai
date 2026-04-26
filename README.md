# Learning OpenGL

This repository contains my experiments while learning modern OpenGL in C.

The goal of this project is to understand how OpenGL works at a low level while building small programs from scratch. The code focuses on simplicity and learning rather than building a full graphics engine.

## Technologies

* C
* OpenGL
* GLFW
* GLAD

GLFW is used for window creation and input handling, while GLAD loads the OpenGL function pointers.

## Goals

Some things I want to understand while working on this project:

* Creating windows and OpenGL contexts
* Rendering simple graphics
* Working with shaders
* Understanding the OpenGL pipeline
* Managing buffers and vertex data
* Building a small rendering framework

## Structure

The project is kept simple:

```
window.c
glad.c
common.h
```

## NOTE
As the project grows the program will include other program 

More modules may be added as the project grows.

## Building

The program requires:

* OpenGL
* GLFW
* GLAD (`link below under sources`)
* A C compiler (gcc/clang)

## Example build command:

Quick demo 

```
make -k
make window
``
or 
``
make -k 
make triangle
```

Main program 

``
make build 
``

## Notes

This project is mainly for learning and experimentation. The code may change frequently as new concepts are explored.

## Sources
    - wiki:https://wikis.khronos.org/opengl/Main_Page
	- pdf: https://learnopengl.com/book/book_pdf.pdf
	- glfw: https://www.glfw.org/
	- github: https://github.com/glfw/glfw \
       https://github.com/JoeyDeVries/LearnOpenGL/tree/master \
	   https://github.com/capnramses/antons_opengl_tutorials_book/blob/master/41_shader_hot_reload/main.c
	- glad: https://glad.dav1d.de/
	- cheatsheet: https://www.glfw.org/GLFWReference27.pdf
	- wikipedia: https://en.wikipedia.org/wiki/OpenGL_Shading_Language\
		https://en.wikipedia.org/wiki/Cartesian_coordinate_system
	- html: https://nicolbolas.github.io/oldtut/index.html
	- manual:https://gcc.gnu.org/onlinedocs/cpp/Concatenation.html\
     	https://gcc.gnu.org/onlinedocs/cpp/Stringizing.html
	- glsl: https://wikis.khronos.org/opengl/Layout_Qualifier_(GLSL)
    - vbo: https://en.wikipedia.org/wiki/Vertex_buffer_object
	- GLAD: https://glad.dav1d.de/
	- Blog: https://moderncprogramming.com/loading-a-glsl-shader-from-file-in-opengl-using-pure-c/
