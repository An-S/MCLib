// The functions contained in this file are pretty dummy
// and are included only as a placeholder. Nevertheless,
// they *will* get included in the static library if you
// don't remove them :)
//
// Obviously, you 'll have to write yourself the super-duper
// functions to include in the resulting library...
// Also, it's not necessary to write every function in this file.
// Feel free to add more files in this project. They will be
// included in the resulting library.

// A function adding two integers and returning the result
#include "StringLinkedList_internal.h"

int main(void){
    stringlist_Head_t *list = stringlist_Create();

    printNumberOfAllocations();

    stringlist_AddListEntry("first");
    printNumberOfAllocations();
    stringlist_AddListEntry("second");
    printNumberOfAllocations();
    stringlist_AddListEntry("third");
    printNumberOfAllocations();
    stringlist_AddListEntry("fourth");
    printNumberOfAllocations();
    stringlist_OutputAllEntries();
    stringlist_Free();
    printNumberOfAllocations();


    stringlist_addListEntry("fifth", list);
    printNumberOfAllocations();
    stringlist_addListEntry("sixth", list);
    printNumberOfAllocations();
    stringlist_addListEntry("seventh", list);
    printNumberOfAllocations();
    stringlist_addListEntry("eighth", list);
    printNumberOfAllocations();
    stringlist_outputAllEntries(list);
    stringlist_free(list);
    printNumberOfAllocations();
	return EXIT_SUCCESS;
}
