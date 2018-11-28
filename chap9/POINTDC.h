#pragma once
#include"CView.h"

class POINTCDC
{
private:
	CView* pView;
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
public:
	POINTCDC(CView* pView);
	virtual ~POINTCDC();
	void GetClientRect();
	void DrawTextCDC();
};