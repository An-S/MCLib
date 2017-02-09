#include "MCLib.h"

int main(void){
    int a = 100, b = 200, c = 300;
    char* test1 = "alpha";
    char* test2 = "gamma";
    char* test3 = "delta";

    //test open intervals, because lessThan does not include limiting value
    printf("%d in [%d, %d] ?. cmp result: %d\n", b, a, c, MCLib_chkRng(&b, &a, &c, MCLib_lessThan_Int) );
    printf("%d in [%d, %d] ?. cmp result: %d\n", a, b, c, MCLib_chkRng(&a, &b, &c, MCLib_lessThan_Int) );
    printf("%d in [%d, %d] ?. cmp result: %d\n", b, b, c, MCLib_chkRng(&b, &b, &c, MCLib_lessThan_Int) );

    printf("%s in [%s, %s] ?. cmp result: %d\n", test1, test2, test3, MCLib_chkRng(test1, test2, test3, MCLib_lessThan_Str) );
    printf("%s in [%s, %s] ?. cmp result: %d\n", test3, test1, test2, MCLib_chkRng(test3, test1, test2, MCLib_lessThan_Str) );

    //test closed intervals, because lessThan does not include limiting value
    printf("%d in [%d, %d] ?. cmp result: %d\n", b, a, c, MCLib_chkRng(&b, &a, &c, MCLib_lessThanOrEq_Int) );
    printf("%d in [%d, %d] ?. cmp result: %d\n", a, b, c, MCLib_chkRng(&a, &b, &c, MCLib_lessThanOrEq_Int) );
    printf("%d in [%d, %d] ?. cmp result: %d\n", b, b, c, MCLib_chkRng(&b, &b, &c, MCLib_lessThanOrEq_Int) );
    return 0;
}
