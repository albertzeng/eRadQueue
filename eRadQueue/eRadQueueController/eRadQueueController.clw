; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgController
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "eradqueuecontroller.h"
LastPage=0

ClassCount=6
Class1=CDlgController
Class2=CeRadQueueControllerDlg
Class3=CeRadQueueControllerDlgAutoProxy
Class4=CDlgQueueController
Class5=CeRadQueueController

ResourceCount=5
Resource1=IDD_DIALOG_CONTROLLER
Resource2=IDD_DIALOG_QUEUE_CONTROLLER
Resource3=IDD_ERADQUEUECONTROLLER_DIALOG
Resource4=IDD_DIALOG_LOGIN
Class6=CDlgLogin
Resource5=IDR_MENU_TRAY_ICON

[CLS:CDlgController]
Type=0
BaseClass=CDialog
HeaderFile=DlgController.h
ImplementationFile=DlgController.cpp
LastObject=CDlgController
Filter=D

[CLS:CeRadQueueControllerDlgAutoProxy]
Type=0
BaseClass=CCmdTarget
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
Filter=N

[CLS:CDlgQueueController]
Type=0
BaseClass=CDialog
HeaderFile=DlgQueueController.h
ImplementationFile=DlgQueueController.cpp
LastObject=CDlgQueueController
Filter=D

[CLS:CeRadQueueController]
Type=0
BaseClass=CWinApp
HeaderFile=eRadQueueController.h
ImplementationFile=eRadQueueController.cpp
Filter=N
LastObject=CeRadQueueController

[CLS:CeRadQueueControllerDlg]
Type=0
BaseClass=CDialog
HeaderFile=eRadQueueControllerDlg.h
ImplementationFile=eRadQueueControllerDlg.cpp
Filter=D

[DLG:IDD_DIALOG_CONTROLLER]
Type=1
Class=CDlgController
ControlCount=0

[DLG:IDD_DIALOG_LOGIN]
Type=1
Class=CDlgLogin
ControlCount=10
Control1=IDC_STATIC_LOGIN,static,1342177294
Control2=IDC_STATIC,static,1073872896
Control3=IDC_STATIC,static,1073872896
Control4=IDC_STATIC,static,1073872896
Control5=IDC_STATIC,static,1073872896
Control6=IDC_EDIT_CODE,edit,1350631552
Control7=IDC_EDIT_NAME,edit,1350568064
Control8=IDC_EDIT_DEPARTMENT,edit,1350568064
Control9=IDC_EDIT_PASSWORD,edit,1350631584
Control10=IDC_BUTTON_LOGIN,button,1342242816

[DLG:IDD_DIALOG_QUEUE_CONTROLLER]
Type=1
Class=CDlgQueueController
ControlCount=2
Control1=IDC_BUTTON_HIDE,button,1342242816
Control2=IDC_BUTTON_EXIT,button,1342242816

[DLG:IDD_ERADQUEUECONTROLLER_DIALOG]
Type=1
Class=CeRadQueueControllerDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[MNU:IDR_MENU_TRAY_ICON]
Type=1
Class=?
Command1=IDM_SHOW_HIDE
Command2=IDM_EXIT
CommandCount=2

[CLS:CDlgLogin]
Type=0
HeaderFile=DlgLogin.h
ImplementationFile=DlgLogin.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgLogin
VirtualFilter=dWC

