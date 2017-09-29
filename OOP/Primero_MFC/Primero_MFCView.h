// Primero_MFCView.h : interface of the CPrimero_MFCView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRIMERO_MFCVIEW_H__41C5B26C_E43E_491C_8452_56DC6AA51F0E__INCLUDED_)
#define AFX_PRIMERO_MFCVIEW_H__41C5B26C_E43E_491C_8452_56DC6AA51F0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPrimero_MFCView : public CView
{
protected: // create from serialization only
	CPrimero_MFCView();
	DECLARE_DYNCREATE(CPrimero_MFCView)

// Attributes
public:
	CPrimero_MFCDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrimero_MFCView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL band;
	virtual ~CPrimero_MFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPrimero_MFCView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Primero_MFCView.cpp
inline CPrimero_MFCDoc* CPrimero_MFCView::GetDocument()
   { return (CPrimero_MFCDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRIMERO_MFCVIEW_H__41C5B26C_E43E_491C_8452_56DC6AA51F0E__INCLUDED_)
