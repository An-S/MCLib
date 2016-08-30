
#include "../StringLinkedList_internal.h"


stringlist_SingleEntry_t *stringlist_getPrev(stringlist_SingleEntry_t *elem){
	if (elem){
		//asserts that if elem->prev is valid, then next pointer of prev element points to current element
		assert (elem->prev?elem==elem->prev->next:true);
		return elem->prev;
	}
	return NULL;
}
