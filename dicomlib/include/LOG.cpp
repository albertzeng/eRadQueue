// LOG.cpp: implementation of the CLOG class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LOG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static CLOG _LOG;

///////////////////////////////////////////////////////////////////////////////
static CLOG::CSingleLOG LogErrorTable[] = {

#include "LOG.inc"

};
///////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLOG::CLOG()
{
	InitializeCriticalSection(&this->m_CriticalSection);
	this->m_dwLength = 0;
	this->m_ppErrorMessage = NULL;
	this->m_nLogLevel = LL_DEBUG | LL_ERROR | LL_MESSAGE;
	this->m_strLogFile = _T("Logdat");
}

CLOG::~CLOG()
{
	if (this->m_ppErrorMessage != NULL) delete this->m_ppErrorMessage;

	DeleteCriticalSection(&this->m_CriticalSection);
}

MRET
CLOG::Initialize()
{
	if (_LOG.m_strLogDir.IsEmpty())
	{
		char lpszFullPathName[MAX_PATH];
		GetFullPathName(_T("LOG"), sizeof(lpszFullPathName), lpszFullPathName, NULL);
		_LOG.m_strLogDir = lpszFullPathName;

		if ((::CreateDirectory(_LOG.m_strLogDir, NULL) == 0) && (::GetLastError() != ERROR_ALREADY_EXISTS))
			return ME_ERR_CREATE_DIRECTORY;
	}

	DWORD dwSize = sizeof(LogErrorTable) / sizeof(CSingleLOG);

	_LOG.m_dwLength = LogErrorTable[dwSize - 1].nLogCode + 1;
	_LOG.m_ppErrorMessage = new LPCTSTR[_LOG.m_dwLength];

	for (DWORD i = 0; i < _LOG.m_dwLength; i++) _LOG.m_ppErrorMessage[i] = NULL;

	for (i = 0; i < dwSize; i++) _LOG.m_ppErrorMessage[LogErrorTable[i].nLogCode] = LogErrorTable[i].lpMessage;

	return ME_OK;
}

LPCTSTR
CLOG::GetMessage(DWORD dwCode)
{
	LPCTSTR lpMessage = NULL;
	if (dwCode < _LOG.m_dwLength) lpMessage = _LOG.m_ppErrorMessage[dwCode];

	return ((lpMessage) ? lpMessage : _T("Generic Error"));
}

void
CLOG::SetParameter(LONG nLogLevel, LPCTSTR lpLogFile)
{
	_LOG.m_nLogLevel = nLogLevel;

	if (lpLogFile != NULL) _LOG.m_strLogFile = lpLogFile;
}

void
CLOG::DoLog(LONG nLevel, CString& strMessage)
{
	if (!(nLevel & LL_MASK & _LOG.m_nLogLevel))
		return;

	EnterCriticalSection(&_LOG.m_CriticalSection);

	if (nLevel & LD_FILE)
	{
		BOOL bNewFile = TRUE;

		SYSTEMTIME stimeThis;
		GetLocalTime(&stimeThis);
		CTime timeThis(stimeThis);
		CString strFileName;
		strFileName.Format(_T("%s\\%s%s.LOG"), _LOG.m_strLogDir, _LOG.m_strLogFile, timeThis.Format(_T("%d")));

		HANDLE hFile = CreateFile(strFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hFile != INVALID_HANDLE_VALUE)
		{
			FILETIME filetimeWrite;
			if(GetFileTime(hFile, NULL, NULL, &filetimeWrite))
			{
				CTime timeFile(filetimeWrite);
				if ((timeThis.GetYear() == timeFile.GetYear()) && (timeThis.GetMonth() == timeFile.GetMonth()) && (timeThis.GetDay() == timeFile.GetDay()))
					bNewFile = FALSE;
			}
			CloseHandle(hFile);
		}

		FILE *file = NULL;
		if (!bNewFile) file = fopen(strFileName, _T("at"));
		if (file == NULL) file = fopen(strFileName, _T("wt"));
		if (file)
		{
			fprintf(file, _T("[%s.%03d](%04X) %s\n"), timeThis.Format(_T("%m-%d %H:%M:%S")), stimeThis.wMilliseconds, ::GetCurrentThreadId(), strMessage);

			fclose(file);
		}
	}
	
	if (nLevel & LD_MSGBOX) ::AfxMessageBox(strMessage, (nLevel & LL_ERROR) ? (MB_OK | MB_ICONERROR) : MB_OK);

	LeaveCriticalSection(&_LOG.m_CriticalSection);
}

void
CLOG::DoLog(LONG nLevel, LPCTSTR lpMessage)
{
	CString strMessage;
	strMessage = lpMessage;
	CLOG::DoLog(nLevel, strMessage);
}

void
CLOG::LogError(LPCTSTR lpFile, LONG nLine, LONG nLevel, DWORD dwCode)
{
	CString strMessage;
	strMessage.Format(_T("[%ld] %s [%s %ld]"), dwCode, CLOG::GetMessage(dwCode), lpFile, nLine);
	CLOG::DoLog(nLevel, strMessage);
}

void
CLOG::LogError(LPCTSTR lpFile, LONG nLine, LONG nLevel, DWORD dwCode, LPCTSTR lpMessage)
{
	CString strMessage;
	strMessage.Format(_T("[%ld] %s [%s %ld]; %s"), dwCode, CLOG::GetMessage(dwCode), lpFile, nLine, lpMessage);
	CLOG::DoLog(nLevel, strMessage);
}

void
CLOG::LogError(LPCTSTR lpFile, LONG nLine, LONG nLevel, DWORD dwCode, LONG nMinor)
{
	CString strMessage;
	strMessage.Format(_T("[%ld] %s [%ld] [%s %ld]"), dwCode, CLOG::GetMessage(dwCode), nMinor, lpFile, nLine);
	CLOG::DoLog(nLevel, strMessage);
}

void
CLOG::LogError(LPCTSTR lpFile, LONG nLine, LONG nLevel, DWORD dwCode, LONG nMinor, LPCTSTR lpMessage)
{
	CString strMessage;
	strMessage.Format(_T("[%ld] %s [%ld] [%s %ld]; %s"), dwCode, CLOG::GetMessage(dwCode), nMinor, lpFile, nLine, lpMessage);
	CLOG::DoLog(nLevel, strMessage);
}
