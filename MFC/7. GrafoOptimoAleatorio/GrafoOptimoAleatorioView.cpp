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
    band = false;
    creado = false;
    name = 'A';
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
	// TODO: add draw code for native data here

}

//*CGrafoOptimoAleatorioView diagnostics

#ifdef _DEBUG
void CGrafoOptimoAleatorioView::AssertValid() const{
	CView::AssertValid();
}

void CGrafoOptimoAleatorioView::Dump(CDumpContext& dc) const{
	CView::Dump(dc);
}

CGrafoOptimoAleatorioDoc* CGrafoOptimoAleatorioView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGrafoOptimoAleatorioDoc)));
	return (CGrafoOptimoAleatorioDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioView message handlers

void CGrafoOptimoAleatorioView::OnOptimo(UINT nID){
    
    int nButton = nID - IDM_CREAR;
    ASSERT( nButton >= 0 && nButton < 3 );

    switch(nButton){
    case 0:
        band = true;
        creaGrafo();
        break;
    case 1:
        band = true;
        Invalidate();    
       
        break;
    case 2:
        if(band){
            dlgCaja.gDlg.AddHead(&g);
            if(dlgCaja.DoModal() == IDOK){
                g.RemoveAll();
            }
          
        }
        break;
    }
}

void CGrafoOptimoAleatorioView::inserta(CNodoP *np, CNodoR *nr){
    np->abajo.AddTail(nr);

}


void CGrafoOptimoAleatorioView::inserta(CNodoP *c1){
    g.AddTail(c1);
}

void CGrafoOptimoAleatorioView::creaGrafo(){
    srand((unsigned)time(NULL));
    CNodoP *c1, *c2;
    POSITION pos1, pos2;
    int numeros, n, quieres;
   
    numeros = rand()%5+2;

    if(!g.IsEmpty()){
    	POSITION posP = g.GetHeadPosition();
        POSITION posR;
        CNodoP *np;
        CNodoR *nr;

        while(posP){
            np = (CNodoP*)g.GetNext(posP);
            posR = np->abajo.GetHeadPosition();
            while(posR){
                nr = (CNodoR*)np->abajo.GetNext(posR);
                delete(nr);
            }
            delete(np);
        }
        g.RemoveAll();
    }

  
    if(band){
        
        np = new CNodoP(name); //relaciones de a 
        c1 = np;

        while(numeros--){
 
            quieres = rand()%2;
            if(quieres){
                n = rand()%100;
                nr = new CNodoR(n);
                nr->arriba = c1;
                inserta(np, nr);
            }
            inserta(c1);
            c1 = new CNodoP(++name);    //nodos principales
        }
        pos1 = g.GetHeadPosition(); //pos1 se posiciona en A
        c1 = (CNodoP*)g.GetNext(pos1); //c1 se posiciona en A
        c1 = (CNodoP*)g.GetAt(pos1); //c2 se posiciona en A


        while(c1 && pos1){ //RELACIONES DE B EN ADELANTE  
            pos2 = g.GetHeadPosition(); //pos2 se posiciona en A
            c2 = (CNodoP*)g.GetAt(pos2); //c2 se posiciona en A
            //c2 recorre todo el grafo
            while(c2 && pos2){ //quieres nr de cada np
                quieres = rand()%2;
                if(quieres){
                    n = rand()%100;
                    nr = new CNodoR(n);
                    nr->arriba = c2;
                    inserta(c1, nr); //INSERTA RELACION EN B
                }
                g.GetNext(pos2); //mueve pos2 al siguiente
                if(pos2){ //si pos2 no es null
                    c2 = (CNodoP*)g.GetAt(pos2); //c2 es pos2
                }
            }
            g.GetNext(pos1);
            if(pos1){
                c1 = (CNodoP*)g.GetAt(pos1);
            }
        }
    }
}
