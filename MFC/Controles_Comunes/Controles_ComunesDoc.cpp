// Controles_ComunesDoc.cpp : implementation of the CControles_ComunesDoc class
//

#include "stdafx.h"
#include "Controles_Comunes.h"

#include "Controles_ComunesDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CControles_ComunesDoc

IMPLEMENT_DYNCREATE(CControles_ComunesDoc, CDocument)

BEGIN_MESSAGE_MAP(CControles_ComunesDoc, CDocument)
	//{{AFX_MSG_MAP(CControles_ComunesDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CControles_ComunesDoc construction/destruction

CControles_ComunesDoc::CControles_ComunesDoc()
{
	// TODO: add one-time construction code here

}

CControles_ComunesDoc::~CControles_ComunesDoc()
{
}

BOOL CControles_ComunesDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CControles_ComunesDoc serialization

void CControles_ComunesDoc::Serialize(CArchive& ar)
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
// CControles_ComunesDoc diagnostics

#ifdef _DEBUG
void CControles_ComunesDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CControles_ComunesDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CControles_ComunesDoc commands
