# Microsoft Developer Studio Project File - Name="DBAPI" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=DBAPI - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "DBAPI.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DBAPI.mak" CFG="DBAPI - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DBAPI - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "DBAPI - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "DBAPI - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386

!ELSEIF  "$(CFG)" == "DBAPI - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "./DBAPI" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "DBAPI - Win32 Release"
# Name "DBAPI - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\database.cpp
# End Source File
# Begin Source File

SOURCE=.\DBAPI.cpp
# End Source File
# Begin Source File

SOURCE=.\DBAPI.def
# End Source File
# Begin Source File

SOURCE=.\DBAPI.odl
# ADD MTL /h "DBAPI_i.h" /iid "DBAPI_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\DBAPI.rc
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\database.h
# End Source File
# Begin Source File

SOURCE=.\DBAPI.h
# End Source File
# Begin Source File

SOURCE=.\dboEISExchange.H
# End Source File
# Begin Source File

SOURCE=.\dboEISExchangeFailed.H
# End Source File
# Begin Source File

SOURCE=.\dboEISFavorite.H
# End Source File
# Begin Source File

SOURCE=.\dboEISFavoriteStudies.H
# End Source File
# Begin Source File

SOURCE=.\dboEISLog.H
# End Source File
# Begin Source File

SOURCE=.\dboEISMessage.H
# End Source File
# Begin Source File

SOURCE=.\dboEISPatients.H
# End Source File
# Begin Source File

SOURCE=.\dboEISQueue.H
# End Source File
# Begin Source File

SOURCE=.\dboEISQueueCall.H
# End Source File
# Begin Source File

SOURCE=.\dboEISQueueControl.H
# End Source File
# Begin Source File

SOURCE=.\dboEISReports.H
# End Source File
# Begin Source File

SOURCE=.\dboEISResults.H
# End Source File
# Begin Source File

SOURCE=.\dboEISResultsImage.H
# End Source File
# Begin Source File

SOURCE=.\dboEISService.H
# End Source File
# Begin Source File

SOURCE=.\dboEISStudies.H
# End Source File
# Begin Source File

SOURCE=.\dboEISStudiesConsultation.H
# End Source File
# Begin Source File

SOURCE=.\dboEISStudiesConsume.H
# End Source File
# Begin Source File

SOURCE=.\dboEISStudiesDisease.H
# End Source File
# Begin Source File

SOURCE=.\dboEISStudiesQC.H
# End Source File
# Begin Source File

SOURCE=.\dboEISStudiesReviews.H
# End Source File
# Begin Source File

SOURCE=.\dboFPAssociation.H
# End Source File
# Begin Source File

SOURCE=.\dboFPFilmBox.H
# End Source File
# Begin Source File

SOURCE=.\dboFPFilmImage.H
# End Source File
# Begin Source File

SOURCE=.\dboFPFilmSession.H
# End Source File
# Begin Source File

SOURCE=.\dboFPServices.H
# End Source File
# Begin Source File

SOURCE=.\dboIMGAnnexFile.H
# End Source File
# Begin Source File

SOURCE=.\dboIMGArchive.H
# End Source File
# Begin Source File

SOURCE=.\dboIMGAviFile.H
# End Source File
# Begin Source File

SOURCE=.\dboIMGNearline.H
# End Source File
# Begin Source File

SOURCE=.\dboIMGNearlineStorage.H
# End Source File
# Begin Source File

SOURCE=.\dboIMGNearlineStorageFile.H
# End Source File
# Begin Source File

SOURCE=.\dboIMGOperate.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRBodies.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRBodiesReplace.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRCode.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRConsume.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRControl.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRDepartment.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRDevice.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRDisease.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRDoctor.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRExamine.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRExamineConsume.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRLinker.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRModalities.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRNode.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRNodeClient.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRPhrase.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRPrivilege.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRSpecs.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRTemplate.H
# End Source File
# Begin Source File

SOURCE=.\dboMGRTemplateDisease.H
# End Source File
# Begin Source File

SOURCE=.\dboPACSFailedImages.H
# End Source File
# Begin Source File

SOURCE=.\dboPACSImages.H
# End Source File
# Begin Source File

SOURCE=.\dboPACSPatients.H
# End Source File
# Begin Source File

SOURCE=.\dboPACSSeries.H
# End Source File
# Begin Source File

SOURCE=.\dboPACSStudies.H
# End Source File
# Begin Source File

SOURCE=.\dboQACSFailedImages.H
# End Source File
# Begin Source File

SOURCE=.\dboQACSImages.H
# End Source File
# Begin Source File

SOURCE=.\dboQACSPatients.H
# End Source File
# Begin Source File

SOURCE=.\dboQACSSeries.H
# End Source File
# Begin Source File

SOURCE=.\dboQACSStudies.H
# End Source File
# Begin Source File

SOURCE=.\dboStorageDVD.H
# End Source File
# Begin Source File

SOURCE=.\dboStorageOrder.H
# End Source File
# Begin Source File

SOURCE=.\dboStorageOrderStudies.H
# End Source File
# Begin Source File

SOURCE=.\dbovEISExchange.H
# End Source File
# Begin Source File

SOURCE=.\dbovEISMwl.H
# End Source File
# Begin Source File

SOURCE=.\dbovEISQueueCall.H
# End Source File
# Begin Source File

SOURCE=.\dbovEISResultsImage.H
# End Source File
# Begin Source File

SOURCE=.\dbovEISStudies.H
# End Source File
# Begin Source File

SOURCE=.\dbovEISWorksLists.H
# End Source File
# Begin Source File

SOURCE=.\dbovEISWorksService.H
# End Source File
# Begin Source File

SOURCE=.\dbovEISWorksVersions.H
# End Source File
# Begin Source File

SOURCE=.\dbovFPFilmSession.H
# End Source File
# Begin Source File

SOURCE=.\dbovFPImages.H
# End Source File
# Begin Source File

SOURCE=.\dbovFPServices.H
# End Source File
# Begin Source File

SOURCE=.\dbovIMGArchive.H
# End Source File
# Begin Source File

SOURCE=.\dbovIMGOperate.H
# End Source File
# Begin Source File

SOURCE=.\dbovMGRBodiesReplace.H
# End Source File
# Begin Source File

SOURCE=.\dbovMGRDoctor.H
# End Source File
# Begin Source File

SOURCE=.\dbovMGRExamine.H
# End Source File
# Begin Source File

SOURCE=.\dbovMGRExamineConsume.H
# End Source File
# Begin Source File

SOURCE=.\dbovMGRNodeClient.H
# End Source File
# Begin Source File

SOURCE=.\dbovPACSImages.H
# End Source File
# Begin Source File

SOURCE=.\dbovPACSPatients.H
# End Source File
# Begin Source File

SOURCE=.\dbovPACSSeries.H
# End Source File
# Begin Source File

SOURCE=.\dbovPACSStudies.H
# End Source File
# Begin Source File

SOURCE=.\dbovQACSImages.H
# End Source File
# Begin Source File

SOURCE=.\dbovQACSPatients.H
# End Source File
# Begin Source File

SOURCE=.\dbovQACSSeries.H
# End Source File
# Begin Source File

SOURCE=.\dbovQACSStudies.H
# End Source File
# Begin Source File

SOURCE=.\dbovStorageOrderStudies.H
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\DBAPI.rc2
# End Source File
# Begin Source File

SOURCE=.\DBAPI.rgs
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section DBAPI : {52474554-5441-4445-2C20-4F4C45535452}
# 	1:9:IDR_DBAPI:5000
# End Section
