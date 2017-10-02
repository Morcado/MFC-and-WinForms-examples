#include <afxwin.h>
#include <stack>

using namespace std;    

stack <int> s;
int x = 0, y = 0;
bool flag = false;

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

class CCascaron_MFC: public CWinApp{ //clase aplicación

    virtual BOOL InitInstance(){
        //AfxMessageBox("Hola MFC");
        //CFont font;
        //font.CreateFont(12, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, FALSE)
        CCascaron_Frame *pFrame = new CCascaron_Frame;
        pFrame->Create(NULL, (CString)"Editor de texto");
        m_pMainWnd = pFrame;
        m_pMainWnd->ShowWindow(SW_SHOWNORMAL);

        return TRUE;
    }
};

void CCascaron_Frame :: OnPaint(){
    CPaintDC dc(this);
    if(flag){
        dc.TextOut(x, y, "Hello");
    }
}

void CCascaron_Frame :: OnChar(UINT nChar){

    CDC *pDC = GetDC();

    CFont font;
    CPen pen;
    RECT rt;
    GetClientRect(&rt);

    pen.CreatePen(PS_DASH, 1, (COLORREF)0x00FFFFFF);
    font.CreateFont(12, 8, 0, 0, FW_NORMAL, false, false, 0, ANSI_CHARSET, OUT_CHARACTER_PRECIS, 
            CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "Lucida Console");
    pDC->SelectObject(&pen);
    pDC->SelectObject(&font);
    //CSize size;
    //size = pDC->GetTextExtent(nChar)
    //pDC->TextOut(x, y, "_");
    //pDC->Rectangle(x, y, x + 9, y + 15);

    switch(nChar){
        case 8: //borrar
            if(x > 0){ //si borra mientras no esté cerca del principio
                pDC->Rectangle(x, y, x + 9, y + 15); //borra el caracter
                pDC->Rectangle(x + 9*2, y, x + 9, y + 15); //borra la linea siguiente
                x -= 9; //retrocede el cursor
            }
            else{
                if(y > 0){  //si borra al principio de la linea y aún hay lineas arriba
                    pDC->Rectangle(x + 9*2, y, x + 9, y + 15);
                    y -= 15;  
                    x = s.top(); //recupera la ultima distancia guardada de la x
                    s.pop(); 
                }
            }
        break;
        case 9: //tabulador
            if(x < rt.right - 20){
                pDC->Rectangle(x + 9*2, y, x + 9, y + 15); //borra la linea siguiente
                x += 4*9; //agrega cuatro espacios
            }
            break;
        case '\r': //enter
            pDC->Rectangle(x + 9*2, y, x + 9, y + 15); // dibuja un rectangulo blanco siguiente del tabulador
            s.push(x); //guarda la distancia de la x y reinicia x y aumenta y
            y += 15;
            x = 0;
            break;
        default: //cualquier tecla
            
            if(x > rt.right - 20){ //si llega al final de la línea
                pDC->Rectangle(x + 9*2, y, x + 9, y + 15);
                s.push(x); //garda la ultima equiz
                y += 15;
                x = 0;
                if(y > rt.bottom){ //cuando llega al ultimo limite
                    x = y = 0; //reinicia y y x
                    while(!s.empty()){ //vacia la pila de x
                        s.pop();
                    }
                    x -= 9;
                    Invalidate(); //repinta todo
                }
            }
            pDC->TextOut(x += 9, y, nChar);
            
    }
    pDC->TextOut(x + 9, y, "_");
    pen.DeleteObject();
    font.DeleteObject();
}

void CCascaron_Frame :: OnLButtonDown(UINT f, CPoint p){

}

CCascaron_MFC theAppp;
