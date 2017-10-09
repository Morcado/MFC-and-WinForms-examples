#include <afxwin.h>
#include <stack>

using namespace std;    

stack <int> s;
int x = 100, y = 100;
bool flag = false;
bool uno = false;

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
    dc.Rectangle(x - 5, y - 5, x + 505, y + 77);
    if(flag){
        dc.TextOut(x, y, "Hello");
    }
}

void CCascaron_Frame :: OnChar(UINT nChar){

    CDC *pDC = GetDC();

    CFont font;
    CPen pen;
    static int tam = 9, lin = 15;
    RECT rt = {100, 100, 600, 172};
    /*if(!uno){ 
        pDC->Ellipse(300, 300, 400, 400);
        uno= true;
    }*/
    //rt.top = 0;
    //rt.left = 0;
    //GetClientRect(&rt);

    pen.CreatePen(PS_DASH, 1, (COLORREF)0x00FFFFFF);
    font.CreateFont(12, 8, 0, 0, FW_NORMAL, false, false, 0, ANSI_CHARSET, OUT_CHARACTER_PRECIS, 
            CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "Lucida Console");
    pDC->SelectObject(&pen);
    pDC->SelectObject(&font);

    switch(nChar){
        case 8: //borrar
            if(x > rt.left){ //si borra mientras no esté cerca del principio
                pDC->Rectangle(x, y, x + tam, y + lin); //borra el caracter
                pDC->Rectangle(x + tam*2, y, x + tam, y + lin); //borra la linea siguiente
                x -= tam; //retrocede el cursor
            }
            else{
                if(y > rt.top){  //si borra al principio de la linea y aún hay lineas arriba
                    pDC->Rectangle(x + tam*2, y, x + tam, y + lin);
                    y -= lin;  
                    x = s.top(); //recupera la ultima distancia guardada de la x
                    s.pop(); 
                }
            }
        break;
        case 9: //tabulador
            if(x < rt.right - 44){
                pDC->Rectangle(x + tam*2, y, x + tam, y + lin); //borra la linea siguiente
                x += 4*tam; //agrega cuatro espacios
            }
            break;
        case '\r': //enter
            if(y < rt.bottom - lin){
                pDC->Rectangle(x + tam*2, y, x + tam, y + lin); // dibuja un rectangulo blanco siguiente del tabulador
                s.push(x); //guarda la distancia de la x y reinicia x y aumenta y
                y += lin;
                x = rt.left;
            }
            break;
        default: //cualquier tecla
            
            if(x > rt.right - 20){ //si llega al final de la línea
                pDC->Rectangle(x + tam*2, y, x + tam, y + lin);
                s.push(x); //garda la ultima equiz
                y += lin;
                x = rt.left;
                if(y > rt.bottom){ //cuando llega al ultimo limite
                    x = rt.top; //reinicia y y x
                    y = rt.left;
                    while(!s.empty()){ //vacia la pila de x
                        s.pop();
                    }
                    x -= tam;
                    InvalidateRect(&rt, TRUE); //repinta todo
                }
            }
            pDC->TextOut(x += tam, y, nChar);
            
    }
    //Invalidate();
    //InvalidateRect(&rt, FALSE);
    pDC->TextOut(x + tam, y, "_");
    pen.DeleteObject();
    font.DeleteObject();
}

void CCascaron_Frame :: OnLButtonDown(UINT f, CPoint p){

}

CCascaron_MFC theAppp;
