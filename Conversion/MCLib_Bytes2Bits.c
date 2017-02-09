#include <MCLib.h>

char *MCLib_Bytes2Bits(void *data, size_t n){
    char *bits = MCLib_stralloc(8*n); //Each byte consists of 8 bits
    size_t byteNo, bitNo;
    uint8_t mask;

    for (byteNo = n; byteNo > 0; --byteNo){
        mask = 128;
        for (bitNo = 8; bitNo > 0; --bitNo){
            bits[(n-byteNo)*8+(8-bitNo)] = ((uint8_t*)data)[byteNo]&mask?'1':'0';
            mask >>= 1;
        }
    }
    return bits;
}
