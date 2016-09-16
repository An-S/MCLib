
#include <slliterator_internal.h>

stringlist_SingleEntry_t *slliterator_proceed(sllIterator_t *it){
	//move to next element if direction is SLLIT_FORWARD
	return slliterator_conditionalMove(SLLIT_FORWARD == slliterator_getDir(it), it);
}
