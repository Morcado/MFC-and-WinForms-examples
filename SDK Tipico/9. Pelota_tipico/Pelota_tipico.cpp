/*
    Fecha:8 de septiembre de 2017
    Nombre: OSCAR ARMANDO GONZÁLEZ PATIÑO
    Funcionalidad: Pelotas que rebotan :v
    Métodos: 
    Handles:
    Mensajes:
    Tipos:
    Estructuras:

*/

#include "stdafx.h"
#include "resource.h"

//Constantes simbolicas y macros
#define MAX_LOADSTRING 100
#define IDT_TIMER 1

// Global Variables:
HINSTANCE hInst;                                // current instance
TCHAR szTitle[MAX_LOADSTRING];                              // The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];                                // The title bar text

// Foward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
BOOL band = FALSE;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    
    MSG msg;
    HACCEL hAccelTable;

    // Initialize global strings
    LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadString(hInstance, IDC_PELOTA_TIPICO, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow)) 
    {
        return FALSE;
    }

    hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_PELOTA_TIPICO);

    // Main message loop:
    while (GetMessage(&msg, NULL, 0, 0)) 
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX); 

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = (WNDPROC)WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, (LPCTSTR)IDI_PELOTA_TIPICO);
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = (LPCSTR)IDC_PELOTA_TIPICO;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

    return RegisterClassEx(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, 400, 400, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int wmId, wmEvent;
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR szHello[MAX_LOADSTRING];
    LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);
    RECT rt;
    static int x = 100, y = 100;
    static int dir = 0;
    static int paso = 1;
    GetClientRect(hWnd, &rt);

    switch (message) 
    {
        case WM_CREATE:
            SetTimer(hWnd, IDT_TIMER, 20, (TIMERPROC)NULL); 
            break;
        case WM_COMMAND:
            wmId    = LOWORD(wParam); 
            wmEvent = HIWORD(wParam); 
            // Parse the menu selections:
            switch (wmId){
                case IDM_RUN:
                    band = TRUE;
                    break;
                case IDM_STOP:
                    band = FALSE;
                    
                    break;
                case IDM_ABOUT:
                   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
                   break;
                case IDM_EXIT:
                   DestroyWindow(hWnd);
                   break;
                default:
                   return DefWindowProc(hWnd, message, wParam, lParam);
            }
            break;
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
            if(band){
                Ellipse(hdc, x, y, x + 100, y + 100);
            }
            else{
                Ellipse(hdc, 100, 100, 200, 200);
            }
            EndPaint(hWnd, &ps);
            break;
        case WM_TIMER:
            if(band){
                switch(dir){
                    case 0:
                        if(x + 100 <= rt.right){
                            x += paso;
                        }
                        else{
                            x = rt.right - 100;
                            dir = 3;
                        }
                        if(y >= rt.top){
                            y -= paso;
                        }
                        else{
                            y = rt.top;
                            dir = 1;
                        }
                        break;
                    case 1:
                        if(x + 100 <= rt.right){
                            x += paso;
                        }
                        else{
                            x = rt.right - 100;
                            dir = 2;
                        }
                        if(y + 100 <= rt.bottom){
                            y += paso;
                        }
                        else{
                            y = rt.bottom - 100;
                            dir = 0;
                        }
                        break;
                    case 2:
                        if(x >= rt.left){
                            x -= paso;
                        }
                        else{
                            x = rt.left;
                            dir = 1;
                        }
                        if(y + 100 <= rt.bottom){
                            y += paso;
                        }
                        else{
                            y = rt.bottom - 100;
                            dir = 3;
                        }
                        break;
                    case 3:
                        if(x >= rt.left){
                            x -= paso;
                        }
                        else{
                            x = rt.left;
                            dir = 0;
                        }
                        if(y >= rt.top){
                            y -= paso;
                        }
                        else{
                            y = rt.top;
                            dir = 2;
                        }
                        break;
                }
                InvalidateRect(hWnd, &rt, FALSE);
            }
            break;
        case WM_DESTROY:
            KillTimer(hWnd, IDT_TIMER);
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_INITDIALOG:
                return TRUE;

        case WM_COMMAND:
            if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
            {
                EndDialog(hDlg, LOWORD(wParam));
                return TRUE;
            }
            break;
    }
    return FALSE;
}
