#include "MCLib.h"

unsigned int gcd(int a, int b){
    a=abs(a);
    b=abs(b);
    while(a!=0 && b!=0 ){
        if (a>b){
            a %= b;
        }else{
            b %= a;
        }
    }
    return a|b;
}
