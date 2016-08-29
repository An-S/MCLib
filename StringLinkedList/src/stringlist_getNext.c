
#include "../StringLinkedList_internal.h"

stringlist_SingleEntry_t *stringlist_GetNext(stringlist_SingleEntry_t *elem){
	if (elem){
		return elem->next;
	}
	return NULL;
}
