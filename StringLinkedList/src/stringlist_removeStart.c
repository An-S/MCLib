#include "../StringLinkedList_internal.h"

int stringlist_removeFirstEntry(stringlist_Head_t *head){
	if (head){
		assertValidList(head);
		if (head->elemCnt > 0){
			//remember to avoid second indirection
			stringlist_SingleEntry_t *first = head->first;

			//ifree(last->entry);
			head->first = first->next;
			ifree(first->entry);
			ifree(first);
			first = head->first;
			first->prev = NULL;

			-- head -> elemCnt;
			return EXIT_SUCCESS;
		}
	}
    return EXIT_FAILURE;
}
