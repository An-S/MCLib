#include "MCLib_List.h"

void *MCLib_printUInt16Elem(char *format, void *elem){
    static uint16_t *myelem;

    //if pointer given remember it locally
    if ( !rememberPointer(elem, (void**)&myelem) ){
        //else use local pointer to print values
        printf(format, *myelem);
        return myelem++;
    }
    return NULL;
}
