// CoordenadasMouse_MFCView.cpp : implementation of the CCoordenadasMouse_MFCView class
//

#include "stdafx.h"
#include "CoordenadasMouse_MFC.h"

#include "CoordenadasMouse_MFCDoc.h"
#include "CoordenadasMouse_MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCoordenadasMouse_MFCView

IMPLEMENT_DYNCREATE(CCoordenadasMouse_MFCView, CView)

BEGIN_MESSAGE_MAP(CCoordenadasMouse_MFCView, CView)
	//{{AFX_MSG_MAP(CCoordenadasMouse_MFCView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCoordenadasMouse_MFCView construction/destruction

CCoordenadasMouse_MFCView::CCoordenadasMouse_MFCView()
{
    band = false;
    x = 100;
    y = 100;
	// TODO: add construction code here

}

CCoordenadasMouse_MFCView::~CCoordenadasMouse_MFCView()
{
}

BOOL CCoordenadasMouse_MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCoordenadasMouse_MFCView drawing

void CCoordenadasMouse_MFCView::OnDraw(CDC* pDC){
	CCoordenadasMouse_MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CString cad2;
    if(band){
        cad.Format("X = %d", x);
        cad += ", ";
        cad2.Format("Y = %d", y);
        cad += cad2;
        //cad += cad.Format("%d", y);
        pDC->TextOut(x, y, cad);
    }
}

/////////////////////////////////////////////////////////////////////////////
// CCoordenadasMouse_MFCView diagnostics

#ifdef _DEBUG
void CCoordenadasMouse_MFCView::AssertValid() const
{
	CView::AssertValid();
}

void CCoordenadasMouse_MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCoordenadasMouse_MFCDoc* CCoordenadasMouse_MFCView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCoordenadasMouse_MFCDoc)));
	return (CCoordenadasMouse_MFCDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCoordenadasMouse_MFCView message handlers

void CCoordenadasMouse_MFCView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CView::OnLButtonDown(nFlags, point);
    x = point.x;
    y = point.y;
    band = true;
    Invalidate();
}
