GENERATORS = *.mo *.pot guess Makefile *.o *~ o.* *.a *.so *.txt autom4te.cache .deps *.m4 compile  configure *.status COPYING depcomp INSTALL install-sh *.in missing stamp-h1 config.log ru

HELP2MAN = help2man 
bin_PROGRAMS = guess
pkgdata_DATA=ru/LC_MESSAGES/guess.mo guess.1


@DX_RULES@

all-local:	doxygen-doc

ru/LC_MESSAGES/guess.mo: guess.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po:	messages.pot
	msgmerge -U $@ $<

messages.pot:	guess.pot guess.c
	xgettext -k_ -c guess.c -o messages.new.pot
	cp guess.pot messages.pot
	msgmerge -U messages.pot messages.new.pot

%.1:	%
	-$(HELP2MAN) --no-info --output=$@ --name='@PACKAGE_NAME@' ./$<

allclean:
	rm -rf $(GENERATORS)
	
gitclean: mainteiner-clean
	git clean -fd
