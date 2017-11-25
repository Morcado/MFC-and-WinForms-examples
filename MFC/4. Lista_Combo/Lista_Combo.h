// Lista_Combo.h : main header file for the LISTA_COMBO application
//

#if !defined(AFX_LISTA_COMBO_H__90CE8E28_9AD4_43E8_BE6D_DEF4A0FDCD6C__INCLUDED_)
#define AFX_LISTA_COMBO_H__90CE8E28_9AD4_43E8_BE6D_DEF4A0FDCD6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboApp:
// See Lista_Combo.cpp for the implementation of this class
//

class CLista_ComboApp : public CWinApp
{
public:
	CLista_ComboApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLista_ComboApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLista_ComboApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTA_COMBO_H__90CE8E28_9AD4_43E8_BE6D_DEF4A0FDCD6C__INCLUDED_)
