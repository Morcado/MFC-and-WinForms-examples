// Nodo.h: interface for the CNodo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODO_H__00FC9A4B_FC99_4587_83C6_F8F129131CA2__INCLUDED_)
#define AFX_NODO_H__00FC9A4B_FC99_4587_83C6_F8F129131CA2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNodo : public CObject  
{
public:
	CNodo(int n);
    CNodo();

	int n;

    
    

	virtual ~CNodo();

};

#endif // !defined(AFX_NODO_H__00FC9A4B_FC99_4587_83C6_F8F129131CA2__INCLUDED_)
