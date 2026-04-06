CC=cc
CFLAGS = -I. -ggdb -lglfw -lm -I/usr/include

all: file.o triangle.o window.o glad.o

window:
	$(CC) $(CFLAGS) -o $@ glad.o window.o

triangle:
	$(CC) $(CFLAGS) -o $@ file.o glad.o triangle.o

clean:
	rm -f *.o window triangle
