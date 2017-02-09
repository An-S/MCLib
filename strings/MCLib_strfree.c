
#include "MCLib_strings.h"

/** \brief overwrites string content with repeated '?' and then frees mem allocated by string
 *
 * \param CuStringSize_t size
 * \return char* strPtr
 *
 */
uint8_t MCLib_strfree(char* str)
{
	//first test if NULL was passed accidently
	if (str){
		//ok, fill string with '?'
		memset(str, '?', strlen(str));
		//now free. if string is used accidently after, a row of '?' is output
		free(str);
		return EXIT_SUCCESS;
	}
	//if reached here then an error occured
	return EXIT_FAILURE;
}
