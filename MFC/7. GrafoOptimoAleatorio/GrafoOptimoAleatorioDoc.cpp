// GrafoOptimoAleatorioDoc.cpp : implementation of the CGrafoOptimoAleatorioDoc class
//

#include "stdafx.h"
#include "GrafoOptimoAleatorio.h"

#include "GrafoOptimoAleatorioDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioDoc

IMPLEMENT_DYNCREATE(CGrafoOptimoAleatorioDoc, CDocument)

BEGIN_MESSAGE_MAP(CGrafoOptimoAleatorioDoc, CDocument)
	//{{AFX_MSG_MAP(CGrafoOptimoAleatorioDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioDoc construction/destruction

CGrafoOptimoAleatorioDoc::CGrafoOptimoAleatorioDoc()
{
	// TODO: add one-time construction code here

}

CGrafoOptimoAleatorioDoc::~CGrafoOptimoAleatorioDoc()
{
}

BOOL CGrafoOptimoAleatorioDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioDoc serialization

void CGrafoOptimoAleatorioDoc::Serialize(CArchive& ar)
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
// CGrafoOptimoAleatorioDoc diagnostics

#ifdef _DEBUG
void CGrafoOptimoAleatorioDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGrafoOptimoAleatorioDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioDoc commands
