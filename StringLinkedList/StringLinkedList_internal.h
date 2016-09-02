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

//only 0-255 should be used in enum
typedef uint8_t stringlist_IterDirection_t;
enum STRINGLIST_ITER_DIRECTIONS{BACKWARD, FORWARD};
typedef struct stringlist_Iter_tag{
	size_t currentPos;
	stringlist_SingleEntry_t *elemPtr;
	stringlist_IterDirection_t direction;
}stringlist_Iter_t;

//private prototypes
int stringlist_initEntry(stringlist_SingleEntry_t *sle);
bool assertHeadOK(stringlist_Head_t *head);
size_t stringlist_incElemCnt(stringlist_Head_t *head);
size_t stringlist_decElemCnt(stringlist_Head_t *head);
uint8_t stringlist_setFirst(stringlist_Head_t *head, stringlist_SingleEntry_t *first);
uint8_t stringlist_setLast(stringlist_Head_t *head, stringlist_SingleEntry_t *last);
uint8_t stringlist_setString(stringlist_SingleEntry_t *elem, char *newstr);
stringlist_SingleEntry_t *stringlist_createEmptyElem(void);

#define assertValidList(head) assert(!assertHeadOK(head))

#endif // STRINGLINKEDLIST_INTERNAL_H_INCLUDED
