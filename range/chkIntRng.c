#include "MCLib_Range.h"

bool MCLib_chkIntRng(int val, int lowBnd, int highBnd){
    if (lowBnd <= val){
        return highBnd >= val;
    }
    return false;
}
