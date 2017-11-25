// GrafoOptimoAleatorioDoc.cpp : implementation of the CGrafoOptimoAleatorioDoc class
//

#include "stdafx.h"
#include "GrafoOptimoAleatorio.h"
#include "NodoP.h"
#include "NodoR.h"
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

CGrafoOptimoAleatorioDoc::CGrafoOptimoAleatorioDoc(){
    band = false;
    creado = false;
    name = 'A';
    srand((unsigned)time(NULL));
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
    g.Serialize(ar);
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

void CGrafoOptimoAleatorioDoc::creaGrafo(){
    
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


void CGrafoOptimoAleatorioDoc::inserta(CNodoP *c1){
    g.AddTail(c1);
}

void CGrafoOptimoAleatorioDoc::inserta(CNodoP *np, CNodoR *nr){
    np->abajo.AddTail(nr);
}
