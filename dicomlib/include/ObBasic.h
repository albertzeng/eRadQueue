// ObBasic.h: interface for the CObBasic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBBASIC_H__0B13A10C_71D0_4801_9076_4A4FF4554167__INCLUDED_)
#define AFX_OBBASIC_H__0B13A10C_71D0_4801_9076_4A4FF4554167__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CObBasic : public CObject  
{
public:
	CElementSet*	m_pElementSet;

protected:
	DECLARE_DYNAMIC(CObBasic);

	struct CMember
	{
		Uint16			nGNumber;
		Uint16			nENumber;
		E_VR			eVR;
		LPVOID			lpvMember;
		BOOL			bHas;
		BOOL			bHasValue;
		CRuntimeClass*	pClass;
		enum {
			MEMBER_SINT16,
			MEMBER_UINT16,
			MEMBER_SINT32,
			MEMBER_UINT32,
			MEMBER_FLOAT32,
			MEMBER_FLOAT64,
			MEMBER_STRING,
			MEMBER_SINT16_ARRAY,
			MEMBER_UINT16_ARRAY,
			MEMBER_SINT32_ARRAY,
			MEMBER_UINT32_ARRAY,
			MEMBER_FLOAT32_ARRAY,
			MEMBER_FLOAT64_ARRAY,
			MEMBER_STRING_ARRAY,
			MEMBER_SQ,
		} eFormat;
	};

	CArray<CMember, CMember> m_MemberTable;

protected:
	virtual MRET	BuildMemberTable()	{ return ME_OK; }

public:
			MRET	LoadMembers()		{ return this->LoadMembers(this->m_pElementSet); }
			MRET	LoadMembers(CElementSet* pElementSet);
			MRET	SaveMembers(BOOL bReplace = FALSE);
			MRET	SaveMembers(CElementSet* pElementSet, BOOL bReplace = FALSE);
			MRET	GetTXT(CString& strTXT, CString strPrefix);
			BOOL	Has(LPVOID lpvMember);
			BOOL	HasValue(LPVOID lpvMember);
			MRET	SetMask(LPVOID lpvMember);
			MRET	SetValueMask(LPVOID lpvMember);
			MRET	SetAllMask();
			MRET	ResetMask(LPVOID lpvMember);
			MRET	ResetValueMask(LPVOID lpvMember);
			MRET	ResetAllMask();
			MRET	SetAllMask(UINT16_ARRAY* pMaskTable);
			MRET	SetAllValueMask(UINT16_ARRAY* pMaskTable);
			MRET	SetAllMask(CObBasic* pDataObject);
			MRET	GetAllMask(UINT16_ARRAY* pMaskTable);

public:
	CObBasic();
	virtual ~CObBasic();
};

#define DECLARE_MEMBER_TABLE(thisClass)								\
protected:															\
	DECLARE_DYNCREATE(thisClass)									\
	virtual MRET BuildMemberTable();								\

#define BEGIN_MEMBER_TABLE(thisClass, baseClass)					\
IMPLEMENT_DYNCREATE(thisClass, baseClass)							\
																	\
MRET thisClass::BuildMemberTable()									\
{																	\

#define ATTRIBUTE(GNumber, ENumber, thisVR, thisFormat, thisMember)	\
	{																\
		CMember theMember;											\
		theMember.nGNumber	= 0x##GNumber;							\
		theMember.nENumber	= 0x##ENumber;							\
		theMember.eVR		= EVR_##thisVR;							\
		theMember.lpvMember	= (LPVOID) &this->thisMember;			\
		theMember.bHas		= FALSE;								\
		theMember.bHasValue	= FALSE;								\
		theMember.pClass	= NULL;									\
		theMember.eFormat	= CMember::MEMBER_##thisFormat;			\
		this->m_MemberTable.Add(theMember);							\
	}																\

#define SEQUENCE(GNumber, ENumber, thisClass, thisMember)			\
	{																\
		CMember theMember;											\
		theMember.nGNumber	= 0x##GNumber;							\
		theMember.nENumber	= 0x##ENumber;							\
		theMember.eVR		= EVR_SQ;								\
		theMember.lpvMember	= (LPVOID) &this->thisMember;			\
		theMember.bHas		= FALSE;								\
		theMember.bHasValue	= FALSE;								\
		theMember.pClass	= RUNTIME_CLASS(thisClass);				\
		theMember.eFormat	= CMember::MEMBER_SQ;					\
		this->m_MemberTable.Add(theMember);							\
	}																\

#define END_MEMBER_TABLE()											\
	return ME_OK;													\
};																	\


class CObSQ : public CTypedPtrArray<CPtrArray, CObBasic*>
{
public:
	CObSQ();
	virtual ~CObSQ();
};


class CObCommand : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObCommand)

public:
	CString			m_strAffectedClass;		// Affected SOP Class UID
	CString			m_strRequestedClass;	// Requested SOP Class UID
	Uint16			m_nCommandField;		// Command Field
	Uint16			m_nMessageID;			// Message ID
	Uint16			m_nMessageResponded;	// Message ID Being Responded To
	CString			m_strMoveDestination;	// Move Destination
	Uint16			m_nPriority;			// Priority
	Uint16			m_nDataSetType;			// Data Set Type
	Uint16			m_nStatus;				// Status
	UINT16_ARRAY	m_OffendingElement;		// Offending Element
	CString			m_strErrorComment;		// Error Comment
	Uint16			m_nErrorID;				// Error ID
	CString			m_strAffected;			// Affected SOP Instance UID
	CString			m_strRequested;			// Requested SOP Instance UID
	Uint16			m_nEventTypeID;			// Event Type ID
	UINT16_ARRAY	m_IdentifierList;		// Attribute Identifier List
	Uint16			m_nActionTypeID;		// Action Type ID
	Uint16			m_nRemaining;			// Number of Remaining Sub-operations
	Uint16			m_nCompleted;			// Number of Completed Sub-operations
	Uint16			m_nFailed;				// Number of Failed Sub-operations
	Uint16			m_nWarning;				// Number of Warning Sub-operations
	CString			m_strMoveOrigAETitle;	// Move Originator Application Entity Title
	Uint16			m_nMoveOrigMessageID;	// Move Originator Message ID

public:
	CObCommand();
	virtual ~CObCommand();
};


class CObFileHeader : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObFileHeader)

public:
	Uint16			m_nVersion;				// File Meta Information Version
	CString			m_strSOPClassUID;		// Media Storage SOP Class UID
	CString			m_strSOPInstUID;		// Media Storage SOP Instance UID
	CString			m_strTransferSyntax;	// Transfer Syntax UID
	CString			m_strImpClassUID;		// Implementation Class UID
	CString			m_strImpVersionName;	// Implementation Version Name
	CString			m_strSourceAETitle;		// Source Application Entity Title

public:
	MRET			CalculateLength	(Uint32& nLength);
	MRET			Built			(COstream* pIOstream);
	MRET			Parse			(CIstream* pIOstream);

public:
	CObFileHeader();
	virtual ~CObFileHeader();
};


class CObRefInstanceItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObRefInstanceItem)

public:
	CString			m_strSOPClassUID;
	CString			m_strSOPInstUID;

public:
	CObRefInstanceItem();
	virtual ~CObRefInstanceItem();
};


typedef CTypedPtrArray<CObSQ, CObRefInstanceItem*> CObRefInstanceSQ;


class CObImage : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObImage)

public:
	CString			m_strSOPClassUID;		// SOP Class UID
	CString			m_strSOPInstUID;		// SOP Instance UID
	CString			m_strPatientName;		// Patient's Name
	CString			m_strPatientID;			// Patient ID
	CString			m_strPatientDOB;		// Patient's Birth Date
	CString			m_strPatientSex;		// Patient's Sex
	CString			m_strOtherPatientID;	// Other Patient IDs
	CString			m_strOtherPatientName;	// Other Patient Names
	CString			m_strStudyInstUID;		// Study Instance UID
	CString			m_strStudyDate;			// Study Date
	CString			m_strStudyTime;			// Study Time
	CString			m_strStudyID;			// Study ID
	CString			m_strAccessionNumber;	// Accession Number
	CString			m_strStudyDescription;	// Study Description
	CString			m_strPatientAge;		// Patient's Age
	CString			m_strPatientSize;		// Patient's Size
	CString			m_strPatientWeight;		// Patient's Weight
	CString			m_strOccupation;		// Occupation
	CString			m_strModality;			// Modality
	CString			m_strSeriesInstUID;		// Series Instance UID
	CString			m_strSeriesNumber;		// Series Number
	CString			m_strSeriesDate;		// Series Date
	CString			m_strSeriesTime;		// Series Time
	CString			m_strBodyPart;			// Body Part Examined
	CString			m_strImageNumber;		// Instance Number
	CString			m_strImageDate;			// Content Date
	CString			m_strImageTime;			// Content Time
	Uint16			m_nSamplesPerPixel;		// Samples per Pixel
	CString			m_strPhotometric;		// Photometric Interpretation
	Uint16			m_nPlanarConfiguration;	// Planar Configuration
	Uint16			m_nRows;				// Rows
	Uint16			m_nColumns;				// Columns
	Uint16			m_nBitsAllocated;		// Bits Allocated
	Uint16			m_nBitsStored;			// Bits Stored
	Uint16			m_nHighBit;				// High Bit
	Uint16			m_nPixelRepresentation;	// Pixel Representation
	CString			m_strFrameTime;			// Frame Time
	CString			m_strCineRate;			// Cine Rate
	CString			m_strFrameNumber;		// Number of Frames
	UINT16_ARRAY	m_IncrementPointer;		// Frame Increment Pointer
	CString			m_strSeriesFrameUID;	// Frame of Reference UID
	CString			m_strImagePosition;		// Image Position (Patient)
	CString			m_strImageOrientation;	// Image Orientation (Patient)
	CString			m_strPixelSpacing;		// Pixel Spacing
	CString			m_strImagerPixelSpacing;// Imager Pixel Spacing

public:
	CObImage();
	virtual ~CObImage();
};


class CObQR : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObQR)

public:
	CString				m_strLevel;				// Query/Retrieve Level
	STRING_ARRAY		m_RetrieveAETitle;		// Retrieve AE Title
	CString				m_strFileSetID;			// Storage Media File-Set ID
	CString				m_strFileSetUID;		// Storage Media File-Set UID
	CString				m_strAvailability;		// Instance Availability

	CString				m_strPatientName;		// Patient's Name
	CString				m_strPatientID;			// Patient ID
	CString				m_strPatientDOB;		// Patient's Birth Date
	CString				m_strPatientSex;		// Patient's Sex
	CString				m_strPatientStudy;		// Number of Patient Related Studies
	CString				m_strPatientSeries;		// Number of Patient Related Series
	CString				m_strPatientImage;		// Number of Patient Related Instances

	CString				m_strAccessionNumber;	// Accession Number
	STRING_ARRAY		m_StudyInstUID;			// Study Instance UID
	CString				m_strStudyDate;			// Study Date
	CString				m_strStudyTime;			// Study Time
	CString				m_strStudyID;			// Study ID
	CString				m_strStudyDescription;	// Study Description
	STRING_ARRAY		m_StudyModality;		// Modalities in Study
	CString				m_strStudySeries;		// Number of Study Related Series
	CString				m_strStudyImage;		// Number of Study Related Instances

	CString				m_strSeriesNumber;		// Series Number
	STRING_ARRAY		m_SeriesInstUID;		// Series Instance UID
	CString				m_strModality;			// Modality
	CString				m_strSeriesFrameUID;	// Frame of Reference UID
	CString				m_strSeriesImage;		// Number of Series Related Instances

	CString				m_strImageNumber;		// Instance Number
	STRING_ARRAY		m_SOPInstUID;			// SOP Instance UID
	CString				m_strPhotometric;		// Photometric Interpretation
	Uint16				m_nRows;				// Rows
	Uint16				m_nColumns;				// Columns
	Uint16				m_nBitsAllocated;		// Bits Allocated
	Uint16				m_nBitsStored;			// Bits Stored
	CString				m_strImagePosition;		// Image Position (Patient)
	CString				m_strImageOrientation;	// Image Orientation (Patient)
	CString				m_strPixelSpacing;		// Pixel Spacing
	CString				m_strImagerPixelSpacing;// Imager Pixel Spacing

public:
	MRET				CheckFind		(E_QR_MODE eMode, E_QR_LEVEL eLevel, BOOL bRelational, BOOL bLocalExecute = FALSE);
	MRET				CheckRetrieve	(E_QR_MODE eMode, E_QR_LEVEL eLevel, BOOL bRelational, BOOL bLocalExecute = FALSE);
	BOOL				SetMaskPatient	(BOOL bValue, BOOL bUnique);
	BOOL				SetMaskStudies	(BOOL bValue, BOOL bUnique);
	BOOL				SetMaskSeries	(BOOL bValue, BOOL bUnique);
	BOOL				SetMaskInstance	(BOOL bValue, BOOL bUnique);

public:
	CObQR();
	virtual ~CObQR();
};


class CObRetrieveResponse : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObRetrieveResponse)

public:
	STRING_ARRAY		m_FailedSOPInstUID;		// Failed SOP Instance UID List

public:
	CObRetrieveResponse();
	virtual ~CObRetrieveResponse();
};

#endif // !defined(AFX_OBBASIC_H__0B13A10C_71D0_4801_9076_4A4FF4554167__INCLUDED_)
