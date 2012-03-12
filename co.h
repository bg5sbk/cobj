#ifndef CO_H
#define CO_H

/* ISO C99 */
#include <assert.h>
#include <complex.h>
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>

/* POSIX */
#include <unistd.h>
#include <fcntl.h>

#include "usage.h"
#include "wrapper.h"

typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned char uchar;

/* Helper Functions */
static inline ssize_t
xread(int fd, void *buf, size_t len)
{
    ssize_t nr;

    while (1) {
        nr = read(fd, buf, len);
        if ((nr < 0) && (errno == EAGAIN || errno == EINTR))
            continue;
        return nr;
    }
}

static inline ssize_t
xwrite(int fd, const void *buf, size_t len)
{
    ssize_t nr;

    while (1) {
        nr = write(fd, buf, len);
        if ((nr < 0) && (errno == EAGAIN || errno == EINTR))
            continue;
        return nr;
    }
}

#endif
