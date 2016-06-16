#ifndef TRIGFUNCTIONS_H_INCLUDED
#define TRIGFUNCTIONS_H_INCLUDED

#include <mclib.h>
#include <math.h>

typedef int MCLib_sinelem_t;
typedef struct{
    size_t len;
    MCLib_sinelem_t min;
    MCLib_sinelem_t max;
} MCLib_sinparameters_t;

typedef struct {
    MCLib_sinparameters_t; //anonymous struct to be able to calculate size of sintable_t
                    //and swallow one malloc
    MCLib_sinelem_t sintable[];
} MCLib_sintable_t;


MCLib_sintable_t *MCLib_createSin(size_t len, MCLib_sinelem_t min, MCLib_sinelem_t max);
int MCLib_destroySin(MCLib_sintable_t  *sintable);

#endif // TRIGFUNCTIONS_H_INCLUDED
