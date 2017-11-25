// DespVert1View.cpp : implementation of the CDespVert1View class
//

#include "stdafx.h"
#include "DespVert1.h"

#include "DespVert1Doc.h"
#include "DespVert1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDespVert1View

IMPLEMENT_DYNCREATE(CDespVert1View, CScrollView)

BEGIN_MESSAGE_MAP(CDespVert1View, CScrollView)
	//{{AFX_MSG_MAP(CDespVert1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDespVert1View construction/destruction

CDespVert1View::CDespVert1View()
{
	// TODO: add construction code here

}

CDespVert1View::~CDespVert1View()
{
}

BOOL CDespVert1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDespVert1View drawing

void CDespVert1View::OnDraw(CDC* pDC)
{
	CDespVert1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

    int i;
    int y = 0;
    CString cad;

    for(i = 0; i < MAXREN; i++){
        cad.Format("%d", i);
        pDC->TextOut(0, y, cad);
        y += 20;
    }
}

/////////////////////////////////////////////////////////////////////////////
// CDespVert1View diagnostics

#ifdef _DEBUG
void CDespVert1View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDespVert1View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDespVert1Doc* CDespVert1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDespVert1Doc)));
	return (CDespVert1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDespVert1View message handlers

void CDespVert1View::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();
	
    CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = 100;
    sizeTotal.cy = (1000)*20;
	SetScrollSizes(MM_TEXT, sizeTotal);
    	
}
