// CajaImprime.cpp : implementation file
//

#include "stdafx.h"
#include "GrafoOptimoAleatorio.h"
#include "CajaImprime.h"
#include "NodoP.h"
#include "NodoR.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCajaImprime dialog


CCajaImprime::CCajaImprime(CWnd* pParent /*=NULL*/) : CDialog(CCajaImprime::IDD, pParent){
	//{{AFX_DATA_INIT(CCajaImprime)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCajaImprime::DoDataExchange(CDataExchange* pDX){
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCajaImprime)
	DDX_Control(pDX, IDC_LIST1, m_Grafo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCajaImprime, CDialog)
	//{{AFX_MSG_MAP(CCajaImprime)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCajaImprime message handlers

BOOL CCajaImprime::OnInitDialog(){
	CDialog::OnInitDialog();
    POSITION posP, posR;
    CNodoP *np;
    CNodoR *nr;
    char name = 'A';
    CString peso;
    int i = 0;
    int j = 0;
    int maxNP = gDlg.GetCount();


    m_Grafo.InsertColumn(0, "P/R", LVCFMT_LEFT, 50, -1);

    for(i = 0; i < maxNP; i++){
        m_Grafo.InsertColumn(i+1, (CString)name, LVCFMT_LEFT, 50, -1);
        m_Grafo.InsertItem(i+1, (CString)name++);
    }

    i = 0;
    j = 1;
    name = 'A';
    posP = gDlg.GetHeadPosition();
    
    while(posP){
        np = (CNodoP*)gDlg.GetNext(posP);
        posR = np->abajo.GetHeadPosition();

        while(posR){
            nr = (CNodoR*)np->abajo.GetNext(posR);
            peso.Format("%d", nr->n);
            if(nr->arriba->nombre == name){
                m_Grafo.SetItemText(i, j++, peso);
                name++;
            }
            else{
                while(nr->arriba->nombre != name){
                    name++;
                    m_Grafo.SetItemText(i, j++, "NULL");
                }
                 
                m_Grafo.SetItemText(i, j++, peso);
                name++;
            }
           
        }
        while(j <= maxNP){
            m_Grafo.SetItemText(i, j, "NULL");
            j++;
        }
        name = 'A';
        i++;
        j = 1;
    }
  
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCajaImprime::OnOK(){

    gDlg.RemoveAll();
	CDialog::OnOK();
}
