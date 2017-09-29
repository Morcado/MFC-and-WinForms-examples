#ifndef CCASCARON_MFC
#define CCASCARON_MFC

class CCascaron_MFC: public CWinApp{ //clase aplicación

    virtual BOOL InitInstance(){
        //AfxMessageBox("Hola MFC");
        //CFont font;
        //font.CreateFont(12, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, FALSE)
        CCascaron_Frame *pFrame = new CCascaron_Frame;
        pFrame->Create(NULL, (CString)"Cascaron MFC");
        m_pMainWnd = pFrame;
        m_pMainWnd->ShowWindow(SW_SHOWNORMAL);

        return TRUE;
    }
};

#endif