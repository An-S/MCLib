#include <sllIterator_internal.h>

sllIterator_Pos_t sllIterator_getPos(sllIterator_t *it){
	if (it){
		return it->currentPos;
	}
    return UINT_MAX;//set error sentinal
}


