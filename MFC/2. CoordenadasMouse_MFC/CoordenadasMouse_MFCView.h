// CoordenadasMouse_MFCView.h : interface of the CCoordenadasMouse_MFCView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COORDENADASMOUSE_MFCVIEW_H__02000BF1_C495_4DE9_806E_23B7976D0BED__INCLUDED_)
#define AFX_COORDENADASMOUSE_MFCVIEW_H__02000BF1_C495_4DE9_806E_23B7976D0BED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCoordenadasMouse_MFCView : public CView
{
protected: // create from serialization only
	CCoordenadasMouse_MFCView();
	DECLARE_DYNCREATE(CCoordenadasMouse_MFCView)

// Attributes
public:
	CCoordenadasMouse_MFCDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCoordenadasMouse_MFCView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	CString cad;
	int y;
	int x;
	bool band;
	virtual ~CCoordenadasMouse_MFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCoordenadasMouse_MFCView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CoordenadasMouse_MFCView.cpp
inline CCoordenadasMouse_MFCDoc* CCoordenadasMouse_MFCView::GetDocument()
   { return (CCoordenadasMouse_MFCDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COORDENADASMOUSE_MFCVIEW_H__02000BF1_C495_4DE9_806E_23B7976D0BED__INCLUDED_)
