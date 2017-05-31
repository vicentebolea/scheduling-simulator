# vim: foldmethod=marker
AC_INIT([SchedulerSimulator], 
    [0.0.1],
    [vicente.bolea@gmail.com], 
    [], [vicente.bolea.me])
AC_CONFIG_AUX_DIR([./.autotools_aux])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AM_SILENT_RULES([yes])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])

AC_PROG_CXX
AC_LANG([C++])

AC_TYPE_SIZE_T
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_HEADER_STDC
#AM_PATH_PYTHON([2.7])

# Compiled defined constants
AC_DEFINE([SCHEDULER_SIMULATOR_INPUT_LINE_LENGTH], [256], [line length of input file])

AC_OUTPUT
