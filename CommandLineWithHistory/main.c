#include <stdio.h>
#include <stdlib.h>
#include <MallocWrapper\imalloc.h>
#include <MallocWrapper\imalloc_helperfunctions.h>
#include <assert.h>
#include <string.h>
#include "CmdLineWithHistory_internal.h"

/*
typedef struct inputListEntry_tag{
	char* entry;
	struct inputListEntry_tag* next;
	struct inputListEntry_tag* prev;
}inputListEntry_t;

inputListEntry_t* inputList = NULL;
inputListEntry_t* last = NULL;

int addListEntry(char* newEntry){
	inputListEntry_t* this = NULL;

	assert (NULL != newEntry);//assert, that newEntry is not invalid pointer

	if (NULL == inputList){
		inputList = imalloc(sizeof(inputListEntry_t));
		RETURNONFAILURE( reportIfimallocError() );

		inputList -> entry = imalloc(strlen(newEntry)+1);
		RETURNONFAILURE( reportIfimallocError() );

		memmove(inputList -> entry, newEntry, strlen(newEntry)+1);
		assert('\0' == (inputList -> entry)[strlen(newEntry)] );//Check that \0 is copied

		inputList -> next = inputList -> prev = NULL;
		last = inputList;
	}else{
		this = last;
		this -> next = imalloc(sizeof(inputListEntry_t));
		RETURNONFAILURE( reportIfimallocError() );

		last = this -> next;
		last -> entry = imalloc(strlen(newEntry)+1);
		RETURNONFAILURE( reportIfimallocError() );

		memmove(last -> entry, newEntry, strlen(newEntry)+1);
		assert('\0' == (last -> entry)[strlen(newEntry)] );//Check that \0 is copied
		last -> next = NULL;
		last -> prev = this;

		assert( NULL == this -> next -> next );
	}

	assert ( NULL == last -> next); //As new entry was appended at end, last -> next should be NULL as there is nothing to point to
	assert ( NULL == inputList -> prev); //Same holds for pointer of first element to previous element which must not exist

	return EXIT_SUCCESS;
}

int outputInputList(void){
	inputListEntry_t *entry = inputList;
	do{
		assert (NULL != entry -> entry);

		puts(entry -> entry);
		entry = entry -> next;
	}while(entry != NULL);

	return EXIT_SUCCESS;
}

int freeInputList(void){
	inputListEntry_t *entry = last;
	inputListEntry_t *preventry;

	assert (entry -> next == NULL );//assert that entry points to last element in list
	do{
		assert (NULL != entry -> entry);//Check for invalid entries
		ifree(entry -> entry);
		assert( EXIT_SUCCESS == reportIfimallocError() );
		preventry = entry -> prev;
		ifree(entry);
		entry = preventry;
	}while(entry != NULL);

	return EXIT_SUCCESS;
}
*/
char* promptUserForStringInput(){
	static unsigned int maxInputLen = 100;

	char* input = imalloc(maxInputLen);//Reserve 100 bytes for input
	char* fgetsreturn = 0;

	assert( EXIT_SUCCESS == reportIfimallocError() );
	//int nread = 0;
	puts("Input string");
	fgetsreturn = fgets(input, maxInputLen, stdin);

	printf("Your input:%s @ %p, returnval:%p\n", input, input, fgetsreturn);
	//input = irealloc(input, strlen(i//nput)+1);
	assert( EXIT_SUCCESS == reportIfimallocError() );
	return input;
}

int main()
{
    char* input = NULL;
    stringlist_Head_t *listHead = stringlist_create();
	sllIterator_t *it = sllIterator_create(listHead, SLLIT_FORWARD);

    do{
		input = promptUserForStringInput();
		stringlist_addListEntry(input, listHead);
		//assert (EXIT_SUCCESS == addListEntry(input) );

		ifree(input);
		RETURNONFAILURE( reportIfimallocError() );
	}while(0 != strcmp(input, "\n"));
	stringlist_outputAllEntries(listHead);

	//outputInputList();
	assert( EXIT_SUCCESS == reportIfimallocError() );

	//freeInputList();
	stringlist_free(listHead);
    assert (0 == returnAllocationCount() );

    return 0;
}
