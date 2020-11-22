GENERATORS = *.mo *.pot guess Makefile *.o *~ o.* *.a *.so *.txt autom4te.cache .deps *.m4 compile *.h* configure *.status COPYING depcomp INSTALL install-sh *.in missing stamp-h1 config.log ru
bin_PROGRAMS = guess
pkgdata_DATA=ru/LC_MESSAGES/guess.mo

ru/LC_MESSAGES/guess.mo: guess.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po:	messages.pot
	msgmerge -U $@ $<

messages.pot:	guess.pot guess.c
	xgettext -k_ -c guess.c -o messages.new.pot
	cp guess.pot messages.pot
	msgmerge -U messages.pot messages.new.pot

allclean:
	rm -rf $(GENERATORS)
	
gitclean: mainteiner-clean
	git clean -fd
