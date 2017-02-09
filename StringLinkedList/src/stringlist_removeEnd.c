#include "../StringLinkedList_internal.h"

int stringlist_removeLastEntry(stringlist_Head_t *head){
	if (head){
		assertValidList(head);
		if (stringlist_getElemCnt(head) > 0){
			//remember to avoid second indirection
			stringlist_SingleEntry_t *last = stringlist_getLast(head);
			stringlist_SingleEntry_t *prev = stringlist_getPrev(last);

			//ifree(last->entry);
			ifree(last);
			MCLib_strfree(prev->entry);

			//stringlist_setPrevPtr(prev, NULL);
			stringlist_setNextPtr(prev, NULL);
			stringlist_setLastPtr(head, prev);
			stringlist_decElemCnt(head);
			return EXIT_SUCCESS;
		}
	}
    return EXIT_FAILURE;
}
