#include <MCLib.h>
#include <cutest.h>
#include "counter_internal.h"

CUTEST(initTest){
    int start = 11, end = 27, runmode = MCLIBCOUNTER_ONESHOT;

    //create new counter
    MCLib_counter_t *cnt = MCLib_createCounter(start, end, runmode);
    //check proper initialization of struct elements
    CuAssertIntEquals(tc, start, cnt->start);
    CuAssertIntEquals(tc, start, cnt->current);
    CuAssertIntEquals(tc, end, cnt->end);
    CuAssertIntEquals(tc, runmode, cnt->runmode);
    MCLib_destroyCounter(cnt);
}

CUTEST(oneShotTest){
    int start = 11, end = 27, runmode = MCLIBCOUNTER_ONESHOT;
    int i;

    MCLib_counter_t *cnt = MCLib_createCounter(start, end, runmode);
    for (i = start; i < end; ++i){
        CuAssertIntEquals(tc, i+1, MCLib_proceedCounter(cnt));
    }
    CuAssertIntEquals(tc, end, MCLib_proceedCounter(cnt));
    CuAssertIntEquals(tc, end, MCLib_proceedCounter(cnt));
    CuAssertIntEquals(tc, end, MCLib_proceedCounter(cnt));
}

void setupSuites(void){
    CUSUITE_OPEN(cntSuite);
    CUTEST_ADD(cntSuite, initTest);
    CUTEST_ADD(cntSuite, oneShotTest);

    CuSuiteRun(cntSuite);
    CuSuiteDetails(cntSuite, stdout);
    CUSUITE_CLOSE(cntSuite);
}

int main(void){
    setupSuites();

    return EXIT_SUCCESS;
}
