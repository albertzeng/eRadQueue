// RunTime.cpp: implementation of the CRunTime class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RunTime.h"
#include "ToolsEx.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

static CRunTime _RunTime;

#define REG_EXCHANGE_PRIVATE(NAME, MEMBER)							\
	strSubKey.Format(_T("SOFTWARE\\RADinfo.com.cn\\%s"), (NAME));	\
	if (!bSave)														\
		nRet = ::RegOpenKeyEx(HKEY_CURRENT_USER, strSubKey, 0, KEY_QUERY_VALUE, &hKey);	\
	if (bSave || nRet != ERROR_SUCCESS)								\
		nRet = ::RegCreateKeyEx(HKEY_CURRENT_USER, strSubKey, NULL, NULL, 0, KEY_ALL_ACCESS, NULL, &hKey, NULL);	\
	if (nRet == ERROR_SUCCESS) {									\
		MEMBER->Exchange(hKey, bSave);								\
		RegCloseKey(hKey);											\
	}																\


#define REG_EXCHANGE_KEY(NAME, MEMBER)								\
	strSubKey.Format(_T("SOFTWARE\\RADinfo.com.cn\\%s"), (NAME));	\
	if (!bSave)														\
		nRet = ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, strSubKey, 0, KEY_QUERY_VALUE, &hKey);	\
	if (bSave || nRet != ERROR_SUCCESS)								\
		nRet = ::RegCreateKeyEx(HKEY_LOCAL_MACHINE, strSubKey, NULL, NULL, 0, KEY_ALL_ACCESS, NULL, &hKey, NULL);	\
	if (nRet == ERROR_SUCCESS) {									\
		MEMBER->Exchange(hKey, bSave);								\
		RegCloseKey(hKey);											\
	}																\


#define REG_EXCHANGE_VALUE_S(NAME, MEMBER, DEFAULT)					\
	if (bSave)														\
		::RegSetValueEx(hKey, (NAME), NULL, REG_SZ, (LPBYTE) (LPCTSTR) MEMBER, MEMBER.GetLength() + 1);	\
	else {															\
		char lpBuffer[1024];										\
		DWORD dwSize = sizeof(lpBuffer);							\
		LONG nRet = ::RegQueryValueEx(hKey, (NAME), NULL, NULL, (LPBYTE) &lpBuffer, &dwSize);	\
		MEMBER = (nRet == ERROR_SUCCESS) ? lpBuffer : (DEFAULT);	\
	}																\


#define REG_EXCHANGE_VALUE_D(NAME, MEMBER, DEFAULT)					\
	if (bSave)														\
		::RegSetValueEx(hKey, (NAME), NULL, REG_DWORD, (LPBYTE) &MEMBER, sizeof(MEMBER));	\
	else {															\
		DWORD dwValue = 0;											\
		DWORD dwSize = sizeof(DWORD);								\
		LONG nRet = ::RegQueryValueEx(hKey, (NAME), NULL, NULL, (LPBYTE) &dwValue, &dwSize);	\
		MEMBER = (nRet == ERROR_SUCCESS) ? dwValue : (DEFAULT);		\
	}																\


#define INI_EXCHANGE_VALUE_S(NAME, MEMBER, DEFAULT, FILE)			\
	if (bSave) {													\
		BOOL bRet = ::WritePrivateProfileString(strSection, NAME, MEMBER, FILE);	\
		if (!bRet) {												\
			LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_SAVE_FILE, ::GetLastError(), FILE);	\
		}															\
	}																\
	else {															\
		char lpBuffer[1024];										\
		DWORD dwRet = ::GetPrivateProfileString(strSection, NAME, "", lpBuffer, sizeof(lpBuffer), FILE);	\
		MEMBER = (dwRet > 0) ? lpBuffer : DEFAULT;					\
	}																\


#define INI_EXCHANGE_VALUE_D(NAME, MEMBER, DEFAULT, FILE)			\
	if (bSave) {													\
		strBuffer.Format(_T("%d"), MEMBER);							\
		BOOL bRet = ::WritePrivateProfileString(strSection, NAME, strBuffer, FILE);	\
		if (!bRet) {												\
			LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_SAVE_FILE, ::GetLastError(), FILE);	\
		}															\
	}																\
	else {															\
		char lpBuffer[1024];										\
		DWORD dwRet = ::GetPrivateProfileString(strSection, NAME, "", lpBuffer, sizeof(lpBuffer), FILE);	\
		MEMBER = (dwRet > 0) ? atoi(lpBuffer) : DEFAULT;			\
	}																\


#define PRIVATE_EXCHANGE_VALUE_S(NAME, MEMBER, DEFAULT)				\
	if (CRunTime::GetGeneral()->m_bPrivateSaveToFile) {				\
		INI_EXCHANGE_VALUE_S(NAME, MEMBER, DEFAULT, CRunTime::GetUser()->m_strPrivateSaveToFile);	\
	}																\
	else {															\
		REG_EXCHANGE_VALUE_S(NAME, MEMBER, DEFAULT);				\
	}																\


#define PRIVATE_EXCHANGE_VALUE_D(NAME, MEMBER, DEFAULT)				\
	if (CRunTime::GetGeneral()->m_bPrivateSaveToFile) {				\
		INI_EXCHANGE_VALUE_D(NAME, MEMBER, DEFAULT, CRunTime::GetUser()->m_strPrivateSaveToFile);	\
	}																\
	else {															\
		REG_EXCHANGE_VALUE_D(NAME, MEMBER, DEFAULT);				\
	}																\


//////////////////////////////////////////////////////////////////////
// CRunTime Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BOOL CRunTime::CGeneral::ExchangeXML(CXmlParse* pXmlParse, LPVOID lpvNode, BOOL bSave, LPCTSTR lpSpace)
{
	IXMLDOMNode* pNode = (IXMLDOMNode*) lpvNode;

	XML_EXCHANGE_VALUE(_T("Call_Node"),							this->m_nCallNode,				0				)
	XML_EXCHANGE_VALUE(_T("Call_Name"),							this->m_strCallName,			_T("")			)
	XML_EXCHANGE_VALUE(_T("Call_Console"),						this->m_strCallConsole,			_T("")			)
	XML_EXCHANGE_VALUE(_T("Call_Device"),						this->m_strCallDevice,			_T("")			)
	XML_EXCHANGE_VALUE(_T("Call_Room"),							this->m_strCallRoom,			_T("")			)
	XML_EXCHANGE_VALUE(_T("Call_RoomNode"),						this->m_strCallRoomNode,		_T("")			)
	XML_EXCHANGE_VALUE(_T("MZ_QUEUE"),							this->m_strMZQueue,			    _T("")			)
	XML_EXCHANGE_VALUE(_T("ZY_QUEUE"),							this->m_strZYQueue,			    _T("")			)
	XML_EXCHANGE_VALUE(_T("Call_Department"),					this->m_nCallDepartment,		0				)
	XML_EXCHANGE_VALUE(_T("Call_Priority"),						this->m_bCallPriority,			TRUE			)
	XML_EXCHANGE_VALUE(_T("Call_Order"),						this->m_bCallOrder,				TRUE			)
	XML_EXCHANGE_VALUE(_T("Call_Capture_Report"),				this->m_bCallCaptureReport,		FALSE			)
	XML_EXCHANGE_VALUE(_T("Call_Capture"),						this->m_bCallCapture,			FALSE			)
	XML_EXCHANGE_VALUE(_T("Call_Report"),						this->m_bCallReport,			FALSE			)
	XML_EXCHANGE_VALUE(_T("Call_Complete"),						this->m_bCallComplete,			FALSE			)
	XML_EXCHANGE_VALUE(_T("Call_Reset"),						this->m_bCallReset,				FALSE			)
	XML_EXCHANGE_VALUE(_T("Call_Increment"),					this->m_nCallIncrement,			3				)
	XML_EXCHANGE_VALUE(_T("Call_Cancel"),						this->m_bCallCancel,			TRUE			)
	XML_EXCHANGE_VALUE(_T("Call_Unready"),						this->m_bCallUnready,			FALSE			)
	XML_EXCHANGE_VALUE(_T("Call_Wait"),							this->m_bCallWait,				FALSE			)
	XML_EXCHANGE_VALUE(_T("Afternoon"),							this->m_bAfternoon,				FALSE			)
	XML_EXCHANGE_VALUE(_T("Afternoon_Time"),					this->m_strAfternoonTime,		_T("1300")		)
	XML_EXCHANGE_VALUE(_T("Auto_Refresh"),						this->m_nAutoRefresh,			180				)
	XML_EXCHANGE_VALUE(_T("Private_Save_To_File"),				this->m_bPrivateSaveToFile,		TRUE			)
    XML_EXCHANGE_VALUE(_T("Call_No_Report"),                    this->m_bCallOrderNoReport,      FALSE          )
	XML_EXCHANGE_VALUE(_T("Call_QueueRoom"),                    this->m_bCallIQueueRoom,          FALSE         )
	XML_EXCHANGE_VALUE(_T("Call_QueuePatientKind"),             this->m_bCallQueuePatientKind,    FALSE         )
	XML_EXCHANGE_VALUE(_T("NOPOP_CalOrder"),					this->m_bNoPopOrderCall,		TRUE			)
	XML_EXCHANGE_VALUE(_T("Call_Pre"),					        this->m_bCallPre,		        TRUE			)
	XML_EXCHANGE_VALUE(_T("LOG_TRACK"),							this->m_bLogTRACK,				FALSE			)
	XML_EXCHANGE_VALUE(_T("LOG_DEBUG"),							this->m_bLogDEBUG,				TRUE			)
	XML_EXCHANGE_VALUE(_T("LOG_ERROR"),							this->m_bLogERROR,				TRUE			)
	XML_EXCHANGE_VALUE(_T("LOG_MESSAGE"),						this->m_bLogMESSAGE,			TRUE			)

	XML_EXCHANGE_VALUE(_T("EIS_Database"),						this->m_strEISDatabase,			_T("")			)

	return TRUE;
}

BOOL CRunTime::CUser::Exchange(HKEY& hKey, BOOL bSave)
{
	CString strBuffer;
	CString strSection = _T("General");

	PRIVATE_EXCHANGE_VALUE_D(_T("DialogQueueLeft"),				this->m_recDlgQueue.left,		0				)
	PRIVATE_EXCHANGE_VALUE_D(_T("DialogQueueTop"),				this->m_recDlgQueue.top,		0				)
	PRIVATE_EXCHANGE_VALUE_D(_T("DialogQueueRight"),			this->m_recDlgQueue.right,		0				)
	PRIVATE_EXCHANGE_VALUE_D(_T("DialogQueueBottom"),			this->m_recDlgQueue.bottom,		0				)

	return TRUE;
}

//////////////////////////////////////////////////////////////////////
// CRunTime Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRunTime::CRunTime()
{
}

CRunTime::~CRunTime()
{
}

MRET CRunTime::Load()
{
	MRET rc = CRunTime::ExchangeXML();
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}
	
	return ME_OK;
}

MRET CRunTime::ExchangeXML(BOOL bSave)
{
	TRACE(_T("CALL CRunTime::ExchangeXML()\n"));

	CString strXML, strFileName;

	char lpModule[_MAX_PATH];
	::GetModuleFileName(NULL, lpModule, sizeof(lpModule));

	char lpDrive[_MAX_PATH], lpDir[_MAX_PATH];
	::_splitpath(lpModule, lpDrive, lpDir, NULL, NULL);

	strcat(lpDrive, lpDir);
	::SetCurrentDirectory(lpDrive);

	strFileName.Format("%sINI\\eRadQueueCall.xml", lpDrive);
	CRunTime::GetGeneral()->m_strPublicSaveToFile.Format(_T("%sINI\\eRadQueueCall.ini"), lpDrive);

	FILE* file = fopen(CRunTime::GetGeneral()->m_strPublicSaveToFile, _T("a"));
	if (file != NULL)
		fclose(file);
	else
	{
		LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_OPEN_FILE, ::GetLastError(), CRunTime::GetGeneral()->m_strPublicSaveToFile);
	}

	if (!bSave)
	{
		CIstreamFile IOstreamFile;
		MRET rc = IOstreamFile.Initialize(strFileName);
		if (rc != ME_OK)
		{
			LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, rc, strFileName);
		}
		else
		{
			LONG nFileSize = IOstreamFile.Available();
			if (nFileSize == 0)
			{
				LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, strFileName);
			}

			LPBYTE lpXML = CTools::Alloc(nFileSize + 10);
			rc = IOstreamFile.Read(lpXML, nFileSize);
			if (rc != ME_OK)
			{
				delete lpXML;
				LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, rc, strFileName);
			}

			strXML = (LPCTSTR) lpXML;

			delete lpXML;
		}
	}

	XML_EXCHANGE_START(strXML);

	XML_EXCHANGE_KEY(_T("General"),					CRunTime::GetGeneral());

	XML_EXCHANGE_CLOSE(strXML);

	if (bSave)
	{
		HANDLE hFile = CreateFile(strFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hFile == INVALID_HANDLE_VALUE)
		{
			LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_OPEN_FILE, strFileName);
		}

		COstreamFile IOstreamFile;
		MRET rc = IOstreamFile.SetFile(hFile);
		if (rc != ME_OK)
		{
			CloseHandle(hFile);
			LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, rc, strFileName);
		}

		rc = IOstreamFile.Write((LPVOID) (LPCTSTR) strXML, strXML.GetLength());
		if (rc != ME_OK)
		{
			CloseHandle(hFile);
			LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, rc, strFileName);
		}

		rc = IOstreamFile.Flush();
		if (rc != ME_OK)
		{
			CloseHandle(hFile);
			LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, rc, strFileName);
		}

		CloseHandle(hFile);
	}

	return ME_OK;
}

BOOL CRunTime::ExchangePublic(BOOL bSave)
{
	CString strBuffer, strSection(_T("Public"));

	return TRUE;
}

BOOL CRunTime::ExchangePrivate(BOOL bSave)
{
    HKEY hKey = NULL;
	LONG nRet = ERROR_SUCCESS;
	CString strSubKey;

	if (CRunTime::GetGeneral()->m_bPrivateSaveToFile)
		CRunTime::GetUser()->Exchange(hKey, bSave);
	else
	{
		REG_EXCHANGE_PRIVATE(_T("eRadQueueCall\\General"), CRunTime::GetUser());
	}

	return TRUE;
}

COleSession* CRunTime::GetEISSession(COleSession* pSession)
{
	if (CRunTime::GetGeneral()->m_strEISDatabase.IsEmpty())
	{
		pSession = NULL;

		LOG_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_CONFIGURATION);
	}
	else
	{
		BSTR bstrConnect = CRunTime::GetGeneral()->m_strEISDatabase.AllocSysString();

		HRESULT hr = pSession->m_dbDataSource.OpenFromInitializationString(bstrConnect);
		if (hr != S_OK)
		{
			pSession = NULL;

			LOG_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN, hr);
		}
		else
		{
			pSession->Open(pSession->m_dbDataSource);
		}

		SysFreeString(bstrConnect);
	}

	return pSession;
}

CRunTime::CGeneral*						CRunTime::GetGeneral()				{ return &_RunTime.m_General; }
CRunTime::CUser*						CRunTime::GetUser()					{ return &_RunTime.m_User; }
CRunTime::CGui*							CRunTime::GetGUI()					{ return &_RunTime.m_Gui; }

LONG CRunTime::GetLogLevel()
{
	LONG nLogLevel = 0;

	if (CRunTime::GetGeneral()->m_bLogTRACK)	nLogLevel |= LL_TRACK;
	if (CRunTime::GetGeneral()->m_bLogDEBUG)	nLogLevel |= LL_DEBUG;
	if (CRunTime::GetGeneral()->m_bLogERROR)	nLogLevel |= LL_ERROR;
	if (CRunTime::GetGeneral()->m_bLogMESSAGE)	nLogLevel |= LL_MESSAGE;

	return nLogLevel;
}
