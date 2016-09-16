
#include <slliterator_internal.h>

stringlist_SingleEntry_t *slliterator_conditionalMove(bool TforthFback, sllIterator_t *it){
	if (it){
		//if it "ok", get ptr to current elem
		stringlist_SingleEntry_t *elem = slliterator_get(it);
		if (elem){
			//if "elem" ok, set ptr to current elem
			slliterator_set(
				it,
				TforthFback?stringlist_getNext(elem):stringlist_getPrev(elem)
			);
		}
		//return element, iterator pointed to before it was advanced
		return elem;
	}
	return NULL;
}

