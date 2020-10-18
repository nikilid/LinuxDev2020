GENERATES = regscanning Makefile *.o *~ o.* *.a *.so *.txt autom4te.cache .deps *.m4 compile *.h* configure *.status COPYING depcomp INSTALL install-sh *.in missing stamp-h1 config.log

bin_PROGRAMS = regscanning
regscanning_SOURCES = Window.c pcredemo.c

gitclean:
	git clean -fd

allclean:
	rm -rf $(GENERATES)
	
