/*
Nombre: Oscar Armando González Patiño
Fecha: 22 de agosto de 2017
Proyecto: Editor
Funcionalidad: Editor de figuras
Métodos: 
Handles:
Mensajes:
Tipos:
Estructuras:
*/

#include <windows.h>
#include "Editor_nuevo.h"

HINSTANCE hInstance;
char szProgName[] = "Programa";
char szProgMenu[] = "Menu";
BOOL band=TRUE;    
int i=0;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow){
    HWND hWnd;
    HACCEL hAccel;
    MSG lpMsg;
    WNDCLASS wcApp;

    hInstance = hInst;

    wcApp.lpszClassName = szProgName;
    wcApp.hInstance = hInst;
    wcApp.lpfnWndProc = WndProc; //ejecuta wndproc
    wcApp.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcApp.hIcon = 0;
    wcApp.lpszMenuName = szProgMenu;
    wcApp.hbrBackground = GetStockObject(WHITE_BRUSH);
    wcApp.style = CS_HREDRAW|CS_VREDRAW;
    wcApp.cbClsExtra = 0;
    wcApp.cbWndExtra = 0;

    if(!RegisterClass(&wcApp))
        return(0);

    hWnd = CreateWindow(szProgName, "Programa Cascaron Aplicacion Win32 (SDK)", 
                        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                        CW_USEDEFAULT, (HWND)NULL, (HMENU)NULL, (HANDLE)hInst, (LPSTR)NULL);
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    hAccel = LoadAccelerators(hInst, "MiAccel");
    while(GetMessage(&lpMsg, 0, 0, 0)){
        if(!TranslateAccelerator(hWnd, hAccel, &lpMsg));
        TranslateMessage(&lpMsg);
        DispatchMessage(&lpMsg);
    }

    return(lpMsg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam){
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rt;
    int wID;

    GetClientRect(hWnd, &rt);

    switch(messg){
        case WM_COMMAND:
            wID = LOWORD(wParam);
            switch(wID){
                case IDM_RECTANGLE:
                    i = 1;
                    break; 
                case IDM_ELLIPSE:
                    i = 2;
                    break;
                case IDM_ROUNDRECT:
                    i = 3;
                    break;
                case IDM_LINE:
                    i = 4;
                    break;
                case IDM_FREEHAND:
                    i = 5;
                    break;
            }
            //band = TRUE;
            InvalidateRect(hWnd, &rt, FALSE);
            break;
        case WM_PAINT:
            if(band){
                hdc = BeginPaint(hWnd, &ps);
                switch(i){
                    case 1:
                        Rectangle(hdc, 100, 100, 200, 200);
                        break;
                    case 2:
                        Ellipse(hdc, 100, 100, 200, 200);
                        break;
                    case 3:
                        RoundRect(hdc, 100, 100, 200, 200, 30, 30);
                        break;
                    case 4:
                        MoveToEx(hdc, 100, 100, NULL);
                        LineTo(hdc, 200, 200);
                        break;
                    case 5:
                        //construccion
                        break;
                }
                EndPaint(hWnd, &ps);
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