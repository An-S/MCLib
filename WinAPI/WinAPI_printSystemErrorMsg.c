#include "winapi.h"

void WinAPI_printSystemErrorMsg(TCHAR *format, DWORD errNo, ...) {
    TCHAR* errorMsg = WinAPI_formatSystemErrorMsg(errNo);
    va_list va;
    va_start(va, errNo);

    if ( errorMsg )
    {
        //Console::Write( (LPTSTR)(errorText)/*.get()*/ );
        _vtprintf(format, va);
        _tprintf("Code %d, %s\n",(int)errNo, errorMsg);

        //std::cout << errorText;

    }else{
        _tprintf("Unable to get errmsg with code %d.\n", (int)errNo);
    }
    LocalFree(errorMsg);
    va_end(va);
}
