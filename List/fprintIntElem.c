#include "MCLib_List.h"

void *MCLib_fprintIntElem(FILE *file, char *format, void *elem){
    static int *myelem;

    //if pointer given remember it locally
    if ( !rememberPointer(elem, (void**)&myelem) ){
        //else use local pointer to print values
        if (-1 == fprintf(file, format, *myelem) ){
            perror("Error outputting table elements");
        }
        return myelem++;
    }
    return NULL;
}

