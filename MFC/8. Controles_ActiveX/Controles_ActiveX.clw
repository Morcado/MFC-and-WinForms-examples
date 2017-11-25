; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CControles_ActiveXView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Controles_ActiveX.h"
LastPage=0

ClassCount=8
Class1=CControles_ActiveXApp
Class2=CControles_ActiveXDoc
Class3=CControles_ActiveXView
Class4=CMainFrame

ResourceCount=9
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_ABOUTBOX (Spanish (Modern))
Resource4=IDR_MENU1
Class6=CVideo
Resource5=IDD_CAL
Class7=CCalendario
Resource6=IDD_TREE
Resource7=IDR_TOOLBAR1
Class8=CTree
Resource8=IDD_VIDEO
Resource9=IDR_MAINFRAME (Spanish (Modern))

[CLS:CControles_ActiveXApp]
Type=0
HeaderFile=Controles_ActiveX.h
ImplementationFile=Controles_ActiveX.cpp
Filter=N

[CLS:CControles_ActiveXDoc]
Type=0
HeaderFile=Controles_ActiveXDoc.h
ImplementationFile=Controles_ActiveXDoc.cpp
Filter=N

[CLS:CControles_ActiveXView]
Type=0
HeaderFile=Controles_ActiveXView.h
ImplementationFile=Controles_ActiveXView.cpp
Filter=C
LastObject=IDC_PRUEBA
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=Controles_ActiveX.cpp
ImplementationFile=Controles_ActiveX.cpp
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
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CVideo]
Type=0
HeaderFile=Video.h
ImplementationFile=Video.cpp
BaseClass=CDialog
Filter=D
LastObject=CVideo
VirtualFilter=dWC

[DLG:IDD_CAL]
Type=1
Class=CCalendario
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_MONTHVIEW1,{232E456A-87C3-11D1-8BE3-0000F8754DA1},1342242816

[CLS:CCalendario]
Type=0
HeaderFile=Calendario.h
ImplementationFile=Calendario.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CCalendario

[MNU:IDR_MENU1]
Type=1
Class=CControles_ActiveXView
Command1=IDM_VIDEO
Command2=IDM_CAL
Command3=IDM_TREE
Command4=IDC_PRUEBA
CommandCount=4

[DLG:IDD_TREE]
Type=1
Class=CTree
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TREE1,SysTreeView32,1350635523

[CLS:CTree]
Type=0
HeaderFile=Tree.h
ImplementationFile=Tree.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_TREE1

[DLG:IDD_VIDEO]
Type=1
Class=CVideo
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_OCX1,{6BF52A52-394A-11D3-B153-00C04F79FAA6},1342242816
Control4=IDC_PLAY,button,1342242816
Control5=IDC_PAUSA,button,1342242816
Control6=IDC_STOP,button,1342242816

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=IDM_VIDEO
Command2=IDM_CAL
Command3=IDM_TREE
CommandCount=3

