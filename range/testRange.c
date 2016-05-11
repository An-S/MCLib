#include "MCLib.h"

int main(void){
    int a = 100, b = 200, c = 300;

    printf("%d in [%d, %d] ?. cmp result: %d\n", b, a, c, MCLib_chkRng(&b, &a, &c, MCLib_lessThan_Int) );
    printf("%d in [%d, %d] ?. cmp result: %d\n", a, b, c, MCLib_chkRng(&a, &b, &c, MCLib_lessThan_Int) );

    return 0;
}
