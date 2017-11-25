// BD1View.cpp : implementation of the CBD1View class
//

#include "stdafx.h"
#include "BD1.h"

#include "BD1Doc.h"
#include "BD1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBD1View

IMPLEMENT_DYNCREATE(CBD1View, CScrollView)

BEGIN_MESSAGE_MAP(CBD1View, CScrollView)
	//{{AFX_MSG_MAP(CBD1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBD1View construction/destruction

CBD1View::CBD1View()
{
	// TODO: add construction code here

}

CBD1View::~CBD1View()
{
}

BOOL CBD1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBD1View drawing

void CBD1View::OnDraw(CDC* pDC){
	CBD1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	TEXTMETRIC tm;
    int alto_linea;
    CPoint pText(0, 0);
    CString str;
   
    pDC->GetTextMetrics(&tm);
    alto_linea = tm.tmHeight + tm.tmExternalLeading;
    pDC->TextOut(pText.x + 1000, pText.y, "Clave");
    pDC->TextOut(pText.x + 2000, pText.y, "Nombre");
    pDC->TextOut(pText.x + 3000, pText.y, "Calificacion");
    pText.y = -400;
    m_p_Tabla->MoveFirst();
    while(!m_p_Tabla->IsEOF()){
        //str.Format("%ld", m_p_Tabla->m_Clave);
        pDC->TextOut(pText.x, pText.y, m_p_Tabla->m_Clave);
        pDC->TextOut(pText.x + 1000, pText.y, m_p_Tabla->m_Nombre);
        str.Format("%ld", m_p_Tabla->m_Calificaci_n_1);
        pDC->TextOut(pText.x + 2000, pText.y, str);
        str.Format("%ld", m_p_Tabla->m_Calificaci_n_2);
        pDC->TextOut(pText.x + 3000, pText.y, str);
        m_p_Tabla->MoveNext();
        pText.y -= alto_linea;
    }
}

void CBD1View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal(8000, 10500);
	// TODO: calculate the total size of this view
	//sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_HIENGLISH, sizeTotal);
    m_p_Tabla = &GetDocument()->m_Tabla;
    if(m_p_Tabla->IsOpen()){
        m_p_Tabla->Close();
    }
    m_p_Tabla->Open();
}

/////////////////////////////////////////////////////////////////////////////
// CBD1View diagnostics

#ifdef _DEBUG
void CBD1View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CBD1View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CBD1Doc* CBD1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBD1Doc)));
	return (CBD1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBD1View message handlers
