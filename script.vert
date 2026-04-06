#version 330

// layout(location = 0) in vec4 position;
// layout(location = 1) in vec4 color;

// smooth out vec4 theColor;

// void main() {
//   gl_Position = position;
//   theColor = color;
// }

// layout(location = 0) in vec3 position;
// void main() { gl_position = {position.x, position.y, position.z, 1.0}; }

layout(location = 0) in vec3 aPos;
void main() { gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); };
