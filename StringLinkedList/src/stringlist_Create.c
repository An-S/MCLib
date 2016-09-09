
#include "../StringLinkedList_internal.h"

stringlist_Head_t* stringlist_create(void){
    stringlist_Head_t* head = imalloc(sizeof(stringlist_Head_t));
    if( TESTFAILURE(reportIfimallocError()) ) return NULL;

    //add empty entry at top of the linked list so that
    //we do not need to test if there are elements
    head -> first =
    head -> last =
    imalloc(sizeof(stringlist_SingleEntry_t));
    //RETURNONFAILURE( reportIfimallocError() );

    //getFirst does not work here because it asserts head->first->prev == NULL and head->first was not init at this time
    stringlist_initEntry(head -> first/*stringlist_getFirst(head)*/);

    // we do not count empty entries. they are filled by AddListEntry
    head -> elemCnt = 0;
    // use UINT_MAX for maxElemCnt, which is more or less equivalent to unlimited entries
    head -> maxElemCnt = UINT_MAX;
    return head;
}
