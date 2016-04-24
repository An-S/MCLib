#include "imalloc_internal.h"

#define E(x,y) y
char* imalloc_StrErrorMessages[IMALLOC_ERRORCODES_COUNT] = {IMALLOC_ERRCODEANDMESSAGELIST};
#undef E

int errorcode = IMALLOCERR_OK;

int imalloc_setError(int ec){
	if (ec <= IMALLOCERR_LOWEST){
		goto wrongerrorcode;
	}

	if (ec >= IMALLOCERR_HIGHEST){
		goto wrongerrorcode;
	}

	errorcode = ec;
	return EXIT_SUCCESS;

	//This part is only executed in case a wrong errorcode was passed
	wrongerrorcode:
	errorcode = IMALLOCERR_WRONGERRCODE;
	return EXIT_FAILURE;
}

int imalloc_getError(void){
	assert (errorcode > IMALLOCERR_LOWEST);//Check validity of error code
	assert (errorcode < IMALLOCERR_HIGHEST);//To be sure, if for some reason check in setError is not working
	return errorcode;
}

bool imalloc_isError(void){
	return IMALLOCERR_OK != errorcode;
}

int imalloc_clearError(void){
	errorcode = IMALLOCERR_OK;
	return EXIT_SUCCESS;
}

char* imalloc_getErrorMessage(void){
	assert (errorcode > IMALLOCERR_LOWEST);//Check validity of error code before indexing array
	assert (errorcode < IMALLOCERR_HIGHEST);
	return imalloc_StrErrorMessages[errorcode];
}
