#include "fileIO.h"

int fileIO_stdErrH(char *format, va_list va){
    vfprintf(stderr, format, va);
    perror(NULL);
    return EXIT_SUCCESS;
}

