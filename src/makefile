# Compiles KNX static library

CC=gcc
CFLAGS= -Wall -std=c11
SRC=KNX_Hash KNX_String
INCLUDES= -I.
OUT=KNX_Library
CLEANEXT = o a
BITVRS=64

#detect OS
#System root is defined on windows but not linux
ifdef SYSTEMROOT
	RM = del/Q
	FixPath = $(subst /,\,$1)
	PLATFORM = __WINDOWS
	OSMODE = -DBITMODE$(BITVRS)
	EXPORT_PTH=../Windows/$(BITVRS)bit
else
	ifeq ($(shell uname), Linux)
		RM= rm -f
		FixPath = $1
		PLATFORM = __LINUX
		OSMODE = -DBITMODE$(BITVRS)
		EXPORT_PTH=../Linux/$(BITVRS)bit
	endif
endif

.PHONY: all
all: $(OUT)

.c.o:
	$(CC) $(INCLUDES) $(CFLAGS) $(OSMODE) $(PLATFORM) -c $< -o $@

$(OUT): $(SRC:=.o)
	ar rcs $(OUT) $(SRC:=.o)


dep:
		makedepend -- $(CFLAGS) -- $(INCLUDES) $(SRC)

.PHONY: clean
clean:
	$(RM) *.o
