#include <afxwin.h>


class CCascaron_Frame: public CFrameWnd{ //clase marco
    afx_msg void OnPaint();
    //afx_msg void OnRbuttonDown(UINT
    DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CCascaron_Frame, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

void CCascaron_Frame::OnPaint(){
    CPaintDC dc(this);

    dc.TextOut(100, 100, "Hola");
}

class CCascaron_MFC: public CWinApp{ //clase aplicación

    virtual BOOL InitInstance(){
    //AfxMessageBox("Hola MFC");
        CCascaron_Frame *pMarco = new CCascaron_Frame;
        pMarco->Create(NULL, (CString)"Cascaron MFC");
        m_pMainWnd = pMarco;
        m_pMainWnd->ShowWindow(SW_SHOWNORMAL);

        return TRUE;
    }
};

CCascaron_MFC theAppp;

