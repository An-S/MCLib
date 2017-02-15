#include "fileIO.h"

int fileIO_callErrorHandler(char *params, fileIO_ErrH_t *errH, char* format, ...){
    //protect calls agains NULL ptr
    if (errH){
		int result;
        //forward parameter list to error handler
        va_list va;
        va_start(va, format);
        //call error handler
        result = errH(params, format, va);
        va_end(va);
        return result;
    }
}




