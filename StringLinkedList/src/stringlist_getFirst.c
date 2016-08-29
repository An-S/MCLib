
#include "../StringLinkedList_internal.h"

stringlist_SingleEntry_t *stringlist_GetFirst(stringlist_Head_t *head){
	if (head){
		return head->first;
	}
	return NULL;
}
