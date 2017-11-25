// DespVertDoc.h : interface of the CDespVertDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DESPVERTDOC_H__69E8C93A_1300_4444_AAD4_51D8887CA820__INCLUDED_)
#define AFX_DESPVERTDOC_H__69E8C93A_1300_4444_AAD4_51D8887CA820__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDespVertDoc : public CDocument
{
protected: // create from serialization only
	CDespVertDoc();
	DECLARE_DYNCREATE(CDespVertDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDespVertDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDespVertDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDespVertDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESPVERTDOC_H__69E8C93A_1300_4444_AAD4_51D8887CA820__INCLUDED_)
