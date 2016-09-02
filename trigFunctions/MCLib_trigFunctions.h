#ifndef TRIGFUNCTIONS_H_INCLUDED
#define TRIGFUNCTIONS_H_INCLUDED

#include <mclib.h>
#include <math.h>

typedef int MCLib_sinelem_t;
typedef struct{
    size_t len;
    size_t size;
    MCLib_sinelem_t min;
    MCLib_sinelem_t max;
} MCLib_sinparameters_t;

typedef struct {
    MCLib_sinparameters_t; //anonymous struct to be able to calculate size of sintable_t
                    //and swallow one malloc
    MCLib_sinelem_t sintable[];
} MCLib_sintable_t;


/** \brief calculates sintable with specified min, max and length. The parameter N specifies how many times
 *          the sin is repeated
 * \param MCLib_sinelem_t min = minimum value of sintable entries
 * \param MCLib_sinelem_t max = maximum value of sintable entries
 * \param size_t len = length of one period in bytes
 * \param size_t N = number of repetitions
 * \return MCLib_sintable_t * = pointer to sinus table data structure
 *
 */
MCLib_sintable_t *MCLib_createSin(size_t len, MCLib_sinelem_t min, MCLib_sinelem_t max, size_t N);

/** \brief destoys sinus table which was allocated and calculated by MCLib_createSin
 * \param MCLib_sintable_t * = pointer to sinus table data structure
 * \return int = success or failure
 *
 */
int MCLib_destroySin(MCLib_sintable_t  *sintable);

#endif // TRIGFUNCTIONS_H_INCLUDED
