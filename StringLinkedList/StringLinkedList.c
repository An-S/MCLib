#include "StringLinkedList_internal.h"

stringlist_SingleEntry_t* stringlist_First = NULL;
stringlist_SingleEntry_t* stringlist_Last = NULL;

int stringlist_AddListEntry(char* newEntry){
	stringlist_SingleEntry_t* this = NULL;

	assert (NULL != newEntry);//assert, that newEntry is not invalid pointer

	if (NULL == stringlist_First){
		stringlist_First= imalloc(sizeof(stringlist_SingleEntry_t));
		RETURNONFAILURE( reportIfimallocError() );

		stringlist_First-> entry = imalloc(strlen(newEntry)+1);
		RETURNONFAILURE( reportIfimallocError() );

		memmove(stringlist_First-> entry, newEntry, strlen(newEntry)+1);
		assert('\0' == (stringlist_First-> entry)[strlen(newEntry)] );//Check that \0 is copied

		stringlist_First-> next = stringlist_First-> prev = NULL;
		stringlist_Last = stringlist_First;
	}else{
		this = stringlist_Last;
		this -> next = imalloc(sizeof(stringlist_SingleEntry_t));
		RETURNONFAILURE( reportIfimallocError() );

		stringlist_Last = this -> next;
		stringlist_Last -> entry = imalloc(strlen(newEntry)+1);
		RETURNONFAILURE( reportIfimallocError() );

		memmove(stringlist_Last -> entry, newEntry, strlen(newEntry)+1);
		assert('\0' == (stringlist_Last -> entry)[strlen(newEntry)] );//Check that \0 is copied
		stringlist_Last -> next = NULL;
		stringlist_Last -> prev = this;

		assert( NULL == this -> next -> next );
	}

	assert ( NULL == stringlist_Last -> next); //As new entry was appended at end, stringlist_Last -> next should be NULL as there is nothing to point to
	assert ( NULL == stringlist_First-> prev); //Same holds for pointer of first element to previous element which must not exist

	return EXIT_SUCCESS;
}

int stringlist_OutputAllEntries(void){
	stringlist_SingleEntry_t *entry = stringlist_First;
	do{
		assert (NULL != entry -> entry);

		puts(entry -> entry);
		entry = entry -> next;
	}while(entry != NULL);

	return EXIT_SUCCESS;
}

int stringlist_Free(void){
	stringlist_SingleEntry_t *entry = stringlist_Last;
	stringlist_SingleEntry_t *preventry;

	assert (entry -> next == NULL );//assert that entry points to stringlist_Last element in list
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
