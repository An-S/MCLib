#include "StringLinkedList_internal.h"


int stringlist_outputAllEntries(stringlist_Head_t *list){
	stringlist_SingleEntry_t *entry = list->first, *last = list->last;
	do{
		assert (NULL != entry -> entry);

		puts(entry -> entry);
		entry = entry -> next;
	}while(entry != last);

	return EXIT_SUCCESS;
}


