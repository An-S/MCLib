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
	//int *dummy = malloc(1000);

	//adds element to list
	stringlist_addListEntry(string, head);
	if (!string){
		//if no string given, set string pointer to "NULL" string.
		string = (char*)constStr_NULL;
	}
	//stringlist_addListEntry(string, (stringlist_Head_t *) dummy);
	//free(dummy);
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

char *getNumStr(char *baseStr, uint8_t num){
	char numstr[4];
	char *str = malloc(strlen(baseStr)+sizeof(numstr));
	snprintf(numstr,3, "%d", num);
	return str;
}

/*
bool addListEntries(CuTest *tc, stringlist_Head_t *head, char *string, uint8_t N){
	uint16_t i;
	bool ret = false;
	char numstr[] = "000";
	char *str = malloc(strlen(string)+sizeof(numstr));
    strcat(str, string, numstr);

	for (i=0; i<=N; ++i){
		sprintf(numstr, "%d", i);
		ret ||= addListEntry(tc, head, str);
	}

	free(str);
	return	ret;
}*/

CUTEST(nextListEntry){
	char *basestr = "test"; uint8_t N = 50;
	stringlist_Head_t *head = stringlist_create();
	stringlist_SingleEntry_t *entry;

	//addListEntries(tc, head, basestr, N);
	/*entry = stringlist_getFirst(head);
	for (i = 0; i<N; ++i){
		CuAssertIntEquals(tc, 0, strcmp()
		entry = stringlist_getNext(entry);
	}*/
	addListEntry(tc, head, "first");
	addListEntry(tc, head, "second");
	entry = stringlist_getFirst(head);
	CuAssertIntEquals(tc, 0, strcmp(stringlist_getString(entry), "first"));
	entry = stringlist_getNext(entry);
	CuAssertIntEquals(tc, 0, strcmp(stringlist_getString(entry), "second"));
	stringlist_free(head);
}

CUTEST(prevListEntry){
	char *basestr = "test"; uint8_t N = 50;
	stringlist_Head_t *head = stringlist_create();
	stringlist_SingleEntry_t *entry;

	//addListEntries(tc, head, basestr, N);
	/*entry = stringlist_getFirst(head);
	for (i = 0; i<N; ++i){
		CuAssertIntEquals(tc, 0, strcmp()
		entry = stringlist_getNext(entry);
	}*/
	addListEntry(tc, head, "first");
	addListEntry(tc, head, "second");
	entry = stringlist_getPrev(stringlist_getLast(head));
	CuAssertIntEquals(tc, 0, strcmp(entry->entry, "second"));
	entry = stringlist_getPrev(entry);
	CuAssertIntEquals(tc, 0, strcmp(entry->entry, "first"));
	stringlist_free(head);
}

CUTEST(firstListEntry){
	stringlist_Head_t *head = stringlist_create();
	addListEntry(tc, head, "first");
	addListEntry(tc, head, "second");
	CuAssertIntEquals(tc, 0, strcmp(stringlist_getFirst(head)->entry, "first"));
	stringlist_free(head);
}

CUTEST(lastListEntry){
	stringlist_Head_t *head = stringlist_create();
	addListEntry(tc, head, "first");
	addListEntry(tc, head, "second");
	CuAssertIntEquals(tc, 0, strcmp(stringlist_getLast(head)->prev->entry, "second"));
	stringlist_free(head);
}

CUTEST(getString){
	stringlist_Head_t *head = stringlist_create();
	addListEntry(tc, head, "first");
	CuAssertIntEquals(tc, 0, strcmp(stringlist_getString(stringlist_getFirst(head)), "first"));
	stringlist_free(head);
}

CUTEST(getElemCnt){
	stringlist_Head_t *head = stringlist_create();

	CuAssertIntEquals(tc, 0, stringlist_getElemCnt(head));
	head->elemCnt = 5;
	CuAssertIntEquals(tc, 5, stringlist_getElemCnt(head));
	head->elemCnt = 23456;
	CuAssertIntEquals(tc, 23456, stringlist_getElemCnt(head));

	stringlist_free(head);
}

CUTEST(incElemCnt){
	stringlist_Head_t *head = stringlist_create();

	CuAssertIntEquals(tc, 1, stringlist_incElemCnt(head));
	CuAssertIntEquals(tc, 2, stringlist_incElemCnt(head));
	CuAssertIntEquals(tc, 3, stringlist_incElemCnt(head));
	CuAssertIntEquals(tc, 4, stringlist_incElemCnt(head));
	CuAssertIntEquals(tc, 5, stringlist_incElemCnt(head));
	stringlist_free(head);
}

CUTEST(decElemCnt){
	stringlist_Head_t *head = stringlist_create();

	//check that elemCnt is not decremented again if already zero
	CuAssertIntEquals(tc, 0, stringlist_decElemCnt(head));
	CuAssertIntEquals(tc, 0, stringlist_decElemCnt(head));
	CuAssertIntEquals(tc, 0, stringlist_decElemCnt(head));

	head->elemCnt = 5;
	CuAssertIntEquals(tc, 4, stringlist_decElemCnt(head));
	CuAssertIntEquals(tc, 3, stringlist_decElemCnt(head));
	CuAssertIntEquals(tc, 2, stringlist_decElemCnt(head));
	CuAssertIntEquals(tc, 1, stringlist_decElemCnt(head));
	CuAssertIntEquals(tc, 0, stringlist_decElemCnt(head));
	stringlist_free(head);
}


CUTEST(addListEntry){
	static char first[] = "first", name[] = "000";
	size_t N = 50,i;
	//this test consist of the following:
	//create a list header and an entry
	//check, if string is copied correctly to the list entry
	//check, if elemCnt is increased correctly as entries are added
	//however because the add function creates also a new reserve element this has to be checked, too
	//so check, if next üpointer points to reserve element at end of list
	//check, if reserve element is cleared correctly with NULL ptrs except the prev pntr
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
    /*CuAssertIntEquals(tc, 1, head->elemCnt);
    CuAssertIntEquals(tc, 0, strcmp(head->first->entry, first));
    CuAssertPtrEquals(tc, head->first->next, head->last);
	CuAssertPtrEquals(tc, head->first->next->prev, head->first);
	CuAssertPtrNull(tc, head->first->prev);
*/
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

CUTEST(finalCheck){
	CuAssertIntEquals(tc, 0, returnAllocationCount());
}

int runSuite1(void){
    CUSUITE_OPEN(suite);

    CUTEST_ADD(suite, create);
    CUTEST_ADD(suite, initEntry);
	CUTEST_ADD(suite, addListEntry);
	CUTEST_ADD(suite, getString);
	CUTEST_ADD(suite, getElemCnt);
	CUTEST_ADD(suite, firstListEntry);
	CUTEST_ADD(suite, lastListEntry);
	CUTEST_ADD(suite, nextListEntry);
	CUTEST_ADD(suite, prevListEntry);
	CUTEST_ADD(suite, incElemCnt);
	CUTEST_ADD(suite, decElemCnt);
	CUTEST_ADD(suite, getElemCnt);

	//must be final test
	CUTEST_ADD(suite, finalCheck);

    CuSuiteRun(suite);
    CuSuiteDetails(suite, stdout);

    return CuSuiteGetFailcount(suite);
}

int main(void){
    size_t fails = runSuite1();


	return fails;
}
