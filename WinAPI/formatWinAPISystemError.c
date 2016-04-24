#include "winapi.h"

TCHAR* WinAPI_formatSystemErrorMsg(DWORD errorNo) {
	TCHAR* errorMsg = NULL; //explicitely NULL ptr
	//TCHAR format[] = TEXT("Code: %d, %s");

	//std::wstringstream sstream;
	//std::unique_ptr<std::wstring> composedErrorMsg(new std::wstring);

	//*composedErrorMsg = L"test";

	FormatMessage(
		// use system message tables to retrieve error text
		FORMAT_MESSAGE_FROM_SYSTEM
		// allocate buffer on local heap for error text
		| FORMAT_MESSAGE_ALLOCATE_BUFFER
		// Important! will fail otherwise, since we're not
		// (and CANNOT) pass insertion parameters
		| FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,    // unused with FORMAT_MESSAGE_FROM_SYSTEM
		errorNo,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&errorMsg,//.get(),  // output
		0, // minimum size for output buffer
		NULL);   // arguments - see note

    //TCHAR *composedErrorMsg = LocalAlloc(_sntprintf(NULL,0,format, (int)errorNo, errorMsg)+1,sizeof(TCHAR));
	//_sntprintf(composedErrorMsg, 500, format, (int)errorNo, errorMsg);
	//LocalFree(errorMsg);
	//composedErrorMsg->a ssign(sstream.str().c_str());
	return errorMsg;//composedErrorMsg;
}
