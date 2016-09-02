
#include "../StringLinkedList_internal.h"

int stringlist_free(stringlist_Head_t *list){
	//NULL ptr sanity check
	if (list){
		stringlist_SingleEntry_t *entry = stringlist_getLast(list);
		//NULL ptr sanity check also for elem
		if (entry){
			stringlist_SingleEntry_t *preventry = stringlist_getPrev(entry);

			ifree(entry); //deletes first the last, unused element
			while(preventry != NULL){
				assert (preventry -> next == entry );//assert that preventry's next ptr points to entry
				entry = preventry;
				assert (NULL != entry -> entry);//Check for invalid entries
				MCLib_strfree(entry -> entry);
				assert( EXIT_SUCCESS == reportIfimallocError() );
				preventry = stringlist_getPrev(entry);
				ifree(entry);
			};

			ifree(list);

			return EXIT_SUCCESS;
		}
	}
	return EXIT_FAILURE;
}
