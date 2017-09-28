
#if !defined(AFX_LISTA_NUM_H__FEC94F47_9E46_44A9_81B4_580E5F0FE617__INCLUDED_)
#define AFX_LISTA_NUM_H__FEC94F47_9E46_44A9_81B4_580E5F0FE617__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"

typedef struct reg Nodo;

struct reg{
    int num;
    Nodo *sig;
};


#endif // !defined(AFX_LISTA_NUM_H__FEC94F47_9E46_44A9_81B4_580E5F0FE617__INCLUDED_)
