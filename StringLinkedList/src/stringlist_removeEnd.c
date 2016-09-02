#include "../StringLinkedList_internal.h"

int stringlist_removeLastEntry(stringlist_Head_t *head){
	if (head){
		assertValidList(head);
		if (head->elemCnt > 0){
			//remember to avoid second indirection
			stringlist_SingleEntry_t *last = stringlist_getLast(head);
			stringlist_SingleEntry_t *prev = stringlist_getPrev(last);

			//ifree(last->entry);
			ifree(last);
			MCLib_strfree(prev->entry);
			prev->entry= NULL;
			head->last = prev;
			prev->next = NULL;
			-- head -> elemCnt;
			return EXIT_SUCCESS;
		}
	}
    return EXIT_FAILURE;
}
