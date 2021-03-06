
// chap 7View.cpp: Cchap7View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "chap 7.h"
#endif

#include "chap 7Doc.h"
#include "chap 7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cchap7View

IMPLEMENT_DYNCREATE(Cchap7View, CView)

BEGIN_MESSAGE_MAP(Cchap7View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cchap7View 생성/소멸

Cchap7View::Cchap7View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cchap7View::~Cchap7View()
{
}

BOOL Cchap7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cchap7View 그리기

void Cchap7View::OnDraw(CDC* /*pDC*/)
{
	Cchap7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void Cchap7View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cchap7View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cchap7View 진단

#ifdef _DEBUG
void Cchap7View::AssertValid() const
{
	CView::AssertValid();
}

void Cchap7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cchap7Doc* Cchap7View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cchap7Doc)));
	return (Cchap7Doc*)m_pDocument;
}
#endif //_DEBUG


// Cchap7View 메시지 처리기
