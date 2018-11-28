#include<Windows.h>
#include<math.h>
#include"CView.h"
#include"CObject.h"
#include"stdafx.h"
#include"DC.h"
#include"POINTDC.h"
#include"resource.h"
CView app;

BEGIN_MESSAGE_MAP(CView)
{WM_CREATE, &CView::OnCreate},
{WM_PAINT, &CView::OnDraw},
{WM_DESTROY, &CView::OnDestroy},
{WM_SIZE, &CView::OnSize},
{WM_LBUTTONDOWN, &CView::OnLButtonDown},
{WM_COMMAND, &CView::OnCommand},
END_MESSAGE_MAP()

LRESULT CView::OnCreate(WPARAM wParam, LPARAM lParam) {
	hIcon =::LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
	cxIcon = ::GetSystemMetrics(SM_CXICON);
	cyIcon = ::GetSystemMetrics(SM_CYICON);
	return 0L;
}
LRESULT CView::OnDraw(WPARAM wParam, LPARAM lParam)
{
	/*HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;*/
	POINTCDC PI(this);
	void GetClientRect();
	void DrawTextCDC();
	/*hdc = BeginPaint(hwnd, &ps);
	GetClientRect(hwnd, &rect);
	DrawText(hdc, "Hello Windows!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	EndPaint(hwnd, &ps);*/
	return 0;
}

LRESULT CView::OnDestroy(WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
	return 0;
}

LRESULT CView::OnLButtonDown(WPARAM wParam, LPARAM lParam)
{
	int i;
	//hdc = GetDC(hwnd);
	CDC dc(this);
	int x, y;
	dc.MoveToEx(0, cyClient / 2, NULL);//MoveToEx(hdc, 0, cyClient / 2, NULL);
	dc.LineTo(cxClient, cyClient / 2);//LineTo(hdc, cxClient, cyClient / 2);

	for (i = 0; i < NUM; i++)
	{
		pt[i].x = i * cxClient / NUM;
		pt[i].y = (int)(cyClient / 2 * (1 - sin(TWOPI*i / NUM)));
	}
	dc.Polyline(pt, NUM);//Polyline(hdc, pt, NUM);
	//ReleaseDC(hwnd, hdc);
	x = LOWORD(lParam);
	y = HIWORD(lParam);
	DrawIcon(dc.hdc, x, y, hIcon);
	return 0;
}

LRESULT CView::OnSize(WPARAM wParam, LPARAM lParam)
{
	cxClient = LOWORD(lParam);
	cyClient = HIWORD(lParam);
	return 0;
}

LRESULT CView::OnCommand(WPARAM wParam, LPARAM lParam)
{
	HMENU hMenu;
	hMenu = GetMenu(hwnd);
	
	switch (LOWORD(wParam))
	{
	case ID_AAA:
		SendMessage(hwnd, WM_CLOSE, 0, 0L);
		break;
	case ID_BBB:
		SendMessage(hwnd, WM_LBUTTONDOWN, 0, 0L);
		break;
	}
	return 0;
}