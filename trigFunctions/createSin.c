#include "MCLib_trigFunctions.h"

MCLib_sintable_t *MCLib_createSin(size_t len, MCLib_sinelem_t min, MCLib_sinelem_t max, size_t N){
    size_t i;
    MCLib_sintable_t *sindata = malloc(sizeof(MCLib_sinparameters_t)+len*N*sizeof(MCLib_sinelem_t));
    if (sindata){
        for (i=0; i<N*len; ++i){
            sindata->sintable[i] = round((min+max+(max-min-0.5)*sin(2*M_PI*i/len))/2);
        }
        sindata->max = max;
        sindata->min = min;
        sindata->len = len;
        sindata->size = N*len;
    }
    return sindata;
}

int MCLib_destroySin(MCLib_sintable_t *sintable){
    if (!sintable){
        return EXIT_FAILURE;
    }
    free(sintable);
    return EXIT_SUCCESS;
}

