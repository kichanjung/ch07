#include"CWnd.h"

IMPLEMENT_DYNCREATE(CWnd)

HWND CWnd::GetSafeHwnd()
{
	return this == NULL ? NULL : m_hwnd;
}


