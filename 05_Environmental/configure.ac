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
AC_CHECK_LIB([ncursesw], [initscr], [], AC_MSG_ERROR([Curses is needed]))
AC_CHECK_LIB([pcre2-8], [pcre2_compile_8], [], AC_MSG_ERROR([PCRE2 is needed]))

# Checks for header files.
AC_CHECK_HEADERS([string.h], [], AC_MSG_ERROR([No string.h]))
AC_CHECK_HEADER([ncurses.h], [], AC_MSG_ERROR([No ncurses.h]))


# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_ARG_WITH([UTF], AS_HELP_STRING([--without-UTF], [Without UTF-8]))

AS_IF([test "x$with_UTF" != "xno"], [AC_DEFINE(UTF, [], [with utf])])

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
