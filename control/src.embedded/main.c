//#include <string>
#include <stdio.h>
#include <stdlib.h>

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

__asm__(".symver __wrap___isoc99_fscanf,__isoc99_sscanf@GLIBC_2.17");
#include "mpc.h"

#define __stack_chk_guard 0xBAAAAAAD;
//__asm__(".symver __stack_chk_guard,__stack_chk_guard@@GLIBC_2.17");






int main(){
    //__stack_chk_guard_setup();
    printf("Starting MPC module ... \n");

    mpc_init();
    mpc_run();
    mpc_hover();

    return 0;
}
