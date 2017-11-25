// Calendario.cpp : implementation file
//

#include "stdafx.h"
#include "Controles_ActiveX.h"
#include "Calendario.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCalendario dialog


CCalendario::CCalendario(CWnd* pParent /*=NULL*/)
	: CDialog(CCalendario::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalendario)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCalendario::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalendario)
	DDX_Control(pDX, IDC_MONTHVIEW1, m_Cal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCalendario, CDialog)
	//{{AFX_MSG_MAP(CCalendario)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalendario message handlers

BOOL CCalendario::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
 	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BEGIN_EVENTSINK_MAP(CCalendario, CDialog)
    //{{AFX_EVENTSINK_MAP(CCalendario)
	ON_EVENT(CCalendario, IDC_MONTHVIEW1, 1 /* DateClick */, OnDateClickMonthview1, VTS_DATE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CCalendario::OnDateClickMonthview1(DATE DateClicked) {
	//double i = DateClicked;
    short d = m_Cal.GetDay();
    long m = m_Cal.GetMonth();
    short y = m_Cal.GetYear();
    CString mes;
    switch(m){
        case 1:
            mes = "enero";
            break;
        case 2:
            mes = "febrero";
            break;
        case 3:
            mes = "marzo";
            break;
        case 4:
            mes = "abril";
            break;
        case 5:
            mes = "mayo";
            break;
        case 6:
            mes = "junio";
            break;
        case 7:
            mes = "julio";
            break;
        case 8:
            mes = "agosto";
            break;
        case 9:
            mes = "septiembre";
            break;
        case 10:
            mes = "octubre";
            break;
        case 11:
            mes = "noviembre";
            break;
        case 12:
            mes = "diciembre";
    }
    cad.Format("%d de %s del %d", d, mes, y);
}

void CCalendario::OnOK(){
	CDialog::OnOK();
    EndDialog(IDOK);
}
