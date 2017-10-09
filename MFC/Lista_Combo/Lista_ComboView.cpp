// Lista_ComboView.cpp : implementation of the CLista_ComboView class
//

#include "stdafx.h"
#include "Lista_Combo.h"
#include "Lista_ComboDoc.h"
#include "Lista_ComboView.h"
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboView

IMPLEMENT_DYNCREATE(CLista_ComboView, CView)

BEGIN_MESSAGE_MAP(CLista_ComboView, CView)
	//{{AFX_MSG_MAP(CLista_ComboView)
	ON_COMMAND(IDM_CREAR, OnCrear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboView construction/destruction

CLista_ComboView::CLista_ComboView(){
    band = FALSE;
    
	// TODO: add construction code here

}

CLista_ComboView::~CLista_ComboView(){
}

BOOL CLista_ComboView::PreCreateWindow(CREATESTRUCT& cs){
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboView drawing

void CLista_ComboView::OnDraw(CDC* pDC){
	CLista_ComboDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
    POSITION pos;
    CString cad;
    int x = 100;

    if(band){
        pos = lista.GetHeadPosition();
        while(pos){
            nodo = (CNodo*)lista.GetNext(pos);
            cad.Format("%d", nodo->numero);
            pDC->TextOut(x += 20, 100, cad);
        }
        //dlgNumeros.combo = "Mundo";
        lista.RemoveAll();
         //dlgNumeros.m_Combo.SetDlgItemText(IDC_COMBO1, "Hola");

    }
}

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboView diagnostics

#ifdef _DEBUG
void CLista_ComboView::AssertValid() const{
	CView::AssertValid();
}

void CLista_ComboView::Dump(CDumpContext& dc) const{
	CView::Dump(dc);
}

CLista_ComboDoc* CLista_ComboView::GetDocument(){ // non-debug version is inline
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLista_ComboDoc)));
	return (CLista_ComboDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboView message handlers

void CLista_ComboView::OnCrear(){
	// TODO: Add your command handler code here
    int num, numeros;
    POSITION pos1, pos2;
    
    srand((unsigned)time(NULL));
    numeros = rand()%5+10;
    while(numeros--){
        pos1 = lista.GetHeadPosition();
        num = rand()%100;
        nodo = new CNodo(num);
        //while(((CNodo*)lista.GetAt(pos1))->numero >num){
        if(lista.GetCount() >= 2){
            while(pos1 && ((CNodo*)lista.GetAt(pos1))->numero > num){
                lista.GetNext(pos1);
            }
            if(!pos1){
                //lista.InsertBefore(pos1, (CObject*)nodo);
                lista.AddTail((CObject*)nodo);
            }
            else{
                lista.InsertBefore(pos1, (CObject*)nodo);
            }
        }
        else{
            if(lista.GetCount() == 1){
                if(((CNodo*)lista.GetHead())->numero > num){
                    lista.InsertAfter(pos1, (CObject*)nodo);
                }
                else{
                    lista.InsertBefore(pos1, (CObject*)nodo);
                }
            }
            else{
                lista.AddHead((CObject*)nodo);
            }
        }
    }
    dlgNumeros.lista_combo.AddHead(&lista);
    dlgNumeros.DoModal();
   //dlgNumeros.DestroyWindow();
    
	//band = true;
    //Invalidate();
}
