// NodoP.h: interface for the CNodoP class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODOP_H__90321A01_C97B_4B0D_9FBF_AA10C87BFE67__INCLUDED_)
#define AFX_NODOP_H__90321A01_C97B_4B0D_9FBF_AA10C87BFE67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNodoP : public CObject{
public: 
   DECLARE_SERIAL(CNodoP)
	CObList abajo;
	char nombre;
	CNodoP(char nom);
	CNodoP();
	virtual ~CNodoP();
    void Serialize(CArchive& ar);

 
};

#endif // !defined(AFX_NODOP_H__90321A01_C97B_4B0D_9FBF_AA10C87BFE67__INCLUDED_)
