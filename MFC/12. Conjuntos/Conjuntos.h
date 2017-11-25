// Conjuntos.h : main header file for the CONJUNTOS application
//

#if !defined(AFX_CONJUNTOS_H__A7AFD98E_95DD_46A6_AA52_09CBEC581FEA__INCLUDED_)
#define AFX_CONJUNTOS_H__A7AFD98E_95DD_46A6_AA52_09CBEC581FEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CConjuntosApp:
// See Conjuntos.cpp for the implementation of this class
//

class CConjuntosApp : public CWinApp
{
public:
	CConjuntosApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConjuntosApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CConjuntosApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONJUNTOS_H__A7AFD98E_95DD_46A6_AA52_09CBEC581FEA__INCLUDED_)
