#include "MCLib.h"

bool MCLib_lessThan_Int(void *a, void *b){
    return (*(int*)a) < (*(int*)b);
}
