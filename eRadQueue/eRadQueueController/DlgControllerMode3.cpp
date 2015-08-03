// DlgControllerMode3.cpp: implementation of the CDlgControllerMode3 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "eRadQueueController.h"
#include "DlgControllerMode3.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDlgControllerMode3::CDlgControllerMode3()
{
    this->TIME = CTime::GetCurrentTime() - CTimeSpan(1, 0, 0, 0);
}

CDlgControllerMode3::~CDlgControllerMode3()
{
	OBPOS POS = NULL;
	while (this->m_lstQueueCallStorage.GetHead(POS) != NULL)
		delete this->m_lstQueueCallStorage.Remove(POS);

	OBPOS POS1 = NULL;
	while (this->m_rectcolumn.GetHead(POS1) != NULL)
		delete this->m_rectcolumn.Remove(POS1);

}

BOOL CDlgControllerMode3::QueueCallManage()
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
	
	if (CTime::GetCurrentTime() > (this->TIME + CTimeSpan(0, 0, 0, this->m_pController->m_MODE3RenovateTime)))
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
				
		LONG mCallNum = 0;
		OBPOS POS2 = NULL;
		for (CRunTime::CITEMColumn* pColumn = this->m_pController->m_lstColumn.GetHead(POS2); pColumn != NULL; pColumn= this->m_pController->m_lstColumn.GetNext(POS2))
		{
            mCallNum +=pColumn->m_MODE3ColumnRows*pColumn->m_MODE3ColumnLines; 
		}
	
		while (this->m_lstQueueCall.GetSize() > mCallNum)
		{
			this->m_lstQueueCall.GetTail(POS);
			delete this->m_lstQueueCall.Remove(POS);
		}

		if(CRunTime::GetGeneral()->m_bHideName)
			this->m_bVideo = TRUE;

		CDC* pDC = this->GetDC();
		
		this->DrawQueueCall(pDC);
		
		this->ReleaseDC(pDC);

		if(CRunTime::GetGeneral()->m_bHideName)
			this->m_bVideo = FALSE;

		if (pQueueCall != NULL) this->PlayQueueCallVoice(pQueueCall);
		
		LeaveCriticalSection(&this->m_pParent->m_CriticalSection);
	}
	
	return TRUE;
}


MRET CDlgControllerMode3::Load()
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
	strFilter.Format(_T("WHERE QueueDevice = %d AND QueueDate = %s AND QueueStatus IN (%d, %d) ORDER BY QueueStatus DESC, QueueNumberReset, QueueNumber"), this->m_pController->m_MODE3QueueIndex, DATETIME_CURRENT_DATE, EIS_QUEUE_WAIT, EIS_QUEUE_ADVANCE);
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

		OBPOS POS2 = NULL;
		LONG mCallNum = 0;
		for (CRunTime::CITEMColumn* pColumn = this->m_pController->m_lstColumn.GetHead(POS2); pColumn != NULL; pColumn= this->m_pController->m_lstColumn.GetNext(POS2))
		{
            mCallNum +=pColumn->m_MODE3ColumnRows*pColumn->m_MODE3ColumnLines; 
		}
		
		if (this->m_lstQueueCallStorage.GetSize() >= mCallNum)
			break;
	}
	
	dboQueue.Close();
	
	return ME_OK;
}


BOOL CDlgControllerMode3::DrawQueueCall(CDC* pDC)
{
	if(CRunTime::GetGeneral()->m_bHideName)
		this->m_bVideo = TRUE;

    OBPOS POS1 = NULL;
    BOOL  BOut = TRUE;
    OBPOS POS2 = NULL;
    UINT Index = 1;
	for ( CRunTime::CITEMColumn* pColumn = this->m_pController->m_lstColumn.GetHead(POS1); pColumn != NULL; pColumn= this->m_pController->m_lstColumn.GetNext(POS1))
	{

		CFont* pFontColumnName = new CFont;
		LOGFONT lf;
		memset(&lf, 0, sizeof(LOGFONT));
		strcpy(lf.lfFaceName,pColumn->m_strColumnNameFontName);
		lf.lfHeight = pColumn->m_nColumnNameFontSize;
		pFontColumnName->CreateFontIndirect(&lf);
		CFont* pFont = pDC->SelectObject(pFontColumnName);
		
		CFont* pFontColumn = new CFont;
		LOGFONT lf1;
		memset(&lf1, 0, sizeof(LOGFONT));
		strcpy(lf1.lfFaceName, pColumn->m_strColumnFontName);
		lf1.lfHeight = pColumn->m_nColumnFontSize;
	    pFontColumn->CreateFontIndirect(&lf1);

        LONG nLine = 0;
		OBPOS POS = NULL;
		
		CString strBuffer1;
		strBuffer1 = pColumn->m_MODE3ColumnName;
		RECT  rc1,rc2;
		CRect recLine;
		recLine = this->m_recQueueCall;
		rc1.left   = pColumn->m_MODE3ColumnLeft;
		rc1.right  = pColumn->m_MODE3ColumnRight;
		rc1.top    = pColumn->m_MODE3ColumnTop;
		rc1.bottom = pColumn->m_MODE3ColumnBottom;
		
		rc2.left   = pColumn->m_MODE3ColumnRight;
		rc2.right  = recLine.right;
		rc2.top    = pColumn->m_MODE3ColumnTop;
		rc2.bottom = pColumn->m_MODE3ColumnBottom;

		pDC->FillSolidRect(&rc1, pColumn->m_clrColumnNameBackground);
		pDC->FillSolidRect(&rc2, pColumn->m_clrColumnBackground);

		pDC->DrawEdge(&rc1,EDGE_ETCHED,BF_RECT);
		pDC->DrawEdge(&rc2,EDGE_ETCHED,BF_RECT);
    	pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(pColumn->m_clrColumnNameForeground);
		CSize txtsize1;
		txtsize1 = pDC->GetTextExtent(strBuffer1);
		//pDC->TextOut(pColumn->m_MODE3ColumnLeft, pColumn->m_MODE3ColumnTop + (pColumn->m_MODE3ColumnBottom - pColumn->m_MODE3ColumnTop - txtsize1.cy )/2, strBuffer1);
		
		CRect temp,rcRect;
		rcRect.left   = pColumn->m_MODE3ColumnLeft;
		rcRect.right  = pColumn->m_MODE3ColumnRight;
		rcRect.top    = pColumn->m_MODE3ColumnTop;
		rcRect.bottom = pColumn->m_MODE3ColumnBottom;
		temp = rcRect;
		int height = pDC->DrawText(strBuffer1,temp,DT_CENTER | DT_WORDBREAK | DT_CALCRECT | DT_EDITCONTROL); // 获得文本高度
		
		rcRect.DeflateRect(0,(rcRect.Height() - height) / 2); 
		pDC->DrawText(strBuffer1,rcRect, DT_CENTER|DT_EDITCONTROL|DT_WORDBREAK);  //多行文字的竖直居中

		for (CQueueCall* pQueueCall = this->m_lstQueueCall.GetAt(Index); pQueueCall != NULL; pQueueCall = this->m_lstQueueCall.GetAt(Index))
		{
			pFont = pDC->SelectObject(pFontColumn);
			if (nLine >=pColumn->m_MODE3ColumnRows*pColumn->m_MODE3ColumnLines)
			{
				break;
			}
			
            if (pQueueCall->m_nQueueStatus != EIS_QUEUE_EXAMINE && BOut)
			{
				BOut = FALSE;
				POS2 = NULL;
				break;
			}
			BOut = FALSE;
			LONG mColumnHeight = (pColumn->m_MODE3ColumnBottom - pColumn->m_MODE3ColumnTop)/pColumn->m_MODE3ColumnRows;
			LONG ColumnWidth = pColumn->m_MODE3ColumnRight - pColumn->m_MODE3ColumnLeft;
			int RecWidth    = this->m_recQueueCall.Width() ;
			LONG mColumnWidth = (RecWidth - ColumnWidth)/pColumn->m_MODE3ColumnLines;

			OBPOS POS4 = NULL;
			UINT  nLenth =0;
			CSize txtsize1;
			for (CRunTime::CITEMVideo* pVideo = this->m_pController->m_lstVideo.GetHead(POS4);pVideo != NULL;pVideo = this->m_pController->m_lstVideo.GetNext(POS4))
			{
				   nLenth+= pVideo->m_nVideoLength;

				   CString strBuffer1;
				   strBuffer1 = pVideo->m_strVideoContent;
				   this->ContentReplace(strBuffer1, pQueueCall);
				   txtsize1 = pDC->GetTextExtent(strBuffer1);
			}
	        CRect rec(pColumn->m_Mode3ColumnRect);

			
			if (!this->m_pController->m_bShowHorizontal)
			{
			//垂直
				rec.OffsetRect((nLine / pColumn->m_MODE3ColumnRows) * mColumnWidth, (nLine % pColumn->m_MODE3ColumnRows) * mColumnHeight);
			}
		    else
			{
			//水平
				rec.OffsetRect((nLine % pColumn->m_MODE3ColumnLines) * mColumnWidth, (nLine / pColumn->m_MODE3ColumnLines) * mColumnHeight);
			}
			
			OBPOS POS3 = NULL;
		
			CRect  rec1 = rec;
			for (CRunTime::CITEMVideo* pVideo1 = this->m_pController->m_lstVideo.GetHead(POS3);pVideo1 != NULL;pVideo1 = this->m_pController->m_lstVideo.GetNext(POS3))
			{
				
		//		pDC->SetTextColor(pColumn->m_clrColumnForeground);
		//		CRect rec(pColumn->m_Mode3ColumnRect);
		//		rec.OffsetRect((nLine / pColumn->m_MODE3ColumnRows) * mColumnWidth, (nLine % pColumn->m_MODE3ColumnRows) * mColumnHeight);
                pDC->SetTextColor(pVideo1->m_clrVideoForeground);
				CString strBuffer;
				strBuffer = pVideo1->m_strVideoContent;
				this->ContentReplace(strBuffer, pQueueCall);
				CSize txtsize;
				txtsize = pDC->GetTextExtent(strBuffer);
        //	    pDC->TextOut(rec1.left +(rec1.right -rec1.left -txtsize.cx)/2, rec1.top + (rec1.Height() - txtsize.cy) / 2, strBuffer);
				pDC->TextOut(rec1.left +(rec1.right -rec1.left -txtsize1.cx)/2, rec1.top + (rec1.Height() - txtsize.cy) / 2, strBuffer);
		//	    rec1.OffsetRect((rec.right - rec.left)*pVideo1->m_nVideoLength/nLenth,0);
				rec1.OffsetRect(txtsize.cx,0);
			
			}

			nLine++;
            Index++;
		}
		pDC->SelectObject(pFont);
        
		
	    if (pFontColumnName != NULL)
	    {
			delete pFontColumnName;
	    }
		if (pFontColumn != NULL)
		{
			delete pFontColumn;
	    }
	
	}
	if(CRunTime::GetGeneral()->m_bHideName)
		this->m_bVideo = FALSE;
	
	return TRUE;
}

BOOL CDlgControllerMode3::ArrangeCalculate()
{
	CRect recLine;
	recLine = this->m_recQueueCall;
	
	recLine.DeflateRect(10, 10);
	OBPOS POS1 = NULL;
	for (CRunTime::CITEMColumn* pColumn = this->m_pController->m_lstColumn.GetHead(POS1);pColumn!= NULL;pColumn = this->m_pController->m_lstColumn.GetNext(POS1))
	{
	    pColumn->m_Mode3ColumnRect.left = pColumn->m_MODE3ColumnRight;
        pColumn->m_Mode3ColumnRect.top  = pColumn->m_MODE3ColumnTop;

		LONG mColumnHeight = (pColumn->m_MODE3ColumnBottom - pColumn->m_MODE3ColumnTop)/pColumn->m_MODE3ColumnRows;
        pColumn->m_Mode3ColumnRect.bottom = pColumn->m_Mode3ColumnRect.top + mColumnHeight;
        
		LONG ColumnWidth  = pColumn->m_MODE3ColumnRight-pColumn->m_MODE3ColumnLeft;
		int recWidth = recLine.Width();
		LONG mColumnWidth = (recWidth - ColumnWidth)/pColumn->m_MODE3ColumnLines;
		pColumn->m_Mode3ColumnRect.right = pColumn->m_Mode3ColumnRect.left + mColumnWidth;
	}

	 return TRUE;
}

