
#include "Counter_internal.h"
#include <stdheaders.h>



MCLib_counter_t *MCLib_createCounter(MCLib_counterValue_t start,
                               MCLib_counterValue_t end, MCLib_counterRunMode_t runmode){
	MCLib_counter_t *myCnt = calloc(sizeof(MCLib_counter_t), 1);
	if (myCnt) {
        //access only, if myCnt not NULL
		myCnt -> start = myCnt -> current = start;
		myCnt -> end = end;
		myCnt -> runmode = runmode;
	}
	return myCnt; //NULL or valid ptr
}

int MCLib_destroyCounter(MCLib_counter_t *cnt){
    if (cnt) {
        free(cnt);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE; //failure if NULL ptr given
}

MCLib_counterValue_t MCLib_proceedCounter(MCLib_counter_t *cnt){
	if (cnt){
        //access only, if cnt not NULL
        if (cnt->start < cnt->end){
            if (cnt->current < cnt->end){
                ++cnt->current;
            }else{
                MCLib_wrapCounter(cnt);
            }
        }else{
            if (cnt->current > cnt->end){
                --cnt->current;
            }else{
                MCLib_wrapCounter(cnt);
            }
        }
        return cnt->current;
	}
	return 0; //cnt was NULL -> return error sentinal
};

int MCLib_wrapCounter(MCLib_counter_t *cnt){
    if (cnt){
        //access only, if cnt not NULL
        switch(cnt->runmode){
        //dependent on runmode, stop/reset/invert counter
        case MCLIBCOUNTER_ONESHOT:
            break;
        case MCLIBCOUNTER_CONTINUOUES:
            cnt->current = cnt->start;
            break;
        case MCLIBCOUNTER_BOUNCE:
            {
                MCLib_counterValue_t tmp = cnt->start;
                cnt->start = cnt->end;
                cnt->end = tmp;
            }
        default: return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE; //cnt was NULL -> return error
}
