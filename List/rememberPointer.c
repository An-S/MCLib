#include "MCLib_List.h"

void *rememberPointer(void *ptr, void **store){
    if (ptr){
        *store = ptr;
    }
    return ptr;
}

