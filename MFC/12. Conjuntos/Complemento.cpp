// Complemento.cpp : implementation file
//

#include "stdafx.h"
#include "Conjuntos.h"
#include "Complemento.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComplemento dialog


CComplemento::CComplemento(CWnd* pParent /*=NULL*/)
	: CDialog(CComplemento::IDD, pParent)
{
	//{{AFX_DATA_INIT(CComplemento)
	//}}AFX_DATA_INIT
}


void CComplemento::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComplemento)
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CComplemento, CDialog)
	//{{AFX_MSG_MAP(CComplemento)
	ON_BN_CLICKED(IDC_COMPLE, OnComple)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComplemento message handlers

//DEL void CComplemento::OnAccion(){
//DEL 
//DEL     
//DEL }

void CComplemento::OnComple(){  
    CNodo* nodo;
    POSITION pos = dlgComple.GetHeadPosition();

    while(pos){
        nodo = (CNodo*)dlgComple.GetNext(pos);
        cad.Format("%d", nodo->n);
        m_Combo2.AddString(cad);
    }
    m_Combo2.SetCurSel(0);

    
}

BOOL CComplemento::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	POSITION pos = dlgSet.GetHeadPosition();
    CNodo *nodo;

    while(pos){
        nodo = (CNodo*)dlgSet.GetNext(pos);
        cad.Format("%d", nodo->n);
        m_Combo1.AddString(cad);
    }
    m_Combo1.SetCurSel(0);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
