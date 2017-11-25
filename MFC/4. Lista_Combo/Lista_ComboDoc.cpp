// Lista_ComboDoc.cpp : implementation of the CLista_ComboDoc class
//

#include "stdafx.h"
#include "Lista_Combo.h"

#include "Lista_ComboDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboDoc

IMPLEMENT_DYNCREATE(CLista_ComboDoc, CDocument)

BEGIN_MESSAGE_MAP(CLista_ComboDoc, CDocument)
	//{{AFX_MSG_MAP(CLista_ComboDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboDoc construction/destruction

CLista_ComboDoc::CLista_ComboDoc()
{
	// TODO: add one-time construction code here

}

CLista_ComboDoc::~CLista_ComboDoc()
{
}

BOOL CLista_ComboDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLista_ComboDoc serialization

void CLista_ComboDoc::Serialize(CArchive& ar)
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
// CLista_ComboDoc diagnostics

#ifdef _DEBUG
void CLista_ComboDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLista_ComboDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboDoc commands
