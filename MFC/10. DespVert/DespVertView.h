// DespVertView.h : interface of the CDespVertView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DESPVERTVIEW_H__86EA8EBF_2474_4A95_8217_8B47F3A69335__INCLUDED_)
#define AFX_DESPVERTVIEW_H__86EA8EBF_2474_4A95_8217_8B47F3A69335__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAXREN 1000
class CDespVertView : public CScrollView
{
protected: // create from serialization only
	CDespVertView();
	DECLARE_DYNCREATE(CDespVertView)

// Attributes
public:
	CDespVertDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDespVertView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDespVertView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDespVertView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DespVertView.cpp
inline CDespVertDoc* CDespVertView::GetDocument()
   { return (CDespVertDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESPVERTVIEW_H__86EA8EBF_2474_4A95_8217_8B47F3A69335__INCLUDED_)
