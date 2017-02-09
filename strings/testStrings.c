#include "MCLib.h"
#include <cutest.h>

char iszero = 0;
char isquestion = '?';

#define FIRSTSTR "first"
#define SECONDSTR "second"

char firstStr[] = FIRSTSTR;
char secondStr[] = SECONDSTR;
char firstsecondStr[] = FIRSTSTR SECONDSTR;

CUTEST(strleft){
	char *string1 = firstsecondStr;
	char *leftstr = MCLib_strleft(string1, strlen(firstStr));
	CuAssertStrEquals(tc, firstStr, leftstr);
	CuAssertIntEquals(tc, 0, leftstr[strlen(firstStr)]);
	MCLib_strfree(leftstr);
	leftstr = MCLib_strleft(string1, 100);
	CuAssertStrEquals(tc, string1, leftstr);
	CuAssertPtrNull(tc, MCLib_strleft(NULL, 5));
	CuAssertStrEquals(tc, "", MCLib_strleft(string1, 0));

	MCLib_strfree(leftstr);
}

CUTEST(strcat){
	char *string1 = firstStr;//[] = "first ";
	char *string2 = secondStr;//[] = "second";
	char *catstr = MCLib_strcat(string1, string2);
	CuAssertStrEquals(tc, firstsecondStr, catstr);
	CuAssertIntEquals(tc, 0, catstr[strlen(firstsecondStr)]);
	MCLib_strfree(catstr);
	catstr = MCLib_strcat(NULL, string2);
	CuAssertStrEquals(tc, string2, catstr);
	MCLib_strfree(catstr);
	catstr = MCLib_strcat(string1, NULL);
	CuAssertStrEquals(tc, string1, catstr);
	MCLib_strfree(catstr);
	catstr = MCLib_strcat(NULL, NULL);
	CuAssertPtrNull(tc, catstr);
	MCLib_strfree(catstr);
}

CUTEST(strfree){
	char *teststr = MCLib_stralloc(10);

	MCLib_strfree(teststr);
	CuAssertArrayElementsConstant(tc, teststr, &isquestion, sizeof(*teststr), 10);
	CuAssertIntEquals(tc, 0, teststr[10]);
	MCLib_strfree(teststr);
}

CUTEST(stralloc){
	char *teststr = MCLib_stralloc(10);
	CuAssertArrayElementsConstant(tc, teststr, &iszero, sizeof(*teststr), 11);
	MCLib_strfree(teststr);
	//check for overflow as there must be one more byte allocated (for the '\0') than specified
	CuAssertPtrNull(tc, MCLib_stralloc(UINT_MAX));
}

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
    CUTEST_ADD(strSuite, stralloc);
    //CUTEST_ADD(strSuite, strfree);
    CUTEST_ADD(strSuite, strcat);
    CUTEST_ADD(strSuite, strleft);
    return strSuite;
}

int main(void){
    CuSuite *strSuite = setupSuites();
    CuSuiteRun(strSuite);
    CuSuiteDetails(strSuite, stdout);
    CUSUITE_CLOSE(strSuite);

    return CuSuiteGetFailcount(strSuite);
}
