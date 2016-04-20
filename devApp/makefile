#compiles testing application
CC=gcc
GFLAGS= -O3 -L../_bin/libKNX_Library -std=c11 -Wall
LIBS= -lm -L/Libs -L. Libs/libKNX_Library.a
BITVRS=64
BITMODE=-DBMODE=$(BITVRS)
SRC=Dev.c
LIBDIR=../_bin/

ifeq ($(BITVRS), 64)
LIBPATH = $(LIBDIR)64/
else
LIBPATH = $(LIBDIR)32/
endif

all:
	$(CC) $(SRC) $(GFLAGS) $(BMODE) -L$(LIBPATH) -lKNX_Library -o dev.exe

clean:
	rm -f *.o
