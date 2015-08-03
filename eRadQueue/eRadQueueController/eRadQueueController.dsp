# Microsoft Developer Studio Project File - Name="eRadQueueController" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=eRadQueueController - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "eRadQueueController.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "eRadQueueController.mak" CFG="eRadQueueController - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "eRadQueueController - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "eRadQueueController - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "eRadQueueController - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "eRadQueueController - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\DBAPI" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 Mpr.lib Winmm.lib Vfw32.lib dicomlib_d.lib LibImage_d.lib Libj08_d.lib Libj12_d.lib Libj16_d.lib Zlib_d.lib iFlyTTS.lib /nologo /subsystem:windows /debug /machine:I386 /nodefaultlib:"libcd.lib" /nodefaultlib:"libcmtd.lib" /out:"D:\MyCode\eRadQueue\RADinfo\eRadQueue\eRadQueueController.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "eRadQueueController - Win32 Release"
# Name "eRadQueueController - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\DlgController.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgControllerMode0.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgControllerMode1.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgControllerMode2.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgControllerMode3.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgLogin.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgProxy.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgQueueController.cpp
# End Source File
# Begin Source File

SOURCE=.\eRadQueueController.cpp
# End Source File
# Begin Source File

SOURCE=.\eRadQueueController.odl
# ADD MTL /h "ERadQueueController_i.h" /iid "ERadQueueController_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\eRadQueueController.rc
# End Source File
# Begin Source File

SOURCE=.\eRadQueueControllerDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\..\eRadTools\ModuleTextToSpeech.cpp
# End Source File
# Begin Source File

SOURCE=.\RunTime.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\..\eRadTools\TabCtrlEx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\eRadTools\ToolsEx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\eRadTools\XmlParse.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\DlgController.h
# End Source File
# Begin Source File

SOURCE=.\DlgControllerMode0.h
# End Source File
# Begin Source File

SOURCE=.\DlgControllerMode1.h
# End Source File
# Begin Source File

SOURCE=.\DlgControllerMode2.h
# End Source File
# Begin Source File

SOURCE=.\DlgControllerMode3.h
# End Source File
# Begin Source File

SOURCE=.\DlgLogin.h
# End Source File
# Begin Source File

SOURCE=.\DlgProxy.h
# End Source File
# Begin Source File

SOURCE=.\DlgQueueController.h
# End Source File
# Begin Source File

SOURCE=.\eRadQueueController.h
# End Source File
# Begin Source File

SOURCE=.\eRadQueueControllerDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RunTime.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\..\eRadTools\ToolsEx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\eRadQueueController.ico
# End Source File
# Begin Source File

SOURCE=.\res\eRadQueueController.rc2
# End Source File
# Begin Source File

SOURCE=.\ERadQueueController.rgs
# End Source File
# End Group
# Begin Source File

SOURCE=.\eRadQueueController.reg
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section eRadQueueController : {00000000-0010-0000-CCFB-E277FFFFFFFF}
# 	1:23:IDR_ERADQUEUECONTROLLER:104
# End Section
