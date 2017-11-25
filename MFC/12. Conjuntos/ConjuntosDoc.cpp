// ConjuntosDoc.cpp : implementation of the CConjuntosDoc class
//

#include "stdafx.h"
#include "Conjuntos.h"
#include "ConjuntosDoc.h"
#include "Interseccion.h"
#include "Union.h"
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConjuntosDoc

IMPLEMENT_DYNCREATE(CConjuntosDoc, CDocument)

BEGIN_MESSAGE_MAP(CConjuntosDoc, CDocument)
	//{{AFX_MSG_MAP(CConjuntosDoc)
	ON_COMMAND(IDM_CONJUNTO, OnConjunto)
	ON_COMMAND(IDM_COMPLEMENTO, OnComplemento)
	ON_COMMAND(IDM_ASIGNACION, OnAsignacion)
	ON_COMMAND(IDM_INTERSECCION, OnInterseccion)
	ON_COMMAND(IDM_UNION, OnUnion)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConjuntosDoc construction/destruction

CConjuntosDoc::CConjuntosDoc(){
    band = false;

}

CConjuntosDoc::~CConjuntosDoc(){
}

BOOL CConjuntosDoc::OnNewDocument(){
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CConjuntosDoc serialization

void CConjuntosDoc::Serialize(CArchive& ar){
	if (ar.IsStoring()){
		// TODO: add storing code here
	}
	else{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CConjuntosDoc diagnostics

#ifdef _DEBUG
void CConjuntosDoc::AssertValid() const{
	CDocument::AssertValid();
}
 
void CConjuntosDoc::Dump(CDumpContext& dc) const{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CConjuntosDoc commands

void CConjuntosDoc::OnConjunto(){
    int n;
    srand(time(NULL));

    //destructor
    set.destruyeLista();
    set2.destruyeLista();
    //constructor
    n = rand()%3+5;
	set.creaLista(n);
    n = rand()%3+5;
	set2.creaLista(n);
    band = true;
}

void CConjuntosDoc::OnComplemento() {	
    dlgComplemento.dlgSet = set;
    dlgComplemento.dlgComple = !dlgComplemento.dlgSet;
	dlgComplemento.DoModal();
    set = dlgComplemento.dlgComple;
}

void CConjuntosDoc::OnAsignacion(){
    dlgComplemento.dlgSet = set;
	// TODO: Add your command handler code here
}

void CConjuntosDoc::OnInterseccion(){
    dlgInterseccion.setA = set;
    dlgInterseccion.setB = set2;
    dlgInterseccion.inter = dlgInterseccion.setA^dlgInterseccion.setB;
    dlgInterseccion.DoModal();
	// TODO: Add your command handler code here
	
}

void CConjuntosDoc::OnUnion(){
    dlgUnion.setA = set;
    dlgUnion.setB = set2;
    dlgUnion.unio = dlgUnion.setA + dlgUnion.setB;
    dlgUnion.DoModal();
    
}
