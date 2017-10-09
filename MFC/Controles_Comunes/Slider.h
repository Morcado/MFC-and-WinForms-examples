#if !defined(AFX_SLIDER_H__7E5CB06B_47C7_47AB_8146_8AEB8C913D93__INCLUDED_)
#define AFX_SLIDER_H__7E5CB06B_47C7_47AB_8146_8AEB8C913D93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Slider.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSlider dialog

class CSlider : public CDialog
{
// Construction
public:
	CSlider(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSlider)
	enum { IDD = IDD_DIALOG1 };
	CSliderCtrl	m_Slider2;
	CSliderCtrl	m_Slider1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSlider)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSlider)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLIDER_H__7E5CB06B_47C7_47AB_8146_8AEB8C913D93__INCLUDED_)
