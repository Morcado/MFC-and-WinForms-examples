// ShortCutView.cpp : implementation of the CShortCutView class
//

#include "stdafx.h"
#include "ShortCut.h"

#include "ShortCutDoc.h"
#include "ShortCutView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShortCutView

IMPLEMENT_DYNCREATE(CShortCutView, CView)

BEGIN_MESSAGE_MAP(CShortCutView, CView)
	//{{AFX_MSG_MAP(CShortCutView)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDM_PLUMA, OnPluma)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShortCutView construction/destruction

CShortCutView::CShortCutView(){
    Pband = false;
	band = false;
    bandfinal = false;
}

CShortCutView::~CShortCutView(){
}

BOOL CShortCutView::PreCreateWindow(CREATESTRUCT& cs){
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShortCutView drawing

void CShortCutView::OnDraw(CDC* pDC){
	CShortCutDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
    pluma = new CPen();
    pDC->SetROP2(R2_NOTXORPEN);
    if(Pband){
        if(band){
        
            pluma->CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
            plumaOld = pDC->SelectObject(pluma);

            pDC->MoveTo(punto);
            pDC->LineTo(punto2);
            Sleep(20);
            pDC->MoveTo(punto);
            pDC->LineTo(punto2);
            pDC->SelectObject(plumaOld);
            pluma->DeleteObject();
        }   
        else{
            if(bandfinal){
                pluma->CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
                plumaOld = pDC->SelectObject(pluma);
                pDC->MoveTo(punto);
                pDC->LineTo(punto2);
                pDC->SelectObject(plumaOld);
                pluma->DeleteObject();
            }
        }
    }
    
}

/////////////////////////////////////////////////////////////////////////////
// CShortCutView diagnostics

#ifdef _DEBUG
void CShortCutView::AssertValid() const{
	CView::AssertValid();
}

void CShortCutView::Dump(CDumpContext& dc) const{
	CView::Dump(dc);
}

CShortCutDoc* CShortCutView::GetDocument(){
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShortCutDoc)));
	return (CShortCutDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShortCutView message handlers

void CShortCutView::OnLButtonDown(UINT nFlags, CPoint point){
    punto = point;
    band = true;

    //cursor = SetCursor(IDC_CROSS);
    ::AfxGetApp()->LoadStandardCursor(IDC_ARROW);
    
    Invalidate(false);
	CView::OnLButtonDown(nFlags, point);
}

void CShortCutView::OnPluma(){
    Pband = !Pband;
}

void CShortCutView::OnMouseMove(UINT nFlags, CPoint point) {
    if(MK_LBUTTON && band){
        //::AfxGetApp()->LoadStandardCursor(IDC_ARROW);
        //::AfxGetApp()->LoadCursor(IDC_CROSS);
        punto2 = point;
        Invalidate(false);
    }
	CView::OnMouseMove(nFlags, point);
}

void CShortCutView::OnLButtonUp(UINT nFlags, CPoint point){
    band = false;
    bandfinal = true;
    Invalidate(false);

	CView::OnLButtonUp(nFlags, point);

}
void CShortCutView::OnContextMenu(CWnd* pWnd, CPoint point){
    CMenu* menu;

    menu = new CMenu();
    //menu->CreateMenu();
    menu->LoadMenu(IDR_MENU1);
    menu->GetSubMenu(0)->TrackPopupMenu(TPM_CENTERALIGN|TPM_RIGHTBUTTON, point.x, point.y, this);
    menu->DestroyMenu();
}
