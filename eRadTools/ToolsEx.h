// ToolsEx.h: interface for the CToolsEx class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLSEX_H__78E5AD15_3C48_40F6_9E0B_81E8E96B2762__INCLUDED_)
#define AFX_TOOLSEX_H__78E5AD15_3C48_40F6_9E0B_81E8E96B2762__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "database.h"
#include "dicomlib.h"
#include "LibImage.h"

#define DATETIME_CURRENT_DATE			(CTime::GetCurrentTime().Format(_T("%Y%m%d")))
#define DATETIME_CURRENT_TIME			(CTime::GetCurrentTime().Format(_T("%H%M%S")))
#define DATETIME_CURRENT_DATETIME		(CTime::GetCurrentTime().Format(_T("%Y%m%d%H%M%S")))
#define	DATETIME_CONTROL_FORMAT			_T("yyyy-MM-dd")

#define EIS_EXAMINE_FILTER_MODALITIES	_T("检查类型")
#define EIS_EXAMINE_FILTER_DEVICE		_T("检查设备")

#define	EIS_STUDIES_MASCULINE			_T("阳性")
#define	EIS_STUDIES_KEENNESS			_T("敏感")
#define	EIS_STUDIES_LEARN				_T("示教")
#define	EIS_STUDIES_CONSULTATION		_T("会诊")

#define EIS_CLASSIFIED_CONSUME			_T("收费类别")
#define EIS_CLASSIFIED_STUDIES			_T("检查类别")

#define RADINFO_TEMPLATE_PUBLIC			_T("公有模板")
#define RADINFO_TEMPLATE_PRIVATE		_T("私有模板")

#define RADINFO_CLASSIFIED_REVIEW		_T("随访类别")

#define	TEMPLATE_TREEKIND_MANAGE		1
#define	TEMPLATE_TREEKIND_IMPORT		2

#define MENU_PHRASE_ITEMS_START			10000
#define MENU_PHRASE_ITEMS_END			12000
#define MENU_PHRASE_ITEMS_CONFIG		_T("常用语管理")

#define COLOR_BRUSH_GLOBAL				RGB(219, 225, 237)
#define COLOR_BRUSH_TITLE_BAR			RGB(169, 110,  16)
#define COLOR_BRUSH_STATUS_BAR			RGB(159, 174, 197)
#define COLOR_BRUSH_EMPHASIS			RGB(255, 255, 224)
#define COLOR_BRUSH_REQUIRED			RGB(255, 255, 224)
#define COLOR_BRUSH_TABCTRL				RGB(176, 208, 255)

#define COLOR_TEXT_DEFAULT				RGB(  0,   0,   0)

#define COLOR_BACK_EMPHASIS				RGB(255, 255, 224)
#define COLOR_BACK_REQUIRED				RGB(255, 255, 224)
#define COLOR_TEXT_EMPHASIS				RGB(255,   0,   0)
#define COLOR_TEXT_REQUIRED				RGB(  0,   0,   0)
#define COLOR_CTRL_READONLY				RGB(222, 236, 245)

#define	SET_LEFT_FROM_RIGHT(LEFT, RIGHT)		(LEFT) = (RIGHT);
#define	SET_RIGHT_FROM_LEFT(LEFT, RIGHT)		(RIGHT) = (LEFT);
#define SET_VALUE_CLONE(TARGET, SOURCE, NAME)	TARGET##NAME = SOURCE##NAME;

#define SET_MOVE_WINDOW(DOWN, CTRL, OFFSET, WIDTH)		\
	if (DOWN) recRange += CSize(0, nHeight);			\
	recCtrl = recRange;									\
	recCtrl.left += (OFFSET);							\
	recCtrl.right = recCtrl.left + (WIDTH);				\
	this->GetDlgItem(CTRL)->MoveWindow(&recCtrl);		\


#define LIST_INSERT_ITEM(LIST, INDEX, ID)			\
		strBuffer.LoadString((ID));					\
		(LIST).InsertItem((INDEX)++, strBuffer);	\


#define REBUID_PHRASE_MENU(MENU, KINDS, DEPARTMENT, DOCTOR)			\
	if (!(MENU).m_hMenu)											\
		return;														\
																	\
	LONG nCount = (MENU).GetMenuItemCount();						\
	for (LONG i = 0; i < nCount; i++)								\
		(MENU).RemoveMenu(0, MF_BYPOSITION);						\
																	\
	CString strFilter, strBuffer;									\
	strFilter.Format(_T("WHERE PhraseKinds = %d AND (PhraseDepartment = %d OR PhraseDoctor = %d) ORDER BY PhraseDepartment DESC, PhraseGather, PhraseOrder"), (KINDS), (DEPARTMENT), (DOCTOR));	\
																	\
	CdboMGRPhrase dboPhrase;										\
	dboPhrase.SetDataSource(pSession);								\
	if (FAILED(dboPhrase.Open(strFilter)))							\
	{																\
		LOG_ERROR_MESSAGE(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_TABLE, strFilter);	\
		return;														\
	}																\
																	\
	CMenu menu;														\
	CString strGather;												\
	BOOL bPublicSeparator = FALSE;									\
	LONG nCommandID = MENU_PHRASE_ITEMS_START + 1;					\
	while (dboPhrase.MoveNext() == S_OK)							\
	{																\
		if (dboPhrase.m_PhraseDepartment > 0) bPublicSeparator = TRUE;	\
																	\
		if (bPublicSeparator && dboPhrase.m_PhraseDepartment == 0)	\
		{															\
			bPublicSeparator = FALSE;								\
			(MENU).AppendMenu(MF_SEPARATOR);						\
		}															\
																	\
		if (strlen(dboPhrase.m_PhraseGather) == 0)					\
		{															\
			(MENU).AppendMenu(MF_STRING, nCommandID++, dboPhrase.m_PhraseContent);	\
			continue;												\
		}															\
																	\
		if (strGather.Compare(dboPhrase.m_PhraseGather) == 0)		\
		{															\
			menu.AppendMenu(MF_STRING, nCommandID++, dboPhrase.m_PhraseContent);	\
			continue;												\
		}															\
																	\
		if (menu.m_hMenu) menu.DestroyMenu();						\
																	\
		menu.CreatePopupMenu();										\
		menu.AppendMenu(MF_STRING, nCommandID++, dboPhrase.m_PhraseContent);	\
		strGather = dboPhrase.m_PhraseGather;						\
		(MENU).AppendMenu(MF_POPUP | MF_BYPOSITION | MF_STRING, (UINT) menu.m_hMenu, strGather);	\
	}																\
																	\
	dboPhrase.Close();												\
																	\
	if (menu.m_hMenu) menu.DestroyMenu();							\
																	\
	(MENU).AppendMenu(MF_SEPARATOR);								\
	(MENU).AppendMenu(MF_STRING, MENU_PHRASE_ITEMS_START, MENU_PHRASE_ITEMS_CONFIG);	\


class CToolsEx  
{
public:
	char*		m_lpChineseSpell;
	DWORD		m_dwChineseSpellCount;

public:
	COBFindLS	m_FilmSessionExecute;
	COBFindLS	m_FilmSessionArchive;
	COBFindLS	m_InstanceAvailable;
	COBFindLS	m_InstanceStorage;
	COBFindLS	m_StorageStatus;
	COBFindLS	m_AdmissionSourceTXT;
	COBFindLL	m_AdmissionSource;
	COBFindLS	m_StudiesStatus;
	COBFindLS	m_ReportsStatus;
	COBFindLS	m_ReportsOutStatus;
	COBFindLS	m_QueueStatus;
	COBFindLS	m_StudiesFilms;
	COBFindLS	m_StudiesReviews;
	COBFindSS	m_SexDICOM2TXT;
	COBFindSL	m_SexDICOM2LONG;
	COBFindSS	m_AgeSuffixDICOM2TXT;
	COBFindSL	m_AgeSuffixDICOM2LONG;
	COBFindLS	m_LogLevel;
	COBFindLS	m_LogOperate;
	COBFindLS	m_NodeKinds;
	COBFindLS	m_InstancePrint;
	COBFindLS	m_InstanceArchiveAuto;
	COBFindLS	m_InstanceArchiveManual;
	COBFindSS	m_ChineseInput;
	COBFindLS	m_LinkDatabase;
	COBFindLS	m_StudiesMarker;
	COBFindLS	m_AviToDICOM;

public:
	static COBFindLS*	GetFilmSessionExecute();
	static COBFindLS*	GetFilmSessionArchive();
	static COBFindLS*	GetInstanceAvailable();
	static COBFindLS*	GetInstanceStorage();
	static COBFindLS*	GetStorageStatus();
	static COBFindLS*	GetAdmissionSourceTXT();
	static COBFindLL*	GetAdmissionSource();
	static COBFindLS*	GetStudiesStatus();
	static COBFindLS*	GetReportsStatus();
	static COBFindLS*	GetReportsOutStatus();
	static COBFindLS*	GetQueueStatus();
	static COBFindLS*	GetStudiesFilms();
	static COBFindLS*	GetStudiesReviews();
	static COBFindSS*	GetSexDICOM2TXT();
	static COBFindSL*	GetSexDICOM2LONG();
	static COBFindSS*	GetAgeSuffixDICOM2TXT();
	static COBFindSL*	GetAgeSuffixDICOM2LONG();
	static COBFindLS*	GetLogLevel();
	static COBFindLS*	GetLogOperate();
	static COBFindLS*	GetNodeKinds();
	static COBFindLS*	GetInstancePrint();
	static COBFindLS*	GetInstanceArchiveAuto();
	static COBFindLS*	GetInstanceArchiveManual();
	static COBFindSS*	GetChineseInput();
	static COBFindLS*	GetLinkDatabase();
	static COBFindLS*	GetStudiesMarker();
	static COBFindLS*	GetAviToDICOM();

public:
	static LPCTSTR	GetOperateTXT	(CString& strTXT, LONG nOperateCommands);

	static LPCTSTR	GetMultiValueTXT(CString& strValue, LPCTSTR lpValue);

	static LPCTSTR	GetAgeTXT		(CString& strAge, COleDateTime timeDate, BOOL bUseChineseAge, UINT nDaysUseDAge = 100, UINT nDaysUseMAge = 300);
	static LPCTSTR	GetAgeTXT		(CString& strAge, LPCTSTR lpDate, BOOL bUseChineseAge, UINT nDaysUseDAge = 100, UINT nDaysUseMAge = 300);
	static LPCTSTR	GetAgeTXT		(CString& strAge, LPCTSTR lpAge);
	static LPCTSTR	GetAgeDICOM		(CString& strAge, COleDateTime timeDate, BOOL bUseChineseAge, UINT nDaysUseDAge = 100, UINT nDaysUseMAge = 300);

	static BOOL		GetDOB			(COleDateTime& timeDate, LPCTSTR lpAge, BOOL bUseChineseAge);
	static BOOL		GetDate			(COleDateTime& timeDate, LPCTSTR lpDate);

	static LPCTSTR	GetDateTXT		(CString& strDate, LPCTSTR lpDate);
	static LPCTSTR	GetTimeTXT		(CString& strTime, LPCTSTR lpTime);

	static LPCTSTR	GetDateTimeTXT	(CString& strDateTime, LPCTSTR lpDateTime);
	static LPCTSTR	GetDateTimeTXT	(CString& strDateTime, LPCTSTR lpDate, LPCTSTR lpTime);

	static LPCTSTR	GetMultiValue(CString& strMultiValue, CStringArray* pArray);
	static LPCTSTR	GetMultiValue(CString& strMultiValue, CList<LONG, LONG>* pList);

	static BOOL		GetMultiValue(CStringArray* pArray, LPCTSTR lpMultiValue);
	static BOOL		GetMultiValue(CList<LONG, LONG>* pList, LPCTSTR lpMultiValue);

	static LONG		GetWindowsControlID();

	static BOOL		Decode(CString& strInput, CString& strOutput);
	static BOOL		Encode(CString& strInput, CString& strOutput);
	static MRET		ZlibDecode(CString& strInput, CString& strOutput);
	static MRET		ZlibEncode(CString& strInput, CString& strOutput);

	static BOOL		OpenChineseInput();

	static BOOL		OpenChineseSpell();
	static BOOL		CloseChineseSpell();
	static BOOL		GetSingleSpell(char* lpSpell, DWORD dwSpell, CString strInput, CStringArray& aOutput);
	static BOOL		GetChineseSpell(UINT nIDResource, CString strInput, CStringArray& aOutput);

public:
	CToolsEx();
	virtual ~CToolsEx();
};

#endif // !defined(AFX_TOOLSEX_H__78E5AD15_3C48_40F6_9E0B_81E8E96B2762__INCLUDED_)
