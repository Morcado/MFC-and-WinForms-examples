// BD2Doc.cpp : implementation of the CBD2Doc class
//

#include "stdafx.h"
#include "BD2.h"

#include "BD2Set.h"
#include "BD2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBD2Doc

IMPLEMENT_DYNCREATE(CBD2Doc, CDocument)

BEGIN_MESSAGE_MAP(CBD2Doc, CDocument)
	//{{AFX_MSG_MAP(CBD2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBD2Doc construction/destruction

CBD2Doc::CBD2Doc()
{
	// TODO: add one-time construction code here

}

CBD2Doc::~CBD2Doc()
{
}

BOOL CBD2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBD2Doc diagnostics

#ifdef _DEBUG
void CBD2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBD2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBD2Doc commands
