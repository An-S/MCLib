
#include "../StringLinkedList_internal.h"

stringlist_SingleEntry_t *stringlist_getFirst(stringlist_Head_t *head){
	if (head){
		//assert that prev pointer of first element signs start correctly with NULL
		assert(NULL == head->first->prev);
		return head->first;
	}
	return NULL;
}
