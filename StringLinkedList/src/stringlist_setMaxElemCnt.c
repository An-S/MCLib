

#include "../StringLinkedList_internal.h"

size_t stringlist_setMaxElemCnt(stringlist_Head_t *head, size_t max){
	if (head){
		//assert that prev pointer of first element signs start correctly with NULL
		//assert(NULL == head->first->prev);
		return head->maxElemCnt = max;
	}
	return 0;
}
