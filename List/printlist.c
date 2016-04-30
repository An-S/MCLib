#include "MCLib_List.h"

/*int printList(char* format, void *list, FGVElementFnc_Ptr FGVElem, size_t n, size_t perLine)
{
    uint16_t elem;
    size_t i;

    if (n == 0) return EXIT_FAILURE;

    for (i = 0; i<n-1; ++i){
        if (0 == i%perLine){
            putchar('\n');
        }
        elem = getElem(&list);
        printf(format, elem);
        printf(", ");
    }

    if (0 == i%perLine){
        putchar('\n');
    }

    elem = getElem(&list);
    printf(format, elem);

    return EXIT_SUCCESS;
}*/

