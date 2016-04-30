#ifndef MCLIB_LIST_H_INCLUDED
#define MCLIB_LIST_H_INCLUDED

#include "..\MCLib.h"
#include <stdarg.h>

typedef enum {FGVElem_GET, FGVElem_PRINT, FGVElem_INIT } FGVElem_OP;
//typedef void FGV_ListElem_UINT8();
//typedef *FGVELemFnc FGVElemFnc_Ptr;
typedef uint16_t getElementFnc_t(void** elem);
typedef getElementFnc_t *getElementFnc_Ptr;

uint16_t getuint8(void **byte);
uint16_t getuint16(void **word);

//int printList(char* format, void *list, getElementFnc_Ptr getElem, size_t n, size_t perLine);


#endif // MCLIB_LIST_H_INCLUDED
