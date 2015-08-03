// PrintObject.h:
//
//////////////////////////////////////////////////////////////////////

#include "ObBasic.h"
#if !defined(AFX_PRINTOBJECT_H__BAE97172_5CD8_4036_9C94_3795FE1FF701__INCLUDED_)
#define AFX_PRINTOBJECT_H__BAE97172_5CD8_4036_9C94_3795FE1FF701__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define	ST_WARNING_MEM_ALLOCATION_UNSUPPORTED	0xB600
#define	ST_WARNING_FS_PRINTING_UNSUPPORTED		0xB601
#define	ST_WARNING_FS_NO_IMAGE_BOX				0xB602
#define	ST_WARNING_FB_NO_IMAGE_BOX				0xB603
#define	ST_WARNING_IMAGE_SIZE_DEMAGNIFIED		0xB604
#define	ST_WARNING_DENSITY_OUT_OF_RANGE			0xB605
#define	ST_WARNING_IMAGE_SIZE_CROPPED			0xB609
#define	ST_WARNING_IMAGE_SIZE_DECIMATED			0xB60A

#define	ST_FAILURE_FS_NO_FILM_BOX				0xC600
#define	ST_FAILURE_FS_CREATE_PRINT_JOB			0xC601
#define	ST_FAILURE_FB_CREATE_PRINT_JOB			0xC602
#define	ST_FAILURE_IMAGE_SIZE					0xC603
#define	ST_FAILURE_INSUFFICIENT_MEM				0xC605
#define	ST_FAILURE_COMBINED_PRINT_IMAGE_SIZE	0xC613
#define	ST_FAILURE_C616							0xC616
#define	ST_FAILURE_PRINT_QUEUE_HALTED			0xC651
#define	ST_FAILURE_MISMATCH_OWNER_ID			0xC652
#define	ST_FAILURE_PRINT_JOB_IN_PROCESS			0xC653


#define	PRINT_ACTION_PRINT						1

#define PRINT_PRINT_JOB_EVENT_PENDING			1
#define PRINT_PRINT_JOB_EVENT_PRINTING			2
#define PRINT_PRINT_JOB_EVENT_DONE				3
#define PRINT_PRINT_JOB_EVENT_FAILURE			4

#define PRINT_PRINTER_EVENT_NORMAL				1
#define PRINT_PRINTER_EVENT_WARNING				2
#define PRINT_PRINTER_EVENT_FAILURE				3


#define	PRINT_QUEUE_EVENT_HALTED				1
#define	PRINT_QUEUE_EVENT_FULL					2
#define	PRINT_QUEUE_EVENT_NORMAL				3

#define	PRINT_QUEUE_ACTION_PRIORITIZE			1
#define	PRINT_QUEUE_ACTION_DELETE				2


#define PRINT_PRIORITY_HIGH						"HIGH"
#define PRINT_PRIORITY_MED						"MED"
#define PRINT_PRIORITY_LOW						"LOW"

#define	PRINT_MEDIUM_PAPER						"PAPER"
#define	PRINT_MEDIUM_CLEAR_FILM					"CLEAR FILM"
#define	PRINT_MEDIUM_BLUE_FILM					"BLUE FILM"
#define	PRINT_MEDIUM_MAMMO_CLEAR_FILM			"MAMMO CLEAR FILM"
#define	PRINT_MEDIUM_MAMMO_BLUE_FILM			"MAMMO BLUE FILM"

#define	PRINT_FILE_DESTINATION_MAGAZINE			"MAGAZINE"
#define	PRINT_FILE_DESTINATION_PROCESSOR		"PROCESSOR"
#define	PRINT_FILE_DESTINATION_BIN_				"BIN_"

#define	PRINT_IMAGE_FORMAT_STANDARD_			"STANDARD\\"
#define	PRINT_IMAGE_FORMAT_ROW_					"ROW\\"
#define	PRINT_IMAGE_FORMAT_COL_					"COL\\"
#define	PRINT_IMAGE_FORMAT_SLIDE				"SLIDE"
#define	PRINT_IMAGE_FORMAT_SUPERSLIDE			"SUPERSLIDE"
#define	PRINT_IMAGE_FORMAT_CUSTOM_				"CUSTOM\\"

#define	PRINT_FILM_ORIENTATION_PORTRAIT			"PORTRAIT"
#define	PRINT_FILM_ORIENTATION_LANDSCAPE		"LANDSCAPE"

#define	PRINT_FILM_SIZE_8INX10IN				"8INX10IN"
#define	PRINT_FILM_SIZE_8_5INX11IN				"8_5INX11IN"
#define	PRINT_FILM_SIZE_10INX12IN				"10INX12IN"
#define	PRINT_FILM_SIZE_10INX14IN				"10INX14IN"
#define	PRINT_FILM_SIZE_11INX14IN				"11INX14IN"
#define	PRINT_FILM_SIZE_11INX17IN				"11INX17IN"
#define	PRINT_FILM_SIZE_14INX14IN				"14INX14IN"
#define	PRINT_FILM_SIZE_14INX17IN				"14INX17IN"
#define	PRINT_FILM_SIZE_24CMX24CM				"24CMX24CM"
#define	PRINT_FILM_SIZE_24CMX30CM				"24CMX30CM"
#define	PRINT_FILM_SIZE_A4						"A4"
#define	PRINT_FILM_SIZE_A3						"A3"

#define	PRINT_MAGNIFICATION_REPLICATE			"REPLICATE"
#define	PRINT_MAGNIFICATION_BILINEAR			"BILINEAR"
#define	PRINT_MAGNIFICATION_CUBIC				"CUBIC"
#define	PRINT_MAGNIFICATION_NONE				"NONE"

#define	PRINT_DENSITY_BLACK						"BLACK"
#define	PRINT_DENSITY_WHITE						"WHITE"

#define	PRINT_TRIM_YES							"YES"
#define	PRINT_TRIM_NO							"NO"

#define	PRINT_RESOLUTION_STANDARD				"STANDARD"
#define	PRINT_RESOLUTION_HIGH					"HIGH"

#define	PRINT_POLARITY_NORMAL					"NORMAL"
#define	PRINT_POLARITY_REVERSE					"REVERSE"

#define	PRINT_DECIMATE_CROP_DECIMATE			"DECIMATE"
#define	PRINT_DECIMATE_CROP_CROP				"CROP"
#define	PRINT_DECIMATE_CROP_FAIL				"FAIL"

#define	PRINT_STATUS_PENDING					"PENDING"
#define	PRINT_STATUS_PRINTING					"PRINTING"
#define	PRINT_STATUS_DONE						"DONE"
#define	PRINT_STATUS_FAILURE					"FAILURE"

#define	PRINT_STATUS_INFO_NORMAL				"NORMAL"
#define	PRINT_STATUS_INFO_INVALID_PAGE_DES		"INVALID PAGE DES"
#define	PRINT_STATUS_INFO_INSUFFIC_MEMORY		"INSUFFIC MEMORY"

#define	PRINT_PRINTER_STATUS_NORMAL				"NORMAL"
#define	PRINT_PRINTER_STATUS_WARNING			"WARNING"
#define	PRINT_PRINTER_STATUS_FAILURE			"FAILURE"

#define	PRINT_IMAGE_SIZE_FLAG_NO				"NO"
#define	PRINT_IMAGE_SIZE_FLAG_YES				"YES"

#define	PRINT_REQUESTED_IMAGE_SIZE_NO			"NO"
#define	PRINT_REQUESTED_IMAGE_SIZE_YES			"YES"

#define	PRINT_DECIMATE_CROP_RESULT_DECIMATE		"DECIMATE"
#define	PRINT_DECIMATE_CROP_RESULT_CROP			"CROP"
#define	PRINT_DECIMATE_CROP_RESULT_FAIL			"FAIL"
#define	PRINT_DECIMATE_CROP_RESULT_DEF_DECIMATE	"DEF DECIMATE"
#define	PRINT_DECIMATE_CROP_RESULT_DEF_CROP		"DEF CROP"
#define	PRINT_DECIMATE_CROP_RESULT_DEF_FAIL		"DEF FAIL"

#define PRINT_PRES_LUT_SHAPE_IDENTITY			"IDENTITY"
#define PRINT_PRES_LUT_SHAPE_LIN_OD				"LIN OD"

#define	PRINT_MAGNIFICATION_IMAGE				"IMAGE"
#define	PRINT_MAGNIFICATION_OVERLAY				"OVERLAY"

#define	PRINT_QUEUE_STATUS_NORMAL				"NORMAL"
#define	PRINT_QUEUE_STATUS_FULL					"FULL"
#define	PRINT_QUEUE_STATUS_HALTED				"HALTED"


class CObProposedStudyItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObProposedStudyItem)

public:
	CString				m_strPatientName;		// (0010,0010)	Patient's Name
	CString				m_strPatientID;			// (0010,0020)	Patient ID
	CString				m_strPatientDOB;		// (0010,0030)	Patient's Birth Date
	CString				m_strPatientSex;		// (0010,0040)	Patient's Sex
	CString				m_strBirthTime;			// (0010,0032)	Patient's Birth Time
	CString				m_strOtherPatientID;	// (0010,1000)	Other Patient IDs
	CString				m_strOtherPatientName;	// (0010,1001)	Other Patient Names
	CString				m_strEthnicGroup;		// (0010,2160)	Ethnic Group
	CString				m_strPatComments;		// (0010,4000)	Patient Comments
	CString				m_strStudyInstUID;		// (0020,000D)	Study Instance UID
	CString				m_strStudyDate;			// (0008,0020)	Study Date
	CString				m_strStudyTime;			// (0008,0030)	Study Time
	CString				m_strReferName;			// (0008,0090)	Referring Physician's Name
	CString				m_strStudyID;			// (0020,0010)	Study ID
	CString				m_strAccessionNumber;	// (0008,0050)	Accession Number
	CString				m_strStudyDescription;	// (0008,1030)	Study Description
	CString				m_strReader;			// (0008,1060)	Name of Physician (s) Reading Study
	CString				m_strAdmDiagDesc;		// (0008,1080)	Admitting Diagnoses Description
	CString				m_strPatientAge;		// (0010,1010)	Patient's Age
	CString				m_strPatSize;			// (0010,1020)	Patient's Size
	CString				m_strPatWeight;			// (0010,1030)	Patient's Weight
	CString				m_strOccupation;		// (0010,2180)	Occupation
	CString				m_strPatHistory;		// (0010,21B0)	Additional Patient History
	CString				m_strSeriesNumber;		// (0020,0011)	Series Number

public:
	CObProposedStudyItem();
	virtual ~CObProposedStudyItem();
};

typedef CTypedPtrArray<CObSQ, CObProposedStudyItem*> CObProposedStudySQ;


class CObFilmSession : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObFilmSession)

public:
	CString				m_strCopies;			// (2000,0010)	Number of Copies
	CString				m_strPriority;			// (2000,0020)	Print Priority
	CString				m_strMedium;			// (2000,0030)	Medium Type
	CString				m_strFilmDestination;	// (2000,0040)	Film Destination
	CString				m_strFilmSessionLabel;	// (2000,0050)	Film Session Label
	CString				m_strMemAllocation;		// (2000,0060)	Memory Allocation
	CString				m_strOwner;				// (2100,0160)	Owner ID
	CObRefInstanceSQ	m_SQFilmBoxInstance;	// (2000,0500)	Referenced Film Box Sequence
	CObProposedStudySQ	m_SQProposedStudy;		// (2130,00A0)	Proposed Study Sequence

public:
	CObFilmSession();
	virtual ~CObFilmSession();
};


class CObFilmBox : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObFilmBox)

public:
	CString				m_strImageFormat;		// (2010,0010)	Image Display Format
	CString				m_strAnnotationFormat;	// (2010,0030)	Annotation Display Format ID
	CString				m_strFilmOrientation;	// (2010,0040)	Film Orientation
	CString				m_strFilmSize;			// (2010,0050)	Film Size ID
	CString				m_strMagnification;		// (2010,0060)	Magnification Type
	CString				m_strSmoothing;			// (2010,0080)	Smoothing Type
	CString				m_strBorderDensity;		// (2010,0100)	Border Density
	CString				m_strEmptyImageDensity;	// (2010,0110)	Empty Image Density
	Uint16				m_nMinDensity;			// (2010,0120)	Min Density
	Uint16				m_nMaxDensity;			// (2010,0130)	Max Density
	CString				m_strTrim;				// (2010,0140)	Trim
	CString				m_strConfiguration;		// (2010,0150)	Configuration Information
	Uint16				m_nIllumination;		// (2010,015E)	Illumination
	Uint16				m_nAmbientLight;		// (2010,0160)	Reflected Ambient Light
	CString				m_strRequestResolution;	// (2020,0050)	Requested Resolution ID
	CObRefInstanceSQ	m_SQFilmSessionInstance;// (2010,0500)	Referenced Film Session Sequence
	CObRefInstanceSQ	m_SQImageBoxInstance;	// (2010,0510)	Referenced Image Box Sequence
	CObRefInstanceSQ	m_SQAnnotationInstance;	// (2010,0520)	Referenced Basic Annotation Box Sequence
	CObRefInstanceSQ	m_SQPresLUTInstance;	// (2050,0500)	Referenced Presentation LUT Sequence

public:
	CObFilmBox();
	virtual ~CObFilmBox();
};


class CObGrayscaleImageItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObGrayscaleImageItem)

public:
	Uint16				m_nSamplesPerPixel;		// Samples per Pixel
	CString				m_strPhotometric;		// Photometric Interpretation
	Uint16				m_nRows;				// Rows
	Uint16				m_nColumns;				// Columns
	CString				m_strPixelAspectRatio;	// Pixel Aspect Ratio
	Uint16				m_nBitsAllocated;		// Bits Allocated
	Uint16				m_nBitsStored;			// Bits Stored
	Uint16				m_nHighBit;				// High Bit
	Uint16				m_nPixelRepresentation;	// Pixel Representation

public:
	CObGrayscaleImageItem();
	virtual ~CObGrayscaleImageItem();
};

typedef CTypedPtrArray<CObSQ, CObGrayscaleImageItem*> CObGrayscaleImageSQ;


class CObColorImageItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObColorImageItem)

public:
	Uint16				m_nSamplesPerPixel;		// Samples per Pixel
	CString				m_strPhotometric;		// Photometric Interpretation
	Uint16				m_nPlanarConfiguration;	// Planar Configuration
	Uint16				m_nRows;				// Rows
	Uint16				m_nColumns;				// Columns
	CString				m_strPixelAspectRatio;	// Pixel Aspect Ratio
	Uint16				m_nBitsAllocated;		// Bits Allocated
	Uint16				m_nBitsStored;			// Bits Stored
	Uint16				m_nHighBit;				// High Bit
	Uint16				m_nPixelRepresentation;	// Pixel Representation

public:
	CObColorImageItem();
	virtual ~CObColorImageItem();
};

typedef CTypedPtrArray<CObSQ, CObColorImageItem*> CObColorImageSQ;


class CObOriginalImageItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObOriginalImageItem)

public:
	CString				m_strStudyInstUID;		// Study Instance UID
	CString				m_strSeriesInstUID;		// Series Instance UID
	CString				m_strPatientID;			// Patient ID
	CString				m_strSOPClassUID;		// SOP Class UID
	CString				m_strSOPInstUID;		// SOP Instance UID
	CString				m_strFrameNumber;		// Referenced Frame Number
	CString				m_strImageNumber;		// Instance Number

public:
	CObOriginalImageItem();
	virtual ~CObOriginalImageItem();
};

typedef CTypedPtrArray<CObSQ, CObOriginalImageItem*> CObOriginalImageSQ;


class CObFilmImage : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObFilmImage)

public:
	Uint16				m_nImagePosition;		// (2020,0010)	Image Position
	CString				m_strPolarity;			// (2020,0020)	Polarity
	CString				m_strMagnification;		// (2010,0060)	Magnification Type
	CString				m_strSmoothing;			// (2010,0080)	Smoothing Type
	CString				m_strConfiguration;		// (2010,0150)	Configuration Information
	CString				m_strImageSize;			// (2020,0030)	Requested Image Size
	CString				m_strDecimateCrop;		// (2020,0040)	Requested Decimate/Crop Behavior
	CObGrayscaleImageSQ	m_SQGrayscaleImage;		// (2020,0110)	Basic Grayscale Image Sequence
	CObColorImageSQ		m_SQColorImage;			// (2020,0111)	Basic Color Image Sequence
	CObRefInstanceSQ	m_SQOverlayBoxInstance;	// (2020,0130)	Referenced Image Overlay Box Sequence
	CObOriginalImageSQ	m_SQOriginalImage;		// (2130,00C0)	Original Image Sequence

public:
	CObFilmImage();
	virtual ~CObFilmImage();
};


class CObAnnotationBox : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObAnnotationBox)

public:
	Uint16				m_nAnnotationPosition;	// (2030,0010)	Annotation Position
	CString				m_strTextString;		// (2030,0020)	Text String

public:
	CObAnnotationBox();
	virtual ~CObAnnotationBox();
};


class CObPrintJob : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObPrintJob)

public:
	CString				m_strStatus;			// (2100,0020)	Execution Status
	CString				m_strStatusInfo;		// (2100,0030)	Execution Status Info
	CString				m_strCreationDate;		// (2100,0040)	Creation Date
	CString				m_strCreationTime;		// (2100,0050)	Creation Time
	CString				m_strPriority;			// (2000,0020)	Print Priority
	CString				m_strPrinterName;		// (2110,0030)	Printer Name
	CString				m_strOriginator;		// (2100,0070)	Originator

public:
	CObPrintJob();
	virtual ~CObPrintJob();
};


class CObPrinter : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObPrinter)

public:
	CString				m_strStatus;			// (2110,0010)	Printer Status
	CString				m_strStatusInfo;		// (2110,0020)	Printer Status Info
	CString				m_strPrinterName;		// (2110,0030)	Printer Name
	CString				m_strManufacturer;		// (0008,0070)	Manufacturer
	CString				m_strModelName;			// (0008,1090)	Manufacturer Model Name
	CString				m_strSerialNumber;		// (0018,1000)	Device Serial Number
	STRING_ARRAY		m_SoftwareVersions;		// (0018,1020)	Software Versions
	STRING_ARRAY		m_CalibrationDate;		// (0018,1200)	Date Of Last Calibration
	STRING_ARRAY		m_CalibrationTime;		// (0018,1201)	Time Of Last Calibration

public:
	CObPrinter();
	virtual ~CObPrinter();
};


class CObInstalledMediaItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObInstalledMediaItem)

public:
	CString				m_strItemNumber;		// (0020,0019)	Item Number
	CString				m_strMedium;			// (2000,0030)	Medium Type
	CString				m_strFilmSize;			// (2010,0050)	Film Size ID
	Uint16				m_nMinDensity;			// (2010,0120)	Min Density
	Uint16				m_nMaxDensity;			// (2010,0130)	Max Density

public:
	CObInstalledMediaItem();
	virtual ~CObInstalledMediaItem();
};

typedef CTypedPtrArray<CObSQ, CObInstalledMediaItem*> CObInstalledMediaSQ;


class CObAvailableMediaItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObAvailableMediaItem)

public:
	CString				m_strMedium;			// (2000,0030)	Medium Type
	CString				m_strFilmSize;			// (2010,0050)	Film Size ID
	Uint16				m_nMinDensity;			// (2010,0120)	Min Density
	Uint16				m_nMaxDensity;			// (2010,0130)	Max Density

public:
	CObAvailableMediaItem();
	virtual ~CObAvailableMediaItem();
};

typedef CTypedPtrArray<CObSQ, CObAvailableMediaItem*> CObAvailableMediaSQ;


class CObImageFormatItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObImageFormatItem)

public:
	Uint16				m_nRows;				// (0028,0010)	Rows
	Uint16				m_nColumns;				// (0028,0011)	Columns
	CString				m_strImageFormat;		// (2010,0010)	Image Display Format
	CString				m_strFilmOrientation;	// (2010,0040)	Film Orientation
	CString				m_strFilmSize;			// (2010,0050)	Film Size ID
	CString				m_strResolutionID;		// (2010,0052)	Printer Resolution ID
	STRING_ARRAY		m_PixelSpacing;			// (2010,0376)	Printer Pixel Spacing
	CString				m_strRequestedImageSize;// (2020,00A0)	Requested Image Size Flag

public:
	CObImageFormatItem();
	virtual ~CObImageFormatItem();
};

typedef CTypedPtrArray<CObSQ, CObImageFormatItem*> CObImageFormatSQ;


class CObConfigurationItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObConfigurationItem)

public:
	STRING_ARRAY		m_SOPClasses;			// (0008,115A)	SOP Classes Supported
	CString				m_strMemAllocation;		// (2000,0061)	Maximum Memory Allocation
	Uint16				m_nMemoryBitDepth;		// (2000,00A0)	Memory Bit Depth
	Uint16				m_nPrintingBitDepth;	// (2000,00A1)	Printing Bit Depth
	CObInstalledMediaSQ	m_SQInstalledMedia;		// (2000,00A2)	Media Installed Sequence
	CObAvailableMediaSQ	m_SQAvailableMedia;		// (2000,00A4)	Other Media Available Sequence
	CObImageFormatSQ	m_SQImageFormats;		// (2000,00A8)	Supported Image Display Formats Sequence
	CString				m_strResolution;		// (2010,0054)	Default Printer Resolution ID
	CString				m_strMagnification;		// (2010,00A6)	Default Magnification Type
	STRING_ARRAY		m_OtherMagnification;	// (2010,00A7)	Other Magnification Types Available
	CString				m_strSmoothing;			// (2010,00A8)	Default Smoothing Type
	STRING_ARRAY		m_OtherSmoothing;		// (2010,00A9)	Other Smoothing Types Available
	CString				m_strConfigurationInfo;	// (2010,0152)	Configuration Information Description
	CString				m_strCollatedFilms;		// (2010,0154)	Maximum Collated Films
	CString				m_strDecimateCrop;		// (2020,00A2)	Decimate/Crop Result

public:
	CObConfigurationItem();
	virtual ~CObConfigurationItem();
};

typedef CTypedPtrArray<CObSQ, CObConfigurationItem*> CObConfigurationSQ;


class CObPrinterConfiguration : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObPrinterConfiguration)

public:
	CObConfigurationSQ	m_SQPrinterConfiguration;// (2000,001E)	Printer Configuration Sequence

public:
	CObPrinterConfiguration();
	virtual ~CObPrinterConfiguration();
};


class CObPrintJobItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObPrintJobItem)

public:
	CString				m_strPrintJob;			// (2100,0010)	Print Job ID
	CString				m_strStatus;			// (2100,0020)	Execution Status
	CString				m_strStatusInfo;		// (2100,0030)	Execution Status Info
	CString				m_strCreationDate;		// (2100,0040)	Creation Date
	CString				m_strCreationTime;		// (2100,0050)	Creation Time
	CString				m_strPriority;			// (2000,0020)	Print Priority
	CString				m_strOriginator;		// (2100,0070)	Originator
	CString				m_strDestinationAE;		// (2100,0140)	Destination AE
	CString				m_strPrinterName;		// (2110,0030)	Printer Name
	CString				m_strFilmDestination;	// (2000,0040)	Film Destination
	CString				m_strFilmSessionLabel;	// (2000,0050)	Film Session Label
	CString				m_strOwner;				// (2100,0160)	Owner ID
	CString				m_strMedium;			// (2000,0030)	Medium Type
	CString				m_strFilmsNumber;		// (2100,0170)	Number of Films
	CObRefInstanceSQ	m_SQPrintJobInstance;	// (2120,0070)	Referenced Print Job Sequence

public:
	CObPrintJobItem();
	virtual ~CObPrintJobItem();
};

typedef CTypedPtrArray<CObSQ, CObPrintJobItem*> CObPrintJobSQ;


class CObPrintQueue : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObPrintQueue)

public:
	CString				m_strQueueStatus;		// (2120,0010)	Queue Status
	CObPrintJobSQ		m_SQPrintJob;			// (2120,0050)	Print Job Description Sequence

public:
	CObPrintQueue();
	virtual ~CObPrintQueue();
};


class CObPresLutItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObPresLutItem)

public:
	CString				m_strLutExplanation;	// (0028,3003)	LUT Explanation

public:
	CObPresLutItem();
	virtual ~CObPresLutItem();
};

typedef CTypedPtrArray<CObSQ, CObPresLutItem*> CObPresLutSQ;


class CObPresLut : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObPresLut)

public:
	CObPresLutSQ		m_SQPresLut;			// (2050,0010)	Presentation LUT Sequence
	CString				m_strPresLutShape;		// (2050,0020)	Presentation LUT Shape

public:
	CObPresLut();
	virtual ~CObPresLut();
};


class CObPrintOverlItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObPrintOverlItem)

public:
	Uint16				m_nRows;				// (6000,0010) Overlay Rows
	Uint16				m_nColumns;				// (6000,0011) Overlay Columns
	SINT16_ARRAY		m_Origin;				// (6000,0050) Overlay Origin
	Uint16				m_nBitsAllocated;		// (6000,0100) Overlay Bits Allocated
	Uint16				m_nBitPosition;			// (6000,0102) Overlay Bit Position

public:
	CObPrintOverlItem();
	virtual ~CObPrintOverlItem();
};

typedef CTypedPtrArray<CObSQ, CObPrintOverlItem*> CObPrintOverlSQ;


class CObPrintOverl : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObPrintOverl)

public:
	CObPrintOverlSQ		m_PrintOverl;			// (2040,0020)	Overlay Pixel Data Sequence
	CString				m_strMagnification;		// (2040,0060)	Overlay Magnification Type
	CString				m_strSmoothing;			// (2040,0070)	Overlay Smoothing Type
	CString				m_strOverlayImage;		// (2040,0072)	Overlay or Image Magnification
	Uint16				m_nMagnifyToColumns;	// (2040,0074)	Magnify to Number of Columns
	CString				m_strForegroundDensity;	// (2040,0080)	Overlay Foreground Density
	CString				m_strBackgroundDensity;	// (2040,0082)	Overlay Background Density

public:
	CObPrintOverl();
	virtual ~CObPrintOverl();
};

#endif // !defined(AFX_PRINTOBJECT_H__BAE97172_5CD8_4036_9C94_3795FE1FF701__INCLUDED_)
