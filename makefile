#Compiles Library and test
KDK_VERSION = "\"0.2.0\""
UNITDIR = src devApp

#get OS
ifeq ($(shell uname), Linux)
	FixPath = $1
	PLATFORM = -D__LINUX
	LIB_EXT = .a
	EXEC_EXT = 
else
#Windows
	FixPath = $(subst /,\,$1)
	PLATFORM = -D__WINDOWS
	LIB_EXT = .a#.lib
	EXEC_EXT = .exe
endif

#Define common/global
CC = gcc
CC_STD = -std=c11

BITVRS 	= 64
DEBUG 	= true
EXPORT_PATH = ../_bin/$(BITVRS)/
CLEAN_TEXT = *.o *.a *.lib
INCLUDES = -Iheaders

COMMON 	= 	-DKDK_VERSION=$(KDK_VERSION) -DPLATFORM=$(PLATFORM) -Iheaders \
			-std=c11 -pedantic -lm -lpthread -m$(BITVRS) -Wall -g -rdynamic

#export to sub makes
export BITVRS
export DEBUG
export COMMON
export CC
export CC_STD
export EXPORT_PATH
export CLEAN_TEXT
export INCLUDES
export KDK_VERSION
export PLATFORM
export LIB_EXT
export EXEC_EXT
export OBJ_FILES

#do the thing
subdirs:
	for dir in $(UNITDIR); do \
	 $(MAKE) -C $$dir; \
	done

dev: devApp/dev.exe
	devApp/dev.exe

.PHONY: clean
clean:
	for dir in $(UNITDIR); do \
	 $(MAKE) clean -C $$dir; \
	done
	 rm -f $@ _bin/32/*.a
	 rm -f $@ _bin/64/*.a
	 rm -f $@ devApp/dev
