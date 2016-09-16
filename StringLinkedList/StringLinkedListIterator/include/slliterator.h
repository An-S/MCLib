#ifndef SLLITERATOR_H_INCLUDED
#define SLLITERATOR_H_INCLUDED


typedef struct sllIterator_tag sllIterator_t;

sllIterator_Pos_t slliterator_getPos(sllIterator_t *it);
stringlist_SingleEntry_t *slliterator_proceed(sllIterator_t *it);
stringlist_SingleEntry_t *slliterator_retreat(sllIterator_t *it, stringlist_SingleEntry_t *elem);
stringlist_SingleEntry_t *slliterator_get(sllIterator_t *it);

#endif // SLLITERATOR_H_INCLUDED
