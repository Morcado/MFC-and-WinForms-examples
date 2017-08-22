/*
Nombre: Oscar Armaando González Patiño
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

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow){
    HWND hWnd;
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
    while(GetMessage(&lpMsg, 0, 0, 0)){
        TranslateMessage(&lpMsg);
        DispatchMessage(&lpMsg);
    }

    return(lpMsg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam){
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rt;
    int wID, i;

    GetClientRect(hWnd, &rt);

    switch(messg){
        case WM_COMMAND:
            wID = LOWORD(wParam);
            switch(wID){
                case IDM_RECTANGLE:
                    i = 0;
                    break; 
                case IDM_ELLIPSE:
                    i = 1;
                    break;
                case IDM_ROUNDRECT:
                    i = 2;
                    break;
                case IDM_LINE:
                    i = 3;
                    break;
                case IDM_FREEHAND:
                    i = 4;
                    break;
            }
            break;
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);

            EndPaint(hWnd, &ps);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return(DefWindowProc(hWnd, messg, wParam, lParam));
    }
    return(0);
}