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

bool testFnc_max(CuTest *tc, int a, int b){
    return CuAssertIntEquals(tc, b<a?a:b, max(a,b));
}

bool testFnc_min(CuTest *tc, int a, int b){
    return CuAssertIntEquals(tc, b<a?b:a, min(a,b));
}

bool testFnc_absDiff(CuTest *tc, int a, int b){
    unsigned int diff = absdiff(a,b);
    printf(" Diff: %u",diff);
    return CuAssertIntEquals(tc, a>b?a-b:b-a, diff);
}

CUTEST(maxTest){
    forEachTwoIntMinZeroMax(tc, testFnc_max);
}

CUTEST(minTest){
    forEachTwoIntMinZeroMax(tc, testFnc_min);
}

CUTEST(gcdTest){
    int a,b,_gcd,_lcm;

    _gcd=gcd(a=10,b=5);
    _lcm=lcm(a,b);
    printf("Testing gcd(%ld) and lcm(%ld) of %d and %d\n", _gcd, _lcm, a,b);
    _gcd=gcd(a=-768,b=334);
    _lcm=lcm(a,b);
    printf("Testing gcd(%ld) and lcm(%ld) of %d and %d\n", _gcd, _lcm, a,b);
    _gcd=gcd(a=12345676,b=-345456);
    _lcm=lcm(a,b);
    printf("Testing gcd(%ld) and lcm(%ld) of %d and %d\n", _gcd, _lcm, a,b);

    CuAssertIntEquals(tc,abs(a*b),_gcd*_lcm);
    //CuFree(str);
}

CUTEST(absdiffTest){
    forEachTwoIntMinZeroMax(tc, testFnc_absDiff);
}

void setupSuites(void){
    CUSUITE_OPEN(intSuite);
    CUTEST_ADD(intSuite, maxTest);
    CUTEST_ADD(intSuite, minTest);
    CUTEST_ADD(intSuite, gcdTest);
    CUTEST_ADD(intSuite, absdiffTest);

    CuSuiteRun(intSuite);
    CuSuiteDetails(intSuite, stdout);
    CUSUITE_CLOSE(intSuite);
}

int main(void){
    int a=18, b=34, c=-10;
    //c=lcd(a,b);
    setupSuites();
    printf("max from %d and %d = %d\n", a,b,max(a,b));
    printf("min from %d and %d = %d\n", a,b,min(a,b));
    printf("gcd of %d and %d = %d", a,b,gcd(a,b));
    printf("absdiff of %d and %d = %d", a,b,absdiff(c,b));
    return EXIT_SUCCESS;
}
