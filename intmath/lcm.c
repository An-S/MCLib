#include <MCLib.h>

//important to return long int as kgv can be many times larger than the inputs
unsigned long int lcm(int num1, int num2){
    //bring the inputs in order of increasing value in order to avoid min / max tests later on
    if ( (num1 = abs(num1)) > (num2 = abs(num2))){
        int tmp = num2;
        num2 = num1;
        num1 = tmp;
        //num1 ^= num2;
        //num2 ^= num1;
        //num1 ^= num2;
    }

    //Test if the first input is zero
    if (!num1) {
        return 0;//return zero because common multiple of zero and any other number is zero!
    }else{
        //Now prepare variables for division rest and summing up
        unsigned int r0 = (num2-num1)%num1, r=r0;
        unsigned long int num3 = num1, num4 = num2;

        //run loop while rest of division if not zero
        while (r){
            if (num3 < num4){
                //update num3 with lowest value which is equal or larger than num4 and which
                //difference to the previous value of num3 is a multiple of num1
                num3 = num4+num1-r;
                //secure against overflow and return error in that case
                //num1 is >0 because of taking abs function before
                if (num3 < num1){
                    return ULONG_MAX;
                }
            }else{
                //update num4 to hold the next multiple of num2
                num4 += num2;
                //secure against overflow and return error in that case
                if (num4 < num2){
                    return ULONG_MAX; //error signal
                }
                //update division rest
                r += r0;
                //restrict division rest into the range of 0..num1-1
                if (r >= num1){
                    r -= num1;
                }
            }
        }
        //return lcm
        return num4;
    }
}
