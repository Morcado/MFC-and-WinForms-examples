// NodoP.cpp: implementation of the CNodoP class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GrafoOptimoAleatorio.h"
#include "NodoP.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(CNodoP,CObject,1)

CNodoP::CNodoP(){

}

CNodoP::~CNodoP(){

}

CNodoP::CNodoP(char nom){
    nombre = nom;
}

void CNodoP::Serialize(CArchive& ar)
{
    if (ar.IsStoring())
    {
        ar << nombre;
   
    }
    else
    {
        ar >> nombre;
      
    }
    abajo.Serialize(ar);
}
