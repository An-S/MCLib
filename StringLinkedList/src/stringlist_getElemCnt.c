
#include "../StringLinkedList_internal.h"

size_t stringlist_getElemCnt(stringlist_Head_t *head){
	if (head){
		return head->elemCnt;
	}
	return 0;
}

