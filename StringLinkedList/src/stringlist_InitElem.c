#include "../StringLinkedList_internal.h"

int stringlist_initEntry(stringlist_SingleEntry_t *sle){
	if (sle){
		sle -> entry = NULL;
		sle -> prev = NULL;
		sle -> next = NULL;
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
