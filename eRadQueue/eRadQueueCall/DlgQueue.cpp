// DlgQueue.cpp : implementation file
//

#include "stdafx.h"
#include "eRadQueueCall.h"
#include "DlgQueue.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define	QUEUE_SHRINK_HEIGHT		48
#define	QUEUE_MINIMAL_WIDTH		200
#define	QUEUE_MINIMAL_HEIGHT	200

#define HM_NONE 0
#define HM_TOP 1
#define CM_ELAPSE 200 
#define HS_ELAPSE 5
#define HS_STEPS 10
#define INTERVAL 20
#define INFALTE  10

CDlgQueue* _pDlgQueue = NULL;

MRET API_OpenConfiguration()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CSetSheet dlgSheet(_T(""));
	dlgSheet.m_psh.dwFlags &= ~PSH_HASHELP;
	dlgSheet.m_psh.dwFlags |= PSH_NOAPPLYNOW;
	dlgSheet.m_psh.dwFlags |= PSH_PROPTITLE;

	CPageGeneral			dlgGeneral;

	dlgGeneral				.m_psp.dwFlags &= ~PSP_HASHELP;

	dlgSheet.AddPage(&dlgGeneral);

	SET_LEFT_FROM_RIGHT(dlgGeneral.m_nCallNode,					CRunTime::GetGeneral()->m_nCallNode);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_strCallName,				CRunTime::GetGeneral()->m_strCallName);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_strCallConsole,			CRunTime::GetGeneral()->m_strCallConsole);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_strCallDevice,				CRunTime::GetGeneral()->m_strCallDevice);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_strCallRoom,				CRunTime::GetGeneral()->m_strCallRoom);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_strCallRoomNode,			CRunTime::GetGeneral()->m_strCallRoomNode);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_strMZQueue,			    CRunTime::GetGeneral()->m_strMZQueue);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_strZYQueue,			    CRunTime::GetGeneral()->m_strZYQueue);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_nCallDepartment,			CRunTime::GetGeneral()->m_nCallDepartment);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bCallPriority,				CRunTime::GetGeneral()->m_bCallPriority);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bCallOrder,				CRunTime::GetGeneral()->m_bCallOrder);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bCallCaptureReport,		CRunTime::GetGeneral()->m_bCallCaptureReport);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bCallCapture,				CRunTime::GetGeneral()->m_bCallCapture);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bCallReport,				CRunTime::GetGeneral()->m_bCallReport);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bCallComplete,				CRunTime::GetGeneral()->m_bCallComplete);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bCallReset,				CRunTime::GetGeneral()->m_bCallReset);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_nCallIncrement,			CRunTime::GetGeneral()->m_nCallIncrement);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bCallCancel,				CRunTime::GetGeneral()->m_bCallCancel);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bCallUnready,				CRunTime::GetGeneral()->m_bCallUnready);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bCallWait,					CRunTime::GetGeneral()->m_bCallWait);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bAfternoon,				CRunTime::GetGeneral()->m_bAfternoon);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_strAfternoonTime,			CRunTime::GetGeneral()->m_strAfternoonTime);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_nAutoRefresh,				CRunTime::GetGeneral()->m_nAutoRefresh);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bCallOrderNoReport,        CRunTime::GetGeneral()->m_bCallOrderNoReport); //20110724
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bCallIQueueRoom,           CRunTime::GetGeneral()->m_bCallIQueueRoom);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bCallQueuePatientKind,     CRunTime::GetGeneral()->m_bCallQueuePatientKind);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bNoPopOrderCall,			CRunTime::GetGeneral()->m_bNoPopOrderCall);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bCallPre,			        CRunTime::GetGeneral()->m_bCallPre);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bPrivateSaveToFile,		CRunTime::GetGeneral()->m_bPrivateSaveToFile);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bLogTRACK,					CRunTime::GetGeneral()->m_bLogTRACK);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bLogDEBUG,					CRunTime::GetGeneral()->m_bLogDEBUG);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bLogERROR,					CRunTime::GetGeneral()->m_bLogERROR);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bLogMESSAGE,				CRunTime::GetGeneral()->m_bLogMESSAGE);

	if (dlgSheet.DoModal() == IDOK)
	{
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_nCallNode,				CRunTime::GetGeneral()->m_nCallNode);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_strCallName,			CRunTime::GetGeneral()->m_strCallName);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_strCallConsole,		CRunTime::GetGeneral()->m_strCallConsole);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_strCallDevice,			CRunTime::GetGeneral()->m_strCallDevice);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_strCallRoom,			CRunTime::GetGeneral()->m_strCallRoom);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_strCallRoomNode,		CRunTime::GetGeneral()->m_strCallRoomNode);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_strMZQueue,		    CRunTime::GetGeneral()->m_strMZQueue);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_strZYQueue,		    CRunTime::GetGeneral()->m_strZYQueue);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_nCallDepartment,		CRunTime::GetGeneral()->m_nCallDepartment);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bCallPriority,			CRunTime::GetGeneral()->m_bCallPriority);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bCallOrder,			CRunTime::GetGeneral()->m_bCallOrder);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bCallCaptureReport,	CRunTime::GetGeneral()->m_bCallCaptureReport);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bCallCapture,			CRunTime::GetGeneral()->m_bCallCapture);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bCallReport,			CRunTime::GetGeneral()->m_bCallReport);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bCallComplete,			CRunTime::GetGeneral()->m_bCallComplete);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bCallReset,			CRunTime::GetGeneral()->m_bCallReset);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_nCallIncrement,		CRunTime::GetGeneral()->m_nCallIncrement);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bCallCancel,			CRunTime::GetGeneral()->m_bCallCancel);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bCallUnready,			CRunTime::GetGeneral()->m_bCallUnready);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bCallWait,				CRunTime::GetGeneral()->m_bCallWait);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bAfternoon,			CRunTime::GetGeneral()->m_bAfternoon);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_strAfternoonTime,		CRunTime::GetGeneral()->m_strAfternoonTime);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_nAutoRefresh,			CRunTime::GetGeneral()->m_nAutoRefresh);
        SET_RIGHT_FROM_LEFT(dlgGeneral.m_bCallOrderNoReport,    CRunTime::GetGeneral()->m_bCallOrderNoReport);//20110724
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bCallIQueueRoom,       CRunTime::GetGeneral()->m_bCallIQueueRoom);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bCallQueuePatientKind, CRunTime::GetGeneral()->m_bCallQueuePatientKind);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bNoPopOrderCall,		CRunTime::GetGeneral()->m_bNoPopOrderCall);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bCallPre,		        CRunTime::GetGeneral()->m_bCallPre);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bPrivateSaveToFile,	CRunTime::GetGeneral()->m_bPrivateSaveToFile);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bLogTRACK,				CRunTime::GetGeneral()->m_bLogTRACK);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bLogDEBUG,				CRunTime::GetGeneral()->m_bLogDEBUG);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bLogERROR,				CRunTime::GetGeneral()->m_bLogERROR);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bLogMESSAGE,			CRunTime::GetGeneral()->m_bLogMESSAGE);

		MRET rc = CRunTime::ExchangeXML(TRUE);
		if (rc != ME_OK)
		{
			LOG_RET_ERROR(LL_ERROR | LD_ALL, rc);
		}
	}

	return ME_OK;
}

MRET API_SetQueueCallProc(CALLBACK_QUEUE_CALL_PROC lpcbQueueCallProc)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (_pDlgQueue == NULL)
		_pDlgQueue = new CDlgQueue;

	return _pDlgQueue->SetQueueCallProc(lpcbQueueCallProc);
}

MRET API_StartQueueCall(LONG nDoctorIndex, LONG nDoctorDepartment, LONG nDoctorPrivilege, CString strDoctorCode, CString strDoctorName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return _pDlgQueue->StartQueueCall(nDoctorIndex, nDoctorDepartment, nDoctorPrivilege, strDoctorCode, strDoctorName);
}

MRET API_CloseQueueCall()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

    if (_pDlgQueue == NULL)
    {
       return ME_OK;
    }
    MRET rc = _pDlgQueue->CloseQueueCall();
	delete  _pDlgQueue; //20110510
	_pDlgQueue = NULL;
	return rc;
}

MRET API_QueueCallComplete(LONG nQueueIndex)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	return _pDlgQueue->QueueCallComplete(nQueueIndex);
}

/////////////////////////////////////////////////////////////////////////////
// CDlgQueue dialog


CDlgQueue::CDlgQueue(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgQueue::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgQueue)
	m_bAutoRefresh = TRUE;
	m_bCallWait = FALSE;
	m_bCallAllRoom = TRUE;
	m_bGeneralMode = TRUE;
	m_nQueueCallRoom = -1;
	//}}AFX_DATA_INIT

	this->m_bInitDialog			= FALSE;
	this->m_bShowNormal			= TRUE;
	this->m_bFirstRun           = TRUE;

	this->m_nQueueIndexCall		= 0;
	this->m_lpcbQueueCallProc	= NULL;

	m_isSizeChanged = FALSE;
	m_isSetTimer = FALSE;
	m_hsFinished = TRUE;
	m_hiding = FALSE;
	m_edgeHeight = 0;
	m_edgeWidth=0;
    m_hideMode = HM_NONE;
}


void CDlgQueue::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgQueue)
	DDX_Control(pDX, IDC_COMBO_QUEUE_STATUS, m_cboQueueStatus);
	DDX_Control(pDX, IDC_COMBO_QUEUE_ROOM, m_cboQueueRoom);     //20121214
	DDX_Control(pDX, IDC_COMBO_QUEUE_SETTING, m_cboQueueSetting); 
	DDX_Control(pDX, IDC_LIST_QUEUE, m_listQueue);
	DDX_Check(pDX, IDC_CHECK_AUTO_REFRESH, m_bAutoRefresh);
	DDX_Check(pDX, IDC_CHECK_CALL_WAIT, m_bCallWait);
	DDX_Check(pDX, IDC_CHECK_CALL_ALL_ROOM, m_bCallAllRoom);
	DDX_CBIndex(pDX, IDC_COMBO_QUEUE_ROOM, m_nQueueCallRoom);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgQueue, CDialog)
	//{{AFX_MSG_MAP(CDlgQueue)
	ON_WM_DESTROY()
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON_CALL_ORDER, OnButtonCallOrder)
	ON_BN_CLICKED(IDC_BUTTON_CALL_CAPTURE_REPORT, OnButtonCallCaptureReport)
	ON_BN_CLICKED(IDC_BUTTON_CALL_CAPTURE, OnButtonCallCapture)
	ON_BN_CLICKED(IDC_BUTTON_CALL_REPORT, OnButtonCallReport)
	ON_BN_CLICKED(IDC_BUTTON_CALL_REPEAT, OnButtonCallRepeat)
	ON_BN_CLICKED(IDC_BUTTON_REFRESH, OnButtonRefresh)
	ON_BN_CLICKED(IDC_BUTTON_CALL_COMPLETE, OnButtonCallComplete)
	ON_BN_CLICKED(IDC_BUTTON_CALL_RESET, OnButtonCallReset)
	ON_BN_CLICKED(IDC_BUTTON_CALL_UNREADY, OnButtonCallUnready)
	ON_BN_CLICKED(IDC_BUTTON_CALL_CANCEL, OnButtonCallCancel)
	ON_NOTIFY(NM_CLICK, IDC_LIST_QUEUE, OnClickListQueue)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_QUEUE, OnDblclkListQueue)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_QUEUE, OnRclickListQueue)
	ON_WM_NCHITTEST()
	ON_WM_MOVING()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON_CALL_PRE, OnButtonCallPre)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgQueue message handlers

BOOL CDlgQueue::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	this->m_bInitDialog = TRUE;

	this->GetWindowText(this->m_strTitle);

	CRect recDesktop;
	this->GetDesktopWindow()->GetClientRect(&recDesktop);

	CRect rec;
	rec = CRunTime::GetUser()->m_recDlgQueue;
	rec.NormalizeRect();
	if (rec.IsRectEmpty() || rec.Width() < QUEUE_MINIMAL_WIDTH || rec.Height() < QUEUE_MINIMAL_HEIGHT)
		this->SetWindowPos(NULL, recDesktop.left + 400, recDesktop.top, 0, 0, SWP_HIDEWINDOW | SWP_NOZORDER | SWP_NOSIZE);
	else
	{
		LONG nOffsetX = 0, nOffsetY = 0;
		if (rec.left < recDesktop.left)
			nOffsetX = recDesktop.left - rec.left;
		else if (rec.right > recDesktop.right)
			nOffsetX = recDesktop.right - rec.right;
		if (rec.top < recDesktop.top)
			nOffsetY = recDesktop.top - rec.top;
		else if (rec.top + QUEUE_SHRINK_HEIGHT > recDesktop.bottom)
			nOffsetY = recDesktop.bottom - (rec.top + QUEUE_SHRINK_HEIGHT);

		rec.OffsetRect(nOffsetX, nOffsetY);

		this->SetWindowPos(NULL, rec.left, rec.top, rec.Width(), rec.Height(), SWP_HIDEWINDOW | SWP_NOZORDER);
	}

	this->GetClientRect(&rec);
	this->m_NormalSize = rec.Size();

	this->Layout();

	this->m_listQueue.ModifyStyle(0, LVS_REPORT | LVS_SHOWSELALWAYS | LVS_SINGLESEL);
	this->m_listQueue.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP);
	this->m_listQueue.LoadSave(_T("eRadQueueCall.DlgQueue.Queue"), CRunTime::GetGeneral()->m_bPrivateSaveToFile, CRunTime::GetUser()->m_strPrivateSaveToFile, REGISTER_LOCATION);

	BEGIN_LISTCOLUMNMAP(m_listQueue, 14)
		LISTCOLUMNMAP(IDS_QUEUE_CLASS,					80,			LVCFMT_LEFT,	ELCT_STRING_CASE)
		LISTCOLUMNMAP(IDS_QUEUE_NUMBER_RESET,			80,			LVCFMT_LEFT,	ELCT_INTEGER)
		LISTCOLUMNMAP(IDS_QUEUE_NUMBER,					80,			LVCFMT_LEFT,	ELCT_INTEGER)  /////
		LISTCOLUMNMAP(IDS_QUEUE_CALL_NAME,				80,			LVCFMT_LEFT,	ELCT_STRING_CASE)
		LISTCOLUMNMAP(IDS_QUEUE_STATUS,					80,			LVCFMT_LEFT,	ELCT_STRING_CASE)
		LISTCOLUMNMAP(IDS_QUEUE_PATIENTS_ALIAS,			100,		LVCFMT_LEFT,	ELCT_STRING_CASE)
		LISTCOLUMNMAP(IDS_QUEUE_ACCESSION_NUMBER,		100,		LVCFMT_LEFT,	ELCT_STRING_CASE)
		LISTCOLUMNMAP(IDS_QUEUE_EXAMINE_ALIAS,			100,		LVCFMT_LEFT,	ELCT_STRING_CASE)
		LISTCOLUMNMAP(IDS_QUEUE_BODIES_ALIAS,			100,		LVCFMT_LEFT,	ELCT_STRING_CASE)
		LISTCOLUMNMAP(IDS_QUEUE_PATIENTS_ID,			100,		LVCFMT_LEFT,	ELCT_STRING_CASE)
		LISTCOLUMNMAP(IDS_QUEUE_ADMISSION_ID,			100,		LVCFMT_LEFT,	ELCT_STRING_CASE)
		LISTCOLUMNMAP(IDS_QUEUE_DEVICE_ALIAS,			100,		LVCFMT_LEFT,	ELCT_STRING_CASE)
		LISTCOLUMNMAP(IDS_QUEUE_CALL_TS,				100,		LVCFMT_LEFT,	ELCT_STRING_CASE)
		LISTCOLUMNMAP(IDS_QUEUE_TS,						100,		LVCFMT_LEFT,	ELCT_STRING_CASE)
	END_LISTCOLUMNMAP()

	for (UINT i = 0; i < CToolsEx::GetQueueStatus()->GetSize(); i++)
	{
		LONG nIndex = this->m_cboQueueStatus.AddString(CToolsEx::GetQueueStatus()->GetValue(i));
		this->m_cboQueueStatus.SetItemData(nIndex, CToolsEx::GetQueueStatus()->GetKey(i));

	}

	this->m_cboQueueStatus.LoadSave(_T("eRadQueueCall.DlgQueue.QueueStatus"),	CRunTime::GetGeneral()->m_bPrivateSaveToFile, CRunTime::GetUser()->m_strPrivateSaveToFile, REGISTER_LOCATION);
	//this->m_cboQueueStatus.SelectAll();

	//#呼叫器名称
	if(CRunTime::GetGeneral()->m_bCallIQueueRoom)
	{
		CString strRoom = CRunTime::GetGeneral()->m_strCallRoom;
		strRoom.Replace(_T("\\\\"), _T("|"));
		strRoom.Replace(_T("\\"), _T("|"));

		LONG nStart = 0, nClose = 0;
		CString strSingle;
		while (TRUE)
		{
			nStart = strRoom.Find('|', nClose);
			if (nStart == -1)
				break;
			
			nClose = strRoom.Find('|', nStart + 1);
			if (nClose == -1)
				break;
			
			strSingle = strRoom.Mid(nStart + 1, nClose - nStart - 1);
			
			if (!strSingle.IsEmpty())
				m_aQueueRoom.Add(strSingle);
		}

		this->m_cboQueueRoom.AddString("");
		for (int nSize = 0; nSize < m_aQueueRoom.GetSize(); nSize++)
			this->m_cboQueueRoom.AddString(m_aQueueRoom.GetAt(nSize));

		//#呼叫器编号
		strRoom = CRunTime::GetGeneral()->m_strCallRoomNode;
		strRoom.Replace(_T("\\\\"), _T("|"));
		strRoom.Replace(_T("\\"), _T("|"));
		nStart = 0, nClose = 0;
		strSingle = "";

		while (TRUE)
		{
			nStart = strRoom.Find('|', nClose);
			if (nStart == -1)
				break;
			
			nClose = strRoom.Find('|', nStart + 1);
			if (nClose == -1)
				break;
			
			strSingle = strRoom.Mid(nStart + 1, nClose - nStart - 1);
			
			if (!strSingle.IsEmpty())
				m_aQueueRoomNode.Add(strSingle);
		}
	}

	//#按照门诊住院类型呼叫病人
	if(CRunTime::GetGeneral()->m_bCallQueuePatientKind)
	{
		this->m_cboQueueSetting.AddString("呼叫门诊");
		this->m_cboQueueSetting.AddString("呼叫住院");
		
		this->m_cboQueueSetting.LoadSave(_T("eRadQueueCall.DlgQueue.QueueSetting"),	CRunTime::GetGeneral()->m_bPrivateSaveToFile, CRunTime::GetUser()->m_strPrivateSaveToFile, REGISTER_LOCATION);
		this->m_cboQueueSetting.SelectAll();
	}
	//
	
	this->OnButtonRefresh();

	this->SetTimer(ID_TIMER_QUEUE_ACTIVE, 100, NULL);
	if (CRunTime::GetGeneral()->m_nAutoRefresh > 0)
		this->SetTimer(ID_TIMER_QUEUE_REFRESH, CRunTime::GetGeneral()->m_nAutoRefresh * 1000, NULL);
	else
		this->SetTimer(ID_TIMER_QUEUE_REFRESH, 180 * 1000, NULL);
	this->SetTimer(ID_TIMER_QUEUE_NORMAL_HIDE,100,NULL);                      //20110616
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgQueue::OnOK() 
{
	// TODO: Add extra validation here

//	CDialog::OnOK();
}

void CDlgQueue::OnCancel() 
{
	// TODO: Add extra cleanup here
	
//	CDialog::OnCancel();
}

void CDlgQueue::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here

	this->KillTimer(ID_TIMER_QUEUE_ACTIVE);
	this->KillTimer(ID_TIMER_QUEUE_REFRESH);

	CRect rec;
	this->GetWindowRect(&rec);

	rec.bottom = rec.top + this->m_NormalSize.cy;
	CRunTime::GetUser()->m_recDlgQueue = rec;

	CRunTime::ExchangePrivate(TRUE);
}

HBRUSH CDlgQueue::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here

	switch(nCtlColor)	
	{
	case CTLCOLOR_DLG:
	case CTLCOLOR_STATIC:
	case CTLCOLOR_BTN:
	case CTLCOLOR_MSGBOX:
	case CTLCOLOR_LISTBOX:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(COLOR_TEXT_DEFAULT);
		return CRunTime::GetGUI()->m_brushGlobal;
	}

	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CDlgQueue::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here

	if (this->m_bInitDialog)
	{
		this->Layout();

		CRect rec;
		this->GetWindowRect(&rec);
		if (rec.Width() > QUEUE_MINIMAL_WIDTH && rec.Height() > QUEUE_MINIMAL_HEIGHT)
			this->m_NormalSize = rec.Size();
	}
	
}

void CDlgQueue::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	if (nIDEvent == ID_TIMER_QUEUE_ACTIVE)
	{
		
		if (this->GetActiveWindow() != this && this->m_bShowNormal)
			this->ShowQueue();
	}
	else if (nIDEvent == ID_TIMER_QUEUE_REFRESH)
	{
		this->UpdateData();
		if (this->m_bAutoRefresh)
			this->OnButtonRefresh();
	}
	else if (nIDEvent == ID_TIMER_QUEUE_NORMAL_HIDE)   //20110616  当鼠标不在呼叫器时自动收缩
	{
		POINT pt;
		CRect rc;
		GetCursorPos(&pt);
		this->GetWindowRect(rc);
		CRect rect;
		rect.left=rc.left-INFALTE;
		rect.right=rc.right+INFALTE;
		rect.bottom=rc.bottom+INFALTE;
		rect.top=rc.top;
		if(!rect.PtInRect(pt) && this->m_bShowNormal)
			this->ShowQueue();
	}                                                 
	else if (nIDEvent == ID_TIMER_QUEUE_SHOW)         //20110616  呼叫器边框在桌面边缘时自动隐藏
	{
		POINT curPos;
		GetCursorPos(&curPos);
		CRect tRect;
		GetWindowRect(tRect);
		tRect.InflateRect(INFALTE,INFALTE);
		if(!tRect.PtInRect(curPos)) 
		{
			KillTimer(ID_TIMER_QUEUE_SHOW); 
			m_isSetTimer = FALSE;
			m_hsFinished = FALSE;
			m_hiding = TRUE;
			SetTimer(ID_TIMER_QUEUE_HIDE,HS_ELAPSE,NULL); 
		}
	}
	else (nIDEvent == ID_TIMER_QUEUE_HIDE);
	{
		if(m_hsFinished) 
			KillTimer(ID_TIMER_QUEUE_HIDE);
		else
           m_hiding ? DoHide() : DoShow();
	}                                                 //20110616  呼叫器边框在桌面边缘时自动隐藏
	
    CDialog::OnTimer(nIDEvent);
}

void CDlgQueue::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if (!this->m_bShowNormal)
		 this->ShowQueue();
   
	CDialog::OnMouseMove(nFlags, point);
}

void CDlgQueue::OnButtonCallOrder() 
{
	// TODO: Add your control notification handler code here

	MRET rc = this->CallQueueOrder(E_QUEUE_CALL_ORDER);
	if (rc != ME_OK)
	{
		LOG_ERROR(LL_ERROR | LD_ALL, rc);
	}
}

void CDlgQueue::OnButtonCallPre() 
{
	// TODO: Add your control notification handler code here
	MRET rc = this->CallQueueOrder(E_QUEUE_CALL_PRECALL);
	if (rc != ME_OK)
	{
		LOG_ERROR(LL_ERROR | LD_ALL, rc);
	}
}

void CDlgQueue::OnButtonCallCaptureReport() 
{
	// TODO: Add your control notification handler code here

	MRET rc = this->CallQueueOrder(E_QUEUE_CALL_CAPTURE_REPORT);
	if (rc != ME_OK)
	{
		LOG_ERROR(LL_ERROR | LD_ALL, rc);
	}
}

void CDlgQueue::OnButtonCallCapture() 
{
	// TODO: Add your control notification handler code here

	MRET rc = this->CallQueueOrder(E_QUEUE_CALL_CAPTURE);
	if (rc != ME_OK)
	{
		LOG_ERROR(LL_ERROR | LD_ALL, rc);
	}
}

void CDlgQueue::OnButtonCallReport() 
{
	// TODO: Add your control notification handler code here

	MRET rc = this->CallQueueOrder(E_QUEUE_CALL_REPORT);
	if (rc != ME_OK)
	{
		LOG_ERROR(LL_ERROR | LD_ALL, rc);
	}
}

void CDlgQueue::OnButtonCallRepeat() 
{
	// TODO: Add your control notification handler code here

	COleSession dbSession;
	COleSession* pSession = CRunTime::GetEISSession(&dbSession);
	if (pSession == NULL)
	{
		LOG_ERROR(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_SESSION);
		return;
	}

	LONG nCount = 0;
	if (this->m_nQueueIndexCall > 0)
	{
		CString strFilter;
		strFilter.Format(_T("SELECT COUNT(1) FROM EISQueue WHERE QueueIndex = %d"), this->m_nQueueIndexCall);
		if (FAILED(pSession->Calculate(strFilter, nCount)))
		{
			LOG_ERROR(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_TABLE);
			return;
		}
	}

	if (!(this->m_nQueueIndexCall > 0) || !(nCount == 1))
	{
		AfxMessageBox(IDS_MESSAGE_DATA_ERROR, MB_OK | MB_ICONERROR);

		this->m_nQueueIndexCall = 0;

		this->ChangeStatus();
	}
	else
	{
		MRET rc = this->CallQueue(pSession, this->m_nQueueIndexCall, EIS_QUEUE_EXAMINE);
		if (rc != ME_OK)
		{
			LOG_ERROR(LL_ERROR | LD_ALL, rc);
			return;
		}

		if (this->m_lpcbQueueCallProc != NULL)
		{
			MRET rc = this->m_lpcbQueueCallProc(this->m_nQueueIndexCall, E_QUEUE_CALL_REPEAT);
			if (rc != ME_OK)
			{
				LOG_ERROR(LL_ERROR | LD_ALL, rc);
			}
		}
	}
}

void CDlgQueue::OnButtonRefresh() 
{
	// TODO: Add your control notification handler code here

	this->UpdateData();

	CString strFilter, strBuffer;
	strFilter.Format(_T("WHERE QueueDate = %s"), DATETIME_CURRENT_DATE);

	if (!this->m_bCallAllRoom)
	{
		strBuffer.Format(_T(" AND QueueCallNode IN (0, %d)"), CRunTime::GetGeneral()->m_nCallNode);
		strFilter += strBuffer;
	}

	if (this->m_cboQueueStatus.GetSelectCount() > 0)
	{
		CString strCombined, strSingle;
		for (LONG i = 0; i < this->m_cboQueueStatus.GetCount(); i++)
		{
			if (this->m_cboQueueStatus.GetCheck(i))
			{
				if (strCombined.IsEmpty())
					strCombined.Format(_T("%d"), this->m_cboQueueStatus.GetItemData(i));
				else
				{
					strSingle.Format(_T(", %d"), this->m_cboQueueStatus.GetItemData(i));
					strCombined += strSingle;
				}
			}
		}

		strBuffer.Format(_T(" AND QueueStatus IN (%s)"), strCombined);
		strFilter += strBuffer;
	}

	if(CRunTime::GetGeneral()->m_bCallQueuePatientKind)
	{
		CString strSQL,strCombined="";
		if (this->m_cboQueueSetting.GetSelectCount() > 0)
		{
			CString strSingle;
			
			if (this->m_cboQueueSetting.GetCheck(0))
			{
				if (strCombined.IsEmpty())
					strCombined.Format(_T("%s"), CRunTime::GetGeneral()->m_strMZQueue);
				else
				{
					strSingle.Format(_T(", %s"), CRunTime::GetGeneral()->m_strMZQueue);
					strCombined += strSingle;
				}
			}
			
			if (this->m_cboQueueSetting.GetCheck(1))
			{
				if (strCombined.IsEmpty())
					strCombined.Format(_T("%s"), CRunTime::GetGeneral()->m_strZYQueue);
				else
				{
					strSingle.Format(_T(", %s"), CRunTime::GetGeneral()->m_strZYQueue);
					strCombined += strSingle;
				}
			}
			
			strSQL.Format(_T(" AND QueueDevice IN (%s)"), strCombined);
			strFilter += strSQL;
		}
	}
	else
	{
		strBuffer.Format(_T(" AND QueueDevice IN (%s)"), CRunTime::GetGeneral()->m_strCallDevice);
		strBuffer.Replace(_T("\\\\"), _T(","));
		strBuffer.Replace(_T("\\"), _T(""));
		strFilter += strBuffer;
	}

	LONG nAfternoon = 0;
	if (CRunTime::GetGeneral()->m_bAfternoon && CRunTime::GetGeneral()->m_strAfternoonTime < DATETIME_CURRENT_TIME)
		nAfternoon = 1;
	strBuffer.Format(_T(" AND QueueAfternoon = %d"), nAfternoon);
	strFilter += strBuffer;

	MRET rc = this->RefreshQueue(strFilter);
	if (rc != ME_OK)
	{
		LOG_ERROR(LL_ERROR | LD_ALL, rc);
	}
}

void CDlgQueue::OnButtonCallComplete() 
{
	// TODO: Add your control notification handler code here

	if (this->m_nQueueIndexCall > 0)
	{
		COleSession dbSession;
		COleSession* pSession = CRunTime::GetEISSession(&dbSession);
		if (pSession == NULL)
		{
			LOG_ERROR(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_SESSION);
			return;
		}

		MRET rc = this->CallQueueComplete(pSession, this->m_nQueueIndexCall);
		if (rc != ME_OK)
		{
			LOG_ERROR(LL_ERROR | LD_ALL, rc);
			return;
		}

		this->m_nQueueIndexCall = 0;

		this->ChangeStatus();
	}
}

void CDlgQueue::OnButtonCallReset() 
{
	// TODO: Add your control notification handler code here

	if (this->m_nQueueIndexCall > 0)
	{
		COleSession dbSession;
		COleSession* pSession = CRunTime::GetEISSession(&dbSession);
		if (pSession == NULL)
		{
			LOG_ERROR(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_SESSION);
			return;
		}

		MRET rc = this->CallQueueReset(pSession, this->m_nQueueIndexCall);
		if (rc != ME_OK)
		{
			LOG_ERROR(LL_ERROR | LD_ALL, rc);
			return;
		}

		this->m_nQueueIndexCall = 0;

		this->ChangeStatus();
	}
}

void CDlgQueue::OnButtonCallUnready() 
{
	// TODO: Add your control notification handler code here

	if (this->m_nQueueIndexCall > 0)
	{
		COleSession dbSession;
		COleSession* pSession = CRunTime::GetEISSession(&dbSession);
		if (pSession == NULL)
		{
			LOG_ERROR(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_SESSION);
			return;
		}

		MRET rc = this->CallQueueUnready(pSession, this->m_nQueueIndexCall);
		if (rc != ME_OK)
		{
			LOG_ERROR(LL_ERROR | LD_ALL, rc);
			return;
		}

		this->m_nQueueIndexCall = 0;

		this->ChangeStatus();
	}
}

void CDlgQueue::OnButtonCallCancel() 
{
	// TODO: Add your control notification handler code here

	if (this->m_nQueueIndexCall > 0)
	{
		COleSession dbSession;
		COleSession* pSession = CRunTime::GetEISSession(&dbSession);
		if (pSession == NULL)
		{
			LOG_ERROR(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_SESSION);
			return;
		}

		MRET rc = this->CallQueueCancel(pSession, this->m_nQueueIndexCall);
		if (rc != ME_OK)
		{
			LOG_ERROR(LL_ERROR | LD_ALL, rc);
			return;
		}

		this->m_nQueueIndexCall = 0;

		this->ChangeStatus();
	}
}

void CDlgQueue::OnClickListQueue(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	this->ChangeStatus();

	*pResult = 0;
}

void CDlgQueue::OnDblclkListQueue(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	// ???

	*pResult = 0;
}

void CDlgQueue::OnRclickListQueue(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	LONG nSelectedCount = this->m_listQueue.GetSelectedCount();

	CMenu menu;
	menu.LoadMenu(IDR_MENU_QUEUE);

	CMenu* pSubMenu = menu.GetSubMenu(0);

	if (!CRunTime::GetGeneral()->m_bCallOrder || CRunTime::GetGeneral()->m_bNoPopOrderCall)
		pSubMenu->DeleteMenu(IDM_QUEUE_CALL_SELECT,				MF_BYCOMMAND);
	else
	{
		if(!CRunTime::GetGeneral()->m_bNoPopOrderCall)
			pSubMenu->EnableMenuItem(IDM_QUEUE_CALL_SELECT,			MF_BYCOMMAND | ((nSelectedCount == 1)	? 0 : MF_GRAYED));
	}

	if (!CRunTime::GetGeneral()->m_bCallCaptureReport)
		pSubMenu->DeleteMenu(IDM_QUEUE_CALL_CAPTURE_REPORT,		MF_BYCOMMAND);
	else
		pSubMenu->EnableMenuItem(IDM_QUEUE_CALL_CAPTURE_REPORT,	MF_BYCOMMAND | ((nSelectedCount == 1)	? 0 : MF_GRAYED));

	if (!CRunTime::GetGeneral()->m_bCallCapture)
		pSubMenu->DeleteMenu(IDM_QUEUE_CALL_CAPTURE,			MF_BYCOMMAND);
	else
		pSubMenu->EnableMenuItem(IDM_QUEUE_CALL_CAPTURE,		MF_BYCOMMAND | ((nSelectedCount == 1)	? 0 : MF_GRAYED));

	if (!CRunTime::GetGeneral()->m_bCallReport)
		pSubMenu->DeleteMenu(IDM_QUEUE_CALL_REPORT,				MF_BYCOMMAND);
	else
		pSubMenu->EnableMenuItem(IDM_QUEUE_CALL_REPORT,			MF_BYCOMMAND | ((nSelectedCount == 1)	? 0 : MF_GRAYED));

	if (!CRunTime::GetGeneral()->m_bCallComplete)
		pSubMenu->DeleteMenu(IDM_QUEUE_CALL_COMPLETE,			MF_BYCOMMAND);
	else
		pSubMenu->EnableMenuItem(IDM_QUEUE_CALL_COMPLETE,		MF_BYCOMMAND | ((nSelectedCount > 0)	? 0 : MF_GRAYED));

	if (!CRunTime::GetGeneral()->m_bCallReset || CRunTime::GetGeneral()->m_bNoPopOrderCall)
		pSubMenu->DeleteMenu(IDM_QUEUE_CALL_RESET,				MF_BYCOMMAND);
	else
		pSubMenu->EnableMenuItem(IDM_QUEUE_CALL_RESET,			MF_BYCOMMAND | ((nSelectedCount > 0)	? 0 : MF_GRAYED));

	if (!CRunTime::GetGeneral()->m_bCallUnready)
		pSubMenu->DeleteMenu(IDM_QUEUE_CALL_UNREADY,			MF_BYCOMMAND);
	else
		pSubMenu->EnableMenuItem(IDM_QUEUE_CALL_UNREADY,		MF_BYCOMMAND | ((nSelectedCount > 0)	? 0 : MF_GRAYED));

	if (!CRunTime::GetGeneral()->m_bCallCancel)
		pSubMenu->DeleteMenu(IDM_QUEUE_CALL_CANCEL,				MF_BYCOMMAND);
	else
		pSubMenu->EnableMenuItem(IDM_QUEUE_CALL_CANCEL,			MF_BYCOMMAND | ((nSelectedCount > 0)	? 0 : MF_GRAYED));

	CPoint pt;
	::GetCursorPos(&pt);
	LONG nRet = pSubMenu->TrackPopupMenu(TPM_RIGHTBUTTON | TPM_RETURNCMD, pt.x, pt.y, this);

//	pSubMenu->DestroyMenu();

	switch (nRet)
	{
	case IDM_QUEUE_CALL_SELECT:
		{
			MRET rc = this->CallQueueSelect(E_QUEUE_CALL_SELECT);
			if (rc != ME_OK)
			{
				LOG_ERROR(LL_ERROR | LD_ALL, rc);
			}
		}
		break;

	case IDM_QUEUE_CALL_CAPTURE_REPORT:
		{
			MRET rc = this->CallQueueSelect(E_QUEUE_CALL_CAPTURE_REPORT);
			if (rc != ME_OK)
			{
				LOG_ERROR(LL_ERROR | LD_ALL, rc);
			}
		}
		break;

	case IDM_QUEUE_CALL_CAPTURE:
		{
			MRET rc = this->CallQueueSelect(E_QUEUE_CALL_CAPTURE);
			if (rc != ME_OK)
			{
				LOG_ERROR(LL_ERROR | LD_ALL, rc);
			}
		}
		break;

	case IDM_QUEUE_CALL_REPORT:
		{
			MRET rc = this->CallQueueSelect(E_QUEUE_CALL_REPORT);
			if (rc != ME_OK)
			{
				LOG_ERROR(LL_ERROR | LD_ALL, rc);
			}
		}
		break;

	case IDM_QUEUE_CALL_COMPLETE:
		{
			COleSession dbSession;
			COleSession* pSession = CRunTime::GetEISSession(&dbSession);
			if (pSession == NULL)
			{
				LOG_ERROR(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_SESSION);
			}
			else
			{
				LONG nIndex = -1;
				while ((nIndex = this->m_listQueue.GetNextItem(nIndex, LVNI_SELECTED)) != -1)
				{
					LONG nQueueIndex = this->m_listQueue.GetItemData(nIndex);
					if (nQueueIndex <= 0)
					{
						AfxMessageBox(IDS_MESSAGE_DATA_ERROR, MB_OK | MB_ICONERROR);
						LOG_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, nQueueIndex);
						break;
					}

					MRET rc = this->CallQueueComplete(pSession, nQueueIndex);
					if (rc != ME_OK)
					{
						LOG_ERROR(LL_ERROR | LD_ALL, rc);
						break;
					}
				}
			}

			this->m_nQueueIndexCall = 0;

			this->ChangeStatus();
		}
		break;

	case IDM_QUEUE_CALL_RESET:
		{
			COleSession dbSession;
			COleSession* pSession = CRunTime::GetEISSession(&dbSession);
			if (pSession == NULL)
			{
				LOG_ERROR(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_SESSION);
			}
			else
			{
				LONG nIndex = -1;
				while ((nIndex = this->m_listQueue.GetNextItem(nIndex, LVNI_SELECTED)) != -1)
				{
					LONG nQueueIndex = this->m_listQueue.GetItemData(nIndex);
					if (nQueueIndex <= 0)
					{
						AfxMessageBox(IDS_MESSAGE_DATA_ERROR, MB_OK | MB_ICONERROR);
						LOG_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, nQueueIndex);
						break;
					}

					MRET rc = this->CallQueueReset(pSession, nQueueIndex);
					if (rc != ME_OK)
					{
						LOG_ERROR(LL_ERROR | LD_ALL, rc);
						break;
					}
				}
			}

			this->m_nQueueIndexCall = 0;

			this->ChangeStatus();
		}
		break;

	case IDM_QUEUE_CALL_UNREADY:
		{
			COleSession dbSession;
			COleSession* pSession = CRunTime::GetEISSession(&dbSession);
			if (pSession == NULL)
			{
				LOG_ERROR(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_SESSION);
			}
			else
			{
				LONG nIndex = -1;
				while ((nIndex = this->m_listQueue.GetNextItem(nIndex, LVNI_SELECTED)) != -1)
				{
					LONG nQueueIndex = this->m_listQueue.GetItemData(nIndex);
					if (nQueueIndex <= 0)
					{
						AfxMessageBox(IDS_MESSAGE_DATA_ERROR, MB_OK | MB_ICONERROR);
						LOG_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, nQueueIndex);
						break;
					}

					MRET rc = this->CallQueueUnready(pSession, nQueueIndex);
					if (rc != ME_OK)
					{
						LOG_ERROR(LL_ERROR | LD_ALL, rc);
						break;
					}
				}
			}

			this->m_nQueueIndexCall = 0;

			this->ChangeStatus();
		}
		break;

	case IDM_QUEUE_CALL_CANCEL:
		{
			COleSession dbSession;
			COleSession* pSession = CRunTime::GetEISSession(&dbSession);
			if (pSession == NULL)
			{
				LOG_ERROR(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_SESSION);
			}
			else
			{
				LONG nIndex = -1;
				while ((nIndex = this->m_listQueue.GetNextItem(nIndex, LVNI_SELECTED)) != -1)
				{
					LONG nQueueIndex = this->m_listQueue.GetItemData(nIndex);
					if (nQueueIndex <= 0)
					{
						AfxMessageBox(IDS_MESSAGE_DATA_ERROR, MB_OK | MB_ICONERROR);
						LOG_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, nQueueIndex);
						break;
					}

					MRET rc = this->CallQueueCancel(pSession, nQueueIndex);
					if (rc != ME_OK)
					{
						LOG_ERROR(LL_ERROR | LD_ALL, rc);
						break;
					}
				}
			}

			this->m_nQueueIndexCall = 0;

			this->ChangeStatus();
		}
		break;
	}

	*pResult = 0;
}

BOOL CDlgQueue::Layout()
{
	CRect recClient, recRange, recCtrl;
	this->GetClientRect(&recClient);

	LONG nBlank = 10;
	LONG nSpace = 3;
	LONG nHCtrl = 24;
	LONG nHeight = nHCtrl + nSpace;
	LONG nWCtrl = 100;

	recRange.left = nBlank;
	recRange.top = nBlank;
	recRange.right = recClient.right - nBlank * 2 - nWCtrl;
	recRange.bottom = recClient.bottom - nBlank;
	this->GetDlgItem(IDC_LIST_QUEUE)->MoveWindow(&recRange);

	recRange.left = recClient.right - nBlank - nWCtrl;
	recRange.top = nBlank;
	recRange.right = recClient.right - nBlank;
	recRange.bottom = recRange.top + nHCtrl;

	recRange -= CSize(0, nHeight);

	if (!CRunTime::GetGeneral()->m_bCallOrder)
		this->GetDlgItem(IDC_BUTTON_CALL_ORDER)->ShowWindow(SW_HIDE);
	else
	{
		SET_MOVE_WINDOW(TRUE,	IDC_BUTTON_CALL_ORDER,			0,						nWCtrl);
	}

	if (!CRunTime::GetGeneral()->m_bCallPre)
		this->GetDlgItem(IDC_BUTTON_CALL_PRE)->ShowWindow(SW_HIDE);
	else
	{
		SET_MOVE_WINDOW(TRUE,	IDC_BUTTON_CALL_PRE,			0,						nWCtrl);
	}

	if (!CRunTime::GetGeneral()->m_bCallCaptureReport)
		this->GetDlgItem(IDC_BUTTON_CALL_CAPTURE_REPORT)->ShowWindow(SW_HIDE);
	else
	{
		SET_MOVE_WINDOW(TRUE,	IDC_BUTTON_CALL_CAPTURE_REPORT,	0,						nWCtrl);
	}

	if (!CRunTime::GetGeneral()->m_bCallCapture)
		this->GetDlgItem(IDC_BUTTON_CALL_CAPTURE)->ShowWindow(SW_HIDE);
	else
	{
		SET_MOVE_WINDOW(TRUE,	IDC_BUTTON_CALL_CAPTURE,		0,						nWCtrl);
	}

	if (!CRunTime::GetGeneral()->m_bCallReport)
		this->GetDlgItem(IDC_BUTTON_CALL_REPORT)->ShowWindow(SW_HIDE);
	else
	{
		SET_MOVE_WINDOW(TRUE,	IDC_BUTTON_CALL_REPORT,			0,						nWCtrl);
	}

	SET_MOVE_WINDOW(TRUE,	IDC_BUTTON_CALL_REPEAT,				0,						nWCtrl);
    
	recRange += CPoint(0, 20);

	SET_MOVE_WINDOW(TRUE,	IDC_BUTTON_REFRESH,					0,						nWCtrl);
	
	SET_MOVE_WINDOW(TRUE,	IDC_CHECK_AUTO_REFRESH,				0,						nWCtrl);

	if (!CRunTime::GetGeneral()->m_bCallWait)
		this->GetDlgItem(IDC_CHECK_CALL_WAIT)->ShowWindow(SW_HIDE);
	else
	{
		SET_MOVE_WINDOW(TRUE,	IDC_CHECK_CALL_WAIT,			0,						nWCtrl);
	}

	SET_MOVE_WINDOW(TRUE,	IDC_CHECK_CALL_ALL_ROOM,			0,						nWCtrl);
	SET_MOVE_WINDOW(TRUE,	IDC_COMBO_QUEUE_STATUS,				0,						nWCtrl);

	recRange += CPoint(0, 5);

	if (!CRunTime::GetGeneral()->m_bCallQueuePatientKind)
		this->GetDlgItem(IDC_COMBO_QUEUE_SETTING)->ShowWindow(SW_HIDE);
	else
	{
		SET_MOVE_WINDOW(TRUE,	IDC_COMBO_QUEUE_SETTING,		0,						nWCtrl);
	}

	recRange += CPoint(0, 5);
	
	if (!CRunTime::GetGeneral()->m_bCallIQueueRoom)
		this->GetDlgItem(IDC_COMBO_QUEUE_ROOM)->ShowWindow(SW_HIDE);
	else
	{
		SET_MOVE_WINDOW(TRUE,	IDC_COMBO_QUEUE_ROOM,			    0,					    nWCtrl);
	}

	recRange += CPoint(0, 20);

	if (!CRunTime::GetGeneral()->m_bCallComplete)
		this->GetDlgItem(IDC_BUTTON_CALL_COMPLETE)->ShowWindow(SW_HIDE);
	else
	{
		SET_MOVE_WINDOW(TRUE,	IDC_BUTTON_CALL_COMPLETE,		0,						nWCtrl);
	}

	if (!CRunTime::GetGeneral()->m_bCallReset)
		this->GetDlgItem(IDC_BUTTON_CALL_RESET)->ShowWindow(SW_HIDE);
	else
	{
		SET_MOVE_WINDOW(TRUE,	IDC_BUTTON_CALL_RESET,			0,						nWCtrl);
	}

	if (!CRunTime::GetGeneral()->m_bCallUnready)
		this->GetDlgItem(IDC_BUTTON_CALL_UNREADY)->ShowWindow(SW_HIDE);
	else
	{
		SET_MOVE_WINDOW(TRUE,	IDC_BUTTON_CALL_UNREADY,		0,						nWCtrl);
	}

	if (!CRunTime::GetGeneral()->m_bCallCancel)
		this->GetDlgItem(IDC_BUTTON_CALL_CANCEL)->ShowWindow(SW_HIDE);
	else
	{
		SET_MOVE_WINDOW(TRUE,	IDC_BUTTON_CALL_CANCEL,			0,						nWCtrl);
	}
    
	return TRUE;
}

BOOL CDlgQueue::ChangeStatus()
{
	this->GetDlgItem(IDC_BUTTON_CALL_REPEAT)	->EnableWindow(this->m_nQueueIndexCall > 0);
	this->GetDlgItem(IDC_BUTTON_CALL_COMPLETE)	->EnableWindow(this->m_nQueueIndexCall > 0);
	this->GetDlgItem(IDC_BUTTON_CALL_UNREADY)	->EnableWindow(this->m_nQueueIndexCall > 0);
	this->GetDlgItem(IDC_BUTTON_CALL_RESET)		->EnableWindow(this->m_nQueueIndexCall > 0);
	this->GetDlgItem(IDC_BUTTON_CALL_CANCEL)	->EnableWindow(this->m_nQueueIndexCall > 0);

	return TRUE;
}

BOOL CDlgQueue::ShowQueue(BOOL bShowNormal)
{
	if (bShowNormal || !this->m_bShowNormal)
	{
		this->m_bShowNormal = TRUE;
		this->SetWindowPos(&wndTop, 0, 0, this->m_NormalSize.cx, this->m_NormalSize.cy, SWP_SHOWWINDOW | SWP_NOMOVE);
        this->OnButtonRefresh();

		this->m_bFirstRun = FALSE;
	}
	else
	{
		this->m_bShowNormal = FALSE;
		this->SetWindowPos(&wndTop, 0, 0, this->m_NormalSize.cx, QUEUE_SHRINK_HEIGHT, SWP_SHOWWINDOW | SWP_NOACTIVATE| SWP_NOMOVE);

		if(!m_bFirstRun)
		{
			HWND msnHwnd = ::FindWindow(0, _T("eRadMedical"));
			if(msnHwnd != NULL)
				::PostMessage(msnHwnd,WM_MEDICALREFRESH,TRUE,0);
			DWORD i = GetLastError();
		}
	}

	return ME_OK;
}

MRET CDlgQueue::CallQueue(COleSession* pSession, LONG nQueueIndex, LONG nQueueStatus)
{
	if (FAILED(pSession->StartTransaction()))
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_START_TRANSACTION);
	}

	CString strFilter;
	if(m_nQueueCallRoom > 0)
		strFilter.Format(_T("UPDATE EISQueue SET QueueStatus = %d, QueueCallNode = %d, QueueCallName = '%s', QueueCallTS = '%s' WHERE QueueIndex = %d"), nQueueStatus, atoi(m_aQueueRoomNode.GetAt(m_nQueueCallRoom - 1)), m_aQueueRoom.GetAt(m_nQueueCallRoom - 1), DATETIME_CURRENT_DATETIME, nQueueIndex);
	else
		strFilter.Format(_T("UPDATE EISQueue SET QueueStatus = %d, QueueCallNode = %d, QueueCallName = '%s', QueueCallTS = '%s' WHERE QueueIndex = %d"), nQueueStatus, CRunTime::GetGeneral()->m_nCallNode, CRunTime::GetGeneral()->m_strCallName, DATETIME_CURRENT_DATETIME, nQueueIndex);
	if (FAILED(pSession->Execute(strFilter)))
	{
		pSession->Abort();
		LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_DB_UPDATE, strFilter);
	}

	CdboEISQueueCall dboQueueCall;
	dboQueueCall.SetDataSource(pSession);

	strFilter.Format(_T("WHERE 1=2"));
	if (FAILED(dboQueueCall.Open(strFilter)))
	{
		pSession->Abort();
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE);
	}

	for (LONG i = 0; i < this->m_aQueueConsole.GetSize(); i++)
	{
		LONG nCallIndex = 0;
		if (FAILED(pSession->GetControlIndex(IX_EIS_QUEUE_CALL, nCallIndex)))
		{
			pSession->Abort();
			dboQueueCall.Close();
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE);
		}

		dboQueueCall.ClearRecord();

		dboQueueCall.m_CallIndex						= nCallIndex;
		dboQueueCall.m_CallQueue						= nQueueIndex;
		dboQueueCall.m_CallConsole						= atoi(this->m_aQueueConsole.ElementAt(i));
		dboQueueCall.m_CallNode							= CRunTime::GetGeneral()->m_nCallNode;
		FILL_STRING_FIELD(dboQueueCall.m_CallName,		CRunTime::GetGeneral()->m_strCallName);
		FILL_STRING_FIELD(dboQueueCall.m_CallTS,		DATETIME_CURRENT_DATETIME);

		if (FAILED(dboQueueCall.Insert()))
		{
			pSession->Abort();
			dboQueueCall.Close();
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_INSERT);
		}
	}

	dboQueueCall.Close();

	if (FAILED(pSession->Commit(_T("CALL"))))
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_COMMIT_TRANSACTION);
	}

	return ME_OK;
}

MRET CDlgQueue::CallQueueOrder(LONG nQueueCallAction)
{
	this->UpdateData();

	CString strCombined = "";
	if(CRunTime::GetGeneral()->m_bCallQueuePatientKind)
	{
		if (this->m_cboQueueSetting.GetSelectCount() > 0)
		{
			CString strSingle;
			if (this->m_cboQueueSetting.GetCheck(0))
			{
				if (strCombined.IsEmpty())
					strCombined.Format(_T("%s"), CRunTime::GetGeneral()->m_strMZQueue);
				else
				{
					strSingle.Format(_T(", %s"), CRunTime::GetGeneral()->m_strMZQueue);
					strCombined += strSingle;
				}
			}
			
			if (this->m_cboQueueSetting.GetCheck(1))
			{
				if (strCombined.IsEmpty())
					strCombined.Format(_T("%s"), CRunTime::GetGeneral()->m_strZYQueue);
				else
				{
					strSingle.Format(_T(", %s"), CRunTime::GetGeneral()->m_strZYQueue);
					strCombined += strSingle;
				}
			}
		}
	}

	LONG nAfternoon = 0;
	if (CRunTime::GetGeneral()->m_bAfternoon && CRunTime::GetGeneral()->m_strAfternoonTime < DATETIME_CURRENT_TIME)
		nAfternoon = 1;

	COleSession dbSession;
	COleSession* pSession = CRunTime::GetEISSession(&dbSession);
	if (pSession == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_SESSION);
	}

	CdboEISQueue dboQueue;
	dboQueue.SetDataSource(pSession);

	LONG nQueueIndexCall = 0, nQueueIndexWait = 0;

	CString strFilter, strBuffer;
	if (!CRunTime::GetGeneral()->m_bCallPriority)
	{
		strBuffer = CRunTime::GetGeneral()->m_strCallDevice;
		strBuffer.Replace(_T("\\\\"), _T(","));
		strBuffer.Replace(_T("\\"), _T(""));

		if (!strCombined.IsEmpty())
			strBuffer = strCombined;

		if(m_nQueueCallRoom > 0)
			strFilter.Format(_T("WHERE QueueDevice IN (%s) AND QueueDate = %s AND QueueAfternoon = %d AND QueueStatus IN (%d, %d) AND QueueCallNode IN (0, %d) ORDER BY QueueStatus DESC, QueueEmergent DESC, QueueNumberReset, QueueNumber"), strBuffer, DATETIME_CURRENT_DATE, nAfternoon, EIS_QUEUE_WAIT, EIS_QUEUE_ADVANCE, atoi(m_aQueueRoomNode.GetAt(m_nQueueCallRoom - 1)));
		else
			strFilter.Format(_T("WHERE QueueDevice IN (%s) AND QueueDate = %s AND QueueAfternoon = %d AND QueueStatus IN (%d, %d) AND QueueCallNode IN (0, %d) ORDER BY QueueStatus DESC, QueueEmergent DESC, QueueNumberReset, QueueNumber"), strBuffer, DATETIME_CURRENT_DATE, nAfternoon, EIS_QUEUE_WAIT, EIS_QUEUE_ADVANCE, CRunTime::GetGeneral()->m_nCallNode);
		if (FAILED(dboQueue.Open(strFilter)))
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE);
		}

		while (dboQueue.MoveNext() == S_OK)
		{
			if (nQueueIndexCall == 0)
			{
				nQueueIndexCall = dboQueue.m_QueueIndex;
				if (!this->m_bCallWait)
					break;
				else
					continue;
			}
			
			nQueueIndexWait = dboQueue.m_QueueIndex;
			break;
		}

		dboQueue.Close();
	}
	else
	{
		strBuffer = CRunTime::GetGeneral()->m_strCallDevice;
		strBuffer.Replace(_T("\\\\"), _T(","));
		strBuffer.Replace(_T("\\"), _T(""));

		if (!strCombined.IsEmpty())
			strBuffer = strCombined;

		strFilter.Format(_T("WHERE QueueDevice IN (%s) AND QueueDate = %s AND QueueAfternoon = %d AND QueueStatus = %d AND QueueCallNode = %d"), strBuffer, DATETIME_CURRENT_DATE, nAfternoon, EIS_QUEUE_ADVANCE, CRunTime::GetGeneral()->m_nCallNode);
		if (FAILED(dboQueue.Open(strFilter)))
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE);
		}

		while (dboQueue.MoveNext() == S_OK)
		{
			if (nQueueIndexCall == 0)
			{
				nQueueIndexCall = dboQueue.m_QueueIndex;
				if (!this->m_bCallWait)
					break;
				else
					continue;
			}
			
			nQueueIndexWait = dboQueue.m_QueueIndex;
			break;
		}

		dboQueue.Close();

		if (nQueueIndexCall == 0 || (nQueueIndexWait == 0 && this->m_bCallWait))
		{
			for (LONG i = 0; i < this->m_aQueueDevice.GetSize(); i++)
			{
				strFilter.Format(_T("WHERE QueueDevice = %s AND QueueDate = %s AND QueueAfternoon = %d AND QueueStatus = %d AND QueueCallNode IN (0, %d) ORDER BY QueueEmergent DESC, QueueNumberReset, QueueNumber"), this->m_aQueueDevice.ElementAt(i), DATETIME_CURRENT_DATE, nAfternoon, EIS_QUEUE_WAIT, CRunTime::GetGeneral()->m_nCallNode);
				if (FAILED(dboQueue.Open(strFilter)))
				{
					LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE);
				}

				while (dboQueue.MoveNext() == S_OK)
				{
					if (nQueueIndexCall == 0)
					{
						nQueueIndexCall = dboQueue.m_QueueIndex;
						if (!this->m_bCallWait)
							break;
						else
							continue;
					}
					
					nQueueIndexWait = dboQueue.m_QueueIndex;
					break;
				}

				dboQueue.Close();

				if (nQueueIndexCall != 0 && (nQueueIndexWait != 0 || !this->m_bCallWait))
					break;
			}
		}
	}

	if (nQueueIndexCall == 0)
	{
		AfxMessageBox(IDS_MESSAGE_QUEUE_EMPTY, MB_OK | MB_ICONINFORMATION);

		this->m_nQueueIndexCall = 0;

		this->ChangeStatus();
	}
	else
	{
		if(!CRunTime::GetGeneral()->m_bCallPre || (nQueueCallAction != E_QUEUE_CALL_PRECALL))   //预呼按钮
		{
			MRET rc = this->CallQueue(pSession, nQueueIndexCall, EIS_QUEUE_EXAMINE);
			if (rc != ME_OK)
			{
				LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
			}

			this->m_nQueueIndexCall = nQueueIndexCall;

			this->ChangeStatus();
			if (this->m_lpcbQueueCallProc != NULL)       //20110724
			{
				if(CRunTime::GetGeneral()->m_bCallOrderNoReport==TRUE)
				{
					switch (nQueueCallAction)
					{
						case E_QUEUE_CALL_CAPTURE:
						case E_QUEUE_CALL_CAPTURE_REPORT:
						case E_QUEUE_CALL_REPORT:
						{
							MRET rc = this->m_lpcbQueueCallProc(this->m_nQueueIndexCall, nQueueCallAction);
							if (rc != ME_OK)
							{
								LOG_ERROR(LL_ERROR | LD_ALL, rc);
							}
						}
						break;
						case E_QUEUE_CALL_ORDER:
						break;
					}
				
				}
				else
				{
					MRET rc = this->m_lpcbQueueCallProc(this->m_nQueueIndexCall, nQueueCallAction);
					if (rc != ME_OK)
					{
						LOG_ERROR(LL_ERROR | LD_ALL, rc);
					}
					
				}
			}     //20110724
		}
		else
		{
			MRET rc = this->CallQueue(pSession, nQueueIndexCall, EIS_QUEUE_ADVANCE);
			if (rc != ME_OK)
			{
				LOG_ERROR(LL_ERROR | LD_FILE, rc);
			}
			
		}
	}

	if (nQueueIndexWait != 0 && !CRunTime::GetGeneral()->m_bCallPre)
	{
		MRET rc = this->CallQueue(pSession, nQueueIndexWait, EIS_QUEUE_ADVANCE);
		if (rc != ME_OK)
		{
			LOG_ERROR(LL_ERROR | LD_FILE, rc);
		}
	}

	return ME_OK;
}

MRET CDlgQueue::CallQueueSelect(LONG nQueueCallAction)
{
	if (this->m_listQueue.GetSelectedCount() == 1)
	{
		LONG nIndex = this->m_listQueue.GetNextItem(-1, LVNI_SELECTED);
		if (nIndex != -1)
		{
			LONG nQueueIndex = this->m_listQueue.GetItemData(nIndex);

			COleSession dbSession;
			COleSession* pSession = CRunTime::GetEISSession(&dbSession);
			if (pSession == NULL)
			{
				LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_SESSION);
			}

			LONG nCount = 0;
			if (nQueueIndex > 0)
			{
				CString strFilter;
				strFilter.Format(_T("SELECT COUNT(1) FROM EISQueue WHERE QueueIndex = %d"), nQueueIndex);
				if (FAILED(pSession->Calculate(strFilter, nCount)))
				{
					LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE);
				}
			}

			if (!(nQueueIndex > 0) || !(nCount == 1))
			{
				AfxMessageBox(IDS_MESSAGE_DATA_ERROR, MB_OK | MB_ICONERROR);

				this->m_nQueueIndexCall = 0;

				this->ChangeStatus();
			}
			else
			{
				if(!CRunTime::GetGeneral()->m_bNoPopOrderCall || (nQueueCallAction != E_QUEUE_CALL_CAPTURE_REPORT)) //右键点采集报告不呼叫
				{
					MRET rc = this->CallQueue(pSession, nQueueIndex, EIS_QUEUE_EXAMINE);
					if (rc != ME_OK)
					{
						LOG_RET_ERROR(LL_ERROR | LD_FILE, rc);
					}
				}

				this->m_nQueueIndexCall = nQueueIndex;

				this->ChangeStatus();

				if (this->m_lpcbQueueCallProc != NULL)
				{
					if(CRunTime::GetGeneral()->m_bCallOrderNoReport==TRUE)   //20110725
					{
						switch (nQueueCallAction)
						{
						case E_QUEUE_CALL_SELECT:
						case E_QUEUE_CALL_CAPTURE:
						case E_QUEUE_CALL_CAPTURE_REPORT:
				        case E_QUEUE_CALL_REPORT:
						     break;
						}
						
					}
					else
					{
                        MRET rc = this->m_lpcbQueueCallProc(this->m_nQueueIndexCall, nQueueCallAction);
					    if (rc != ME_OK)
						{
						    LOG_ERROR(LL_ERROR | LD_ALL, rc);
						}
					}       //20110725
				}
			}
		}
	}

	return ME_OK;
}

MRET CDlgQueue::CallQueueComplete(COleSession* pSession, LONG nQueueIndex)
{
	CString strFilter;
	strFilter.Format(_T("UPDATE EISQueue SET QueueStatus = %d WHERE QueueIndex = %d"), EIS_QUEUE_COMPLETE, nQueueIndex);
	if (FAILED(pSession->Execute(strFilter)))
	{
		LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_DB_UPDATE, strFilter);
	}

	if (this->m_lpcbQueueCallProc != NULL)
	{
		MRET rc = this->m_lpcbQueueCallProc(nQueueIndex, E_QUEUE_CALL_COMPLETE);
		if (rc != ME_OK)
		{
			LOG_ERROR(LL_ERROR | LD_FILE, rc);
		}
	}

	return ME_OK;
}

MRET CDlgQueue::CallQueueReset(COleSession* pSession, LONG nQueueIndex)
{
	CString strFilter;
	strFilter.Format(_T("UPDATE EISQueue SET QueueStatus = %d, QueueNumberReset = QueueNumberReset + %d WHERE QueueIndex = %d"), EIS_QUEUE_WAIT, CRunTime::GetGeneral()->m_nCallIncrement, nQueueIndex);
	if (FAILED(pSession->Execute(strFilter)))
	{
		LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_DB_UPDATE, strFilter);
	}

	if (this->m_lpcbQueueCallProc != NULL)
	{
		MRET rc = this->m_lpcbQueueCallProc(nQueueIndex, E_QUEUE_CALL_RESET);
		if (rc != ME_OK)
		{
			LOG_ERROR(LL_ERROR | LD_FILE, rc);
		}
	}

	return ME_OK;
}

MRET CDlgQueue::CallQueueUnready(COleSession* pSession, LONG nQueueIndex)
{
	CString strFilter;
	strFilter.Format(_T("UPDATE EISQueue SET QueueStatus = %d, QueueCallNode = 0, QueueCallName = '' WHERE QueueIndex = %d"), EIS_QUEUE_UNREADY, nQueueIndex);
	if (FAILED(pSession->Execute(strFilter)))
	{
		LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_DB_UPDATE, strFilter);
	}

	if (this->m_lpcbQueueCallProc != NULL)
	{
		MRET rc = this->m_lpcbQueueCallProc(nQueueIndex, E_QUEUE_CALL_UNREADY);
		if (rc != ME_OK)
		{
			LOG_ERROR(LL_ERROR | LD_FILE, rc);
		}
	}

	return ME_OK;
}

MRET CDlgQueue::CallQueueCancel(COleSession* pSession, LONG nQueueIndex)
{
	CString strFilter;
	strFilter.Format(_T("UPDATE EISQueue SET QueueStatus = %d, QueueCallNode = 0, QueueCallName = '' WHERE QueueIndex = %d"), EIS_QUEUE_CANCEL, nQueueIndex);
	if (FAILED(pSession->Execute(strFilter)))
	{
		LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_DB_UPDATE, strFilter);
	}

	if (this->m_lpcbQueueCallProc != NULL)
	{
		MRET rc = this->m_lpcbQueueCallProc(nQueueIndex, E_QUEUE_CALL_CANCEL);
		if (rc != ME_OK)
		{
			LOG_ERROR(LL_ERROR | LD_FILE, rc);
		}
	}

	return ME_OK;
}

MRET CDlgQueue::RefreshQueue(CString strFilter)
{
	this->m_listQueue.DeleteAllItems();

	this->ChangeStatus();

	COleSession dbSession;
	COleSession* pSession = CRunTime::GetEISSession(&dbSession);
	if (pSession == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_SESSION);
	}

	CdboEISQueue dboQueue;
	dboQueue.SetDataSource(pSession);
	if (FAILED(dboQueue.Open(strFilter)))
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE);
	}

	LONG nIndex = 0;
	while (dboQueue.MoveNext() == S_OK)
	{
		nIndex = this->m_listQueue.InsertItem(nIndex + 1, _T(""));

		this->RefreshQueue(nIndex, dboQueue);
	}

	dboQueue.Close();

	this->m_listQueue.SortListCtrl();

	CString strBuffer;
	strBuffer.Format(_T("%s ( %d )"), this->m_strTitle, this->m_listQueue.GetItemCount());
	this->SetWindowText(strBuffer);

	return ME_OK;
}

MRET CDlgQueue::RefreshQueue(LONG nIndex, CdboEISQueue& dboQueue)
{
	CString strBuffer, strTS;

	LONG i = 0;

	if (dboQueue.m_QueueEmergent == EIS_QUEUE_EMERGENT)
		strBuffer = TXT_QUEUE_CLASS_EMERGENT;
	else if (dboQueue.m_QueueEmergent == EIS_QUEUE_EXCEPTIVE)
		strBuffer = TXT_QUEUE_CLASS_EXCEPTIVE;
	else if (dboQueue.m_QueuePrearrange)
		strBuffer = TXT_QUEUE_CLASS_PREARRANGE;
	else
		strBuffer = _T("");

	this->m_listQueue.SetItemText(nIndex, i++, strBuffer);
	this->m_listQueue.SetItemText(nIndex, i++, dboQueue.m_QueueNumberReset);
	this->m_listQueue.SetItemText(nIndex, i++, dboQueue.m_QueueNumberExtension);   /////
	this->m_listQueue.SetItemText(nIndex, i++, dboQueue.m_QueueCallName);
	this->m_listQueue.SetItemText(nIndex, i++, CToolsEx::GetQueueStatus()->FindValue(dboQueue.m_QueueStatus));
	
	if ( 50 == dboQueue.m_QueueStatus)//20110418 待检状态背景色
	{
		COLORREF col = RGB(255,0,0);
	    this->m_listQueue.AddColorScheme("待检",col);
	}
	if ( 0 == dboQueue.m_QueueStatus)
	{
		COLORREF col = RGB(0,255,0);
		this->m_listQueue.AddColorScheme("等候",col);
	}                                //20110418 待检状态背景色
	
	
	this->m_listQueue.SetItemText(nIndex, i++, dboQueue.m_PatientsAlias);
	this->m_listQueue.SetItemText(nIndex, i++, dboQueue.m_AccessionNumber);
	this->m_listQueue.SetItemText(nIndex, i++, dboQueue.m_ExamineAlias);
	this->m_listQueue.SetItemText(nIndex, i++, dboQueue.m_BodiesAlias);
	this->m_listQueue.SetItemText(nIndex, i++, dboQueue.m_PatientsID);
	this->m_listQueue.SetItemText(nIndex, i++, dboQueue.m_AdmissionID);
	this->m_listQueue.SetItemText(nIndex, i++, dboQueue.m_QueueDeviceAlias);

	strTS = dboQueue.m_QueueCallTS;
	if (!strTS.IsEmpty()) strTS = strTS.Mid(8);
	this->m_listQueue.SetItemText(nIndex, i++, CToolsEx::GetDateTimeTXT(strBuffer, strTS));

	strTS = dboQueue.m_QueueTS;
	if (!strTS.IsEmpty()) strTS = strTS.Mid(8);
	this->m_listQueue.SetItemText(nIndex, i++, CToolsEx::GetDateTimeTXT(strBuffer, strTS));

	this->m_listQueue.SetItemData(nIndex, dboQueue.m_QueueIndex);

	return ME_OK;
}

MRET CDlgQueue::SetQueueCallProc(CALLBACK_QUEUE_CALL_PROC lpcbQueueCallProc)
{
	this->m_lpcbQueueCallProc = lpcbQueueCallProc;

	return ME_OK;
}

MRET CDlgQueue::StartQueueCall(LONG nDoctorIndex, LONG nDoctorDepartment, LONG nDoctorPrivilege, CString strDoctorCode, CString strDoctorName)
{
	char lpModule[_MAX_PATH];
	::GetModuleFileName(NULL, lpModule, sizeof(lpModule));

	char lpDrive[_MAX_PATH], lpDir[_MAX_PATH];
	::_splitpath(lpModule, lpDrive, lpDir, NULL, NULL);

	strcat(lpDrive, lpDir);
	::SetCurrentDirectory(lpDrive);
	
	CLOG::SetParameter(CRunTime::GetLogLevel());

	CRunTime::GetUser()->m_nDoctorIndex			= nDoctorIndex;
	CRunTime::GetUser()->m_nDoctorDepartment	= nDoctorDepartment;
	CRunTime::GetUser()->m_nDoctorPrivilege		= nDoctorPrivilege;
	CRunTime::GetUser()->m_strDoctorCode		= strDoctorCode;
	CRunTime::GetUser()->m_strDoctorName		= strDoctorName;

	CRunTime::GetUser()->m_strPrivateSaveToFile.Format(_T("%sINI\\eRadQueueCall.%s.ini"), lpDrive, CRunTime::GetUser()->m_strDoctorCode);
	if (CRunTime::GetGeneral()->m_bPrivateSaveToFile)
	{
		FILE* file = fopen(CRunTime::GetUser()->m_strPrivateSaveToFile, _T("a"));
		if (file != NULL)
			fclose(file);
		else
		{
			LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_OPEN_FILE, ::GetLastError(), CRunTime::GetUser()->m_strPrivateSaveToFile);
		}
	}

	BOOL bSuccess = CRunTime::ExchangePrivate();
	if (!bSuccess)
	{
		LOG_RET_ERROR(LL_ERROR | LD_ALL, ME_ERR_CONFIGURATION);
	}

	bSuccess = CRunTime::ExchangePublic();
	if (!bSuccess)
	{
		LOG_RET_ERROR(LL_ERROR | LD_ALL, ME_ERR_CONFIGURATION);
	}

	CToolsEx::GetMultiValue(&this->m_aQueueDevice, CRunTime::GetGeneral()->m_strCallDevice);
	CToolsEx::GetMultiValue(&this->m_aQueueConsole, CRunTime::GetGeneral()->m_strCallConsole);

	this->m_bCallWait = CRunTime::GetGeneral()->m_bCallWait;

	this->Create(CDlgQueue::IDD, NULL);

	this->ShowQueue();

	return ME_OK;
}

MRET CDlgQueue::CloseQueueCall()
{
	this->DestroyWindow();

	return ME_OK;
}

UINT CDlgQueue::OnNcHitTest(CPoint point)          //20110616  呼叫器边框在桌面边缘时自动隐藏
{
	// TODO: Add your message handler code here and/or call default
	if(m_hideMode != HM_NONE && !m_isSetTimer &&
		point.x < GetSystemMetrics(SM_CXSCREEN) + INFALTE)
	{ 
		SetTimer(ID_TIMER_QUEUE_SHOW,CM_ELAPSE,NULL);
		m_isSetTimer = TRUE;
		m_hsFinished = FALSE;
		m_hiding = FALSE;
		SetTimer(ID_TIMER_QUEUE_HIDE,HS_ELAPSE,NULL); 
	}
	return CDialog::OnNcHitTest(point);
}

void CDlgQueue::DoHide()                          //20110616  呼叫器边框在桌面边缘时自动隐藏
{
	if(m_hideMode == HM_NONE)
		return;
	
	CRect tRect;
	GetWindowRect(tRect);
	
	INT height = tRect.Height();
	INT width = tRect.Width();
	INT steps = 0;
	
	if(m_hideMode == HM_TOP)
	{
        steps = height/HS_STEPS;
		tRect.bottom -= steps;
		if(tRect.bottom <= m_edgeWidth)
		{ 
			tRect.bottom = m_edgeWidth;
			m_hsFinished = TRUE; 
		}
		tRect.top = tRect.bottom - height;
	}
	
    this->SetWindowPos(&wndTop,tRect.left, tRect.top,tRect.right - tRect.left, tRect.bottom - tRect.top, NULL);

}

void CDlgQueue::DoShow()                        //20110616  呼叫器边框在桌面边缘时自动隐藏
{
	if(m_hideMode == HM_NONE)
		return;
	
	CRect tRect;
	GetWindowRect(tRect);
	INT height = tRect.Height();
	INT width = tRect.Width();
	INT steps = 0;
	
    if(m_hideMode==HM_TOP)
	{
        steps = height/HS_STEPS;
		tRect.top += steps;
		if(tRect.top >= -m_edgeHeight)
		{ 
			tRect.top = -m_edgeHeight;
			m_hsFinished = TRUE; 
		}
		tRect.bottom = tRect.top + height;
	}
    this->SetWindowPos(&wndTop,tRect.left, tRect.top,tRect.right - tRect.left, tRect.bottom - tRect.top, NULL);
}

void CDlgQueue::FixMoving(UINT fwSide, LPRECT pRect)     //20110616  呼叫器边框在桌面边缘时自动隐藏
{
	POINT curPos;
	GetCursorPos(&curPos);
	INT screenHeight = GetSystemMetrics(SM_CYSCREEN);
	INT screenWidth = GetSystemMetrics(SM_CXSCREEN);
	INT height = pRect->bottom - pRect->top;
	INT width = pRect->right - pRect->left;
	
	if (curPos.y <= INTERVAL)
	{ 
		pRect->bottom = height - m_edgeHeight;
		pRect->top = -m_edgeHeight;
		m_hideMode = HM_TOP;
	}
	else
	{ 
		if(m_isSizeChanged)
		{ 
			pRect->bottom = pRect->top + QUEUE_SHRINK_HEIGHT;
			m_isSizeChanged = FALSE;
		}
		if(m_isSetTimer)
		{ 
			if(KillTimer(ID_TIMER_QUEUE_SHOW) == 1)
				m_isSetTimer = FALSE;
		}
		m_hideMode = HM_NONE;
	}

}

void CDlgQueue::OnMoving(UINT fwSide, LPRECT pRect)     //20110616  呼叫器边框在桌面边缘时自动隐藏
{
	CDialog::OnMoving(fwSide, pRect);
	
	// TODO: Add your message handler code here
	FixMoving(fwSide,pRect);
}

int CDlgQueue::OnCreate(LPCREATESTRUCT lpCreateStruct)  //20110616  呼叫器边框在桌面边缘时自动隐藏
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_edgeHeight = GetSystemMetrics(SM_CYEDGE);  //以相素值为单位的3D边框的高度
	m_edgeWidth  = GetSystemMetrics(SM_CXFRAME); //围绕可改变大小的窗口的边框的厚度
	return 0;
}

MRET CDlgQueue::QueueCallComplete(LONG nStudiesIndex)
{
	COleSession dbSession;
	COleSession* pSession = CRunTime::GetEISSession(&dbSession);
	if (pSession == NULL)
	{
		LOG_ERROR(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_SESSION);
		return 0;
	}
	
	CdboEISQueue dboQueue;
	dboQueue.SetDataSource(pSession);
	
	LONG nQueueIndex;
	CString strFilter;
	strFilter.Format(_T("WHERE QueueStudies= %d"), nStudiesIndex);
	if (FAILED(dboQueue.Open(strFilter)))
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE);
	}
	while (dboQueue.MoveNext() == S_OK)
	{
		nQueueIndex = dboQueue.m_QueueIndex;
	}
	dboQueue.Close();

	
	CdboEISStudies dboStudy;
	dboStudy.SetDataSource(pSession);
	
	CString strAllExamineName;
	strFilter.Format(_T("WHERE StudiesIndex= %d"), nStudiesIndex);
	if (FAILED(dboStudy.Open(strFilter)))
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE);
	}
	while (dboStudy.MoveNext() == S_OK)
	{
		strAllExamineName = dboStudy.m_StudiesExamineAlias;
	}
	dboStudy.Close();

	
	CdboEISResults dboResults;
	dboResults.SetDataSource(pSession);
	
	CString strMultiExamineName = _T("");
	strFilter.Format(_T("WHERE ResultsStudies= %d and ResultsDate <> ''"), nStudiesIndex);
	//	strFilter.Format(_T("WHERE ResultsStudies= %d and ResultsDate is not NULL"), nQueueIndex);
	if (FAILED(dboResults.Open(strFilter)))
	{
		LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE);
	}
	while (dboResults.MoveNext() == S_OK)
	{
		CString strExamineName = _T("");
		
		strExamineName = dboResults.m_ResultsExamineAlias;
		
		if (!strMultiExamineName.IsEmpty())
			strMultiExamineName += ",";
		strMultiExamineName += strExamineName;
	}
	dboResults.Close();

	
	int n, s=0, ntime=0;
	while((n = strAllExamineName.Find(",",s)) != -1) s=n+1, ntime++;
	
	int m, k=0, nCount=0;
	while((m = strMultiExamineName.Find(",",k)) != -1) k=m+1, nCount++;
	
	if(nCount == ntime)
	{
		MRET rc = this->CallQueueComplete(pSession, nQueueIndex);
		if (rc != ME_OK)
		{
			LOG_ERROR(LL_ERROR | LD_ALL, rc);
			return FALSE;
		}
	}
	else
	{
		MRET rc = this->CallQueueUnready(pSession, nQueueIndex);
		if (rc != ME_OK)
		{
			LOG_ERROR(LL_ERROR | LD_ALL, rc);
			return FALSE;
		}
	}
				
	this->ChangeStatus();
	return ME_OK;
}

