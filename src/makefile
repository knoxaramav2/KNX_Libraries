#compile KNX library
OUT = libKNX_Library$(LIB_EXT)

SRC = strutil.c hash.c tree.c filestr.c
DIRS := $(wildcard */.)
GARBAGE := $(foreach DIR, $(DIRS), $(DIR)/$(CLEAN_TEXT))

OBJ_FILES = $(SRC:.c=.o)
current_dir = $(shell pwd)

%.o : %.c
	$(CC) $(INCLUDES) $(COMMON) -c $<

$(EXPORT_PATH)$(OUT): $(OBJ_FILES)
	ar rcs $(EXPORT_PATH)$(OUT) $(OBJ_FILES)

.PHONY: clean
clean:
	rm -f $@ *.o
