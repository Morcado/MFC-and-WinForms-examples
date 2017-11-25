#if !defined(AFX_SPIN_H__F6EC83AF_91AF_4953_BA0F_DE8A4128F7E8__INCLUDED_)
#define AFX_SPIN_H__F6EC83AF_91AF_4953_BA0F_DE8A4128F7E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Spin.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpin dialog

class CSpin : public CDialog
{
// Construction
public:
	CSpin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSpin)
	enum { IDD = IDD_SPIN };
	CSpinButtonCtrl	m_Spin;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSpin)
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPIN_H__F6EC83AF_91AF_4953_BA0F_DE8A4128F7E8__INCLUDED_)
