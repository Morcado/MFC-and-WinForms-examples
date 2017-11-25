// DespVertView.cpp : implementation of the CDespVertView class
//

#include "stdafx.h"
#include "DespVert.h"

#include "DespVertDoc.h"
#include "DespVertView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDespVertView

IMPLEMENT_DYNCREATE(CDespVertView, CScrollView)

BEGIN_MESSAGE_MAP(CDespVertView, CScrollView)
	//{{AFX_MSG_MAP(CDespVertView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDespVertView construction/destruction

CDespVertView::CDespVertView()
{
	// TODO: add construction code here

}

CDespVertView::~CDespVertView()
{
}

BOOL CDespVertView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDespVertView drawing

void CDespVertView::OnDraw(CDC* pDC)
{
	CDespVertDoc* pDoc = GetDocument();
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

void CDespVertView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = 100;
    sizeTotal.cy = (MAXREN)*20;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CDespVertView diagnostics

#ifdef _DEBUG
void CDespVertView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDespVertView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDespVertDoc* CDespVertView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDespVertDoc)));
	return (CDespVertDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDespVertView message handlers
