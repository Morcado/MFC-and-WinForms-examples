// Ole_BDDoc.h : interface of the COle_BDDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLE_BDDOC_H__05E75D87_7954_4A89_B377_B1E5094D1E18__INCLUDED_)
#define AFX_OLE_BDDOC_H__05E75D87_7954_4A89_B377_B1E5094D1E18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Ole_BDSet.h"


class COle_BDDoc : public CDocument
{
protected: // create from serialization only
	COle_BDDoc();
	DECLARE_DYNCREATE(COle_BDDoc)

// Attributes
public:
	COle_BDSet m_ole_BDSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COle_BDDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COle_BDDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COle_BDDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLE_BDDOC_H__05E75D87_7954_4A89_B377_B1E5094D1E18__INCLUDED_)
