// Lista_ComboDoc.h : interface of the CLista_ComboDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTA_COMBODOC_H__B9F97E7A_FBDE_4B89_BDDF_7E1EA473F97D__INCLUDED_)
#define AFX_LISTA_COMBODOC_H__B9F97E7A_FBDE_4B89_BDDF_7E1EA473F97D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLista_ComboDoc : public CDocument
{
protected: // create from serialization only
	CLista_ComboDoc();
	DECLARE_DYNCREATE(CLista_ComboDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLista_ComboDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLista_ComboDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLista_ComboDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTA_COMBODOC_H__B9F97E7A_FBDE_4B89_BDDF_7E1EA473F97D__INCLUDED_)
