
#include "../StringLinkedList_internal.h"

stringlist_SingleEntry_t *stringlist_GetLast(stringlist_Head_t *head){
	if (head){
		return head->last;
	}
	return NULL;
}
