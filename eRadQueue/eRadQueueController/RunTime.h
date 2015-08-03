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

enum E_CONTROLLER_MODE
{
	EC_MODE0_GENERAL,				// 常规排队模式
	EC_MODE1_REPORT,				// 报告发布模式
	EC_MODE2_SINGLE_QUEUE,			// 单队列等候模式
	EC_MODE3_SINGLE_QUEUE_SHOWALL	// 单队列列表模式

};

enum E_MODE1_ORDER_MODE
{
	EMOM_PATIENTS_ALIAS,			// 病人姓名
	EMOM_ACCESSION_NUMBER			// 检查号
};

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
		BOOL			m_bLogTRACK;
		BOOL			m_bLogDEBUG;
		BOOL			m_bLogERROR;
		BOOL			m_bLogMESSAGE;
		LONG			m_nUseDepartment;
	public:
		LONG			m_nVoiceClass;
		CString			m_strVoiceDescription;
		LONG			m_nVoiceRate;
		LONG			m_nVoiceVolume;
		CString			m_strVoicePlay;
	public:
		CString			m_strEISDatabase;

	public:
		BOOL			m_bAutoLogin;				
		CString			m_strAutoDoctorCode;
		BOOL            m_bHideName;
	public:
		virtual	BOOL	ExchangeXML(CXmlParse* pXmlParse, LPVOID lpvNode, BOOL bSave = FALSE, LPCTSTR lpSpace = NULL);
	public:
		CGeneral() {}
		virtual ~CGeneral() {}
	};

	class CITEMVideo : public CRunTimeExchange  
	{
	public:
		UINT			m_nControllerNode;
		UINT			m_nVideoOrder;
		UINT			m_nVideoLength;
		CString			m_strVideoContent;
		COLORREF		m_clrVideoForeground;
	public:
		CRect			m_recVideo;
	public:
		virtual	BOOL	ExchangeXML(CXmlParse* pXmlParse, LPVOID lpvNode, BOOL bSave = FALSE, LPCTSTR lpSpace = NULL);
	public:
		CITEMVideo()
		{
			this->m_recVideo = CRect(0, 0, 0, 0);
		}
		virtual ~CITEMVideo() {}
	};


	class  CITEMColumn: public CRunTimeExchange  
	{
	public:
        UINT            m_ControlID;
		UINT            m_MODE3ColumnId;
		CString         m_MODE3ColumnName;
		UINT            m_MODE3ColumnRows;
		UINT            m_MODE3ColumnLines;
		LONG            m_MODE3ColumnLeft;
		LONG	        m_MODE3ColumnRight;
		LONG            m_MODE3ColumnTop;
		LONG            m_MODE3ColumnBottom;
		

	public:
		CString			m_strColumnFontName;
		LONG			m_nColumnFontSize;
		COLORREF		m_clrColumnForeground;
		COLORREF		m_clrColumnBackground;
		
		CString			m_strColumnNameFontName;
		LONG			m_nColumnNameFontSize;
		COLORREF		m_clrColumnNameForeground;
		COLORREF		m_clrColumnNameBackground;


	public:
		CRect          m_Mode3ColumnRect;
		BOOL           m_bShowHorizontal;
	public:
		virtual	BOOL	ExchangeXML(CXmlParse* pXmlParse, LPVOID lpvNode, BOOL bSave = FALSE, LPCTSTR lpSpace = NULL);
	public:
		CITEMColumn()
		{
			m_ControlID = 0 ;
			m_MODE3ColumnId = 0;
			m_MODE3ColumnName =_T("");
			m_MODE3ColumnRows = 1;
			m_MODE3ColumnLines = 1;
			m_MODE3ColumnLeft = 0;
			m_MODE3ColumnRight = 0;
			m_MODE3ColumnTop = 0;
			m_MODE3ColumnBottom = 0;
		/*	
			
			m_strColumnFontName = _T("");
			m_nColumnFontSize = 18;
			m_clrColumnForeground = RGB(0,0,0);
			m_clrColumnBackground = RGB(0,0,255);;
			
			m_strColumnNameFontName = _T("");
			m_nColumnNameFontSize = 18;
			m_clrColumnNameForeground =  RGB(0,0,0);;
			m_clrColumnNameBackground =  RGB(0,0,255);;
  
			*/	  
		}
		virtual ~CITEMColumn() {}
		
	};

	class CITEMController : public CRunTimeExchange  
	{
	public:
		UINT			m_nControllerNode;
		CString			m_strControllerName;
		LONG			m_nControllerMode;
		LONG			m_nControllerLeft;
		LONG			m_nControllerTop;
		LONG			m_nControllerWidth;
		LONG			m_nControllerHeight;
		UINT			m_nControllerRows;
		UINT			m_nControllerCols;
		BOOL			m_bControllerFromTop;
		CString			m_strControllerFontName;
		LONG			m_nControllerFontSize;
		COLORREF		m_clrControllerBackground;
	public:
		BOOL			m_bScrollEnable;
		UINT			m_nScrollHeight;
		LONG			m_nScrollSpeed;
		LONG            m_nQueueScrollSpeed;
		CString			m_strScrollContent;
		CString			m_strScrollFontName;
		LONG			m_nScrollFontSize;
		COLORREF		m_clrScrollBackground;
		COLORREF		m_clrScrollForeground;
	public:
		BOOL			m_bTitleEnable;
		CString			m_strTitleContent;
		UINT			m_nTitleHeight;
		CString			m_strTitleFontName;
		LONG			m_nTitleFontSize;
		COLORREF		m_clrTitleBackground;
		COLORREF		m_clrTitleForeground;
		BOOL			m_bDesc;
		BOOL            m_bScroll;

	public:
		BOOL			m_bVoiceEnable;
		UINT			m_nVoiceRepeat;
		UINT			m_nVoiceInterval;
		CString			m_strVoiceFormat;
		BOOL            m_bpromptVoiceEnable;
		BOOL            m_bUseKdfx;
        CString         m_strSeriesId;
	public:
		UINT			m_nMode1TimeRange;
		UINT			m_nMode1TimeDelay;
		UINT			m_nMode1RefreshIdle;
		UINT			m_nMode1RefreshScreen;
		CString			m_strMode1AdmissionSource;
		CString			m_strMode1ExcludeOutStatus;
		CString			m_strMode1SourceHospital;
		LONG			m_nMode1OrderMode;
	public:
		LONG			m_nMode2DeviceIndex;
		UINT			m_nMode2RefreshIdle;
		
	public:
		LONG            m_MODE3QueueIndex;
		UINT            m_MODE3RenovateTime;
		BOOL            m_bShowHorizontal;
		
	
	public:
		COBList<CITEMColumn>    m_lstColumn;
	public:
		COBList<CITEMVideo> 	m_lstVideo;
	public:
		virtual	BOOL	ExchangeXML(CXmlParse* pXmlParse, LPVOID lpvNode, BOOL bSave = FALSE, LPCTSTR lpSpace = NULL);
	public:
		CITEMController()
		{
			this->m_bVoiceEnable			= FALSE;
			this->m_nVoiceRepeat			= 2;
			this->m_nVoiceInterval			= 1;
			this->m_nMode1TimeRange			= 24;
			this->m_nMode1TimeDelay			= 10;
			this->m_nMode1RefreshIdle		= 60;
			this->m_nMode1RefreshScreen		= 10;
			this->m_nMode1OrderMode			= 0;
			this->m_nMode2DeviceIndex		= 0;
			this->m_nMode2RefreshIdle		= 60;
			
			this->m_MODE3QueueIndex = 0;
			this->m_MODE3RenovateTime = 0;

			this->m_bpromptVoiceEnable = FALSE;
			this->m_bShowHorizontal = FALSE;
			this->m_bUseKdfx = FALSE;
		}
		virtual ~CITEMController() {}
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
	COBList<CITEMController>		m_lstController;


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
	static COBList<CITEMController>*GetLstController();
	static COBList<CITEMColumn>*GetLstColumn();

public:
	static CUser*					GetUser();
	static CGui*					GetGUI();

public:
	static LONG						GetLogLevel();
	static CITEMController*			GetController(UINT nControllerNode);
	static COLORREF					GetColor(LONG value);
	static LONG						GetColor(COLORREF value);

public:
	CRunTime();
	virtual ~CRunTime();
};

#endif // !defined(AFX_RUNTIME_H__2FBD9DB3_E7FB_492E_B922_BA9A75D1882E__INCLUDED_)
