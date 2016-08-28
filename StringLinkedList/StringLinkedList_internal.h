#ifndef STRINGLINKEDLIST_INTERNAL_H_INCLUDED
#define STRINGLINKEDLIST_INTERNAL_H_INCLUDED

#include <MallocWrapper\imalloc.h>
#include <MallocWrapper\imalloc_helperfunctions.h>

#include <ModuleTestSupportLib\ModuleTestSupportLib.h>

#include <MCLib.h>
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


#define assertValidList(head) assert( ((head) -> last) ); /*
		*/ assert ( (head) -> first); \
		assert ( (head) -> last -> next == NULL ); /*
		*/ /*assert that entry points to stringlist_Last element in list*/ /*
		*/ assert ( (head) -> last -> entry == NULL ); /*
		*/ /*assert that entry points to reserve element with NULL ptr*/ /*
		*/ assert ( (head) -> last -> prev ? (head)->last->prev->next == (head)->last:true)

#endif // STRINGLINKEDLIST_INTERNAL_H_INCLUDED
