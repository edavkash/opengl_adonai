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

More modules may be added as the project grows.

## Building

The program requires:

* OpenGL
* GLFW
* GLAD
* A C compiler (gcc/clang)

Example build command:

```
gcc src/main.c -lglfw -lGL -ldl -o opengl
```

## Notes

This project is mainly for learning and experimentation. The code may change frequently as new concepts are explored.
