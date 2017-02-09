#include "../StringLinkedList_internal.h"

uint8_t stringlist_setPrevPtr(stringlist_SingleEntry_t *elem, stringlist_SingleEntry_t *prev){
	if (elem){
		//just set first ptr to new value without asking dumb questions
		elem->prev = prev;
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}

