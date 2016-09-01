
#include "../StringLinkedList_internal.h"

stringlist_SingleEntry_t *stringlist_getFirst(stringlist_Head_t *head){
	if (head){
		//assert that prev pointer of first element signs start correctly with NULL
		assert(NULL == head->first->prev);
		return head->first;
	}
	return NULL;
}

uint8_t stringlist_setFirst(stringlist_Head_t *head, stringlist_SingleEntry_t *first){
	if (head){
		//get element, which is first element up to now
		stringlist_SingleEntry_t *oldFirst = stringlist_getFirst(head);

		//check, if first->next points to another element.
		if (!stringlist_getNext(first)){
			//if not, just insert new first before old first
			head->first = first;
			first->next = oldFirst;
		}else{
			//if some elements already chained exit with error
			return EXIT_FAILURE;
		}
		return EXIT_SUCCESS,
	}
	return EXIT_FAILURE;
}
