#ifndef __IMALLOC_INTERNAL_H__
#define __IMALLOC_INTERNAL_H__
	#include <stdlib.h>
	#include <stdio.h>
	#include <stddef.h>
	#include <stdbool.h>
	#include <stdint.h>
	#include <assert.h>
	#include <string.h>
	#include <cmacros.h>

	#include "imalloc.h"
	#include "imalloc_helperfunctions.h"

	#define DEFAULTMAGIC "*_iMaL_loC*"
	#define DEFAULTENDMARKER "*_ImaLEn_D*"

	//Use strange spelling to make it nearly improbable that someone fills allocated memory with exactly the DEFAULTMAGIC

	//	**********************************************************************
	//	**	Structure which is placed at beginning of every allocated block	**
	//	**********************************************************************




	int imalloc_setError(int ec);//Setting of error codes will be performed internally, only

	//	**********************************************************
	//	**	Error checking functions							**
	//	**********************************************************
	int setupAllocatedBlockStructure(void* ptr, size_t size);
	int updateAllocatedBlockStructure(void* ptr, size_t size);
	void* getAllocatedBlockDataAddress(void* ptr);
	bool checkStructure(void* ptr);
	bool checkEndIndicator(void* ptr);
	bool checkMagic(void* ptr);
	bool checkThisPtr(void* ptr);
	bool imalloc_isError(void);
	size_t getBlockSizeIncludingHeaderAndEndmarker(size_t sizeWithoutHeaderAndEndmarker);

	unsigned int checkalloclist(void* ptr);
	bool imalloc_alloclistCheckEndMarker(void);
	int imalloc_alloclistAddEntry(void* ptr);
	int imalloc_alloclistRemoveEntry(void* ptr);
	int imalloc_alloclistUpdateEntry(void* oldptr, void* newptr);
	int imalloc_alloclistAddEntryAtEnd(void* ptr);
	int imalloc_alloclistRemoveEntryAt(unsigned int at);
	void** imalloc_alloclistGetEntry(unsigned int pos);
	int imalloc_alloclistSetEntry(void* ptr, unsigned int pos);

	unsigned int returnAllocationCount(void);


	//	**********************************************************
	//	**	Internal defaults									**
	//	**********************************************************


	extern char defaultEndMarkerStr[sizeof(DEFAULTENDMARKER)];
	extern char defaultMagicStr[sizeof(DEFAULTMAGIC)];
	extern char* imalloc_StrErrorMessages[IMALLOC_ERRORCODES_COUNT];
	extern char* imalloc_StrArrayTypes[IMALLOC_ARRAYTYPES_COUNT];
	extern uint8_t imalloc_ElementSizeArrayTypes[IMALLOC_ARRAYTYPES_COUNT];

    typedef struct blockheader_tag {
		size_t headersize;
		size_t size;
		//imalloc_arrayType_t type;
		void* thisptr;
		char magic[sizeof(defaultMagicStr)-1];
	} blockheader_t;

    #define BLOCKHEADER_SIZE sizeof(blockheader_t)

    extern blockheader_t defaultblockheader;
#endif
