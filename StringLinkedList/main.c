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

bool checkReserveEntry(CuTest *tc, stringlist_SingleEntry_t *e){
    return	//checks if pointer to string is init correctly to NULL in reserve
			CuAssertPtrNull(tc, e->entry) ||
			//checks, if next pointer in reserve is set to NULL correctly
			CuAssertPtrNull(tc, e->next) ||
			//checks, if atleast prev pointer of reserve point so some memory location and is not NULL
            CuAssertPtrNotNull(tc, e->prev);
}

bool addListEntry(CuTest *tc, stringlist_Head_t *head, char *string){
	size_t elemCnt = head->elemCnt;
	stringlist_SingleEntry_t *beforelast = head->last;

	//adds element to list
	stringlist_addListEntry(string, head);
	if (!string){
		//if no string given, set string pointer to "NULL" string.
		string = (char*)constStr_NULL;
	}
	stringlist_addListEntry(string, (stringlist_Head_t *) 1234);
	return	//checks, if elemCnt is increased correctly on adding elements
			CuAssertIntEquals(tc, elemCnt+1, head->elemCnt) ||
			//checks, if pointer to string is set correctly
			CuAssertIntEquals(tc, 0, strcmp(string, beforelast->entry) ) ||
			//checks, if reserve entry's prev pointer points to "beforelast"
			CuAssertPtrEquals(tc, beforelast, head->last->prev) ||
			//checks, if reserve entry is initialized correctly
			checkReserveEntry(tc, beforelast->next) ||
			//checks, if beforelast's next pointer points to reserve
			CuAssertPtrEquals(tc, beforelast->next, head->last);
}

CUTEST(addListEntry){
	static char first[] = "first", name[] = "000";
	size_t N = 50,i;

	stringlist_Head_t *head = stringlist_create();
	//tests, if creation of first element succeeds
    CuAssertFalse(tc, addListEntry(tc, head, first));
    //tests, if contruction of element given NULL pointer instead of string -> succeeds
	CuAssertFalse(tc, addListEntry(tc, head, NULL));

	//tests, if creation of a certain amount of elements succeeds
	for (i=N; i!=0; --i){
		snprintf(name, 3, "%d", i);
		CuAssertFalse(tc, addListEntry(tc, head, name));
	}
	//frees resources
	stringlist_free(head);
	//tests, if all resources were freed correctly
	CuAssertIntEquals(tc, 0, returnAllocationCount());
}

CUTEST(create){
	//creates new header for linked list
    stringlist_Head_t *head = stringlist_create();
    //checks, if elemCnt initially zero
    CuAssertIntEquals(tc, head->elemCnt, 0);
    //checks, if head->first set to reserve element
    CuAssertPtrNotNull(tc, head->first);
    //checks, if last and first element are the same (only one reserve element available)
    CuAssertPtrEquals(tc, head->last, head->first);
    //checks initialization of reserve element
    CuAssertFalse(tc, checkPtrsNULL(tc, head->first));
    //frees resources
    stringlist_free(head);
    //tests, if all resources were freed correctly
    CuAssertIntEquals(tc, 0, returnAllocationCount());
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
    size_t fails = runSuite1();


	return fails;
}
