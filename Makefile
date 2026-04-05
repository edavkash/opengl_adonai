CC=cc
CFLAGS = -ggdb -lglfw -lm -I/usr/include

all: window.o glad.o

window:
	$(CC) $(CFLAGS) -o $@ *.o

clean:
	rm -f *.o window
