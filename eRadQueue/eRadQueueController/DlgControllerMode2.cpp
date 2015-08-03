// DlgControllerMode2.cpp: implementation of the CDlgControllerMode2 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "eRadQueueController.h"
#include "DlgControllerMode2.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDlgControllerMode2::CDlgControllerMode2()
{
  this->TIME = CTime::GetCurrentTime() - CTimeSpan(1, 0, 0, 0);
}

CDlgControllerMode2::~CDlgControllerMode2()
{
	OBPOS POS = NULL;
	while (this->m_lstQueueCallStorage.GetHead(POS) != NULL)
		delete this->m_lstQueueCallStorage.Remove(POS);
}

MRET CDlgControllerMode2::Load()
{
	COleSession dbSession;
	COleSession* pSession = CRunTime::GetEISSession(&dbSession);
	if (pSession == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_SESSION);
	}

	CdboEISQueue dboQueue;
	dboQueue.SetDataSource(pSession);

	CString strFilter;
	strFilter.Format(_T("WHERE QueueDevice = %d AND QueueDate = %s AND QueueStatus IN (%d, %d) ORDER BY QueueStatus DESC, QueueNumberReset, QueueNumber"), this->m_pController->m_nMode2DeviceIndex, DATETIME_CURRENT_DATE, EIS_QUEUE_WAIT, EIS_QUEUE_ADVANCE);
    
	if (this->m_pController->m_bDesc)  //20101227
	{
	
		strFilter.Format(_T("WHERE QueueDevice = %d AND QueueDate = %s AND QueueStatus IN (%d, %d) ORDER BY QueueTs DESC,QueueStatus DESC"), this->m_pController->m_nMode2DeviceIndex, DATETIME_CURRENT_DATE, EIS_QUEUE_WAIT, EIS_QUEUE_ADVANCE);
		
	}

	//strFilter.Format(_T("WHERE QueueDate = %s AND QueueStatus IN (%d, %d) ORDER BY QueueTs DESC,QueueStatus DESC"), DATETIME_CURRENT_DATE, EIS_QUEUE_WAIT, EIS_QUEUE_ADVANCE);

	if (FAILED(dboQueue.Open(strFilter)))
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE);
	}

	while (dboQueue.MoveNext() == S_OK)
	{
		BOOL bExisted = FALSE;

		OBPOS POS = NULL;
		for (CQueueCall* IT = this->m_lstQueueCallStorage.GetHead(POS); IT != NULL; IT = this->m_lstQueueCallStorage.GetNext(POS))
		{
			if (IT->m_nQueueIndex == dboQueue.m_QueueIndex)
			{
				bExisted = TRUE;
				break;
			}
		}

		if (bExisted)
			continue;

		CQueueCall* pQueueCall = new CQueueCall;

		this->LoadQueueCall(pQueueCall, dboQueue);

		this->m_lstQueueCallStorage.AddTail(pQueueCall);

		if (!this->m_pController->m_bScroll)        //20121211¹ö¶¯
		{
			if (this->m_lstQueueCallStorage.GetSize() >= this->m_pController->m_nControllerRows * this->m_pController->m_nControllerCols)
				break;
		}
	}

	dboQueue.Close();

	return ME_OK;
}

BOOL CDlgControllerMode2::QueueCallManage()
{
	//20101221	static CTime TIME = CTime::GetCurrentTime() - CTimeSpan(1, 0, 0, 0);

  	OBPOS POS = NULL;
	while (this->m_lstQueueCallStorage.GetHead(POS) != NULL)
		delete this->m_lstQueueCallStorage.Remove(POS);

	BOOL bToBeRefresh = FALSE;

	CQueueCall* pQueueCall = this->FindQueueCall();
	if (pQueueCall != NULL)
	{
		bToBeRefresh = TRUE;

		this->m_lstQueueCallStorage.AddTail(pQueueCall);
	}

	if (CTime::GetCurrentTime() > (this->TIME + CTimeSpan(0, 0, 0, this->m_pController->m_nMode2RefreshIdle)))
		bToBeRefresh = TRUE;

	if (bToBeRefresh)
	{
		this->TIME = CTime::GetCurrentTime();

		MRET rc = this->Load();
		if (rc != ME_OK)
		{
			LOG_ERROR(LL_ERROR | LD_FILE, rc);
		}

		EnterCriticalSection(&this->m_pParent->m_CriticalSection);

		CQueueCall* pHeadReserved = NULL;
		if (pQueueCall == NULL || pQueueCall->m_nQueueStatus != EIS_QUEUE_EXAMINE)
		{
			pHeadReserved = this->m_lstQueueCall.GetHead(POS);
			if (pHeadReserved != NULL)
				this->m_lstQueueCall.Remove(POS);
		}

		while (this->m_lstQueueCall.GetHead(POS) != NULL)
			delete this->m_lstQueueCall.Remove(POS);

		if (pHeadReserved != NULL)
		{
			if (pHeadReserved->m_nQueueStatus != EIS_QUEUE_EXAMINE)
				delete pHeadReserved;
			else
			{
				for (CQueueCall* IT = this->m_lstQueueCallStorage.GetHead(POS); IT != NULL; IT = this->m_lstQueueCallStorage.GetNext(POS))
					if (IT->m_nQueueIndex == pHeadReserved->m_nQueueIndex)
						break;

				if (IT != NULL)
					delete pHeadReserved;
				else
					this->m_lstQueueCall.AddTail(pHeadReserved);
			}
		}

		while (this->m_lstQueueCallStorage.GetHead(POS) != NULL)
			this->m_lstQueueCall.AddTail(this->m_lstQueueCallStorage.Remove(POS));

		LONG nRowsCols = this->m_pController->m_nControllerRows * this->m_pController->m_nControllerCols;
		while (this->m_lstQueueCall.GetSize() > nRowsCols)
		{
			if (!this->m_pController->m_bScroll)        //20121211¹ö¶¯
			{
				this->m_lstQueueCall.GetTail(POS);
				delete this->m_lstQueueCall.Remove(POS);
			}
			else
				break;
		}

		if(CRunTime::GetGeneral()->m_bHideName)
			this->m_bVideo = TRUE;

		CDC* pDC = this->GetDC();

		if (this->m_pController->m_bScroll && this->m_lstQueueCall.GetSize() > nRowsCols)
			this->DrawQueueScrollCall();
		else
			this->DrawQueueCall(pDC);

		this->ReleaseDC(pDC);

		if(CRunTime::GetGeneral()->m_bHideName)
			this->m_bVideo = FALSE;

		if (pQueueCall != NULL) this->PlayQueueCallVoice(pQueueCall);
		
		LeaveCriticalSection(&this->m_pParent->m_CriticalSection);
	}
    return TRUE;
}
