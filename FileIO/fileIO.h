#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED

#include <stdheaders.h>
#include <ctype.h>

typedef int fileIO_ErrH_t(char* format, va_list va);

FILE *fileIO_openBinaryWrite(char *path, fileIO_ErrH_t *errH);
int fileIO_writeBinary(char *path, void *buf, size_t N, fileIO_ErrH_t *errH);
int fileIO_callErrorHandler(fileIO_ErrH_t *errH, char* format, ...);
int fileIO_stdErrH(char *format, va_list va);
int fileIO_YNErrH(char *format, va_list va);

#endif // FILEIO_H_INCLUDED
