// Union.cpp : implementation file
//

#include "stdafx.h"
#include "Conjuntos.h"
#include "Union.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUnion dialog


CUnion::CUnion(CWnd* pParent /*=NULL*/)
	: CDialog(CUnion::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUnion)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CUnion::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUnion)
	DDX_Control(pDX, IDC_COMBO3, m_Combo3);
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUnion, CDialog)
	//{{AFX_MSG_MAP(CUnion)
	ON_BN_CLICKED(IDC_UNION, OnUnion)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUnion message handlers

void CUnion::OnUnion(){
	POSITION pos = unio.GetHeadPosition();
    CString cad;
    CNodo *nodo;

    while(pos){
        nodo = (CNodo*)unio.GetNext(pos);
        cad.Format("%d", nodo->n);
        m_Combo3.AddString(cad);
    }

    m_Combo3.SetCurSel(0);

}

BOOL CUnion::OnInitDialog(){
	CDialog::OnInitDialog();
	POSITION pos = setA.GetHeadPosition();
    POSITION pos2 = setB.GetHeadPosition();
    CString cad;
    CNodo *nodo;

    while(pos){
        nodo = (CNodo*)setA.GetNext(pos);
        cad.Format("%d", nodo->n);
        m_Combo1.AddString(cad);
    }

    m_Combo1.SetCurSel(0);

    while(pos2){
        nodo = (CNodo*)setB.GetNext(pos2);
        cad.Format("%d", nodo->n);
        m_Combo2.AddString(cad);
    }
    m_Combo2.SetCurSel(0);
    	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
