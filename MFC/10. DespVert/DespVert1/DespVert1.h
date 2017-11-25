// DespVert1.h : main header file for the DESPVERT1 application
//

#if !defined(AFX_DESPVERT1_H__DDC1CAD0_2DB2_4501_A365_FF134DD39199__INCLUDED_)
#define AFX_DESPVERT1_H__DDC1CAD0_2DB2_4501_A365_FF134DD39199__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDespVert1App:
// See DespVert1.cpp for the implementation of this class
//

class CDespVert1App : public CWinApp
{
public:
	CDespVert1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDespVert1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDespVert1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESPVERT1_H__DDC1CAD0_2DB2_4501_A365_FF134DD39199__INCLUDED_)
