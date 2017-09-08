/*
Nombre: Oscar Armaando González Patiño
Fecha: 1 de septiembre de 2017
Proyecto: Pizarron
Funcionalidad: Funcionamiento del pizzaron con un borrador y distintos colores de tiza.
Métodos: 
Handles:
Mensajes:
Tipos:
Estructuras:
*/

#include "stdafx.h"
#include "resource.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text
COLORREF penColor = RGB(255, 255, 255);
int penWidth = 1;
int penStyle = 1;
HBRUSH fondo = CreateSolidBrush(RGB(0, 150, 0));
// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_PREEX1_TIPICO_PIZZARON, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_PREEX1_TIPICO_PIZZARON);

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



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_PREEX1_TIPICO_PIZZARON);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= fondo;
	wcex.lpszMenuName	= (LPCSTR)IDC_PREEX1_TIPICO_PIZZARON;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);
    RECT rt;
	static int x, y, x2, y2;
    static BOOL band = FALSE;
    static BOOL borrador = FALSE;
    static BOOL rect = FALSE;

    HPEN penNew, penOld;

    GetClientRect(hWnd, &rt);
    switch (message){
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId){
				case IDM_ABOUT:
                    DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				    break;
                case IDM_PEN:
                    borrador = FALSE;
                    penColor = RGB(255, 255, 255);
                    break;
                case IDM_ERASER:
                    borrador = TRUE;
                    penColor = RGB(0, 150, 0);           
                    break;

                //colores
                case IDM_RED_P:
                    penColor = RGB(255, 0, 0);
                    break;
                case IDM_GREEN_P:
                    penColor = RGB(0, 255, 0);
                    break;
                case IDM_BLUE_P:
                    penColor = RGB(0, 0, 255);
                    break;
                case IDM_BLACK_P:
                    penColor = RGB(0, 0, 0);
                    break;
                case IDM_WHITE_P:
                    penColor = RGB(255, 255, 255);
                    break;

                //ancho linea
                case IDM_P1:
                    penWidth = 1;
                    break;
                case IDM_P2:
                    penWidth = 2;
                    break;
                case IDM_P3:
                    penWidth = 3;
                    break;
                case IDM_P4:
                    penWidth = 4;
                    break;
                case IDM_P5:
                    penWidth = 5;
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
                //pintar
                if(borrador){
                    penWidth = 20;
                }
                else
                    penWidth = 2;
                penNew = CreatePen(penStyle , penWidth, penColor);
                penOld = (HPEN)SelectObject(hdc, penNew);
                MoveToEx(hdc, x, y, NULL);
                LineTo(hdc, x2, y2);
                x = x2;
                y = y2;
                
                SelectObject(hdc, penOld);
                //SetROP2(hdc, R2_NOTXORPEN);

                Sleep(15);
                if(borrador){
                    penNew = CreatePen(penStyle , penWidth, penColor);
                    penOld = (HPEN)SelectObject(hdc, penNew);
                }
            }
      
			EndPaint(hWnd, &ps);
			break;
        case WM_LBUTTONDOWN:
            x = LOWORD(lParam);
            y = HIWORD(lParam);
            break;
        case WM_MOUSEMOVE:
            if(MK_LBUTTON & wParam){
                x2 = LOWORD(lParam);
                y2 = HIWORD(lParam);
                band = TRUE;
                InvalidateRect(hWnd, &rt, FALSE);
            }
            break;
        case WM_LBUTTONUP:
            x2 = LOWORD(lParam);
            y2 = HIWORD(lParam);
            band = FALSE;
            
            InvalidateRect(hWnd, &rt, FALSE);
            break;
		case WM_DESTROY:
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
