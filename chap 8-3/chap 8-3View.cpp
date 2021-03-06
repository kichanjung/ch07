
// chap 8-3View.cpp: Cchap83View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "chap 8-3.h"
#endif

#include "chap 8-3Doc.h"
#include "chap 8-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cchap83View

IMPLEMENT_DYNCREATE(Cchap83View, CView)

BEGIN_MESSAGE_MAP(Cchap83View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cchap83View 생성/소멸

Cchap83View::Cchap83View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cchap83View::~Cchap83View()
{
}

BOOL Cchap83View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cchap83View 그리기

void Cchap83View::OnDraw(CDC* /*pDC*/)
{
	Cchap83Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void Cchap83View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cchap83View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cchap83View 진단

#ifdef _DEBUG
void Cchap83View::AssertValid() const
{
	CView::AssertValid();
}

void Cchap83View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cchap83Doc* Cchap83View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cchap83Doc)));
	return (Cchap83Doc*)m_pDocument;
}
#endif //_DEBUG


// Cchap83View 메시지 처리기


void Cchap83View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	cxClient = cx;
	cyClient = cy;
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

#define NUM 1000
#define TWOPI (2*3.14159)
void Cchap83View::OnLButtonDown(UINT nFlags, CPoint point)
{
	POINT pt[NUM];
	CClientDC dc(this);
	int i;
	dc.MoveTo(0, cyClient / 2);
	dc.LineTo(cxClient, cyClient / 2);

	dc.MoveTo(cxClient / 2, 0);
	dc.LineTo(cxClient / 2, cyClient);

	for (i = 0; i < NUM; i++) //sin 그래프 
	{
		pt[i].x = i * cxClient / NUM;
		pt[i].y = (int)(cyClient / 2 * (1 - sin(TWOPI*i / NUM)));
	}
	dc.Polyline(pt, NUM);
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnLButtonDown(nFlags, point);
}
