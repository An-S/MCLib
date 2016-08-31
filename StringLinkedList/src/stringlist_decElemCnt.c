
#include "../StringLinkedList_internal.h"

size_t stringlist_decElemCnt(stringlist_Head_t *head){
	if (head){
		//size_t cnt = head->elemCnt;
		//assert that prev pointer of first element signs start correctly with NULL
		//assert(NULL == head->first->prev);

		//assure that No elements don't wrap around to size_t max.
		if (head->elemCnt){
			return --head->elemCnt;
		}
		//return 0;
	}
	return 0;
}


