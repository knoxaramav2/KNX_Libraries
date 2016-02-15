# Compiles KNX static library

CC=gcc
CFLAGS= -Wall -std=c11
SRC=KNX_Hash KNX_String
INCLUDES= ../headers
OUT=libKNX_Library.a
CLEANEXT = o a
BITVRS=64
EXPORT_PTH=../_bin/

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

.PHONY: all
all: $(OUT)

#.c.o:
$(SRC:=.o): $(SRC:=.c)
	$(CC) $(CFLAGS) $(OSMODE) $(PLATFORM) -c $< -o $@

$(OUT): $(SRC:=.o)
	ar rc $(EXPORT_PTH)/$(OUT) $(SRC:=.o)
	ranlib  $(EXPORT_PTH)/$(OUT)
#$(EXPORT_PTH)$(OUT)
dep:
		makedepend -- $(CFLAGS) -- $(INCLUDES) $(SRC)

.PHONY: clean
clean:
	rm -f $@ *.o
