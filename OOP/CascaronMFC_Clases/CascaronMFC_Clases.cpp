#include <afxwin.h>

int x = 100, y = 100;
BOOL flag = false;

class CCascaron_Frame: public CFrameWnd{ //clase marco
    afx_msg void OnPaint();
    afx_msg void OnLButtonDown(UINT, CPoint);
    afx_msg void OnChar(UINT);
    DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CCascaron_Frame, CFrameWnd)
    ON_WM_CHAR()
    ON_WM_LBUTTONDOWN()
    ON_WM_PAINT()
END_MESSAGE_MAP()

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
    CClientDC pDC(this);
    x = p.x;
    y = p.y;
    Invalidate(FALSE); //parámetro por default
    flag = true;
    //pDC.TextOut(100, 100, "Holaa");
}

class CCascaron_MFC: public CWinApp{ //clase aplicación

    virtual BOOL InitInstance(){
        //AfxMessageBox("Hola MFC");
        CCascaron_Frame *pFrame = new CCascaron_Frame;
        pFrame->Create(NULL, (CString)"Cascaron MFC");
        m_pMainWnd = pFrame;
        m_pMainWnd->ShowWindow(SW_SHOWNORMAL);

        return TRUE;
    }
};

CCascaron_MFC theAppp;

