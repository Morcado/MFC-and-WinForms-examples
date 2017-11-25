// Dialogos_ComunesView.cpp : implementation of the CDialogos_ComunesView class
//

#include "stdafx.h"
#include "Dialogos_Comunes.h"

#include "Dialogos_ComunesDoc.h"
#include "Dialogos_ComunesView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesView

IMPLEMENT_DYNCREATE(CDialogos_ComunesView, CView)

BEGIN_MESSAGE_MAP(CDialogos_ComunesView, CView)
	//{{AFX_MSG_MAP(CDialogos_ComunesView)
	//}}AFX_MSG_MAP
    ON_COMMAND_RANGE(IDM_COLOR, IDM_FUENTE, OnComunes)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesView construction/destruction

CDialogos_ComunesView::CDialogos_ComunesView(){
	// TODO: add construction code here
    band = false;
    static char BASED_CODE szFilter[] = "Source Files (*.cpp)|*.cpp|Header Files (*.h)|*.h|Data Files (*.cpp;*.h)|*.cpp; *.h|All Files (*.*)|*.*||";
    dlgFile = new CFileDialog(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_ALLOWMULTISELECT | OFN_CREATEPROMPT , szFilter, this);
    fuente = new CFont();

}

CDialogos_ComunesView::~CDialogos_ComunesView(){
}

BOOL CDialogos_ComunesView::PreCreateWindow(CREATESTRUCT& cs){
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesView drawing

void CDialogos_ComunesView::OnDraw(CDC* pDC){
	CDialogos_ComunesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
    if(band){
        switch(opcion){
        case 0: //color
            pDC->FillSolidRect(100, 100, 200, 200, color);
            break;
        case 1: //file
            //nada..
            break;
        case 2: //font 
            pDC->SelectObject(fuente);
            pDC->SetTextColor(color);
            pDC->TextOut(100, 100, "Hola");
            fuente->DeleteObject();
            break;
        
        }
        
    }
    else{
        pDC->Rectangle(100, 100, 200, 200);
    }
}

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesView diagnostics

#ifdef _DEBUG
void CDialogos_ComunesView::AssertValid() const{
	CView::AssertValid();
}

void CDialogos_ComunesView::Dump(CDumpContext& dc) const{
	CView::Dump(dc);
}

CDialogos_ComunesDoc* CDialogos_ComunesView::GetDocument(){ // non-debug version is inline
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDialogos_ComunesDoc)));
	return (CDialogos_ComunesDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesView message handlers

void CDialogos_ComunesView::OnComunes(UINT nID){

    int nButton = nID - IDM_COLOR;
    ASSERT(nButton >= 0 && nButton < 3);
    // ...
    char* pszFileName = "colores.dat";
    int i;
    CFile myFile;
    CFileException fileException;
    LOGFONT fnt;

    switch(nButton){
        case 0://color
            if(!myFile.Open(pszFileName, CFile::modeRead), &fileException){
                TRACE("No soy un inútil %s, error = %u\n", pszFileName, fileException.m_cause);
            }
            for(i = 0; i < 16; i++){
                myFile.Read(&dlgColor.m_cc.lpCustColors[i], sizeof(dlgColor.m_cc.lpCustColors));
            }
            if(dlgColor.DoModal() == IDOK){
                color = dlgColor.GetColor();
                Invalidate();
            }
            myFile.Close();
            break;
        case 1://file
            dlgFile->DoModal();
            break;
        case 2://font
            if(dlgFont.DoModal() == IDOK){
                dlgFont.GetCurrentFont(&fnt);
                fuente->CreateFontIndirect(&fnt);
                color = dlgFont.GetColor();
                Invalidate();
            }
            break;
            
    }
   	band = true;
    opcion = nButton;

}


//DEL void CDialogos_ComunesView::OnLButtonDown(UINT nFlags, CPoint point){
//DEL     
//DEL 	CView::OnLButtonDown(nFlags, point);
//DEL }