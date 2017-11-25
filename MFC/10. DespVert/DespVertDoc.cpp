// DespVertDoc.cpp : implementation of the CDespVertDoc class
//

#include "stdafx.h"
#include "DespVert.h"

#include "DespVertDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDespVertDoc

IMPLEMENT_DYNCREATE(CDespVertDoc, CDocument)

BEGIN_MESSAGE_MAP(CDespVertDoc, CDocument)
	//{{AFX_MSG_MAP(CDespVertDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDespVertDoc construction/destruction

CDespVertDoc::CDespVertDoc()
{
	// TODO: add one-time construction code here

}

CDespVertDoc::~CDespVertDoc()
{
}

BOOL CDespVertDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDespVertDoc serialization

void CDespVertDoc::Serialize(CArchive& ar)
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
// CDespVertDoc diagnostics

#ifdef _DEBUG
void CDespVertDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDespVertDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDespVertDoc commands
