#include "../StringLinkedList_internal.h"

bool assertHeadOK(stringlist_Head_t *head){
	if( !(head -> last) ) {	perror("head->last not set"); return true;}
	if( !(head -> first) )	{perror("head->first not set"); return true;}
	if( head -> last -> next != NULL ) {perror("suspicious next pointer in head->last"); return true;}
	if( head -> last -> entry != NULL ) {perror("reserve element should not have string set"); return true;}
	if( head -> last -> prev ? (head)->last->prev->next != (head)->last:false) {perror("prev of head->last not chained correctly"); return true;}
	return false;
}

