// Numeros.cpp : implementation file
//

#include "stdafx.h"
#include "Lista_Combo.h"
#include "Numeros.h"
#include "Nodo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNumeros dialog


CNumeros::CNumeros(CWnd* pParent /*=NULL*/)
	: CDialog(CNumeros::IDD, pParent){
	//{{AFX_DATA_INIT(CNumeros)
	//}}AFX_DATA_INIT
    
}


void CNumeros::DoDataExchange(CDataExchange* pDX){
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNumeros)
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNumeros, CDialog)
	//{{AFX_MSG_MAP(CNumeros)
	ON_BN_CLICKED(IDC_ACCION, OnAccion)
	ON_BN_CLICKED(IDOK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNumeros message handlers

void CNumeros::OnAccion(){
    
    POSITION pos = lista_combo.GetHeadPosition();
    CNodo *nodo;
    CString cad;

    while(pos){
        nodo = (CNodo*)lista_combo.GetNext(pos);
        cad.Format("%d", nodo->numero);
        m_Combo.AddString(cad);
    }
    //m_Combo.SendMessage(CB_INSERTSTRING, 0, 0);
    m_Combo.SetCurSel(1);
    //SetDlgItemText(IDC_COMBO1, "Hola Andrey");
}

BOOL CNumeros::OnInitDialog() {
    CDialog::OnInitDialog();
    
    return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CNumeros::OnOk(){
    CNodo *c;

    POSITION pos = lista_combo.GetHeadPosition();
    POSITION pos2 = lista_combo.GetTailPosition();
    if(pos != pos2){
        while(!lista_combo.IsEmpty()){
            c = (CNodo*)lista_combo.RemoveHead();
            pos = lista_combo.GetHeadPosition();
            delete(c);
        }
    }
    EndDialog(IDOK);
    //m_Combo.DestroyWindow();
    //DestroyWindow();
    //lista_combo.Dump();
}
