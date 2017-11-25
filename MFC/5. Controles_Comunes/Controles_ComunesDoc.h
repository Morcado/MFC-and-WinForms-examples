// Controles_ComunesDoc.h : interface of the CControles_ComunesDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTROLES_COMUNESDOC_H__412CC4A5_9447_494F_A797_B0C161A67490__INCLUDED_)
#define AFX_CONTROLES_COMUNESDOC_H__412CC4A5_9447_494F_A797_B0C161A67490__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CControles_ComunesDoc : public CDocument
{
protected: // create from serialization only
	CControles_ComunesDoc();
	DECLARE_DYNCREATE(CControles_ComunesDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControles_ComunesDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CControles_ComunesDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CControles_ComunesDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLES_COMUNESDOC_H__412CC4A5_9447_494F_A797_B0C161A67490__INCLUDED_)
