#include "../StringLinkedList_internal.h"

uint8_t stringlist_setLastPtr(stringlist_Head_t *head, stringlist_SingleEntry_t *last){
	if (head){
		//just set first ptr to new value without asking dumb questions
		head->last = last;
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
