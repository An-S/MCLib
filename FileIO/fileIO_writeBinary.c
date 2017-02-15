#include "fileIO.h"

int fileIO_writeBinary(char *path, void *buf, size_t N, fileIO_ErrH_t *errH, fileIO_ErrH_t *errH2){
    FILE *file=NULL;
    if (file = fileIO_openBinaryWrite(path, errH, errH2)){
        fwrite(buf, N, 1, file);
        if (ferror(file)){
            fileIO_callErrorHandler(NULL, errH, "writeBinary_err: \"%s\"", path);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

