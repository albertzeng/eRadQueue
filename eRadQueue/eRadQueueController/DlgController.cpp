// DlgController.cpp : implementation file
//

#include "stdafx.h"
#include "eRadQueueController.h"
#include "DlgController.h"
#include "Shlwapi.h"

#include "iFly_TTS.h"
#include "mmsystem.h"
#include "vector"
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/*
static const char *g_szCompanyName = "Radinfo";
static const char *g_szUserName = "Liuc";
static const char *g_szProductName = "RadinfoQueue";
static const char *g_szSerialNO = "PTMQPJ-V8JHK5-L2Y4EQ";//序列号 
static const char *g_szServerIp = "127.0.0.1";
*/
/////////////////////////////////////////////////////////////////////////////
// CDlgController dialog


TTSRETVAL SynthProcessProc(HTTSINSTANCE hTTSInstance, PTTSData pTTSData, TTSINT32 lParam, PTTSVOID pUserData)
{

//	static vector<char*> Savevector;

	if(pTTSData->dwOutBufSize > 0)
	{
		BOOL BplaySuccessed = TRUE;	
		BplaySuccessed = PlaySound((char *)pTTSData->pOutBuf,NULL,SND_SYNC|SND_MEMORY);
	 	if (!BplaySuccessed)
		{
			LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, _T("播放合成语音失败"));
		}
/*	
		char* Buffer = new char[pTTSData->dwOutBufSize];
		if (Buffer)
		{
			memcpy(Buffer,pTTSData->pOutBuf,pTTSData->dwOutBufSize);
			Savevector.push_back(Buffer);

		}
		
		
		if(pTTSData->dwOutFlags == TTS_FLAG_DATA_END)//语音合成完毕
		{
			
			for (int i= 0;i< Savevector.size();i++)
			{
				PlaySound((const char*)Savevector[i], NULL, SND_SYNC|SND_MEMORY);
			}
//	PlaySound((const char*)Savevector[1], NULL, SND_ASYNC|SND_MEMORY|SND_LOOP);
			for (int j= 0;j< Savevector.size();j++)
			{
			//	PlaySound((const char*)Savevector[i], NULL, SND_SYNC|SND_MEMORY);
				delete []Savevector[j];
			}
               Savevector.clear();		
		}
		
*/		
	} 	
	return pTTSData->dwErrorCode;
}
 TTSRETVAL SynthEventProc(HTTSINSTANCE hTTSInst, PTTSData pTTSData, TTSINT16 nNotify, TTSINT32 lParam, PTTSVOID pUserData)
 {
	
	 // 目前只支持mark事件
	 if ( nNotify == TTS_EVENT_MARK )
	 {
		 TRACE("Recved a mark event, mark name = %s.\n", lParam);
		 
		 return TTSERR_OK;
	 }
	 return TTSERR_OK;
}

CDlgController::CDlgController(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgController::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgController)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	this->m_pParent			= NULL;
	this->m_pController		= NULL;

	this->m_bExit			= FALSE;
	this->m_hExitEvent		= ::CreateEvent(NULL, TRUE, TRUE, NULL);
	this->m_bVideo          = FALSE;

	this->m_recTitle		= CRect(0, 0, 0, 0);
	this->m_pFontTitle		= NULL;

	this->m_recScroll		= CRect(0, 0, 0, 0);
	this->m_pFontScroll		= NULL;
	this->m_nScrollOffset	= 0;
	this->m_nQueueScrollOffset = 0;

	this->m_recQueueCall	= CRect(0, 0, 0, 0);
	this->m_pFontQueueCall	= NULL;
	this->m_nRowsHeight		= 0;
	this->m_nColsWidth		= 0;

}


void CDlgController::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgController)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgController, CDialog)
	//{{AFX_MSG_MAP(CDlgController)
	ON_WM_DESTROY()
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgController message handlers

BOOL CDlgController::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	//限制启动实例数

	CRect recClient(CPoint(this->m_pController->m_nControllerLeft, this->m_pController->m_nControllerTop), CSize(this->m_pController->m_nControllerWidth, this->m_pController->m_nControllerHeight));
	this->MoveWindow(&recClient);
	this->GetClientRect(&recClient);

	this->m_recTitle = recClient;
	if (this->m_pController->m_bTitleEnable)
	{
		this->m_recTitle.bottom = this->m_recTitle.top + this->m_pController->m_nTitleHeight;
		recClient.top += this->m_pController->m_nTitleHeight;

		this->m_pFontTitle = new CFont;
		LOGFONT lf;
		memset(&lf, 0, sizeof(LOGFONT));
		strcpy(lf.lfFaceName, this->m_pController->m_strTitleFontName);
		lf.lfHeight = this->m_pController->m_nTitleFontSize;
		this->m_pFontTitle->CreateFontIndirect(&lf);
	}

	this->m_recScroll = recClient;
	this->m_recQueueCall = recClient;
	if (this->m_pController->m_bScrollEnable)
	{
		this->m_recScroll.top = this->m_recScroll.bottom - this->m_pController->m_nScrollHeight;
		this->m_recQueueCall.bottom -= this->m_pController->m_nScrollHeight;

		this->m_pFontScroll = new CFont;
		LOGFONT lf;
		memset(&lf, 0, sizeof(LOGFONT));
		strcpy(lf.lfFaceName, this->m_pController->m_strScrollFontName);
		lf.lfHeight = this->m_pController->m_nScrollFontSize;
		this->m_pFontScroll->CreateFontIndirect(&lf);

		this->SetTimer(ID_TIMER_SCROLL, 1000 / this->m_pController->m_nScrollSpeed, NULL);
	}

	this->m_pFontQueueCall = new CFont;
	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	strcpy(lf.lfFaceName, this->m_pController->m_strControllerFontName);
	lf.lfHeight = this->m_pController->m_nControllerFontSize;
	this->m_pFontQueueCall->CreateFontIndirect(&lf);

	this->ArrangeCalculate();

	HANDLE hThread = ::CreateThread(NULL, 0x10000, TProcQueue, this, 0, NULL);
	if (hThread == NULL)
	{
		LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_BEGINTHREAD, _T("CDlgController::TProcQueue!"));
		return FALSE;
	}

	
	//初始化科大飞讯语音包
	if (this->m_pController->m_bUseKdfx)
	{
		
		DWORD dwErr;
		dwErr = TTSInitializeEx(NULL,NULL);
		if(dwErr != TTSERR_OK)
		{
			LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, _T("初始化科大讯飞语音合成库失败！"));
			
		} 
		//初始化科大飞讯语音包	   
	}
    ::CloseHandle(hThread);

	
    return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgController::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CDlgController::OnCancel() 
{
	// TODO: Add extra cleanup here
	
//	CDialog::OnCancel();
}

void CDlgController::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here

	if (this->m_pController->m_bScrollEnable) this->KillTimer(ID_TIMER_SCROLL);

	this->m_bExit = TRUE;

	::WaitForSingleObject(this->m_hExitEvent, INFINITE);

	if (this->m_pFontTitle != NULL)
		delete this->m_pFontTitle;

	if (this->m_pFontScroll != NULL)
		delete this->m_pFontScroll;

	if (this->m_pFontQueueCall != NULL)
		delete this->m_pFontQueueCall;

	OBPOS POS = NULL;
	while (this->m_lstQueueCall.GetHead(POS) != NULL)
		delete this->m_lstQueueCall.Remove(POS);

	
	// 断开与TTS服务的连接
	if (this->m_pController->m_bUseKdfx)
	{
		DWORD dwErr;

		
		dwErr = TTSUninitialize();
		if( dwErr != TTSERR_OK)
		{
			LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, _T("逆初始化失败"));	
		}
	}
	
}

HBRUSH CDlgController::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CDlgController::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here

	this->DrawTitle(&dc);
	this->DrawScroll(&dc);

	EnterCriticalSection(&this->m_pParent->m_CriticalSection);

	this->DrawQueueCall(&dc);

	LeaveCriticalSection(&this->m_pParent->m_CriticalSection);

	// Do not call CDialog::OnPaint() for painting messages
}

void CDlgController::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

	if (nIDEvent == ID_TIMER_SCROLL)
	{
		this->m_nScrollOffset += 10;

		CDC* pDC = this->GetDC();

		this->DrawScroll(pDC);

		this->ReleaseDC(pDC);
	}
	if (nIDEvent == ID_TIMER_QUEUESCROLL)
	{
		CDC* pDC = this->GetDC();
		
		this->DrawQueueCall(pDC);
		
		this->ReleaseDC(pDC);

		this->m_nQueueScrollOffset += this->m_nRowsHeight;
	}

	CDialog::OnTimer(nIDEvent);
}

BOOL CDlgController::ArrangeCalculate()
{
	CRect recLine;
	recLine = this->m_recQueueCall;

	this->m_nColsWidth = recLine.Width() / this->m_pController->m_nControllerCols;
	if (this->m_pController->m_bControllerFromTop)
		recLine.right = recLine.left + this->m_nColsWidth;
	else
	{
		this->m_nColsWidth = - this->m_nColsWidth;
		recLine.left = recLine.right + this->m_nColsWidth;
	}

	recLine.DeflateRect(10, 10);

	LONG nLen = 0;
	OBPOS POS = NULL;
	for (CRunTime::CITEMVideo* pVideo = this->m_pController->m_lstVideo.GetHead(POS); pVideo != NULL; pVideo = this->m_pController->m_lstVideo.GetNext(POS))
		nLen += pVideo->m_nVideoLength;

	if (nLen > 0)
	{
		this->m_nRowsHeight = recLine.Height() / this->m_pController->m_nControllerRows;

		LONG nSingle = recLine.Width() / nLen;

		recLine.DeflateRect((recLine.Width() - nSingle * nLen) / 2, (recLine.Height() - this->m_nRowsHeight * this->m_pController->m_nControllerRows) / 2);

		if (this->m_pController->m_bControllerFromTop)
			recLine.bottom = recLine.top + this->m_nRowsHeight;
		else
		{
			this->m_nRowsHeight = - this->m_nRowsHeight;
			recLine.top = recLine.bottom + this->m_nRowsHeight;
		}

		for (CRunTime::CITEMVideo* pVideo = this->m_pController->m_lstVideo.GetHead(POS); pVideo != NULL; pVideo = this->m_pController->m_lstVideo.GetNext(POS))
		{
			pVideo->m_recVideo = recLine;
			pVideo->m_recVideo.right = pVideo->m_recVideo.left + nSingle * pVideo->m_nVideoLength;

			recLine.left = pVideo->m_recVideo.right;
		}
	}

	return TRUE;
}

BOOL CDlgController::DrawTitle(CDC* pDC)
{
	if (this->m_pController->m_bTitleEnable)
	{
		pDC->FillSolidRect(this->m_recTitle, this->m_pController->m_clrTitleBackground);

		CFont* pFont = pDC->SelectObject(this->m_pFontTitle);

		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(this->m_pController->m_clrTitleForeground);

		CSize txtsize;
		txtsize = pDC->GetTextExtent(this->m_pController->m_strTitleContent);
		//pDC->TextOut(this->m_recTitle.left + (this->m_recTitle.Width() - txtsize.cx) / 2, this->m_recTitle.top + (this->m_recTitle.Height() - txtsize.cy) / 2, this->m_pController->m_strTitleContent);


		CRect rcTemp,rcRectTitle;
		rcRectTitle.left   = this->m_recTitle.left;
		rcRectTitle.right  = this->m_recTitle.right;
		rcRectTitle.top    = this->m_recTitle.top;
		rcRectTitle.bottom = this->m_recTitle.bottom;
		rcTemp = rcRectTitle;
		int height = pDC->DrawText(this->m_pController->m_strTitleContent,rcTemp,DT_CENTER | DT_WORDBREAK | DT_CALCRECT | DT_EDITCONTROL); // 获得文本高度
		
		rcRectTitle.DeflateRect(0,(rcRectTitle.Height() - height) / 2); 
		pDC->DrawText(this->m_pController->m_strTitleContent,rcRectTitle, DT_CENTER|DT_EDITCONTROL|DT_WORDBREAK);  //多行文字的竖直居中

		pDC->SelectObject(pFont);
	}

	return TRUE;
}

BOOL CDlgController::DrawScroll(CDC* pDC)
{
	if (this->m_pController->m_bScrollEnable)
	{
		pDC->FillSolidRect(this->m_recScroll, this->m_pController->m_clrScrollBackground);

		CFont* pFont = pDC->SelectObject(this->m_pFontScroll);

		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(this->m_pController->m_clrScrollForeground);

		CSize txtsize;
		txtsize = pDC->GetTextExtent(this->m_pController->m_strScrollContent);
		if (txtsize.cx < this->m_recScroll.Width())
		{
			this->m_nScrollOffset = 0;
			pDC->TextOut(this->m_recScroll.left + (this->m_recScroll.Width() - txtsize.cx) / 2, this->m_recScroll.top + (this->m_recScroll.Height() - txtsize.cy) / 2, this->m_pController->m_strScrollContent);
		}
		else
		{
			if ((this->m_nScrollOffset < 0) || (this->m_nScrollOffset > txtsize.cx + this->m_recScroll.Width()))
				this->m_nScrollOffset = 0;
			pDC->TextOut(this->m_recScroll.right - this->m_nScrollOffset, this->m_recScroll.top + (this->m_recScroll.Height() - txtsize.cy) / 2, this->m_pController->m_strScrollContent);
		}

		pDC->SelectObject(pFont);
	}

	return TRUE;
}

void CDlgController::DrawQueueScrollCall()
{
	this->SetTimer(ID_TIMER_QUEUESCROLL, 10000 / this->m_pController->m_nQueueScrollSpeed, NULL);
}

BOOL CDlgController::DrawQueueCall(CDC* pDC)  
{
	if(CRunTime::GetGeneral()->m_bHideName)
		this->m_bVideo = TRUE;

	pDC->FillSolidRect(this->m_recQueueCall, this->m_pController->m_clrControllerBackground);
	CFont* pFont = pDC->SelectObject(this->m_pFontQueueCall);

	pDC->SetBkMode(TRANSPARENT);

	LONG nRowsCols = this->m_pController->m_nControllerRows * this->m_pController->m_nControllerCols;

	LONG nLine = 0; 
	OBPOS POS = NULL;
	for (CQueueCall* pQueueCall = this->m_lstQueueCall.GetHead(POS); pQueueCall != NULL; pQueueCall = this->m_lstQueueCall.GetNext(POS), nLine++)
	{
		LONG nIndex = 0;
		OBPOS POS1 = NULL;
		for (CRunTime::CITEMVideo* pVideo = this->m_pController->m_lstVideo.GetHead(POS1); pVideo != NULL; pVideo = this->m_pController->m_lstVideo.GetNext(POS1), nIndex++)
		{
			pDC->SetTextColor(pVideo->m_clrVideoForeground);
			
			CRect rec(pVideo->m_recVideo);
			if (this->m_pController->m_bScroll && this->m_lstQueueCall.GetSize() > nRowsCols)
				rec.OffsetRect((nLine / this->m_lstQueueCall.GetSize()) * this->m_nColsWidth, (nLine % this->m_lstQueueCall.GetSize()) * this->m_nRowsHeight);
			else
			{
				rec.OffsetRect((nLine / this->m_pController->m_nControllerRows) * this->m_nColsWidth, (nLine % this->m_pController->m_nControllerRows) * this->m_nRowsHeight);
				this->m_nQueueScrollOffset = 0;
			}


			//if (rec == pVideo->m_recVideo)                //20111114第一行绿色显示                     
				//pDC->SetTextColor(RGB(0,255,0));          //20111114


			CString strBuffer;
			strBuffer = pVideo->m_strVideoContent;
			this->ContentReplace(strBuffer, pQueueCall);

			CSize txtsize;
			txtsize = pDC->GetTextExtent(strBuffer);

			if(this->m_nQueueScrollOffset > (this->m_lstQueueCall.GetSize() - nRowsCols)* this->m_nRowsHeight)
 				this->m_nQueueScrollOffset = 0;

			
			if(this->m_pController->m_bTitleEnable && this->m_pController->m_bScrollEnable)
			{
				if((rec.top + (rec.Height() + txtsize.cy) / 2 - this->m_nQueueScrollOffset) > this->m_pController->m_nTitleHeight && (rec.top + (rec.Height() + txtsize.cy) / 2 - this->m_nQueueScrollOffset) < (this->m_pController->m_nControllerHeight - this->m_pController->m_nScrollHeight)) //文字不在标题栏滚动栏
					pDC->TextOut(rec.left, rec.top + (rec.Height() - txtsize.cy) / 2 - this->m_nQueueScrollOffset, strBuffer);
			}	
			else if(this->m_pController->m_bTitleEnable && !this->m_pController->m_bScrollEnable)
			{
				if((rec.top + (rec.Height() + txtsize.cy) / 2 - this->m_nQueueScrollOffset) > this->m_pController->m_nTitleHeight) //文字不在标题栏
					pDC->TextOut(rec.left, rec.top + (rec.Height() - txtsize.cy) / 2 - this->m_nQueueScrollOffset, strBuffer);
			}
			else if(!this->m_pController->m_bTitleEnable && this->m_pController->m_bScrollEnable)
			{
				if((rec.top + (rec.Height() + txtsize.cy) / 2 - this->m_nQueueScrollOffset) < (this->m_pController->m_nControllerHeight - this->m_pController->m_nScrollHeight)) //文字不在滚动栏
					pDC->TextOut(rec.left, rec.top + (rec.Height() - txtsize.cy) / 2 - this->m_nQueueScrollOffset, strBuffer);
			}
			else
				pDC->TextOut(rec.left, rec.top + (rec.Height() - txtsize.cy) / 2 - this->m_nQueueScrollOffset, strBuffer);
		}
	}

	pDC->SelectObject(pFont);

	if(CRunTime::GetGeneral()->m_bHideName)
		this->m_bVideo = FALSE;

	return TRUE;
}

BOOL CDlgController::PlayQueueCallVoice(CQueueCall* pQueueCall)
{
	if (pQueueCall != NULL && this->m_pController->m_bVoiceEnable && this->m_pController->m_nVoiceRepeat > 0)
	{
		
		if (this->m_pController->m_bpromptVoiceEnable)//提示音
		{
			char lpModule[_MAX_PATH];
			::GetModuleFileName(NULL, lpModule, sizeof(lpModule));
			
			char lpDrive[_MAX_PATH], lpDir[_MAX_PATH];
			::_splitpath(lpModule, lpDrive, lpDir, NULL, NULL);
			
			strcat(lpDrive, lpDir);
			::SetCurrentDirectory(lpDrive);
			
			CString strBuffer = "";
			strBuffer.Format("%s\\prompt.wav",lpDrive);
			BOOL BplaySuccessed = TRUE;	
			BplaySuccessed = PlaySound(strBuffer, NULL, SND_FILENAME|SND_SYNC); 
			if (!BplaySuccessed)
			{
				LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, _T("播放提示音失败"));
			}
			//		Sleep(this->m_pController->m_nVoiceInterval * 1000);
		}
		
		CString strVoice;
		strVoice = this->m_pController->m_strVoiceFormat;
		this->ContentReplace(strVoice, pQueueCall);
		
		for (LONG i = 0; i < this->m_pController->m_nVoiceRepeat; i++)
		{
			if (i > 0)
				Sleep(this->m_pController->m_nVoiceInterval * 1000);
			//科大飞讯
			
			if (this->m_pController->m_bUseKdfx)
			{
				TTSConnectStruct ttsConnect;
				memset(&ttsConnect, 0, sizeof(TTSConnectStruct));
				ttsConnect.dwSDKVersion = IFLYTTS_SDK_VER;
				
				strcpy(ttsConnect.szServiceUID, "ce30");
				
				
				const char *g_szCompanyName = "RadinfoFSK";
				const char *g_szUserName = "FSK";
				const char *g_szProductName = "RadinfoQueueFSK";
				const char *g_szSerialNO = this->m_pController->m_strSeriesId;
				const char *g_szServerIp = "202.120.191.250";//服务器IP可设置
				//	const char *g_szServerIp = "127.0.0.1";
				
				
				
				strcpy(ttsConnect.szCompanyName, g_szCompanyName);
				strcpy(ttsConnect.szUserName, g_szUserName);
				strcpy(ttsConnect.szProductName, g_szProductName);
				strcpy(ttsConnect.szSerialNumber, g_szSerialNO);
				strcpy(ttsConnect.szTTSServerIP, g_szServerIp);
				ttsConnect.bSetParams = TRUE;
				ttsConnect.nSpeed = CRunTime::GetGeneral()->m_nVoiceRate;
				ttsConnect.nVolume = CRunTime::GetGeneral()->m_nVoiceVolume;
				
				this->m_hTTSInstance = TTSConnect(&ttsConnect);
				if(this->m_hTTSInstance == NULL)
				{
					if( TTSGETERRCODE(ttsConnect.dwErrorCode) == TTSERR_INVALIDSN )
					{
						LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, _T("序列号错误"));
						
					}
					else
					{
						int nRet;
						
						nRet = TTSGETERRCODE(ttsConnect.dwErrorCode);
						
						LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, _T("与TTS建立连接失败"));
						LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, nRet);
						
					}
				}
				
				
				int nMaxInBufSize=0;
				
                nMaxInBufSize = 65536 * 5;//最大输出缓存
				
				DWORD dwErr;
				TTSData tTtsData;
				TTSCallBacks tTtsCB;
				memset( &tTtsData, 0, sizeof(tTtsData));
				memset( &tTtsCB, 0, sizeof(TTSCallBacks));
				
				
				tTtsData.szInBuf=  strVoice.GetBuffer(strVoice.GetLength());
				tTtsData.dwInBufSize = strVoice.GetLength();
				
				
				int nRet = TTSSetParam(this->m_hTTSInstance, TTS_PARAM_OUTBUFSIZE, (TTSINT32*)&nMaxInBufSize,sizeof(nMaxInBufSize));
                if(nRet != TTSERR_OK)
				{
					LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, _T("设置最大缓冲长度失败！"));
				}
				
				// 回调函数数量
				tTtsCB.nNumCallbacks = 1;
				// 过程处理回调函数
				tTtsCB.pfnTTSProcessCB = SynthProcessProc;
				dwErr = TTSSynthTextEx(this->m_hTTSInstance, &tTtsData, &tTtsCB, FALSE, NULL);
				
				strVoice.ReleaseBuffer();
				TTSClean(this->m_hTTSInstance);
				
				dwErr = TTSDisconnect(this->m_hTTSInstance);
				if(dwErr != TTSERR_OK)
				{
					LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, _T("断开连接失败！"));
				}
				
			} 
			//科大飞讯
			if (!this->m_pController->m_bUseKdfx)
			{
				this->m_pParent->m_ModuleTTS.SpeakText(strVoice, CRunTime::GetGeneral()->m_nVoiceRate, CRunTime::GetGeneral()->m_nVoiceVolume, CRunTime::GetGeneral()->m_nVoiceClass, CRunTime::GetGeneral()->m_strVoiceDescription);
			}
			
		}
	}
	return TRUE;
}

BOOL CDlgController::ContentReplace(CString& strQueueCall, CQueueCall* pQueueCall)
{
	strQueueCall.Replace(_T("|1001|"), pQueueCall->m_strQueueDeviceAlias);
	strQueueCall.Replace(_T("|1002|"), pQueueCall->m_strQueueNumber);
	//strQueueCall.Replace(_T("|1003|"), pQueueCall->m_strPatientsAlias);
	strQueueCall.Replace(_T("|1004|"), pQueueCall->m_strPatientsID);
	strQueueCall.Replace(_T("|1005|"), pQueueCall->m_strAdmissionID);
	strQueueCall.Replace(_T("|1006|"), pQueueCall->m_strAccessionNumber);
	strQueueCall.Replace(_T("|1007|"), pQueueCall->m_strCallName);
	strQueueCall.Replace(_T("|1008|"), pQueueCall->m_strQueueClass);
	strQueueCall.Replace(_T("|1009|"), pQueueCall->m_strQueueStatus);

  
	if (pQueueCall->m_strQueueTs.GetLength() != 0)
	{
		CString strBuff = pQueueCall->m_strQueueTs;
     	CString strBuff1,strBuff2;
		strBuff1 = strBuff.Mid(8,2);
		strBuff2 = strBuff.Mid(10,2);
		strBuff.Format("%02d:%02d",atoi(strBuff1),atoi(strBuff2));
		strQueueCall.Replace(_T("|1010|"), strBuff);

	}
	else
	{
        strQueueCall.Replace(_T("|1010|"), "");
	}


	if(pQueueCall->m_nCallNode > 0)                                   //是否顺延已呼叫
		strQueueCall.Replace(_T("|1011|"), TXT_QUEUE_CALL_STATUS);  
	else
		strQueueCall.Replace(_T("|1011|"), "");

	CString strPatAlias("");
	strPatAlias = pQueueCall->m_strPatientsAlias;
	if(CRunTime::GetGeneral()->m_bHideName && this->m_bVideo)
	{
		INT nLen = strPatAlias.GetLength();
			
		if (nLen <= 4)
			strPatAlias = strPatAlias.Left(2) + "○" + strPatAlias.Right(nLen-2);
		else
			strPatAlias = strPatAlias.Left(2) + "○" + strPatAlias.Right(nLen-4);
			
		strQueueCall.Replace(_T("|1003|"), strPatAlias);
	}
	else
		strQueueCall.Replace(_T("|1003|"), strPatAlias);

	return TRUE;
}

BOOL CDlgController::LoadQueueCall(CQueueCall* pQueueCall, CdboEISQueue& dboQueue)
{
	pQueueCall->m_nCallIndex	= 0;
	pQueueCall->m_nQueueIndex	= dboQueue.m_QueueIndex;
	pQueueCall->m_nStudiesIndex	= dboQueue.m_QueueStudies;
	pQueueCall->m_nQueueStatus	= dboQueue.m_QueueStatus;

	pQueueCall->m_strQueueDeviceAlias	= dboQueue.m_QueueDeviceAlias;
	pQueueCall->m_strQueueNumber		= dboQueue.m_QueueNumberExtension;   /////
	pQueueCall->m_strPatientsAlias		= dboQueue.m_PatientsAlias;
	pQueueCall->m_strPatientsID			= dboQueue.m_PatientsID;
	pQueueCall->m_strAdmissionID		= dboQueue.m_AdmissionID;
	pQueueCall->m_strAccessionNumber	= dboQueue.m_AccessionNumber;
	pQueueCall->m_strExamineAlias		= dboQueue.m_ExamineAlias;
	pQueueCall->m_strCallName			= dboQueue.m_QueueCallName;
	pQueueCall->m_strQueueTs            = dboQueue.m_QueueTS;
	pQueueCall->m_nCallNode             = dboQueue.m_QueueCallNode;

	if (1 == dboQueue.m_QueueEmergent)
		pQueueCall->m_strQueueClass = TXT_QUEUE_CLASS_EMERGENT;
	if (10 == dboQueue.m_QueueEmergent) //20110428
	{
        pQueueCall->m_strQueueClass = TXT_QUEUE_CLASS_TEZHEN;
	}
	else if (dboQueue.m_QueuePrearrange)
		pQueueCall->m_strQueueClass = TXT_QUEUE_CLASS_PREARRANGE;

	if (dboQueue.m_QueueStatus == EIS_QUEUE_EXAMINE)
		pQueueCall->m_strQueueStatus = TXT_QUEUE_STATUS_EXAMINE;
	else if (dboQueue.m_QueueStatus == EIS_QUEUE_WAIT || dboQueue.m_QueueStatus == EIS_QUEUE_ADVANCE)
		pQueueCall->m_strQueueStatus = TXT_QUEUE_STATUS_WAIT;

	return TRUE;
}

BOOL CDlgController::LoadQueueCall(CQueueCall* pQueueCall, CdbovEISQueueCall& dbovQueueCall)
{
	pQueueCall->m_nCallIndex	= dbovQueueCall.m_CallIndex;
	pQueueCall->m_nQueueIndex	= dbovQueueCall.m_QueueIndex;
	pQueueCall->m_nStudiesIndex	= dbovQueueCall.m_QueueStudies;
	pQueueCall->m_nQueueStatus	= dbovQueueCall.m_QueueStatus;

	pQueueCall->m_strQueueDeviceAlias	= dbovQueueCall.m_QueueDeviceAlias;
	pQueueCall->m_strQueueNumber		= dbovQueueCall.m_QueueNumberExtension;  /////
	pQueueCall->m_strPatientsAlias		= dbovQueueCall.m_PatientsAlias;
	pQueueCall->m_strPatientsID			= dbovQueueCall.m_PatientsID;
	pQueueCall->m_strAdmissionID		= dbovQueueCall.m_AdmissionID;
	pQueueCall->m_strAccessionNumber	= dbovQueueCall.m_AccessionNumber;
	pQueueCall->m_strExamineAlias		= dbovQueueCall.m_ExamineAlias;
	//pQueueCall->m_strCallName			= dbovQueueCall.m_CallName;
	pQueueCall->m_strCallName			= dbovQueueCall.m_QueueCallName;
	//pQueueCall->m_nCallNode           = dbovQueueCall.m_CallNode;             //20111027
	pQueueCall->m_nCallNode             = dbovQueueCall.m_QueueCallNode;             //20111027

	if (1 == dbovQueueCall.m_QueueEmergent)
		pQueueCall->m_strQueueClass = TXT_QUEUE_CLASS_EMERGENT;
	if (10 == dbovQueueCall.m_QueueEmergent) //20110428
		pQueueCall->m_strQueueClass = TXT_QUEUE_CLASS_TEZHEN;
	else if (dbovQueueCall.m_QueuePrearrange)
		pQueueCall->m_strQueueClass = TXT_QUEUE_CLASS_PREARRANGE;

	if (dbovQueueCall.m_QueueStatus == EIS_QUEUE_EXAMINE)
		pQueueCall->m_strQueueStatus = TXT_QUEUE_STATUS_EXAMINE;
	else if (dbovQueueCall.m_QueueStatus == EIS_QUEUE_WAIT || dbovQueueCall.m_QueueStatus == EIS_QUEUE_ADVANCE)
		pQueueCall->m_strQueueStatus = TXT_QUEUE_STATUS_WAIT;

	return TRUE;
}

BOOL CDlgController::LoadQueueCall(CQueueCall* pQueueCall, CdbovEISWorksLists& dbovWorklists)
{
	pQueueCall->m_nCallIndex	= 0;
	pQueueCall->m_nQueueIndex	= 0;
	pQueueCall->m_nStudiesIndex	= dbovWorklists.m_StudiesIndex;
	pQueueCall->m_nQueueStatus	= 0;

	pQueueCall->m_strQueueDeviceAlias	.Empty();
	pQueueCall->m_strQueueNumber		.Empty();
	pQueueCall->m_strPatientsAlias		= dbovWorklists.m_PatientsAlias;
	pQueueCall->m_strPatientsID			= dbovWorklists.m_PatientsID;
	pQueueCall->m_strAdmissionID		= dbovWorklists.m_AdmissionID;
	pQueueCall->m_strAccessionNumber	= dbovWorklists.m_AccessionNumber;
	pQueueCall->m_strExamineAlias		= dbovWorklists.m_ResultsExamineAlias;
	pQueueCall->m_strCallName			.Empty();

	return TRUE;
}

CDlgController::CQueueCall* CDlgController::FindQueueCall()
{
	COleSession dbSession;
	COleSession* pSession = CRunTime::GetEISSession(&dbSession);
	if (pSession == NULL)
	{
		LOG_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_SESSION);
		return NULL;
	}

	CString strFilter;
	
	strFilter.Format(_T("WHERE CallConsole = %d ORDER BY CallIndex"), this->m_pController->m_nControllerNode);

	CdbovEISQueueCall dbovQueueCall;
	dbovQueueCall.SetDataSource(pSession);
	if (FAILED(dbovQueueCall.Open(strFilter)))
	{
		LOG_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE);
		return NULL;
	}

	CQueueCall* pQueueCall = NULL;
	if (dbovQueueCall.MoveNext() == S_OK)
	{
		pQueueCall = new CQueueCall;

		this->LoadQueueCall(pQueueCall, dbovQueueCall);
	}
	
	dbovQueueCall.Close();

	if (pQueueCall != NULL)
	{
		strFilter.Format(_T("DELETE FROM EISQueueCall WHERE CallIndex = %d"), pQueueCall->m_nCallIndex);
		if (FAILED(pSession->Execute(strFilter)))
		{
			LOG_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_DELETE);
		}
	}

	return pQueueCall;
}


DWORD WINAPI CDlgController::TProcQueue(LPVOID lpvParameter)
{
	CoInitialize(NULL);

	CDlgController* pDlgController = (CDlgController*) lpvParameter;

	ResetEvent(pDlgController->m_hExitEvent);

	while (!pDlgController->m_bExit)
	{
#ifdef CATCH_EXCEPTION
		try
#endif // CATCH_EXCEPTION
		{
			pDlgController->QueueCallManage();
		}
#ifdef CATCH_EXCEPTION
		catch (...) {
			try {
				LOG_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_CATCH_EXCEPTION, _T("CDlgController::TProcQueue!"));
			}
			catch (...) {}
		}
#endif // CATCH_EXCEPTION

		Sleep(1000);
	}

	SetEvent(pDlgController->m_hExitEvent);

	CoUninitialize();

	return 0;
}


