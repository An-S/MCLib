#ifndef COUNTER_INTERNAL_H_INCLUDED
#define COUNTER_INTERNAL_H_INCLUDED

#include "counter.h"


typedef struct MCLib_counter_tag{
	MCLib_counterValue_t start;
	MCLib_counterValue_t end;
	MCLib_counterValue_t current;
	MCLib_counterRunMode_t runmode;
} MCLib_counter_t;

int MCLib_wrapCounter(MCLib_counter_t *cnt);
#endif // COUNTER_INTERNAL_H_INCLUDED
