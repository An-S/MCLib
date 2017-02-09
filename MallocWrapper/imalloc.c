#include "imalloc_internal.h"
unsigned int n_imalloccalls = 0;
unsigned int n_ifreecalls = 0;

//	**************************************************************
//	** Check for inconsistency in protocol variables			**
//	**************************************************************
/*int imalloc_inconsistencyCheck(void){
	if (n_allocations != (n_plainallocs - n_plainfrees)){
		imalloc_setError(IMALLOCERR_INCONSISTENCY);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}*/

//	**************************************************************
//	** add blockheader and endmarker size to argument			**
//	**************************************************************


//give type and size information, return number of entry to secure access to data
void* imalloc(size_t size){
	void* ptr = NULL;

	if (size > 0){ //if size == 0 -> malloc return value is implementation dependent
		ptr = malloc(getBlockSizeIncludingHeaderAndEndmarker(size));
		if ( NULL == ptr ){
			imalloc_setError(IMALLOCERR_ALLOCATIONFAILED);
			return NULL;
		}
		if ( EXIT_SUCCESS == imalloc_alloclistAddEntry(ptr) ){
			++n_imalloccalls;
			assert(n_imalloccalls - n_ifreecalls == returnAllocationCount());
			//Assert, that number of frees und mallocs matches allocation count

			setupAllocatedBlockStructure(ptr, size);

			return getAllocatedBlockDataAddress(ptr); //-> return NULL, if size == 0 or malloc failed. else return pointer to allocated mem
		}else{
			imalloc_setError(IMALLOCERR_REGISTERADDRESS);
			return NULL;
		}
	}else{
		imalloc_setError(IMALLOCERR_IMALLOCRECEIVEDZERO);
		return NULL;
	}

}

void* irealloc(void* ptr, size_t size){

	unsigned int newblocksize = getBlockSizeIncludingHeaderAndEndmarker(size);

	if (NULL != ptr){
        void* sptr = (uint8_t*)ptr-sizeof(blockheader_t);
		unsigned int alloclistpos = checkalloclist(sptr);
		if ((unsigned)~0 == alloclistpos){
			imalloc_setError(IMALLOCERR_PTRNOTFOUNDINALLOCLIST);
			return NULL;
		};
		if ( !checkStructure(sptr) ) {
			return NULL;//assert that thisptr equals given ptr
		}

		sptr = realloc(sptr, newblocksize);
		if (NULL == sptr){
			imalloc_setError(IMALLOCERR_ALLOCATIONFAILED);
			return NULL;
		}

		updateAllocatedBlockStructure(sptr, size);
		//ToDo:
		//1. calculate size including header and end marker -> OK
		//2. realloc memory -> OK

		//3. move end marker to new end	-> OK
		//4. erase old end marker
		imalloc_alloclistUpdateEntry(ptr-

                               BLOCKHEADER_SIZE*
                               sizeof(char)
                               ,sptr);//Overwrite old entry with new address
		//The UpdateEntry sub checks structure a second time as changes were made

		return (uint8_t*)sptr+sizeof(blockheader_t);
	}else{
		//imalloc_setError(IMALLOCERR_IREALLOCRECEIVEDNULL);
		return NULL;
	}
}


int ifree(void* ptr){
	void* sptr = NULL;

	if (NULL != ptr){
		sptr = (uint8_t*)ptr-sizeof(blockheader_t);


		if ( EXIT_SUCCESS == imalloc_alloclistRemoveEntry(sptr) ){
			++n_ifreecalls;
			assert(n_imalloccalls - n_ifreecalls == returnAllocationCount());
		}else{
			return EXIT_FAILURE;
		}
		//Assert, that number of frees und mallocs matches allocation count

		return EXIT_SUCCESS;
	}else{
		imalloc_setError(IMALLOCERR_IFREERECEIVEDNULL);
		return EXIT_FAILURE;
	}
}



