
#if !defined(AFX_PREEX21_DECENAS_H__64319AF8_5B4F_4908_8EBF_5B5C58658E04__INCLUDED_)
#define AFX_PREEX21_DECENAS_H__64319AF8_5B4F_4908_8EBF_5B5C58658E04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"

typedef struct reg NP;
typedef struct reg1 NR;

struct reg{
    char nombre;
    NP *sig;
    NR *abajo;
   
};

struct reg1{
    int num;
    NR *sig;
    NP *arriba;
};

#endif // !defined(AFX_PREEX21_DECENAS_H__64319AF8_5B4F_4908_8EBF_5B5C58658E04__INCLUDED_)
