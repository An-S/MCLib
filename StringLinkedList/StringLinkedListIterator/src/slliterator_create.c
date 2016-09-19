
#include <sllIterator_internal.h>

sllIterator_t* sllIterator_create(stringlist_Head_t *head, sllIterator_Direction_t dir){
	//alloc space to hold iterator
    sllIterator_t* it = sllIterator_alloc();
    //dependent on direction set elemPtr to first or last element in list
	it->elemPtr = dir==SLLIT_FORWARD?stringlist_getFirst(head):stringlist_getLast(head);
	//remember direction
	it->direction = dir;
	//dependent on direction set pos indicator to first or last element in list
	it->currentPos = dir==SLLIT_FORWARD?0:stringlist_getElemCnt(head);
    return it;
}
