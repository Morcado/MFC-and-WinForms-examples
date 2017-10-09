// CoordenadasMouse_MFCDoc.h : interface of the CCoordenadasMouse_MFCDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COORDENADASMOUSE_MFCDOC_H__FEFD49AA_E237_4D5F_9D7F_0AFB3DB6DC63__INCLUDED_)
#define AFX_COORDENADASMOUSE_MFCDOC_H__FEFD49AA_E237_4D5F_9D7F_0AFB3DB6DC63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCoordenadasMouse_MFCDoc : public CDocument
{
protected: // create from serialization only
	CCoordenadasMouse_MFCDoc();
	DECLARE_DYNCREATE(CCoordenadasMouse_MFCDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCoordenadasMouse_MFCDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCoordenadasMouse_MFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCoordenadasMouse_MFCDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COORDENADASMOUSE_MFCDOC_H__FEFD49AA_E237_4D5F_9D7F_0AFB3DB6DC63__INCLUDED_)
