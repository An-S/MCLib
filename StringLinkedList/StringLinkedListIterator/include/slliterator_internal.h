#ifndef SLLITERATOR_INTERNAL_H_INCLUDED
#define SLLITERATOR_INTERNAL_H_INCLUDED

#include "slliterator.h"

//only 0-255 should be used in enum
typedef uint8_t stringlist_IterDirection_t;
enum STRINGLIST_ITER_DIRECTIONS{BACKWARD, FORWARD};
typedef struct sllIterator_tag{
	size_t currentPos;
	stringlist_SingleEntry_t *elemPtr;
	stringlist_IterDirection_t direction;
}sllIterator_t;

#endif // SLLITERATOR_INTERNAL_H_INCLUDED
