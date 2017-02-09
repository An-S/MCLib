#include "MCLib_strings.h"

/** \brief allocates memory for duplication of c-string and then copies the content of the original c-string to the new address
 *
 * \param CuStringSize_t size
 * \return char* strPtr
 *
 */
char* MCLib_strcopy(const char* old)
{
	//first test if NULL was passed accidently
	if (old){
		//ok, original not NULL, so alloc space for newStr
		char* newStr = MCLib_stralloc(strlen(old));
		//now, check if alloc failed.
		if (newStr){
			//if ok then copy string
			strcpy(newStr, old);
			//and pass it back by ref
			return newStr;
		}
	}
	//if reached here then an error occured
	return NULL;
}
