
#include "../StringLinkedList_internal.h"

stringlist_SingleEntry_t *stringlist_getNext(stringlist_SingleEntry_t *elem){
	if (elem){
		//asserts that if elem->next is valid, then prev pointer of next element points to current element
		assert (elem->next?elem==elem->next->prev:true);
		return elem->next;
	}
	return NULL;
}
