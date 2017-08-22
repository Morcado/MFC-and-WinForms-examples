/*
Nombre: Oscar Armando González Patiño
Fecha: 13 de junio de 2017
Proyecto: Editor de figuras usando el proyecto tipico
Funcionalidad: implementacion de figuras edicion con color
Métodos: Sleep, 
Handles: 
Mensajes:
Tipos: 
Estructuras: 
*/

#include "stdafx.h"
#include "resource.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;    // current instance
TCHAR szTitle[MAX_LOADSTRING];  // The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];    // The title bar text
//int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
 
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_EDITOR, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if(!InitInstance(hInstance, nCmdShow)){
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_EDITOR);

	// Main message loop:
	while(GetMessage(&msg, NULL, 0, 0)) {
		if(!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}
/*
  FUNCTION: MyRegisterClass()

  PURPOSE: Registers the window class.

  COMMENTS:

    This function and its usage is only necessary if you want this code
    to be compatible with Win32 systems prior to the 'RegisterClassEx'
    function that was added to Windows 95. It is important to call this function
    so that the application will get 'well formed' small icons associated
    with it.
*/

ATOM MyRegisterClass(HINSTANCE hInstance){
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_EDITOR);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_EDITOR;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

/*
   FUNCTION: InitInstance(HANDLE, int)

   PURPOSE: Saves instance handle and creates main window

   COMMENTS:

        In this function, we save the instance handle in a global variable and
        create and display the main program window.
*/
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow){
    HWND hWnd;

    hInst = hInstance; // Store instance handle in our global variable

    hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

    if(!hWnd)
        return FALSE;

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

/*
  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)

  PURPOSE:  Processes messages for the main window.

  WM_COMMAND	- process the application menu
  WM_PAINT	- Paint the main window
  WM_DESTROY	- post a quit message and return
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc; 
	TCHAR szHello[MAX_LOADSTRING];
    RECT rt;
    HPEN hPen, hPenOld;

	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);
    GetClientRect(hWnd, &rt);
   
	static int op = 0;
    static int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    static bool band = false;
    static bool bandFinal = FALSE;
    static COLORREF foreColor = RGB(0, 0, 0);
    static COLORREF backColor = RGB(255, 255, 255);

    switch(message){
        case WM_LBUTTONDOWN:
            x1 = LOWORD(lParam);
            y1 = HIWORD(lParam);
        break;
        case WM_LBUTTONUP:
            band = false;
            bandFinal = true;
            InvalidateRect(hWnd, &rt, FALSE);
        break;
        case WM_MOUSEMOVE:
            if(MK_LBUTTON && wParam){
                x2 = LOWORD(lParam);
                y2 = HIWORD(lParam);
                band = TRUE;
                InvalidateRect(hWnd, &rt, FALSE);
            }
        break;
		case WM_COMMAND:
			wmId = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch(wmId){
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
				case IDM_ABOUT:
				    DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				break;
				case IDM_EXIT:
				    DestroyWindow(hWnd);
				break;
                //colores
                case IDM_RED:
                    foreColor = RGB(255, 0, 0);
                break;
                case IDM_GREEN:
                    foreColor = RGB(0, 255, 0);
                break;
                case IDM_BLUE:
                    foreColor = RGB(0, 0, 255);
                break;
				default:
				    return DefWindowProc(hWnd, message, wParam, lParam);
			}
	    break;
		case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
            if(band){  
                SetROP2(hdc, R2_NOTXORPEN);
                hPen = CreatePen(PS_SOLID, 6, foreColor); //creacion del recurso de la pluma
			    hPenOld = (HPEN)SelectObject(hdc, hPen); //selecciona el recurso
                switch(op){ //pinta la figura
                    case 1: 
                        Rectangle(hdc, x1, y1, x2, y2);
                    break;
                    case 2:
                        Ellipse(hdc, x1, y1, x2, y2);
                    break;
                    case 3:
                        RoundRect(hdc, x1, y1, x2, y2, 15, 15);
                    break;
                    case 4:
                        MoveToEx(hdc, x1, y1, NULL);
                        LineTo(hdc, x2, y2);
                    break;
                }
                Sleep(5);
                switch(op){ //borra la figura
                    case 1: 
                        Rectangle(hdc, x1, y1, x2, y2);
                    break;
                    case 2:
                        Ellipse(hdc, x1, y1, x2, y2);
                    break;
                    case 3:
                        RoundRect(hdc, x1, y1, x2, y2, 15, 15);
                    break;
                    case 4:
                        MoveToEx(hdc, x1, y1, NULL);
                        LineTo(hdc, x2, y2);
                    break;
                }
                SelectObject(hdc, hPenOld);
                band = FALSE;                
            }
            else{ //pinta al final
                //InvalidateRect(hWnd, &rt, false);
                if(bandFinal){
                    hPen = CreatePen(PS_SOLID, 6, foreColor); //creacion del recurso de la pluma
			        hPenOld = (HPEN)SelectObject(hdc, hPen); //selecciona el recurso
                    switch(op){ //pinta la figura
                        case 1: 
                            Rectangle(hdc, x1, y1, x2, y2);
                        break;
                        case 2:
                            Ellipse(hdc, x1, y1, x2, y2);
                        break;
                        case 3:
                            RoundRect(hdc, x1, y1, x2, y2, 15, 15);
                        break;
                        case 4:
                            MoveToEx(hdc, x1, y1, NULL);
                            LineTo(hdc, x2, y2);
                        break;
                    }
                    SelectObject(hdc, hPenOld);
                }

            }
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

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
   	switch(message){
  	   	case WM_INITDIALOG:
            return TRUE;

   	   	case WM_COMMAND:
       	   	if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
            }
         	break;
	}
    return TRUE;
}
