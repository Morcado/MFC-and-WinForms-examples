/*
Nombre: Oscar Armaando González Patiño
Fecha: 5 de junio de 2017
Proyecto: Coordenadas mouse
Funcionalidad: Imprime las coordenadas donde se da click con el mouse
Métodos: itoa, strcpy, strcat, InvalidateRect, SetTextColor
Handles:
Mensajes:
Tipos: WM_LBUTTONDOWN, LOWORD, HIWORD
Estructuras:
*/

#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInstance;
char szProgName[] = "Programa";
char szProgMenu[] = "Menu";
BOOL band = FALSE;
int xPos = 100, yPos = 100;

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
    char c[5];
    char cad[50];

    GetClientRect(hWnd, &rt);
    switch(messg)
    {
        case WM_PAINT: 
            if(band)
            {
                hdc = BeginPaint(hWnd, &ps);
                SetTextColor(hdc, RGB(0, 0, 0));

                itoa(xPos, c, 10);
                strcpy(cad, "X = ");
                strcat(cad, c);

                itoa(yPos, c, 10);
                strcat(cad, ", Y = ");
                strcat(cad, c);

                TextOut(hdc, xPos, yPos, cad, strlen(cad));  
                band = FALSE;

                EndPaint(hWnd, &ps);
            }        
        break;
        case WM_LBUTTONDOWN:
            xPos = LOWORD(lParam);
            yPos = HIWORD(lParam);
            band = TRUE;
            InvalidateRect(hWnd, &rt, TRUE);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return(DefWindowProc(hWnd, messg, wParam, lParam));
    }
    return(0);
}