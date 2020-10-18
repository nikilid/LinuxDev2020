#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Regular scanning], [0.0], [lidanikiforova@mail.ru])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([Window.c])
AC_CONFIG_HEADERS([config.h])


# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([ncursesw], [initscr])
AC_CHECK_LIB([prce2], [pcre2_match])

# Checks for header files.
AC_CHECK_HEADERS([string.h])
AC_CHECK_HEADER([ncurses.h])
AC_CHECK_HEADER([pcre2.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
