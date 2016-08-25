#include "StringLinkedList_internal.h"

int stringlist_initEntry(stringlist_SingleEntry_t *sle){
    sle -> entry = NULL;
    sle -> prev = NULL;
    sle -> next = NULL;
}

stringlist_Head_t* stringlist_create(void){
    stringlist_Head_t* head = imalloc(sizeof(stringlist_Head_t));
    if( TESTFAILURE(reportIfimallocError()) ) return NULL;

    //add empty entry at top of the linked list so that
    //we do not need to test if there are elements
    head -> first =
    head -> last =
    imalloc(sizeof(stringlist_SingleEntry_t));
    //RETURNONFAILURE( reportIfimallocError() );
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
    ++ head -> elemCnt;
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

int stringlist_removeLastEntry(stringlist_Head_t *head){
    //remember to avoid second indirection
    if (head->elemCnt > 0){
        stringlist_SingleEntry_t *last = head->last;
        stringlist_SingleEntry_t *prev = last->prev;

        //ifree(last->entry);
        ifree(last);
        ifree(prev->entry);
        prev->entry= NULL;
        head->last = prev;
        prev->next = NULL;
        -- head -> elemCnt;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int stringlist_removeFirstEntry(stringlist_Head_t *head){
    //remember to avoid second indirection
    if (head->elemCnt > 0){
        stringlist_SingleEntry_t *first = head->first;

        //ifree(last->entry);
        head->first = first->next;
        ifree(first->entry);
        ifree(first);
        first = head->first;
        first->prev = NULL;

        -- head -> elemCnt;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
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
