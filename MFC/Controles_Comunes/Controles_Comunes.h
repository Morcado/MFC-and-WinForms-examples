// Controles_Comunes.h : main header file for the CONTROLES_COMUNES application
//

#if !defined(AFX_CONTROLES_COMUNES_H__4E464FC9_95AB_4A29_91FE_52C68B060BB9__INCLUDED_)
#define AFX_CONTROLES_COMUNES_H__4E464FC9_95AB_4A29_91FE_52C68B060BB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CControles_ComunesApp:
// See Controles_Comunes.cpp for the implementation of this class
//

class CControles_ComunesApp : public CWinApp
{
public:
	CControles_ComunesApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControles_ComunesApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CControles_ComunesApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLES_COMUNES_H__4E464FC9_95AB_4A29_91FE_52C68B060BB9__INCLUDED_)
