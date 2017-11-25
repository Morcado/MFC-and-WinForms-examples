#if !defined(AFX_UNION_H__C22154D5_4738_4DAD_B63B_D3417AD2D883__INCLUDED_)
#define AFX_UNION_H__C22154D5_4738_4DAD_B63B_D3417AD2D883__INCLUDED_

#include "Set.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Union.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUnion dialog

class CUnion : public CDialog
{
// Construction
public:
	CSet setB;
	CSet setA;
	CSet unio;
	CUnion(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUnion)
	enum { IDD = IDD_UNION };
	CComboBox	m_Combo3;
	CComboBox	m_Combo2;
	CComboBox	m_Combo1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUnion)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUnion)
	afx_msg void OnUnion();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UNION_H__C22154D5_4738_4DAD_B63B_D3417AD2D883__INCLUDED_)
