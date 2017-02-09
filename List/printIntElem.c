#include "MCLib_List.h"

void *MCLib_printIntElem(char *format, void *elem){
    return MCLib_fprintIntElem(stdout, format, elem);
}

