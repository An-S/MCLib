
#include "../StringLinkedList_internal.h"

char *stringlist_GetString(stringlist_SingleEntry_t *elem){
	if (elem){
		return elem->entry;
	}
	return NULL;
}
