#if !defined(AFX_NUMEROS_H__6810695C_7D71_4478_BEBC_62F8E59560EC__INCLUDED_)
#define AFX_NUMEROS_H__6810695C_7D71_4478_BEBC_62F8E59560EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Numeros.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNumeros dialog

class CNumeros : public CDialog{
// Construction
public:
	CObList lista_combo;
	CString combo;
	CNumeros(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNumeros)
	enum { IDD = IDD_LISTA };
	CComboBox	m_Combo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumeros)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNumeros)
	afx_msg void OnAccion();
	virtual BOOL OnInitDialog();
	afx_msg void OnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMEROS_H__6810695C_7D71_4478_BEBC_62F8E59560EC__INCLUDED_)
