#include "fileIO.h"

void fileIO_callErrorHandler(fileIO_ErrH_t *errH, char* format, ...){
    //protect calls agains NULL ptr
    if (errH){
        //forward parameter list to error handler
        va_list va;
        va_start(va, format);
        //call error handler
        errH(format, va);
        va_end(va);
    }
}




