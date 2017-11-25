// Nodo.h: interface for the CNodo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODO_H__0249D484_F81C_4464_B3D2_27E9CA268853__INCLUDED_)
#define AFX_NODO_H__0249D484_F81C_4464_B3D2_27E9CA268853__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNodo : public CObject{
public:
	int numero;
	CNodo(int n);
	virtual ~CNodo();

};

#endif // !defined(AFX_NODO_H__0249D484_F81C_4464_B3D2_27E9CA268853__INCLUDED_)
