#include "ParseCommandLineArgs_internal.h"

int nDef = 0;
cmdargs_t (*switchDefinitions)[] = NULL;

int cmdargs_addSwitchDefinition(char* optionString, char* helptext){
	if (NULL == switchDefinitions){
		cmdargs_setError("Call cmdargs_init() first");

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
