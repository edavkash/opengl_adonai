CC=cc
CFLAGS = -I. -ggdb -lglfw -lm -I/usr/include

all: mesh.o shader.o shader_load.o triangle.o window.o glad.o

window:
	$(CC) $(CFLAGS) -o $@ glad.o window.o

triangle:
	$(CC) $(CFLAGS) -o $@ shader.o mesh.o shader_load.o glad.o triangle.o
clean:
	rm -f *.o window triangle
