#ifndef CMDARGS_ERRORMESSAGES_C_INCLUDED
#define CMDARGS_ERRORMESSAGES_C_INCLUDED

	#include "ParseCommandLineArgs_internal.h"

	#define C(x,y) y
	char *cmdargsErrMessages[] = {CMDARGERRLIST};
	#undef C

#endif // CMDARGS_ERRORMESSAGES_C_INCLUDED
