#include "../MCLib.h"

/*void testfunc();
void testfunc(int a, int b){
}*/

/** \brief controls access to lists (1d arrays) with following possibilities
 *
 * \param op: INIT -> remember pointer to data
 * \param op: PRINT -> print all elements to stdout
 * \param op: GET -> get current element and proceed to next element
 * \return desired element
 *
 */

uint8_t FGV_ListElem_UINT8(FGVElem_OP op, ...){
    static uint8_t *ptr;
    va_list va;

    switch(op){
    case FGVElem_PRINT:
        printf("%d", *ptr++ );
        return *ptr;
    case FGVElem_INIT:
        va_start(va, op);
        ptr = (uint8_t*)va_arg(va, uint8_t*);
        return *ptr;
    case FGVElem_GET:
        return *ptr++;
    default:
        break;
    }
    return *ptr;
}

void *getuint8(void *list)
{
    uint8_t *list_local;

    //init local pointer to start of list, if argument given
    if (list){
        list_local = list;
        return 0;
    }
    return list_local++;
}
