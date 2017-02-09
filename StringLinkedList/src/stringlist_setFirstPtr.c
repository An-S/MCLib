#include "../StringLinkedList_internal.h"

uint8_t stringlist_setFirstPtr(stringlist_Head_t *head, stringlist_SingleEntry_t *first){
	if (head){
		//just set first ptr to new value without asking dumb questions
		head->first = first;
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
