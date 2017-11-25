// ConjuntosDoc.h : interface of the CConjuntosDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONJUNTOSDOC_H__F8E77CDD_9CC7_4067_B0C5_2ACB63896D3A__INCLUDED_)
#define AFX_CONJUNTOSDOC_H__F8E77CDD_9CC7_4067_B0C5_2ACB63896D3A__INCLUDED_

#include "Nodo.h"	// Added by ClassView
#include "Set.h"	// Added by ClassView
#include "Complemento.h"	// Added by ClassView
#include "Interseccion.h"	// Added by ClassView
#include "Union.h"	// Added by ClassView

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CConjuntosDoc : public CDocument
{
protected: // create from serialization only
	CConjuntosDoc();
	DECLARE_DYNCREATE(CConjuntosDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConjuntosDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	bool band;
	CUnion dlgUnion;
	CSet set2;
	CInterseccion dlgInterseccion;
	CComplemento dlgComplemento;
	CSet set;
	virtual ~CConjuntosDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CConjuntosDoc)
	afx_msg void OnConjunto();
	afx_msg void OnComplemento();
	afx_msg void OnAsignacion();
	afx_msg void OnInterseccion();
	afx_msg void OnUnion();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONJUNTOSDOC_H__F8E77CDD_9CC7_4067_B0C5_2ACB63896D3A__INCLUDED_)
