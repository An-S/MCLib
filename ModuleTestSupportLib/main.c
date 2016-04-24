#include <stdio.h>
#include <stdlib.h>

#include <CuTest.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "ModuleTestSupportLib.h"

void test_TestSuccessMacro(CuTest *tc) {
	bool testresult = false;

	testresult = TESTSUCCESS(EXIT_SUCCESS);
	CuAssert(tc, "TESTSUCCESS macro did not return true on EXIT_SUCCESS", testresult);

	testresult = TESTSUCCESS(EXIT_FAILURE);
	CuAssert(tc, "TESTSUCCESS macro did not return false on EXIT_FAILURE", !testresult);
}

void test_TestFailureMacro(CuTest *tc) {
	bool testresult = false;

	testresult = TESTFAILURE(EXIT_SUCCESS);
	CuAssert(tc, "TESTFAILURE macro did not return false on EXIT_SUCCESS", !testresult);

	testresult = TESTFAILURE(EXIT_FAILURE);
	CuAssert(tc, "TESTFAILURE macro did not return true on EXIT_FAILURE", testresult);
}

void test_ReturnOKMacro(CuTest *tc) {
	int returnOK(void){
		RETURNOK;
	}//define local function
	CuAssertTrue(tc, EXIT_SUCCESS == returnOK());
}

void test_ReturnBadMacro(CuTest *tc) {
	int returnBAD(void){
		RETURNBAD;
	}
	CuAssertTrue(tc, EXIT_FAILURE == returnBAD());
}

void test_ConditionalReturnMacro(CuTest *tc) {
	int conditionalReturn(bool cond, int rettrue, int retfalse){
		CuAssert(tc, "true and false return value should be different", rettrue != retfalse);
		CONDITIONALRETURN(cond, rettrue);
		return retfalse;
	}

	int conditionalReturn2(bool cond, int rettrue, int retfalse){
		int dummy = rettrue -1;
		CuAssert(tc, "true and false return value should be different", rettrue != retfalse);
		CONDITIONALRETURN(cond, ++dummy);
		return retfalse;
	}//Tests side effect by ++ operator

	CuAssert(tc, "CONDITIONALRETURN did not return arg on true", 100 == conditionalReturn(true, 100, 200));
	CuAssert(tc, "CONDITIONALRETURN did return arg on false", 200 == conditionalReturn(false, 100, 200));
	CuAssert(tc, "CONDITIONALRETURN sideeffect error", 100 == conditionalReturn2(true, 100, 200));
}

void test_ReturnOnFailureMacro(CuTest *tc) {
	int returnOnFailure(int isfailure){
		RETURNONFAILURE(isfailure);
		return EXIT_SUCCESS;
	}
	CuAssert(tc, "RETURNONFAILURE did not return EXIT_FAILURE on EXIT_FAILURE", EXIT_FAILURE == returnOnFailure(EXIT_FAILURE));
	CuAssert(tc, "RETURNONFAILURE did return EXIT_FAILURE on EXIT_SUCCESS", EXIT_SUCCESS == returnOnFailure(EXIT_SUCCESS));
	CuAssert(tc, "RETURNONFAILURE did return EXIT_FAILURE on non EXIT_FAILURE", EXIT_SUCCESS == returnOnFailure(EXIT_SUCCESS));
}

CuSuite* CuTestGetSuite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, test_TestSuccessMacro);
	SUITE_ADD_TEST(suite, test_TestFailureMacro);
	SUITE_ADD_TEST(suite, test_ReturnOKMacro);
	SUITE_ADD_TEST(suite, test_ReturnBadMacro);
	SUITE_ADD_TEST(suite, test_ConditionalReturnMacro);
	SUITE_ADD_TEST(suite, test_ReturnOnFailureMacro);
	return suite;
}

void RunAllTests(void) {
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();

	CuSuiteAddSuite(suite, CuTestGetSuite());

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}

int main()
{
    RunAllTests();
    return 0;
}
