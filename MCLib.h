#ifndef MCLIB_H_INCLUDED
#define MCLIB_H_INCLUDED

#include <stdheaders.h>
#include <cmacros.h>
#include "MallocWrapper/imalloc_internal.h"
#include "Range/MCLib_Range.h"
#include "List/MCLib_List.h"
#include "intmath/intmath.h"
#include "Comparison/comparison.h"
#include "constStdStr/MCLib_constStdStr.h"
#include "Strings/MCLib_Strings.h"
#include "Counter/Counter.h"
#include "TrigFunctions/MCLib_TrigFunctions.h"

//typedef char[8] mychar;
typedef char minWidthIntCharArray_t[INTFIELDWIDTH(sizeof(int))];
typedef char minWidthHIntCharArray_t[INTFIELDWIDTH(sizeof(short int))];
typedef char minWidthLIntCharArray_t[INTFIELDWIDTH(sizeof(long int))];

#endif // MCLIB_H_INCLUDED
