#compiles testing application
CC=gcc
GFLAGS= -O3 -L../_bin/libKNX_Library -std=c11 -Wall
LIBS= -lm -L/Libs -L. Libs/libKNX_Library.a
SRC=Dev.c

all:
	$(CC) $(SRC) $(GFLAGS) -L../_bin -lKNX_Library -o dev.exe

clean:
	rm -f *.o
