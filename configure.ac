AC_INIT([mcpat], [0.8_r274], [])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_SUBST([NTHREADS], [4])
AC_ARG_WITH(
             [nthreads],
             AC_HELP_STRING([--with-nthreads=NUM], [Number of threads to use for cacti (default: $NTHREADS).]),
             [
                NTHREADS=$withval;
             ]
)

AC_LANG([C++])

AC_PROG_CXX
AC_PROG_RANLIB

AC_CONFIG_FILES([
                 Makefile
                 cacti/Makefile
])

AC_OUTPUT
