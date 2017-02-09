#include "fileIO.h"

FILE *fileIO_openBinaryWrite(char *path, fileIO_ErrH_t *errH){
    FILE *file = fopen(path, "r");
    if (file) {
		int YesNoResult;

		fclose(file);
		YesNoResult = fileIO_callErrorHandler(errH, "File \"%s\" exists. ", path);
	}
	file = fopen(path, "wb");
    if (!file) fileIO_callErrorHandler(errH, "openBinarWrite_err, file:\"%s\"", path);
    return file;
}
