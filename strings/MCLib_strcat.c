#include "MCLib_strings.h"

/** \brief allocates memory for duplication of c-string and then copies the content of the original c-string to the new address
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
			
		}
		size_t len = strlen(first)+strlen(second);
		char* newStr = MCLib_stralloc(len); //= CuAlloc(strlen(old)+1);//CuStrAlloc(len + 1);
		strcpy(newStr, first);
		strcat(newStr, second);
		return newStr;
	}
	return NULL;
}
