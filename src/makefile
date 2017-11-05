# Compiles KNX static library

CC=gcc
BITVRS=64
CFLAGS= -std=c11 -pedantic -Wall -m$(BITVRS) -DBITMODE=$(BITVRS)
LDFLAGS= -g
LIBS= -lm
SRC=KNX_String.c KNX_Hash.c KNX_File.c
OBJ=$(SRC:.c=.o)
INCLUDES= -I ../headers
OUT=libKNX_Library.a
CLEANEXT = o a
BITMODE=$(BITVRS)
EXPORT_PTH=../_bin/

EPATH_FULL=$(EXPORT_PTH)$(BITVRS)/$(OUT)

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

#all:
#	$(CC) $(CFLAGS) $(BITMODE) $(SRC) -o $(EPATH_FULL) $(PLATFORM)

%.o : %.c
	#$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@
	$(CC) $(INCLUDES) $(CFLAGS) -c $< $(LIBS)

$(EPATH_FULL): $(OBJ)
	ar rcs $(EPATH_FULL) $(OBJ)



.PHONY: clean
clean:
	rm -f $@ *.o
