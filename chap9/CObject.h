#pragma once
#include<Windows.h>


#ifndef _CObject_
#define _CObject_
class CObject {
protected:
	static char szAppName[];
	HWND		hwnd;
	MSG			msg;
	WNDCLASSEX	wndclass;

public:
	HINSTANCE hInst; //9���ҽ�����
	void InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow);
	void Run();
	WPARAM ExitInstance();
};

#endif