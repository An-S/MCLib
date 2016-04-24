#ifndef STRINGLINKEDLIST_INTERNAL_H_INCLUDED
#define STRINGLINKEDLIST_INTERNAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include <MallocWrapper\imalloc.h>
#include <MallocWrapper\imalloc_helperfunctions.h>

#include <ModuleTestSupportLib\ModuleTestSupportLib.h>
#include "StringLinkedList.h"

typedef struct stringlist_SingleEntry_tag{
	char* entry;
	struct stringlist_SingleEntry_tag* next;
	struct stringlist_SingleEntry_tag* prev;
}stringlist_SingleEntry_t;

#endif // STRINGLINKEDLIST_INTERNAL_H_INCLUDED
