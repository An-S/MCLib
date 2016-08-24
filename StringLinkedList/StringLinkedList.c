#include "StringLinkedList_internal.h"

//this is a singleton

stringlist_SingleEntry_t* stringlist_First = NULL;
stringlist_SingleEntry_t* stringlist_Last = NULL;

int stringlist_initEntry(stringlist_SingleEntry_t *sle){
    sle -> entry = NULL;
    sle -> prev = NULL;
    sle -> next = NULL;
}

stringlist_Head_t* stringlist_Create(void){
    stringlist_Head_t* head = imalloc(sizeof(stringlist_Head_t));
    RETURNONFAILURE( reportIfimallocError() );

    //add empty entry at top of the linked list so that
    //we do not need to test if there are elements
    head -> first =
    head -> last =
    imalloc(sizeof(stringlist_SingleEntry_t));
    RETURNONFAILURE( reportIfimallocError() );
    stringlist_initEntry(head -> first);
    //we do not count empty entries. they are filled by AddListEntry
    head -> elemCnt = 0;
    return head;
}

int stringlist_addListEntry(char* newEntry, stringlist_Head_t *head){
    //remember to avoid second indirection
    stringlist_SingleEntry_t *last = head->last, *next = NULL;
    //last: ......*

    //alloc space for string and
    //copy string to list element
    last -> entry = strcpy(imalloc(strlen(newEntry)+1), newEntry);
    assert('\0' == (last -> entry)[strlen(newEntry)] );//Check that \0 is copied

    //alloc next element and set next pointer to it
    next = head -> last = last -> next = imalloc(sizeof(stringlist_SingleEntry_t));
    //last: ......#*
    RETURNONFAILURE( reportIfimallocError() );

    //last = last->next;
    next -> prev = last;
    next -> next = NULL;
    next -> entry = NULL;

    //assert( NULL == this -> next -> next );

}

int stringlist_AddListEntry(char* newEntry){
	stringlist_SingleEntry_t* this = NULL;

	assert (NULL != newEntry);//assert, that newEntry is not invalid pointer

	if (!stringlist_First){
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

int stringlist_outputAllEntries(stringlist_Head_t *list){
	stringlist_SingleEntry_t *entry = list->first, *last = list->last;
	do{
		assert (NULL != entry -> entry);

		puts(entry -> entry);
		entry = entry -> next;
	}while(entry != last);

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

    stringlist_First = NULL;
    stringlist_Last = NULL;

	return EXIT_SUCCESS;
}

int stringlist_free(stringlist_Head_t *list){
	stringlist_SingleEntry_t *entry = list->last;
	stringlist_SingleEntry_t *preventry;

	assert (entry -> next == NULL );//assert that entry points to stringlist_Last element in list
	preventry = entry -> prev;
	ifree(entry); //deletes first the last, unused element
	do{
        entry = preventry;
		assert (NULL != entry -> entry);//Check for invalid entries
		ifree(entry -> entry);
		assert( EXIT_SUCCESS == reportIfimallocError() );
		preventry = entry -> prev;
		ifree(entry);
	}while(preventry != NULL);

    ifree(list);

	return EXIT_SUCCESS;
}
