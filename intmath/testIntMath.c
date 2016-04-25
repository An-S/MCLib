#include <MCLib.h>
#include <cutest.h>

CUTEST(maxTest){
    int amax = 63, bmax = 16,a,b;
    char* str;
    //test combinations of positive, zero and negative numbers
    for (a = -amax; a<amax; a+=amax){
        for (b = -bmax; b<bmax; b+=bmax){
            if ( CuAssertIntEquals(tc, b<a?a:b, max(a,b)) ){
                CuFail_Msg(tc, str=CuStrFormat("failed at: %d, %d", a,b));
            };
        }
    }
    CuFree(str);
}

CUTEST(minTest){
    int amax = 63, bmax = 16,a,b;
    char* str;
    //test combinations of positive, zero and negative numbers
    for (a = -amax; a<amax; a+=amax){
        for (b = -bmax; b<bmax; b+=bmax){
            if ( CuAssertIntEquals(tc, b<a?b:a, min(a,b)) ){
                CuFail_Msg(tc, str=CuStrFormat("failed at: %d, %d", a,b));
            };
        }
    }
    CuFree(str);
}

CUTEST(gcdTest){
    int amax = 63, bmax = 16,a,b;
    char* str;
    //test combinations of positive, zero and negative numbers
    for (a = -amax; a<amax; a+=amax){
        for (b = -bmax; b<bmax; b+=bmax){
            if ( CuAssertIntEquals(tc, b<a?a:b, max(a,b)) ){
                CuFail_Msg(tc, str=CuStrFormat("failed at: %d, %d", a,b));
            };
        }
    }
    CuFree(str);
}

CUTEST(absdiffTest){
    int amax = 63, bmax = 16,a,b;
    char* str;
    //test combinations of positive, zero and negative numbers
    for (a = -amax; a<amax; a+=amax){
        for (b = -bmax; b<bmax; b+=bmax){
            if ( CuAssertIntEquals(tc, b<a?a:b, max(a,b)) ){
                CuFail_Msg(tc, str=CuStrFormat("failed at: %d, %d", a,b));
            };
        }
    }
    CuFree(str);
}

void setupSuites(void){
    CUSUITE_OPEN(intSuite);
    CUTEST_ADD(intSuite, maxTest);
    CUTEST_ADD(intSuite, minTest);
    CUTEST_ADD(intSuite, gcdTest);
    CUTEST_ADD(intSuite, absdiffTest);

    CuSuiteRun(intSuite);
    CuSuiteDetails(intSuite, stdout);
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
