; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBD2View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BD2.h"
LastPage=0

ClassCount=6
Class1=CBD2App
Class2=CBD2Doc
Class3=CBD2View
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=10
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource7=IDD_BD2_FORM
Resource8=IDD_ABOUTBOX (Spanish (Modern))
Resource9=IDR_MAINFRAME (Spanish (Modern))
Class5=CBD2Set
Resource10=IDD_BD2_FORM (Spanish (Modern))

[CLS:CBD2App]
Type=0
HeaderFile=BD2.h
ImplementationFile=BD2.cpp
Filter=N

[CLS:CBD2Doc]
Type=0
HeaderFile=BD2Doc.h
ImplementationFile=BD2Doc.cpp
Filter=N

[CLS:CBD2View]
Type=0
HeaderFile=BD2View.h
ImplementationFile=BD2View.cpp
Filter=N
BaseClass=CRecordView
VirtualFilter=RVWC
LastObject=IDM_DEL


[CLS:CBD2Set]
Type=0
HeaderFile=BD2Set.h
ImplementationFile=BD2Set.cpp
Filter=N

[DB:CBD2Set]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[Id], 4, 4
Column2=[Clave], 12, 510
Column3=[Nombre], 12, 510
Column4=[Calificación 1], 4, 4
Column5=[Calificación 2], 4, 4


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDM_UPDATE




[CLS:CAboutDlg]
Type=0
HeaderFile=BD2.cpp
ImplementationFile=BD2.cpp
Filter=D

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
Command10=ID_RECORD_LAST
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13
Command1=ID_FILE_MRU_FILE1
Command2=ID_APP_EXIT
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_RECORD_FIRST
Command8=ID_RECORD_PREV
Command9=ID_RECORD_NEXT

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_NEXT_PANE
Command10=ID_PREV_PANE
CommandCount=10
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE

[DLG:IDD_BD2_FORM]
Type=1
Class=CBD2View

[DLG:IDD_BD2_FORM (Spanish (Modern))]
Type=1
Class=CBD2View
ControlCount=10
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT3,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT4,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT5,edit,1350631552
Control10=IDC_STATIC,static,1342308352

[TB:IDR_MAINFRAME (Spanish (Modern))]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_FILE_PRINT
Command5=ID_RECORD_FIRST
Command6=ID_RECORD_PREV
Command7=ID_RECORD_NEXT
Command8=ID_RECORD_LAST
Command9=ID_APP_ABOUT
CommandCount=9

[MNU:IDR_MAINFRAME (Spanish (Modern))]
Type=1
Class=CMainFrame
Command1=ID_APP_EXIT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_RECORD_FIRST
Command7=ID_RECORD_PREV
Command8=ID_RECORD_NEXT
Command9=ID_RECORD_LAST
Command10=IDM_ADD
Command11=IDM_CLEAR
Command12=IDM_DEL
Command13=IDM_UPDATE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME (Spanish (Modern))]
Type=1
Class=?
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_NEXT_PANE
Command10=ID_PREV_PANE
CommandCount=10

[DLG:IDD_ABOUTBOX (Spanish (Modern))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

