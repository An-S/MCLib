#ifndef MCLIB_STRINGS_H_INCLUDED
#define MCLIB_STRINGS_H_INCLUDED

#include "../MCLib.h"

size_t MCLib_getVaFieldwidthFromFormatString(const char* const format, va_list va);
size_t MCLib_getFieldwidthFromFormatString(const char* const format, ...);
char *MCLib_stralloc(size_t strlen);
char* MCLib_strcat(const char* first, const char* second);
char* MCLib_strcopy(const char* old);
uint8_t MCLib_strfree(char* str);
char *MCLib_strleft(char* str, size_t len);
char *MCLib_randstr(uint8_t lenmin, uint8_t lenmax, char cmin, char cmax);
char *MCLib_randstrLen(uint8_t len, char cmin, char cmax);

#endif // MCLIB_STRINGS_H_INCLUDED
