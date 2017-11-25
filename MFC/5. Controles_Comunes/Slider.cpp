// Slider.cpp : implementation file
//

#include "stdafx.h"
#include "Controles_Comunes.h"
#include "Slider.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define IDT_TIMER 1

/////////////////////////////////////////////////////////////////////////////
// CSlider dialog


CSlider::CSlider(CWnd* pParent /*=NULL*/) : CDialog(CSlider::IDD, pParent){
    band = false;
	//{{AFX_DATA_INIT(CSlider)
	//}}AFX_DATA_INIT
}


void CSlider::DoDataExchange(CDataExchange* pDX){
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSlider)
	DDX_Control(pDX, IDC_SLIDER2, m_Slider2);
	DDX_Control(pDX, IDC_SLIDER1, m_Slider1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSlider, CDialog)
	//{{AFX_MSG_MAP(CSlider)
	ON_BN_CLICKED(IDC_BUTTON1, OnAccion)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSlider message handlers

BOOL CSlider::OnInitDialog(){
	CDialog::OnInitDialog();
	SetTimer(IDT_TIMER, 20, NULL);
    m_Slider1.SetRange(0, 100);
    m_Slider2.SetRange(0, 100);
    m_Slider1.SetPos(0);
    m_Slider2.SetPos(0);
    pos = 0;
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSlider::OnAccion(){
    band = true;
}

void CSlider::OnTimer(UINT nIDEvent){
    CString cad, cad2;
    static int pos2 = 0;
    if(band){
        m_Slider1.SetPos(pos++);
        if(pos == 100){
            pos = 0;
        }
        pos2 = m_Slider2.GetPos();
        cad.Format("%d", pos);
        cad2.Format("%d", pos2);

        SetDlgItemText(IDC_EDIT1, cad);
        SetDlgItemText(IDC_EDIT2, cad2);
    }
    CDialog::OnTimer(nIDEvent);
}
