#include "imalloc_internal.h"

#define E(x,y,z) y
char* imalloc_StrArrayTypes[IMALLOC_ARRAYTYPES_COUNT] = {IMALLOC_ARRAYTYPES};
#undef E

#define E(x,y,z) z
uint8_t imalloc_ElementSizeArrayTypes[IMALLOC_ARRAYTYPES_COUNT] = {IMALLOC_ARRAYTYPES};
#undef E
