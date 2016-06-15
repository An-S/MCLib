#ifndef MCLIB_H_INCLUDED
#define MCLIB_H_INCLUDED

#include <stdheaders.h>
#include <cmacros.h>
#include "MallocWrapper/imalloc_internal.h"
#include "range/MCLib_range.h"
#include "list/MCLib_List.h"
#include "intmath/intmath.h"
#include "comparison/comparison.h"
#include "constStdStr/MCLib_constStdStr.h"
#include "strings/MCLib_strings.h"
//typedef char[8] mychar;
typedef char minWidthIntCharArray_t[INTFIELDWIDTH(sizeof(int))];
typedef char minWidthHIntCharArray_t[INTFIELDWIDTH(sizeof(short int))];
typedef char minWidthLIntCharArray_t[INTFIELDWIDTH(sizeof(long int))];

#endif // MCLIB_H_INCLUDED
