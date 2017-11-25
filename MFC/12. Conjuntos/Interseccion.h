#if !defined(AFX_INTERSECCION_H__DA4CFB63_0BE6_4BDF_9F88_17370338FE08__INCLUDED_)
#define AFX_INTERSECCION_H__DA4CFB63_0BE6_4BDF_9F88_17370338FE08__INCLUDED_

#include "Set.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Interseccion.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInterseccion dialog

class CInterseccion : public CDialog
{
// Construction
public:
	CSet inter;
	CSet setB;
	CSet setA;
	CInterseccion(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInterseccion)
	enum { IDD = IDD_INTER };
	CComboBox	m_Combo3;
	CComboBox	m_Combo2;
	CComboBox	m_Combo1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInterseccion)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInterseccion)
	virtual BOOL OnInitDialog();
	afx_msg void OnInterseccion();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INTERSECCION_H__DA4CFB63_0BE6_4BDF_9F88_17370338FE08__INCLUDED_)
