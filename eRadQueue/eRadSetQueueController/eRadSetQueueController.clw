; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPageSingleQueueShowAll
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "eradsetqueuecontroller.h"
LastPage=0

ClassCount=10
Class1=CERadSetQueueControllerApp
Class2=CPageController
Class3=CPageGeneral
Class4=CPageMode0General
Class5=CPageMode1Report
Class6=CPageMode2SingleQueue
Class7=CPageSingleQueueShowAll
Class8=CPageVideo
Class9=CPageVoice
Class10=CSetSheet

ResourceCount=8
Resource1=IDD_DIALOG_MODE0_GENERAL
Resource2=IDD_DIALOG_MODE1_REPORT
Resource3=IDD_DIALOG_MODE2_SINGLE_QUEUE
Resource4=IDD_DIALOG_VIDEO
Resource5=IDD_DIALOG_CONTROLLER
Resource6=IDD_DIALOG_VOICE
Resource7=IDD_DIALOG_GENERAL
Resource8=IDD_DIALOG_MODE3_SINGLE_QUEUE_SHOWALL

[CLS:CERadSetQueueControllerApp]
Type=0
BaseClass=CWinApp
HeaderFile=eRadSetQueueController.h
ImplementationFile=eRadSetQueueController.cpp
LastObject=CERadSetQueueControllerApp
Filter=N

[CLS:CPageController]
Type=0
BaseClass=CPropertyPage
HeaderFile=PageController.h
ImplementationFile=PageController.cpp
Filter=D
VirtualFilter=idWC
LastObject=CPageController

[CLS:CPageGeneral]
Type=0
BaseClass=CPropertyPage
HeaderFile=PageGeneral.h
ImplementationFile=PageGeneral.cpp
LastObject=CPageGeneral
Filter=D
VirtualFilter=idWC

[CLS:CPageMode0General]
Type=0
BaseClass=CPropertyPage
HeaderFile=PageMode0General.h
ImplementationFile=PageMode0General.cpp
LastObject=CPageMode0General
Filter=D

[CLS:CPageMode1Report]
Type=0
BaseClass=CPropertyPage
HeaderFile=PageMode1Report.h
ImplementationFile=PageMode1Report.cpp
Filter=D
LastObject=IDC_COMBO_MODE1_SOURCE_HOSPITAL
VirtualFilter=idWC

[CLS:CPageMode2SingleQueue]
Type=0
BaseClass=CPropertyPage
HeaderFile=PageMode2SingleQueue.h
ImplementationFile=PageMode2SingleQueue.cpp
LastObject=CPageMode2SingleQueue

[CLS:CPageSingleQueueShowAll]
Type=0
BaseClass=CPropertyPage
HeaderFile=PageSingleQueueShowAll.h
ImplementationFile=PageSingleQueueShowAll.cpp
LastObject=CPageSingleQueueShowAll
Filter=D
VirtualFilter=idWC

[CLS:CPageVideo]
Type=0
BaseClass=CPropertyPage
HeaderFile=PageVideo.h
ImplementationFile=PageVideo.cpp
Filter=D
LastObject=CPageVideo

[CLS:CPageVoice]
Type=0
BaseClass=CPropertyPage
HeaderFile=PageVoice.h
ImplementationFile=PageVoice.cpp
Filter=D
VirtualFilter=idWC
LastObject=IDC_EDIT_SERIESID

[CLS:CSetSheet]
Type=0
BaseClass=CPropertySheet
HeaderFile=SetSheet.h
ImplementationFile=SetSheet.cpp
Filter=W

[DLG:IDD_DIALOG_CONTROLLER]
Type=1
Class=CPageController
ControlCount=46
Control1=IDC_LIST_CONTROLLER,SysListView32,1350631425
Control2=IDC_BUTTON_CONTROLLER_BACKGROUND,button,1342242816
Control3=IDC_BUTTON_CONTROLLER_FONT,button,1342242816
Control4=IDC_BUTTON_TITLE_BACKGROUND,button,1342242816
Control5=IDC_BUTTON_TITLE_FOREGROUND,button,1342242816
Control6=IDC_BUTTON_TITLE_FONT,button,1342242816
Control7=IDC_BUTTON_SCROLL_BACKGROUND,button,1342242816
Control8=IDC_BUTTON_SCROLL_FOREGROUND,button,1342242816
Control9=IDC_BUTTON_SCROLL_FONT,button,1342242816
Control10=IDC_STATIC_CONTROLLER,static,1342308865
Control11=IDC_STATIC_TITLE,static,1342308865
Control12=IDC_STATIC_SCROLL,static,1342308865
Control13=IDC_STATIC,button,1342177287
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDIT_CONTROLLER_NODE,edit,1350631552
Control16=IDC_STATIC,static,1342308352
Control17=IDC_EDIT_CONTROLLER_NAME,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_COMBO_CONTROLLER_MODE,combobox,1344339971
Control20=IDC_STATIC,static,1342308352
Control21=IDC_EDIT_CONTROLLER_LEFT,edit,1350631552
Control22=IDC_EDIT_CONTROLLER_TOP,edit,1350631552
Control23=IDC_EDIT_CONTROLLER_WIDTH,edit,1350631552
Control24=IDC_EDIT_CONTROLLER_HEIGHT,edit,1350631552
Control25=IDC_STATIC,static,1342308352
Control26=IDC_EDIT_CONTROLLER_ROWS,edit,1350631552
Control27=IDC_EDIT_CONTROLLER_COLS,edit,1350631552
Control28=IDC_CHECK_CONTROLLER_FROM_TOP,button,1342242819
Control29=IDC_CHECK_TITLE_ENABLE,button,1342242819
Control30=IDC_EDIT_TITLE_CONTENT,edit,1350631552
Control31=IDC_STATIC,static,1342308352
Control32=IDC_EDIT_TITLE_HEIGHT,edit,1350631552
Control33=IDC_STATIC,button,1342177287
Control34=IDC_CHECK_SCROLL_ENABLE,button,1342242819
Control35=IDC_STATIC,static,1342308352
Control36=IDC_EDIT_SCROLL_HEIGHT,edit,1350631552
Control37=IDC_STATIC,static,1342308352
Control38=IDC_EDIT_SCROLL_SPEED,edit,1350631552
Control39=IDC_EDIT_SCROLL_CONTENT,edit,1352728644
Control40=IDC_BUTTON_INSERT,button,1342242816
Control41=IDC_BUTTON_UPDATE,button,1342242816
Control42=IDC_BUTTON_DELETE,button,1342242816
Control43=IDC_CHECK_BDESC,button,1342242819
Control44=IDC_CHECK_BSCROLL,button,1342242819
Control45=IDC_STATIC,static,1342308352
Control46=IDC_EDIT_QUEUESCROLL_SPEED,edit,1350631552

[DLG:IDD_DIALOG_GENERAL]
Type=1
Class=CPageGeneral
ControlCount=26
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,button,1342177287
Control3=IDC_CHECK_LOG_TRACK,button,1342242819
Control4=IDC_CHECK_LOG_ERROR,button,1342242819
Control5=IDC_CHECK_LOG_DEBUG,button,1342242819
Control6=IDC_CHECK_LOG_MESSAGE,button,1342242819
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,static,1342308352
Control9=IDC_BUTTON_EIS_DATABASE,button,1342242816
Control10=IDC_EDIT_EIS_DATABASE,edit,1342244992
Control11=IDC_STATIC,static,1342308352
Control12=IDC_COMBO_DEPARTMENT,combobox,1344340227
Control13=IDC_STATIC,button,1342177287
Control14=IDC_STATIC,static,1342308352
Control15=IDC_COMBO_VOICE_CLASS,combobox,1344339971
Control16=IDC_STATIC,static,1342308352
Control17=IDC_EDIT_VOICE_RATE,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_EDIT_VOICE_VOLUME,edit,1350631552
Control20=IDC_STATIC,static,1342308352
Control21=IDC_BUTTON_VOICE_PLAY,button,1342242816
Control22=IDC_EDIT_VOICE_PLAY,edit,1352728644
Control23=IDC_STATIC,static,1342308352
Control24=IDC_CHECK_AUTO_LOGIN,button,1342242819
Control25=IDC_EDIT_AUTO_DOCTOR_CODE,edit,1350631552
Control26=IDC_CHECK_HIDE_NAME,button,1342242819

[DLG:IDD_DIALOG_MODE0_GENERAL]
Type=1
Class=CPageMode0General
ControlCount=2
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,button,1342177287

[DLG:IDD_DIALOG_MODE1_REPORT]
Type=1
Class=CPageMode1Report
ControlCount=18
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_MODE1_TIME_RANGE,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_MODE1_TIME_DELAY,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_MODE1_REFRESH_IDLE,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_MODE1_REFRESH_SCREEN,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_COMBO_MODE1_ADMISSION_SOURCE,combobox,1344340515
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMBO_MODE1_EXCLUDE_OUT_STATUS,combobox,1344340515
Control14=IDC_STATIC,static,1342308352
Control15=IDC_COMBO_MODE1_ORDER_MODE,combobox,1344339971
Control16=IDC_STATIC,button,1342177287
Control17=IDC_STATIC,static,1342308352
Control18=IDC_COMBO_MODE1_SOURCE_HOSPITAL,combobox,1344340515

[DLG:IDD_DIALOG_MODE2_SINGLE_QUEUE]
Type=1
Class=CPageMode2SingleQueue
ControlCount=7
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_MODE2_DEVICE_INDEX,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_MODE2_REFRESH_IDLE,edit,1350631552
Control6=IDC_STATIC,button,1342177287
Control7=IDC_LIST_DEVICE,SysListView32,1350631425

[DLG:IDD_DIALOG_MODE3_SINGLE_QUEUE_SHOWALL]
Type=1
Class=CPageSingleQueueShowAll
ControlCount=34
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_MODE3_COLUMN_NAME,edit,1350631552
Control9=IDC_MODE3_COLUMN_LEFT,edit,1350631552
Control10=IDC_MODE3_COLUMN_RIGHT,edit,1350631552
Control11=IDC_MODE3_COLUMN_TOP,edit,1350631552
Control12=IDC_MODE3_COLUMN_BOTTOM,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_MODE3_COLUMN_ID,edit,1350631552
Control15=IDC_MODE3_COLUMN_ROWS,edit,1350631552
Control16=IDC_MODE3_COLUMN_LINES,edit,1350631552
Control17=IDC_LIST_MODE3_COLUMNSET,SysListView32,1350631425
Control18=IDC_LIST_MODE3_QUEUE,SysListView32,1342242817
Control19=IDC_BUTTON_MODE3_ADD,button,1342242816
Control20=IDC_BUTTON_MODE3_CHANGE,button,1342242816
Control21=IDC_BUTTON_MODE3_DELETE,button,1342242816
Control22=IDC_MODE3_COLUMN_NAME_DEMO,static,1342308865
Control23=IDC_MODE3_COLUMN_DEMO,static,1342308865
Control24=IDC_BUTTON_MODE3_COLUMN_NAME_FONT,button,1342242816
Control25=IDC_BUTTON_MODE3_COLUME_NAME_FTCOLOR,button,1342242816
Control26=IDC_BUTTON_MODE3_COLUMN_FONT,button,1342242816
Control27=IDC_BUTTON_MODE3_COLUMN_FTCOLOR,button,1342242816
Control28=IDC_BUTTON_MODE3_COLUMN_NAME_BKCOLOR,button,1342242816
Control29=IDC_STATIC,static,1342308352
Control30=IDC_STATIC,static,1342308352
Control31=IDC_EDIT_MODE3_QUEUEINDEX,edit,1350631552
Control32=IDC_EDIT_MODE3_RENOVATETIME,edit,1350631552
Control33=IDC_BUTTON_MODE3_COLUMN_BKCOLOR,button,1342242816
Control34=IDC_CHECK_BShowHorizontal,button,1342242819

[DLG:IDD_DIALOG_VIDEO]
Type=1
Class=CPageVideo
ControlCount=14
Control1=IDC_LIST_VIDEO,SysListView32,1350631425
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_VIDEO_ORDER,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_VIDEO_LENGTH,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_VIDEO_CONTENT,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_BUTTON_VIDEO_FOREGROUND,button,1342242816
Control11=IDC_STATIC_CONTROLLER,static,1342308865
Control12=IDC_BUTTON_INSERT,button,1342242816
Control13=IDC_BUTTON_UPDATE,button,1342242816
Control14=IDC_BUTTON_DELETE,button,1342242816

[DLG:IDD_DIALOG_VOICE]
Type=1
Class=CPageVoice
ControlCount=14
Control1=IDC_STATIC,button,1342177287
Control2=IDC_CHECK_VOICE_ENABLE,button,1342242819
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_VOICE_REPEAT,edit,1350631552
Control5=IDC_EDIT_VOICE_INTERVAL,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_VOICE_FORMAT,edit,1352728644
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,button,1342177287
Control10=IDC_CHECK_PROMPTVOICE_ENABLE,button,1342242819
Control11=IDC_CHECK_BUSEKDFX,button,1342242819
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT_SERIESID,edit,1350631552
Control14=IDC_STATIC,static,1342308352
