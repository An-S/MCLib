#include "MCLib.h"


size_t MCLib_getVaFieldwidthFromFormatString(const char* const format, va_list va){
	char discard;
	if (!format) return 0;
	return vsnprintf(&discard, 1, format, va);
}

size_t MCLib_getFieldwidthFromFormatString(const char* const format, ...){
	va_list va;
	va_start(va, format);

	return MCLib_getVaFieldwidthFromFormatString(format, va);
    //va_end was omitted because va_list is allocated on stack and this resource is freed automatically
}

