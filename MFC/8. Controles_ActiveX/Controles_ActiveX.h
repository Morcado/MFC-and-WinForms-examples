// Controles_ActiveX.h : main header file for the CONTROLES_ACTIVEX application
//

#if !defined(AFX_CONTROLES_ACTIVEX_H__875A9A6E_486F_4679_8F72_B8D4BD5FAA20__INCLUDED_)
#define AFX_CONTROLES_ACTIVEX_H__875A9A6E_486F_4679_8F72_B8D4BD5FAA20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CControles_ActiveXApp:
// See Controles_ActiveX.cpp for the implementation of this class
//

class CControles_ActiveXApp : public CWinApp
{
public:
	CControles_ActiveXApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControles_ActiveXApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CControles_ActiveXApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLES_ACTIVEX_H__875A9A6E_486F_4679_8F72_B8D4BD5FAA20__INCLUDED_)
