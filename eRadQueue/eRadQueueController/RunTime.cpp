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

	XML_EXCHANGE_VALUE(_T("LOG_TRACK"),							this->m_bLogTRACK,				FALSE			)
	XML_EXCHANGE_VALUE(_T("LOG_DEBUG"),							this->m_bLogDEBUG,				TRUE			)
	XML_EXCHANGE_VALUE(_T("LOG_ERROR"),							this->m_bLogERROR,				TRUE			)
	XML_EXCHANGE_VALUE(_T("LOG_MESSAGE"),						this->m_bLogMESSAGE,			TRUE			)
	XML_EXCHANGE_VALUE(_T("Use_Department"),					this->m_nUseDepartment,			0				)

	XML_EXCHANGE_VALUE(_T("Voice_Class"),						this->m_nVoiceClass,			0				)
	XML_EXCHANGE_VALUE(_T("Voice_Description"),					this->m_strVoiceDescription,	_T("")			)
	XML_EXCHANGE_VALUE(_T("Voice_Rate"),						this->m_nVoiceRate,				0				)
	XML_EXCHANGE_VALUE(_T("Voice_Volume"),						this->m_nVoiceVolume,			100				)
	XML_EXCHANGE_VALUE(_T("Voice_Play"),						this->m_strVoicePlay,			_T("")			)

	XML_EXCHANGE_VALUE(_T("EIS_Database"),						this->m_strEISDatabase,			_T("")			)

	XML_EXCHANGE_VALUE(_T("AutoLogin"),						    this->m_bAutoLogin,		     	FALSE			)
    XML_EXCHANGE_VALUE(_T("AutoDoctorCode"),					this->m_strAutoDoctorCode,		_T("")			)
	XML_EXCHANGE_VALUE(_T("HideName"),						    this->m_bHideName,		     	FALSE			)
	
	return TRUE;
}

BOOL CRunTime::CITEMVideo::ExchangeXML(CXmlParse* pXmlParse, LPVOID lpvNode, BOOL bSave, LPCTSTR lpSpace)
{
	IXMLDOMNode* pNode = (IXMLDOMNode*) lpvNode;

	LONG nVideoForeground = 0;
	if (bSave)
		nVideoForeground = CRunTime::GetColor(this->m_clrVideoForeground);

	XML_EXCHANGE_VALUE(_T("Controller_Node"),					this->m_nControllerNode,		0				)
	XML_EXCHANGE_VALUE(_T("Video_Order"),						this->m_nVideoOrder,			0				)
	XML_EXCHANGE_VALUE(_T("Video_Length"),						this->m_nVideoLength,			1				)
	XML_EXCHANGE_VALUE(_T("Video_Content"),						this->m_strVideoContent,		_T("")			)
	XML_EXCHANGE_VALUE(_T("Video_Foreground"),					nVideoForeground,				0xFFFFFF		)

	if (!bSave)
		this->m_clrVideoForeground = CRunTime::GetColor(nVideoForeground);

	return TRUE;
}

BOOL CRunTime::CITEMColumn::ExchangeXML(CXmlParse* pXmlParse, LPVOID lpvNode, BOOL bSave, LPCTSTR lpSpace)
{
	IXMLDOMNode* pNode = (IXMLDOMNode*) lpvNode;
	LONG nclrColumnNameForeground = 0,	 nclrColumnNameBackground = 0, nclrColumnForeground = 0, nclrColumnBackground = 0;
	if (bSave)
	{
		nclrColumnNameForeground	= CRunTime::GetColor(this->m_clrColumnNameForeground);	
		nclrColumnNameBackground	= CRunTime::GetColor(this->m_clrColumnNameBackground);	
		nclrColumnForeground	= CRunTime::GetColor(this->m_clrColumnForeground);	
		nclrColumnBackground	= CRunTime::GetColor(this->m_clrColumnBackground);
		
	}
	
    	XML_EXCHANGE_VALUE(_T("Control_ID"),					this->m_ControlID,		            0		)
		XML_EXCHANGE_VALUE(_T("MODE_ColumnId"),					this->m_MODE3ColumnId,		        0		)
		XML_EXCHANGE_VALUE(_T("MODE_ColumnName"),				this->m_MODE3ColumnName,			_T("")	)
		XML_EXCHANGE_VALUE(_T("MODE_ColumnRows"),				this->m_MODE3ColumnRows,			1		)
		XML_EXCHANGE_VALUE(_T("MODE_ColumnLines"),				this->m_MODE3ColumnLines,		    1	    )
		XML_EXCHANGE_VALUE(_T("MODE_ColumnTop"),			    this->m_MODE3ColumnTop,			    0		)
		XML_EXCHANGE_VALUE(_T("MODE_ColumnLeft"),				this->m_MODE3ColumnLeft,			0		)
		XML_EXCHANGE_VALUE(_T("MODE_ColumnBottom"),				this->m_MODE3ColumnBottom,			0		)
		XML_EXCHANGE_VALUE(_T("MODE_ColumnRight"),				this->m_MODE3ColumnRight,		  	0		)
		
		XML_EXCHANGE_VALUE(_T("MODE_ColumnNameForeground"),		nclrColumnNameForeground,	        0xFF0000)
		XML_EXCHANGE_VALUE(_T("MODE_ColumnNameBackground"),	    nclrColumnNameBackground,	        0x000000)
		XML_EXCHANGE_VALUE(_T("MODE_ColumnNameFontName"),		this->m_strColumnNameFontName,		_T("")	)
		XML_EXCHANGE_VALUE(_T("MODE_ColumnNameFontSize"),		this->m_nColumnNameFontSize,		18		)
		
		XML_EXCHANGE_VALUE(_T("MODE_ColumnForeground"),			nclrColumnForeground,	        	0xFF0000)
		XML_EXCHANGE_VALUE(_T("MODE_ColumnBackground"),			nclrColumnBackground,	        	0x000000)
		XML_EXCHANGE_VALUE(_T("MODE_ColumnFontName"),			this->m_strColumnFontName,			_T("")	)
		XML_EXCHANGE_VALUE(_T("MODE_ColumnFontSize"),			this->m_nColumnFontSize,			18		)
		
		
		if (!bSave)
		{
	    	this->m_clrColumnNameForeground	= CRunTime::GetColor(nclrColumnNameForeground);	
			this->m_clrColumnNameBackground	= CRunTime::GetColor(nclrColumnNameBackground);	
			this->m_clrColumnForeground	= CRunTime::GetColor(nclrColumnForeground);	
			this->m_clrColumnBackground	= CRunTime::GetColor(nclrColumnBackground);	
		}
		return TRUE;
}


BOOL CRunTime::CITEMController::ExchangeXML(CXmlParse* pXmlParse, LPVOID lpvNode, BOOL bSave, LPCTSTR lpSpace)
{
	IXMLDOMNode* pNode = (IXMLDOMNode*) lpvNode;

	LONG nControllerBackground = 0, nScrollBackground = 0, nScrollForeground = 0, nTitleBackground = 0, nTitleForeground = 0;
	if (bSave)
	{
		nControllerBackground	= CRunTime::GetColor(this->m_clrControllerBackground);
		nScrollBackground		= CRunTime::GetColor(this->m_clrScrollBackground);
		nScrollForeground		= CRunTime::GetColor(this->m_clrScrollForeground);
		nTitleBackground		= CRunTime::GetColor(this->m_clrTitleBackground);
		nTitleForeground		= CRunTime::GetColor(this->m_clrTitleForeground);
	}

	XML_EXCHANGE_VALUE(_T("Controller_Node"),					this->m_nControllerNode,		0				)
	XML_EXCHANGE_VALUE(_T("Controller_Name"),					this->m_strControllerName,		_T("")			)
	XML_EXCHANGE_VALUE(_T("Controller_Mode"),					this->m_nControllerMode,		0				)
	XML_EXCHANGE_VALUE(_T("Controller_Left"),					this->m_nControllerLeft,		0				)
	XML_EXCHANGE_VALUE(_T("Controller_Top"),					this->m_nControllerTop,			0				)
	XML_EXCHANGE_VALUE(_T("Controller_Width"),					this->m_nControllerWidth,		0				)
	XML_EXCHANGE_VALUE(_T("Controller_Height"),					this->m_nControllerHeight,		0				)
	XML_EXCHANGE_VALUE(_T("Controller_Rows"),					this->m_nControllerRows,		8				)
	XML_EXCHANGE_VALUE(_T("Controller_Cols"),					this->m_nControllerCols,		1				)
	XML_EXCHANGE_VALUE(_T("Controller_From_Top"),				this->m_bControllerFromTop,		TRUE			)
	XML_EXCHANGE_VALUE(_T("Controller_Font_Name"),				this->m_strControllerFontName,	_T("")			)
	XML_EXCHANGE_VALUE(_T("Controller_Font_Size"),				this->m_nControllerFontSize,	18				)
	XML_EXCHANGE_VALUE(_T("Controller_Background"),				nControllerBackground,			0x0000FF		)
	XML_EXCHANGE_VALUE(_T("Controller_BDesc"),					this->m_bDesc,				    FALSE		    )
	XML_EXCHANGE_VALUE(_T("Controller_BScr"),					this->m_bScroll,				FALSE		    )

	XML_EXCHANGE_VALUE(_T("Scroll_Enable"),						this->m_bScrollEnable,			FALSE			)
	XML_EXCHANGE_VALUE(_T("Scroll_Height"),						this->m_nScrollHeight,			100				)
	XML_EXCHANGE_VALUE(_T("Scroll_Speed"),						this->m_nScrollSpeed,			10				)
	XML_EXCHANGE_VALUE(_T("Scroll_QueueSpeed"),					this->m_nQueueScrollSpeed,		10				)
	XML_EXCHANGE_VALUE(_T("Scroll_Content"),					this->m_strScrollContent,		_T("")			)
	XML_EXCHANGE_VALUE(_T("Scroll_Font_Name"),					this->m_strScrollFontName,		_T("")			)
	XML_EXCHANGE_VALUE(_T("Scroll_Font_Size"),					this->m_nScrollFontSize,		18				)
	XML_EXCHANGE_VALUE(_T("Scroll_Background"),					nScrollBackground,				0x000000		)
	XML_EXCHANGE_VALUE(_T("Scroll_Foreground"),					nScrollForeground,				0xFF0000		)

	XML_EXCHANGE_VALUE(_T("Title_Enable"),						this->m_bTitleEnable,			FALSE			)
	XML_EXCHANGE_VALUE(_T("Title_Content"),						this->m_strTitleContent,		_T("")			)
	XML_EXCHANGE_VALUE(_T("Title_Height"),						this->m_nTitleHeight,			100				)
	XML_EXCHANGE_VALUE(_T("Title_Font_Name"),					this->m_strTitleFontName,		_T("")			)
	XML_EXCHANGE_VALUE(_T("Title_Font_Size"),					this->m_nTitleFontSize,			18				)
	XML_EXCHANGE_VALUE(_T("Title_Background"),					nTitleBackground,				0x000000		)
	XML_EXCHANGE_VALUE(_T("Title_Foreground"),					nTitleForeground,				0xFF0000		)
	

	XML_EXCHANGE_VALUE(_T("Voice_Enable"),						this->m_bVoiceEnable,			FALSE			)
	XML_EXCHANGE_VALUE(_T("Voice_Repeat"),						this->m_nVoiceRepeat,			2				)
	XML_EXCHANGE_VALUE(_T("Voice_Interval_S"),					this->m_nVoiceInterval,			1				)
	XML_EXCHANGE_VALUE(_T("Voice_Format"),						this->m_strVoiceFormat,			_T("")			)
	XML_EXCHANGE_VALUE(_T("Voice_PromptEnable"),				this->m_bpromptVoiceEnable,	    FALSE			)
    XML_EXCHANGE_VALUE(_T("Voice_BUseKdfx"),				    this->m_bUseKdfx,	           FALSE			)
	XML_EXCHANGE_VALUE(_T("Voice_StrSeriesId"),				    this->m_strSeriesId,	          _T("")		)


	XML_EXCHANGE_VALUE(_T("Mode1_Time_Range_H"),				this->m_nMode1TimeRange,		24				)
	XML_EXCHANGE_VALUE(_T("Mode1_Time_Delay_M"),				this->m_nMode1TimeDelay,		10				)
	XML_EXCHANGE_VALUE(_T("Mode1_Refresh_Idle_S"),				this->m_nMode1RefreshIdle,		60				)
	XML_EXCHANGE_VALUE(_T("Mode1_Refresh_Screen_S"),			this->m_nMode1RefreshScreen,	10				)
	XML_EXCHANGE_VALUE(_T("Mode1_Admission_Source"),			this->m_strMode1AdmissionSource,_T("")			)
	XML_EXCHANGE_VALUE(_T("Mode1_Exclude_Out_Status"),			this->m_strMode1ExcludeOutStatus,_T("")			)
	XML_EXCHANGE_VALUE(_T("Mode1_Source_Hospital"),			    this->m_strMode1SourceHospital, _T("")			)
	XML_EXCHANGE_VALUE(_T("Mode1_Order_Mode"),					this->m_nMode1OrderMode,		0				)

	XML_EXCHANGE_VALUE(_T("Mode2_Device_Index"),				this->m_nMode2DeviceIndex,		0				)
	XML_EXCHANGE_VALUE(_T("Mode2_Refresh_Idle"),				this->m_nMode2RefreshIdle,		60				)


	XML_EXCHANGE_VALUE(_T("Mode3_Device_Index"),				this->m_MODE3QueueIndex,		0				)
	XML_EXCHANGE_VALUE(_T("Mode3_Refresh_Idle"),				this->m_MODE3RenovateTime,		60				)
	XML_EXCHANGE_VALUE(_T("Mode3_bShowHorizontal"),			    this->m_bShowHorizontal,		FALSE			)


	if (!bSave)
	{
		this->m_clrControllerBackground	= CRunTime::GetColor(nControllerBackground);
		this->m_clrScrollBackground		= CRunTime::GetColor(nScrollBackground);
		this->m_clrScrollForeground		= CRunTime::GetColor(nScrollForeground);
		this->m_clrTitleBackground		= CRunTime::GetColor(nTitleBackground);
		this->m_clrTitleForeground		= CRunTime::GetColor(nTitleForeground);

		if (this->m_nControllerRows < 1) this->m_nControllerRows = 1;
		if (this->m_nControllerCols < 1) this->m_nControllerCols = 1;
	}

	return TRUE;
}

BOOL CRunTime::CUser::Exchange(HKEY& hKey, BOOL bSave)
{
	CString strBuffer;
	CString strSection = _T("General");

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

	strFileName.Format("%sINI\\eRadQueueController.xml", lpDrive);

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

	COBList<CITEMVideo>	lstVideo;
	if (bSave)
	{
		OBPOS POS = NULL, POS1 = NULL;
		for (CITEMController* IT = CRunTime::GetLstController()->GetHead(POS); IT != NULL; IT = CRunTime::GetLstController()->GetNext(POS))
			while (IT->m_lstVideo.GetHead(POS1) != NULL)
			{
				CITEMVideo* pVideo = IT->m_lstVideo.Remove(POS1);

				pVideo->m_nControllerNode = IT->m_nControllerNode;

				lstVideo.AddTail(pVideo);
			}
	}


	COBList<CITEMColumn> lstColumn;
	if (bSave)
	{
		OBPOS POS = NULL, POS1 = NULL;
		for (CITEMController* IT = CRunTime::GetLstController()->GetHead(POS); IT != NULL; IT = CRunTime::GetLstController()->GetNext(POS))
			while (IT->m_lstColumn.GetHead(POS1) != NULL)
			{
				CITEMColumn* pColumn = IT->m_lstColumn.Remove(POS1);
				pColumn->m_ControlID = IT->m_nControllerNode;
				lstColumn.AddTail(pColumn);
			}
	}

	XML_EXCHANGE_START(strXML);

	XML_EXCHANGE_KEY(_T("General"),					CRunTime::GetGeneral());

	XML_EXCHANGE_KEY_GROUP(_T("Controller"),		CITEMController,	CRunTime::GetLstController());
	XML_EXCHANGE_KEY_GROUP(_T("Controller_Video"),	CITEMVideo,			&lstVideo);
    XML_EXCHANGE_KEY_GROUP(_T("Controller_Column"),	CITEMColumn,		&lstColumn);

    XML_EXCHANGE_CLOSE(strXML);

	if (!bSave)
	{
		OBPOS POS = NULL;
		while (lstVideo.GetHead(POS) != NULL)
		{
			CITEMVideo* pVideo = lstVideo.Remove(POS);
			CITEMController* pController = CRunTime::GetController(pVideo->m_nControllerNode);
			if (pController == NULL)
			{
				LOG_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_BADPARAMETER, pVideo->m_nControllerNode);
				delete pVideo;
				continue;
			}
			
			OBPOS POS1 = NULL;
			for (CITEMVideo* IT = pController->m_lstVideo.GetHead(POS1); IT != NULL; IT = pController->m_lstVideo.GetNext(POS1))
			{
				if (pVideo->m_nVideoOrder < IT->m_nVideoOrder)
					break;
			}
			
			if (IT == NULL)
				pController->m_lstVideo.AddTail(pVideo);
			else
				pController->m_lstVideo.AddPrev(POS1, pVideo);
		}
	}


	if (!bSave)
	{
		OBPOS POS = NULL;
		while (lstColumn.GetHead(POS) != NULL)
		{
			CITEMColumn* pColumn = lstColumn.Remove(POS);
 
			CITEMController* pController = CRunTime::GetController(pColumn->m_ControlID);

			if (pController == NULL)
			{
				LOG_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_BADPARAMETER, pColumn->m_ControlID);
				delete pColumn;
				continue;
			}
			
			OBPOS POS1 = NULL;
			for (CITEMColumn* IT = pController->m_lstColumn.GetHead(POS1); IT != NULL; IT = pController->m_lstColumn.GetNext(POS1))
			{
				if (pColumn->m_MODE3ColumnId < IT->m_MODE3ColumnId)
					break;
			}
			
			if (IT == NULL)
				pController->m_lstColumn.AddTail(pColumn);
			else
				pController->m_lstColumn.AddPrev(POS1, pColumn);
		}
	}


	

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
COBList<CRunTime::CITEMController>*		CRunTime::GetLstController()		{ return &_RunTime.m_lstController; }
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

CRunTime::CITEMController* CRunTime::GetController(UINT nControllerNode)
{
	OBPOS POS = NULL;
	for (CITEMController* IT = CRunTime::GetLstController()->GetHead(POS); IT != NULL; IT = CRunTime::GetLstController()->GetNext(POS))
		if (IT->m_nControllerNode == nControllerNode)
			return IT;

	return NULL;
}

COLORREF CRunTime::GetColor(LONG value)
{
	return RGB((value / 256) / 256, (value / 256) % 256, (value % 256) % 256);
}

LONG CRunTime::GetColor(COLORREF value)
{
	return (GetRValue(value) * 256 + GetGValue(value)) * 256 + GetBValue(value);
}
