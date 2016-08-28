#ifndef STRINGLINKEDLIST_INTERNAL_H_INCLUDED
#define STRINGLINKEDLIST_INTERNAL_H_INCLUDED

#include <MallocWrapper\imalloc.h>
#include <MallocWrapper\imalloc_helperfunctions.h>

#include <ModuleTestSupportLib\ModuleTestSupportLib.h>
#include "StringLinkedList.h"

/** \brief typedef for elements of linked list
 *
 * \param
 * \param
 * \return
 *
 */
typedef struct stringlist_SingleEntry_tag{
	char* entry;
	struct stringlist_SingleEntry_tag* next;
	struct stringlist_SingleEntry_tag* prev;
}stringlist_SingleEntry_t;


typedef struct stringlist_Head_tag{
	size_t elemCnt;
	struct stringlist_SingleEntry_tag* first;
	struct stringlist_SingleEntry_tag* last;
}stringlist_Head_t;

int stringlist_initEntry(stringlist_SingleEntry_t *sle);

#endif // STRINGLINKEDLIST_INTERNAL_H_INCLUDED
