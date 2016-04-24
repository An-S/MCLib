#ifndef MODULETESTSUPPORTLIB_H_INCLUDED
#define MODULETESTSUPPORTLIB_H_INCLUDED

#include <stdlib.h>

#define TESTSUCCESS(test) (EXIT_SUCCESS == (test))
#define TESTFAILURE(test) (EXIT_FAILURE == (test))
#define CONDITIONALRETURN(cond, returnvalue) do{if (cond) return returnvalue;}while(0)
#define RETURNONFAILURE(test) do{if (TESTFAILURE(test)) return EXIT_FAILURE;}while(0)
#define RETURNOK do{return EXIT_SUCCESS;}while(0)
#define RETURNBAD do{return EXIT_FAILURE;}while(0)

#endif // MODULETESTSUPPORTLIB_H_INCLUDED
