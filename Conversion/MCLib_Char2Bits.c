#include <MCLib.h>

char *MCLib_Char2Bits(char data){
    return MCLib_Bytes2Bits((void*)&data, sizeof(char));
}


