#include <afxwin.h>
#include "CCascaron_Frame.h"
#include "CCascaron_MFC.h"

void CCascaron_Frame :: OnPaint(){
    CPaintDC dc(this);
    if(flag){
        dc.TextOut(x, y, "Hello");
    }
}

void CCascaron_Frame :: OnChar(UINT nChar){
    CDC *pDC = GetDC();
    //CSize size;
    //size = pDC->GetTextExtent(nChar)
    switch(nChar){
        case '\r':
            y += 20;
            x = 100;
            break;
        default:
            pDC->TextOut(x += 8, y, nChar);
    }
}

void CCascaron_Frame :: OnLButtonDown(UINT f, CPoint p){
    //CClientDC pDC(this);
    //x = p.x;
    //y = p.y;
    //Invalidate(FALSE); //parámetro por default
    //flag = true;
    //pDC.TextOut(100, 100, "Holaa");
}


CCascaron_MFC theAppp;

