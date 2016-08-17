#ifndef MCLIB_LIST_H_INCLUDED
#define MCLIB_LIST_H_INCLUDED

#include "../MCLib.h"
#include <stdarg.h>

typedef enum {FGVElem_GET, FGVElem_PRINT, FGVElem_INIT } FGVElem_OP;
//typedef void FGV_ListElem_UINT8();
//typedef *FGVELemFnc FGVElemFnc_Ptr;
typedef void *printElemFnc_t(char *format, void* elem);
typedef void *fprintElemFnc_t(FILE *file, char *format, void* elem);
typedef void *getElementFnc_t(void* list);
typedef getElementFnc_t *getElementFnc_Ptr;

void *getuint8(void *bytelist);
//void *getuint16(void *wordlist);
void *MCLib_printIntElem(char *format, void *elem);
void *MCLib_printCharElem(char *format, void *elem);
void *MCLib_printStringElem(char *format, void *elem);
void *MCLib_printUInt8Elem(char *format, void *elem);
void *MCLib_printUInt16Elem(char *format, void *elem);
void *MCLib_fprintIntElem(FILE *file, char *format, void *elem);

int MCLib_printList(char* format, void *list, printElemFnc_t *printElemFnc, size_t n, size_t perLine);
int MCLib_fprintList(FILE *file, char* format, void *list, fprintElemFnc_t *fprintElemFnc, size_t n, size_t perLine);

//internal functions
void *rememberPointer(void *ptr, void **store);

#endif // MCLIB_LIST_H_INCLUDED
