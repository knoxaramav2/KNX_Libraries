#compiles testing application
CC=gcc
BITVRS=64
GFLAGS= -O3 -L../_bin/$(BITVRS) -std=c11 -Wall -m$(BITVRS) -I ../headers
LIBS= -lm -lKNX_Library
SRC=Dev.c
BITMODE=-DBITMODE=$(BITVRS)

all:
	$(CC) $(SRC) $(GFLAGS) $(BITMODE) $(LIBS) -o dev.exe

clean:
	rm -f *.o
