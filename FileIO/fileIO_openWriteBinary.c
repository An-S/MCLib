#include "fileIO.h"

FILE *fileIO_openBinaryWrite(char *path, fileIO_ErrH_t *errH, fileIO_ErrH_t *errH_FExisting){
    char funcName[] = "fileIO_openBinaryWrite";

    //if (overwriteMode == FILEIO_OVERWRITEMODE_PROMPTUSER){
    FILE *file = fopen(path, "r");
    if (file) {
        int YesNoResult;

        fclose(file);

        YesNoResult = fileIO_callErrorHandler(NULL, errH_FExisting, "File \"%s\" exists. ", path);
        if (EXIT_FAILURE == YesNoResult){
            fileIO_callErrorHandler(NULL, errH, "Cancelled Write");
            return NULL;
        }
    }
    file = fopen(path, "wb");
    if (!file) fileIO_callErrorHandler(NULL, errH, "openBinaryWrite_err, file:\"%s\"", path);
    return file;
}
