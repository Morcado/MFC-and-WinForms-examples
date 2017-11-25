// ShortCutView.h : interface of the CShortCutView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHORTCUTVIEW_H__C6A5FDB9_A02A_4615_AF65_A710E3F5C554__INCLUDED_)
#define AFX_SHORTCUTVIEW_H__C6A5FDB9_A02A_4615_AF65_A710E3F5C554__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShortCutView : public CView
{
protected: // create from serialization only
	CShortCutView();
	DECLARE_DYNCREATE(CShortCutView)

// Attributes
public:
	CShortCutDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShortCutView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	HCURSOR cursor;
	bool Pband;
	bool bandfinal;
	CPen* plumaOld;
	CPoint punto2;
	bool band;
	CPoint punto;
	COLORREF color;
	CPen *pluma;
	virtual ~CShortCutView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShortCutView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPluma();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ShortCutView.cpp
inline CShortCutDoc* CShortCutView::GetDocument()
   { return (CShortCutDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHORTCUTVIEW_H__C6A5FDB9_A02A_4615_AF65_A710E3F5C554__INCLUDED_)
