
#include <sllIterator_internal.h>

stringlist_SingleEntry_t *sllIterator_proceed(sllIterator_t *it){
	//move to next element if direction is SLLIT_FORWARD
	return sllIterator_conditionalMove(SLLIT_FORWARD == sllIterator_getDir(it), it);
}
