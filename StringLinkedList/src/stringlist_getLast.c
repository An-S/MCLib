
#include "../StringLinkedList_internal.h"

stringlist_SingleEntry_t *stringlist_GetLast(stringlist_Head_t *head){
	if (head){
		//assert that next pointer of last element signs end correctly with NULL
		assert(NULL == head->last->next);
		return head->last;
	}
	return NULL;
}
