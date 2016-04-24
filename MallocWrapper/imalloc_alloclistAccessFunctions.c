#include "imalloc_internal.h"

unsigned int n_allocations = 0;
//unsigned int updatepos = ~0;

void** alloclist = NULL;

//prototype for internal use
unsigned int increaseAllocationCount(void);
unsigned int decreaseAllocationCount(void);
int imalloc_alloclistMoveEndingSubArrayFromTo(unsigned int from, unsigned int to);

bool imalloc_alloclistCheckIndex(unsigned int at){
	assert (~0 != at);//assert that indicator for invalid pos is not passed by accident
	return at < n_allocations;
}

int imalloc_alloclistSetEntry(void* ptr, unsigned int pos){
	if (pos <= n_allocations){ //Here it is okay to request setting a NULL at end of array because it is the end marker
		if (pos != n_allocations){
			alloclist[pos] = ptr;
			return EXIT_SUCCESS;
		}else if (NULL == ptr){
			alloclist[n_allocations] = NULL;
			return EXIT_SUCCESS;
		}
	}
	imalloc_setError(IMALLOCERR_LISTINDEXOUTOFRANGE);
	return EXIT_FAILURE;
}

void** imalloc_alloclistGetEntry(unsigned int pos){
	if (pos >= n_allocations){//Here it would be an error to request the end marker NULL that why there's a >=
		imalloc_setError(IMALLOCERR_LISTINDEXOUTOFRANGE);
		return NULL;
	}
	return alloclist[pos];
}

bool imalloc_alloclistCheckEndMarker(void){
	if (NULL == alloclist){
		assert (0 == n_allocations);//If alloclist is NULL then # allocations should also be 0
		return true;
	}
	return (NULL == alloclist[n_allocations]);
}

int imalloc_alloclistAddEntryAtEnd(void* ptr){
	if (NULL != alloclist){ //secure this, if some implementation does not take account for NULL in realloc
		assert( imalloc_alloclistCheckEndMarker() );//Check, if end marker (NULL ptr) exists
		alloclist = realloc(alloclist, (n_allocations+2)*sizeof(void*));//This is not save. provisorial
	}else{
		alloclist = malloc(2*sizeof(void*));//This is not save. provisorial
	}//alloclist may not exist when this is executed first time

	//from here on, alloclist should not be NULL, else error
	if (NULL == alloclist){//If true, malloc or realloc failed
		imalloc_setError(IMALLOCERR_ALLOCATIONFAILED);
		return EXIT_FAILURE;
	}

	increaseAllocationCount();//Increase only, if success
	if (EXIT_FAILURE == imalloc_alloclistSetEntry(ptr, n_allocations-1) ){
		return EXIT_FAILURE;
	}//Insert pointer to new allocation block at end of alloclist

	if (EXIT_FAILURE == imalloc_alloclistSetEntry(NULL, n_allocations) ){
		return EXIT_FAILURE;
	}//Insert NULL as end marker at end if alloclist

	assert( imalloc_alloclistCheckEndMarker() );//Check, if end marker was correctly restored

	return EXIT_SUCCESS;
}

int imalloc_alloclistMoveEndingSubArrayFromTo(unsigned int from, unsigned int to){
	assert( imalloc_alloclistCheckEndMarker() );//Check, if end marker (NULL ptr) exists
	if (from <= n_allocations){
		if (to < n_allocations){ //only do something if from and to are between 0 and n_allocations
			if (from >= to){
				memmove(alloclist+to, alloclist+from, (n_allocations-from+1)*sizeof(void*));//Copy with NULL as end identifier
			}else{
				memmove(alloclist+to, alloclist+from, (n_allocations-to+1)*sizeof(void*));//Copy with NULL as end identifier
			}
			//assert( NULL == alloclist[n_allocations] );//Check, if end marker (NULL ptr) exists
			return EXIT_SUCCESS;
		}
	}
	imalloc_setError(IMALLOCERR_LISTINDEXOUTOFRANGE);
	return EXIT_FAILURE;
}

int imalloc_alloclistRemoveEntryAt(unsigned int at){
	assert( imalloc_alloclistCheckEndMarker() );//Check, if end marker (NULL ptr) exists

	if ( !imalloc_alloclistCheckIndex(at) ){
		imalloc_setError(IMALLOCERR_LISTINDEXOUTOFRANGE);
		return EXIT_FAILURE;
	}

	if (0 < n_allocations){
		imalloc_alloclistMoveEndingSubArrayFromTo(at+1, at);
		//memmove(&alloclist[alloclistpos], &alloclist[alloclistpos+1], (n_allocations-alloclistpos)*sizeof(void*));//Copy with NULL as end identifier
		alloclist = realloc(alloclist, (n_allocations+1)*sizeof(void*));//This is not save. provisorial
	}else{
		alloclist = NULL;
	}

	decreaseAllocationCount();

	return EXIT_SUCCESS;
}
//	**************************************************************
//	** Return number of total allocated blocks					**
//	**************************************************************
unsigned int returnAllocationCount(void){
	return n_allocations;
}

unsigned int increaseAllocationCount(void){
	return ++n_allocations;
}

unsigned int decreaseAllocationCount(void){
	if (n_allocations > 0){//If no allocation has been done, there should be no need to call this function
		return --n_allocations;
	}else{
		imalloc_setError(IMALLOCERR_TOOMUCHCALLSTOIFREE);
		return 0;
	}
}
