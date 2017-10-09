// Primero_MFCDoc.cpp : implementation of the CPrimero_MFCDoc class
//

#include "stdafx.h"
#include "Primero_MFC.h"

#include "Primero_MFCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrimero_MFCDoc

IMPLEMENT_DYNCREATE(CPrimero_MFCDoc, CDocument)

BEGIN_MESSAGE_MAP(CPrimero_MFCDoc, CDocument)
	//{{AFX_MSG_MAP(CPrimero_MFCDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrimero_MFCDoc construction/destruction

CPrimero_MFCDoc::CPrimero_MFCDoc()
{
	// TODO: add one-time construction code here

}

CPrimero_MFCDoc::~CPrimero_MFCDoc()
{
}

BOOL CPrimero_MFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPrimero_MFCDoc serialization

void CPrimero_MFCDoc::Serialize(CArchive& ar)
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
// CPrimero_MFCDoc diagnostics

#ifdef _DEBUG
void CPrimero_MFCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPrimero_MFCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPrimero_MFCDoc commands
