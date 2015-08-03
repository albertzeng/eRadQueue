// RISObject.h: interface for the RIS Object classes.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RISOBJECT_H__BFF71E48_3501_4119_8FE7_DC3389648A48__INCLUDED_)
#define AFX_RISOBJECT_H__BFF71E48_3501_4119_8FE7_DC3389648A48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define PATIENT_CREATED_EVENT					1
#define PATIENT_DELETED_EVENT					2
#define PATIENT_UPDATED_EVENT					3

#define VISIT_CREATED_EVENT						1
#define VISIT_SCHEDULED_EVENT					2
#define VISIT_ADMITTED_EVENT					3
#define VISIT_TRANSFERRED_EVENT					4
#define VISIT_DISCHARGED_EVENT					5
#define VISIT_DELETED_EVENT						6
#define VISIT_UPDATED_EVENT						7

#define STUDY_CREATED_EVENT						1
#define STUDY_SCHEDULED_EVENT					2
#define STUDY_ARRIVED_EVENT						3
#define STUDY_STARTED_EVENT						4
#define STUDY_COMPLETED_EVENT					5
#define STUDY_VERIFIED_EVENT					6
#define STUDY_READ_EVENT						7
#define STUDY_DELETED_EVENT						8
#define STUDY_UPDATED_EVENT						9

#define MPPS_IN_PROGRESS_EVENT					1
#define MPPS_COMPLETED_EVENT					2
#define MPPS_DISCONTINUED_EVENT					3
#define MPPS_UPDATED_EVENT						4
#define MPPS_DELETED_EVENT						5

#define STORAGE_COMMITMENT_REQUEST_ACTION		1
	
#define STORAGE_COMMITMENT_SUCCESSFUL_EVENT		1
#define STORAGE_COMMITMENT_FAILURES_EXIST_EVENT	2

#define RESULTS_CREATED_EVENT					1
#define RESULTS_DELETED_EVENT					2
#define RESULTS_UPDATED_EVENT					3

#define INTERPRETATION_CREATED_EVENT			1
#define INTERPRETATION_RECORDED_EVENT			2
#define INTERPRETATION_TRANSCRIBED_EVENT		3
#define INTERPRETATION_APPROVED_EVENT			4
#define INTERPRETATION_DELETED_EVENT			5
#define INTERPRETATION_UPDATED_EVENT			6

#define GSPS_STATUS_MODIFICATION_REQUEST_ACTION	1

#define VISIT_CREATED_STATUS					"CREATED"
#define VISIT_SCHEDULED_STATUS					"SCHEDULED"
#define VISIT_ADMITTED_STATUS					"ADMITTED"
#define VISIT_DISCHARGED_STATUS					"DISCHARGED"

#define	VISIT_OUT_PATIENT						"OUTPATIENT"
#define	VISIT_IN_PATIENT						"INPATIENT"
#define	VISIT_EMERGENCY							"EMERGENCY"

#define STUDY_CREATED_STATUS					"CREATED"
#define STUDY_SCHEDULED_STATUS					"SCHEDULED"
#define STUDY_ARRIVED_STATUS					"ARRIVED"
#define STUDY_STARTED_STATUS					"STARTED"
#define STUDY_COMPLETED_STATUS					"COMPLETED"
#define STUDY_VERIFIED_STATUS					"VERIFIED"
#define STUDY_READ_STATUS						"READ"

#define STUDY_LOW_PRIORITY						"LOW"
#define STUDY_MED_PRIORITY						"MED"
#define STUDY_HIGH_PRIORITY						"HIGH"

#define STUDY_COMPONENT_CREATED_STATUS			"CREATED"
#define STUDY_COMPONENT_INCOMPLETE_STATUS		"INCOMPLETE"
#define STUDY_COMPONENT_COMPLETED_STATUS		"COMPLETED"
#define STUDY_COMPONENT_VERIFIED_STATUS			"VERIFIED"
#define STUDY_COMPONENT_POSTINTERPRET_STATUS	"POSTINTERPRET"

#define MPPS_IN_PROGRESS_STATUS					"IN PROGRESS"
#define MPPS_DISCONTINUED_STATUS				"DISCONTINUED"
#define MPPS_COMPLETED_STATUS					"COMPLETED"

#define INTERPRETATION_CREATED_STATUS			"CREATED"
#define INTERPRETATION_RECORDED_STATUS			"RECORDED"
#define INTERPRETATION_TRANSCRIBED_STATUS		"TRANSCRIBED"
#define INTERPRETATION_APPROVED_STATUS			"APPROVED"

#define INTERPRETATION_REPORT_TYPE				"REPORT"
#define INTERPRETATION_AMENDMENT_TYPE			"AMENDMENT"

#define MSPS_SCHEDULED_STATUS					"SCHEDULED"
#define MSPS_ARRIVED_STATUS						"ARRIVED"

#define REQUESTED_PROCEDURE_STAT_PRIORITY		"STAT"
#define REQUESTED_PROCEDURE_HIGH_PRIORITY		"HIGH"
#define REQUESTED_PROCEDURE_ROUTINE_PRIORITY	"ROUTINE"
#define REQUESTED_PROCEDURE_MEDIUM_PRIORITY		"MEDIUM"
#define REQUESTED_PROCEDURE_LOW_PRIORITY		"LOW"

#define REPORTING_HIGH_PRIORITY					"HIGH"
#define REPORTING_ROUTINE_PRIORITY				"ROUTINE"
#define REPORTING_MEDIUM_PRIORITY				"MEDIUM"
#define REPORTING_LOW_PRIORITY					"LOW"


#define GSPS_SCHEDULED_STATUS					"SCHEDULED"
#define GSPS_IN_PROGRESS_STATUS					"IN PROGRESS"
#define GSPS_SUSPENDED_STATUS					"SUSPENDED"
#define GSPS_COMPLETED_STATUS					"COMPLETED"
#define GSPS_DISCONTINUED_STATUS				"DISCONTINUED"

#define GSPS_PARTIAL_AVAILABILITY_FLAG			"PARTIAL"
#define GSPS_COMPLETE_AVAILABILITY_FLAG			"COMPLETE"

#define GSPS_HIGH_PRIORITY						"HIGH"
#define GSPS_MEDIUM_PRIORITY					"MEDIUM"
#define GSPS_LOW_PRIORITY						"LOW"

#define GPPS_IN_PROGRESS_STATUS					"IN PROGRESS"
#define GPPS_COMPLETED_STATUS					"COMPLETED"
#define GPPS_DISCONTINUED_STATUS				"DISCONTINUED"


class CObCodeItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObCodeItem)

public:
	CString				m_strCodeValue;			// (0008,0100)	>Code Value
	CString				m_strCodeScheme;		// (0008,0102)	>Coding Scheme Designator
	CString				m_strCodeVersion;		// (0008,0103)	>Coding Scheme Version
	CString				m_strMeaning;			// (0008,0104)	>Code Meaning

public:
	CObCodeItem();
	virtual ~CObCodeItem();
};

typedef CTypedPtrArray<CObSQ, CObCodeItem*> CObCodeSQ;


class CObLangCodeItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObLangCodeItem)

public:
	CString				m_strCodeValue;			// (0008,0100)	>Code Value
	CString				m_strCodeScheme;		// (0008,0102)	>Coding Scheme Designator
	CString				m_strCodeVersion;		// (0008,0103)	>Coding Scheme Version
	CString				m_strMeaning;			// (0008,0104)	>Code Meaning
	CObCodeSQ			m_SQModifierCode;		// (0010,0102)	>Patient's Primary Language Code Modifier Sequence

public:
	CObLangCodeItem();
	virtual ~CObLangCodeItem();
};

typedef CTypedPtrArray<CObSQ, CObLangCodeItem*> CObLangCodeSQ;


class CObPatient : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObPatient)

public:
	CString				m_strCharacter;			// (0008,0005)	Specific Character Set
	CString				m_strCreateDate;		// (0008,0012)	Instance Creation Date
	CString				m_strCreateTime;		// (0008,0013)	Instance Creation Time
	CString				m_strCreatorUID;		// (0008,0014)	Instance Creator UID
	CObRefInstanceSQ	m_SQStudyInstance;		// (0008,1110)	Referenced Study Sequence
	CObRefInstanceSQ	m_SQVisitInstance;		// (0008,1125)	Referenced Visit Sequence
	CObRefInstanceSQ	m_SQAliasInstance;		// (0038,0004)	Referenced Patient Alias Sequence
	CString				m_strPatientName;		// (0010,0010)	Patient's Name
	CString				m_strPatientID;			// (0010,0020)	Patient ID
	CString				m_strIDIssuer;			// (0010,0021)	Issuer of Patient ID
	CString				m_strOtherPatientID;	// (0010,1000)	Other Patient IDs
	CString				m_strOtherPatientName;	// (0010,1001)	Other Patient Names
	CString				m_strBirthName;			// (0010,1005)	Patient's Birth Name
	CString				m_strMotherName;		// (0010,1060)	Patient's Mother's Birth Name
	CString				m_strRecordLocator;		// (0010,1090)	Medical Record Locator
	CString				m_strPatientAge;		// (0010,1010)	Patient's Age
	CString				m_strOccupation;		// (0010,2180)	Occupation
	CString				m_strConfidentiality;	// (0040,3001)	Patient Data Confidentiality Constraint Description
	CString				m_strPatientDOB;		// (0010,0030)	Patient's Birth Date
	CString				m_strBirthTime;			// (0010,0032)	Patient's Birth Time
	CString				m_strPatientSex;		// (0010,0040)	Patient's Sex
	CObCodeSQ			m_SQInsuranceCode;		// (0010,0050)	Patient's Insurance Plan Code Sequence
	CObLangCodeSQ		m_SQLanguageCode;		// (0010,0101)	Patient's Primary Language Code Sequence
	CString				m_strPatSize;			// (0010,1020)	Patient's Size
	CString				m_strPatWeight;			// (0010,1030)	Patient's Weight
	CString				m_strPatAddress;		// (0010,1040)	Patient's Address
	CString				m_strMilitaryRank;		// (0010,1080)	Military Rank
	CString				m_strMilitaryBranch;	// (0010,1081)	Branch of Service
	CString				m_strCountry;			// (0010,2150)	Country of Residence
	CString				m_strRegion;			// (0010,2152)	Region of Residence
	CString				m_strPatPhone;			// (0010,2154)	Patient's Telephone Numbers
	CString				m_strEthnicGroup;		// (0010,2160)	Ethnic Group
	CString				m_strReligion;			// (0010,21F0)	Patient's Religious Preference
	CString				m_strPatComments;		// (0010,4000)	Patient Comments
	CString				m_strMedAlert;			// (0010,2000)	Medical Alerts
	CString				m_strMedAllergy;		// (0010,2110)	Contrast Allergies
	CString				m_strSmoking;			// (0010,21A0)	Smoking Status
	CString				m_strPatHistory;		// (0010,21B0)	Additional Patient History
	Uint16				m_nPregnant;			// (0010,21C0)	Pregnancy Status
	CString				m_strLastMenses;		// (0010,21D0)	Last Menstrual Date
	CString				m_strSpecialNeed;		// (0038,0050)	Special Needs
	CString				m_strPatState;			// (0038,0500)	Patient State

public:
	CObPatient();
	virtual ~CObPatient();
};


class CObVisit : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObVisit)

public:
	CString				m_strCharacter;			// (0008,0005)	Specific Character Set
	CString				m_strCreateDate;		// (0008,0012)	Instance Creation Date
	CString				m_strCreateTime;		// (0008,0013)	Instance Creation Time
	CString				m_strCreatorUID;		// (0008,0014)	Instance Creator UID
	CObRefInstanceSQ	m_SQStudyInstance;		// (0008,1110)	Referenced Study Sequence
	CObRefInstanceSQ	m_SQPatientInstance;	// (0008,1120)	Referenced Patient Sequence
	CString				m_strInstitutionName;	// (0008,0080)	Institution Name
	CString				m_strInstitutionAddress;// (0008,0081)	Institution Address
	CObCodeSQ			m_SQInstitutionCode;	// (0008,0082)	Institution Code Sequence
	CString				m_strAdmissionID;		// (0038,0010)	Admission ID
	CString				m_strIDIssuer;			// (0038,0011)	Issuer of Admission ID
	CString				m_strStatusID;			// (0038,0008)	Visit Status ID
	CString				m_strPatLocation;		// (0038,0300)	Current Patient Location
	CString				m_strPatResidence;		// (0038,0400)	Patient¡¯s Institution Residence
	CString				m_strVisitComments;		// (0038,4000)	Visit Comments
	CString				m_strReferName;			// (0008,0090)	Referring Physician's Name
	CString				m_strReferAddress;		// (0008,0092)	Referring Physician's Address
	CString				m_strReferPhone;		// (0008,0094)	Referring Physician's Phone Numbers
	CString				m_strAdmDiagDesc;		// (0008,1080)	Admitting Diagnoses Description
	CObCodeSQ			m_SQAdmDiagCode;		// (0008,1084)	Admitting Diagnoses Code Sequence
	CString				m_strAdmRoute;			// (0038,0016)	Route of Admissions
	CString				m_strAdmDate;			// (0038,0020)	Admitting Date
	CString				m_strAdmTime;			// (0038,0021)	Admitting Time
	CString				m_strDischDate;			// (0038,0030)	Discharge Date
	CString				m_strDischTime;			// (0038,0032)	Discharge Time
	CString				m_strDischDiagDesc;		// (0038,0040)	Discharge Diagnosis Description
	CObCodeSQ			m_SQDischDiagCode;		// (0038,0044)	Discharge Diagnosis Code Sequence
	CString				m_strSchAdmDate;		// (0038,001A)	Scheduled Admission Date
	CString				m_strSchAdmTime;		// (0038,001B)	Scheduled Admission Time
	CString				m_strSchDischDate;		// (0038,001C)	Scheduled Discharge Date
	CString				m_strSchDischTime;		// (0038,001D)	Scheduled Discharge Time
	CString				m_strSchResidence;		// (0038,001E)	Scheduled Patient Institution Residence

public:
	CObVisit();
	virtual ~CObVisit();
};


class CObStudy : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObStudy)

public:
	CString				m_strCharacter;			// (0008,0005)	Specific Character Set
	CString				m_strCreateDate;		// (0008,0012)	Instance Creation Date
	CString				m_strCreateTime;		// (0008,0013)	Instance Creation Time
	CString				m_strCreatorUID;		// (0008,0014)	Instance Creator UID
	CObRefInstanceSQ	m_SQVisitInstance;		// (0008,1125)	Referenced Visit Sequence
	CObRefInstanceSQ	m_SQPatientInstance;	// (0008,1120)	Referenced Patient Sequence
	CObRefInstanceSQ	m_SQResultsInstance;	// (0008,1100)	Referenced Results Sequence
	CObRefInstanceSQ	m_SQComponentInstance;	// (0008,1111)	Referenced Study Component Sequence
	CString				m_strStudyInstUID;		// (0020,000D)	Study Instance UID
	CString				m_strAccessionNumber;	// (0008,0050)	Accession Number
	CString				m_strStudyID;			// (0020,0010)	Study ID
	CString				m_strIDIssuer;			// (0032,0012)	Study ID Issuer
	CString				m_strOtherNumbers;		// (0020,1070)	Other Study Numbers
	CString				m_strStatusID;			// (0032,000A)	Study Status ID
	CString				m_strPriorityID;		// (0032,000C)	Study Priority ID
	CString				m_strStudyComments;		// (0032,4000)	Study Comments
	CString				m_strStartDate;			// (0032,1000)	Scheduled Study Start Date
	CString				m_strStartTime;			// (0032,1001)	Scheduled Study Start Time
	CString				m_strStopDate;			// (0032,1010)	Scheduled Study Stop Date
	CString				m_strStopTime;			// (0032,1011)	Scheduled Study Stop Time
	CString				m_strSchLocation;		// (0032,1020)	Scheduled Study Location
	CString				m_strAETitle;			// (0032,1021)	Scheduled Study Location AE Title
	CString				m_strReason;			// (0032,1030)	Reason for Study
	CString				m_strRequester;			// (0032,1032)	Requesting Physician
	CString				m_strService;			// (0032,1033)	Requesting Service
	CString				m_strProcDesc;			// (0032,1060)	Requested Procedure Description
	CObCodeSQ			m_SQProcCode;			// (0032,1064)	Requested Procedure Code Sequence
	CString				m_strContrastAgent;		// (0032,1070)	Requested Contrast Agent
	CString				m_strArriveDate;		// (0032,1040)	Study Arrival Date
	CString				m_strArriveTime;		// (0032,1041)	Study Arrival Time
	CString				m_strStudyDate;			// (0008,0020)	Study Date
	CString				m_strStudyTime;			// (0008,0030)	Study Time
	CString				m_strDoneDate;			// (0032,1050)	Study Completion Date
	CString				m_strDoneTime;			// (0032,1051)	Study Completion Time
	CString				m_strVerifyDate;		// (0032,0032)	Study Verified Date
	CString				m_strVerifyTime;		// (0032,0033)	Study Verified Time
	CString				m_strModality;			// (0008,0061)	Modalities in Study
	CString				m_strTotalSeries;		// (0020,1000)	Series in Study
	CString				m_strTotalImage;		// (0020,1004)	Acquisitions in Study
	CString				m_strReader;			// (0008,1060)	Name of Physician (s) Reading Study
	CString				m_strReadDate;			// (0032,0034)	Study Read Date
	CString				m_strReadTime;			// (0032,0035)	Study Read Time

public:
	CObStudy();
	virtual ~CObStudy();
};


class CObSOPInstanceItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObSOPInstanceItem)

public:
	CString				m_strSOPClassUID;		// (0008,1150)	>>Referenced SOP Class UID
	CString				m_strSOPInstanceUID;	// (0008,1155)	>>Referenced SOP Instance UID
	CString				m_strAETitle;			// (0008,0054)	>>Retrieve AE Title
	CString				m_strFileSetID;			// (0088,0130)	>>Storage Media File-Set ID
	CString				m_strFileSetUID;		// (0088,0140)	>>Storage Media File-Set UID

public:
	CObSOPInstanceItem();
	virtual ~CObSOPInstanceItem();
};

typedef CTypedPtrArray<CObSQ, CObSOPInstanceItem*> CObSOPInstanceSQ;


class CObSeriesItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObSeriesItem)

public:
	CString				m_strSeriesDate;		// (0008,0021)	>Series Date
	CString				m_strSeriesTime;		// (0008,0031)	>Series Time
	CString				m_strSeriesInstUID;		// (0020,000E)	>Series Instance UID
	CString				m_strAETitle;			// (0008,0054)	>Retrieve AE Title
	CString				m_strFileSetID;			// (0088,0130)	>Storage Media File-Set ID
	CString				m_strFileSetUID;		// (0088,0140)	>Storage Media File-Set UID
	CObSOPInstanceSQ	m_SQReferencedImage;	// (0008,1140)	>Referenced Image Sequence

public:
	CObSeriesItem();
	virtual ~CObSeriesItem();
};

typedef CTypedPtrArray<CObSQ, CObSeriesItem*> CObSeriesSQ;


class CObComponent : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObComponent)

public:
	CString				m_strCharacter;			// (0008,0005)	Specific Character Set
	CString				m_strCreateDate;		// (0008,0012)	Instance Creation Date
	CString				m_strCreateTime;		// (0008,0013)	Instance Creation Time
	CString				m_strCreatorUID;		// (0008,0014)	Instance Creator UID
	CString				m_strStudyID;			// (0020,0010)	Study ID
	CString				m_strStudyInstUID;		// (0020,000D)	Study Instance UID
	CObSeriesSQ			m_SQReferencedSeries;	// (0008,1115)	Referenced Series Sequence
	CObRefInstanceSQ	m_SQStudyInstance;		// (0008,1110)	Referenced Study Sequence
	CString				m_strModality;			// (0008,0060)	Modality
	CString				m_strStudyDescription;	// (0008,1030)	Study Description
	CObCodeSQ			m_SQProcCode;			// (0008,1032)	Procedure Code Sequence
	CString				m_strPerformer;			// (0008,1050)	Performing Physician's Name
	CString				m_strStatusID;			// (0032,1055)	Study Component Status ID

public:
	CObComponent();
	virtual ~CObComponent();
};


class CObScheduledStepItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObScheduledStepItem)

public:
	CString				m_strStudyInstUID;		// (0020,000D)	>Study Instance UID
	CObRefInstanceSQ	m_SQStudyInstance;		// (0008,1110)	>Referenced Study Sequence
	CString				m_strAccessionNumber;	// (0008,0050)	>Accession Number
	CString				m_strPlacerOrder;		// (0040,2016)	>Placer Order Number/Imaging Service Request
	CString				m_strFillerOrder;		// (0040,2017)	>Filler Order Number/Imaging Service Request
	CString				m_strProcID;			// (0040,1001)	>Requested Procedure ID
	CString				m_strProcDesc;			// (0032,1060)	>Requested Procedure Description
	CString				m_strStepID;			// (0040,0009)	>Scheduled Procedure Step ID
	CString				m_strStepDesc;			// (0040,0007)	>Scheduled Procedure Step Description
	CObCodeSQ			m_SQProtCode;			// (0040,0008)	>Scheduled Protocol Code Sequence

public:
	CObScheduledStepItem();
	virtual ~CObScheduledStepItem();
};

typedef CTypedPtrArray<CObSQ, CObScheduledStepItem*> CObScheduledStepSQ;


class CObPerformSeriesItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObPerformSeriesItem)

public:
	CString				m_strPerformer;			// (0008,1050)	>Performing Physician's Name
	CString				m_strOperator;			// (0008,1070)	>Operator's Name
	CString				m_strProtName;			// (0018,1030)	>Protocol Name
	CString				m_strSeriesInstUID;		// (0020,000E)	>Series Instance UID
	CString				m_strSeriesDescription;	// (0008,103E)	>Series Description
	CString				m_strAETitle;			// (0008,0054)	>Retrieve AE Title
	CObRefInstanceSQ	m_SQImageInstance;		// (0008,1140)	>Referenced Image Sequence
	CObRefInstanceSQ	m_SQNonImageInstance;	// (0040,0220)	>Referenced Non-Image Composite SOP Instance Sequence

public:
	CObPerformSeriesItem();
	virtual ~CObPerformSeriesItem();
};

typedef CTypedPtrArray<CObSQ, CObPerformSeriesItem*> CObPerformSeriesSQ;


class CObMpps : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObMpps)

public:
	CString				m_strCharacter;			// (0008,0005)	Specific Character Set
	CString				m_strCreateDate;		// (0008,0012)	Instance Creation Date
	CString				m_strCreateTime;		// (0008,0013)	Instance Creation Time
	CString				m_strCreatorUID;		// (0008,0014)	Instance Creator UID
	CString				m_strPatientName;		// (0010,0010)	Patient's Name
	CString				m_strPatientID;			// (0010,0020)	Patient ID
	CString				m_strPatientDOB;		// (0010,0030)	Patient's Birth Date
	CString				m_strPatientSex;		// (0010,0040)	Patient's Sex
	CObRefInstanceSQ	m_SQPatientInstance;	// (0008,1120)	Referenced Patient Sequence
	CObScheduledStepSQ	m_SQScheduledStep;		// (0040,0270)	Scheduled Step Attributes Sequence
	CString				m_strStationAETitle;	// (0040,0241)	Performed Station AE Title
	CString				m_strStationName;		// (0040,0242)	Performed Station Name
	CString				m_strLocation;			// (0040,0243)	Performed Location
	CString				m_strStartDate;			// (0040,0244)	Performed Procedure Step Start Date
	CString				m_strStartTime;			// (0040,0245)	Performed Procedure Step Start Time
	CString				m_strMppsID;			// (0040,0253)	Performed Procedure Step ID
	CString				m_strEndDate;			// (0040,0250)	Performed Procedure Step End Date
	CString				m_strEndTime;			// (0040,0251)	Performed Procedure Step End Time
	CString				m_strMppsStatus;		// (0040,0252)	Performed Procedure Step Status
	CString				m_strMppsDesc;			// (0040,0254)	Performed Procedure Step Description
	CString				m_strMppsComments;		// (0040,0280)	Comments on the Performed Procedure Step
	CString				m_strMppsProcType;		// (0040,0255)	Performed Procedure Type Description
	CObCodeSQ			m_SQProcCode;			// (0008,1032)	Procedure Code Sequence
	CString				m_strModality;			// (0008,0060)	Modality
	CString				m_strStudyID;			// (0020,0010)	Study ID
	CObCodeSQ			m_SQMppsProtCode;		// (0040,0260)	Performed Protocol Code Sequence
	CObPerformSeriesSQ	m_SQPerformSeries;		// (0040,0340)	Performed Series Sequence

public:
	CObMpps();
	virtual ~CObMpps();
};


class CObResults : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObResults)

public:
	CString				m_strCharacter;			// (0008,0005)	Specific Character Set
	CString				m_strCreateDate;		// (0008,0012)	Instance Creation Date
	CString				m_strCreateTime;		// (0008,0013)	Instance Creation Time
	CString				m_strCreatorUID;		// (0008,0014)	Instance Creator UID
	CObRefInstanceSQ	m_SQStudyInstance;		// (0008,1110)	Referenced Study Sequence
	CObRefInstanceSQ	m_SQInterInstance;		// (4008,0050)	Referenced Interpretation Sequence
	CString				m_strResultsID;			// (4008,0040)	Results ID
	CString				m_strIDIssuer;			// (4008,0042)	Results ID Issuer
	CString				m_strImpressions;		// (4008,0300)	Impressions
	CString				m_strResultsComments;	// (4008,4000)	Results Comments

public:
	CObResults();
	virtual ~CObResults();
};


class CObApproverItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObApproverItem)

public:
	CString				m_strApproveDate;		// (4008,0112)	>Interpretation Approval Date
	CString				m_strApproveTime;		// (4008,0113)	>Interpretation Approval Time
	CString				m_strApprover;			// (4008,0114)	>Physicians Approving Interpretation

public:
	CObApproverItem();
	virtual ~CObApproverItem();
};

typedef CTypedPtrArray<CObSQ, CObApproverItem*> CObApproverSQ;


class CObDistributeItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObDistributeItem)

public:
	CString				m_strName;				// (4008,0119)	>Distribution Name
	CString				m_strAddress;			// (4008,011A)	>Distribution Address

public:
	CObDistributeItem();
	virtual ~CObDistributeItem();
};

typedef CTypedPtrArray<CObSQ, CObDistributeItem*> CObDistributeSQ;


class CObInterpretation : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObInterpretation)

public:
	CString				m_strCharacter;			// (0008,0005)	Specific Character Set
	CString				m_strCreateDate;		// (0008,0012)	Instance Creation Date
	CString				m_strCreateTime;		// (0008,0013)	Instance Creation Time
	CString				m_strCreatorUID;		// (0008,0014)	Instance Creator UID
	CObRefInstanceSQ	m_SQResultsInstance;	// (0008,1100)	Referenced Results Sequence
	CString				m_strInterID;			// (4008,0200)	Interpretation ID
	CString				m_strIDIssuer;			// (4008,0202)	Interpretation ID Issuer
	CString				m_strTypeID;			// (4008,0210)	Interpretation Type ID
	CString				m_strStatusID;			// (4008,0212)	Interpretation Status ID
	CString				m_strRecordDate;		// (4008,0100)	Interpretation Recorded Date
	CString				m_strRecordTime;		// (4008,0101)	Interpretation Recorded Time
	CString				m_strRecorder;			// (4008,0102)	Interpretation Recorder
	CString				m_strRecordSound;		// (4008,0103)	Reference to Recorded Sound
	CString				m_strTransDate;			// (4008,0108)	Interpretation Transcription Date
	CString				m_strTransTime;			// (4008,0109)	Interpretation Transcription Time
	CString				m_strTranscriber;		// (4008,010A)	Interpretation Transcriber
	CString				m_strInterText;			// (4008,010B)	Interpretation Text
	CString				m_strAuthor;			// (4008,010C)	Interpretation Author
	CObApproverSQ		m_SQApprover;			// (4008,0111)	Interpretation Approver Sequence
	CString				m_strDiagDesc;			// (4008,0115)	Interpretation Diagnosis Description
	CObCodeSQ			m_SQDiagCode;			// (4008,0117)	Interpretation Diagnosis Codes Sequence
	CObDistributeSQ		m_SQDistribute;			// (4008,0118)	Results Distribution List Sequence

public:
	CObInterpretation();
	virtual ~CObInterpretation();
};


class CObFailedItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObFailedItem)

public:
	CString				m_strSOPClassUID;		// (0008,1150)	>Referenced SOP Class UID
	CString				m_strSOPInstanceUID;	// (0008,1155)	>Referenced SOP Instance UID
	Uint16				m_nFailureReason;		// (0008,1197)	>Failure Reason 

public:
	CObFailedItem();
	virtual ~CObFailedItem();
};

typedef CTypedPtrArray<CObSQ, CObFailedItem*> CObFailedSQ;


class CObStorageCommitment : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObStorageCommitment)

public:
	CString				m_strCharacter;			// (0008,0005)	Specific Character Set
	CString				m_strTransactionUID;	// (0008,1195)	Transaction UID 
	CString				m_strAETitle;			// (0008,0054)	Retrieve AE Title 
	CString				m_strFileSetID;			// (0088,0130)	Storage Media File-Set ID 
	CString				m_strFileSetUID;		// (0088,0140)	Storage Media File-Set UID 
	CObSOPInstanceSQ	m_SQReferencedInstance;	// (0008,1199)	Referenced SOP Sequence 
	CObRefInstanceSQ	m_SQComponentInstance;	// (0008,1111)	Referenced Study Component Sequence 
	CObFailedSQ			m_SQFailedInstance;		// (0008,1198)	Failed SOP Sequence 

public:
	CObStorageCommitment();
	virtual ~CObStorageCommitment();
};


class CObMwlStepItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObMwlStepItem)

public:
	CString				m_strAETitle;			// (0040,0001)	>Scheduled Station AE Title
	CString				m_strStationName;		// (0040,0010)	>Scheduled Station Name
	CString				m_strStepLocation;		// (0040,0011)	>Scheduled Procedure Step Location
	CString				m_strStartDate;			// (0040,0002)	>Scheduled Procedure Step Start Date
	CString				m_strStartTime;			// (0040,0003)	>Scheduled Procedure Step Start Time
	CString				m_strEndDate;			// (0040,0004)	>Scheduled Procedure Step End Date
	CString				m_strEndTime;			// (0040,0005)	>Scheduled Procedure Step End Time
	CString				m_strSchPerformer;		// (0040,0006)	>Scheduled Performing Physician's Name
	CString				m_strStepDesc;			// (0040,0007)	>Scheduled Procedure Step Description
	CObCodeSQ			m_SQProtCode;			// (0040,0008)	>Scheduled Protocol Code Sequence
	CString				m_strStepID;			// (0040,0009)	>Scheduled Procedure Step ID
	CString				m_strStepStatus;		// (0040,0020)	>Scheduled Procedure Step Status
	CString				m_strStepComments;		// (0040,0400)	>Comments on the Scheduled Procedure Step
	CString				m_strModality;			// (0008,0060)	>Modality
	CString				m_strContrastAgent;		// (0032,1070)	>Requested Contrast Agent
	CString				m_strPreMedication;		// (0040,0012)	>Pre-Medication

public:
	CObMwlStepItem();
	virtual ~CObMwlStepItem();
};

typedef CTypedPtrArray<CObSQ, CObMwlStepItem*> CObMwlStepSQ;


class CObMwlManagement : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObMwlManagement)

public:
	CString				m_strCharacter;			// (0008,0005)	Specific Character Set
	CObMwlStepSQ		m_SQStep;				// (0040,0100)	Scheduled Procedure Step Sequence
	CString				m_strProcID;			// (0040,1001)	Requested Procedure ID
	CString				m_strProcReason;		// (0040,1002)	Reason for the Requested Procedure
	CString				m_strProcComments;		// (0040,1400)	Requested Procedure Comments
	CObCodeSQ			m_SQProcCode;			// (0032,1064)	Requested Procedure Code Sequence
	CString				m_strStudyInstUID;		// (0020,000D)	Study Instance UID
	CObRefInstanceSQ	m_SQStudyInstance;		// (0008,1110)	Referenced Study Sequence
	CString				m_strProcDesc;			// (0032,1060)	Requested Procedure Description
	CString				m_strProcPriority;		// (0040,1003)	Requested Procedure Priority
	CString				m_strTransport;			// (0040,1004)	Patient Transport Arrangements
	CString				m_strProcLocation;		// (0040,1005)	Requested Procedure Location
	CString				m_strConfidentiality;	// (0040,1008)	Confidentiality Code
	CString				m_strReportPriority;	// (0040,1009)	Reporting Priority
	CString				m_strRecipients;		// (0040,1010)	Names of Intended Recipients of Results
	CString				m_strSvcReason;			// (0040,2001)	Reason for the Imaging Service Request
	CString				m_strSvcComments;		// (0040,2400)	Imaging Service Request Comments
	CString				m_strRequester;			// (0032,1032)	Requesting Physician
	CString				m_strReferName;			// (0008,0090)	Referring Physician's Name
	CString				m_strService;			// (0032,1033)	Requesting Service
	CString				m_strAccessionNumber;	// (0008,0050)	Accession Number
	CString				m_strIssueDate;			// (0040,2004)	Issue Date of Imaging Service Request
	CString				m_strIssueTime;			// (0040,2005)	Issue Time of Imaging Service Request
	CString				m_strPlacerOrder;		// (0040,2016)	Placer Order Number / Imaging Service Request
	CString				m_strFillerOrder;		// (0040,2017)	Filler Order Number / Imaging Service Request
	CString				m_strEnterer;			// (0040,2008)	Order entered by ...
	CString				m_strEnterLocation;		// (0040,2009)	Order Enterer's Location
	CString				m_strEnterPhone;		// (0040,2010)	Order Callback Phone Number
	CString				m_strAdmissionID;		// (0038,0010)	Admission ID
	CString				m_strPatLocation;		// (0038,0300)	Current Patient Location
	CObRefInstanceSQ	m_SQPatientInstance;	// (0008,1120)	Referenced Patient Sequence
	CString				m_strPatientName;		// (0010,0010)	Patient's Name
	CString				m_strPatientID;			// (0010,0020)	Patient ID
	CString				m_strOtherPatientID;	// (0010,1000)	Other Patient IDs
	CString				m_strOtherPatientName;	// (0010,1001)	Other Patient Names
	CString				m_strPatientAge;		// (0010,1010)	Patient's Age
	CString				m_strPatientDOB;		// (0010,0030)	Patient's Birth Date
	CString				m_strPatientSex;		// (0010,0040)	Patient's Sex
	CObLangCodeSQ		m_SQLanguageCode;		// (0010,0101)	Patient's Primary Language Code Sequence
	CString				m_strPatWeight;			// (0010,1030)	Patient's Weight
	CString				m_strPatConfidentiality;// (0040,3001)	Patient Data Confidentiality Constraint Description
	CString				m_strPatState;			// (0038,0500)	Patient State
	Uint16				m_nPregnant;			// (0010,21C0)	Pregnancy Status
	CString				m_strMedAlert;			// (0010,2000)	Medical Alerts
	CString				m_strMedAllergy;		// (0010,2110)	Contrast Allergies
	CString				m_strSpecialNeed;		// (0038,0050)	Special Needs

public:
	CObMwlManagement();
	virtual ~CObMwlManagement();
};


class CObGpHumanItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObGpHumanItem)

public:
	CObCodeSQ			m_SQHumanCode;			// (0040,4009)	>Human Performer Code Sequence
	CString				m_strName;				// (0040,4037)	>Human Performer's Name
	CString				m_strOrganization;		// (0040,4036)	>Human Performer's Organization

public:
	CObGpHumanItem();
	virtual ~CObGpHumanItem();
};

typedef CTypedPtrArray<CObSQ, CObGpHumanItem*> CObGpHumanSQ;


class CObGpRequestItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObGpRequestItem)

public:
	CString				m_strStudyInstUID;		// (0020,000D)	>Study Instance UID
	CObRefInstanceSQ	m_SQStudyInstance;		// (0008,1110)	>Referenced Study Sequence
	CString				m_strAccessionNumber;	// (0008,0050)	>Accession Number
	CObCodeSQ			m_SQProcCode;			// (0032,1064)	>Requested Procedure Code Sequence
	CString				m_strPlacerOrder;		// (0040,2016)	>Placer Order Number / Imaging Service Request
	CString				m_strFillerOrder;		// (0040,2017)	>Filler Order Number / Imaging Service Request
	CString				m_strProcID;			// (0040,1001)	>Requested Procedure ID
	CString				m_strProcDesc;			// (0032,1060)	>Requested Procedure Description
	CString				m_strProcReason;		// (0040,1002)	>Reason for the Requested Procedure
	CString				m_strProcComments;		// (0040,1400)	>Requested Procedure Comments
	CString				m_strConfidentiality;	// (0040,1008)	>Confidentiality Code
	CString				m_strRecipients;		// (0040,1010)	>Names of Intended Recipients of Results
	CString				m_strSvcReason;			// (0040,2001)	>Reason for the Imaging Service Request
	CString				m_strSvcComments;		// (0040,2400)	>Imaging Service Request Comments
	CString				m_strRequester;			// (0032,1032)	>Requesting Physician
	CString				m_strService;			// (0032,1033)	>Requesting Service
	CString				m_strIssueDate;			// (0040,2004)	>Issue Date of Imaging Service Request
	CString				m_strIssueTime;			// (0040,2005)	>Issue Time of Imaging Service Request
	CString				m_strReferName;			// (0008,0090)	>Referring Physician's Name

public:
	CObGpRequestItem();
	virtual ~CObGpRequestItem();
};

typedef CTypedPtrArray<CObSQ, CObGpRequestItem*> CObGpRequestSQ;


class CObGpInfoItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObGpInfoItem)

public:
	CString				m_strStudyInstUID;		// (0020,000D)	>Study Instance UID
	CObSeriesSQ			m_SQReferencedSeries;	// (0008,1115)	>Referenced Series Sequence

public:
	CObGpInfoItem();
	virtual ~CObGpInfoItem();
};

typedef CTypedPtrArray<CObSQ, CObGpInfoItem*> CObGpInfoSQ;


class CObGpwlManagement : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObGpwlManagement)

public:
	CString				m_strCharacter;			// (0008,0005)	Specific Character Set
	CString				m_strSOPClassUID;		// (0008,0016)	SOP Class UID
	CString				m_strSOPInstanceUID;	// (0008,0018)	SOP Instance UID
	CString				m_strStepStatus;		// (0040,4001)	General Purpose Scheduled Procedure Step Status
	CString				m_strStepPriority;		// (0040,4003)	General Purpose Scheduled Procedure Step Priority
	CString				m_strStepID;			// (0040,0009)	Scheduled Procedure Step ID
	CObCodeSQ			m_SQApplicationCode;	// (0040,4004)	Scheduled Processing Applications Code Sequence
	CObCodeSQ			m_SQNameCode;			// (0040,4025)	Scheduled Station Name Code Sequence
	CObCodeSQ			m_SQClassCode;			// (0040,4026)	Scheduled Station Class Code Sequence
	CObCodeSQ			m_SQLocationCode;		// (0040,4027)	Scheduled Station Geographic Location Code Sequence
	CObGpHumanSQ		m_SQScheduledHuman;		// (0040,4034)	Scheduled Human Performers Sequence
	CString				m_strStartDateTime;		// (0040,4005)	Scheduled Procedure Step Start Date and Time
	CString				m_strEndDateTime;		// (0040,4011)	Expected Completion Date and Time
	CObCodeSQ			m_SQWorkItemCode;		// (0040,4018)	Scheduled Workitem Code Sequence
	CString				m_strStepComments;		// (0040,0400)	Comments on the Scheduled Procedure Step
	CObRefInstanceSQ	m_SQComponentInstance;	// (0008,1111)	Referenced Study Component Sequence
	CString				m_strAvailability;		// (0040,4020)	Input Availability Flag
	CObGpInfoSQ			m_SQInput;				// (0040,4021)	Input Information Sequence
	CObGpInfoSQ			m_SQRelevant;			// (0040,4022)	Relevant Information Sequence
	CString				m_strStudyInstUID;		// (0020,000D)	Study Instance UID
	CString				m_strMultipleCopies;	// (0040,4006)	Multiple Copies Flag
	CObRefInstanceSQ	m_SQGppsInstance;		// (0040,4015)	Resulting General Purpose Performed Procedure Steps Sequence
	CObGpHumanSQ		m_SQActualHuman;		// (0040,4035)	Actual Human Performers Sequence
	CString				m_strPatientName;		// (0010,0010)	Patient's Name
	CString				m_strPatientID;			// (0010,0020)	Patient ID
	CString				m_strPatientDOB;		// (0010,0030)	Patient's Birth Date
	CString				m_strPatientSex;		// (0010,0040)	Patient's Sex
	CObGpRequestSQ		m_SQGpwlRequest;		// (0040,A370)	Referenced Request Sequence

public:
	CObGpwlManagement();
	virtual ~CObGpwlManagement();
};


class CObGsps : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObGsps)

public:
	CString				m_strCharacter;			// (0008,0005)	Specific Character Set
	CString				m_strCreateDate;		// (0008,0012)	Instance Creation Date
	CString				m_strCreateTime;		// (0008,0013)	Instance Creation Time
	CString				m_strCreatorUID;		// (0008,0014)	Instance Creator UID
	CString				m_strTransactionUID;	// (0008,1195)	Transaction UID 
	CString				m_strPatientName;		// (0010,0010)	Patient's Name
	CString				m_strPatientID;			// (0010,0020)	Patient ID
	CString				m_strPatientDOB;		// (0010,0030)	Patient's Birth Date
	CString				m_strPatientSex;		// (0010,0040)	Patient's Sex
	CObGpRequestSQ		m_SQGspsRequest;		// (0040,A370)	Referenced Request Sequence
	CString				m_strStepStatus;		// (0040,4001)	General Purpose Scheduled Procedure Step Status
	CString				m_strStepPriority;		// (0040,4003)	General Purpose Scheduled Procedure Step Priority
	CString				m_strStepID;			// (0040,0009)	Scheduled Procedure Step ID
	CObCodeSQ			m_SQApplicationCode;	// (0040,4004)	Scheduled Processing Applications Code Sequence
	CObCodeSQ			m_SQNameCode;			// (0040,4025)	Scheduled Station Name Code Sequence
	CObCodeSQ			m_SQClassCode;			// (0040,4026)	Scheduled Station Class Code Sequence
	CObCodeSQ			m_SQLocationCode;		// (0040,4027)	Scheduled Station Geographic Location Code Sequence
	CObGpHumanSQ		m_SQScheduledHuman;		// (0040,4034)	Scheduled Human Performers Sequence
	CString				m_strStartDateTime;		// (0040,4005)	Scheduled Procedure Step Start Date and Time
	CString				m_strEndDateTime;		// (0040,4011)	Expected Completion Date and Time
	CObCodeSQ			m_SQWorkItemCode;		// (0040,4018)	Scheduled Workitem Code Sequence
	CString				m_strStepComments;		// (0040,0400)	Comments on the Scheduled Procedure Step
	CObRefInstanceSQ	m_SQComponentInstance;	// (0008,1111)	Referenced Study Component Sequence
	CString				m_strAvailability;		// (0040,4020)	Input Availability Flag
	CObGpInfoSQ			m_SQInput;				// (0040,4021)	Input Information Sequence
	CObGpInfoSQ			m_SQRelevant;			// (0040,4022)	Relevant Information Sequence
	CString				m_strStudyInstUID;		// (0020,000D)	Study Instance UID
	CString				m_strMultipleCopies;	// (0040,4006)	Multiple Copies Flag
	CObRefInstanceSQ	m_SQGppsInstance;		// (0040,4015)	Resulting General Purpose Performed Procedure Steps Sequence
	CObGpHumanSQ		m_SQActualHuman;		// (0040,4035)	Actual Human Performers Sequence

public:
	CObGsps();
	virtual ~CObGsps();
};


class CObGspsItem : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObGspsItem)

public:
	CString				m_strSOPClassUID;		// (0008,1150)	>Referenced SOP Class UID
	CString				m_strSOPInstanceUID;	// (0008,1155)	>Referenced SOP Instance UID
	CString				m_strTransactionUID;	// (0040,4023)	>Referenced General Purpose Scheduled Procedure Step Transaction UID

public:
	CObGspsItem();
	virtual ~CObGspsItem();
};

typedef CTypedPtrArray<CObSQ, CObGspsItem*> CObGspsSQ;


class CObGpps : public CObBasic  
{
	DECLARE_MEMBER_TABLE(CObGpps)

public:
	CString				m_strCharacter;			// (0008,0005)	Specific Character Set
	CString				m_strCreateDate;		// (0008,0012)	Instance Creation Date
	CString				m_strCreateTime;		// (0008,0013)	Instance Creation Time
	CString				m_strCreatorUID;		// (0008,0014)	Instance Creator UID
	CString				m_strPatientName;		// (0010,0010)	Patient's Name
	CString				m_strPatientID;			// (0010,0020)	Patient ID
	CString				m_strPatientDOB;		// (0010,0030)	Patient's Birth Date
	CString				m_strPatientSex;		// (0010,0040)	Patient's Sex
	CObGpRequestSQ		m_SQGppsRequest;		// (0040,A370)	Referenced Request Sequence
	CObGspsSQ			m_SQGspsInstance;		// (0040,4016)	Referenced General Purpose Scheduled Procedure Step Sequence
	CObGpHumanSQ		m_SQActualHuman;		// (0040,4035)	Actual Human Performers Sequence
	CObCodeSQ			m_SQNameCode;			// (0040,4028)	Performed Station Name Code Sequence
	CObCodeSQ			m_SQClassCode;			// (0040,4029)	Performed Station Class Code Sequence
	CObCodeSQ			m_SQLocationCode;		// (0040,4030)	Performed Station Geographic Location Code Sequence
	CObCodeSQ			m_SQApplicationCode;	// (0040,4007)	Performed Processing Applications Code Sequence
	CString				m_strStartDate;			// (0040,0244)	Performed Procedure Step Start Date
	CString				m_strStartTime;			// (0040,0245)	Performed Procedure Step Start Time
	CString				m_strStepID;			// (0040,0253)	Performed Procedure Step ID
	CString				m_strEndDate;			// (0040,0250)	Performed Procedure Step End Date
	CString				m_strEndTime;			// (0040,0251)	Performed Procedure Step End Time
	CString				m_strStepStatus;		// (0040,4002)	General Purpose Performed Procedure Step Status
	CString				m_strStepDesc;			// (0040,0254)	Performed Procedure Step Description
	CString				m_strStepComments;		// (0040,0280)	Comments on the Performed Procedure Step
	CObCodeSQ			m_SQWorkitemCode;		// (0040,4019)	Performed Workitem Code Sequence
	CObGpInfoSQ			m_SQOutput;				// (0040,4033)	Output Information Sequence
	CObCodeSQ			m_SQSubWorkitemCode;	// (0040,4031)	Requested Subsequent Workitem Code Sequence
	CObCodeSQ			m_SQOutputCode;			// (0040,4032)	Non-DICOM Output Code Sequence

public:
	CObGpps();
	virtual ~CObGpps();
};

#endif // !defined(AFX_RISOBJECT_H__BFF71E48_3501_4119_8FE7_DC3389648A48__INCLUDED_)
