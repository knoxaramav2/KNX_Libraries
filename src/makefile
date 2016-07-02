# Compiles KNX static library

CC=gcc
CFLAGS= -std=c11 -pedantic -Wall
LDFLAGS= -g
LIBS= -lm
SRC=KNX_String.c KNX_Hash.c KNX_File.c KNX_Data.c
OBJ=$(SRC:.c=.o)
INCLUDES= -I../headers
OUT=libKNX_Library.a
CLEANEXT = o a
BITVRS=32
BITMODE=-DBMODE=$(BITVRS)
EXPORT_PTH=../_bin/

ifeq ($(BITVRS), 64)
EPATH_FULL=$(EXPORT_PTH)64/$(OUT)
else
EPATH_FULL=$(EXPORT_PTH)32/$(OUT)
endif


#configure for Linux and Windows
ifeq ($(shell uname), Linux)
	FixPath = $1
	PLATFORM = -D__LINUX
	OSMODE = -DBITMODE=$(BITVRS)
else
#Windows
	FixPath = $(subst /,\,$1)
	PLATFORM = -D__WINDOWS
	OSMODE = -DBITMODE=$(BITVRS)
endif


%.o : %.c
	#$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@
	$(CC) $(BITMODE) $(INCLUDES) $(CFLAGS) -c $< $(LIBS)

$(EPATH_FULL): $(OBJ)
	#ar rcs $(EPATH_FULL) $(OBJ)
	ar rcs $(EPATH_FULL) $(OBJ)


.PHONY: clean
clean:
	rm -f $@ *.o
