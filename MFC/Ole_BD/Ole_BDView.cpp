// Ole_BDView.cpp : implementation of the COle_BDView class
//

#include "stdafx.h"
#include "Ole_BD.h"

#include "Ole_BDSet.h"
#include "Ole_BDDoc.h"
#include "Ole_BDView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COle_BDView

IMPLEMENT_DYNCREATE(COle_BDView, COleDBRecordView)

BEGIN_MESSAGE_MAP(COle_BDView, COleDBRecordView)
	//{{AFX_MSG_MAP(COle_BDView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COle_BDView construction/destruction

COle_BDView::COle_BDView()
	: COleDBRecordView(COle_BDView::IDD)
{
	//{{AFX_DATA_INIT(COle_BDView)
		// NOTE: the ClassWizard will add member initialization here
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

COle_BDView::~COle_BDView()
{
}

void COle_BDView::DoDataExchange(CDataExchange* pDX)
{
	COleDBRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COle_BDView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL COle_BDView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return COleDBRecordView::PreCreateWindow(cs);
}

void COle_BDView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ole_BDSet;
	{
		CWaitCursor wait;
		HRESULT hr = m_pSet->Open();
		if (hr != S_OK)
		{
			AfxMessageBox(_T("Record set failed to open."), MB_OK);
			// Disable the Next and Previous record commands,
			// since attempting to change the current record without an
			// open RecordSet will cause a crash.
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}				
	}
	COleDBRecordView::OnInitialUpdate();

}

/////////////////////////////////////////////////////////////////////////////
// COle_BDView diagnostics

#ifdef _DEBUG
void COle_BDView::AssertValid() const
{
	COleDBRecordView::AssertValid();
}

void COle_BDView::Dump(CDumpContext& dc) const
{
	COleDBRecordView::Dump(dc);
}

COle_BDDoc* COle_BDView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COle_BDDoc)));
	return (COle_BDDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COle_BDView database support
CRowset* COle_BDView::OnGetRowset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// COle_BDView message handlers
