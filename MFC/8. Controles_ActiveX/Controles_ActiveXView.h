// Controles_ActiveXView.h : interface of the CControles_ActiveXView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTROLES_ACTIVEXVIEW_H__1AFAED19_E0BD_489F_AD99_90E22117CEF4__INCLUDED_)
#define AFX_CONTROLES_ACTIVEXVIEW_H__1AFAED19_E0BD_489F_AD99_90E22117CEF4__INCLUDED_

#include "Tree.h"	// Added by ClassView
#include "Video.h"	// Added by ClassView
#include "Calendario.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CControles_ActiveXView : public CView
{
protected: // create from serialization only
	CControles_ActiveXView();
	DECLARE_DYNCREATE(CControles_ActiveXView)

// Attributes
public:
	CControles_ActiveXDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControles_ActiveXView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	UINT m_ID;
	CTree dlgTree;
	bool band;
	int opcion;

	CCalendario dlgCal;
	CVideo dlgVideo;
	virtual ~CControles_ActiveXView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CControles_ActiveXView)
	//}}AFX_MSG
    afx_msg void OnActiveX(UINT nID);
    afx_msg void OnComunesUpdateX(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Controles_ActiveXView.cpp
inline CControles_ActiveXDoc* CControles_ActiveXView::GetDocument()
   { return (CControles_ActiveXDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLES_ACTIVEXVIEW_H__1AFAED19_E0BD_489F_AD99_90E22117CEF4__INCLUDED_)
