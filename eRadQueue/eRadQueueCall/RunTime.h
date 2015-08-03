// RunTime.h: interface for the CRunTime class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RUNTIME_H__2FBD9DB3_E7FB_492E_B922_BA9A75D1882E__INCLUDED_)
#define AFX_RUNTIME_H__2FBD9DB3_E7FB_492E_B922_BA9A75D1882E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ToolsEx.h"
#include "XMLParse.h"

//////////////////////////////////////////////////////////////////////

class CRunTime  
{
public:
	class CRunTimeExchange  
	{
	public:
		CString			m_strName;
	public:
		virtual	BOOL	ExchangeXML(CXmlParse* pXmlParse, LPVOID lpvNode, BOOL bSave = FALSE, LPCTSTR lpSpace = NULL) = 0;
	public:
		CRunTimeExchange() {}
		virtual ~CRunTimeExchange() {}
	};

	class CGeneral : public CRunTimeExchange  
	{
	public:
		UINT			m_nCallNode;
		CString			m_strCallName;
		CString			m_strCallConsole;
		CString			m_strCallDevice;
		CString         m_strCallRoom;
		CString         m_strCallRoomNode;
		CString         m_strMZQueue;
		CString         m_strZYQueue;
		LONG			m_nCallDepartment;
		BOOL			m_bCallPriority;
		BOOL			m_bCallOrder;
		BOOL			m_bCallCaptureReport;
		BOOL			m_bCallCapture;
		BOOL			m_bCallReport;
		BOOL			m_bCallComplete;
		BOOL			m_bCallReset;
		UINT			m_nCallIncrement;
		BOOL			m_bCallCancel;
		BOOL			m_bCallUnready;
		BOOL			m_bCallWait;
		BOOL			m_bAfternoon;
		BOOL            m_bCallOrderNoReport;             //20110724
		BOOL            m_bCallIQueueRoom;
		BOOL            m_bCallQueuePatientKind;
		BOOL            m_bNoPopOrderCall;
		BOOL            m_bCallPre;
		CString			m_strAfternoonTime;
		UINT			m_nAutoRefresh;
		BOOL			m_bPrivateSaveToFile;
		BOOL			m_bLogTRACK;
		BOOL			m_bLogDEBUG;
		BOOL			m_bLogERROR;
		BOOL			m_bLogMESSAGE;
       
	public:
		CString			m_strEISDatabase;
	public:
		CString			m_strPublicSaveToFile;
	public:
		virtual	BOOL	ExchangeXML(CXmlParse* pXmlParse, LPVOID lpvNode, BOOL bSave = FALSE, LPCTSTR lpSpace = NULL);
	public:
		CGeneral() {}
		virtual ~CGeneral() {}
	};

	class CUser  
	{
	public:
		LONG			m_nDoctorIndex;
		LONG			m_nDoctorDepartment;
		LONG			m_nDoctorPrivilege;
		CString			m_strDoctorCode;
		CString			m_strDoctorName;
		CString			m_strDoctorPassword;
		CString			m_strDepartmentName;
	public:
		CString			m_strPrivateSaveToFile;
		CRect			m_recDlgQueue;
	public:
		virtual	BOOL	Exchange(HKEY& hKey, BOOL bSave = FALSE);
	public:
		CUser()
		{
			this->m_nDoctorIndex		= 0;
			this->m_nDoctorDepartment	= 0;
			this->m_nDoctorPrivilege	= 0;
		}
		virtual ~CUser() {}
	};

//////////////////////////////////////////////////////////////////////

	class CGui  
	{
	public:
		HBRUSH			m_brushBlack;
		HBRUSH			m_brushGlobal;
		HBRUSH			m_brushTitleBar;
		HBRUSH			m_brushStatusBar;
		HBRUSH			m_brushEmphasis;
		HBRUSH			m_brushRequired;
	public:
		CGui()
		{
			this->m_brushBlack		= CreateSolidBrush(RGB(0, 0, 0));
			this->m_brushGlobal		= CreateSolidBrush(COLOR_BRUSH_GLOBAL);
			this->m_brushTitleBar	= CreateSolidBrush(COLOR_BRUSH_TITLE_BAR);
			this->m_brushStatusBar	= CreateSolidBrush(COLOR_BRUSH_STATUS_BAR);
			this->m_brushEmphasis	= CreateSolidBrush(COLOR_BRUSH_EMPHASIS);
			this->m_brushRequired	= CreateSolidBrush(COLOR_BRUSH_REQUIRED);
		}
		virtual ~CGui() {}
	};

//////////////////////////////////////////////////////////////////////

public:
	CGeneral						m_General;

public:
	CUser							m_User;
	CGui							m_Gui;

public:
	static MRET						Load();
	static MRET						ExchangeXML(BOOL bSave = FALSE);
	static BOOL						ExchangePublic(BOOL bSave = FALSE);
	static BOOL						ExchangePrivate(BOOL bSave = FALSE);
	static COleSession*				GetEISSession(COleSession* pSession);

public:
	static CGeneral*				GetGeneral();

public:
	static CUser*					GetUser();
	static CGui*					GetGUI();

public:
	static LONG						GetLogLevel();

public:
	CRunTime();
	virtual ~CRunTime();
};

#endif // !defined(AFX_RUNTIME_H__2FBD9DB3_E7FB_492E_B922_BA9A75D1882E__INCLUDED_)
