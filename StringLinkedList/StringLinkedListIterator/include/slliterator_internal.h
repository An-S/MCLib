#ifndef SLLITERATOR_INTERNAL_H_INCLUDED
#define SLLITERATOR_INTERNAL_H_INCLUDED

#include <slliterator.h>
#include <StringLinkedList.h>

//only 0-255 should be used in enum
typedef uint8_t sllIterator_Direction_t;
enum STRINGLIST_ITER_DIRECTIONS{SLLIT_BACKWARD, SLLIT_FORWARD};
typedef struct sllIterator_tag{
	size_t currentPos;
	stringlist_SingleEntry_t *elemPtr;
	sllIterator_Direction_t direction;
}sllIterator_t;
sllIterator_t* sllIterator_alloc(void);

#endif // SLLITERATOR_INTERNAL_H_INCLUDED
