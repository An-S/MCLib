#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED

#include <stdheaders.h>
#include <ctype.h>

typedef int fileIO_ErrH_t(char* params, char* format, va_list va);
typedef struct fileIO_errHParams_tag{
    char * filename;
    uint8_t verbosity; //pass some numeric code to indicate desired verbosity of error output
} errHParams_t;

extern char fileIO_errH_SILENT[];

FILE *fileIO_openBinaryWrite(char *path, fileIO_ErrH_t *errH, fileIO_ErrH_t *errH_FExisting);
int fileIO_writeBinary(char *path, void *buf, size_t N, fileIO_ErrH_t *errH, fileIO_ErrH_t *errH_FExisting);
int fileIO_callErrorHandler(char *params, fileIO_ErrH_t *errH, char* format, ...);
int fileIO_stdErrH(char *params, char *format, va_list va);
int fileIO_YNErrH(char *params, char *format, va_list va);
int fileIO_overwriteYNErrH(char *params, char *format, va_list va);

#endif // FILEIO_H_INCLUDED
