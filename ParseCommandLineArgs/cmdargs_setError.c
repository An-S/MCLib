#include "ParseCommandLineArgs_internal.h"

char* errormsg = NULL;

int cmdargs_setError(char* message){
	size_t bytesize = strlen(message)+1;
	int exitcode = EXIT_SUCCESS;

	if (256 <= bytesize){
		message = "Error message too long (max 256)";
		bytesize = strlen(message)+1;
		exitcode = EXIT_FAILURE;
	}
	//free(errormsg);//Clear previous error message from mem, if existant
	errormsg = realloc(errormsg, bytesize);//adjust memory window to fit new error message
	memmove(errormsg, message, bytesize);

	return exitcode;
}

char* cmdargs_getLastError(void){
	return errormsg;
}

int cmdargs_clearError(void){

	free(errormsg);//Clear previous error message from mem, if existant
	errormsg = NULL;

	return EXIT_SUCCESS;
}


