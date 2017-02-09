#ifndef MCLIB_STRINGS_H_INCLUDED
#define MCLIB_STRINGS_H_INCLUDED


size_t MCLib_getVaFieldwidthFromFormatString(const char* const format, va_list va);
size_t MCLib_getFieldwidthFromFormatString(const char* const format, ...);

#endif // MCLIB_STRINGS_H_INCLUDED
