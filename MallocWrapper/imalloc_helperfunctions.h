#ifndef __IMALLOC_HELPERFUNCTIONS_H__
#define __IMALLOC_HELPERFUNCTIONS_H__
	#include <stdbool.h>
	#include <stdlib.h>

	int convertTrueToSUCCESSFalseToFAILURE(bool val);
	int printNumberOfAllocations(void);
	int reportIfimallocError(void);
#endif
