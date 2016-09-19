#include <sllIterator_internal.h>

sllIterator_Direction_t sllIterator_getDir(sllIterator_t *it){
	if (it){
		return it->direction;
	}
    return (sllIterator_Direction_t)UINT_MAX;//set error sentinal
}


