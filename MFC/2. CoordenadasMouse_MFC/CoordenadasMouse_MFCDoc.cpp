// CoordenadasMouse_MFCDoc.cpp : implementation of the CCoordenadasMouse_MFCDoc class
//

#include "stdafx.h"
#include "CoordenadasMouse_MFC.h"

#include "CoordenadasMouse_MFCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCoordenadasMouse_MFCDoc

IMPLEMENT_DYNCREATE(CCoordenadasMouse_MFCDoc, CDocument)

BEGIN_MESSAGE_MAP(CCoordenadasMouse_MFCDoc, CDocument)
	//{{AFX_MSG_MAP(CCoordenadasMouse_MFCDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCoordenadasMouse_MFCDoc construction/destruction

CCoordenadasMouse_MFCDoc::CCoordenadasMouse_MFCDoc()
{
	// TODO: add one-time construction code here

}

CCoordenadasMouse_MFCDoc::~CCoordenadasMouse_MFCDoc()
{
}

BOOL CCoordenadasMouse_MFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCoordenadasMouse_MFCDoc serialization

void CCoordenadasMouse_MFCDoc::Serialize(CArchive& ar)
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
// CCoordenadasMouse_MFCDoc diagnostics

#ifdef _DEBUG
void CCoordenadasMouse_MFCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCoordenadasMouse_MFCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCoordenadasMouse_MFCDoc commands
