// Dialogos_ComunesDoc.h : interface of the CDialogos_ComunesDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIALOGOS_COMUNESDOC_H__42E13BB0_BCA5_476B_81F7_0BFC1CCAB109__INCLUDED_)
#define AFX_DIALOGOS_COMUNESDOC_H__42E13BB0_BCA5_476B_81F7_0BFC1CCAB109__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDialogos_ComunesDoc : public CDocument
{
protected: // create from serialization only
	CDialogos_ComunesDoc();
	DECLARE_DYNCREATE(CDialogos_ComunesDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogos_ComunesDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDialogos_ComunesDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDialogos_ComunesDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGOS_COMUNESDOC_H__42E13BB0_BCA5_476B_81F7_0BFC1CCAB109__INCLUDED_)
