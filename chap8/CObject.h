#pragma once
#include<Windows.h>

#ifndef _CObject_
#define _CObject_

class CObject {
protected:
	static char szAppName[];
	HWND			hwnd;
	MSG				msg;
	WNDCLASSEX		wndclass;

public:
	void InitInstance(HINSTANCE hInstance, PSTR szCmdLiine, int iCmdShow);
	void Run();
	WPARAM ExitInstance();
};//class CObject

#endif // !_CObject
