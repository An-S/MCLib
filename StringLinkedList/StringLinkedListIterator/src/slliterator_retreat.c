#include <slliterator_internal.h>

stringlist_SingleEntry_t *slliterator_retreat(sllIterator_t *it, stringlist_SingleEntry_t *elem){
	//move to next element if direction is SLLIT_BACKWARD
	//because the pointers in the list moves relative to the specified direction
	return slliterator_conditionalMove(SLLIT_BACKWARD == slliterator_getDir(it), it);
}


