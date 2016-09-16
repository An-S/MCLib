
#include <slliterator_internal.h>

stringlist_SingleEntry_t *slliterator_set(sllIterator_t *it, stringlist_SingleEntry_t *elem){
	if (it){
		it->elemPtr = elem;
		return elem;
	}
    return NULL;
}


