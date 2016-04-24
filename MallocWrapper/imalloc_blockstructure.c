#include "imalloc_internal.h"

int updateAllocatedBlockStructure(void* ptr, size_t size){
	memmove((uint8_t*)ptr+size+sizeof(blockheader_t), &defaultEndMarkerStr, sizeof(defaultEndMarkerStr)); //Copy end marker
	//Todo:Fill new allocated block with zero

	((blockheader_t*) ptr) -> size = size;
	((blockheader_t*) ptr) -> thisptr = ptr;

	return EXIT_SUCCESS;
}

int setupAllocatedBlockStructure(void* ptr, size_t size){
	memmove(ptr, &defaultblockheader, sizeof(blockheader_t));//copy default values. Header
	updateAllocatedBlockStructure(ptr, size);

	assert( checkStructure(ptr) );//Test, if block structure was initialized correctly
	return EXIT_SUCCESS;
}

size_t getBlockSizeIncludingHeaderAndEndmarker(size_t sizeWithoutHeaderAndEndmarker){
	return sizeWithoutHeaderAndEndmarker+sizeof(blockheader_t)+sizeof(defaultEndMarkerStr);
}

void* getAllocatedBlockDataAddress(void* blockstart){
	assert ( checkStructure(blockstart) ); //Security check that blockstart points to valid block

	return (uint8_t*)blockstart+sizeof(blockheader_t);
}

//	**************************************************
//	** Checks if thisptr equals passed ptr			**
//	**************************************************
bool checkThisPtr(void* ptr){
	if ( ((blockheader_t*) ptr) -> thisptr != ptr ) {
		imalloc_setError(IMALLOCERR_THISPTR);
		return false;//assert that thisptr equals given ptr
	}
	return true;
}

//	**************************************************
//	** Checks on existance of magic byte			**
//	**************************************************
bool checkMagic(void* ptr){
	if ( 0 != memcmp( ((blockheader_t*) ptr) -> magic, defaultMagicStr, sizeof(defaultMagicStr)) ) {
		imalloc_setError(IMALLOCERR_MISSINGMAGIC);
		return false;//assert that thisptr equals given ptr
	}
	return true;
}

//	**************************************************
//	** Checks on existance of end indicator			**
//	**************************************************
bool checkEndIndicator(void* ptr){
	if ( 0 != memcmp( (uint8_t*)ptr + ((blockheader_t*) ptr) -> size + sizeof(blockheader_t), defaultEndMarkerStr, sizeof(defaultEndMarkerStr)) ) {
		imalloc_setError(IMALLOCERR_MISSINGBLOCKENDTAG);
		return false;//assert that thisptr equals given ptr
	}
	return true;
}

//	**************************************************
//	** Checks complete structure of block			**
//	** Expects ptr to start of header				**
//	**************************************************
bool checkStructure(void* ptr){
	//Error codes will be set by individual functions
	/*if ( !checkThisPtr(ptr) ) {
		return false;//assert that thisptr equals given ptr
	}*/

	if ( !checkMagic(ptr) ) {
		return false;//assert that magic sequence is found
	}

	if ( !checkEndIndicator(ptr) ) {
		return false;//assert that end marker is existant
	}

	return true;
}
