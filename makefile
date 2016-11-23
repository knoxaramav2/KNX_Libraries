#Compiles Library and test

SUBDIRS = src devApp

subdirs:
	for dir in $(SUBDIRS); do \
	 $(MAKE) -C $$dir; \
	done

dev: devApp/dev.exe
	devApp/dev.exe
