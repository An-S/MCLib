
#include <sllIterator_internal.h>

sllIterator_t* sllIterator_alloc(void){
	return calloc(sizeof(sllIterator_t),1);
}
