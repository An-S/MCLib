
#include "../StringLinkedList_internal.h"

/** \brief gets stored string in list elem and returns copy
 *
 * \param stringlist_SingleEntry_t *elem, pointer to stringlist element
 * \return pointer to copy of string
 *
 */
char *stringlist_getString(stringlist_SingleEntry_t *elem){
	if (elem){
		return MCLib_strcopy(elem->entry);
	}
	return NULL;
}

/** \brief stores copy of passed string into stringlist
 *
 * \param stringlist_SingleEntry_t *elem, pointer to stringlist element
 * \param char *newstr, pointer to string to be inserted
 * \return EXIT_SUCCESS or EXIT_FAILURE
 *
 */
uint8_t stringlist_setString(stringlist_SingleEntry_t *elem, char *newstr){
	if (elem){
		//insert pointer to copy of input string
		elem->entry = MCLib_strcopy(newstr);
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
