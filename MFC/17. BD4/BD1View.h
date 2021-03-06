// BD1View.h : interface of the CBD1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BD1VIEW_H__3C9615C9_868E_4EB3_883F_529CDC34CCC7__INCLUDED_)
#define AFX_BD1VIEW_H__3C9615C9_868E_4EB3_883F_529CDC34CCC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBD1View : public CScrollView
{
protected: // create from serialization only
	CBD1View();
	DECLARE_DYNCREATE(CBD1View)

// Attributes
public:
	CBD1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBD1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	CTabla* m_p_Tabla;
	virtual ~CBD1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBD1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BD1View.cpp
inline CBD1Doc* CBD1View::GetDocument()
   { return (CBD1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BD1VIEW_H__3C9615C9_868E_4EB3_883F_529CDC34CCC7__INCLUDED_)
