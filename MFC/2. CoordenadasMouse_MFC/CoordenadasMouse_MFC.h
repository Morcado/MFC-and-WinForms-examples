// CoordenadasMouse_MFC.h : main header file for the COORDENADASMOUSE_MFC application
//

#if !defined(AFX_COORDENADASMOUSE_MFC_H__9AE1573A_B57C_4F3D_98CD_AC7F441E0EDA__INCLUDED_)
#define AFX_COORDENADASMOUSE_MFC_H__9AE1573A_B57C_4F3D_98CD_AC7F441E0EDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCoordenadasMouse_MFCApp:
// See CoordenadasMouse_MFC.cpp for the implementation of this class
//

class CCoordenadasMouse_MFCApp : public CWinApp
{
public:
	CCoordenadasMouse_MFCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCoordenadasMouse_MFCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCoordenadasMouse_MFCApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COORDENADASMOUSE_MFC_H__9AE1573A_B57C_4F3D_98CD_AC7F441E0EDA__INCLUDED_)
