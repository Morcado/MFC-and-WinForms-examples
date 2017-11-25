// Dialogos_ComunesDoc.cpp : implementation of the CDialogos_ComunesDoc class
//

#include "stdafx.h"
#include "Dialogos_Comunes.h"

#include "Dialogos_ComunesDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesDoc

IMPLEMENT_DYNCREATE(CDialogos_ComunesDoc, CDocument)

BEGIN_MESSAGE_MAP(CDialogos_ComunesDoc, CDocument)
	//{{AFX_MSG_MAP(CDialogos_ComunesDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesDoc construction/destruction

CDialogos_ComunesDoc::CDialogos_ComunesDoc()
{
	// TODO: add one-time construction code here

}

CDialogos_ComunesDoc::~CDialogos_ComunesDoc()
{
}

BOOL CDialogos_ComunesDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesDoc serialization

void CDialogos_ComunesDoc::Serialize(CArchive& ar)
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
// CDialogos_ComunesDoc diagnostics

#ifdef _DEBUG
void CDialogos_ComunesDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDialogos_ComunesDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesDoc commands
