#include "imalloc_internal.h"

//	**************************************************************
//	** Searches list of allocated blocks for matching pointer	**
//	**************************************************************
unsigned int checkalloclist(void* ptr){
	unsigned int i;
	unsigned int returnval = ~0;
	void* singleAlloclistEntry = NULL;
	unsigned int allocCount = returnAllocationCount();

	assert(NULL != ptr); //NULL ptr should not be passed to this functional depth
	for (i=0; i < allocCount; ++i){
		singleAlloclistEntry = imalloc_alloclistGetEntry(i);
		if (imalloc_isError() ) break;//Tracks possible error during alloclist access
		//imalloc_alloclistGetEntry returns NULL on error

		if (singleAlloclistEntry == ptr){
			returnval = i;
			break;//Exit for loop, if right entry was found
		}

		assert (NULL != singleAlloclistEntry);//Should have been tracked before
	}
	assert ( imalloc_alloclistCheckEndMarker() );//Check, if alloclist end indicator is found

	return returnval; //Maximum value of unsigned int (bitwise not 0)
}

int imalloc_alloclistAddEntry(void* ptr){
	assert(NULL != ptr);//Assert, that valid ptr is given

	imalloc_alloclistAddEntryAtEnd(ptr);

	return EXIT_SUCCESS;
}

int imalloc_alloclistRemoveEntry(void* ptr){
	unsigned int alloclistpos = checkalloclist(ptr);

	if ((unsigned)~0 == alloclistpos){
		if (returnAllocationCount() > 0){
			imalloc_setError(IMALLOCERR_PTRNOTFOUNDINALLOCLIST);
		}else{
			imalloc_setError(IMALLOCERR_TOOMUCHCALLSTOIFREE);
		}
		return EXIT_FAILURE;
	};

	if (!checkStructure(ptr) || !checkThisPtr(ptr)){
		return EXIT_FAILURE;
	}

	imalloc_alloclistRemoveEntryAt(alloclistpos);
	free(ptr);

	return EXIT_SUCCESS;
}

int imalloc_alloclistUpdateEntry(void* oldptr, void* newptr){
	unsigned int alloclistpos = checkalloclist(oldptr);//checkalloclist provides assert(ptr!=NULL) already
	if ((unsigned)~0 == alloclistpos){ //If address not found in list -> error
		imalloc_setError(IMALLOCERR_PTRNOTFOUNDINALLOCLIST);
		return EXIT_FAILURE;
	};

	assert (checkStructure(newptr)); //There should be no error with newptr before, errors should have been tracked in callers
	assert (checkThisPtr(newptr));
	/*if (!checkStructure(newptr) || !checkThisPtr(newptr)){
		return EXIT_FAILURE;
	}*/

	//assert (0<=alloclistpos);//Assert validity range of pos in alloclist
	//assert (alloclistpos < n_allocations);
	return imalloc_alloclistSetEntry(newptr, alloclistpos);
}
