// BD2View.cpp : implementation of the CBD2View class
//

#include "stdafx.h"
#include "BD2.h"

#include "BD2Set.h"
#include "BD2Doc.h"
#include "BD2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBD2View

IMPLEMENT_DYNCREATE(CBD2View, CRecordView)

BEGIN_MESSAGE_MAP(CBD2View, CRecordView)
	//{{AFX_MSG_MAP(CBD2View)
	ON_COMMAND(IDM_ADD, OnAdd)
	ON_COMMAND(IDM_CLEAR, OnClear)
	ON_COMMAND(IDM_DEL, OnDel)
	ON_COMMAND(IDM_UPDATE, OnUpdate)
	ON_UPDATE_COMMAND_UI(IDM_UPDATE, OnUpdateUpdate)
	ON_UPDATE_COMMAND_UI(IDM_DEL, OnUpdateDel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBD2View construction/destruction

CBD2View::CBD2View()
	: CRecordView(CBD2View::IDD)
{
	//{{AFX_DATA_INIT(CBD2View)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CBD2View::~CBD2View()
{
}

void CBD2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBD2View)
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_Id, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_Clave, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->m_Nombre, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT4, m_pSet->m_Calificaci_n_1, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT5, m_pSet->m_Calificaci_n_2, m_pSet);
	//}}AFX_DATA_MAP
}

BOOL CBD2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CBD2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_bD2Set;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CBD2View diagnostics

#ifdef _DEBUG
void CBD2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CBD2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CBD2Doc* CBD2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBD2Doc)));
	return (CBD2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBD2View database support
CRecordset* CBD2View::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CBD2View message handlers

void CBD2View::OnAdd() {
	m_pSet->MoveLast();
    m_pSet->AddNew();

    m_pSet->m_Clave = "666";
    m_pSet->m_Nombre = "Ingrese el nombre del estudiante";
    m_pSet->m_Calificaci_n_1 = 00;
    m_pSet->m_Calificaci_n_2 = 00;

    m_pSet->Update();
    UpdateData();
}

void CBD2View::OnClear() {
	m_pSet->SetFieldNull(NULL);
    UpdateData(false);
}

void CBD2View::OnDel() {
	CRecordsetStatus status;

    try{
        m_pSet->Delete();
    }
    catch(CDBException* e){
        AfxMessageBox(e->m_strError);
        e->Delete();
        m_pSet->MoveFirst();
        UpdateData(false);
    }
    m_pSet->GetStatus(status);

    if(status.m_lCurrentRecord == 0){
        m_pSet->MoveFirst();
    }
    else{
        m_pSet->MoveNext();
    }
    UpdateData(false);
}

void CBD2View::OnUpdate(){
	m_pSet->Edit();
    UpdateData();

    if(m_pSet->CanUpdate()){
        m_pSet->Update();
    }
}

BOOL CBD2View::OnMove(UINT nIDMoveCommand){

    switch(nIDMoveCommand){
        case ID_RECORD_PREV:
            m_pSet->MovePrev();
            if(m_pSet->IsBOF()){
                break;
            }
            break;
        case ID_RECORD_FIRST:
            m_pSet->MoveFirst();
            break;
        case ID_RECORD_NEXT:
            m_pSet->MoveNext();
            if(!m_pSet->IsEOF()){
                break;
            }
            if(!m_pSet->CanScroll()){
                m_pSet->SetFieldNull(NULL);
                break;
            }
            break;
        case ID_RECORD_LAST:
            m_pSet->MoveLast();
            break;
        default:
            ASSERT(FALSE);
    }

    UpdateData(false);
    return true;
	//return CRecordView::OnMove(nIDMoveCommand);
}

void CBD2View::OnUpdateUpdate(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CBD2View::OnUpdateDel(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}
