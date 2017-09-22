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

int x = 100, y = 100, numCombos = 0;
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

    RECT rt;

    int numeros, i, n, d;
    NR *nr;
    NP *aux, *np;
    GetClientRect(hWnd, &rt);

    switch (message){
        case WM_CREATE:          
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
                                np = creaNodoNP(d);
                                inserta_OrdenadoNP(np);
                                numCombos++;
                            }
                            
                            np = lista;
                            while(np && np->dec < d){
                                np = np->sig;
                            }
                            
                            if(n != d){
                                nr = creaNodoNR(n);
                                inserta_OrdenadoNR(np, nr);
                            }
                            //np = creanpNP(d);
                            //inserta_OrdenadoNP(np);
                            //creaLista(np);
                            //insertaFinal(np);   
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
            aux = lista;
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
    
    RECT rtDlg, rtMarco, rtTamCliente;
    static HWND hCombo;
    NP *aux;
    NR *aux2;
    
    static BOOL bband = FALSE;
    int tamDlg;
    int tamCombo = 60, espCombo, i, posCombo;// idCombo;

    switch (message){
        case WM_INITDIALOG:
            //hCombo = GetDlgItem(hDlg, IDC_COMBO1);
            GetClientRect(hDlg, &rtDlg);
            GetWindowRect(hDlg, &rtMarco);
            tamDlg = rtDlg.right + 6;//(rtMarco.right - rtMarco.left) - 6;
            espCombo = (tamDlg - (tamCombo*numCombos))/(numCombos + 1);
            aux = lista;
            
            for(i = 0; i < numCombos; i ++){
                posCombo = espCombo*i + tamCombo*i + espCombo;
                aux->dlgItem = i + 2000;
                hCombo = CreateWindow("COMBOBOX", 0, CBS_SIMPLE|WS_CHILD|WS_VISIBLE|WS_VSCROLL, posCombo, 10, tamCombo, 160, hDlg, (HMENU)aux->dlgItem, hInst, NULL);
                aux->hCombo = hCombo;
                
                aux = aux->sig;
            }
            bband = TRUE;
            break;
        case WM_COMMAND:
            switch(LOWORD(wParam)){
                case IDC_ACCION:
                    if(bband){
                        aux = lista;
                        while(aux){
                            itoa(aux->dec, cad, 10);
                            //idCombo = GetDlgCtrlID(aux->hCombo);
                            SetDlgItemText(hDlg, aux->dlgItem, cad); //para la decena en el edit del combo
                        
                            aux2 = aux->abajo;
                            while(aux2){
                                itoa(aux2->num, cad, 10);
                                SendMessage(aux->hCombo, CB_INSERTSTRING, 0, (LPARAM)(LPCTSTR)cad); //para el numero que va en la decena
                                aux2 = aux2->sig;
                            }
                            //SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)cad);
                            aux = aux->sig;
                        }
                    
                        //SetDlgItemText(hDlg, IDC_COMBO1, "100");
                        //SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)"100");
                        SendDlgItemMessage(hDlg, IDC_NUEVO, CB_SETCURSEL, 0, 0);
                        bband = FALSE;
                    }
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
    NP *np = new NP;
    np->dec = n;
    np->sig = NULL;
    np->abajo = NULL;
    return np;
}

NR *creaNodoNR(int n){
    NR *nr = new NR;
    nr->num = n;
    nr->sig = NULL;
    return nr;
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
    NP *aux;

    if(!lista || lista->dec > np->dec){
        np->sig = lista;
        lista = np;
    }
    else{
        aux = lista;
        if(aux && aux->dec < np->dec){
            while(aux->sig){
                if(aux->sig->dec > np->dec){
                   break;
                }
                aux = aux->sig;
            }
        }
        if(!(aux->sig)){
            np->sig = aux->sig;
            aux->sig = np;
        }
        else{
                np->sig = aux->sig;
                aux->sig = np;
        }
    }
}

// np= nodo abajo para insertar el nuevo(nr) en la LiLi
BOOL inserta_OrdenadoNR(NP *np, NR *nr){
    NR *aux;

    if(!np->abajo || np->abajo->num > nr->num){
        nr->sig = np->abajo;
        np->abajo = nr;
    }
    else{
        aux = np->abajo;
        if(aux->num < nr->num){
            while(aux->sig){
                if(aux->sig->num > nr->num){
                   break;
                }
                aux = aux->sig;
            }
        }
        if(aux->num == nr->num){
            return FALSE;
        }
        if(!(aux->sig)){
            nr->sig = aux->sig;
            aux->sig = nr;
        }
        else{
            nr->sig = aux->sig;
            aux->sig = nr;
        }
    }
    return TRUE;
}

void imprimeLista(HDC hdc){
    NP *aux = lista;
    NR *aux2;
    int x = 100, y = 100;
    char cad[3];
    int tam;

    while(aux){
        itoa(aux->dec, cad, 10);
        tam = strlen(cad);
        TextOut(hdc, x, y, cad, tam);
        aux2 = aux->abajo;

        while(aux2){
            itoa(aux2->num, cad, 10);
            tam = strlen(cad);
            TextOut(hdc, x += 25, y, cad, tam);
            aux2 = aux2->sig;
        }
        y += 20;
        x = 100;
        aux = aux->sig;
    }
}