#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([cs_fundamentals], [0.0.1], [julian.simioni@gmail.com])
AC_CONFIG_SRCDIR([.])
AC_CONFIG_HEADERS([src/config.h])

# Checks for programs.
AC_PROG_CC_C99
AM_INIT_AUTOMAKE

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h sys/time.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([gettimeofday])

AC_CONFIG_FILES([Makefile src/Makefile test/Makefile])
AC_OUTPUT
