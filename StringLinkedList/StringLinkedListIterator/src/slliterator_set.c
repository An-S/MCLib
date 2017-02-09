
#include <sllIterator_internal.h>

stringlist_SingleEntry_t *sllIterator_set(sllIterator_t *it, stringlist_SingleEntry_t *elem){
	if (it){
		it->elemPtr = elem;
		return elem;
	}
    return NULL;
}


