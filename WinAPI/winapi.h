#ifndef WINAPI_H_INCLUDED
#define WINAPI_H_INCLUDED

#include <stdheaders.h>
#include <TCHAR.h>

TCHAR* WinAPI_formatSystemErrorMsg(DWORD errorNo);
void WinAPI_printSystemErrorMsg(TCHAR *format, DWORD errNo, ...);

#endif // WINAPI_H_INCLUDED
