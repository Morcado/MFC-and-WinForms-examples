// DespVert1View.h : interface of the CDespVert1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DESPVERT1VIEW_H__4816E98D_5EDD_439B_BCB5_1C2C7D9B5826__INCLUDED_)
#define AFX_DESPVERT1VIEW_H__4816E98D_5EDD_439B_BCB5_1C2C7D9B5826__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAXREN 1000
class CDespVert1View : public CScrollView
{
protected: // create from serialization only
	CDespVert1View();
	DECLARE_DYNCREATE(CDespVert1View)

// Attributes
public:
	CDespVert1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDespVert1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDespVert1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDespVert1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DespVert1View.cpp
inline CDespVert1Doc* CDespVert1View::GetDocument()
   { return (CDespVert1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESPVERT1VIEW_H__4816E98D_5EDD_439B_BCB5_1C2C7D9B5826__INCLUDED_)
