#include "ParseCommandLineArgs_internal.h"

int cmdargs_ConsoleOutputLastError(void){
	char* errormsg = cmdargs_getLastError();

	if (NULL == errormsg){
		printf("No error!\n");
	}

	puts(errormsg);
	putchar('\n');

	return EXIT_SUCCESS;
}
