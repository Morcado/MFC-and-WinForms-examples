// ConjuntosView.h : interface of the CConjuntosView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONJUNTOSVIEW_H__DEC11265_FC45_4E67_8D5B_7E4173466350__INCLUDED_)
#define AFX_CONJUNTOSVIEW_H__DEC11265_FC45_4E67_8D5B_7E4173466350__INCLUDED_

#include "Complemento.h"	// Added by ClassView
#include "Set.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CConjuntosView : public CView{
protected: // create from serialization only
	CConjuntosView();
	DECLARE_DYNCREATE(CConjuntosView)

// Attributes
public:
	CConjuntosDoc* GetDocument();

// Operations
public:

// Overrides 
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConjuntosView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:

	int opcion;
	CObList conjunto;
	CComplemento dlgComplemento;
	virtual ~CConjuntosView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CConjuntosView)
	afx_msg void OnImprime();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

#ifndef _DEBUG  // debug version in ConjuntosView.cpp
inline CConjuntosDoc* CConjuntosView::GetDocument()
   { return (CConjuntosDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONJUNTOSVIEW_H__DEC11265_FC45_4E67_8D5B_7E4173466350__INCLUDED_)
