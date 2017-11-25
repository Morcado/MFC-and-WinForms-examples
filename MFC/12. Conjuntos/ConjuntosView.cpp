// ConjuntosView.cpp : implementation of the CConjuntosView class
//

#include "stdafx.h"
#include "Conjuntos.h"

#include "ConjuntosDoc.h"
#include "ConjuntosView.h"
#include "Nodo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConjuntosView

IMPLEMENT_DYNCREATE(CConjuntosView, CView)

BEGIN_MESSAGE_MAP(CConjuntosView, CView)
	//{{AFX_MSG_MAP(CConjuntosView)
	ON_COMMAND(IDM_IMPRIME, OnImprime)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConjuntosView construction/destruction

CConjuntosView::CConjuntosView(){
	// TODO: add construction code here

}

CConjuntosView::~CConjuntosView()
{
}

BOOL CConjuntosView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CConjuntosView drawing

void CConjuntosView::OnDraw(CDC* pDC){
	CConjuntosDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
    
    POSITION pos1, pos2;
    CString cad;
    CNodo *nodo;
    int x = 100, y = 100;

    if(pDoc->band){
        pos1 = pDoc->set.GetHeadPosition();
        pos2 = pDoc->set2.GetHeadPosition();

        while(pos1){
            nodo = (CNodo*)pDoc->set.GetNext(pos1);
            cad.Format("%d", nodo->n);
            pDC->TextOut(x += 30, y, cad);
        }
        y += 20;
        x = 100;
        while(pos2){
            nodo = (CNodo*)pDoc->set2.GetNext(pos2);
            cad.Format("%d", nodo->n);
            pDC->TextOut(x += 30, y, cad);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// CConjuntosView printing

BOOL CConjuntosView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CConjuntosView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CConjuntosView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CConjuntosView diagnostics

#ifdef _DEBUG
void CConjuntosView::AssertValid() const
{
	CView::AssertValid();
}

void CConjuntosView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CConjuntosDoc* CConjuntosView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CConjuntosDoc)));
	return (CConjuntosDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CConjuntosView message handlers

//DEL void CConjuntosView::OnConjunto( UINT nID ){
//DEL     int nButton = nID - IDM_CONJUNTO;
//DEL     ASSERT( nButton >= 0 && nButton < 2 );
//DEL     
//DEL 
//DEL     switch(nButton){
//DEL         case 0:
//DEL             opcion = 1;
//DEL             break;
//DEL         case 1:
//DEL             opcion = 2;
//DEL             break;
//DEL     }
//DEL     Invalidate();
//DEL }

//DEL void CConjuntosView::OnComplemento() {
//DEL 	CConjuntosDoc* pDoc = GetDocument();
//DEL 	ASSERT_VALID(pDoc);
//DEL     
//DEL 	dlgComplemento.dlgSet = (pDoc->set);
//DEL }


void CConjuntosView::OnImprime(){
    Invalidate();	
}
