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

/////////////////////////////////////////////////////////////////////////////
// CSlider dialog


CSlider::CSlider(CWnd* pParent /*=NULL*/)
	: CDialog(CSlider::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSlider)
	//}}AFX_DATA_INIT
}


void CSlider::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSlider)
	DDX_Control(pDX, IDC_SLIDER2, m_Slider2);
	DDX_Control(pDX, IDC_SLIDER1, m_Slider1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSlider, CDialog)
	//{{AFX_MSG_MAP(CSlider)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSlider message handlers

BOOL CSlider::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
