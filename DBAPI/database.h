// database.h:
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATABASE_H__89C77E7D_79C5_41D1_8607_34DDBBFF48EB__INCLUDED_)
#define AFX_DATABASE_H__89C77E7D_79C5_41D1_8607_34DDBBFF48EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LOG.H"

#define	ERAD_REWORK_TIMES		10
#define	ERAD_MAX_RESPONSE		10000

#define	ERAD_ZLIB_FORMAT		"ZLIB"

#define	ERADUID_ANNEX_RESULTS	"1.2.473.8013.1.1.1.1"
#define	ERADUID_ANNEX_FILMPRINT	"1.2.473.8013.1.1.2.1"
#define	ERADUID_ANNEX_SIGNATURE	"1.2.473.8013.1.1.3.1"

enum E_DB_INDEX
{
//100
	IX_EIS_PATIENTS				= 101,
	IX_EIS_STUDIES				= 102,
	IX_EIS_RESULTS				= 103,
	IX_EIS_REPORTS				= 104,
	IX_EIS_SERVICE				= 105,
	IX_EIS_FAVORITE				= 106,
	IX_EIS_FAVORITE_STUDIES		= 107,
	IX_EIS_EXCHANGE				= 108,
	IX_EIS_STUDIES_CONSUME		= 109,
	IX_EIS_LOG					= 110,
	IX_EIS_STUDIES_QC			= 111,
	IX_EIS_MESSAGE				= 112,
	IX_EIS_EXCHANGE_FAILED		= 113,
	IX_EIS_QUEUE				= 114,
	IX_EIS_QUEUE_CALL			= 115,

	IX_MGR_DEPARTMENT			= 201,
	IX_MGR_DOCTOR				= 202,
	IX_MGR_MODALITIES			= 203,
	IX_MGR_DEVICE				= 204,
	IX_MGR_BODIES				= 205,
	IX_MGR_SPECS				= 206,
	IX_MGR_EXAMINE				= 207,
	IX_MGR_DISEASE				= 208,
	IX_MGR_TEMPLATE				= 209,
	IX_MGR_CONSUME				= 210,
	IX_MGR_CODE					= 211,
	IX_MGR_NODE					= 212,
	IX_MGR_PHRASE				= 213,
	IX_MGR_LINKER				= 214,
	IX_MGR_BODIES_REPLACE		= 215,

	IX_ORD_PATIENTS_ID			= 301,
	IX_ORD_ACCESSION_PREARRANGE	= 302,
	IX_ORD_ACCESSION_NUMBER		= 303,

	IX_EIS_RESULTS_IMAGE		= 401,

	IX_FP_ASSOCIATION			= 411,
	IX_FP_SERVICES				= 412,
	IX_FP_FILM_SESSION			= 413,
	IX_FP_FILM_BOX				= 414,
	IX_FP_FILM_IMAGE			= 415,
	IX_FP_FILM_SESSION_PRINT	= 430,

	IX_PACS_PATIENTS			= 501,
	IX_PACS_STUDIES				= 502,
	IX_PACS_SERIES				= 503,
	IX_PACS_IMAGES				= 504,
	IX_PACS_FAILED_IMAGES		= 505,

	IX_QACS_PATIENTS			= 511,
	IX_QACS_STUDIES				= 512,
	IX_QACS_SERIES				= 513,
	IX_QACS_IMAGES				= 514,
	IX_QACS_FAILED_IMAGES		= 515,

//521
	IX_IMG_NEAR_LINE			= 522,
//523
	IX_IMG_ARCHIVE				= 524,
	IX_IMG_OPERATE				= 525,
	IX_IMG_ANNEX_FILE			= 526,
//531
//532
	IX_STORAGE_DVD				= 541,
	IX_STORAGE_ORDER			= 542,
	IX_STORAGE_ORDER_SUBMIT		= 543,
//544
//545
//546
	IX_IMG_AVI_FILE				= 547,
	IX_IMG_NEARLINE_STORAGE		= 548,
	IX_IMG_NEARLINE_STORAGE_FILE= 549,

	IX_EIS_TECHCTROL			= 802,
	IX_EIS_WORD					= 803
};

enum E_DB_OPERATE_PRIVILEGE
{
	OP_ADMINISTRATION			= 0x00000001,
	OP_ADMINISTRATION_DEPARTMENT= 0x00000002,
	OP_TEMPLATE_PUBLIC			= 0x00000004,
	OP_TEMPLATE_PRIVATE			= 0x00000008,
	OP_PASSWORD					= 0x00000010,
	OP_REGISTER					= 0x00000020,
	OP_PERFORMER				= 0x00000040,
	OP_PERFORMER_CANCEL			= 0x00000080,
	OP_PERFORMER_CANCEL_ALL		= 0x00000100,
	OP_REPORT					= 0x00000200,
	OP_APPROVE					= 0x00000400,
	OP_REVIEW					= 0x00000800,
	OP_REPORT_PRINT				= 0x00001000,
	OP_REPORT_PRINT_TOGETHER	= 0x00002000,
	OP_REPORT_AMENDMENT			= 0x00004000,
	OP_REPORT_AMENDMENT_ALL		= 0x00008000,
	OP_REPORT_REFERENCE			= 0x00010000,
//	OP_REPORT_HISTORY 			= 0x00020000,
//	OP_REPORT_CONCLUSION		= 0x00040000,
//	OP_CLINICAL 				= 0x00080000,
//	OP_CLINICAL_DEPARTMENT 		= 0x00100000,
//	OP_CLINICAL_ALL 			= 0x00200000,
	OP_SET_PARAMETER			= 0x00400000,
//	OP_MODIFY_INFOMATION		= 0x00800000,
	OP_RECORD					= 0x01000000,
	OP_PHRASE_PUBLIC			= 0x02000000,
	OP_PHRASE_PRIVATE			= 0x04000000,
	OP_ADMINISTRATION_PACS		= 0x08000000,
	OP_PROTECTIVE				= 0x10000000,
	OP_STUDIES_QC				= 0x20000000
};

enum E_EIS_LOG_LEVEL
{
	EIS_LOG_INFORMATION			= 0,
	EIS_LOG_ALERT				= 1,
	EIS_LOG_ERROR				= 2,
	EIS_LOG_RECORD				= 10
};

enum E_EIS_LOG_OPERATE
{
	LOG_SCHEDULE_INSERT			= 10,
	LOG_SCHEDULE_REGISTER		= 20,
	LOG_REGISTER_INSERT			= 30,
	LOG_REGISTER_UPDATE			= 40,
	LOG_REGISTER_DELETE			= 50,
	LOG_REGISTER_PRINT			= 60,
	LOG_FILM_CANCEL				= 70,
	LOG_FILM_ARCHIVE			= 80,
	LOG_HIS_INTERFACE			= 90,
	LOG_EXAMINE_SIGNATURE		= 100,
	LOG_EXAMINE_UPDATE			= 110,
	LOG_EXAMINE_CANCEL			= 120,
	LOG_EXAMINE_RESET			= 130,
	LOG_EXAMINE_PRINT			= 140,
	LOG_IMAGE_ARCHIVE_AUTO		= 150,
	LOG_IMAGE_ARCHIVE_MANUAL	= 160,
	LOG_IMAGE_DELETE			= 170,
	LOG_REPORTS_SAVE			= 200,
	LOG_REPORTS_ADVANCE			= 210,
	LOG_REPORTS_REPORT			= 220,
	LOG_REPORTS_BACK			= 230,
	LOG_REPORTS_APPROVE			= 240,
	LOG_REPORTS_UPDATE			= 250,
	LOG_REPORTS_REVIEW			= 260,
	LOG_EXAMINE_CONSULTATION	= 270,
	LOG_EXAMINE_REVIEW			= 280,
	LOG_QC_TECHNOLOGY			= 290,
	LOG_QC_DIAGNOSE				= 300,
	LOG_QC_REQUEST				= 310,
	LOG_ADMISSION_ID_QUERY		= 9001
};

enum E_EIS_NODE_KINDS
{
	EIS_NODE_EIS_SERVICE		= 10,
	EIS_NODE_PAS_SERVICE		= 20,
	EIS_NODE_QAS_SERVICE		= 21,
	EIS_NODE_PRINT_SERVICE		= 30,
	EIS_NODE_PRINT_CLIENT		= 32,
	EIS_NODE_REGISTER			= 40,
	EIS_NODE_QACS				= 50,
	EIS_NODE_REPORTER			= 60,
	EIS_NODE_VIEWER				= 70,
	EIS_NODE_DEVICE				= 80,
	EIS_NODE_PRINTER			= 90,
	EIS_NODE_DVD_STORAGE		= 100,
	EIS_NODE_LINKER_SERVICE		= 110,
	EIS_NODE_REGISTER_CLIENT	= 120,
	EIS_NODE_MEDICAL_STATION	= 150
};

enum E_EIS_DOCTOR
{
	EIS_DOCTOR_SYSTEM			= 0x00000001
};

enum E_EIS_DISEASE
{
	EIS_DISEASE_ACR				= 1,
	EIS_DISEASE_ICD10			= 10,
	EIS_DISEASE_CUSTOM			= 100
};

enum E_EIS_TEMPLATE
{
	EIS_TEMPLATE_FOLDER			= 0,
	EIS_TEMPLATE_GENERAL		= 1,
	EIS_TEMPLATE_SELECTIVE 		= 10,
	EIS_TEMPLATE_LABEL			= 20,
	EIS_TEMPLATE_LABEL_UI		= 22,
	EIS_TEMPLATE_LABEL_SECTION	= 24,
	EIS_TEMPLATE_TECHNOLOGY		= 100,
	EIS_TEMPLATE_COMMENT		= 110,
	EIS_TEMPLATE_CANCEL			= 1000
};

enum E_EIS_TEMPLATE_OFFSET
{
	EIS_OFFSET_TECHNOLOGIES	= 0x01000000
};

enum E_EIS_PHRASE
{
	EIS_PHRASE_DISEASE					= 3,
	EIS_PHRASE_TEMPLATE					= 8,
	EIS_PHRASE_PATIENTS_COMMENTS		= 10,
	EIS_PHRASE_REQUEST_REASON			= 20,
	EIS_PHRASE_EXECUTE_TECHNOLOGIES		= 30,
	EIS_PHRASE_EXECUTE_COMMENTS			= 40,
	EIS_PHRASE_RESULTS_COMMENTS			= 50,
	EIS_PHRASE_SR_CLINICAL				= 60,
	EIS_PHRASE_SR_PATHOLOGIC			= 70,
	EIS_PHRASE_SR_COMMENTS				= 80,
	EIS_PHRASE_CONSULTATION_RECORD		= 90,
	EIS_PHRASE_CONSULTATION_CONCLUSION	= 100,
	EIS_PHRASE_REPORTS_TECHNOLOGIES		= 110,
	EIS_PHRASE_REPORTS_EVIDENCES		= 120,
	EIS_PHRASE_REPORTS_CONCLUSION		= 130,
	EIS_PHRASE_QC_EVIDENCES				= 140,
	EIS_PHRASE_QC_CONCLUSION			= 150,
	EIS_PHRASE_QC_REQUEST				= 160,
	EIS_PHRASE_REQUEST_HOSPITAL			= 200,
	EIS_PHRASE_REQUEST_CLINIC			= 210,
	EIS_PHRASE_DEVICE_MODEL				= 220,
	EIS_PHRASE_DEVICE_HZ				= 230,
	EIS_PHRASE_PATIENTS_OCCUPATION		= 240,
	EIS_PHRASE_PATIENTS_POSTCODE		= 250
};

enum E_EIS_ADMISSION
{
	EIS_ADMISSION_EXAMIN		= 1,
	EIS_ADMISSION_IMPORT		= 5,
	EIS_ADMISSION_INPATIENT		= 10,
	EIS_ADMISSION_OUTPATIENT	= 50,
	EIS_ADMISSION_EMERGENTY		= 100,
	EIS_ADMISSION_PROTECTIVE	= 1000
};

enum E_EIS_ADMISSION_PRIORITY 
{
	EIS_ADMISSION_LOW			= 10,
	EIS_ADMISSION_MED			= 50,
	EIS_ADMISSION_HIGH			= 100
};

enum E_EIS_QUEUE_STATUS 
{
	EIS_QUEUE_WAIT				= 0,
	EIS_QUEUE_ADVANCE			= 10,
	EIS_QUEUE_EXAMINE			= 50,
	EIS_QUEUE_COMPLETE			= 100,
	EIS_QUEUE_UNREADY			= 110,
	EIS_QUEUE_CANCEL			= 120
};

enum E_EIS_QUEUE_EMERGENT 
{
	EIS_QUEUE_GENERAL			= 0,
	EIS_QUEUE_EMERGENT			= 1,
	EIS_QUEUE_EXCEPTIVE			= 10
};

enum E_EIS_STUDIES_STATUS 
{
	EIS_STUDIES_PREARRANGE		= 10,
	EIS_STUDIES_REGISTER		= 50,
	EIS_STUDIES_SIGNATURE		= 80,
	EIS_STUDIES_COMPLETE		= 100,
	EIS_STUDIES_CANCEL			= 120
};

enum E_EIS_STUDIES_MARKER 
{
	EIS_MARKER_MASCULINE		= 10,
	EIS_MARKER_KEENNESS			= 20,
	EIS_MARKER_CONSULTATION		= 30,
	EIS_MARKER_LEARN			= 40,
	EIS_MARKER_REVIEW			= 50
};

enum E_EIS_STUDIES_SUSPENSE 
{
	EIS_SUSPENSE_REDO			= 0x00000001,
	EIS_SUSPENSE_AMENDMENT		= 0x00000002,
	EIS_SUSPENSE_CONSUME		= 0x00000004
};

enum E_EIS_STUDIES_FILMS 
{
	EIS_FILMS_ZERO				= 0,
	EIS_FILMS_READY				= 10,
	EIS_FILMS_PRINT				= 11,
	EIS_FILMS_OK				= 100,
	EIS_FILMS_OUT				= 110,
	EIS_FILMS_FALSE				= 119,
	EIS_FILMS_CANCEL			= 120
};

enum E_EIS_STUDIES_REVIEWS 
{
	EIS_REVIEWS_ZERO			= 0,
	EIS_REVIEWS_WAIT			= 1,
	EIS_REVIEWS_COMPLETE		= 100
};

enum E_EIS_STUDIES_CONSULTATION 
{
	EIS_CONSULTATION_ZERO		= 0,
	EIS_CONSULTATION_WAIT		= 1,
	EIS_CONSULTATION_COMPLETE	= 100
};

enum E_EIS_STUDIES_QC 
{
	EIS_QC_ZERO					= 0,
	EIS_QC_TECHNOLOGY			= 10,
	EIS_QC_DIAGNOSE				= 50,
	EIS_QC_REQUEST				= 80
};

enum E_EIS_REPORTS
{
	EIS_REPORTS_ZERO			= 0,
	EIS_REPORTS_ADVANCE			= 1,
	EIS_REPORTS_REPORT			= 10,
	EIS_REPORTS_BACK			= 50,
	EIS_REPORTS_APPROVE			= 100,
	EIS_REPORTS_REVIEW			= 120
};

enum E_EIS_REPORTS_OUT 
{
	EIS_REPORTS_OUT_ZERO		= 0,
	EIS_REPORTS_OUT_PRINT		= 100,
	EIS_REPORTS_OUT_OUT			= 110,
	EIS_REPORTS_OUT_BACK		= 120
};

enum E_INSTANCE_AVAILABLE		/// (0008,0056) Instance Availability
{
	EI_AVAILABLE_ONLINE			= 0,		// 在线
	EI_AVAILABLE_NEARLINE		= 10,		// 近线
	EI_AVAILABLE_OFFLINE		= 100,		// 离线
	EI_AVAILABLE_UNAVAILABLE	= 1000
};

enum E_INSTANCE_ARCHIVE_AUTO
{
	EI_ARCHIVE_AUTO_NONE		= 0,
	EI_ARCHIVE_AUTO_READY		= 10,
	EI_ARCHIVE_AUTO_OK			= 100,
	EI_ARCHIVE_AUTO_STOP		= 110,
	EI_ARCHIVE_AUTO_FALSE		= 119,
	EI_ARCHIVE_AUTO_IGNORE		= 120
};

enum E_INSTANCE_AVI_TO_DICOM
{
	EI_AVI_TO_DICOM_NONE		= 0,
	EI_AVI_TO_DICOM_READY		= 10,
	EI_AVI_TO_DICOM_OK			= 100,
	EI_AVI_TO_DICOM_FALSE		= 119
};

enum E_INSTANCE_ARCHIVE_MANUAL
{
	EI_ARCHIVE_MANUAL_NONE		= 0,
	EI_ARCHIVE_MANUAL_READY		= 10,
	EI_ARCHIVE_MANUAL_OK		= 100,
	EI_ARCHIVE_MANUAL_FALSE		= 119,
	EI_ARCHIVE_MANUAL_IGNORE	= 120,
	EI_ARCHIVE_MANUAL_AUTO		= 1000
};

enum E_INSTANCE_STORAGE
{
	EI_STORAGE_NONE				= 0,
	EI_STORAGE_READY			= 10,
	EI_STORAGE_OK				= 100,
	EI_STORAGE_FALSE			= 119,
	EI_STORAGE_IGNORE			= 120
};

enum E_INSTANCE_COMPRESSION
{
	EI_COMPRESSION_NONE			= 0,
	EI_COMPRESSION_OK			= 100,
	EI_COMPRESSION_FALSE		= 119,
	EI_COMPRESSION_IGNORE		= 120
};

enum E_IMAGE_MATCHING
{
	E_MATCHING_NONE				= 0,
	E_MATCHING_ACCESSION_NUMBER	= 1,
	E_MATCHING_PATIENTS_ID		= 2,
	E_MATCHING_PATIENTS_NAME	= 3,
	E_MATCHING_PATIENTS_ALIAS	= 4
};

enum E_OPERATE_COMMANDS
{
	EOC_AUTO_ROUTE				= 0x00001,
	EOC_QR_CONFIRM				= 0x00002,
	EOC_SC_CONFIRM				= 0x00004,
	EOC_SC_CONFIRM_WAIT			= 0x00008,
	EOC_SET_VERIFIED			= 0x01000,
	EOC_IMAGE_ARCHIVE			= 0x10000,
	EOC_IMAGE_DELAY_ARCHIVE		= 0x20000
};

enum E_OPERATE_REQUESTS
{
	EOR_RECEIVE_AUTO_ROUTE		= 0x0001,	// 
	EOR_RECEIVE_QR_CONFIRM		= 0x0002,
	EOR_RECEIVE_SC_CONFIRM		= 0x0004,

	EOR_FAILURE_AUTO_ROUTE		= 0x0010,
	EOR_FAILURE_QR_CONFIRM		= 0x0020,
	EOR_FAILURE_SC_CONFIRM		= 0x0040,

	EOR_ARCHIVE_AUTO_ROUTE		= 0x0100,
	EOR_ARCHIVE_QR_CONFIRM		= 0x0200,
	EOR_ARCHIVE_SC_CONFIRM		= 0x0400,

	EOR_ARCHIVE_SET_VERIFIED	= 0x1000,

	EOR_OPERATE_REQUESTS_NONE	= 0x0000,
	EOR_RECEIVE_MASK			= 0x000F,
	EOR_FAILURE_MASK			= 0x00F0,
	EOR_ARCHIVE_MASK			= 0xFF00,
	EOR_AUTO_ROUTE_MASK			= 0x0111,
	EOR_QR_CONFIRM_MASK			= 0x0222,
	EOR_SC_CONFIRM_MASK			= 0x0444
};

enum E_LINKER_DATABASE
{
	E_DATABASE_NULL				= 0,
	E_DATABASE_SYSTEM			= 10,
	E_DATABASE_PUBLIC_HIS		= 20,
	E_DATABASE_PUBLIC_RIS		= 21,
	E_DATABASE_PUBLIC_HIS_ORACLE= 30,
	E_DATABASE_PUBLIC_ZJJTRJYXGS= 40
};

enum E_LINKER_EXCHANGECODE
{
	E_EXCHANGECODE_REGISTER		= 1,
	E_EXCHANGECODE_UPDATE		= 5,
	E_EXCHANGECODE_DELETE		= 10,
	E_EXCHANGECODE_INSERT		= 15,
	E_EXCHANGECODE_COMPLETE		= 100,
	E_EXCHANGECODE_REPORTS		= 105,
	E_EXCHANGECODE_APPROVE		= 110,
	E_EXCHANGECODE_AMENDMENT	= 115
};


#ifndef RADINFO_DBAPI
#define RADINFO_DBAPI

#define	FILL_STRING_FIELD(lpTarget, lpSource)	strncpy((lpTarget), (lpSource), sizeof(lpTarget) - 1);
#define GET_DB_STRING(OWNER, DATABASE, NAME)	OWNER##m_str##NAME = DATABASE##m_##NAME;
#define SET_DB_STRING(OWNER, DATABASE, NAME)	strncpy((DATABASE##m_##NAME), (OWNER##m_str##NAME), sizeof(DATABASE##m_##NAME) - 1);
#define GET_DB_LONG(OWNER, DATABASE, NAME)		OWNER##m_n##NAME = DATABASE##m_##NAME;
#define SET_DB_LONG(OWNER, DATABASE, NAME)		DATABASE##m_##NAME =OWNER##m_n##NAME;
#define GET_DB_DOUBLE(OWNER, DATABASE, NAME)		OWNER##m_dbl##NAME = DATABASE##m_##NAME;
#define SET_DB_DOUBLE(OWNER, DATABASE, NAME)		DATABASE##m_##NAME =OWNER##m_dbl##NAME;

#define	DECLARE_TABLE(NAME)		\
	typedef COledbTable<Cdbo##NAME##Accessor>		Cdbo##NAME;


#define	DECLARE_VIEW(NAME)		\
	typedef COledbCommand<Cdbo##NAME##Accessor>		Cdbo##NAME;


template <class TAccessor>
class COledbTable : public CCommand<CAccessor<TAccessor> >
{
public:
	CString		m_strSQL;
	CSession*	m_pSession;

	HRESULT SetDataSource(CSession* pSession)		{ m_pSession = pSession; return S_OK; }
	HRESULT SetDataSource(CSession& oledbSession)	{ m_pSession = &oledbSession; return S_OK; }

	HRESULT MoveNext()	{ CCommand<CAccessor<TAccessor> >::ClearRecord(); return CCommand<CAccessor<TAccessor> >::MoveNext(); }

	HRESULT Open(LPCTSTR lpFilter = NULL, BOOL bOrder = FALSE)
	{
		// Set properties for open
		CDBPropSet	propset(DBPROPSET_ROWSET);
		propset.AddProperty(DBPROP_SERVERCURSOR, true );
		propset.AddProperty(DBPROP_SERVERDATAONINSERT, true );
		if (bOrder)
			propset.AddProperty(DBPROP_IRowsetChange, VARIANT_TRUE);
		else
			propset.AddProperty(DBPROP_IRowsetChange, true);
		propset.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);
//		propset.AddProperty(DBPROP_LOCKMODE, DBPROPVAL_LM_SINGLEROW);
		propset.AddProperty(DBPROP_LOCKMODE, DBPROPVAL_LM_NONE);

		LPCTSTR szCommand = NULL;
		HRESULT hr = _CommandClass::GetDefaultCommand(&szCommand);
		if (FAILED(hr))
			return hr;

		m_strSQL = szCommand;
		if (lpFilter != NULL)
		{
			m_strSQL += " ";
			m_strSQL += lpFilter;
		}
		
		hr = CCommand<CAccessor<TAccessor> >::Open(*m_pSession, m_strSQL, &propset);
		if (FAILED(hr))
		{
			LOG_MESSAGE(LL_ERROR | LD_FILE, m_strSQL);
		}
		else
		{
			CCommand<CAccessor<TAccessor> >::ClearRecord();
		}

		return hr;
	}
};

template <class TAccessor>
class COledbCommand : public CCommand<CAccessor<TAccessor> >
{
public:
	CString		m_strSQL;
	CSession*	m_pSession;

	HRESULT SetDataSource(CSession* pSession)		{ m_pSession = pSession; return S_OK; }
	HRESULT SetDataSource(CSession& oledbSession)	{ m_pSession = &oledbSession; return S_OK; }

	HRESULT MoveNext()	{ CCommand<CAccessor<TAccessor> >::ClearRecord(); return CCommand<CAccessor<TAccessor> >::MoveNext(); }

	HRESULT Open(LPCTSTR lpFilter = NULL, BOOL bOrder = FALSE)
	{
		LPCTSTR szCommand = NULL;
		HRESULT hr = _CommandClass::GetDefaultCommand(&szCommand);
		if (FAILED(hr))
			return hr;

		m_strSQL = szCommand;
		if (lpFilter != NULL)
		{
			m_strSQL += " ";
			m_strSQL += lpFilter;
		}

		hr = CCommand<CAccessor<TAccessor> >::Open(*m_pSession, m_strSQL);
		if (FAILED(hr))
		{
			LOG_MESSAGE(LL_ERROR | LD_FILE, m_strSQL);
		}
		else
		{
			CCommand<CAccessor<TAccessor> >::ClearRecord();
		}

		return hr;
	}
};

class COledbExecuteAccessor
{
public:
	LONG m_Index;

BEGIN_COLUMN_MAP(COledbExecuteAccessor)
	COLUMN_ENTRY(1, m_Index)
END_COLUMN_MAP()

DEFINE_COMMAND(COledbExecuteAccessor, _T(""))
};

class COledbExecute : public CCommand<CAccessor<COledbExecuteAccessor> >
{
public:
	HRESULT Execute(CSession* pSession, LPCTSTR lpSQL)
	{
		HRESULT hr = S_OK;

		LONG i = 0;
		while (TRUE)
		{
			hr = CCommand<CAccessor<COledbExecuteAccessor> >::Open(*pSession, lpSQL, NULL, NULL, DBGUID_DEFAULT, FALSE);
			if (!FAILED(hr))
				break;
			else
			{
				if (i++ < 88)
				{
					LOG_ERROR_MINOR_MESSAGE(LL_TRACK | LD_FILE, ME_ERR_DB_OPEN_TABLE, hr, lpSQL);
					Sleep(0);
					continue;
				}
				else
				{
					LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE, hr, lpSQL);
					return hr;
				}
			}
		}

		CCommand<CAccessor<COledbExecuteAccessor> >::Close();
		return hr;
	}
};

class COledbCalculateAccessor
{
public:
	LONG m_ReturnValue;

BEGIN_COLUMN_MAP(COledbCalculateAccessor)
	COLUMN_ENTRY(1, m_ReturnValue)
END_COLUMN_MAP()

DEFINE_COMMAND(COledbCalculateAccessor, _T(""))
};

class COledbCalculate : public CCommand<CAccessor<COledbCalculateAccessor> >
{
public:
	HRESULT Calculate(CSession* pSession, LPCTSTR lpSQL, LONG& nReturnValue)
	{
		nReturnValue = 0;

		HRESULT hr = S_OK;

		LONG i = 0;
		while (TRUE)
		{
			hr = CCommand<CAccessor<COledbCalculateAccessor> >::Open(*pSession, lpSQL, NULL, NULL, DBGUID_DEFAULT, TRUE);
			if (!FAILED(hr))
				break;
			else
			{
				if (i++ < 88)
				{
					LOG_ERROR_MINOR_MESSAGE(LL_TRACK | LD_FILE, ME_ERR_DB_OPEN_TABLE, hr, lpSQL);
					Sleep(0);
					continue;
				}
				else
				{
					LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE, hr, lpSQL);
					return hr;
				}
			}
		}

		this->m_ReturnValue = 0;

		hr = CCommand<CAccessor<COledbCalculateAccessor> >::MoveNext();
		if (hr == S_OK)
			nReturnValue = this->m_ReturnValue;

		CCommand<CAccessor<COledbCalculateAccessor> >::Close();

		return hr;
	}
};

#include "dboMGRControl.H"

DECLARE_TABLE(MGRControl);

class COleSession : public CSession  
{
public:
	SYSTEMTIME	m_timeStart;
	CDataSource	m_dbDataSource;

public:
	HRESULT	Open(const CDataSource& ds)	{ return CSession::Open(ds); }
	HRESULT	StartTransaction()			{ ::GetLocalTime(&m_timeStart); return CSession::StartTransaction(); }

	HRESULT	Abort()
	{
		HRESULT hr = CSession::Abort();

		CTime timeThis = CTime::GetCurrentTime();

		LOG_MESSAGE(LL_DEBUG | LD_FILE, _T("SESSION ABORT"));

		return hr;
	}

	HRESULT	Commit(LPCTSTR lpMessage = NULL)
	{
		HRESULT hr = CSession::Commit();

		SYSTEMTIME timeStop;
		GetLocalTime(&timeStop);
		CTime timeThis(timeStop);

		LONG nMillisecond = (timeStop.wHour - m_timeStart.wHour) * 60;
		nMillisecond = (nMillisecond + (timeStop.wMinute - m_timeStart.wMinute)) * 60;
		nMillisecond = (nMillisecond + (timeStop.wSecond - m_timeStart.wSecond)) * 1000;
		nMillisecond = (nMillisecond + (timeStop.wMilliseconds - m_timeStart.wMilliseconds));

		CString strMessage;
		strMessage.Format(_T("SESSION COMMIT: -----%s-----> %d"), lpMessage, nMillisecond);
		LOG_MESSAGE(LL_DEBUG | LD_FILE, strMessage);

		return hr;
	}

	HRESULT Execute(LPCTSTR lpSQL)
	{
		COledbExecute dbExecute;

		return dbExecute.Execute(this, lpSQL);
	}

	HRESULT Calculate(LPCTSTR lpSQL, LONG& nReturnValue)
	{
		COledbCalculate dbCalculate;

		return dbCalculate.Calculate(this, lpSQL, nReturnValue);
	}

	HRESULT GetControlIndex(LONG nControl, LONG &nCurrent)
	{
		CString strFilter;
		strFilter.Format("WHERE ControlIndex = %d", nControl);

#ifdef INCLUDE_DICOMLIB
		EnterCriticalSection(CCommManager::GetCriticalSection());
#endif

		CdboMGRControl dboControl;
		dboControl.SetDataSource(this);
		HRESULT hr = dboControl.Open(strFilter);
		if (FAILED(hr))
		{
#ifdef INCLUDE_DICOMLIB
			LeaveCriticalSection(CCommManager::GetCriticalSection());
#endif

			LOG_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE, hr);
			return hr;
		}

		if (dboControl.MoveNext() == S_OK)
		{
			nCurrent = ++(dboControl.m_ControlCurrent);
			hr = dboControl.SetData();
			if (FAILED(hr))
			{
				dboControl.Close();

#ifdef INCLUDE_DICOMLIB
				LeaveCriticalSection(CCommManager::GetCriticalSection());
#endif

				LOG_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_DB_UPDATE, hr);
				return hr;
			}
		}
		else
		{
			dboControl.ClearRecord();
			dboControl.m_ControlIndex = nControl;
			dboControl.m_ControlCurrent = 1;
			hr = dboControl.Insert();
			if (FAILED(hr))
			{
				dboControl.Close();

#ifdef INCLUDE_DICOMLIB
				LeaveCriticalSection(CCommManager::GetCriticalSection());
#endif

				LOG_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_DB_INSERT, hr);
				return hr;
			}

			nCurrent = 1;
		}

		dboControl.Close();

#ifdef INCLUDE_DICOMLIB
		LeaveCriticalSection(CCommManager::GetCriticalSection());
#endif

		if (!(nCurrent > 0))
		{
			LOG_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_BADDATA, nCurrent);
			return -1;
		}

		return hr;
	}

public:
	COleSession()			{}
	virtual ~COleSession()	{ this->m_dbDataSource.Close(); CSession::Close(); }
};

#endif	// RADINFO_DBAPI

#include "dboEISExchange.H"
#include "dboEISExchangeFailed.H"
#include "dboEISFavorite.H"
#include "dboEISFavoriteStudies.H"
#include "dboEISLog.H"
#include "dboEISMessage.H"
#include "dboEISPatients.H"
#include "dboEISQueue.H"
#include "dboEISQueueCall.H"
#include "dboEISQueueControl.H"
#include "dboEISReports.H"
#include "dboEISResults.H"
#include "dboEISResultsImage.H"
#include "dboEISService.H"
#include "dboEISStudies.H"
#include "dboEISStudiesConsultation.H"
#include "dboEISStudiesConsume.H"
#include "dboEISStudiesDisease.H"
#include "dboEISStudiesQC.H"
#include "dboEISStudiesReviews.H"
#include "dboFPAssociation.H"
#include "dboFPFilmBox.H"
#include "dboFPFilmImage.H"
#include "dboFPFilmSession.H"
#include "dboFPServices.H"
#include "dboIMGAnnexFile.H"
#include "dboIMGArchive.H"
#include "dboIMGAviFile.H"
#include "dboIMGNearline.H"
#include "dboIMGNearlineStorage.H"
#include "dboIMGNearlineStorageFile.H"
#include "dboIMGOperate.H"
#include "dboMGRBodies.H"
#include "dboMGRBodiesReplace.H"
#include "dboMGRCode.H"
#include "dboMGRConsume.H"
#include "dboMGRDepartment.H"
#include "dboMGRDevice.H"
#include "dboMGRDisease.H"
#include "dboMGRDoctor.H"
#include "dboMGRExamine.H"
#include "dboMGRExamineConsume.H"
#include "dboMGRLinker.H"
#include "dboMGRModalities.H"
#include "dboMGRNode.H"
#include "dboMGRNodeClient.H"
#include "dboMGRPhrase.H"
#include "dboMGRPrivilege.H"
#include "dboMGRSpecs.H"
#include "dboMGRTemplate.H"
#include "dboMGRTemplateDisease.H"
#include "dboPACSFailedImages.H"
#include "dboPACSImages.H"
#include "dboPACSPatients.H"
#include "dboPACSSeries.H"
#include "dboPACSStudies.H"
#include "dboQACSFailedImages.H"
#include "dboQACSImages.H"
#include "dboQACSPatients.H"
#include "dboQACSSeries.H"
#include "dboQACSStudies.H"
#include "dboStorageDVD.H"
#include "dboStorageOrder.H"
#include "dboStorageOrderStudies.H"
#include "dboJHJCPDQHXX.H"
#include "dboJHJCPDJHXX.H"
#include "dboJHPDZSXX.H"
#include "dboMGRHospital.H"

DECLARE_TABLE(EISExchange);
DECLARE_TABLE(EISExchangeFailed);
DECLARE_TABLE(EISFavorite);
DECLARE_TABLE(EISFavoriteStudies);
DECLARE_TABLE(EISLog);
DECLARE_TABLE(EISMessage);
DECLARE_TABLE(EISPatients);
DECLARE_TABLE(EISQueue);
DECLARE_TABLE(EISQueueCall);
DECLARE_TABLE(EISQueueControl);
DECLARE_TABLE(EISReports);
DECLARE_TABLE(EISResults);
DECLARE_TABLE(EISResultsImage);
DECLARE_TABLE(EISService);
DECLARE_TABLE(EISStudies);
DECLARE_TABLE(EISStudiesConsultation);
DECLARE_TABLE(EISStudiesConsume);
DECLARE_TABLE(EISStudiesDisease);
DECLARE_TABLE(EISStudiesQC);
DECLARE_TABLE(EISStudiesReviews);
DECLARE_TABLE(FPAssociation);
DECLARE_TABLE(FPFilmBox);
DECLARE_TABLE(FPFilmImage);
DECLARE_TABLE(FPFilmSession);
DECLARE_TABLE(FPServices);
DECLARE_TABLE(IMGAnnexFile);
DECLARE_TABLE(IMGArchive);
DECLARE_TABLE(IMGAviFile);
DECLARE_TABLE(IMGNearline);
DECLARE_TABLE(IMGNearlineStorage);
DECLARE_TABLE(IMGNearlineStorageFile);
DECLARE_TABLE(IMGOperate);
DECLARE_TABLE(MGRBodies);
DECLARE_TABLE(MGRBodiesReplace);
DECLARE_TABLE(MGRCode);
DECLARE_TABLE(MGRConsume);
DECLARE_TABLE(MGRDepartment);
DECLARE_TABLE(MGRDevice);
DECLARE_TABLE(MGRDisease);
DECLARE_TABLE(MGRDoctor);
DECLARE_TABLE(MGRExamine);
DECLARE_TABLE(MGRExamineConsume);
DECLARE_TABLE(MGRLinker);
DECLARE_TABLE(MGRModalities);
DECLARE_TABLE(MGRNode);
DECLARE_TABLE(MGRNodeClient);
DECLARE_TABLE(MGRPhrase);
DECLARE_TABLE(MGRPrivilege);
DECLARE_TABLE(MGRSpecs);
DECLARE_TABLE(MGRTemplate);
DECLARE_TABLE(MGRTemplateDisease);
DECLARE_TABLE(PACSFailedImages);
DECLARE_TABLE(PACSImages);
DECLARE_TABLE(PACSPatients);
DECLARE_TABLE(PACSSeries);
DECLARE_TABLE(PACSStudies);
DECLARE_TABLE(QACSFailedImages);
DECLARE_TABLE(QACSImages);
DECLARE_TABLE(QACSPatients);
DECLARE_TABLE(QACSSeries);
DECLARE_TABLE(QACSStudies);
DECLARE_TABLE(StorageDVD);
DECLARE_TABLE(StorageOrder);
DECLARE_TABLE(StorageOrderStudies);
DECLARE_TABLE(JHJCPDQHXX);
DECLARE_TABLE(JHJCPDJHXX);
DECLARE_TABLE(JHPDZSXX);
DECLARE_TABLE(MGRHospital);

#include "dbovEISExchange.H"
#include "dbovEISMwl.H"
#include "dbovEISQueueCall.H"
#include "dbovEISStudies.H"
#include "dbovEISWorksLists.H"
#include "dbovEISWorksService.H"
#include "dbovEISWorksVersions.H"
#include "dbovFPFilmSession.H"
#include "dbovFPImages.H"
#include "dbovFPServices.H"
#include "dbovIMGArchive.H"
#include "dbovIMGOperate.H"
#include "dbovMGRBodiesReplace.H"
#include "dbovMGRDoctor.H"
#include "dbovMGRExamine.H"
#include "dbovMGRExamineConsume.H"
#include "dbovMGRNodeClient.H"
#include "dbovPACSImages.H"
#include "dbovPACSPatients.H"
#include "dbovPACSSeries.H"
#include "dbovPACSStudies.H"
#include "dbovQACSImages.H"
#include "dbovQACSPatients.H"
#include "dbovQACSSeries.H"
#include "dbovQACSStudies.H"
#include "dbovStorageOrderStudies.H"

DECLARE_VIEW(vEISExchange);
DECLARE_VIEW(vEISMwl);
DECLARE_VIEW(vEISQueueCall);
DECLARE_VIEW(vEISStudies);
DECLARE_VIEW(vEISWorksLists);
DECLARE_VIEW(vEISWorksService);
DECLARE_VIEW(vEISWorksVersions);
DECLARE_VIEW(vFPFilmSession);
DECLARE_VIEW(vFPImages);
DECLARE_VIEW(vFPServices);
DECLARE_VIEW(vIMGArchive);
DECLARE_VIEW(vIMGOperate);
DECLARE_VIEW(vMGRBodiesReplace);
DECLARE_VIEW(vMGRDoctor);
DECLARE_VIEW(vMGRExamine);
DECLARE_VIEW(vMGRExamineConsume);
DECLARE_VIEW(vMGRNodeClient);
DECLARE_VIEW(vPACSImages);
DECLARE_VIEW(vPACSPatients);
DECLARE_VIEW(vPACSSeries);
DECLARE_VIEW(vPACSStudies);
DECLARE_VIEW(vQACSImages);
DECLARE_VIEW(vQACSPatients);
DECLARE_VIEW(vQACSSeries);
DECLARE_VIEW(vQACSStudies);
DECLARE_VIEW(vStorageOrderStudies);


#endif // !defined(AFX_DATABASE_H__89C77E7D_79C5_41D1_8607_34DDBBFF48EB__INCLUDED_)
