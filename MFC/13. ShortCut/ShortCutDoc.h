// ShortCutDoc.h : interface of the CShortCutDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHORTCUTDOC_H__FC80697D_D860_494C_A579_9844AC7B459A__INCLUDED_)
#define AFX_SHORTCUTDOC_H__FC80697D_D860_494C_A579_9844AC7B459A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShortCutDoc : public CDocument
{
protected: // create from serialization only
	CShortCutDoc();
	DECLARE_DYNCREATE(CShortCutDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShortCutDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShortCutDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShortCutDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHORTCUTDOC_H__FC80697D_D860_494C_A579_9844AC7B459A__INCLUDED_)
