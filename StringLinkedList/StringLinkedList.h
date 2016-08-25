#ifndef STRINGLINKEDLIST_H_INCLUDED
#define STRINGLINKEDLIST_H_INCLUDED

//typedef struct X stringlist_SingleEntry_t;
#include <stdheaders.h>

typedef struct stringlist_SingleEntry_tag stringlist_SingleEntry_t;
typedef struct stringlist_Head_tag stringlist_Head_t;

int stringlist_addListEntry(char* newEntry, stringlist_Head_t *list);
int stringlist_removeLastEntry(stringlist_Head_t *head);
int stringlist_removeFirstEntry(stringlist_Head_t *head);
int stringlist_outputAllEntries(stringlist_Head_t *list);
int stringlist_free(stringlist_Head_t *list);
stringlist_Head_t *stringlist_create(void);

#endif // STRINGLINKEDLIST_H_INCLUDED
