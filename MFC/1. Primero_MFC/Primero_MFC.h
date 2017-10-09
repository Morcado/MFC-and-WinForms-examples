// Primero_MFC.h : main header file for the PRIMERO_MFC application
//

#if !defined(AFX_PRIMERO_MFC_H__5D018F76_5812_4229_943F_500AE34CFE28__INCLUDED_)
#define AFX_PRIMERO_MFC_H__5D018F76_5812_4229_943F_500AE34CFE28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPrimero_MFCApp:
// See Primero_MFC.cpp for the implementation of this class
//

class CPrimero_MFCApp : public CWinApp
{
public:
	CPrimero_MFCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrimero_MFCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPrimero_MFCApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRIMERO_MFC_H__5D018F76_5812_4229_943F_500AE34CFE28__INCLUDED_)
