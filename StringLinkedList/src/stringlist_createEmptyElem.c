

#include "../StringLinkedList_internal.h"

stringlist_SingleEntry_t *stringlist_createEmptyElem(void){
	stringlist_SingleEntry_t *elem = imalloc(sizeof(stringlist_SingleEntry_t));
	if (elem) stringlist_initEntry(elem);
	return elem;
}

