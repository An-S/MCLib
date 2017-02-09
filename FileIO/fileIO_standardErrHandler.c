#include "fileIO.h"

void fileIO_stdErrH(char *format, va_list va){
    vfprintf(stderr, format, va);
    perror(NULL);
}

