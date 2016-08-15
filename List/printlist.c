#include "MCLib_List.h"

int MCLib_printList(char* format, void *list, printElemFnc_t *printElemFnc, size_t n, size_t perLine)
{
    size_t i;

    if (n == 0) return EXIT_FAILURE;

    //init function to print elements, remember pointer
    printElemFnc(0, list);

    for (i = 0; i<n-1; ++i){
        if (0 == i%perLine){
            putchar('\n');
        }
        //print current element. give NULL pointer to skip initialization and inc ptr instead
        printElemFnc(format, NULL);
        printf(", ");
    }

    if (0 == i%perLine){
        putchar('\n');
    }

    printElemFnc(format, NULL);

    return EXIT_SUCCESS;
}

