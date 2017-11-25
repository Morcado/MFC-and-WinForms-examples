// NodoR.h: interface for the CNodoR class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODOR_H__99A65E09_CB7E_442C_B2F5_C99C3BCC3042__INCLUDED_)
#define AFX_NODOR_H__99A65E09_CB7E_442C_B2F5_C99C3BCC3042__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "NodoP.h"

class CNodoR : public CObject{
public:
    DECLARE_SERIAL(CNodoR)
	CNodoR(int num); //constructor
	CNodoP *arriba; //apuntador arriba
	int n; //peso
	CNodoR(); //constructor por defeco
	virtual ~CNodoR(); //destructor au au au

    void Serialize(CArchive& ar);
};

#endif // !defined(AFX_NODOR_H__99A65E09_CB7E_442C_B2F5_C99C3BCC3042__INCLUDED_)
