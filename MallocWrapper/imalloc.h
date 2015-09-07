#ifndef __IMALLOC_H__
#define __IMALLOC_H__
	#include <stdlib.h>

	void* imalloc(size_t size);
	int ifree(void* ptr);
	int imalloc_getError(void);
	char* imalloc_getErrorMessage(void);
	unsigned int returnAllocationCount(void);
	int imalloc_clearError(void);
	void* irealloc(void* ptr, size_t size);

	#define IMALLOC_ERRCODEANDMESSAGELIST \
		E(IMALLOCERR_LOWEST, "Error code too small"),\
		E(IMALLOCERR_OK, "No error"),\
		E(IMALLOCERR_ALLOCATIONFAILED, "Allocation failed"),\
		E(IMALLOCERR_FREEVERIFY, "Verify error by ifree(void*)"),\
		E(IMALLOCERR_IFREERECEIVEDNULL, "ifree(void*) received NULL pointer"),\
		E(IMALLOCERR_IMALLOCRECEIVEDZERO, "void* imalloc(size_t) received zero size"),\
		E(IMALLOCERR_WRONGERRCODE, "Error code not assigned!"),\
		E(IMALLOCERR_PTRNOTFOUNDINALLOCLIST, "Given address not found in alloclist"),\
		E(IMALLOCERR_INCONSISTENCY, "Detected internal inconsistency"),\
		E(IMALLOCERR_MISSINGBLOCKHEADER, "Missing block header"),\
		E(IMALLOCERR_MISSINGBLOCKENDTAG, "Missing end tag in block"),\
		E(IMALLOCERR_THISPTR, "This pointer does not match block address"),\
		E(IMALLOCERR_SIZE, "Block size differs from specified one"),\
		E(IMALLOCERR_MISSINGMAGIC, "Missing magic byte sequence"),\
		E(IMALLOCERR_TOOMUCHCALLSTOIFREE, "Called ifree too often"),\
		E(IMALLOCERR_LISTINDEXOUTOFRANGE, "Out of range error during access of alloclist"),\
		E(IMALLOCERR_REGISTERADDRESS, "Could not register address in alloclist"),\
		E(IMALLOCERR_HIGHEST, "Error code not assigned!")

	#define IMALLOC_ARRAYTYPES \
		E(IMALLOC_ARRAYTYPE_LOWEST,"",0),\
		E(IMALLOC_ARRAYTYPE_INT,"int",sizeof(int)),\
		E(IMALLOC_ARRAYTYPE_UINT,"uint",sizeof(unsigned int)),\
		E(IMALLOC_ARRAYTYPE_FLOAT,"float",sizeof(float)),\
		E(IMALLOC_ARRAYTYPE_DOUBLE,"double",sizeof(double)),\
		E(IMALLOC_ARRAYTYPE_SHORT,"short",sizeof(short)),\
		E(IMALLOC_ARRAYTYPE_USHORT,"ushort",sizeof(unsigned short)),\
		E(IMALLOC_ARRAYTYPE_CHAR,"char",sizeof(char)),\
		E(IMALLOC_ARRAYTYPE_UCHAR,"uchar",sizeof(unsigned char)),\
		E(IMALLOC_ARRAYTYPE_UINT8,"uint8_t",sizeof(uint8_t)),\
		E(IMALLOC_ARRAYTYPE_UINT16,"uint16_t",sizeof(uint16_t)),\
		E(IMALLOC_ARRAYTYPE_UINT32,"uint32_t",sizeof(uint32_t)),\
		E(IMALLOC_ARRAYTYPE_INT8,"int8_t",sizeof(int8_t)),\
		E(IMALLOC_ARRAYTYPE_INT16,"int16_t",sizeof(int16_t)),\
		E(IMALLOC_ARRAYTYPE_INT32,"int32_t",sizeof(int32_t)),\
		E(IMALLOC_ARRAYTYPE_USER,"userdef",0),\
		E(IMALLOC_ARRAYTYPE_HIGHEST,"",0)

	#define E(x,y,z) x
		typedef enum {IMALLOC_ARRAYTYPES} imalloc_arrayType_t;
	#undef E
	#define IMALLOC_ARRAYTYPES_COUNT (IMALLOC_ARRAYTYPE_HIGHEST-IMALLOC_ARRAYTYPE_LOWEST+1)

	/*case IMALLOCERR_OK:
		return "no error";
		break;
	case IMALLOCERR_FREEVERIFY:
		return "Verify error by ifree(void*)";
		break;
	case IMALLOCERR_IFREERECEIVEDNULL:
		return "ifree(void*) received NULL pointer";
		break;
	case IMALLOCERR_IMALLOCRECEIVEDZERO:
		return "void* imalloc(size_t) received zero size";
		break;
	case IMALLOCERR_WRONGERRCODE:
		return "Error code not assigned!";
		break;
	case IMALLOCERR_PTRNOTFOUNDINALLOCLIST:
		return "Free received ptr to memory which was not previously allocated by void* imalloc(size_t)";
		break;
	case IMALLOCERR_INCONSISTENCY:
		return "Detected internal inconsistency";
		break;
	default:
		return "Error code was falsely not considered";
		break;*/

	/*enum imalloc_errorcodes{IMALLOCERR_LOWEST, IMALLOCERR_OK, IMALLOCERR_ALLOCATIONFAILED, IMALLOCERR_FREEVERIFY,
		IMALLOCERR_IFREERECEIVEDNULL,
		IMALLOCERR_IMALLOCRECEIVEDZERO, IMALLOCERR_WRONGERRCODE, IMALLOCERR_PTRNOTFOUNDINALLOCLIST,
		IMALLOCERR_INCONSISTENCY, IMALLOCERR_HIGHEST};
	*/

	#define E(x,y) x
	enum imalloc_errorcodes{IMALLOC_ERRCODEANDMESSAGELIST};
	#undef E
	#define IMALLOC_ERRORCODES_COUNT (IMALLOCERR_HIGHEST-IMALLOCERR_LOWEST+1)
#endif
