// The functions contained in this file are pretty dummy
// and are included only as a placeholder. Nevertheless,
// they *will* get included in the static library if you
// don't remove them :)
//
// Obviously, you 'll have to write yourself the super-duper
// functions to include in the resulting library...
// Also, it's not necessary to write every function in this file.
// Feel free to add more files in this project. They will be
// included in the resulting library.

// A function adding two integers and returning the result
#include <stdheaders.h>
#include "StringLinkedList_internal.h"
#include <CuTest.h>

CUTEST(testCreate){
    stringlist_Head_t *head = stringlist_create();
    CuAssertIntEquals(tc, head->elemCnt, 0);

}

CuSuite *getSuite(void){
    CUSUITE_OPEN(suite);
    CUTEST_ADD(suite, testCreate);
}

int main(void){
    stringlist_Head_t *list = stringlist_create();

    printNumberOfAllocations();
    stringlist_addListEntry("first", list);
    printNumberOfAllocations();
    stringlist_addListEntry("second", list);
    printNumberOfAllocations();
    stringlist_addListEntry("third", list);
    printNumberOfAllocations();
    stringlist_addListEntry("fourth", list);
    printNumberOfAllocations();
    stringlist_addListEntry("fifth", list);
    printNumberOfAllocations();
    stringlist_addListEntry("sixth", list);
    printNumberOfAllocations();
    stringlist_addListEntry("seventh", list);
    printNumberOfAllocations();
    stringlist_addListEntry("eighth", list);
    printNumberOfAllocations();
    stringlist_outputAllEntries(list);

    stringlist_addListEntry("ninth", list);
    printNumberOfAllocations();
    stringlist_outputAllEntries(list);

    stringlist_removeLastEntry(list);
    printNumberOfAllocations();
    stringlist_outputAllEntries(list);
    stringlist_removeFirstEntry(list);
    printNumberOfAllocations();
    stringlist_outputAllEntries(list);

    stringlist_free(list);
    printNumberOfAllocations();
	return EXIT_SUCCESS;
}
