// Ole_BDView.h : interface of the COle_BDView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLE_BDVIEW_H__6A7510B1_A704_495A_A859_CE528DBF605C__INCLUDED_)
#define AFX_OLE_BDVIEW_H__6A7510B1_A704_495A_A859_CE528DBF605C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COle_BDSet;

class COle_BDView : public COleDBRecordView
{
protected: // create from serialization only
	COle_BDView();
	DECLARE_DYNCREATE(COle_BDView)

public:
	//{{AFX_DATA(COle_BDView)
	enum{ IDD = IDD_OLE_BD_FORM };
	COle_BDSet* m_pSet;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	COle_BDDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COle_BDView)
	public:
	virtual CRowset* OnGetRowset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COle_BDView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COle_BDView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ole_BDView.cpp
inline COle_BDDoc* COle_BDView::GetDocument()
   { return (COle_BDDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLE_BDVIEW_H__6A7510B1_A704_495A_A859_CE528DBF605C__INCLUDED_)
