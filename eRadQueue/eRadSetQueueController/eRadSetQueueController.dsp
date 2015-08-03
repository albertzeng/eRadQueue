# Microsoft Developer Studio Project File - Name="eRadSetQueueController" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=eRadSetQueueController - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "eRadSetQueueController.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "eRadSetQueueController.mak" CFG="eRadSetQueueController - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "eRadSetQueueController - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "eRadSetQueueController - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "eRadSetQueueController - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386

!ELSEIF  "$(CFG)" == "eRadSetQueueController - Win32 Debug"

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
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../eRadQueueController" /I "..\..\DBAPI" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 Mpr.lib Winmm.lib Vfw32.lib dicomlib_d.lib LibImage_d.lib Libj08_d.lib Libj12_d.lib Libj16_d.lib Zlib_d.lib /nologo /subsystem:windows /dll /debug /machine:I386 /nodefaultlib:"libcd.lib" /nodefaultlib:"libcmtd.lib" /out:"..\..\RADinfo\eRadQueue\eRadSetQueueController.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "eRadSetQueueController - Win32 Release"
# Name "eRadSetQueueController - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\eRadTools\ComboBoxCheck.cpp
# End Source File
# Begin Source File

SOURCE=.\eRadSetQueueController.cpp
# End Source File
# Begin Source File

SOURCE=.\eRadSetQueueController.def
# End Source File
# Begin Source File

SOURCE=.\eRadSetQueueController.odl
# ADD MTL /h "ERadSetQueueController_i.h" /iid "ERadSetQueueController_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\eRadSetQueueController.rc
# End Source File
# Begin Source File

SOURCE=..\..\eRadTools\ListCtrlEx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\eRadTools\ModuleTextToSpeech.cpp
# End Source File
# Begin Source File

SOURCE=.\PageController.cpp
# End Source File
# Begin Source File

SOURCE=.\PageGeneral.cpp
# End Source File
# Begin Source File

SOURCE=.\PageMode0General.cpp
# End Source File
# Begin Source File

SOURCE=.\PageMode1Report.cpp
# End Source File
# Begin Source File

SOURCE=.\PageMode2SingleQueue.cpp
# End Source File
# Begin Source File

SOURCE=.\PageSingleQueueShowAll.cpp
# End Source File
# Begin Source File

SOURCE=.\PageVideo.cpp
# End Source File
# Begin Source File

SOURCE=.\PageVoice.cpp
# End Source File
# Begin Source File

SOURCE=..\eRadQueueController\RunTime.cpp
# End Source File
# Begin Source File

SOURCE=.\SetSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
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

SOURCE=.\eRadSetQueueController.h
# End Source File
# Begin Source File

SOURCE=..\..\eRadTools\ModuleTextToSpeech.h
# End Source File
# Begin Source File

SOURCE=.\PageController.h
# End Source File
# Begin Source File

SOURCE=.\PageGeneral.h
# End Source File
# Begin Source File

SOURCE=.\PageMode0General.h
# End Source File
# Begin Source File

SOURCE=.\PageMode1Report.h
# End Source File
# Begin Source File

SOURCE=.\PageMode2SingleQueue.h
# End Source File
# Begin Source File

SOURCE=.\PageSingleQueueShowAll.h
# End Source File
# Begin Source File

SOURCE=.\PageVideo.h
# End Source File
# Begin Source File

SOURCE=.\PageVoice.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=..\eRadQueueController\RunTime.h
# End Source File
# Begin Source File

SOURCE=.\SetSheet.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\eRadSetQueueController.ico
# End Source File
# Begin Source File

SOURCE=.\res\eRadSetQueueController.rc2
# End Source File
# Begin Source File

SOURCE=.\ERadSetQueueController.rgs
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section eRadSetQueueController : {00000000-0000-0000-0000-000000000000}
# 	1:26:IDR_ERADSETQUEUECONTROLLER:15000
# End Section
