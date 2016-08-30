#include "../StringLinkedList_internal.h"

int stringlist_addListEntry(char* newEntry, stringlist_Head_t *head){
	//check on valid head ptr
	if (head){
		//if one of these asserts fail, given head pointer is suspicious to really point to list structure
		assertValidList(head);
		//remember to avoid second indirection
		stringlist_SingleEntry_t *last = stringlist_getLast(head), *next = NULL;
		//last: ......*

		//check, if valid string is given
		if (!newEntry){
			//return pointer to string NULL
			newEntry = (char*)constStr_NULL;
		}
		//alloc space for string and
		//copy string to list element
		last -> entry = strcpy(imalloc(strlen(newEntry)+1), newEntry);
		assert('\0' == (last -> entry)[strlen(newEntry)] );//Check that \0 is copied
		//else last -> entry is kept NULL
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
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
