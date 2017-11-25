// BD1Doc.cpp : implementation of the CBD1Doc class
//

#include "stdafx.h"
#include "BD1.h"

#include "BD1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBD1Doc

IMPLEMENT_DYNCREATE(CBD1Doc, CDocument)

BEGIN_MESSAGE_MAP(CBD1Doc, CDocument)
	//{{AFX_MSG_MAP(CBD1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBD1Doc construction/destruction

CBD1Doc::CBD1Doc()
{
	// TODO: add one-time construction code here

}

CBD1Doc::~CBD1Doc()
{
}

BOOL CBD1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBD1Doc serialization

void CBD1Doc::Serialize(CArchive& ar)
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
// CBD1Doc diagnostics

#ifdef _DEBUG
void CBD1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBD1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBD1Doc commands
