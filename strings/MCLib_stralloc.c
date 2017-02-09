#include "MCLib_strings.h"

/** \brief allocates memory for c-string that there is also room for '\0'
 *
 * \param CuStringSize_t size
 * \return char* strPtr
 *
 */
char *MCLib_stralloc(size_t strlen)
{
	//allocate room for terminating \0 character, too
    //newly allocated string should be valid and empty, thats why we use Calloc instead of just Alloc
    ++strlen;
    //test on strlen>0 (overflow). string with length 0 does not make sense
    if (strlen){
		char* newStr = (char*) calloc ( sizeof(char), strlen );
		assert (NULL != newStr);

		return newStr;
    }
    //}
    return NULL;
}

