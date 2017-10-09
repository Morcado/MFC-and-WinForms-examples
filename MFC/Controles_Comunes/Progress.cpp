// Progress.cpp : implementation file
//

#include "stdafx.h"
#include "Controles_Comunes.h"
#include "Progress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define IDT_TIMER 1
/////////////////////////////////////////////////////////////////////////////
// CProgress dialog


CProgress::CProgress(CWnd* pParent /*=NULL*/)
	: CDialog(CProgress::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProgress)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
    band = false;
}


void CProgress::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProgress)
	DDX_Control(pDX, IDC_PROGRESS3, m_Progress3);
	DDX_Control(pDX, IDC_PROGRESS2, m_Progress2);
	DDX_Control(pDX, IDC_PROGRESS1, m_Progress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProgress, CDialog)
	//{{AFX_MSG_MAP(CProgress)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, OnAccion)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgress message handlers

BOOL CProgress::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetTimer(IDT_TIMER, 20, NULL);
    m_Progress2.SetRange(0, 100);
    m_Progress3.SetRange(0, 100);
    m_Progress.SetRange(0, 100);

    m_Progress3.SetStep(-1);
    m_Progress2.SetStep(1);
    m_Progress.SetStep(0.5);

    m_Progress2.SetPos(0);
    m_Progress3.SetPos(100);
   
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CProgress::OnTimer(UINT nIDEvent){
    int paso;
    int paso2;
    if(band){
        if(nIDEvent){
            m_Progress3.StepIt();
            m_Progress2.StepIt();
            paso = m_Progress.StepIt();
            if(paso >= 50){
                m   
            }
            if(paso >= 100){

            }


            m_Progress3.StepIt();
            paso = m_Progress.StepIt();
            if(paso <= 0){
                m_Progress3.SetStep(0);
                m_Progress3.SetPos(0);

                //m_Progress2.SetPos(0);
                m_Progress2.SetStep(-1);

                m_Progress.SetPos(0);
                m_Progress.SetStep(1);
                paso2 = 1;
            }


        }
	    CDialog::OnTimer(nIDEvent);
    }
}

void CProgress::OnAccion(){
    band = true;	
}
