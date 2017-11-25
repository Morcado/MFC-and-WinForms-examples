// DespVert1Doc.cpp : implementation of the CDespVert1Doc class
//

#include "stdafx.h"
#include "DespVert1.h"

#include "DespVert1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDespVert1Doc

IMPLEMENT_DYNCREATE(CDespVert1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDespVert1Doc, CDocument)
	//{{AFX_MSG_MAP(CDespVert1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDespVert1Doc construction/destruction

CDespVert1Doc::CDespVert1Doc()
{
	// TODO: add one-time construction code here

}

CDespVert1Doc::~CDespVert1Doc()
{
}

BOOL CDespVert1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDespVert1Doc serialization

void CDespVert1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDespVert1Doc diagnostics

#ifdef _DEBUG
void CDespVert1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDespVert1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDespVert1Doc commands
