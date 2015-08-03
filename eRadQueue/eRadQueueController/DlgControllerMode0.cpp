// DlgControllerMode0.cpp: implementation of the CDlgControllerMode0 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "eRadQueueController.h"
#include "DlgControllerMode0.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDlgControllerMode0::CDlgControllerMode0()
{

}

CDlgControllerMode0::~CDlgControllerMode0()
{

}

BOOL CDlgControllerMode0::QueueCallManage()
{
	CQueueCall* pQueueCall = this->FindQueueCall();
	if (pQueueCall != NULL)
	{
		EnterCriticalSection(&this->m_pParent->m_CriticalSection);

		OBPOS POS = NULL;
		for (CQueueCall* IT = this->m_lstQueueCall.GetHead(POS); IT != NULL; IT = this->m_lstQueueCall.GetNext(POS))
		{
			if (IT->m_nQueueIndex == pQueueCall->m_nQueueIndex)
			{
				delete this->m_lstQueueCall.Remove(POS);
				break;
			}
		}

		LONG nRowsCols = this->m_pController->m_nControllerRows * this->m_pController->m_nControllerCols;
		while (this->m_lstQueueCall.GetSize() > nRowsCols - 1)
		{
			this->m_lstQueueCall.GetHead(POS);
			delete this->m_lstQueueCall.Remove(POS);
		}

		this->m_lstQueueCall.AddTail(pQueueCall);

		if(CRunTime::GetGeneral()->m_bHideName)
			this->m_bVideo = TRUE;

		CDC* pDC = this->GetDC();

		this->DrawQueueCall(pDC);

		this->ReleaseDC(pDC);

		if(CRunTime::GetGeneral()->m_bHideName)
			this->m_bVideo = FALSE;

		this->PlayQueueCallVoice(pQueueCall);

		LeaveCriticalSection(&this->m_pParent->m_CriticalSection);
	}

	return TRUE;
}
