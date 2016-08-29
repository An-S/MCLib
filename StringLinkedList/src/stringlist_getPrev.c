
#include "../StringLinkedList_internal.h"


stringlist_SingleEntry_t *stringlist_GetPrev(stringlist_SingleEntry_t *elem){
	if (elem){
		return elem->prev;
	}
	return NULL;
}
