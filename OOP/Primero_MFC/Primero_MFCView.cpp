// Primero_MFCView.cpp : implementation of the CPrimero_MFCView class
//

#include "stdafx.h"
#include "Primero_MFC.h"

#include "Primero_MFCDoc.h"
#include "Primero_MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrimero_MFCView

IMPLEMENT_DYNCREATE(CPrimero_MFCView, CView)

BEGIN_MESSAGE_MAP(CPrimero_MFCView, CView)
	//{{AFX_MSG_MAP(CPrimero_MFCView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrimero_MFCView construction/destruction

CPrimero_MFCView::CPrimero_MFCView()
{
	// TODO: add construction code here
    band = FALSE;
}

CPrimero_MFCView::~CPrimero_MFCView()
{
}

BOOL CPrimero_MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPrimero_MFCView drawing

void CPrimero_MFCView::OnDraw(CDC* pDC)
{
	CPrimero_MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

    if(band){
        pDC->TextOut(100, 100, "Hola mundo");
    }
}

/////////////////////////////////////////////////////////////////////////////
// CPrimero_MFCView diagnostics

#ifdef _DEBUG
void CPrimero_MFCView::AssertValid() const
{
	CView::AssertValid();
}

void CPrimero_MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPrimero_MFCDoc* CPrimero_MFCView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPrimero_MFCDoc)));
	return (CPrimero_MFCDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPrimero_MFCView message handlers

void CPrimero_MFCView::OnLButtonDown(UINT nFlags, CPoint point) 
{
    band = TRUE;
    Invalidate();
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);
}
