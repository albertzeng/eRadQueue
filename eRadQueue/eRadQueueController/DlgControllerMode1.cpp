// DlgControllerMode1.cpp: implementation of the CDlgControllerMode1 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "eRadQueueController.h"
#include "DlgControllerMode1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDlgControllerMode1::CDlgControllerMode1()
{
   this->TIME = CTime::GetCurrentTime() - CTimeSpan(1, 0, 0, 0);
}

CDlgControllerMode1::~CDlgControllerMode1()
{
	OBPOS POS = NULL;
	while (this->m_lstQueueCallStorage.GetHead(POS) != NULL)
		delete this->m_lstQueueCallStorage.Remove(POS);
}

MRET CDlgControllerMode1::Load()
{
	COleSession dbSession;
	COleSession* pSession = CRunTime::GetEISSession(&dbSession);
	if (pSession == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_SESSION);
	}

	CString strFilter, strBuffer;
	strFilter.Format(_T("WHERE StudiesDepartment = %d AND ReportsStatus >= %d"), CRunTime::GetGeneral()->m_nUseDepartment, EIS_REPORTS_APPROVE);

	CTime TIME = CTime::GetCurrentTime() - CTimeSpan(0, this->m_pController->m_nMode1TimeRange, 0, 0);
	strBuffer.Format(_T(" AND ((ApproveDate > '%s') OR (ApproveDate = '%s' AND ApproveTime > '%s'))"), TIME.Format("%Y%m%d"), TIME.Format("%Y%m%d"), TIME.Format("%H%M%S"));
	strFilter += strBuffer;

	if (this->m_pController->m_nMode1TimeDelay > 0)
	{
		CTime TIME = CTime::GetCurrentTime() - CTimeSpan(0, 0, this->m_pController->m_nMode1TimeDelay, 0);
		strBuffer.Format(_T(" AND ((ApproveDate < '%s') OR (ApproveDate = '%s' AND ApproveTime < '%s'))"), TIME.Format("%Y%m%d"), TIME.Format("%Y%m%d"), TIME.Format("%H%M%S"));
		strFilter += strBuffer;
	}

	if (!this->m_pController->m_strMode1AdmissionSource.IsEmpty())
	{
		strBuffer.Format(_T(" AND AdmissionSource IN (%s)"), this->m_pController->m_strMode1AdmissionSource);
		strBuffer.Replace(_T("\\\\"), _T(","));
		strBuffer.Replace(_T("\\"), _T(""));
		strFilter += strBuffer;
	}

	if (!this->m_pController->m_strMode1SourceHospital.IsEmpty())
	{
		strBuffer.Format(_T(" AND AdmissionSourceHospital IN ('%s')"), this->m_pController->m_strMode1SourceHospital);
		strBuffer.Replace(_T("\\\\"), _T("','"));
		strBuffer.Replace(_T("\\"), _T(""));
		strFilter += strBuffer;
	}

	if (!this->m_pController->m_strMode1ExcludeOutStatus.IsEmpty())
	{
		strBuffer.Format(_T(" AND ReportsOutStatus NOT IN (%s)"), this->m_pController->m_strMode1ExcludeOutStatus);
		strBuffer.Replace(_T("\\\\"), _T(","));
		strBuffer.Replace(_T("\\"), _T(""));
		strFilter += strBuffer;
	}

	switch (this->m_pController->m_nMode1OrderMode)
	{
	case EMOM_PATIENTS_ALIAS:
		strFilter += _T(" ORDER BY PatientsAlias");
		break;
	case EMOM_ACCESSION_NUMBER:
		strFilter += _T(" ORDER BY AccessionNumber");
		break;
	}

	LOG_MESSAGE(LL_DEBUG | LD_FILE, strFilter);

	CdbovEISWorksLists dbovWorklists;
	dbovWorklists.SetDataSource(pSession);
	if (FAILED(dbovWorklists.Open(strFilter)))
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE);
	}

	while (dbovWorklists.MoveNext() == S_OK)
	{
		CQueueCall* pQueueCall = new CQueueCall;

		this->LoadQueueCall(pQueueCall, dbovWorklists);

		this->m_lstQueueCallStorage.AddTail(pQueueCall);
	}

	dbovWorklists.Close();

	return ME_OK;
}

BOOL CDlgControllerMode1::QueueCallManage()
{
	//20101221	static CTime TIME = CTime::GetCurrentTime() - CTimeSpan(1, 0, 0, 0);

 
	LONG nRowsCols = this->m_pController->m_nControllerRows * this->m_pController->m_nControllerCols;
	if (CTime::GetCurrentTime() > (this->TIME + CTimeSpan(0, 0, 0, this->m_pController->m_nMode1RefreshScreen)))
	{
		this->TIME = CTime::GetCurrentTime();

		EnterCriticalSection(&this->m_pParent->m_CriticalSection);

		OBPOS POS = NULL;
		while (this->m_lstQueueCall.GetHead(POS) != NULL)
			delete this->m_lstQueueCall.Remove(POS);

		if (this->m_lstQueueCallStorage.GetSize() == 0)
		{
			MRET rc = this->Load();
			if (rc != ME_OK)
			{
				LOG_ERROR(LL_ERROR | LD_FILE, rc);
			}
		}

		while (this->m_lstQueueCallStorage.GetHead(POS) != NULL && this->m_lstQueueCall.GetSize() < nRowsCols)
			this->m_lstQueueCall.AddTail(this->m_lstQueueCallStorage.Remove(POS));

		CDC* pDC = this->GetDC();

		this->DrawQueueCall(pDC);

		this->ReleaseDC(pDC);

		LeaveCriticalSection(&this->m_pParent->m_CriticalSection);
	}

	return TRUE;
}
