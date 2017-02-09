#ifndef MCLIB_RANGE_H_INCLUDED
#define MCLIB_RANGE_H_INCLUDED

#include "../MCLib.h"

typedef bool MCLib_compFnc_t(const void *a, const void *b);

bool MCLib_chkIntRng(int val, int lowb, int upperb);
bool MCLib_chkRng(const void *val, const void *lb, const void *ub, MCLib_compFnc_t *cmp);

#endif // MCLIB_RANGE_H_INCLUDED
