/*
Nombre: Oscar Armaando González Patiño
Fecha: 13 de junio de 2017
Proyecto: Mensajes Mouse
Funcionalidad: Ejecucion de los eventos mensajes del mouse
Métodos: MessageBox, 
Handles:
Mensajes:WM_LBUTTONDOWN, WM_RBUTTONDOWN, WM_MBUTTONDOWN
Tipos:
Estructuras:
*/


#include <windows.h>
//#include <tchar.h>

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

    hWnd = CreateWindow(szProgName, "Programa mensajes del Mouse", 
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

    GetClientRect(hWnd, &rt);
    switch(messg){
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        break;
    case WM_LBUTTONDOWN:
        MessageBox(hWnd, "Boton izquierdo abajo", "Mensajes del Mouse", MB_OK);
        break;
    case WM_RBUTTONDOWN:
        MessageBox(hWnd, "Boton derecho abajo", "Mensajes del mouse", MB_OK);
        break;
    case WM_MBUTTONDOWN:
        MessageBox(hWnd, "Boton medio abajo", "Mensajes del mouse", MB_OK);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return(DefWindowProc(hWnd, messg, wParam, lParam));
    }
    return(0);
}