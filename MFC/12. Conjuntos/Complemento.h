#if !defined(AFX_COMPLEMENTO_H__661CE948_C3E3_44AB_B8FF_A1BB57337462__INCLUDED_)
#define AFX_COMPLEMENTO_H__661CE948_C3E3_44AB_B8FF_A1BB57337462__INCLUDED_

#include "Set.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Complemento.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CComplemento dialog

class CComplemento : public CDialog
{
// Construction
public:
	CSet dlgComple;
	CString cad;
	CSet dlgSet;
	CComplemento(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CComplemento)
	enum { IDD = IDD_COMPLEMENTO };
	CComboBox	m_Combo1;
	CComboBox	m_Combo2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComplemento)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CComplemento)
	afx_msg void OnComple();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMPLEMENTO_H__661CE948_C3E3_44AB_B8FF_A1BB57337462__INCLUDED_)
