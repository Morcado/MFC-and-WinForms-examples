/*  Nombre: Oscar Armando González Patiño
    Fecha: 14 de septiembre de 2017   */

#include "stdafx.h"
#include "resource.h"
#include "Combo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
TCHAR szTitle[MAX_LOADSTRING];                              // The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];                                // The title bar text

NP *lista;

int x = 100, y = 100;
BOOL band, dband = FALSE;
char cad[10];

// Foward declarations of functions included in this code module:
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK Combo(HWND, UINT, WPARAM, LPARAM);
NP *creaNodoNP(int n);
NR *creaNodoNR(int n);
BOOL Busca_Dec(int d);

void iniciaLista();
void creaLista(NP *n);
void inserta_OrdenadoNP(NP *np);
BOOL inserta_OrdenadoNR(NP *np, NR *nr);
void imprimeLista(HDC hdc);
//void Inserta_OrdenadoNR(NP *np, NR *nr);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    // TODO: Place code here.
    MSG msg;
    HACCEL hAccelTable;

    // Initialize global strings
    LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadString(hInstance, IDC_COMBO, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow)) 
    {
        return FALSE;
    }

    hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_COMBO);

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


ATOM MyRegisterClass(HINSTANCE hInstance){
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX); 

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = (WNDPROC)WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_COMBO);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName = (LPCSTR)IDC_COMBO;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

    return RegisterClassEx(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow){
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

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

    int wmId, wmEvent;
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR szHello[MAX_LOADSTRING];
    LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);

    RECT rt, rtMarco;

    int numeros, i, n, d;
    NR *nr;
    NP *corre, *nodo;
    GetClientRect(hWnd, &rt);

    switch (message){
        case WM_CREATE:
            GetWindowRect(hWnd, &rtMarco);
            break;
        case WM_COMMAND:
            wmId    = LOWORD(wParam);
            wmEvent = HIWORD(wParam); 
            // Parse the menu selections:
            switch (wmId)
            {
                case IDM_ABOUT:
                   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
                   break;
                case IDM_LL:
                    srand((unsigned)time(NULL));
                    iniciaLista();
                    numeros = rand()%35 + rand()%5 + rand()%5;
                        for(i = 0; i < numeros; i ++){
                            n = rand()%100;
                            d = n/10*10;
                            if(Busca_Dec(d) == FALSE){
                                nodo = creaNodoNP(d);
                                inserta_OrdenadoNP(nodo); 
                            }
                            
                            nodo = lista;
                            while(nodo && nodo->dec < d){
                                nodo = nodo->sig;
                            }
                            
                            if(n != d){
                                nr = creaNodoNR(n);
                                inserta_OrdenadoNR(nodo, nr);
                            }
                            //nodo = creaNodoNP(d);
                            //inserta_OrdenadoNP(nodo);
                            //creaLista(nodo);
                            //insertaFinal(nodo);   
                        }
                        
                    break;
                case IDM_IMPRIMIR:
                    band = TRUE;
                    InvalidateRect(hWnd, &rt, FALSE);
                    break;
                case IDM_COMBO:
                    DialogBox(hInst, (LPCTSTR)IDD_COMBO, hWnd, (DLGPROC)Combo);
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
            corre = lista;
            if(band){
                imprimeLista(hdc);
               
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

    switch (message){
        case WM_INITDIALOG:
                return TRUE;

        case WM_COMMAND:
            if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
                EndDialog(hDlg, LOWORD(wParam));
                return TRUE;
            }
            break;
    }
    return FALSE;
}

LRESULT CALLBACK Combo(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){

    char cad[4] = "100";
    static HWND hCombo;
    NP *corre;

    switch (message){
        case WM_INITDIALOG:
            hCombo = GetDlgItem(hDlg, IDC_COMBO1);
            break;
        case WM_COMMAND:
            switch(LOWORD(wParam)){
                case IDC_ACCION:
                    corre = lista;
                    while(corre){
                        //itoa(corre->num, cad, 10);
                        SendMessage(hCombo, CB_INSERTSTRING, -1, (LPARAM)(LPCTSTR)cad);
                        //SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)cad);
                        corre = corre->sig;
                    }
                    

                    //SetDlgItemText(hDlg, IDC_COMBO1, "100");
                    //SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)"100");
                    //SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)"100");
                    //SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)"120");
                    SendDlgItemMessage(hDlg, IDC_COMBO1, CB_SETCURSEL, 0, 0);
                break;
                
                case IDOK:
                case IDCANCEL:
                    EndDialog(hDlg, LOWORD(wParam));
                    return TRUE;
                    break;
            }
            break;
    }
    return FALSE;
}

void iniciaLista(){
    lista = NULL;
}

NP *creaNodoNP(int n){
    NP *nodo = new NP;
    nodo->dec = n;
    nodo->sig = NULL;
    nodo->abajo = NULL;
    return nodo;
}

NR *creaNodoNR(int n){
    NR *nodo = new NR;
    nodo->num = n;
    nodo->sig = NULL;
    return nodo;
}

BOOL Busca_Dec(int d){
    NP *c1 = lista;
    while(c1){
        if(c1->dec != d){
            c1 = c1->sig;
        }
        else{
            return TRUE;
        }
    }
    return FALSE;
}

void inserta_OrdenadoNP(NP *np){    
    NP *corre;

    if(!lista || lista->dec > np->dec){
        np->sig = lista;
        lista = np;
    }
    else{
        corre = lista;
        if(corre && corre->dec < np->dec){
            while(corre->sig){
                if(corre->sig->dec > np->dec){
                   break;
                }
                corre = corre->sig;
            }
        }
        if(!(corre->sig)){
            np->sig = corre->sig;
            corre->sig = np;
        }
        else{
                np->sig = corre->sig;
                corre->sig = np;
        }
    }
}

// np= nodo abajo para insertar el nuevo(nr) en la LiLi
BOOL inserta_OrdenadoNR(NP *np, NR *nr){
    NR *c2;

    if(!np->abajo || np->abajo->num > nr->num){
        nr->sig = np->abajo;
        np->abajo = nr;
    }
    else{
        c2 = np->abajo;
        if(c2->num < nr->num){
            while(c2->sig){
                if(c2->sig->num > nr->num){
                   break;
                }
                c2 = c2->sig;
            }
        }
        if(c2->num == nr->num){
            return FALSE;
        }
        if(!(c2->sig)){
            nr->sig = c2->sig;
            c2->sig = nr;
        }
        else{
            nr->sig = c2->sig;
            c2->sig = nr;
        }
    }
    return TRUE;
}

void imprimeLista(HDC hdc){
    NP *corre = lista;
    NR *corre2;
    int x = 100, y = 100;
    char cad[3];
    int tam;

    while(corre){
        itoa(corre->dec, cad, 10);
        tam = strlen(cad);
        TextOut(hdc, x, y, cad, tam);
        corre2 = corre->abajo;

        while(corre2){
            itoa(corre2->num, cad, 10);
            tam = strlen(cad);
            TextOut(hdc, x += 25, y, cad, tam);
            corre2 = corre2->sig;
        }
        y += 20;
        x = 100;
        corre = corre->sig;
    }
}