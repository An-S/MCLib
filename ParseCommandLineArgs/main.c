#include <stdio.h>
#include <stdlib.h>

#include "ParseCommandLineArgs_internal.h"

#define assertExitSuccess(value) assert(EXIT_SUCCESS == (value))

int main(void)
{
	int returnValue;

    returnValue = cmdargs_ConsoleOutputLastError();
    assertExitSuccess(returnValue);

    returnValue = cmdargs_setError("Bloeder Fehler!");
    assertExitSuccess(returnValue);

    returnValue = cmdargs_ConsoleOutputLastError();
    assertExitSuccess(returnValue);

    returnValue = cmdargs_clearError();
    assertExitSuccess(returnValue);

    returnValue = cmdargs_ConsoleOutputLastError();
    assertExitSuccess(returnValue);

    return EXIT_SUCCESS;
}
