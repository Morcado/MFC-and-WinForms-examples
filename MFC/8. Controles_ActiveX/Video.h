//{{AFX_INCLUDES()
#include "wmpplayer4.h"
#include "wmpcontrols.h"	// Added by ClassView
//}}AFX_INCLUDES
#if !defined(AFX_VIDEO_H__BC7747BD_1D2A_433A_AF79_0111B3024221__INCLUDED_)
#define AFX_VIDEO_H__BC7747BD_1D2A_433A_AF79_0111B3024221__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Video.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVideo dialog

class CVideo : public CDialog
{
// Construction
public:
	CWMPControls boton;
	CVideo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CVideo)
	enum { IDD = IDD_VIDEO };
	CWMPPlayer4	m_Video;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CVideo)
	afx_msg void OnPlay();
	afx_msg void OnPausa();
	afx_msg void OnStop();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEO_H__BC7747BD_1D2A_433A_AF79_0111B3024221__INCLUDED_)
