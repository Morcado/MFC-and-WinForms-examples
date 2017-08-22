/*
Nombre: Oscar Armando González Patiño
Fecha: 13 de junio de 2017
Proyecto: Menus
Funcionalidad: Menus de la ventana con separadores
Métodos: Rectangle, Ellipse, RoundRect, DialogBox	 
Handles: HACCEL
Mensajes:
Tipos:
Estructuras:
*/

#include <windows.h>
#include "Menus.h"

HINSTANCE hInstance;
char szProgName[] = "Programa";
char szProgMenu[] = "MiMenu";

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DiagProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL APIENTRY About(HWND hDlg, UINT message, UINT wParam, LONG lParam);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow){
    HWND hWnd;
    MSG lpMsg;
    WNDCLASS wcApp;
    HACCEL hAccel;
    hInstance = hInst;
    
    wcApp.lpszClassName = szProgName;
    wcApp.hInstance = hInst;
    wcApp.lpfnWndProc = WndProc;
    wcApp.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcApp.hIcon = 0;
    wcApp.lpszMenuName = szProgMenu;
    wcApp.hbrBackground = GetStockObject(WHITE_BRUSH);
    wcApp.style = CS_HREDRAW|CS_VREDRAW;
    wcApp.cbClsExtra = 0;
    wcApp.cbWndExtra = 0;

    if(!RegisterClass(&wcApp))
        return(0);

    

    hWnd = CreateWindow(szProgName, "Programa Menu", 
                        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                        CW_USEDEFAULT, (HWND)NULL, (HMENU)NULL, (HANDLE)hInst, (LPSTR)NULL);

    hAccel = LoadAccelerators(hInst, "MiAccel");
    //TranslateAccelerator(hWnd, hAccel, &lpMsg);

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    while(GetMessage(&lpMsg, 0, 0, 0)){
        if (!TranslateAccelerator(hWnd, hAccel, &lpMsg)){

            TranslateMessage(&lpMsg);
            DispatchMessage(&lpMsg);
        }
    }

    return(lpMsg.wParam);
}

BOOL APIENTRY About(HWND hDlg, UINT message, UINT wParam, LONG lParam){
    switch(message){
        case WM_INITDIALOG: 
            return (TRUE);
        case WM_COMMAND:
            if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL){
                EndDialog(hDlg, TRUE);
                return TRUE;
            }
            break;
    }    
    return FALSE;
} 

LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam){
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rt;
    static int op = 0;
    static int x1 = 200, y1 = 200;
    static BOOL band = FALSE;

    GetClientRect(hWnd, &rt);
    switch(messg){
        case WM_PAINT:
            if(band){
                hdc = BeginPaint(hWnd, &ps);   
            
                switch(op){
                    case 1:
                        Rectangle(hdc, x1, y1, x1+200, y1+200);
                    break;
                    case 2:
                        Ellipse(hdc, x1, y1, x1+200, y1+200);
                    break;
                    case 3:
                        RoundRect(hdc, x1, y1, x1+200, y1+200, 20, 20);
                    break;
                 
                        
                }
                EndPaint(hWnd, &ps);
            }
            band = FALSE;
        break;
        case WM_LBUTTONDOWN:            
            x1 = LOWORD(lParam);
            y1 = HIWORD(lParam);
            band = TRUE;
            InvalidateRect(hWnd, &rt, FALSE);
        break;
        case WM_COMMAND:
            switch(LOWORD(wParam)){
                case IDM_RECTANGLE:
                    op = 1;
                break;
                case IDM_ELLIPSE:
                    op = 2;
                break;
                case IDM_ROUNDRECT:
                    op = 3;
                break;
                case IDM_LINE:
                    op = 4;
                break;
                case IDM_SAVE:
                     DialogBox(hInstance, "MiDialog", hWnd, (DLGPROC)About);
                break;
            }
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return(DefWindowProc(hWnd, messg, wParam, lParam));
    }
    return(0);
}