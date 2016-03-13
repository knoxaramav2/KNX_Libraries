#Compiles Library and test

SUBDIRS = src devApp

subdirs:
	for dir in $(SUBDIRS); do \
	 $(MAKE) -C $$dir; \
	done

rundev: devApp/dev.exe
	devApp/dev.exe