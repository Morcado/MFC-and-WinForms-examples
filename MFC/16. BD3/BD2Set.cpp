// BD2Set.cpp : implementation of the CBD2Set class
//

#include "stdafx.h"
#include "BD2.h"
#include "BD2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBD2Set implementation

IMPLEMENT_DYNAMIC(CBD2Set, CRecordset)

CBD2Set::CBD2Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CBD2Set)
	m_Id = 0;
	m_Clave = _T("");
	m_Nombre = _T("");
	m_Calificaci_n_1 = 0;
	m_Calificaci_n_2 = 0;
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}

CString CBD2Set::GetDefaultConnect()
{
	return _T("ODBC;DSN=MY_ACCESS");
}

CString CBD2Set::GetDefaultSQL()
{
	return _T("[Calificaciones]");
}

void CBD2Set::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CBD2Set)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Id]"), m_Id);
	RFX_Text(pFX, _T("[Clave]"), m_Clave);
	RFX_Text(pFX, _T("[Nombre]"), m_Nombre);
	RFX_Long(pFX, _T("[Calificación 1]"), m_Calificaci_n_1);
	RFX_Long(pFX, _T("[Calificación 2]"), m_Calificaci_n_2);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CBD2Set diagnostics

#ifdef _DEBUG
void CBD2Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBD2Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
