// boton.h : main header file for the BOTON application
//

#if !defined(AFX_BOTON_H__07CD7A10_2DF2_4D7B_9DE0_BA945358D417__INCLUDED_)
#define AFX_BOTON_H__07CD7A10_2DF2_4D7B_9DE0_BA945358D417__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBotonApp:
// See boton.cpp for the implementation of this class
//

class CBotonApp : public CWinApp
{
public:
	CBotonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBotonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBotonApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOTON_H__07CD7A10_2DF2_4D7B_9DE0_BA945358D417__INCLUDED_)
