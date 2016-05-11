#include "MCLib.h"

bool MCLib_lessThan_Int(const void *a, const void *b){
    return (*(int*)a) < (*(int*)b);
}
