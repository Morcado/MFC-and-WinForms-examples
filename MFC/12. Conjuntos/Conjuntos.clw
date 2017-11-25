; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CConjuntosView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Conjuntos.h"
LastPage=0

ClassCount=8
Class1=CConjuntosApp
Class2=CConjuntosDoc
Class3=CConjuntosView
Class4=CMainFrame

ResourceCount=9
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_INTER
Resource4=IDR_TOOLBAR1
Resource5=IDD_COMPLEMENTO
Resource6=IDD_UNION
Class6=CComplemento
Resource7=IDD_ABOUTBOX (Spanish (Modern))
Resource8=IDR_MENU1
Class7=CInterseccion
Class8=CUnion
Resource9=IDR_MAINFRAME (Spanish (Modern))

[CLS:CConjuntosApp]
Type=0
HeaderFile=Conjuntos.h
ImplementationFile=Conjuntos.cpp
Filter=N

[CLS:CConjuntosDoc]
Type=0
HeaderFile=ConjuntosDoc.h
ImplementationFile=ConjuntosDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=IDM_INTERSECCION

[CLS:CConjuntosView]
Type=0
HeaderFile=ConjuntosView.h
ImplementationFile=ConjuntosView.cpp
Filter=C
LastObject=IDM_IMPRIME
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=Conjuntos.cpp
ImplementationFile=Conjuntos.cpp
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
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
CommandCount=16
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command16=ID_APP_ABOUT

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
CommandCount=14
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE


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
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME (Spanish (Modern))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_ABOUTBOX (Spanish (Modern))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_COMPLEMENTO]
Type=1
Class=CComplemento
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_COMBO1,combobox,1344339969
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COMBO2,combobox,1344339969
Control7=IDC_STATIC,static,1342308352
Control8=IDC_COMPLE,button,1342242816

[DLG:IDD_INTER]
Type=1
Class=CInterseccion
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_COMBO1,combobox,1344339969
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COMBO2,combobox,1344339969
Control7=IDC_STATIC,static,1342308352
Control8=IDC_COMBO3,combobox,1344339969
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,button,1342177287
Control11=IDC_INTERSECCION,button,1342242816
Control12=IDC_STATIC,static,1342312449

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=IDM_CONJUNTO
Command2=IDM_IMPRIME
Command3=IDM_COMPLEMENTO
Command4=IDM_INTERSECCION
Command5=IDM_UNION
CommandCount=5

[MNU:IDR_MENU1]
Type=1
Class=CConjuntosView
Command1=IDM_CONJUNTO
Command2=IDM_IMPRIME
Command3=IDM_ASIGNACION
Command4=IDM_COMPLEMENTO
Command5=IDM_INTERSECCION
Command6=IDM_UNION
CommandCount=6

[CLS:CComplemento]
Type=0
HeaderFile=Complemento.h
ImplementationFile=Complemento.cpp
BaseClass=CDialog
Filter=D
LastObject=CComplemento
VirtualFilter=dWC

[CLS:CInterseccion]
Type=0
HeaderFile=Interseccion.h
ImplementationFile=Interseccion.cpp
BaseClass=CDialog
Filter=D
LastObject=CInterseccion
VirtualFilter=dWC

[DLG:IDD_UNION]
Type=1
Class=CUnion
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_COMBO1,combobox,1344339969
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COMBO2,combobox,1344339969
Control7=IDC_STATIC,static,1342308352
Control8=IDC_COMBO3,combobox,1344339969
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,button,1342177287
Control11=IDC_UNION,button,1342242816
Control12=IDC_STATIC,static,1342312449

[CLS:CUnion]
Type=0
HeaderFile=Union.h
ImplementationFile=Union.cpp
BaseClass=CDialog
Filter=D
LastObject=CUnion
VirtualFilter=dWC

