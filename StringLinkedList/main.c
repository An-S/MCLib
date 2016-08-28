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

bool checkPtrsNULL(CuTest *tc, stringlist_SingleEntry_t *e){
    return	CuAssertPtrNull(tc, e->entry) ||
			CuAssertPtrNull(tc, e->next) ||
            CuAssertPtrNull(tc, e->prev);
}

bool addListEntry(CuTest *tc, stringlist_Head_t *head, char *string){
	size_t elemCnt = head->elemCnt;

	stringlist_addListEntry(string, head);

	return	CuAssertIntEquals(tc, elemCnt+1, head->elemCnt) ||
			CuAssertIntEquals(tc, 0, strcmp(string, head->first->entry) ) ||
			CuAssertPtrNull(tc, head->first->next) ||
			CuAssertPtrNull(tc, head->first->prev);
}

CUTEST(addListEntry){
	static char first[] = "first";

	stringlist_Head_t *head = stringlist_create();
    CuAssertFalse(tc, addListEntry(tc, head, first));
}

CUTEST(create){
    stringlist_Head_t *head = stringlist_create();
    CuAssertIntEquals(tc, head->elemCnt, 0);
    CuAssertPtrNotNull(tc, head->first);
    CuAssertPtrEquals(tc, head->last, head->first);
    CuAssertIntEquals(tc, false, checkPtrsNULL(tc, head->first));
}

CUTEST(initEntry){
    static stringlist_SingleEntry_t e = {(void*)1,(void*)2,(void*)3};
    stringlist_initEntry(&e);
    CuAssertIntEquals(tc, false, checkPtrsNULL(tc, &e));
}

int runSuite1(void){
    CUSUITE_OPEN(suite);

    CUTEST_ADD(suite, create);
    CUTEST_ADD(suite, initEntry);
	CUTEST_ADD(suite, addListEntry);

    CuSuiteRun(suite);
    CuSuiteDetails(suite, stdout);
    return CuSuiteGetFailcount(suite);
}

int main(void){
    stringlist_Head_t *list = stringlist_create();
    runSuite1();
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
