
#if !defined(AFX_COMBO_H__D9293594_00C6_4A90_8B76_58C0E27E8C04__INCLUDED_)
#define AFX_COMBO_H__D9293594_00C6_4A90_8B76_58C0E27E8C04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"

typedef struct reg NP;
typedef struct reg1 NR;

struct reg{
    int dec;
    NP *sig;
    NR *abajo;
};

struct reg1{
    int num;
    NR *sig;
};


#endif // !defined(AFX_COMBO_H__D9293594_00C6_4A90_8B76_58C0E27E8C04__INCLUDED_)
