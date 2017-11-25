// Ole_BDDoc.cpp : implementation of the COle_BDDoc class
//

#include "stdafx.h"
#include "Ole_BD.h"

#include "Ole_BDSet.h"
#include "Ole_BDDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COle_BDDoc

IMPLEMENT_DYNCREATE(COle_BDDoc, CDocument)

BEGIN_MESSAGE_MAP(COle_BDDoc, CDocument)
	//{{AFX_MSG_MAP(COle_BDDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COle_BDDoc construction/destruction

COle_BDDoc::COle_BDDoc()
{
	// TODO: add one-time construction code here

}

COle_BDDoc::~COle_BDDoc()
{
}

BOOL COle_BDDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COle_BDDoc serialization

void COle_BDDoc::Serialize(CArchive& ar)
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
// COle_BDDoc diagnostics

#ifdef _DEBUG
void COle_BDDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COle_BDDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COle_BDDoc commands
