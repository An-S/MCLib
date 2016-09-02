#include "../StringLinkedList_internal.h"

int stringlist_removeFirstEntry(stringlist_Head_t *head){
	if (head){
		assertValidList(head);
		if (stringlist_getElemCnt(head) > 0){
			//remember to avoid second indirection
			stringlist_SingleEntry_t *first = stringlist_getFirst(head);

			//ifree(last->entry);
			head->first = stringlist_getNext(first);
			MCLib_strfree(first->entry);
			ifree(first);
			first = stringlist_getFirst(head);
			first->prev = NULL;

			-- head -> elemCnt;
			return EXIT_SUCCESS;
		}
	}
    return EXIT_FAILURE;
}
