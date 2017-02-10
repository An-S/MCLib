#include "fileIO.h"

FILE *fileIO_openBinaryWrite(char *path, fileIO_ErrH_t *errH){
    char funcName[] = "fileIO_openBinaryWrite";

    FILE *file = fopen(path, "r");
    if (file) {
		int YesNoResult;

		fclose(file);
		YesNoResult = fileIO_callErrorHandler(fileIO_overwriteYNErrH, "File \"%s\" exists. ", path);
        if (EXIT_FAILURE == YesNoResult){
            fileIO_callErrorHandler(errH, "Cancelled Write");
            return NULL;
        }
	}
	file = fopen(path, "wb");
    if (!file) fileIO_callErrorHandler(errH, "openBinaryWrite_err, file:\"%s\"", path);
    return file;
}
