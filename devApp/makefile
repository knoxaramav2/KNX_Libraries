#compiles testing application
GFLAGS= -O3 -I../src/headers
LIBS= -lm -L$(EXPORT_PATH) -lKNX_Library
SRC=Dev.c

all:
	$(CC) $(SRC) $(COMMON) $(GFLAGS) $(LIBS) -o dev.exe

clean:
	rm -f *.o
