# vim: foldmethod=marker
AC_INIT([Scheduling-Simulator], 
    [0.0.2],
    [vicente.bolea@gmail.com], 
    [], [vicentebolea.me])
AC_CONFIG_AUX_DIR([./.autotools_aux])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AM_SILENT_RULES([yes])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])

AC_LANG([C++])
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB

# Checks for header files.
AC_CHECK_HEADERS([string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_UINT32_T
AC_HEADER_STDC
#AM_PATH_PYTHON([2.7])

# Compiled defined constants
AC_DEFINE([SCHEDULER_SIMULATOR_INPUT_LINE_LENGTH], [256], [line length of input file])
AC_DEFINE([SJF_IWYOO_INPUT_FIX], [1], [Fixes Iwyoo input style])

AC_OUTPUT
