#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Guess], [0.0], [ex@mail.ru])
AM_INIT_AUTOMAKE([foreign])
DX_INIT_DOXYGEN(guess)
AC_CONFIG_SRCDIR([guess.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

AC_CONFIG_FILES([Makefile
		 Doxyfile
		])

AC_OUTPUT

define(D, `date`)dnl
define(S, [\/\* COMMENT:: AC_PACKAGE_NAME, AC_PACKAGE_VERSION: D \*\/])dnl
define(STR, [1 s/^/S\n/;])dnl
define(insert, ["STR"])dnl

sed -i -s "[/^\/\* COMMENT::.*\*\//d;]" *.{c,h}
sed -i -s insert *.{c,h}

#sed -i -s SEDOPT *.{c,h}

