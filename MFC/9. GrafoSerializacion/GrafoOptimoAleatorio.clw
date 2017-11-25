; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCajaImprime
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GrafoOptimoAleatorio.h"
LastPage=0

ClassCount=6
Class1=CGrafoOptimoAleatorioApp
Class2=CGrafoOptimoAleatorioDoc
Class3=CGrafoOptimoAleatorioView
Class4=CMainFrame

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_IMPRIMIR
Resource4=IDR_TOOLBAR1
Resource5=IDD_ABOUTBOX (Spanish (Modern))
Resource6=IDR_MENU1
Class5=CAboutDlg
Class6=CCajaImprime
Resource7=IDR_MAINFRAME (Spanish (Modern))

[CLS:CGrafoOptimoAleatorioApp]
Type=0
HeaderFile=GrafoOptimoAleatorio.h
ImplementationFile=GrafoOptimoAleatorio.cpp
Filter=N

[CLS:CGrafoOptimoAleatorioDoc]
Type=0
HeaderFile=GrafoOptimoAleatorioDoc.h
ImplementationFile=GrafoOptimoAleatorioDoc.cpp
Filter=N

[CLS:CGrafoOptimoAleatorioView]
Type=0
HeaderFile=GrafoOptimoAleatorioView.h
ImplementationFile=GrafoOptimoAleatorioView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=GrafoOptimoAleatorio.cpp
ImplementationFile=GrafoOptimoAleatorio.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
CommandCount=13
Command4=ID_EDIT_UNDO
Command13=ID_PREV_PANE


[TB:IDR_MAINFRAME (Spanish (Modern))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME (Spanish (Modern))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13

[ACL:IDR_MAINFRAME (Spanish (Modern))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_ABOUTBOX (Spanish (Modern))]
Type=1
Class=CAboutDlg
ControlCount=9
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_LIST1,SysListView32,1350631425
Control6=IDC_BUTTON1,button,1342242816
Control7=IDC_BUTTON2,button,1342242816
Control8=IDC_BUTTON3,button,1342242816
Control9=IDC_BUTTON4,button,1342242816

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=IDM_CREAR
Command8=IDM_IMPRIME
Command9=IDM_LIST
CommandCount=9

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=IDM_CREAR
Command2=IDM_IMPRIME
Command3=IDM_LIST
CommandCount=3

[DLG:IDD_IMPRIMIR]
Type=1
Class=CCajaImprime
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,SysListView32,1350631425

[CLS:CCajaImprime]
Type=0
HeaderFile=CajaImprime.h
ImplementationFile=CajaImprime.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST1
VirtualFilter=dWC

