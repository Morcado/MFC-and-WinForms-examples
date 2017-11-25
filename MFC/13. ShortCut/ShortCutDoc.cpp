// ShortCutDoc.cpp : implementation of the CShortCutDoc class
//

#include "stdafx.h"
#include "ShortCut.h"

#include "ShortCutDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShortCutDoc

IMPLEMENT_DYNCREATE(CShortCutDoc, CDocument)

BEGIN_MESSAGE_MAP(CShortCutDoc, CDocument)
	//{{AFX_MSG_MAP(CShortCutDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShortCutDoc construction/destruction

CShortCutDoc::CShortCutDoc()
{
	// TODO: add one-time construction code here

}

CShortCutDoc::~CShortCutDoc()
{
}

BOOL CShortCutDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShortCutDoc serialization

void CShortCutDoc::Serialize(CArchive& ar)
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
// CShortCutDoc diagnostics

#ifdef _DEBUG
void CShortCutDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShortCutDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShortCutDoc commands
