#ifndef sllIterator_H_INCLUDED
#define sllIterator_H_INCLUDED


typedef struct sllIterator_tag sllIterator_t;
//only 0-255 should be used in enum
typedef size_t sllIterator_Pos_t;
typedef uint8_t sllIterator_Direction_t;
enum STRINGLIST_ITER_DIRECTIONS{SLLIT_BACKWARD, SLLIT_FORWARD};

sllIterator_Pos_t sllIterator_getPos(sllIterator_t *it);
stringlist_SingleEntry_t *sllIterator_proceed(sllIterator_t *it);
stringlist_SingleEntry_t *sllIterator_retreat(sllIterator_t *it, stringlist_SingleEntry_t *elem);
stringlist_SingleEntry_t *sllIterator_get(sllIterator_t *it);
sllIterator_t* sllIterator_create(stringlist_Head_t *head, sllIterator_Direction_t dir);

#endif // sllIterator_H_INCLUDED
