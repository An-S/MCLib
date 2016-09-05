#include "../StringLinkedList_internal.h"

uint8_t stringlist_setNextPtr(stringlist_SingleEntry_t *elem, stringlist_SingleEntry_t *next){
	if (elem){
		//just set first ptr to new value without asking dumb questions
		elem->next = next;
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
