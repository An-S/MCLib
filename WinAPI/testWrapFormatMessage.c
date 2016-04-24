//#define UNICODE

//#include <stdio.h>
//#include <stdlib.h>

//#ifdef UNICODE
 //   #define _sntprintf snwprintf
//#else
//    #define _sntprintf snprintf
//#endif // UNICODE

#include "winapi.h"




int main()
{
    DWORD errNo;

    /*int len1 = snwprintf(NULL, 0, L"Hallo!");
    int len2 = snprintf(NULL, 0, "Hallo!");
    int len3 = _sntprintf(NULL, 0, "Hallo!");
*/
    //printf("Len1:%d, Len2:%d, Len3:%d, sizeof(TCHAR):%d\n", len1, len2, len3, sizeof(TCHAR));

    for (errNo = 0; errNo < 100; ++errNo){
       WinAPI_printSystemErrorMsg(TEXT("Error: "), errNo);
    }

    return 0;
}
