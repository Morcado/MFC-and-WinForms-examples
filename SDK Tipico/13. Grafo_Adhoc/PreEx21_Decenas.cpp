/*  Nombre: Oscar Armando González Patiño
    Fecha: 14 de septiembre de 2017   */

#include "stdafx.h"
#include "resource.h"
#include "PreEx21_Decenas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
TCHAR szTitle[MAX_LOADSTRING];                              // The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];                                // The title bar text

NP *grafo;

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
void insertaColaNP(NP *aux2, NP *np);
void insertaColaNR(NR *aux3, NR *np);
void imprimeGrafo(HDC hdc);
//void inserta_OrdenadoNP(NP *np);
//BOOL inserta_OrdenadoNR(NP *np, NR *nr);
//void imprimeLista(HDC hdc);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    // TODO: Place code here.
    MSG msg;
    HACCEL hAccelTable;

    // Initialize global strings
    LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadString(hInstance, IDC_PREEX21_DECENAS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow)) 
    {
        return FALSE;
    }

    hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_PREEX21_DECENAS);

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
    wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_PREEX21_DECENAS);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName = (LPCSTR)IDC_PREEX21_DECENAS;
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

    static char name = 'A';
    //int numeros, i;
    NR *nr, *aux3;
    NP *aux, *aux2, *np;
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
                    iniciaLista();
       
                    np = creaNodoNP(name);
                    aux = aux2 = np;
                    nr = creaNodoNR(5);
                    np->abajo = nr;
                    nr->arriba = np;
                    insertaColaNP(aux2, np);
                    //creea B y ligarlo a a
                    name++;
                    aux3 = nr;
                    np = creaNodoNP(name);
                    nr = creaNodoNR(10);
                    nr->arriba = np;
                    insertaColaNR(aux3, nr);
                    aux2->sig = np;
                    aux2 = np;
                    //creea C y ligarlo a A
                    name++;
                    aux3 = nr;
                    np = creaNodoNP(name);
                    nr = creaNodoNR(20);
                    nr->arriba = np;
                    insertaColaNR(aux3, nr);
                    aux2->sig = np;
                    aux2 = np;
                    //relaciones de B: regresa aux2(A) y avanza aux (B);
                    aux2 = grafo;
                    aux = aux->sig;
                    nr = creaNodoNR(30);
                    aux2 = aux2->sig; //avanvza aux2 a B
                    aux2 = aux2->sig;
                    nr->arriba = aux2; //nodo C
                    aux->abajo = nr; //la primer relacion de B
                     //relaciones de C: regresa aux(C) y avanza aux2 (B);
                    aux2 = grafo;
                    aux = aux->sig;
                    nr = creaNodoNR(40);
                    aux2 = aux2->sig;//a (B)
                    nr->arriba = aux2; //nodo C
                    aux->abajo = nr; //la primer relación de C
                    band = true;
                    InvalidateRect(hWnd, &rt, TRUE);
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
            if(band){
                imprimeGrafo(hdc);
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
    
    RECT rtDlg, rtMarco;//, rtTamCliente;
    static HWND hCombo;
    NP *aux;
    NR *aux2;
    
    static BOOL bband = FALSE;
    //int tamDlg;
    int tamCombo;// = 60, espCombo, i, posCombo;// idCombo;

    switch (message){
        case WM_INITDIALOG:
            
            break;
        case WM_COMMAND:
            switch(LOWORD(wParam)){
                case IDC_ACCION:
                    if(bband){
                        GetWindowRect(hDlg, &rtMarco);
                        SetWindowPos(hDlg, HWND_TOP, rtMarco.left, rtMarco.top, 25*(numCombos+1)+tamCombo*numCombos, rtMarco.bottom-rtMarco.top, SWP_NOZORDER);
                        aux = grafo;
                        while(aux){
                            itoa(aux->nombre, cad, 10);
                            //idCombo = GetDlgCtrlID(aux->hCombo);
                            //SetDlgItemText(hDlg, aux->dlgItem, cad); //para la decena en el edit del combo
                        
                            aux2 = aux->abajo;
                            while(aux2){
                                itoa(aux2->num, cad, 10);
                                //SendMessage(aux->hCombo, CB_INSERTSTRING, 0, (LPARAM)(LPCTSTR)cad); //para el numero que va en la decena
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
    grafo = NULL;
}

NP *creaNodoNP(int n){
    NP *np = new NP;

    np->nombre = n;
    np->sig = NULL;
    np->abajo = NULL;

    return np;
}

NR *creaNodoNR(int n){
    NR *nr = new NR;
    nr->num = n;
    nr->sig = NULL;
    nr->arriba = NULL;

    return nr;
}

BOOL Busca_Dec(int d){
    NP *c1 = grafo;
    while(c1){
        if(c1->nombre != d){
            c1 = c1->sig;
        }
        else{
            return TRUE;
        }
    }
    return FALSE;
}

void insertaColaNP(NP *aux2, NP *np){
    if(!grafo){
        grafo = np;
    }
    else{
        aux2->sig = np;
    }
}

void insertaColaNR(NR *aux3, NR *nr){
    aux3->sig = nr;
}

void imprimeGrafo(HDC hdc){
    NP *aux1, *aux2;
    NR *aux3 = NULL;
    aux1 = aux2 = grafo;
    int x = 100, y = 100;
    char cad[10] = {'\0'}, cad1[10] = {'\0'};
    int tam1 = 9, tam2 = 0;
    while(aux2){
        cad[1] = '\0';
        cad1[1] = '\0';
        //itoa((char[])aux2->nombre, cad, 10);
        cad[0] = aux2->nombre;
        strcat(cad, ": ");
        tam1 = strlen(cad);
        TextOut(hdc, x, y, cad, tam1);
        x = x + tam1*3;
        aux3 = aux2->abajo;
        while(aux3){
            itoa(aux3->num, cad, 10);
            strcat(cad, "_");
            //itoa(aux3->arriba->nombre, cad1, 10);
            cad1[0] = aux3->arriba->nombre;
            strcat(cad, cad1);
            strcat(cad, "->");
            tam2 = strlen(cad);
            TextOut(hdc, x += tam2*3, y, cad, tam2);
            x += tam2*5;
            aux3 = aux3->sig;
        }
        TextOut(hdc, x += tam2*3, y, cad, tam2);
        TextOut(hdc, x, y, "NULL", tam2);
        aux2 = aux2->sig;
        y += 20;
        x = 100;


    }
}

