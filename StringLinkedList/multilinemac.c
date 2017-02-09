/* ========================================================================== */
/*                                                                            */
/*   Filename.c                                                               */
/*   (c) 2012 Author                                                          */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

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

#define assertValidList(head) assert( ((head) -> last) ); /*assert head -> last set
		*/ assert ( (head) -> first); /*assert head -> first set
		*/ assert ( (head) -> last -> next == NULL ); /*assert that successor of reserve element is not set
		*/ assert ( (head) -> last -> entry == NULL ); /*assert that entry of reserve element is not set
		*/ assert ( (head) -> last -> prev ? (head)->last->prev->next == (head)->last:true)
		/*assert that entry points to reserve element with NULL ptr */

#define expandml mein /* erste zeile
  */ multi /* zweite zeile
  */ line /*  dritte zeile
  */ macro
  
void main()
{
    assertValidList( (stringlist_Head_t*) 1234);
}
