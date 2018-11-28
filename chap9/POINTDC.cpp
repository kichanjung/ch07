#include"POINTDC.h"

POINTCDC::POINTCDC(CView* p)
{
	pView = p;
	hdc = BeginPaint(pView->hwnd, &ps);
}
POINTCDC::~POINTCDC()
{
	EndPaint(pView->hwnd, &ps);
}
void POINTCDC::GetClientRect()
{
	::GetClientRect(pView->hwnd, &rect);
}
void POINTCDC::DrawTextCDC() {
	::DrawText(hdc, "HELLO WINDOW!", -1, &rect,
		DT_SINGLELINE | DT_VCENTER | DT_CENTER);
}