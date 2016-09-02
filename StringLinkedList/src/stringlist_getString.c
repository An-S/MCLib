
#include "../StringLinkedList_internal.h"

char *stringlist_getString(stringlist_SingleEntry_t *elem){
	if (elem){
		return elem->entry;
	}
	return NULL;
}

uint8_t stringlist_setString(stringlist_SingleEntry_t *elem, char *newstr){
	if (elem){
		//insert pointer to copy of input string
		elem->entry = MCLib_strcopy(newstr);
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
