#compile KNX library
OUT = libKNX_Library$(LIB_EXT)

SRC = string/string.c
DIRS := $(wildcard */.)
GARBAGE := $(foreach DIR, $(DIRS), $(DIR)/$(CLEAN_TEXT))

OBJ_FILES = $(SRC:.c=.o)
current_dir = $(shell pwd)

objects/%.o : %.c
	$(CC) $(INCLUDES) $(COMMON) -c $<

$(EXPORT_PATH)$(OUT): $(OBJ_FILES)
	ar rcs $(EXPORT_PATH)$(OUT) $(OBJ_FILES)

.PHONY: clean
clean:
	rm -rf $(GARBAGE)
	#rm -f $@ *.o
