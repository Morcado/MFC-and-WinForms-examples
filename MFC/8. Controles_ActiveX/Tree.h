#if !defined(AFX_TREE_H__FFD35EA1_7A9E_485A_A555_D438A9BEA0AE__INCLUDED_)
#define AFX_TREE_H__FFD35EA1_7A9E_485A_A555_D438A9BEA0AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Tree.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTree dialog

class CTree : public CDialog
{
// Construction
public:
	CTree(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTree)
	enum { IDD = IDD_TREE };
	CTreeCtrl	m_Tree;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTree)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTree)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREE_H__FFD35EA1_7A9E_485A_A555_D438A9BEA0AE__INCLUDED_)
