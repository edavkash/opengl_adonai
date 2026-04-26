CC=cc
INCLUDE = include/
GL = gl
CFLAGS = -I$(INCLUDE) -ggdb -lglfw -lm -I/usr/include

all:
	$(CC) $(CFLAGS) -c shader_load.c glad.c main.c \
	$(GL)/mesh.c $(GL)/shader.c $(GL)/texture.c

build:
	$(CC) $(CFLAGS) -o a.out *.o 

window:
	$(CC) $(CFLAGS) -o $@.out glad.o window.o

triangle:
	$(CC) $(CFLAGS) -o $@.out shader.o mesh.o shader_load.o glad.o triangle.o
clean:
	rm -f *.o *.out
