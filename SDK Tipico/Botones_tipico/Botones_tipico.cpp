// Botones_tipico.cpp : Defines the entry point for the application.
/*
    Fecha: 4 de septiembre de 2017
    Nombre: OSCAR ARMANDO GONZÁLEZ PATIÑO
    Funcionalidad: Manipulacion de los controles de los botones
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

// Foward declarations of functions included in this code module:
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK Botones(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_BOTONES_TIPICO, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_BOTONES_TIPICO);

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

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_BOTONES_TIPICO);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_BOTONES_TIPICO;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

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


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);
	RECT rt;
	GetClientRect(hWnd, &rt);
	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				   break;
				case IDM_EXIT:
				   DestroyWindow(hWnd);
				   break;
                case IDM_BOTONES:
                    DialogBox(hInst, (LPCTSTR)IDD_BOTONES, hWnd, (DLGPROC)Botones);
                    break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			// TODO: Add any drawing code here...
		

			EndPaint(hWnd, &ps);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}


LRESULT CALLBACK Botones(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
    static int x = 123, y = 31, ancho = 50, alto= 50;
    static HWND hNuevo = CreateWindow("BUTTON", "Nuevo", WS_CHILD, 123, 31, 50, 50, hDlg, (HMENU)IDC_NUEVO, hInst, NULL);;
	switch (message){
		case WM_INITDIALOG:
			return TRUE;
            break;
		case WM_COMMAND:
            switch(LOWORD(wParam)){
                case IDC_BUILD:
                    SetWindowPos(GetDlgItem(hDlg, IDC_NUEVO), HWND_NOTOPMOST, 123, 31, 50, 50, SWP_NOZORDER);
                    ShowWindow(GetDlgItem(hDlg, IDC_NUEVO), SW_SHOWNORMAL);
                    ShowWindow(GetDlgItem(hDlg, IDC_HIDE), SW_SHOWNORMAL);
                    ShowWindow(GetDlgItem(hDlg, IDC_MOVE), SW_SHOWNORMAL);
                    ShowWindow(GetDlgItem(hDlg, IDC_RESIZE), SW_SHOWNORMAL);
                    ShowWindow(GetDlgItem(hDlg, IDC_PUSH), SW_SHOWNORMAL);
                    //ShowWindow(GetDlgItem(hDlg, IDC_REBUILD), SW_SHOWNORMAL);
                    ShowWindow(GetDlgItem(hDlg, IDC_BUILD), SW_HIDE);
                break;
                case IDC_HIDE:
                    EnableWindow(GetDlgItem(hDlg, IDC_HIDE), FALSE);
                    ShowWindow(GetDlgItem(hDlg, IDC_NUEVO), SW_HIDE);
                    ShowWindow(GetDlgItem(hDlg, IDC_REBUILD), SW_SHOWNORMAL);
                    break;
                case IDC_REBUILD:
                    EnableWindow(GetDlgItem(hDlg, IDC_HIDE), TRUE);
                    EnableWindow(GetDlgItem(hDlg, IDC_MOVE), TRUE);
                    EnableWindow(GetDlgItem(hDlg, IDC_RESIZE), TRUE);
                    EnableWindow(GetDlgItem(hDlg, IDC_PUSH), TRUE);
                    SendMessage(hNuevo, BM_SETSTATE, 0, 0);
                    SetWindowPos(GetDlgItem(hDlg, IDC_NUEVO), HWND_NOTOPMOST, 123, 31, 50, 50, SWP_NOZORDER);
                    ShowWindow(GetDlgItem(hDlg, IDC_NUEVO), SW_SHOWNORMAL);
                    break;
                
                case IDC_RESIZE:
                    EnableWindow(GetDlgItem(hDlg, IDC_RESIZE), FALSE);
                    //MoveWindow(GetDlgItem(hDlg, IDC_NUEVO), 78, 20, 66, 63, TRUE);
                    SetWindowPos(GetDlgItem(hDlg, IDC_NUEVO), HWND_TOP, 123, 31, 90, 90, SWP_NOZORDER);
                    ShowWindow(GetDlgItem(hDlg, IDC_REBUILD), SW_SHOWNORMAL);
                    break;
                case IDC_MOVE:
                    EnableWindow(GetDlgItem(hDlg, IDC_MOVE), FALSE);
                    ShowWindow(GetDlgItem(hDlg, IDC_REBUILD), SW_SHOWNORMAL);
                    SetWindowPos(GetDlgItem(hDlg, IDC_NUEVO), HWND_TOP, 50, 50, 50, 50, SWP_NOZORDER);
                    break;
                case IDC_PUSH:
                    SendMessage(hNuevo, BM_SETSTATE, 1, 0);
                    EnableWindow(GetDlgItem(hDlg, IDC_PUSH), FALSE);
                    ShowWindow(GetDlgItem(hDlg, IDC_REBUILD), SW_SHOWNORMAL);
                    
                    break;
                    //MoveWindow(GetDlgItem(hDlg, IDC_NUEVO), 78, 20, 26, 23, TRUE);
                    
                    break;
                
                case IDOK:
                case IDCANCEL:
                    EndDialog(hDlg, LOWORD(wParam));
                    return TRUE;
                    break;
            }
	}
    return FALSE;
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
