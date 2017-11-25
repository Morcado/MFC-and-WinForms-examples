// BD2Doc.h : interface of the CBD2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BD2DOC_H__BCB5E130_EC89_4D57_930E_73BB97CDCC1F__INCLUDED_)
#define AFX_BD2DOC_H__BCB5E130_EC89_4D57_930E_73BB97CDCC1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "BD2Set.h"


class CBD2Doc : public CDocument
{
protected: // create from serialization only
	CBD2Doc();
	DECLARE_DYNCREATE(CBD2Doc)

// Attributes
public:
	CBD2Set m_bD2Set;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBD2Doc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBD2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBD2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BD2DOC_H__BCB5E130_EC89_4D57_930E_73BB97CDCC1F__INCLUDED_)
