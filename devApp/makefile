#compiles testing application
CC=gcc
BITVRS=64
GFLAGS= -O3 -L../_bin/$(BITVRS) -std=c11 -Wall -DBMODE=$(BITVRS) -m$(BITVRS)
LIBS= -lm -lKNX_Library
SRC=Dev.c

all:
	$(CC) $(SRC) $(GFLAGS) $(LIBS) -o dev.exe

clean:
	rm -f *.o
