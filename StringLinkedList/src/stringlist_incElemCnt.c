
#include "../StringLinkedList_internal.h"

size_t stringlist_incElemCnt(stringlist_Head_t *head){
	if (head){
		//assert that prev pointer of first element signs start correctly with NULL
		//assert(NULL == head->first->prev);
		return ++head->elemCnt;
	}
	return 0;
}

