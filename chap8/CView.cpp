#include<math.h>
#include"stdafx.h"
#include"CView.h"
#include"DC.h"

CView app;

BEGIN_MESSAGE_MAP(CView)
{WM_CREATE, &CView::onCreate},
{WM_PAINT, &CView::onDraw},
{WM_DESTROY, &CView::onDestroy},
{WM_SIZE, &CView::OnSize},
{ WM_LBUTTONDOWN, &CView::onLButtonDown },
END_MESSAGE_MAP()

LRESULT CView::onCreate(WPARAM wParam, LPARAM lParam)
{
	return 0L;
}
LRESULT CView::onDraw(WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	hdc = BeginPaint(hwnd, &ps);
	GetClientRect(hwnd, &rect);
	DrawText(hdc, "Hello Windows!", -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	EndPaint(hwnd, &ps);
	return 0;
}
LRESULT CView::onDestroy(WPARAM wParam, LPARAM lParam) {
	PostQuitMessage(0);
	return 0;
}

LRESULT CView::onLButtonDown(WPARAM wParam, LPARAM lParam) {
	int i;
	
	CDC dc(this);//hdc = GetDC(hwnd); 8-1

	dc.MoveToEx( 0, cyClient / 2, NULL);//MoveToEx(hdc, 0, cyClient / 2, NULL); //가로직선
	dc.LineTo( cxClient, cyClient / 2);//LineTo(hdc, cxClient, cyClient / 2);

	dc.MoveToEx( cxClient / 2, 0, NULL);// MoveToEx(hdc, cxClient / 2, 0, NULL); //세로직선
	dc.LineTo( cxClient/2, cyClient); //LineTo(hdc, cxClient/2, cyClient);

	for (i = 0; i < NUM; i++) //sin 그래프 
	{
		pt[i].x = i * cxClient / NUM;
		pt[i].y = (int)(cyClient / 2 * (1 - sin(TWOPI*i / NUM)));
	}
	dc.Polyline( pt, NUM);
	//Polyline(hdc, pt, NUM);

	//ReleaseDC(hwnd, hdc);
	return 0;
}

LRESULT CView::OnSize(WPARAM wParam, LPARAM lParam)
{
	cxClient = LOWORD(lParam);
	cyClient = HIWORD(lParam);
	return 0;
}