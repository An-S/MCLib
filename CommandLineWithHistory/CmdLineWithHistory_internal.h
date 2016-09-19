#ifndef CMDLINEWITHHISTORY_INTERNAL_H_INCLUDED
#define CMDLINEWITHHISTORY_INTERNAL_H_INCLUDED

#define TESTSUCCESS(test) (EXIT_SUCCESS == (test))
#define TESTFAILURE(test) (EXIT_FAILURE == (test))
#define CONDITIONALRETURN(cond, returnvalue) do{if (cond) return returnvalue;}while(0);
#define RETURNONFAILURE(test) do{if (TESTFAILURE(test)) return EXIT_FAILURE;}while(0);

#include <StringLinkedList/StringLinkedList.h>
#include <StringLinkedList/StringLinkedListIterator/include/sllIterator.h>
#endif // CMDLINEWITHHISTORY_INTERNAL_H_INCLUDED
