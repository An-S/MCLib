#include <MCLib.h>

long int lcm(int num1, int num2){
    long int num3 = num1, num4 = num2;

    while (!(num3 == num4)){
        if (num3 > num4){
            num4+=abs(num2);
        }else{
            num3+=abs(num1);
        }
    }
    return num3;
}
