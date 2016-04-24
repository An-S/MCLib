#include <MCLib.h>

int main(void){
    int a=18, b=34, c;
    //c=lcd(a,b);
    printf("max from %d and %d = %d\n", a,b,max(a,b));
    printf("min from %d and %d = %d\n", a,b,min(a,b));
    printf("lcd of %d and %d = %d", a,b,lcd(a,b));
    return EXIT_SUCCESS;
}
