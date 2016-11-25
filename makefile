#Compiles Library and test

SUBDIRS = src devApp

BITVRS=64

export BITVRS

subdirs:
	for dir in $(SUBDIRS); do \
	 $(MAKE) -C $$dir; \
	done

dev: devApp/dev.exe
	devApp/dev.exe

.PHONY: clean
clean:
	for dir in $(SUBDIRS); do \
	 $(MAKE) clean -C $$dir; \
	done
	 rm -f $@ _bin/32/*.a
	 rm -f $@ _bin/64/*.a
	 rm -f $@ devApp/dev
