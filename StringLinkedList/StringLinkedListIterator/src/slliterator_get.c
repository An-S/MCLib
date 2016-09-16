
#include <slliterator_internal.h>

stringlist_SingleEntry_t *slliterator_get(sllIterator_t *it){
	if (it){
		return it->elemPtr;
	}
    return NULL;
}

