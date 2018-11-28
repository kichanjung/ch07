#pragma once
#include<Windows.h>
#include"stdafx.h"
#include"CObject.h"


#ifndef _CView_
#define _CView_


class CView;

typedef LRESULT(CView::*CViewFunPointer)(WPARAM, LPARAM);

typedef struct tagMessageMap {
	UINT iMsg;
	CViewFunPointer fp;
}MessageMap;

static CViewFunPointer fpCViewGlobal;

#define NUM		1000
#define TWOPI	(2*3.14159)

class CView : public CObject {
public:
	CObject::hwnd;
public:
	PAINTSTRUCT ps;
	POINT pt[NUM];
	HDC hdc;
	int cyClient;
	int cxClient;
	int cxIcon, cyIcon;
	HICON hIcon;

	LRESULT OnCreate(WPARAM, LPARAM);
	LRESULT OnDraw(WPARAM, LPARAM);
	LRESULT OnDestroy(WPARAM, LPARAM);
	LRESULT OnSize(WPARAM wParam, LPARAM lParam);
	LRESULT OnLButtonDown(WPARAM, LPARAM);
	LRESULT OnCommand(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
};

#endif