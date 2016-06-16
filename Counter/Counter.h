#ifndef COUNTER_H_INCLUDED
#define COUNTER_H_INCLUDED

typedef int MCLib_counterValue_t;
typedef struct MCLib_counter_tag MCLib_counter_t;
typedef enum {
	MCLIBCOUNTER_ONESHOT,
	MCLIBCOUNTER_CONTINUOUES,
	MCLIBCOUNTER_BOUNCE,
	MCLIBCOUNTER_ILLEGALMODE
} MCLib_counterRunMode_t;

//special error/message sentinals
//ten highest int values for ten extras
typedef enum {
	MCLIBCOUNTER_WASRESET=INT_MAX-10,
	MCLIBCOUNTER_STOPPED,
	MCLIBCOUNTER_HASBOUNCED,
	MCLIBCOUNTER_ERROR
} MCLib_counterError_t;

MCLib_counter_t *MCLib_createCounter(MCLib_counterValue_t start,
                               MCLib_counterValue_t end, MCLib_counterRunMode_t runmode);
int MCLib_destroyCounter(MCLib_counter_t *cnt);
MCLib_counterValue_t MCLib_proceedCounter(MCLib_counter_t *cnt);

#endif // COUNTER_H_INCLUDED
