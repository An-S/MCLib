#include "../StringLinkedList_internal.h"

int stringlist_addListEntry(char* newEntry, stringlist_Head_t *head){
	//check on valid head ptr
	if (head){

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
		stringlist_setString(last, newEntry);
		assert('\0' == (last -> entry)[strlen(newEntry)] );//Check that \0 is copied
		//else last -> entry is kept NULL
		stringlist_incElemCnt(head);
		//alloc next element and set next pointer to it
		next = stringlist_createEmptyElem();
		RETURNONFAILURE( reportIfimallocError() );
		stringlist_setNextPtr(last, next);
		stringlist_setLastPtr(head, next);
		//last = last->next;
		stringlist_setPrevPtr(next, last);

		//test if we would exceed max list length
		if (stringlist_getElemCnt(head) >= stringlist_getMaxElemCnt(head)){
			stringlist_removeFirstEntry(head);
		}
		//assert( NULL == this -> next -> next );
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
