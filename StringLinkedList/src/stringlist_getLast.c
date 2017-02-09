
#include "../StringLinkedList_internal.h"

stringlist_SingleEntry_t *stringlist_getLast(stringlist_Head_t *head){
	if (head){
		//assert that next pointer of last element signs end correctly with NULL
		assert(NULL == head->last->next);
		return head->last;
	}
	return NULL;
}

uint8_t stringlist_setLast(stringlist_Head_t *head, stringlist_SingleEntry_t *last){
	if (head){
		//get element, which is first element up to now
		stringlist_SingleEntry_t *oldLast = stringlist_getLast(head);

		//check, if first->next points to another element.
		if (!stringlist_getPrev(last)){
			//if not, just insert new last after old last
			head->last = last;
			last->prev = oldLast;
		}else{
			//if some elements already chained exit with error
			return EXIT_FAILURE;
		}
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
