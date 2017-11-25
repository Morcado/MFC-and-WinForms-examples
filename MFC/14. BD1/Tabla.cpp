// Tabla.cpp : implementation file
//

#include "stdafx.h"
#include "BD1.h"
#include "Tabla.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabla

IMPLEMENT_DYNAMIC(CTabla, CRecordset)

CTabla::CTabla(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CTabla)
	m_Id = 0;
	m_Clave = _T("");
	m_Nombre = _T("");
	m_Calificaci_n_1 = 0;
	m_Calificaci_n_2 = 0;
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CTabla::GetDefaultConnect()
{
	return _T("ODBC;DSN=MY_ACCESS");
}

CString CTabla::GetDefaultSQL()
{
	return _T("[Calificaciones]");
}

void CTabla::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CTabla)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Id]"), m_Id);
	RFX_Text(pFX, _T("[Clave]"), m_Clave);
	RFX_Text(pFX, _T("[Nombre]"), m_Nombre);
	RFX_Long(pFX, _T("[Calificación 1]"), m_Calificaci_n_1);
	RFX_Long(pFX, _T("[Calificación 2]"), m_Calificaci_n_2);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CTabla diagnostics

#ifdef _DEBUG
void CTabla::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTabla::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
