
#include "MCLib_List.h"

void *printElemFnc_wrapper(FILE *file, char *format, void* list, fprintElemFnc_t *fnc, size_t perLine){
    static size_t i = 0;

    //if element ptr given, set reset counter (start of row)
    if (list){
        i = 0;
        return fnc(0, 0, list);
    }else{
        //check counter for end of row condition
        if (0 == i%perLine){
            fputc('\n', file);
        }
        ++i;//inc row counter
    }
    return fnc(file, format, NULL);
}


int MCLib_fprintList(FILE *file, char* format, void *list, fprintElemFnc_t *fprintElemFnc, size_t n, size_t perLine)
{
    size_t i;

    if (n == 0) return EXIT_FAILURE;

    //init function to print elements, remember pointer
    //fprintElemFnc(0, 0, list);
    printElemFnc_wrapper(0, 0, list, fprintElemFnc, 0);

    for (i = 0; i<n-1; ++i){
        printElemFnc_wrapper(file, format, NULL, fprintElemFnc, perLine);
        fprintf(file, ", ");
    }

    printElemFnc_wrapper(file, format, NULL, fprintElemFnc, perLine);

    return EXIT_SUCCESS;
}

