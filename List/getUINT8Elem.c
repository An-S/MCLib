#include "..\MCLib.h"

void testfunc();
void testfunc(int a, int b){
}

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

uint16_t getuint8(void **byte)
{
    uint8_t tByte = (uint8_t)(*(uint8_t*)*byte);
    uint8_t **ptr = (uint8_t**)byte;
    ++(*ptr);
    return tByte;
}
