#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Guess], [0.0], [ex@mail.ru])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([guess.c])
AC_CONFIG_HEADERS([config.h])

AC_ARG_ENABLE([destdir], 
              [AS_HELP_STRING([--destdir])],
              [destdir=$enableval],
              [destdir])

AM_CONDITIONAL([DESTDIR],  [test "x$destdir"])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
