// botonDlg.h : header file
//

#if !defined(AFX_BOTONDLG_H__E613ADD2_592F_446C_AC37_892B447277E0__INCLUDED_)
#define AFX_BOTONDLG_H__E613ADD2_592F_446C_AC37_892B447277E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBotonDlg dialog

class CBotonDlg : public CDialog
{
// Construction
public:
	CBitmapButton img;
	CBotonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBotonDlg)
	enum { IDD = IDD_BOTON_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBotonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBotonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOTONDLG_H__E613ADD2_592F_446C_AC37_892B447277E0__INCLUDED_)
