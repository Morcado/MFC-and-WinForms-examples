// DespVert1Doc.h : interface of the CDespVert1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DESPVERT1DOC_H__CF6325DB_40F8_4A1B_844E_F84FBC9B67FC__INCLUDED_)
#define AFX_DESPVERT1DOC_H__CF6325DB_40F8_4A1B_844E_F84FBC9B67FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDespVert1Doc : public CDocument
{
protected: // create from serialization only
	CDespVert1Doc();
	DECLARE_DYNCREATE(CDespVert1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDespVert1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDespVert1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDespVert1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESPVERT1DOC_H__CF6325DB_40F8_4A1B_844E_F84FBC9B67FC__INCLUDED_)
