#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Buffer generator], [0.0.0], [lidanikiforova@mail.ru])
AM_INIT_AUTOMAKE([foreign])
PKG_CHECK_MODULES([CHECK], [check])
LT_INIT([disable-static])

AC_CONFIG_MACRO_DIRS([src])
ACLOCAL_AMFLAGS = -I src
AC_CONFIG_SRCDIR([src/libbuf.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stddef.h stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC

AC_CONFIG_FILES([Makefile
                 src/Makefile tests/Makefile])
AC_OUTPUT
