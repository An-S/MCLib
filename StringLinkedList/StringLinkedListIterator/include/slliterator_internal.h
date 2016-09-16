#ifndef SLLITERATOR_INTERNAL_H_INCLUDED
#define SLLITERATOR_INTERNAL_H_INCLUDED


#include <StringLinkedList.h>

//only 0-255 should be used in enum
typedef size_t sllIterator_Pos_t;
typedef uint8_t sllIterator_Direction_t;
enum STRINGLIST_ITER_DIRECTIONS{SLLIT_BACKWARD, SLLIT_FORWARD};

#include <slliterator.h>

typedef struct sllIterator_tag{
	sllIterator_Pos_t currentPos;
	stringlist_SingleEntry_t *elemPtr;
	sllIterator_Direction_t direction;
}sllIterator_t;

sllIterator_t* sllIterator_alloc(void);
sllIterator_Direction_t slliterator_getDir(sllIterator_t *it);
stringlist_SingleEntry_t *slliterator_set(sllIterator_t *it, stringlist_SingleEntry_t *elem);
stringlist_SingleEntry_t *slliterator_conditionalMove(bool TforthFback, sllIterator_t *it);


#endif // SLLITERATOR_INTERNAL_H_INCLUDED
