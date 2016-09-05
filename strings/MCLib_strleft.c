#include "MCLib_strings.h"

/** \brief returns left part of a string. if length given exceeds string length, the whole
 * \brief string is returned
 * \param CuStringSize_t size
 * \return copy of desired part of string
 *
 */
char *MCLib_strleft(char* str, size_t len)
{
	//first test if NULL was passed accidently
	if (str){
		//now test if length param exceeds string length of original string
		//if so return complete copy of string
		if (len >= strlen(str) ) return MCLib_strcopy(str);
		//test if a zero length was passed
		if (len){
			//not zero length -> return copy of left part of string
			char *newstr = MCLib_stralloc(len);
			strncpy(newstr, str, len);
		}
		//when reached here, string length was zero
	}
	//if reached here then an error occured (either zero string length or str param was NULL
	return NULL;
}

