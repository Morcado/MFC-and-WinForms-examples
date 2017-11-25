// GrafoOptimoAleatorio.h : main header file for the GRAFOOPTIMOALEATORIO application
//

#if !defined(AFX_GRAFOOPTIMOALEATORIO_H__0EF82BFF_4E0C_4E68_AD64_604283620DDB__INCLUDED_)
#define AFX_GRAFOOPTIMOALEATORIO_H__0EF82BFF_4E0C_4E68_AD64_604283620DDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioApp:
// See GrafoOptimoAleatorio.cpp for the implementation of this class
//

class CGrafoOptimoAleatorioApp : public CWinApp
{
public:
	CGrafoOptimoAleatorioApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGrafoOptimoAleatorioApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGrafoOptimoAleatorioApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAFOOPTIMOALEATORIO_H__0EF82BFF_4E0C_4E68_AD64_604283620DDB__INCLUDED_)
