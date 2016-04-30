
#include "intmath.h"

unsigned int absdiff(int a, int b){
    //With using the if statement it is possible to avoid overflow by subtracting in the wrong order
    if (a>b) return a-b;
    return b-a;
}
