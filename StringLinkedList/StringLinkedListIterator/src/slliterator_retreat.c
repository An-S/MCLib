#include <sllIterator_internal.h>

stringlist_SingleEntry_t *sllIterator_retreat(sllIterator_t *it, stringlist_SingleEntry_t *elem){
	//move to next element if direction is SLLIT_BACKWARD
	//because the pointers in the list moves relative to the specified direction
	return sllIterator_conditionalMove(SLLIT_BACKWARD == sllIterator_getDir(it), it);
}


