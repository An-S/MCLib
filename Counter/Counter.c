
#include "Counter.h"

typedef int counterValue_t;

typedef struct{
	counterValue_t start;
	counterValue_t end;
	counterValue_t current;
	counterRunMode_t runmode;
} counter_t;

counter_t *MCLib_createCounter(counterValue_t start, counterValue_t end, counterRunMode_t runmode){
	counter_t *myCnt = calloc(sizeof(counter_t), 1);
	if (myCnt) {
		myCnt -> start = myCnt -> current = start;
		myCnt -> end = end;
		myCnt -> rundmode = runmode;
	}
	return myCnt;
}

counterValue_t MCLib_proceedCounter(counter_t *cnt){
	if (cnt->start < cnt->end){
		if (cnt->current < cnt->end){
			++cnt->current;
		}else{
			switch(cnt->runmode){
			case MCLIBCOUNTER_ONESHOT:
				break;
			case MCLIBCOUNTER_CONTINUOUES:
				cnt->current = cnt->start;
				break;
			case MCLIBCOUNTER_BOUNCE:
				{
					counterValue_t tmp = counter->start;
					cnt->start = cnt->end;
					cnt->end = tmp;
				}
			default: break;
			}
		}
	}else{
		if (cnt->current > cnt->end){
			--cnt->current;
		}else{
			switch(cnt->runmode){
			case MCLIBCOUNTER_ONESHOT:
				break;
			case MCLIBCOUNTER_CONTINUOUES:
				cnt->current = cnt->start;
				break;
			case MCLIBCOUNTER_BOUNCE:
				{
					counterValue_t tmp = counter->start;
					cnt->start = cnt->end;
					cnt->end = tmp;
				}
			default: break;
			}
		}
	}
};
