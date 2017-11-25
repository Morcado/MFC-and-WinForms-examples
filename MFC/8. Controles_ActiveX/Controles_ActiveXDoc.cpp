// Controles_ActiveXDoc.cpp : implementation of the CControles_ActiveXDoc class
//

#include "stdafx.h"
#include "Controles_ActiveX.h"

#include "Controles_ActiveXDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CControles_ActiveXDoc

IMPLEMENT_DYNCREATE(CControles_ActiveXDoc, CDocument)

BEGIN_MESSAGE_MAP(CControles_ActiveXDoc, CDocument)
	//{{AFX_MSG_MAP(CControles_ActiveXDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CControles_ActiveXDoc construction/destruction

CControles_ActiveXDoc::CControles_ActiveXDoc()
{
	// TODO: add one-time construction code here

}

CControles_ActiveXDoc::~CControles_ActiveXDoc()
{
}

BOOL CControles_ActiveXDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CControles_ActiveXDoc serialization

void CControles_ActiveXDoc::Serialize(CArchive& ar)
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
// CControles_ActiveXDoc diagnostics

#ifdef _DEBUG
void CControles_ActiveXDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CControles_ActiveXDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CControles_ActiveXDoc commands
