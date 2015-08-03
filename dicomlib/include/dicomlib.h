// dicomlib.h:
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DICOMLIB_H__A0D9D760_D195_4D70_AE75_E03B528A9637__INCLUDED_)
#define AFX_DICOMLIB_H__A0D9D760_D195_4D70_AE75_E03B528A9637__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define	INCLUDE_DICOMLIB

//#define CHECK_SOFTDOG
#define CATCH_EXCEPTION

#include <MMSYSTEM.H>
#include <AFXTEMPL.H>

#include <list>
#define	STList						std::list
#define	STListIter(x)				std::list<x>::iterator


typedef signed char					Sint8;
typedef unsigned char				Uint8;
typedef signed short				Sint16;
typedef unsigned short				Uint16;
typedef signed long					Sint32;
typedef unsigned long				Uint32;
typedef float						Float32;
typedef double						Float64;

typedef CArray<Sint16, Sint16>		SINT16_ARRAY;
typedef CArray<Uint16, Uint16>		UINT16_ARRAY;
typedef CArray<Sint32, Sint32>		SINT32_ARRAY;
typedef CArray<Uint32, Uint32>		UINT32_ARRAY;
typedef CArray<Float32, Float32>	FLOAT32_ARRAY;
typedef CArray<Float64, Float64>	FLOAT64_ARRAY;
typedef CStringArray				STRING_ARRAY;


#define	XOR(A, B)								( ((A) && !(B)) || (!(A) && (B)) )
#define	XNOR(A, B)								( ((A) && (B)) || (!(A) && !(B)) )
#define	DELETE_SAFELY(lpvTarget)				{ delete lpvTarget; lpvTarget = NULL; }
#define	MEMSET(lpvTarget, nValue, nCount)		memset((lpvTarget), (nValue), (nCount))
#define	MEMCPY(lpvTarget, lpvSource, nCount)	memcpy((lpvTarget), (lpvSource), (nCount))


#define	ERAD_DICOMLIB_VERSION_NAME			_T("DICOMLIB")
#define	ERAD_DICOMLIB_VERSION_NUMBER		_T("231")
#define	ERAD_DICOMLIB_VERSION_STRING		_T("2.3.1")

#define	ERAD_UID_ROOT						_T("1.2.840.473.8013.")
#define	ERAD_IMPLEMENTATION_CLASS_UID		ERAD_UID_ROOT ERAD_DICOMLIB_VERSION_STRING
#define	ERAD_IMPLEMENTATION_VERSION_NAME	ERAD_DICOMLIB_VERSION_NAME ERAD_DICOMLIB_VERSION_NUMBER


#define	DCM_FilePrefix				"DICM"
#define	DCM_FilePrefixLength		4
#define	DCM_FilePreambleLength		128
#define	DCM_ETS_ForFileMetaInfo		ETS_ExplicitVR
#define	DCM_ETS_ForDICOMDIR			ETS_ExplicitVR
#define	DCM_ETS_ForCommand			ETS_ImplicitVR

#define	DCM_UndefinedLength			0xFFFFFFFF
#define	DCM_UndefinedTIndex			CTIndex(0xFFFF, 0xFFFF)

#define	DCM_LOCAL_AE_TITLE			"LOCAL"


enum E_SERVICE_PRIVILEGE
{
	ESP_NONE			= 0x0000,
	ESP_C_STORE			= 0x0001,
	ESP_C_FIND			= 0x0002,
	ESP_C_GET			= 0x0004,
	ESP_C_MOVE			= 0x0008,
	ESP_C_FIND_MWL		= 0x0010,
	ESP_C_FIND_GPWL		= 0x0020,
	ESP_DICOM_PRINT		= 0x0040,
	ESP_SC_PUSH_AT_ONCE	= 0x0080,
	ESP_MASK			= 0x007F
};

enum e_streamCompression
{
	ESC_UNKNOWN		= 0,
	ESC_NONE		= 1,
	ESC_ZLIB		= 2
};

enum E_TS
{
	ETS_UNKNOWN = 0,
	ETS_ImplicitVR = 1,
	ETS_ExplicitVR,
	ETS_DeflatedExplicitVR,
	ETS_ExplicitVRBigEndian,
	ETS_JPEGBaseline50,
	ETS_JPEGExtended51,
	ETS_JPEGLossless57,
	ETS_JPEGLossless70,
	ETS_JPEGLSLossless80,
	ETS_JPEGLSLossy81,
	ETS_JPEG2000Lossless,
	ETS_JPEG2000,
	ETS_RLELossless
};

enum E_ENCAPSULATED_TS
{
	EETS_NONE,
	EETS_DeflatedExplicitVR,
	EETS_JPEG_50_51,
	EETS_JPEGLossless,
	EETS_RLELossless
};

enum E_ACCEPTABLE_TS
{
	EATS_NONE				= 0x0000,
	EATS_ImplicitVR			= 0x0001,
	EATS_ExplicitVR			= 0x0002,
	EATS_DeflatedExplicitVR	= 0x0004,
	EATS_ExplicitVRBigEndian= 0x0008,
	EATS_JPEGBaseline50		= 0x0010,
	EATS_JPEGExtended51		= 0x0020,
	EATS_JPEGLossless57		= 0x0040,
	EATS_JPEGLossless70		= 0x0080,
	EATS_JPEGLSLossless80	= 0x0100,
	EATS_JPEGLSLossy81		= 0x0200,
	EATS_JPEG2000Lossless	= 0x0400,
	EATS_JPEG2000			= 0x0800,
	EATS_RLELossless		= 0x1000,
	EATS_MASK				= 0x1FFF
};

enum E_QR_MODE							/// 
{
	EQRM_UNKNOWN,
	EQRM_PATIENT_ROOT,
	EQRM_STUDY_ROOT,
	EQRM_PATIENT_STUDY_ONLY
};

enum E_QR_LEVEL							/// (0008,0052) Query/Retrieve Level
{
	EQRL_UNKNOWN,
	EQRL_PATIENT,
	EQRL_STUDY,
	EQRL_SERIES,
	EQRL_IMAGE
};

#define	QR_PATIENT_LEVEL			"PATIENT"
#define	QR_STUDY_LEVEL				"STUDY"
#define	QR_SERIES_LEVEL				"SERIES"
#define	QR_IMAGE_LEVEL				"IMAGE"


#define	QR_AVAILABILITY_ONLINE		"ONLINE"	/// (0008,0056) Instance Availability
#define	QR_AVAILABILITY_NEARLINE	"NEARLINE"
#define	QR_AVAILABILITY_OFFLINE		"OFFLINE"
#define	QR_AVAILABILITY_UNAVAILABLE	"UNAVAILABLE"

enum E_PI								/// (0028,0004) Photometric Interpretation
{
	EPI_UNKNOWN,
	EPI_MONOCHROME1,
	EPI_MONOCHROME2,
	EPI_PALETTE_COLOR,
	EPI_RGB,
	EPI_YBR_FULL,
	EPI_YBR_FULL_422,
	EPI_YBR_PARTIAL_422,
	EPI_YBR_ICT,
	EPI_YBR_RCT
};

#define	PHOTOMETRIC_MONOCHROME1			"MONOCHROME1"
#define	PHOTOMETRIC_MONOCHROME2			"MONOCHROME2"
#define	PHOTOMETRIC_PALETTE_COLOR		"PALETTE COLOR"
#define	PHOTOMETRIC_RGB					"RGB"
#define	PHOTOMETRIC_YBR_FULL			"YBR_FULL"
#define	PHOTOMETRIC_YBR_FULL_422		"YBR_FULL_422"
#define	PHOTOMETRIC_YBR_PARTIAL_422		"YBR_PARTIAL_422"
#define	PHOTOMETRIC_YBR_ICT				"YBR_ICT"
#define	PHOTOMETRIC_YBR_RCT				"YBR_RCT"

enum E_DIRECTORY_RECORD					/// (0004,1430)	Directory Record Type
{
	EDR_UNKNOWN,
	EDR_PATIENT,
	EDR_STUDY,
	EDR_SERIES,
	EDR_IMAGE
};

#define	DR_PATIENT						"PATIENT"
#define	DR_STUDY						"STUDY"
#define	DR_SERIES						"SERIES"
#define	DR_IMAGE						"IMAGE"


#include "LOG.H"
#include "AttributeVR.h"
#include "TAG.H"
#include "UID.H"
#include "AttributeTable.h"
#include "IOstream.h"
#include "Tools.h"

#include "Element.h"
#include "ElementSet.h"

#include "ObBasic.h"
#include "RISObject.h"
#include "PrintObject.h"

#include "PDU.H"

#include "Service.h"
#include "ServiceClass.h"

#include "DCMInfo.h"
#include "ImageFile.h"

#include "CommManager.h"

#include "JDecoder.h"
#include "JDecoder08.h"
#include "JDecoder12.h"
#include "JDecoder16.h"

#include "JEncoder.h"
#include "JEncoder08.h"
#include "JEncoder12.h"
#include "JEncoder16.h"

#include "RLEDecoder.h"
#include "RLEEncoder.h"

#endif // !defined(AFX_DICOMLIB_H__A0D9D760_D195_4D70_AE75_E03B528A9637__INCLUDED_)
