/*
Nombre: Oscar Armaando González Patiño
Fecha: 25 AGOSTO DE 2017
Proyecto: Editor de figuras
Funcionalidad: Dibuja formas con diferente tamaño, tamaño de pincel, de relleno y distintos colores
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
int figura = 0;
int penStyle = 0;
int penWidth = 1;
int brushStyle = 1;
COLORREF penColor = RGB(0, 0, 0);
COLORREF backgroundColor = RGB(255, 255, 255);
COLORREF brushColor = RGB(255, 255, 255);

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_EDITOR_FIGURAS_TIPICO, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if(!InitInstance(hInstance, nCmdShow)){
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_EDITOR_FIGURAS_TIPICO);

	// Main message loop:
	while(GetMessage(&msg, NULL, 0, 0)){
		if(!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)){
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

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = (WNDPROC)WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_EDITOR_FIGURAS_TIPICO);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName = (LPCSTR)IDC_EDITOR_FIGURAS_TIPICO;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

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
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow){
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd){
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

//lresult es lo que regresa, callback es como se guarda en la memoria
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);
    RECT rt;
	static int x, y, x2, y2;
    static BOOL band = FALSE;
    static BOOL finalBand = FALSE;
    static BOOL solido = FALSE;

    HPEN penNew, penOld;
    HBRUSH brushNew, brushOld;

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
                case IDM_RECTANGLE:
                    figura = 1;
                    break;
                case IDM_ELLIPSE:
                    figura = 2;
                    break;
                case IDM_ROUNDRECT:
                    figura = 3;
                    break;
                case IDM_LINE:
                    figura = 4;
                    break;
                case IDM_FREEHAND:
                    figura = 5;
                    break;

                //colores pluma
                case IDM_RED_P:
                    penColor = RGB(200, 0, 0);
                    break;
                case IDM_GREEN_P:
                    penColor = RGB(0, 200, 0);
                    break;
                case IDM_BLUE_P:
                    penColor = RGB(0, 0, 200);
                    break;
                case IDM_BLACK_P:
                    penColor = RGB(0, 0, 0);
                    break;

                //colores brocha
                case IDM_RED_B:
                    brushColor = RGB(200, 0, 0);
                    break;
                case IDM_GREEN_B:
                    brushColor = RGB(0, 200, 0);
                    break;
                case IDM_BLUE_B:
                    brushColor = RGB(0, 0, 200);
                    break;
                case IDM_BLACK_B:
                    brushColor = RGB(0, 0, 0);
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

                //pen style
                case IDM_PS_SOLID:
                    penStyle = PS_SOLID;
                    break;
                case IDM_PEN_DASH:
                    penStyle = PS_DASH;
                    break;
                case IDM_PS_DOT:
                    penStyle = PS_DOT;
                    break;
                case IDM_PS_DASHDOT:
                    penStyle = PS_DASHDOT;
                    break;
                case IDM_PS_DASHDOTDOT:
                    penStyle = PS_DASHDOTDOT;
                    break;

                //brusHh
                case IDM_HS_BDIAGONAL:
                    brushStyle = 1;
                    break;
                case IDM_HS_CROSS:
                    brushStyle = 2;
                    break;
                case IDM_HS_DIAGCROSS:
                    brushStyle = 3;
                    break;
                case IDM_HS_FDIAGONAL:
                    brushStyle = 4;
                    break;
                case IDM_HS_HORIZONTAL:
                    brushStyle = 5;
                    break;
                case IDM_HS_VERTICAL:
                    brushStyle = 0;
                    break;
                case IDM_SOLID:
                    solido = !solido;
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
                SetROP2(hdc, R2_NOTXORPEN);
                penNew = CreatePen(penStyle , penWidth, penColor);
                if(solido){
                    brushNew = CreateSolidBrush(brushColor);
                }
                else{
                    brushNew = CreateHatchBrush(brushStyle, brushColor);
                }
                penOld = (HPEN)SelectObject(hdc, penNew);
                brushOld = (HBRUSH)SelectObject(hdc, brushNew);
                
                switch(figura){
                    case 1:
                        Rectangle(hdc, x, y, x2, y2);
                        break;
                    case 2:
                        Ellipse(hdc, x, y, x2, y2);
                        break;
                    case 3:
                        RoundRect(hdc, x, y, x2, y2, 20, 20); 
                        break;
                    case 4:
                        MoveToEx(hdc, x, y, NULL);
                        LineTo(hdc, x2, y2);
                        break;
                    case 5:
                        MoveToEx(hdc, x, y, NULL);
                        LineTo(hdc, x2, y2);
                        x = x2;
                        y = y2;
                        break;
                }
                SelectObject(hdc, penOld);  
                SelectObject(hdc, brushOld);
                Sleep(10);

                //borrar
                penNew = CreatePen(penStyle , penWidth, penColor);
            
                if(solido){
                    brushNew = CreateSolidBrush(brushColor);
                }
                else{
                    brushNew = CreateHatchBrush(brushStyle, brushColor);
                }
                penOld = (HPEN)SelectObject(hdc, penNew);
                brushOld = (HBRUSH)SelectObject(hdc, brushNew);

                switch(figura){
                    case 1:
                        Rectangle(hdc, x, y, x2, y2);
                        break;
                    case 2:
                        Ellipse(hdc, x, y, x2, y2);
                        break;
                    case 3:
                        RoundRect(hdc, x, y, x2, y2, 20, 20); 
                        break;
                    case 4:
                        MoveToEx(hdc, x, y, NULL);
                        LineTo(hdc, x2, y2);
                        break;
                                                                                                                                                                                                                                                                                                                     
                }

            }
            else{
                if(finalBand && MK_LBUTTON){
                    penNew = CreatePen(penStyle , penWidth, penColor);
                  
                    if(solido){
                        brushNew = CreateSolidBrush(brushColor);
                    }
                    else{
                        brushNew = CreateHatchBrush(brushStyle, brushColor);
                    }
                    penOld = (HPEN)SelectObject(hdc, penNew);
                    brushOld = (HBRUSH)SelectObject(hdc, brushNew);

                    switch(figura){
                        case 1:
                            Rectangle(hdc, x, y, x2, y2);
                            break;
                        case 2:
                            Ellipse(hdc, x, y, x2, y2);
                            break;
                        case 3:
                            RoundRect(hdc, x, y, x2, y2, 20, 20); 
                            break;
                        case 4:
                            MoveToEx(hdc, x, y, NULL);
                            LineTo(hdc, x2, y2);
                            break;
                        
                    }
                }
                finalBand = FALSE;
                SelectObject(hdc, penOld); 
                SelectObject(hdc, brushOld);
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
            finalBand = TRUE;
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
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	switch (message){
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL){
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}
