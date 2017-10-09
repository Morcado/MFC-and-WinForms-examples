// BaseDLG_MFCDlg.h : header file
//

#if !defined(AFX_BASEDLG_MFCDLG_H__45CCB633_F397_4A87_BA75_8697C8A302DC__INCLUDED_)
#define AFX_BASEDLG_MFCDLG_H__45CCB633_F397_4A87_BA75_8697C8A302DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBaseDLG_MFCDlg dialog

class CBaseDLG_MFCDlg : public CDialog
{
// Construction
public:
	CWnd pCombo;
	CBaseDLG_MFCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBaseDLG_MFCDlg)
	enum { IDD = IDD_BASEDLG_MFC_DIALOG };
	CComboBox m_Combo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseDLG_MFCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBaseDLG_MFCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAccion();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEDLG_MFCDLG_H__45CCB633_F397_4A87_BA75_8697C8A302DC__INCLUDED_)
