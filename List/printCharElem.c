#include "MCLib_List.h"

void *MCLib_printCharElem(char *format, void *elem){
    static char *myelem;

    //if pointer given remember it locally
    if ( !rememberPointer(elem, (void**)&myelem) ){
        //else use local pointer to print values
        printf(format, *myelem);
    }
    return myelem++;
}

