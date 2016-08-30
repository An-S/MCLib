#ifndef STRINGLINKEDLIST_INTERNAL_H_INCLUDED
#define STRINGLINKEDLIST_INTERNAL_H_INCLUDED

#include <MallocWrapper\imalloc.h>
#include <MallocWrapper\imalloc_helperfunctions.h>

#include <ModuleTestSupportLib\ModuleTestSupportLib.h>

#include <MCLib.h>
#include "StringLinkedList.h"

//private struct definitions

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

//private prototypes
int stringlist_initEntry(stringlist_SingleEntry_t *sle);
bool assertHeadOK(stringlist_Head_t *head);

#define assertValidList(head) assert(!assertHeadOK(head))

#endif // STRINGLINKEDLIST_INTERNAL_H_INCLUDED
