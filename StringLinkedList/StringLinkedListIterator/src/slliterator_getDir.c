#include <slliterator_internal.h>

sllIterator_Direction_t slliterator_getDir(sllIterator_t *it){
	if (it){
		return it->direction;
	}
    return UINT_MAX;//set error sentinal
}


