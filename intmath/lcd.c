#include "intmath.h"

int lcd(int a, int b){
    while(a!=0 && b!=0 ){
        if (a>b){
            a %= b;
        }else{
            b %= a;
        }
    }
    return a;
}