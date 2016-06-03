#include "MCLib.h"
#include <cutest.h>

CUTEST(fieldwidth){
    char *format = "Nummer:%d";
    int nummer = 1000;
    char buffer[20];

    CuAssertIntEquals(tc, 0, MCLib_getFieldwidthFromFormatString(NULL));
    CuAssertIntEquals(tc, 4, MCLib_getFieldwidthFromFormatString("abcd"));
    snprintf(buffer, sizeof(buffer), format, nummer);
    CuAssertIntEquals(tc, strlen(buffer), MCLib_getFieldwidthFromFormatString(format, nummer));

}

CuSuite* setupSuites(void){
    CUSUITE_OPEN(strSuite);
    CUTEST_ADD(strSuite, fieldwidth);
    return strSuite;
}

int main(void){
    CuSuite *strSuite = setupSuites();
    CuSuiteRun(strSuite);
    CuSuiteDetails(strSuite, stdout);
    CUSUITE_CLOSE(strSuite);

    return CuSuiteGetFailcount(strSuite);
}
