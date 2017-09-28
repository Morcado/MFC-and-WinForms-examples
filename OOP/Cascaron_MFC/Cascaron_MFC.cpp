#include <afxwin.h>

class CCascaron_MFC: public CWinApp{

    virtual BOOL InitInstance(){
        AfxMessageBox("Hola MFC");
        return TRUE;
    }
};

CCascaron_MFC theAppp;

