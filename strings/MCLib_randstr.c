#include "MCLib_strings.h"

char *MCLib_randstrLen(uint8_t len, char cmin, char cmax){
	//allocate space of random string with length "len"
	char *randstr = MCLib_stralloc(len);

    //test on NULL ptr
    if (randstr){
		int i = len; char rc;
		if (!cmin) cmin = 1;
		for (;i!=0;--i){
			rc = rand()*(cmax-cmin)/RAND_MAX+cmin;
			randstr[i] = rc;
		}
		return randstr;
    }
    return NULL;
}


/** \brief generates random string of specific length
 *
 * \param uint8_t lenmin, uint8_t lenmax, char cmin, char cmax
 * \return char* strPtr
 *
 */
char *MCLib_randstr(uint8_t lenmin, uint8_t lenmax, char cmin, char cmax)
{
	uint8_t len;
	//upper bits are more random
	srand(clock()>>(8*(sizeof(clock_t)-sizeof(unsigned int))) );
	len = rand()*(lenmax-lenmin)/RAND_MAX+lenmin;

	{char *randstr = MCLib_randstrLen(len, cmin, cmax);

    return randstr;
	}
}
