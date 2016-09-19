#ifndef sllIterator_INTERNAL_H_INCLUDED
#define sllIterator_INTERNAL_H_INCLUDED


#include <StringLinkedList.h>



#include <sllIterator.h>

typedef struct sllIterator_tag{
	sllIterator_Pos_t currentPos;
	stringlist_SingleEntry_t *elemPtr;
	sllIterator_Direction_t direction;
}sllIterator_t;

sllIterator_t* sllIterator_alloc(void);
sllIterator_Direction_t sllIterator_getDir(sllIterator_t *it);
stringlist_SingleEntry_t *sllIterator_set(sllIterator_t *it, stringlist_SingleEntry_t *elem);
stringlist_SingleEntry_t *sllIterator_conditionalMove(bool TforthFback, sllIterator_t *it);


#endif // sllIterator_INTERNAL_H_INCLUDED
