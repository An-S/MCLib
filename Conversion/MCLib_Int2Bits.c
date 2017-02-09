#include <MCLib.h>

char *MCLib_Int2Bits(int data){
    return MCLib_Bytes2Bits(&data, sizeof(int));
}

