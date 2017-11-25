// BD2View.h : interface of the CBD2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BD2VIEW_H__3F717723_0436_4872_8330_319E8B3E9975__INCLUDED_)
#define AFX_BD2VIEW_H__3F717723_0436_4872_8330_319E8B3E9975__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBD2Set;

class CBD2View : public CRecordView
{
protected: // create from serialization only
	CBD2View();
	DECLARE_DYNCREATE(CBD2View)

public:
	//{{AFX_DATA(CBD2View)
	enum { IDD = IDD_BD2_FORM };
	CBD2Set* m_pSet;
	//}}AFX_DATA

// Attributes
public:
	CBD2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBD2View)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnMove(UINT nIDMoveCommand);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBD2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBD2View)
	afx_msg void OnAdd();
	afx_msg void OnClear();
	afx_msg void OnDel();
	afx_msg void OnUpdate();
	afx_msg void OnUpdateUpdate(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDel(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BD2View.cpp
inline CBD2Doc* CBD2View::GetDocument()
   { return (CBD2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BD2VIEW_H__3F717723_0436_4872_8330_319E8B3E9975__INCLUDED_)
