#include <stdio.h>
#include <stdarg.h>
/* Define a wrapper function for __isoc99_fscanf that calls fscanf */
int __wrap___isoc99_fscanf(FILE *stream, const char *format, ...)
{
    va_list args;
    int ret;

    va_start(args, format);
    ret = vfscanf(stream, format, args);
    va_end(args);

    return ret;
}
