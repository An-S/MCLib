
#include <sllIterator_internal.h>

stringlist_SingleEntry_t *sllIterator_get(sllIterator_t *it){
	if (it){
		return it->elemPtr;
	}
    return NULL;
}

