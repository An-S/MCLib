#include "MCLib_Range.h"

bool MCLib_chkRng(const void *val, const void *lb, const void *ub, MCLib_compFnc_t *cmp){
    return cmp(lb, val) && cmp(val, ub);
}

