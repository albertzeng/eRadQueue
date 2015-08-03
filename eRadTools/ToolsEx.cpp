// ToolsEx.cpp: implementation of the CToolsEx class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ToolsEx.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

static CToolsEx	_ToolsEx;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolsEx::CToolsEx()
{
	this->m_lpChineseSpell		= NULL;
	this->m_dwChineseSpellCount	= 0;

	this->m_FilmSessionExecute.SetDefault(0, _T("--"));
	this->m_FilmSessionExecute.Add(EIS_FILMS_ZERO,				_T("未拍片"));
	this->m_FilmSessionExecute.Add(EIS_FILMS_PRINT,				_T("拍片中"));
	this->m_FilmSessionExecute.Add(EIS_FILMS_OK,				_T("已拍片"));
	this->m_FilmSessionExecute.Add(EIS_FILMS_FALSE,				_T("拍片错误"));
	this->m_FilmSessionExecute.Add(EIS_FILMS_CANCEL,			_T("取消拍片"));

	this->m_FilmSessionArchive.SetDefault(0, _T("--"));
	this->m_FilmSessionArchive.Add(EI_ARCHIVE_AUTO_NONE,		_T("未归档"));
	this->m_FilmSessionArchive.Add(EI_ARCHIVE_AUTO_READY,		_T("已归档_自动"));
	this->m_FilmSessionArchive.Add(EI_ARCHIVE_AUTO_OK,			_T("已合成_自动"));
	this->m_FilmSessionArchive.Add(1000*EI_ARCHIVE_MANUAL_READY,_T("已归档_人工"));
	this->m_FilmSessionArchive.Add(1000*EI_ARCHIVE_MANUAL_OK,	_T("已合成_人工"));

	this->m_InstanceAvailable.SetDefault(0, _T("--"));
	this->m_InstanceAvailable.Add(EI_AVAILABLE_ONLINE,			_T("在线"));
	this->m_InstanceAvailable.Add(EI_AVAILABLE_NEARLINE,		_T("近线"));
	this->m_InstanceAvailable.Add(EI_AVAILABLE_OFFLINE,			_T("离线"));

	this->m_InstanceStorage.SetDefault(0, _T("--"));
	this->m_InstanceStorage.Add(EI_STORAGE_NONE,				_T("等待"));
	this->m_InstanceStorage.Add(EI_STORAGE_READY,				_T("准备中"));
	this->m_InstanceStorage.Add(EI_STORAGE_OK,					_T("完成"));
	this->m_InstanceStorage.Add(EI_STORAGE_FALSE,				_T("失败"));
	this->m_InstanceStorage.Add(EI_STORAGE_IGNORE,				_T("忽略"));

	this->m_StorageStatus.SetDefault(0, _T("--"));
	this->m_StorageStatus.Add(EI_STORAGE_NONE,					_T("等待"));
	this->m_StorageStatus.Add(EI_STORAGE_READY,					_T("准备中"));
	this->m_StorageStatus.Add(EI_STORAGE_OK,					_T("完成"));
	this->m_StorageStatus.Add(EI_STORAGE_FALSE,					_T("失败"));
	this->m_StorageStatus.Add(EI_STORAGE_IGNORE,				_T("中止"));

	this->m_AdmissionSourceTXT.SetDefault(0, _T("--"));
	this->m_AdmissionSourceTXT.Add(EIS_ADMISSION_EXAMIN,		_T("体检"));
	this->m_AdmissionSourceTXT.Add(EIS_ADMISSION_IMPORT,		_T("外院"));
	this->m_AdmissionSourceTXT.Add(EIS_ADMISSION_INPATIENT,		_T("住院"));
	this->m_AdmissionSourceTXT.Add(EIS_ADMISSION_OUTPATIENT,	_T("门诊"));
	this->m_AdmissionSourceTXT.Add(EIS_ADMISSION_EMERGENTY,		_T("急诊"));
	this->m_AdmissionSourceTXT.Add(EIS_ADMISSION_PROTECTIVE,	_T("重保"));

	this->m_AdmissionSource.SetDefault(EIS_ADMISSION_IMPORT, -1);
	this->m_AdmissionSource.Add(EIS_ADMISSION_EXAMIN,			3);
	this->m_AdmissionSource.Add(EIS_ADMISSION_INPATIENT,		2);
	this->m_AdmissionSource.Add(EIS_ADMISSION_OUTPATIENT,		1);
	this->m_AdmissionSource.Add(EIS_ADMISSION_EMERGENTY,		0);

	this->m_StudiesStatus.SetDefault(0, _T("--"));
	this->m_StudiesStatus.Add(EIS_STUDIES_PREARRANGE,			_T("预约"));
	this->m_StudiesStatus.Add(EIS_STUDIES_REGISTER,				_T("登记"));
	this->m_StudiesStatus.Add(EIS_STUDIES_SIGNATURE,			_T("签名"));
	this->m_StudiesStatus.Add(EIS_STUDIES_COMPLETE,				_T("检查完成"));
	this->m_StudiesStatus.Add(EIS_STUDIES_CANCEL,				_T("取消"));

	this->m_ReportsStatus.SetDefault(0, _T("--"));
	this->m_ReportsStatus.Add(EIS_REPORTS_ZERO,					_T("未报告"));
	this->m_ReportsStatus.Add(EIS_REPORTS_ADVANCE,				_T("临时报告"));
	this->m_ReportsStatus.Add(EIS_REPORTS_REPORT,				_T("已报告"));
	this->m_ReportsStatus.Add(EIS_REPORTS_BACK,					_T("已回退"));
	this->m_ReportsStatus.Add(EIS_REPORTS_APPROVE,				_T("已审核"));
	this->m_ReportsStatus.Add(EIS_REPORTS_REVIEW,				_T("已复审"));

	this->m_ReportsOutStatus.SetDefault(0, _T("--"));
	this->m_ReportsOutStatus.Add(EIS_REPORTS_OUT_ZERO,			_T("未打印"));
	this->m_ReportsOutStatus.Add(EIS_REPORTS_OUT_PRINT,			_T("已打印"));
	this->m_ReportsOutStatus.Add(EIS_REPORTS_OUT_OUT,			_T("已取报告"));
	this->m_ReportsOutStatus.Add(EIS_REPORTS_OUT_BACK,			_T("已追回"));

	this->m_QueueStatus.SetDefault(-1, _T("--"));
	this->m_QueueStatus.Add(EIS_QUEUE_WAIT,						_T("等候"));
	this->m_QueueStatus.Add(EIS_QUEUE_ADVANCE,					_T("预呼"));
	this->m_QueueStatus.Add(EIS_QUEUE_EXAMINE,					_T("待检"));
	this->m_QueueStatus.Add(EIS_QUEUE_COMPLETE,					_T("完成"));
	this->m_QueueStatus.Add(EIS_QUEUE_UNREADY,					_T("未准备"));
	this->m_QueueStatus.Add(EIS_QUEUE_CANCEL,					_T("弃号"));

	this->m_StudiesFilms.SetDefault(0, _T("--"));
	this->m_StudiesFilms.Add(EIS_FILMS_ZERO,					_T("未拍片"));
	this->m_StudiesFilms.Add(EIS_FILMS_READY,					_T("已准备"));
	this->m_StudiesFilms.Add(EIS_FILMS_PRINT,					_T("拍片中"));
	this->m_StudiesFilms.Add(EIS_FILMS_OK,						_T("已拍片"));
	this->m_StudiesFilms.Add(EIS_FILMS_OUT,						_T("已取片"));
	this->m_StudiesFilms.Add(EIS_FILMS_FALSE,					_T("拍片错误"));
	this->m_StudiesFilms.Add(EIS_FILMS_CANCEL,					_T("取消拍片"));
	
	this->m_StudiesReviews.SetDefault(0, _T("--"));
	this->m_StudiesReviews.Add(EIS_REVIEWS_ZERO,				_T("未随访"));
	this->m_StudiesReviews.Add(EIS_REVIEWS_WAIT,				_T("等待"));
	this->m_StudiesReviews.Add(EIS_REVIEWS_COMPLETE,			_T("完成"));

	this->m_SexDICOM2TXT.SetDefault(_T("-"), _T("--"));
	this->m_SexDICOM2TXT.Add(_T("M"),							_T("男"));
	this->m_SexDICOM2TXT.Add(_T("F"),							_T("女"));
	this->m_SexDICOM2TXT.Add(_T("O"),							_T("未知"));

	this->m_SexDICOM2LONG.SetDefault(_T("-"), 2);
	this->m_SexDICOM2LONG.Add(_T("M"),							0);
	this->m_SexDICOM2LONG.Add(_T("F"),							1);
	this->m_SexDICOM2LONG.Add(_T("O"),							2);

	this->m_AgeSuffixDICOM2TXT.SetDefault(_T("-"), _T("--"));
	this->m_AgeSuffixDICOM2TXT.Add(_T("Y"),						_T("岁"));
	this->m_AgeSuffixDICOM2TXT.Add(_T("M"),						_T("月"));
	this->m_AgeSuffixDICOM2TXT.Add(_T("W"),						_T("周"));
	this->m_AgeSuffixDICOM2TXT.Add(_T("D"),						_T("天"));
	this->m_AgeSuffixDICOM2TXT.Add(_T("H"),						_T("时"));

	this->m_AgeSuffixDICOM2LONG.SetDefault(_T("-"), 0);
	this->m_AgeSuffixDICOM2LONG.Add(_T("Y"),					0);
	this->m_AgeSuffixDICOM2LONG.Add(_T("M"),					1);
	this->m_AgeSuffixDICOM2LONG.Add(_T("W"),					2);
	this->m_AgeSuffixDICOM2LONG.Add(_T("D"),					3);
	this->m_AgeSuffixDICOM2LONG.Add(_T("H"),					4);

	this->m_LogLevel.SetDefault(0, _T("--"));
	this->m_LogLevel.Add(EIS_LOG_INFORMATION,					_T("信息"));
	this->m_LogLevel.Add(EIS_LOG_ALERT,							_T("警告"));
	this->m_LogLevel.Add(EIS_LOG_ERROR,							_T("错误"));
	this->m_LogLevel.Add(EIS_LOG_RECORD,						_T("记录"));

	this->m_LogOperate.SetDefault(0, _T("--"));
	this->m_LogOperate.Add(LOG_SCHEDULE_INSERT,					_T("检查预约"));
	this->m_LogOperate.Add(LOG_SCHEDULE_REGISTER,				_T("预约登记"));
	this->m_LogOperate.Add(LOG_REGISTER_INSERT,					_T("检查登记"));
	this->m_LogOperate.Add(LOG_REGISTER_UPDATE,					_T("检查修改"));
	this->m_LogOperate.Add(LOG_REGISTER_DELETE,					_T("检查删除"));
	this->m_LogOperate.Add(LOG_REGISTER_PRINT,					_T("登记拍片"));
	this->m_LogOperate.Add(LOG_FILM_CANCEL,						_T("取消拍片"));
	this->m_LogOperate.Add(LOG_FILM_ARCHIVE,					_T("相片归档"));
	this->m_LogOperate.Add(LOG_HIS_INTERFACE,					_T("（HIS）连接"));
	this->m_LogOperate.Add(LOG_EXAMINE_SIGNATURE,				_T("检查签名"));
	this->m_LogOperate.Add(LOG_EXAMINE_UPDATE,					_T("检查数据保存"));
	this->m_LogOperate.Add(LOG_EXAMINE_CANCEL,					_T("取消签名"));
	this->m_LogOperate.Add(LOG_EXAMINE_RESET,					_T("检查状态复位"));
	this->m_LogOperate.Add(LOG_EXAMINE_PRINT,					_T("检查拍片"));
	this->m_LogOperate.Add(LOG_IMAGE_ARCHIVE_AUTO,				_T("影像归档_自动"));
	this->m_LogOperate.Add(LOG_IMAGE_ARCHIVE_MANUAL,			_T("影像归档_人工"));
	this->m_LogOperate.Add(LOG_IMAGE_DELETE,					_T("影像删除"));
	this->m_LogOperate.Add(LOG_REPORTS_SAVE,					_T("报告保存"));
	this->m_LogOperate.Add(LOG_REPORTS_ADVANCE,					_T("临时报告"));
	this->m_LogOperate.Add(LOG_REPORTS_REPORT,					_T("报告提交"));
	this->m_LogOperate.Add(LOG_REPORTS_BACK,					_T("报告回退"));
	this->m_LogOperate.Add(LOG_REPORTS_APPROVE,					_T("报告审核"));
	this->m_LogOperate.Add(LOG_REPORTS_UPDATE,					_T("报告修改"));
	this->m_LogOperate.Add(LOG_REPORTS_REVIEW,					_T("报告复审"));
	this->m_LogOperate.Add(LOG_EXAMINE_CONSULTATION,			_T("会诊"));
	this->m_LogOperate.Add(LOG_EXAMINE_REVIEW,					_T("随访"));
	this->m_LogOperate.Add(LOG_QC_TECHNOLOGY,					_T("质控_技术"));
	this->m_LogOperate.Add(LOG_QC_DIAGNOSE,						_T("质控_诊断"));
	this->m_LogOperate.Add(LOG_ADMISSION_ID_QUERY,				_T("门诊住院号查询"));

	this->m_NodeKinds.SetDefault(0, _T("--"));
	this->m_NodeKinds.Add(EIS_NODE_EIS_SERVICE,					_T("EIS Service"));
	this->m_NodeKinds.Add(EIS_NODE_PAS_SERVICE,					_T("PACS Service"));
	this->m_NodeKinds.Add(EIS_NODE_QAS_SERVICE,					_T("QACS Service"));
	this->m_NodeKinds.Add(EIS_NODE_PRINT_SERVICE,				_T("PRINT Service"));
	this->m_NodeKinds.Add(EIS_NODE_PRINT_CLIENT,				_T("PRINT Client"));
	this->m_NodeKinds.Add(EIS_NODE_REGISTER,					_T("登记工作站"));
	this->m_NodeKinds.Add(EIS_NODE_QACS,						_T("检查工作站"));
	this->m_NodeKinds.Add(EIS_NODE_REPORTER,					_T("报告工作站"));
	this->m_NodeKinds.Add(EIS_NODE_VIEWER,						_T("VIEWER"));
	this->m_NodeKinds.Add(EIS_NODE_DEVICE,						_T("设备"));
	this->m_NodeKinds.Add(EIS_NODE_PRINTER,						_T("相机"));
	this->m_NodeKinds.Add(EIS_NODE_DVD_STORAGE,					_T("刻录备份系统"));
	this->m_NodeKinds.Add(EIS_NODE_LINKER_SERVICE,				_T("Linker Service"));
	this->m_NodeKinds.Add(EIS_NODE_MEDICAL_STATION,				_T("图文工作站"));

	this->m_InstancePrint.SetDefault(0, _T("--"));
	this->m_InstancePrint.Add(0,								_T("未打印"));
	this->m_InstancePrint.Add(1,								_T("已打印"));

	this->m_InstanceArchiveAuto.SetDefault(0, _T("--"));
	this->m_InstanceArchiveAuto.Add(EI_ARCHIVE_AUTO_NONE,		_T("----"));
	this->m_InstanceArchiveAuto.Add(EI_ARCHIVE_AUTO_STOP,		_T("停止"));
	this->m_InstanceArchiveAuto.Add(EI_ARCHIVE_AUTO_FALSE,		_T("失败"));
	this->m_InstanceArchiveAuto.Add(EI_ARCHIVE_AUTO_IGNORE,		_T("删除"));

	this->m_InstanceArchiveManual.SetDefault(0, _T("--"));
	this->m_InstanceArchiveManual.Add(EI_ARCHIVE_MANUAL_NONE,	_T(""));
	this->m_InstanceArchiveManual.Add(EI_ARCHIVE_MANUAL_READY,	_T("准备"));
	this->m_InstanceArchiveManual.Add(EI_ARCHIVE_MANUAL_OK,		_T("成功"));
	this->m_InstanceArchiveManual.Add(EI_ARCHIVE_MANUAL_FALSE,	_T("失败"));
	this->m_InstanceArchiveManual.Add(EI_ARCHIVE_MANUAL_IGNORE,	_T("忽略"));

	this->m_ChineseInput.SetDefault(_T("-"), _T("--"));

	this->m_LinkDatabase.SetDefault(0, _T("--"));
	this->m_LinkDatabase.Add(E_DATABASE_NULL,					_T("空数据库"));
	this->m_LinkDatabase.Add(E_DATABASE_SYSTEM,					_T("系统数据库"));
	this->m_LinkDatabase.Add(E_DATABASE_PUBLIC_HIS,				_T("中间库（HIS）"));
	this->m_LinkDatabase.Add(E_DATABASE_PUBLIC_RIS,				_T("中间库（RIS）"));
	this->m_LinkDatabase.Add(E_DATABASE_PUBLIC_HIS_ORACLE,		_T("中间库（HIS-Oracle）"));
	this->m_LinkDatabase.Add(E_DATABASE_PUBLIC_ZJJTRJYXGS,		_T("中间库（浙江金唐软件有限公司）"));

	this->m_StudiesMarker.SetDefault(0, _T("----"));
	this->m_StudiesMarker.Add(EIS_MARKER_MASCULINE,				_T("阳性"));
	this->m_StudiesMarker.Add(EIS_MARKER_KEENNESS,				_T("敏感"));
	this->m_StudiesMarker.Add(EIS_MARKER_CONSULTATION,			_T("示教"));
	this->m_StudiesMarker.Add(EIS_MARKER_LEARN,					_T("会诊"));
	this->m_StudiesMarker.Add(EIS_MARKER_REVIEW,				_T("随访"));

	this->m_AviToDICOM.SetDefault(0, _T("----"));
	this->m_AviToDICOM.Add(EI_AVI_TO_DICOM_NONE,				_T("未转换"));
	this->m_AviToDICOM.Add(EI_AVI_TO_DICOM_READY,				_T("准备转换"));
	this->m_AviToDICOM.Add(EI_AVI_TO_DICOM_OK,					_T("已完成"));
	this->m_AviToDICOM.Add(EI_AVI_TO_DICOM_FALSE,				_T("转换失败"));
}

CToolsEx::~CToolsEx()
{

}

COBFindLS* CToolsEx::GetFilmSessionExecute()	{ return &_ToolsEx.m_FilmSessionExecute;	}
COBFindLS* CToolsEx::GetFilmSessionArchive()	{ return &_ToolsEx.m_FilmSessionArchive;	}
COBFindLS* CToolsEx::GetInstanceAvailable()		{ return &_ToolsEx.m_InstanceAvailable;		}
COBFindLS* CToolsEx::GetInstanceStorage()		{ return &_ToolsEx.m_InstanceStorage;		}
COBFindLS* CToolsEx::GetStorageStatus()			{ return &_ToolsEx.m_StorageStatus;			}
COBFindLS* CToolsEx::GetAdmissionSourceTXT()	{ return &_ToolsEx.m_AdmissionSourceTXT;	}
COBFindLL* CToolsEx::GetAdmissionSource()		{ return &_ToolsEx.m_AdmissionSource;		}
COBFindLS* CToolsEx::GetStudiesStatus()			{ return &_ToolsEx.m_StudiesStatus;			}
COBFindLS* CToolsEx::GetReportsStatus()			{ return &_ToolsEx.m_ReportsStatus;			}
COBFindLS* CToolsEx::GetReportsOutStatus()		{ return &_ToolsEx.m_ReportsOutStatus;		}
COBFindLS* CToolsEx::GetQueueStatus()			{ return &_ToolsEx.m_QueueStatus;			}
COBFindLS* CToolsEx::GetStudiesFilms()			{ return &_ToolsEx.m_StudiesFilms;			}
COBFindLS* CToolsEx::GetStudiesReviews()		{ return &_ToolsEx.m_StudiesReviews;		}
COBFindSS* CToolsEx::GetSexDICOM2TXT()			{ return &_ToolsEx.m_SexDICOM2TXT;			}
COBFindSL* CToolsEx::GetSexDICOM2LONG()			{ return &_ToolsEx.m_SexDICOM2LONG;			}
COBFindSS* CToolsEx::GetAgeSuffixDICOM2TXT()	{ return &_ToolsEx.m_AgeSuffixDICOM2TXT;	}
COBFindSL* CToolsEx::GetAgeSuffixDICOM2LONG()	{ return &_ToolsEx.m_AgeSuffixDICOM2LONG;	}
COBFindLS* CToolsEx::GetLogLevel()				{ return &_ToolsEx.m_LogLevel;				}
COBFindLS* CToolsEx::GetLogOperate()			{ return &_ToolsEx.m_LogOperate;			}
COBFindLS* CToolsEx::GetNodeKinds()				{ return &_ToolsEx.m_NodeKinds;				}
COBFindLS* CToolsEx::GetInstancePrint()			{ return &_ToolsEx.m_InstancePrint;			}
COBFindLS* CToolsEx::GetInstanceArchiveAuto()	{ return &_ToolsEx.m_InstanceArchiveAuto;	}
COBFindLS* CToolsEx::GetInstanceArchiveManual()	{ return &_ToolsEx.m_InstanceArchiveManual;	}
COBFindSS* CToolsEx::GetChineseInput()			{ return &_ToolsEx.m_ChineseInput;			}
COBFindLS* CToolsEx::GetLinkDatabase()			{ return &_ToolsEx.m_LinkDatabase;			}
COBFindLS* CToolsEx::GetStudiesMarker()			{ return &_ToolsEx.m_StudiesMarker;			}
COBFindLS* CToolsEx::GetAviToDICOM()			{ return &_ToolsEx.m_AviToDICOM;			}

LPCTSTR CToolsEx::GetOperateTXT(CString& strTXT, LONG nOperateCommands)
{
	strTXT.Empty();

	if ((nOperateCommands & EOC_IMAGE_ARCHIVE) != 0)
	{
		if (!strTXT.IsEmpty()) strTXT += ","; strTXT += "人工归档";
	}
	if ((nOperateCommands & EOC_IMAGE_DELAY_ARCHIVE) != 0)
	{
		if (!strTXT.IsEmpty()) strTXT += ","; strTXT += "延时归档";
	}
	if ((nOperateCommands & EOC_AUTO_ROUTE) != 0)
	{
		if (!strTXT.IsEmpty()) strTXT += ","; strTXT += "路由";
	}
	if ((nOperateCommands & EOC_QR_CONFIRM) > 0)
	{
		if (!strTXT.IsEmpty()) strTXT += ","; strTXT += "查询验证";
	}
	if ((nOperateCommands & EOC_SC_CONFIRM) > 0)
	{
		if (!strTXT.IsEmpty()) strTXT += ","; strTXT += "存储验证";
	}
	if ((nOperateCommands & EOC_SC_CONFIRM_WAIT) > 0)
	{
		if (!strTXT.IsEmpty()) strTXT += ","; strTXT += "存储验证等待";
	}
	if ((nOperateCommands & EOC_SET_VERIFIED) > 0)
	{
		if (!strTXT.IsEmpty()) strTXT += ","; strTXT += "检查完成";
	}

	return strTXT;
}

LPCTSTR CToolsEx::GetMultiValueTXT(CString& strValue, LPCTSTR lpValue)
{
	strValue = lpValue;
	strValue.Replace("\\\\", ",");
	strValue.Replace("\\", "");

	return strValue;
}

LPCTSTR CToolsEx::GetAgeTXT(CString& strAge, COleDateTime timeDate, BOOL bUseChineseAge, UINT nDaysUseDAge, UINT nDaysUseMAge)
{
	strAge = "";

	CString strBuffer;
	if (CToolsEx::GetAgeDICOM(strBuffer, timeDate, bUseChineseAge, nDaysUseDAge, nDaysUseMAge) != NULL)
		CToolsEx::GetAgeTXT(strAge, strBuffer);

	return strAge;
}

LPCTSTR CToolsEx::GetAgeTXT(CString& strAge, LPCTSTR lpDate, BOOL bUseChineseAge, UINT nDaysUseDAge, UINT nDaysUseMAge)
{
	strAge = "";

	CString strDate(lpDate);
	strDate.Replace(".", "");
	if (strDate.GetLength() >= 8)
	{
		COleDateTime TIME(atoi(strDate.Left(4)), atoi(strDate.Mid(4, 2)), atoi(strDate.Right(2)), 0, 0, 0);

		return CToolsEx::GetAgeTXT(strAge, TIME, bUseChineseAge, nDaysUseDAge, nDaysUseMAge);
	}

	return strAge;
}

LPCTSTR CToolsEx::GetAgeTXT(CString& strAge, LPCTSTR lpAge)
{
	strAge = lpAge;

	CString strBuffer;
	for (UINT i = 0; i < CToolsEx::GetAgeSuffixDICOM2TXT()->GetSize(); i++)
	{
		if (strAge.Find(CToolsEx::GetAgeSuffixDICOM2TXT()->GetKey(i)) > 0)
		{
			strBuffer = CToolsEx::GetAgeSuffixDICOM2TXT()->GetValue(i);
			strAge.Replace(CToolsEx::GetAgeSuffixDICOM2TXT()->GetKey(i), "");
			break;
		}
	}

	LONG nAge = atoi(strAge);
	strAge.Format("%d%s", nAge, strBuffer);

	return strAge;
}

LPCTSTR CToolsEx::GetAgeDICOM(CString& strAge, COleDateTime timeDate, BOOL bUseChineseAge, UINT nDaysUseDAge, UINT nDaysUseMAge)
{
	strAge = "";

	COleDateTime TIME = COleDateTime::GetCurrentTime();

	LONG nDays = (TIME - timeDate).GetDays();
	if (nDays < 0)
		strAge = _T("000Y");
	else if (nDays < (LONG) nDaysUseDAge)
		strAge.Format("%03dD", nDays);
	else if (nDays < (LONG) nDaysUseMAge)
		strAge.Format("%03dM", nDays / 30);
	else
	{
		LONG nAge = TIME.GetYear() - timeDate.GetYear();

		strAge.Format("%03dY", (bUseChineseAge) ? nAge + 1 : nAge);
	}

	return strAge;
}

BOOL CToolsEx::GetDOB(COleDateTime& timeDate, LPCTSTR lpAge, BOOL bUseChineseAge)
{
	COleDateTime TIME = COleDateTime::GetCurrentTime();

	CString strAge, strAgeSuffix;
	
	strAge = lpAge;
	strAgeSuffix = strAge.Right(1);
	switch (CToolsEx::GetAgeSuffixDICOM2LONG()->FindValue(strAgeSuffix))
	{
	case 0:
		{
			LONG nAge = atoi(strAge);
			if (bUseChineseAge) nAge--;
			if (nAge < 0) nAge = 0;
			timeDate = COleDateTime(TIME.GetYear() - nAge, 1, 1, 0, 0, 0);
		}
		break;
	case 1:
		timeDate = TIME - COleDateTimeSpan(atoi(strAge) * 30, 0, 0, 0);
		break;
	case 2:
		timeDate = TIME - COleDateTimeSpan(atoi(strAge) * 7, 0, 0, 0);
		break;
	case 3:
		timeDate = TIME - COleDateTimeSpan(atoi(strAge), 0, 0, 0);
		break;
	case 4:
		timeDate = TIME - COleDateTimeSpan(0, atoi(strAge), 0, 0);
		break;
	default:
		timeDate = TIME;
		break;
	}

	return TRUE;
}

BOOL CToolsEx::GetDate(COleDateTime& timeDate, LPCTSTR lpDate)
{
	CString strBuffer;
	
	strBuffer = lpDate;
	strBuffer.Replace(".", "");
	if (strBuffer.GetLength() == 8)
		if (timeDate.SetDate(atoi(strBuffer.Left(4)), atoi(strBuffer.Mid(4, 2)), atoi(strBuffer.Right(2))) == 0)
			return TRUE;

	timeDate.GetCurrentTime();

	return FALSE;
}

LPCTSTR CToolsEx::GetDateTXT(CString& strDate, LPCTSTR lpDate)
{
	strDate = lpDate;
	if (strDate.GetLength() == 8)
	{
		strDate.Insert(4, '-');
		strDate.Insert(7, '-');
	}

	return strDate;
}

LPCTSTR CToolsEx::GetTimeTXT(CString& strTime, LPCTSTR lpTime)
{
	strTime = lpTime;
	if (strTime.GetLength() >= 4)
	{
		strTime.Insert(2, ':');
		strTime = strTime.Left(5);
	}

	return strTime;
}

LPCTSTR CToolsEx::GetDateTimeTXT(CString& strDateTime, LPCTSTR lpDateTime)
{
	strDateTime = lpDateTime;
	if (strDateTime.GetLength() == 8)
	{
		strDateTime.Insert(4, '-');
		strDateTime.Insert(7, '-');
	}
	else if (strDateTime.GetLength() == 14)
	{
		strDateTime.Insert(4, '-');
		strDateTime.Insert(7, '-');
		strDateTime.Insert(10, ' ');
		strDateTime.Insert(13, ':');
		strDateTime.Insert(16, ':');
	}

	return strDateTime;
}

LPCTSTR CToolsEx::GetDateTimeTXT(CString& strDateTime, LPCTSTR lpDate, LPCTSTR lpTime)
{
	strDateTime = lpDate;
	if (strDateTime.GetLength() == 8)
	{
		strDateTime += lpTime;

		return CToolsEx::GetDateTimeTXT(strDateTime, strDateTime);
	}
	else
	{

		strDateTime += lpTime;

		return strDateTime;
	}
}

LPCTSTR CToolsEx::GetMultiValue(CString& strMultiValue, CStringArray* pArray)
{
	strMultiValue = "";

	CString strBuffer;
	for (LONG i = 0; i < pArray->GetSize(); i++)
	{
		strBuffer.Format(_T("\\%s\\"), pArray->GetAt(i));
		strMultiValue += strBuffer;
	}

	return strMultiValue;
}

LPCTSTR CToolsEx::GetMultiValue(CString& strMultiValue, CList<LONG, LONG>* pList)
{
	strMultiValue = "";

	CString strBuffer;
	for (LONG i = 0; i < pList->GetCount(); i++)
	{
		strBuffer.Format(_T("\\%d\\"), pList->GetAt(pList->FindIndex(i)));
		strMultiValue += strBuffer;
	}

	return strMultiValue;
}

BOOL CToolsEx::GetMultiValue(CStringArray* pArray, LPCTSTR lpMultiValue)
{
	pArray->RemoveAll();
	
	CString strBuffer, strSingle;
	strBuffer = lpMultiValue;

	LONG nStart = 0, nClose = 0;
	while (TRUE)
	{
		nStart = strBuffer.Find('\\', nClose);
		if (nStart == -1)
			break;

		nClose = strBuffer.Find('\\', nStart + 1);
		if (nClose == -1)
			break;

		strSingle = strBuffer.Mid(nStart + 1, nClose - nStart - 1);

		if (!strSingle.IsEmpty())
			pArray->Add(strSingle);
	}
	
	if (pArray->GetSize() == 0 && strlen(lpMultiValue) > 0)
	{
		strSingle = lpMultiValue;
		pArray->Add(strSingle);
	}

	return TRUE;
}

BOOL CToolsEx::GetMultiValue(CList<LONG, LONG>* pList, LPCTSTR lpMultiValue)
{
	pList->RemoveAll();
	
	CString strBuffer, strSingle;
	strBuffer = lpMultiValue;

	LONG nStart = 0, nClose = 0, nValue = 0;
	while (TRUE)
	{
		nStart = strBuffer.Find('\\', nClose);
		if (nStart == -1)
			break;

		nClose = strBuffer.Find('\\', nStart + 1);
		if (nClose == -1)
			break;

		strSingle = strBuffer.Mid(nStart + 1, nClose - nStart - 1);
		nValue = atoi(strSingle);
		if (nValue > 0)
			pList->AddTail(nValue);
	}
	
	if (pList->GetCount() == 0 && strlen(lpMultiValue) > 0)
	{
		nValue = atoi(lpMultiValue);
		if (nValue > 0)
			pList->AddTail(nValue);
	}

	return TRUE;
}

LONG CToolsEx::GetWindowsControlID()
{
	static UINT nWindowsControlID = 20000;

	return nWindowsControlID++;
}

BOOL CToolsEx::Decode(CString& strInput, CString& strOutput)
{
	CString strAscii, strBuffer;

	strOutput = "";

	int nLength = strInput.GetLength();

	long lRand;
	strBuffer = strInput.Left(1);
	sscanf(strBuffer, "%d", &lRand);
	lRand += 3;
	int nValue, nIncrease = lRand;

	for (int i = 1; i < nLength; i++){
		strBuffer = strInput.Mid(i, 1);
		sscanf(strBuffer, "%X", &nValue);
		nValue -= nIncrease;
		nIncrease--;
		if (nIncrease == 1)
			nIncrease = lRand;
		if (nValue < 0)
			nValue += 16;
		strBuffer.Format("%X", nValue);
		strAscii += strBuffer;
	}

	char ch;
	nLength = strAscii.GetLength();
	for (i = 0; i < nLength; i += 2){
		strBuffer = strAscii.Mid(i, 2);
		sscanf(strBuffer, "%X", &ch);
		strBuffer.Format("%c", ch);
		strOutput += strBuffer;
	}

	return TRUE;
}

BOOL CToolsEx::Encode(CString& strInput, CString& strOutput)
{
	char ch;
	CString strAscii, strBuffer;

	strOutput = "";

	int nLength = strInput.GetLength();
	for (int i = 0; i < nLength; i++){
		ch = strInput.GetAt(i);
		strBuffer.Format("%02X", ch);
		strAscii += strBuffer;
	}

	long lRand = (rand() * 9L) / RAND_MAX;
	strOutput.Format("%d", lRand);
	lRand += 3;

	int nValue, nIncrease = lRand;

	nLength = strAscii.GetLength();
	for (i = 0; i < nLength; i++){
		strBuffer = strAscii.Mid(i, 1);
		sscanf(strBuffer, "%X", &nValue);
		nValue += nIncrease;
		nIncrease--;
		if (nIncrease == 1)
			nIncrease = lRand;
		if (nValue > 15)
			nValue -= 16;
		strBuffer.Format("%X", nValue);
		strOutput += strBuffer;
	}

	return TRUE;
}

MRET CToolsEx::ZlibDecode(CString& strInput, CString& strOutput)
{
	if (strInput.GetLength() < 12 || strncmp(strInput, ERAD_ZLIB_FORMAT, strlen(ERAD_ZLIB_FORMAT)))
	{
		strOutput = strInput;

		return ME_OK;
	}

	strOutput = "";

	DWORD dwLength = strInput.GetLength();

	COstreamBuffer Ostream((dwLength > 10240) ? dwLength : 10240);

	BYTE lpByte[8];
	for (DWORD i = 12; i < dwLength; )
	{
		memset(lpByte, 0, 8);
		for (DWORD k = 0; k < 8 && i < dwLength; k++, i++)
		{
			char nValue = strInput.GetAt(i);
			if (nValue != 0x5C)
				lpByte[k] = nValue;
			else
			{
				i++;
				nValue = strInput.GetAt(i);
				switch (nValue)
				{
				case '0':
					lpByte[k] = 0x00;
					break;
				case 'F':
					lpByte[k] = 0x7F;
					break;
				case '\\':
					lpByte[k] = 0x5C;
					break;
				}
			}
		}

		BYTE nByte0 = lpByte[0];
		for (k = 1; k < 8; k++)
		{
			lpByte[k - 1] = lpByte[k];
			if ((nByte0 & 0x01) != 0)
				lpByte[k - 1] |= 0x80;
			nByte0 >>= 1;
		}

		MRET rc = Ostream.Write(lpByte, 7);
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
		}
	}

	LPVOID lpvBuffer = NULL;

	MRET rc = Ostream.Flush();
	if (rc == ME_OK) rc = Ostream.FlushBuffer(lpvBuffer, dwLength);

	CIstreamBuffer Istream;
	if (rc == ME_OK) rc = Istream.SetBuffer(lpvBuffer, dwLength);
	if (rc == ME_OK) rc = Istream.InstallCompressionFilter(ESC_ZLIB);
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	dwLength = atoi(strInput.Mid(4, 8));

	LPBYTE lpBuffer = CTools::Alloc(dwLength + 10);
	rc = Istream.Read(lpBuffer, dwLength);
	if (rc != ME_OK)
	{
		delete lpBuffer;
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	strOutput = (LPSTR) lpBuffer;

	delete lpBuffer;

	return ME_OK;
}

MRET CToolsEx::ZlibEncode(CString& strInput, CString& strOutput)
{
	strOutput.Format(_T("%s%8d"), ERAD_ZLIB_FORMAT, strInput.GetLength());

	DWORD dwLength = strInput.GetLength();

	COstreamBuffer Ostream((dwLength > 10240) ? dwLength : 10240);
	MRET rc = Ostream.InstallCompressionFilter(ESC_ZLIB);
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	rc = Ostream.Write((LPVOID) (LPCTSTR) strInput, dwLength);
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	rc = Ostream.Flush();
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	LPVOID lpvBuffer = NULL;
	rc = Ostream.FlushBuffer(lpvBuffer, dwLength);
	if (rc != ME_OK)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
	}

	BYTE lpByte[8];
	LPBYTE lpValue = (LPBYTE) lpvBuffer;
	for (DWORD i = 0; i < dwLength; )
	{
		memset(lpByte, 0, 8);
		for (DWORD k = 1; k < 8 && i < dwLength; k++, i++)
		{
			BYTE nValue = *lpValue++;
			lpByte[k] = nValue & 0x7F;
			if ((nValue & 0x80) != 0)
				lpByte[0] |= 1 << (k - 1);
		}

		DWORD nCount = k;
		for (k = 0; k < nCount; k++)
		{
			switch (lpByte[k])
			{
			case 0x00:
				strOutput += "\\0";
				break;
			case 0x7F:
				strOutput += "\\F";
				break;
			case 0x5C:
				strOutput += "\\\\";
				break;
			default:
				strOutput += (char) lpByte[k];
				break;
			}
		}
	}

	return ME_OK;
}

BOOL CToolsEx::OpenChineseInput()
{
	CString strKeyName, strKeyValue;

	HKEY hKey = NULL;
	LONG nRet = ::RegOpenKeyEx(HKEY_CURRENT_USER, _T("Keyboard Layout\\Preload"), 0, KEY_QUERY_VALUE, &hKey);
	if (nRet != ERROR_SUCCESS)
		return FALSE;

	char lpBuffer[1024];
	DWORD dwSize = sizeof(lpBuffer);
	DWORD i = 0;
	while (::RegEnumValue(hKey, i++, lpBuffer, &dwSize, NULL, NULL, NULL, NULL) != ERROR_NO_MORE_ITEMS)
	{
		strKeyName = lpBuffer;
		if (!strKeyName.IsEmpty())
		{
			dwSize = sizeof(lpBuffer);
			if (::RegQueryValueEx(hKey, strKeyName, NULL, NULL, (LPBYTE) &lpBuffer, &dwSize) == ERROR_SUCCESS)
			{
				strKeyValue = lpBuffer;
				if (!strKeyValue.IsEmpty())
				{
					HKEY hKeyName = NULL;
					CString strKey;
					strKey.Format(_T("SYSTEM\\CurrentControlSet\\Control\\Keyboard Layouts\\%s"), strKeyValue);
					if (::RegOpenKeyEx(HKEY_LOCAL_MACHINE, strKey, 0, KEY_QUERY_VALUE, &hKeyName) == ERROR_SUCCESS)
					{
						dwSize = sizeof(lpBuffer);
						if (::RegQueryValueEx(hKeyName, _T("Layout Text"), NULL, NULL, (LPBYTE) &lpBuffer, &dwSize) == ERROR_SUCCESS)
							_ToolsEx.m_ChineseInput.Add(strKeyValue, lpBuffer);

						RegCloseKey(hKeyName);
					}
				}
			}
		}
	}

	::RegCloseKey(hKey);

	return TRUE;
}

BOOL CToolsEx::OpenChineseSpell()
{
	HANDLE hFile = CreateFile(_T("ChineseSpell.TXT"), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_READONLY, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_OPEN_FILE, _T("ChineseSpell.TXT"));
		return FALSE;
	}

	DWORD dwLength = GetFileSize(hFile, NULL);

	_ToolsEx.m_lpChineseSpell = (char*) GlobalAlloc(GMEM_FIXED, dwLength);
	if (_ToolsEx.m_lpChineseSpell == NULL)
	{
		CloseHandle(hFile);
		LOG_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		return FALSE;
	}

	DWORD dwRead = 0;
	if (!ReadFile(hFile, _ToolsEx.m_lpChineseSpell, dwLength, &dwRead, NULL) || (dwRead != dwLength))
	{
		CloseHandle(hFile);
		GlobalFree(_ToolsEx.m_lpChineseSpell);
		_ToolsEx.m_lpChineseSpell = NULL;
		LOG_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		return FALSE;
	}

	CloseHandle(hFile);

	_ToolsEx.m_dwChineseSpellCount = dwLength / 14;

	return TRUE;
}

BOOL CToolsEx::CloseChineseSpell()
{
	if (_ToolsEx.m_lpChineseSpell != NULL)
		GlobalFree(_ToolsEx.m_lpChineseSpell);

	_ToolsEx.m_lpChineseSpell = NULL;
	_ToolsEx.m_dwChineseSpellCount = 0;

	return TRUE;
}

BOOL CToolsEx::GetSingleSpell(char* lpSpell, DWORD dwSpell, CString strInput, CStringArray& aOutput)
{
	aOutput.RemoveAll();

	if (strInput.GetLength() != 2)
		return FALSE;
	UCHAR chValueH = strInput.GetAt(0);
	UCHAR chValueL = strInput.GetAt(1);
	if (chValueH <= 0x7F || chValueL < 0x40)	//if (chValueH < 127 || chValueL < 127)
		return FALSE;
	
	char lpBuffer[10];
	CString strBuffer;
	
	int nHead	= 0;
	int nLast	= dwSpell;
	bool bFound	= FALSE;
	while (nLast >= nHead && (!bFound))
	{
		int nCenter = (nHead + nLast) / 2;
		
		UCHAR chResourceH = (UCHAR) (*(lpSpell + nCenter * 14));
		UCHAR chResourceL = (UCHAR) (*(lpSpell + nCenter * 14 + 1));
		
		if (chValueH == chResourceH && chValueL == chResourceL)
		{
			bFound = TRUE;

			int i = 0;
			while (nCenter + --i >= 0)
			{
				chResourceH = (UCHAR) (*(lpSpell + (nCenter + i) * 14));
				chResourceL = (UCHAR) (*(lpSpell + (nCenter + i) * 14 + 1));
				if (chValueH != chResourceH || chValueL != chResourceL)
					break;
			}
			i++;
			while (TRUE)
			{
				chResourceH = (UCHAR) (*(lpSpell + (nCenter + i) * 14));
				chResourceL = (UCHAR) (*(lpSpell + (nCenter + i) * 14 + 1));
				if (chValueH != chResourceH || chValueL != chResourceL)
					break;
				
				strncpy(lpBuffer, lpSpell + (nCenter + i) * 14 + 2, 9);
				lpBuffer[9] = 0;
				
				strBuffer = lpBuffer;
				strBuffer.TrimRight();
				
				aOutput.Add(strBuffer);
				i++;
			}
		}
		else if (chValueH > chResourceH)
			nHead = nCenter + 1;
		else if (chValueL > chResourceL && chValueH == chResourceH)
			nHead = nCenter + 1;
		else
			nLast = nCenter - 1;
	}
	
	return bFound;
}

BOOL CToolsEx::GetChineseSpell(UINT nIDResource, CString strInput, CStringArray& aOutput)
{
	DWORD dwSpell = 0;
	char* lpSpell = NULL;
	if (nIDResource != 0)
	{
		HMODULE hModule = GetModuleHandle(NULL);
		HRSRC hResource = FindResource(hModule, MAKEINTRESOURCE(nIDResource), _T("Spell"));
		dwSpell = ::SizeofResource(hModule, hResource) / 14;
		HGLOBAL hGlobal = LoadResource(hModule, hResource);
		lpSpell = (char*) LockResource(hGlobal);
	}
	else
	{
		dwSpell = _ToolsEx.m_dwChineseSpellCount;
		lpSpell = _ToolsEx.m_lpChineseSpell;
	}

	if (dwSpell == 0 || lpSpell == NULL)
	{
		LOG_ERROR(LL_ERROR | LD_FILE, ME_ERR_RESERVED);
		return FALSE;
	}

	aOutput.RemoveAll();

	CString strSingle, strBuffer;

	int i = 0;
	while (i < strInput.GetLength())
	{
		UCHAR nFirst = strInput.GetAt(i);
		if (nFirst <= 0x7F)
		{
			strSingle = strInput.Mid(i, 1);
			int nCount = aOutput.GetSize();
			if (nCount == 0)
				aOutput.Add(strSingle);
			else
			{
				for (int k = 0; k < nCount; k++)
				{
					strBuffer = aOutput.GetAt(k);
					strBuffer += strSingle;
					aOutput.SetAt(k, strBuffer);
				}
			}

			i++;
			continue;
		}

		UCHAR nSecond = strInput.GetAt(i + 1);
		if (nSecond < 0x40)	//if (nSecond <= 0xA0)
		{
			strSingle = strInput.Mid(i, 2);
			int nCount = aOutput.GetSize();
			if (nCount == 0)
				aOutput.Add(strSingle);
			else
			{
				for (int k = 0; k < nCount; k++)
				{
					strBuffer = aOutput.GetAt(k);
					strBuffer += strSingle;
					aOutput.SetAt(k, strBuffer);
				}
			}

			i += 2;
			continue;
		}
		
		CStringArray aSingleSpell;

		strSingle = strInput.Mid(i, 2);
		CToolsEx::GetSingleSpell(lpSpell, dwSpell, strSingle, aSingleSpell);
		int nCount = aOutput.GetSize();
		if (nCount == 0)
			aOutput.Append(aSingleSpell);
		else
		{
			for (int k = 0; k < nCount; k++)
			{
				strBuffer = aOutput.GetAt(k);
				strBuffer += " ";
				for (int m = 0; m < aSingleSpell.GetSize(); m++)
					aOutput.Add(strBuffer + aSingleSpell.GetAt(m));
			}

			for (k = 0; k < nCount; k++)
				aOutput.RemoveAt(0);
		}
		
		i += 2;
	}
	
	return TRUE;
}
