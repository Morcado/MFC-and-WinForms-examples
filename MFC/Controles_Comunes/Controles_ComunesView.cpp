// Controles_ComunesView.cpp : implementation of the CControles_ComunesView class
//

#include "stdafx.h"
#include "Controles_Comunes.h"

#include "Controles_ComunesDoc.h"
#include "Controles_ComunesView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CControles_ComunesView

IMPLEMENT_DYNCREATE(CControles_ComunesView, CView)

BEGIN_MESSAGE_MAP(CControles_ComunesView, CView)
	//{{AFX_MSG_MAP(CControles_ComunesView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CControles_ComunesView construction/destruction

CControles_ComunesView::CControles_ComunesView()
{
	// TODO: add construction code here

}

CControles_ComunesView::~CControles_ComunesView(){
}

BOOL CControles_ComunesView::PreCreateWindow(CREATESTRUCT& cs){
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CControles_ComunesView drawing

void CControles_ComunesView::OnDraw(CDC* pDC){
	CControles_ComunesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

    dlgProgress.DoModal();
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CControles_ComunesView diagnostics

#ifdef _DEBUG
void CControles_ComunesView::AssertValid() const
{
	CView::AssertValid();
}

void CControles_ComunesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CControles_ComunesDoc* CControles_ComunesView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CControles_ComunesDoc)));
	return (CControles_ComunesDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CControles_ComunesView message handlers
