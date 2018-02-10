#compiles testing application
GFLAGS= -I../src/headers
LIBS= -lm -L$(EXPORT_PATH) -lKNX_Library
SRC=Dev.c
O_SRC = $(SRC:.c=.o) #DELETE

all:
	$(CC) $(SRC) $(COMMON) $(GFLAGS) $(LIBS) -o dev.exe

.c.o:
	$(CC) $(COMMON) $(GFLAGS) -c -o $@ $<

dev.exe : $(O_SRC)
	$(CC) $(COMMON) $(GFLAGS) -o $@ $(O_SRC) $(LIBS)

clean:
	rm -f *.o
