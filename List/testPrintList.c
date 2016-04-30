#include "MCLib_List.h"

int main(void){
    uint8_t arr1[] = {1,10,100,2,20,200,3,9,27,83,243};
    uint16_t arr2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096};

    printList("%d", arr1, getuint8, ELEMCNT(arr1), 4);
    printf("\n");
    printList("%d", arr2, getuint16, ELEMCNT(arr2), 5);
    printf("\n");

    return 0;
}
