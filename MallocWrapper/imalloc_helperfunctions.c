#include "imalloc_internal.h"

int convertTrueToSUCCESSFalseToFAILURE(bool val){
	return val?EXIT_SUCCESS: EXIT_FAILURE;
}

int printNumberOfAllocations(void){
	printf("Number of allocations:%d\n", returnAllocationCount() );
	return EXIT_SUCCESS;
};

int reportIfimallocError(void){
	if (IMALLOCERR_OK != imalloc_getError()){
		puts(imalloc_getErrorMessage());
		imalloc_clearError();
		//putchar('\n');
		return EXIT_FAILURE;
	}
	//puts(imalloc_getErrorMessage());
	return EXIT_SUCCESS;
}
