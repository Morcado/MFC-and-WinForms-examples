// GrafoOptimoAleatorioView.cpp : implementation of the CGrafoOptimoAleatorioView class
//

#include "stdafx.h"
#include "GrafoOptimoAleatorio.h"

#include "GrafoOptimoAleatorioDoc.h"
#include "GrafoOptimoAleatorioView.h"
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioView

IMPLEMENT_DYNCREATE(CGrafoOptimoAleatorioView, CView)

BEGIN_MESSAGE_MAP(CGrafoOptimoAleatorioView, CView)
	//{{AFX_MSG_MAP(CGrafoOptimoAleatorioView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
    ON_COMMAND_RANGE(IDM_CREAR, IDM_LIST, OnOptimo)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioView construction/destruction

CGrafoOptimoAleatorioView::CGrafoOptimoAleatorioView(){
	// TODO: add construction code here

}

CGrafoOptimoAleatorioView :: ~CGrafoOptimoAleatorioView(){

}

BOOL CGrafoOptimoAleatorioView::PreCreateWindow(CREATESTRUCT& cs){
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioView drawing

void CGrafoOptimoAleatorioView::OnDraw(CDC* pDC){
	CGrafoOptimoAleatorioDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
    
    switch(opcion){
        case 1:
            g.AddHead(&(pDoc->g));
            imprimeGrafo(pDC);
            break;
    }

}

//*CGrafoOptimoAleatorioView diagnostics

#ifdef _DEBUG
void CGrafoOptimoAleatorioView::AssertValid() const{
	CView::AssertValid();
}

void CGrafoOptimoAleatorioView::Dump(CDumpContext& dc) const{
	CView::Dump(dc);
}

CGrafoOptimoAleatorioDoc* CGrafoOptimoAleatorioView::GetDocument(){
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGrafoOptimoAleatorioDoc)));
	return (CGrafoOptimoAleatorioDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioView message handlers


void CGrafoOptimoAleatorioView::OnOptimo(UINT nID){
    CGrafoOptimoAleatorioDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
    int nButton = nID - IDM_CREAR;
    ASSERT( nButton >= 0 && nButton < 3 );

    switch(nButton){
    case 0:
        opcion = 0;
        pDoc->band = true;
        pDoc->creaGrafo();
        break;
    case 1:
        opcion = 1;
        band = true;
        Invalidate();
        break;
    case 2:
        dlgCaja.gDlg.RemoveAll();
        dlgCaja.gDlg.AddHead(&g);
        dlgCaja.DoModal();
        break;
    }
}


void CGrafoOptimoAleatorioView::imprimeGrafo(CDC *pDC){  
    if(band){
        POSITION pos1, pos2;
        CNodoP* np;
        CNodoR* nr;
        CString cad;
        char cad2[10];
        name = 'A';
        int x = 100, y = 100;
        
        pos1 = g.GetHeadPosition();
        np = (CNodoP*)g.GetNext(pos1);

        while(np){
            //np = (CNodoP*)g.GetAt(pos1);
            cad += np->nombre;
            cad += ": ";
            pos2 = (np->abajo).GetHeadPosition();
            if(pos2){
                nr = (CNodoR*)(np->abajo).GetNext(pos2);
            }

            while(nr){
                //nr = (CNodoR*)(np->abajo).GetAt(pos2);
                cad += nr->arriba->nombre;
                cad += "_";
                itoa(nr->n, cad2, 10);
                cad += cad2;

                if(pos2){
                    cad += "->";
                    nr = (CNodoR*)(np->abajo).GetNext(pos2);
                }
                else{
                    cad += "->NULL";
                    nr = NULL;
                }
            }
            pDC->TextOut(x, y, cad);
            y+=20;
            cad.Empty();

            if(pos1){
                np = (CNodoP*)g.GetNext(pos1);
            }
            else{
                np = NULL;
            }
        }
    }
}
