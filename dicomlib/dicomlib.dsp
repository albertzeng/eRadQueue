# Microsoft Developer Studio Project File - Name="dicomlib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=dicomlib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "dicomlib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "dicomlib.mak" CFG="dicomlib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "dicomlib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "dicomlib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "dicomlib - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "dicomlib - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "dicomlib - Win32 Release"
# Name "dicomlib - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\include\AttributeTable.h
# End Source File
# Begin Source File

SOURCE=.\include\AttributeVR.h
# End Source File
# Begin Source File

SOURCE=.\include\CoImage.h
# End Source File
# Begin Source File

SOURCE=.\include\CommManager.h
# End Source File
# Begin Source File

SOURCE=.\include\DCMInfo.h
# End Source File
# Begin Source File

SOURCE=.\include\DIBImage.h
# End Source File
# Begin Source File

SOURCE=.\include\dicomlib.h
# End Source File
# Begin Source File

SOURCE=.\include\Element.h
# End Source File
# Begin Source File

SOURCE=.\include\ElementSet.h
# End Source File
# Begin Source File

SOURCE=.\include\ImageFile.h
# End Source File
# Begin Source File

SOURCE=.\include\IOstream.h
# End Source File
# Begin Source File

SOURCE=.\include\IPixel.h
# End Source File
# Begin Source File

SOURCE=.\include\IPixelTemplate.h
# End Source File
# Begin Source File

SOURCE=.\include\JDecoder.h
# End Source File
# Begin Source File

SOURCE=.\include\JDecoder08.h
# End Source File
# Begin Source File

SOURCE=.\include\JDecoder12.h
# End Source File
# Begin Source File

SOURCE=.\include\JDecoder16.h
# End Source File
# Begin Source File

SOURCE=.\include\JEncoder.h
# End Source File
# Begin Source File

SOURCE=.\include\JEncoder08.h
# End Source File
# Begin Source File

SOURCE=.\include\JEncoder12.h
# End Source File
# Begin Source File

SOURCE=.\include\JEncoder16.h
# End Source File
# Begin Source File

SOURCE=.\include\LibImage.h
# End Source File
# Begin Source File

SOURCE=.\include\LOG.h
# End Source File
# Begin Source File

SOURCE=.\include\LUTBasic.h
# End Source File
# Begin Source File

SOURCE=.\include\LUTModalities.h
# End Source File
# Begin Source File

SOURCE=.\include\MCoPixelTemplate.h
# End Source File
# Begin Source File

SOURCE=.\include\MMoPixelTemplate.h
# End Source File
# Begin Source File

SOURCE=.\include\MoImage.h
# End Source File
# Begin Source File

SOURCE=.\include\MPixel.h
# End Source File
# Begin Source File

SOURCE=.\include\ObBasic.h
# End Source File
# Begin Source File

SOURCE=.\include\OPixel.h
# End Source File
# Begin Source File

SOURCE=.\include\OPixelTemplate.h
# End Source File
# Begin Source File

SOURCE=.\include\Overls.h
# End Source File
# Begin Source File

SOURCE=.\include\PDU.h
# End Source File
# Begin Source File

SOURCE=.\include\PixelTemplate.h
# End Source File
# Begin Source File

SOURCE=.\include\PrintObject.h
# End Source File
# Begin Source File

SOURCE=.\include\RADImage.h
# End Source File
# Begin Source File

SOURCE=.\include\RISObject.h
# End Source File
# Begin Source File

SOURCE=.\include\RLEDecoder.h
# End Source File
# Begin Source File

SOURCE=.\include\RLEEncoder.h
# End Source File
# Begin Source File

SOURCE=.\include\Service.h
# End Source File
# Begin Source File

SOURCE=.\include\ServiceClass.h
# End Source File
# Begin Source File

SOURCE=.\include\TAG.h
# End Source File
# Begin Source File

SOURCE=.\include\Tools.h
# End Source File
# Begin Source File

SOURCE=.\include\UID.h
# End Source File
# End Group
# End Target
# End Project
