//{{AFX_INCLUDES()
#include "monthview.h"
//}}AFX_INCLUDES
#if !defined(AFX_CALENDARIO_H__E2DDA99E_BB03_4D16_92E0_8399237E16BB__INCLUDED_)
#define AFX_CALENDARIO_H__E2DDA99E_BB03_4D16_92E0_8399237E16BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Calendario.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCalendario dialog

class CCalendario : public CDialog
{
// Construction
public:
	CString cad;
	CCalendario(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCalendario)
	enum { IDD = IDD_CAL };
	CMonthView	m_Cal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalendario)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCalendario)
	virtual BOOL OnInitDialog();
	afx_msg void OnDateClickMonthview1(DATE DateClicked);
	virtual void OnOK();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALENDARIO_H__E2DDA99E_BB03_4D16_92E0_8399237E16BB__INCLUDED_)
