
#include "MCLib_List.h"

uint16_t getuint16(void **word){
    uint16_t tWord = (uint16_t)(*(uint16_t*)*word);
    uint16_t **ptr = (uint16_t**)word;
    ++(*ptr);
    return tWord;
}
