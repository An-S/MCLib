#include <MCLib.h>
#include <cutest.h>

int toggleIntMinZeroMax(int n){
    switch (n){
    case INT_MIN:
        return 0;
    case 0:
        return INT_MAX;
    default:
        return INT_MIN;
    }
}

void printIntTestPair(int a, int b){
    printf("testing inputs: %d, %d\n", a, b);
}

bool commonTwoIntTestFunction(CuTest *tc, unsigned long int (*fnc)(int, int),
                              unsigned long int line, int a, int b, unsigned long int expected){
    unsigned long int val = fnc(a,b);
    bool result;
    printIntTestPair(a,b);
    printf("->result: %u\n", val);
    result = CuAssertIntEquals(tc, expected, val);
    if (result){
        CuTestAppendMessage(tc, "\nTest failed: %s(%lu), using input values %d, %d",__FILE__, line, a, b);
    }

    return result;

}


char *formatFailedMsg(const char* id, int a, int b){
    char *str=CuStrFormat("%s failed on %d, %d ",id,a,b);
    return str;
}

/** \brief provides for loops to call test functions with each combination of INT_MIN, 0, INT_MAX
 *
 * \param test case from which function was called
 * \param pointer to test function
 * \return test successful?
 *
 */
bool forEachTwoIntMinZeroMax(CuTest *tc, bool (*testFnc)(CuTest *, int, int)){
    int int_vals[] = {INT_MIN, 0, INT_MAX};
    int *a,*b;
    putchar('\n');
    for (a = int_vals; a!=(int_vals+ELEMCNT(int_vals)); ++a){
        for (b = int_vals; b!=(int_vals+ELEMCNT(int_vals)); ++b){
            printf("testing input values %d, %d", *a,*b);
            if (testFnc(tc,*a,*b)) return true;
            putchar('\n');
        }
    }
    return false;
}


/*******
    Test function for testing max function
********/
bool testFnc_max(CuTest *tc, int a, int b){
    return CuAssertIntEquals(tc, b<a?a:b, max(a,b));
}

/*******
    Test function for testing min function
********/
bool testFnc_min(CuTest *tc, int a, int b){
    return CuAssertIntEquals(tc, b<a?b:a, min(a,b));
}

/*******
    Test function for testing diff function
********/
bool testFnc_absDiff(CuTest *tc, int a, int b){
    unsigned int diff = absdiff(a,b);
    printf(" Diff: %u",diff);
    return CuAssertIntEquals(tc, a>b?a-b:b-a, diff);
}

/*******
    Test case which calls test loop with test function for max(.,.)
********/
CUTEST(maxTest){
    forEachTwoIntMinZeroMax(tc, testFnc_max);
}

/*******
    Test case which calls test loop with test function for min(.,.)
********/
CUTEST(minTest){
    forEachTwoIntMinZeroMax(tc, testFnc_min);
}

bool testFncGcd(CuTest *tc, unsigned long int line, int a, int b, unsigned long int expected){
    //return commonTwoIntTestFunction(tc, gcd, a, b, expected);

    unsigned long int _gcd = gcd(a,b);
    bool result;
    printIntTestPair(a,b);
    printf("->result: %u\n", _gcd);
    result = CuAssertIntEquals(tc, expected, _gcd);
    if (result){
        CuTestAppendMessage(tc, "\nTest failed: %s(%lu), using input values %d, %d",__FILE__, line, a, b);
    }

    return result;
}
/*******
    Test case for gcd(.,.)
********/
CUTEST(gcdTest){
    //int a,b,_gcd,_lcm;

    //test some known values
    testFncGcd(tc, __LINE__, 0,0,0); // -> mostly defined as beeing zero!
    testFncGcd(tc, __LINE__, 1,1,1); // one of a or b eq 1 -> gcd = 1
    testFncGcd(tc, __LINE__, 2,1,1);
    testFncGcd(tc, __LINE__, 1563,0,1563); //one of a or b eq zero -> gcd = max(a,b)
    testFncGcd(tc, __LINE__, 0,987467,987467);
    //test primes
    testFncGcd(tc, __LINE__, 23,17,1); //gcd of two prime numbers should be 1
    testFncGcd(tc, __LINE__, 47,29,1);
    //test simple cases
    testFncGcd(tc, __LINE__, 10,5,5);
    testFncGcd(tc, __LINE__, -10,5,5);
    testFncGcd(tc, __LINE__, 36, 16, 4);
    testFncGcd(tc, __LINE__, -768, 334, 2); //expected value taken from wolfram alpha
    //test bigger numbers
    testFncGcd(tc, __LINE__, 5*7*7*3*3*3*11, 13*17*3*7*7*7*2, 7*7*3);//expected value contains the primefactors with lower occurence
    testFncGcd(tc, __LINE__, 12345676,-345456, 4); //expected value taken from wolfram alpha

   //CuAssertIntEquals(tc, UINT_MAX, )

    //testFncGcd(tc, INT_MIN,INT_MAX, 4);
    //_gcd=gcd(a=12345676,b=-345456);
    //_lcm=lcm(a,b);
    //printf("Testing gcd(%ld) and lcm(%ld) of %d and %d\n", _gcd, _lcm, a,b);

    //
    //CuAssertIntEquals(tc,INT_MAX,_gcd*_lcm);
    //CuFree(str);
}

CUTEST(absdiffTest){
    forEachTwoIntMinZeroMax(tc, testFnc_absDiff);
}

/*bool testFnc_lcm(CuTest *tc, int a, int b){

}*/

CUTEST(lcmTest){
    //forEachTwoIntMinZeroMax(tc, testFnc_lcm);

    //test some simple small numbers
    CuAssertIntEquals(tc, 0,lcm(0,0));
    CuAssertIntEquals(tc, 0,lcm(1,0));
    CuAssertIntEquals(tc, 0,lcm(-1,0));
    CuAssertIntEquals(tc, 0,lcm(0,1));
    CuAssertIntEquals(tc, 2,lcm(1,2));
    CuAssertIntEquals(tc, 2,lcm(2,2));
    CuAssertIntEquals(tc, 2,lcm(2,-2));
    CuAssertIntEquals(tc, 3,lcm(3,3));
    CuAssertIntEquals(tc, 6,lcm(2,3));
    CuAssertIntEquals(tc, 12,lcm(3,4));
    CuAssertIntEquals(tc, 20,lcm(5,4));

    //test primes
    CuAssertIntEquals(tc, 5*7,lcm(5,7));
    CuAssertIntEquals(tc, 11*13,lcm(11,13));
    CuAssertIntEquals(tc, 17*19,lcm(17,19));
    CuAssertIntEquals(tc, 23*29,lcm(23,29));
    //test negative numbers
    CuAssertIntEquals(tc, 5*7,lcm(-5,7));
    CuAssertIntEquals(tc, 11*13,lcm(11,-13));
    CuAssertIntEquals(tc, 17*19,lcm(-17,19));
    CuAssertIntEquals(tc, 23*29,lcm(23,-29));

    //test larger numbers
    CuAssertIntEquals(tc, 3*5*5*7*7*11*11*11*13,lcm(3*7*7*5*5*11*11*11,5*7*11*11*13));
    CuAssertIntEquals(tc, 11*11*19*31*31*37,lcm(11*11*31*31,-19*37));
    CuAssertIntEquals(tc, 157*163,lcm(157,-163));//primes
    CuAssertIntEquals(tc, 1039*1049,lcm(1039,1049));//primes
    //test if overflow is treated correctly by returning ULONG_MAX
    CuAssertIntEquals(tc, ULONG_MAX,lcm(INT_MAX,INT_MAX-1));
}

void setupSuites(void){
    CUSUITE_OPEN(intSuite);
    CUTEST_ADD(intSuite, maxTest);
    CUTEST_ADD(intSuite, minTest);
    CUTEST_ADD(intSuite, gcdTest);
    CUTEST_ADD(intSuite, lcmTest);
    CUTEST_ADD(intSuite, absdiffTest);

    CuSuiteRun(intSuite);
    CuSuiteDetails(intSuite, stdout);
    CUSUITE_CLOSE(intSuite);
}

int main(void){
    setupSuites();

    return EXIT_SUCCESS;
}
