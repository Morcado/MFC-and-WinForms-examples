// Video.cpp : implementation file

#include "stdafx.h"
#include "Controles_ActiveX.h"
#include "Video.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVideo dialog
CVideo::CVideo(CWnd* pParent /*=NULL*/) : CDialog(CVideo::IDD, pParent){
	//{{AFX_DATA_INIT(CVideo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
    
}

void CVideo::DoDataExchange(CDataExchange* pDX){
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVideo)
	DDX_Control(pDX, IDC_OCX1, m_Video);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CVideo, CDialog)
	//{{AFX_MSG_MAP(CVideo) 
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_PAUSA, OnPausa)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVideo message handlers

void CVideo::OnPlay(){
    boton.play();
}

void CVideo::OnPausa() {
    boton.pause();	
}

void CVideo::OnStop() {
    boton.stop();	
}

BOOL CVideo::OnInitDialog(){
	CDialog::OnInitDialog();
	boton = m_Video.GetControls();
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
