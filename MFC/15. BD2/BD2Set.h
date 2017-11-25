// BD2Set.h : interface of the CBD2Set class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BD2SET_H__9968A218_C45A_4309_A41A_C50F016D5541__INCLUDED_)
#define AFX_BD2SET_H__9968A218_C45A_4309_A41A_C50F016D5541__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBD2Set : public CRecordset
{
public:
	CBD2Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CBD2Set)

// Field/Param Data
	//{{AFX_FIELD(CBD2Set, CRecordset)
	long	m_Id;
	CString	m_Clave;
	CString	m_Nombre;
	long	m_Calificaci_n_1;
	long	m_Calificaci_n_2;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBD2Set)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BD2SET_H__9968A218_C45A_4309_A41A_C50F016D5541__INCLUDED_)

