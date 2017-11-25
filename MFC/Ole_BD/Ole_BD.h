// Ole_BD.h : main header file for the OLE_BD application
//

#if !defined(AFX_OLE_BD_H__5CED2E15_853D_4FD2_9326_26B4CE1B1810__INCLUDED_)
#define AFX_OLE_BD_H__5CED2E15_853D_4FD2_9326_26B4CE1B1810__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COle_BDApp:
// See Ole_BD.cpp for the implementation of this class
//

class COle_BDApp : public CWinApp
{
public:
	COle_BDApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COle_BDApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COle_BDApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLE_BD_H__5CED2E15_853D_4FD2_9326_26B4CE1B1810__INCLUDED_)
