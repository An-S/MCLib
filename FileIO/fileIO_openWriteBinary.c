#include "fileIO.h"

FILE *fileIO_openBinaryWrite(char *path, fileIO_ErrH_t *errH){
    FILE *file = fopen(path, "wb");
    if (!file) fileIO_callErrorHandler(errH, "openBinaryWrite_err, file:\"%s\"", path);
    return file;
}
