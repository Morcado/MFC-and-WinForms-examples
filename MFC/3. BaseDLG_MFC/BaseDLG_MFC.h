// BaseDLG_MFC.h : main header file for the BASEDLG_MFC application
//

#if !defined(AFX_BASEDLG_MFC_H__B96D7C96_223C_480E_B023_70BA921BDFDD__INCLUDED_)
#define AFX_BASEDLG_MFC_H__B96D7C96_223C_480E_B023_70BA921BDFDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBaseDLG_MFCApp:
// See BaseDLG_MFC.cpp for the implementation of this class
//

class CBaseDLG_MFCApp : public CWinApp
{
public:
	CBaseDLG_MFCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseDLG_MFCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBaseDLG_MFCApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEDLG_MFC_H__B96D7C96_223C_480E_B023_70BA921BDFDD__INCLUDED_)
