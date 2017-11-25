// Set.h: interface for the CSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SET_H__21F6A145_D66F_40C7_867C_D5869DE980FF__INCLUDED_)
#define AFX_SET_H__21F6A145_D66F_40C7_867C_D5869DE980FF__INCLUDED_

#include "Nodo.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSet : public CObList  
{
public:
	bool band;
	void destruyeLista();
	CSet& operator +(CSet &s);

	void creaLista(int numeros);
    CNodo *nodo;

    CSet& operator ! (); //complemento
	CSet& operator = (CSet &l); //asignacion
    CSet& operator ^(const CSet &l); //interseccion
	CSet();
	virtual ~CSet();

};

#endif // !defined(AFX_SET_H__21F6A145_D66F_40C7_867C_D5869DE980FF__INCLUDED_)
