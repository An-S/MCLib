#include "MCLib_strings.h"

/** \brief concatenation of c strings with respect to NULL ptr arguments
 *
 * \param CuStringSize_t size
 * \return char* strPtr
 *
 */
char* MCLib_strcat(const char* first, const char* second)
{
	//if either first or second not NULL
	if (first){
		if (second){
			//both input params set -> alloc space to hold concatenated strings
			size_t len = strlen(first)+strlen(second);
			char* newStr = MCLib_stralloc(len);
			//copy first to new string
			strcpy(newStr, first);
			//concatenate second
			strcat(newStr, second);
			//return cat str
			return newStr;
		}else{
		//only make copy of first string as second param contained NULL
            char* newStr = MCLib_strcopy(first);
            return newStr;
		}
	}
	if (second){
		//only make copy of second string as first param contained NULL
		char* newStr = MCLib_strcopy(second);

		return newStr;
	}
	//if both params contained NULL return NULL, too
	return NULL;
}
