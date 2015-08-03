// PageController.cpp : implementation file
//

#include "stdafx.h"
#include "eRadSetQueueController.h"
#include "PageController.h"
#include "PageSingleQueueShowAll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageController property page

IMPLEMENT_DYNCREATE(CPageController, CPropertyPage)

CPageController::CPageController() : CPropertyPage(CPageController::IDD)
{
	//{{AFX_DATA_INIT(CPageController)
	m_nControllerNode = 0;
	m_strControllerName = _T("");
	m_nControllerLeft = 0;
	m_nControllerTop = 0;
	m_nControllerWidth = 0;
	m_nControllerHeight = 0;
	m_nControllerRows = 0;
	m_bScrollEnable = FALSE;
	m_nScrollHeight = 0;
	m_nScrollSpeed = 0;
	m_nQueueScrollSpeed = 0;
	m_strScrollContent = _T("");
	m_nControllerMode = 0;
	m_bControllerFromTop = FALSE;
	m_bTitleEnable = FALSE;
	m_strTitleContent = _T("");
	m_nTitleHeight = 0;
	m_nControllerCols = 0;
	m_bDesc = FALSE;
	m_bScroll = FALSE;
	//}}AFX_DATA_INIT

	this->m_pController			= NULL;
	this->m_pFontController		= NULL;
	this->m_pFontScroll			= NULL;
	this->m_pFontTitle			= NULL;
}

CPageController::~CPageController()
{
}

void CPageController::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageController)
	DDX_Control(pDX, IDC_LIST_CONTROLLER, m_listController);
	DDX_Text(pDX, IDC_EDIT_CONTROLLER_NODE, m_nControllerNode);
	DDX_Text(pDX, IDC_EDIT_CONTROLLER_NAME, m_strControllerName);
	DDX_Text(pDX, IDC_EDIT_CONTROLLER_LEFT, m_nControllerLeft);
	DDX_Text(pDX, IDC_EDIT_CONTROLLER_TOP, m_nControllerTop);
	DDX_Text(pDX, IDC_EDIT_CONTROLLER_WIDTH, m_nControllerWidth);
	DDX_Text(pDX, IDC_EDIT_CONTROLLER_HEIGHT, m_nControllerHeight);
	DDX_Text(pDX, IDC_EDIT_CONTROLLER_ROWS, m_nControllerRows);
	DDV_MinMaxUInt(pDX, m_nControllerRows, 1, 100);
	DDX_Check(pDX, IDC_CHECK_SCROLL_ENABLE, m_bScrollEnable);
	DDX_Text(pDX, IDC_EDIT_SCROLL_HEIGHT, m_nScrollHeight);
	DDX_Text(pDX, IDC_EDIT_SCROLL_SPEED, m_nScrollSpeed);
	DDV_MinMaxLong(pDX, m_nScrollSpeed, 1, 100);
	DDX_Text(pDX, IDC_EDIT_QUEUESCROLL_SPEED, m_nQueueScrollSpeed);
	DDV_MinMaxLong(pDX, m_nQueueScrollSpeed, 1, 100);
	DDX_Text(pDX, IDC_EDIT_SCROLL_CONTENT, m_strScrollContent);
	DDX_CBIndex(pDX, IDC_COMBO_CONTROLLER_MODE, m_nControllerMode);
	DDX_Check(pDX, IDC_CHECK_CONTROLLER_FROM_TOP, m_bControllerFromTop);
	DDX_Check(pDX, IDC_CHECK_TITLE_ENABLE, m_bTitleEnable);
	DDX_Text(pDX, IDC_EDIT_TITLE_CONTENT, m_strTitleContent);
	DDX_Text(pDX, IDC_EDIT_TITLE_HEIGHT, m_nTitleHeight);
	DDX_Text(pDX, IDC_EDIT_CONTROLLER_COLS, m_nControllerCols);
	DDV_MinMaxUInt(pDX, m_nControllerCols, 1, 10);
	DDX_Check(pDX, IDC_CHECK_BDESC, m_bDesc);
	DDX_Check(pDX, IDC_CHECK_BSCROLL, m_bScroll);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageController, CPropertyPage)
	//{{AFX_MSG_MAP(CPageController)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_INSERT, OnButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CONTROLLER, OnClickListController)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CONTROLLER, OnDblclkListController)
	ON_BN_CLICKED(IDC_BUTTON_CONTROLLER_BACKGROUND, OnButtonControllerBackground)
	ON_BN_CLICKED(IDC_BUTTON_CONTROLLER_FONT, OnButtonControllerFont)
	ON_BN_CLICKED(IDC_BUTTON_SCROLL_BACKGROUND, OnButtonScrollBackground)
	ON_BN_CLICKED(IDC_BUTTON_SCROLL_FOREGROUND, OnButtonScrollForeground)
	ON_BN_CLICKED(IDC_BUTTON_SCROLL_FONT, OnButtonScrollFont)
	ON_BN_CLICKED(IDC_BUTTON_TITLE_BACKGROUND, OnButtonTitleBackground)
	ON_BN_CLICKED(IDC_BUTTON_TITLE_FOREGROUND, OnButtonTitleForeground)
	ON_BN_CLICKED(IDC_BUTTON_TITLE_FONT, OnButtonTitleFont)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_REFRESH_LIST_MESSAGE, OnRefreshList)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageController message handlers

BOOL CPageController::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here

	this->m_listController.ModifyStyle(0, LVS_REPORT | LVS_SHOWSELALWAYS | LVS_SINGLESEL);
	this->m_listController.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP);
	this->m_listController.LoadSave(_T("eRadConfiguration.eRadSetQueueController.Controller"), FALSE, _T(""), REGISTER_LOCATION);

	BEGIN_LISTCOLUMNMAP(m_listController, 2)
		LISTCOLUMNMAP(IDS_CONTROLLER_NODE,		100,		LVCFMT_LEFT,	ELCT_INTEGER)
		LISTCOLUMNMAP(IDS_CONTROLLER_NAME,		200,		LVCFMT_LEFT,	ELCT_STRING_CASE)
	END_LISTCOLUMNMAP()

	this->RefreshController();

	this->Initialize();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CPageController::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CPropertyPage::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	switch (pWnd->GetDlgCtrlID())
	{
	case IDC_STATIC_CONTROLLER:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetBkColor(this->m_clrControllerBackground);
		pDC->SetTextColor(RGB(255, 255, 255));
		return this->m_brushController;
	case IDC_STATIC_SCROLL:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetBkColor(this->m_clrScrollBackground);
		pDC->SetTextColor(this->m_clrScrollForeground);
		return this->m_brushScroll;
	case IDC_STATIC_TITLE:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetBkColor(this->m_clrTitleBackground);
		pDC->SetTextColor(this->m_clrTitleForeground);
		return this->m_brushTitle;
	}

	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CPageController::OnButtonInsert() 
{
	// TODO: Add your control notification handler code here

	if (!this->DoValidate())
		return;

	this->m_pController = new CRunTime::CITEMController;

	SET_RIGHT_FROM_LEFT(this->m_nControllerNode,				this->m_pController->m_nControllerNode);
	SET_RIGHT_FROM_LEFT(this->m_strControllerName,				this->m_pController->m_strControllerName);
	SET_RIGHT_FROM_LEFT(this->m_nControllerMode,				this->m_pController->m_nControllerMode);
	SET_RIGHT_FROM_LEFT(this->m_nControllerLeft,				this->m_pController->m_nControllerLeft);
	SET_RIGHT_FROM_LEFT(this->m_nControllerTop,					this->m_pController->m_nControllerTop);
	SET_RIGHT_FROM_LEFT(this->m_nControllerWidth,				this->m_pController->m_nControllerWidth);
	SET_RIGHT_FROM_LEFT(this->m_nControllerHeight,				this->m_pController->m_nControllerHeight);
	SET_RIGHT_FROM_LEFT(this->m_nControllerRows,				this->m_pController->m_nControllerRows);
	SET_RIGHT_FROM_LEFT(this->m_nControllerCols,				this->m_pController->m_nControllerCols);
	SET_RIGHT_FROM_LEFT(this->m_bControllerFromTop,				this->m_pController->m_bControllerFromTop);
	SET_RIGHT_FROM_LEFT(this->m_strControllerFontName,			this->m_pController->m_strControllerFontName);
	SET_RIGHT_FROM_LEFT(this->m_nControllerFontSize,			this->m_pController->m_nControllerFontSize);
	SET_RIGHT_FROM_LEFT(this->m_clrControllerBackground,		this->m_pController->m_clrControllerBackground);
	SET_RIGHT_FROM_LEFT(this->m_bScrollEnable,					this->m_pController->m_bScrollEnable);
	SET_RIGHT_FROM_LEFT(this->m_nScrollHeight,					this->m_pController->m_nScrollHeight);
	SET_RIGHT_FROM_LEFT(this->m_nScrollSpeed,					this->m_pController->m_nScrollSpeed);
	SET_RIGHT_FROM_LEFT(this->m_nQueueScrollSpeed,				this->m_pController->m_nQueueScrollSpeed);
	SET_RIGHT_FROM_LEFT(this->m_strScrollContent,				this->m_pController->m_strScrollContent);
	SET_RIGHT_FROM_LEFT(this->m_strScrollFontName,				this->m_pController->m_strScrollFontName);
	SET_RIGHT_FROM_LEFT(this->m_nScrollFontSize,				this->m_pController->m_nScrollFontSize);
	SET_RIGHT_FROM_LEFT(this->m_clrScrollBackground,			this->m_pController->m_clrScrollBackground);
	SET_RIGHT_FROM_LEFT(this->m_clrScrollForeground,			this->m_pController->m_clrScrollForeground);
	SET_RIGHT_FROM_LEFT(this->m_bTitleEnable,					this->m_pController->m_bTitleEnable);
	SET_RIGHT_FROM_LEFT(this->m_strTitleContent,				this->m_pController->m_strTitleContent);
	SET_RIGHT_FROM_LEFT(this->m_nTitleHeight,					this->m_pController->m_nTitleHeight);
	SET_RIGHT_FROM_LEFT(this->m_strTitleFontName,				this->m_pController->m_strTitleFontName);
	SET_RIGHT_FROM_LEFT(this->m_nTitleFontSize,					this->m_pController->m_nTitleFontSize);
	SET_RIGHT_FROM_LEFT(this->m_clrTitleBackground,				this->m_pController->m_clrTitleBackground);
	SET_RIGHT_FROM_LEFT(this->m_clrTitleForeground,				this->m_pController->m_clrTitleForeground);
	SET_RIGHT_FROM_LEFT(this->m_bDesc,				            this->m_pController->m_bDesc);
	SET_RIGHT_FROM_LEFT(this->m_bScroll,				        this->m_pController->m_bScroll);

	CRunTime::GetLstController()->AddTail(this->m_pController);

	LONG nIndex = this->m_listController.InsertItem(0, _T(""));
	
	this->RefreshController(nIndex, this->m_pController);
	
	this->Initialize();
}

void CPageController::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here

	if (this->m_pController != NULL)
	{
		OBPOS POS = NULL;
		for (CRunTime::CITEMController* IT = CRunTime::GetLstController()->GetHead(POS); IT != NULL; IT = CRunTime::GetLstController()->GetNext(POS))
			if (IT == this->m_pController)
				break;

		if (IT != NULL)
		{
			delete CRunTime::GetLstController()->Remove(POS);

			LVFINDINFO lvFindInfo;
			lvFindInfo.flags = LVFI_PARAM;
			lvFindInfo.lParam = (DWORD) (LPVOID) this->m_pController;

			LONG nIndex = this->m_listController.FindItem(&lvFindInfo);
			if (nIndex != -1) this->m_listController.DeleteItem(nIndex);
		}
	}

	this->Initialize();
}

void CPageController::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here

	if (this->m_pController == NULL)
	{
		this->OnButtonInsert();
		return;
	}

	if (!this->DoValidate(FALSE))
		return;

	SET_RIGHT_FROM_LEFT(this->m_nControllerNode,				this->m_pController->m_nControllerNode);
	SET_RIGHT_FROM_LEFT(this->m_strControllerName,				this->m_pController->m_strControllerName);
	SET_RIGHT_FROM_LEFT(this->m_nControllerMode,				this->m_pController->m_nControllerMode);
	SET_RIGHT_FROM_LEFT(this->m_nControllerLeft,				this->m_pController->m_nControllerLeft);
	SET_RIGHT_FROM_LEFT(this->m_nControllerTop,					this->m_pController->m_nControllerTop);
	SET_RIGHT_FROM_LEFT(this->m_nControllerWidth,				this->m_pController->m_nControllerWidth);
	SET_RIGHT_FROM_LEFT(this->m_nControllerHeight,				this->m_pController->m_nControllerHeight);
	SET_RIGHT_FROM_LEFT(this->m_nControllerRows,				this->m_pController->m_nControllerRows);
	SET_RIGHT_FROM_LEFT(this->m_nControllerCols,				this->m_pController->m_nControllerCols);
	SET_RIGHT_FROM_LEFT(this->m_bControllerFromTop,				this->m_pController->m_bControllerFromTop);
	SET_RIGHT_FROM_LEFT(this->m_strControllerFontName,			this->m_pController->m_strControllerFontName);
	SET_RIGHT_FROM_LEFT(this->m_nControllerFontSize,			this->m_pController->m_nControllerFontSize);
	SET_RIGHT_FROM_LEFT(this->m_clrControllerBackground,		this->m_pController->m_clrControllerBackground);
	SET_RIGHT_FROM_LEFT(this->m_bScrollEnable,					this->m_pController->m_bScrollEnable);
	SET_RIGHT_FROM_LEFT(this->m_nScrollHeight,					this->m_pController->m_nScrollHeight);
	SET_RIGHT_FROM_LEFT(this->m_nScrollSpeed,					this->m_pController->m_nScrollSpeed);
	SET_RIGHT_FROM_LEFT(this->m_nQueueScrollSpeed,				this->m_pController->m_nQueueScrollSpeed);
	SET_RIGHT_FROM_LEFT(this->m_strScrollContent,				this->m_pController->m_strScrollContent);
	SET_RIGHT_FROM_LEFT(this->m_strScrollFontName,				this->m_pController->m_strScrollFontName);
	SET_RIGHT_FROM_LEFT(this->m_nScrollFontSize,				this->m_pController->m_nScrollFontSize);
	SET_RIGHT_FROM_LEFT(this->m_clrScrollBackground,			this->m_pController->m_clrScrollBackground);
	SET_RIGHT_FROM_LEFT(this->m_clrScrollForeground,			this->m_pController->m_clrScrollForeground);
	SET_RIGHT_FROM_LEFT(this->m_bTitleEnable,					this->m_pController->m_bTitleEnable);
	SET_RIGHT_FROM_LEFT(this->m_strTitleContent,				this->m_pController->m_strTitleContent);
	SET_RIGHT_FROM_LEFT(this->m_nTitleHeight,					this->m_pController->m_nTitleHeight);
	SET_RIGHT_FROM_LEFT(this->m_strTitleFontName,				this->m_pController->m_strTitleFontName);
	SET_RIGHT_FROM_LEFT(this->m_nTitleFontSize,					this->m_pController->m_nTitleFontSize);
	SET_RIGHT_FROM_LEFT(this->m_clrTitleBackground,				this->m_pController->m_clrTitleBackground);
	SET_RIGHT_FROM_LEFT(this->m_clrTitleForeground,				this->m_pController->m_clrTitleForeground);
	SET_RIGHT_FROM_LEFT(this->m_bDesc,			            	this->m_pController->m_bDesc);
	SET_RIGHT_FROM_LEFT(this->m_bScroll,			           	this->m_pController->m_bScroll);

	LVFINDINFO lvFindInfo;
	lvFindInfo.flags = LVFI_PARAM;
	lvFindInfo.lParam = (DWORD) (LPVOID) this->m_pController;

	LONG nIndex = this->m_listController.FindItem(&lvFindInfo);

	if (nIndex != -1) this->RefreshController(nIndex, this->m_pController);

	this->Initialize();
}

void CPageController::OnClickListController(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	LONG nIndex = this->m_listController.GetNextItem(-1, LVNI_SELECTED);
	if (nIndex == -1)
		return;

	this->Initialize();

	this->m_pController = (CRunTime::CITEMController*) this->m_listController.GetItemData(nIndex);

	SET_LEFT_FROM_RIGHT(this->m_nControllerNode,				this->m_pController->m_nControllerNode);
	SET_LEFT_FROM_RIGHT(this->m_strControllerName,				this->m_pController->m_strControllerName);
	SET_LEFT_FROM_RIGHT(this->m_nControllerMode,				this->m_pController->m_nControllerMode);
	SET_LEFT_FROM_RIGHT(this->m_nControllerLeft,				this->m_pController->m_nControllerLeft);
	SET_LEFT_FROM_RIGHT(this->m_nControllerTop,					this->m_pController->m_nControllerTop);
	SET_LEFT_FROM_RIGHT(this->m_nControllerWidth,				this->m_pController->m_nControllerWidth);
	SET_LEFT_FROM_RIGHT(this->m_nControllerHeight,				this->m_pController->m_nControllerHeight);
	SET_LEFT_FROM_RIGHT(this->m_nControllerRows,				this->m_pController->m_nControllerRows);
	SET_LEFT_FROM_RIGHT(this->m_nControllerCols,				this->m_pController->m_nControllerCols);
	SET_LEFT_FROM_RIGHT(this->m_bControllerFromTop,				this->m_pController->m_bControllerFromTop);
	SET_LEFT_FROM_RIGHT(this->m_strControllerFontName,			this->m_pController->m_strControllerFontName);
	SET_LEFT_FROM_RIGHT(this->m_nControllerFontSize,			this->m_pController->m_nControllerFontSize);
	SET_LEFT_FROM_RIGHT(this->m_clrControllerBackground,		this->m_pController->m_clrControllerBackground);
	SET_LEFT_FROM_RIGHT(this->m_bScrollEnable,					this->m_pController->m_bScrollEnable);
	SET_LEFT_FROM_RIGHT(this->m_nScrollHeight,					this->m_pController->m_nScrollHeight);
	SET_LEFT_FROM_RIGHT(this->m_nScrollSpeed,					this->m_pController->m_nScrollSpeed);
	SET_LEFT_FROM_RIGHT(this->m_nQueueScrollSpeed,				this->m_pController->m_nQueueScrollSpeed);
	SET_LEFT_FROM_RIGHT(this->m_strScrollContent,				this->m_pController->m_strScrollContent);
	SET_LEFT_FROM_RIGHT(this->m_strScrollFontName,				this->m_pController->m_strScrollFontName);
	SET_LEFT_FROM_RIGHT(this->m_nScrollFontSize,				this->m_pController->m_nScrollFontSize);
	SET_LEFT_FROM_RIGHT(this->m_clrScrollBackground,			this->m_pController->m_clrScrollBackground);
	SET_LEFT_FROM_RIGHT(this->m_clrScrollForeground,			this->m_pController->m_clrScrollForeground);
	SET_LEFT_FROM_RIGHT(this->m_bTitleEnable,					this->m_pController->m_bTitleEnable);
	SET_LEFT_FROM_RIGHT(this->m_strTitleContent,				this->m_pController->m_strTitleContent);
	SET_LEFT_FROM_RIGHT(this->m_nTitleHeight,					this->m_pController->m_nTitleHeight);
	SET_LEFT_FROM_RIGHT(this->m_strTitleFontName,				this->m_pController->m_strTitleFontName);
	SET_LEFT_FROM_RIGHT(this->m_nTitleFontSize,					this->m_pController->m_nTitleFontSize);
	SET_LEFT_FROM_RIGHT(this->m_clrTitleBackground,				this->m_pController->m_clrTitleBackground);
	SET_LEFT_FROM_RIGHT(this->m_clrTitleForeground,				this->m_pController->m_clrTitleForeground);
	SET_LEFT_FROM_RIGHT(this->m_bDesc,			            	this->m_pController->m_bDesc);
	SET_LEFT_FROM_RIGHT(this->m_bScroll,			            this->m_pController->m_bScroll);
	
	this->UpdateData(FALSE);

	this->ShowPreview();

	*pResult = 0;
}

void CPageController::OnDblclkListController(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	LONG nIndex = this->m_listController.GetNextItem(-1, LVNI_SELECTED);
	if (nIndex == -1)
		return;

	CRunTime::CITEMController* pController = (CRunTime::CITEMController*) this->m_listController.GetItemData(nIndex);

	CSetSheet dlgSheet(_T(""));
	dlgSheet.m_psh.dwFlags &= ~PSH_HASHELP;
	dlgSheet.m_psh.dwFlags |= PSH_NOAPPLYNOW;
	dlgSheet.m_psh.dwFlags |= PSH_PROPTITLE;

	CPageMode0General			dlgMode0General;
	CPageMode1Report			dlgMode1Report;
	CPageMode2SingleQueue		dlgMode2SingleQueue;
	CPageVideo					dlgVideo;
	CPageVoice					dlgVoice;
	CPageSingleQueueShowAll     dlgMode3SingleQueueShowALL;

	dlgMode0General				.m_psp.dwFlags &= ~PSP_HASHELP;
	dlgMode1Report				.m_psp.dwFlags &= ~PSP_HASHELP;
	dlgMode2SingleQueue			.m_psp.dwFlags &= ~PSP_HASHELP;
	dlgVideo					.m_psp.dwFlags &= ~PSP_HASHELP;
	dlgVoice					.m_psp.dwFlags &= ~PSP_HASHELP;
	dlgMode3SingleQueueShowALL  .m_psp.dwFlags &= ~PSP_HASHELP;

	dlgMode1Report				.m_pController = pController;
	dlgMode2SingleQueue			.m_pController = pController;
	dlgVideo					.m_pController = pController;
	dlgVoice					.m_pController = pController;
    dlgMode3SingleQueueShowALL  .m_pController = pController;
    

	switch (pController->m_nControllerMode)
	{
	case EC_MODE0_GENERAL:
		dlgSheet.AddPage(&dlgMode0General);
		break;
	case EC_MODE1_REPORT:
		dlgSheet.AddPage(&dlgMode1Report);
		break;
	case EC_MODE2_SINGLE_QUEUE:
		dlgSheet.AddPage(&dlgMode2SingleQueue);
		break;
	case EC_MODE3_SINGLE_QUEUE_SHOWALL:
        dlgSheet.AddPage(&dlgMode3SingleQueueShowALL);
		break;
		
	}

	dlgSheet.AddPage(&dlgVideo);
	dlgSheet.AddPage(&dlgVoice);

	SET_LEFT_FROM_RIGHT(dlgVoice.m_bVoiceEnable,					pController->m_bVoiceEnable);
	SET_LEFT_FROM_RIGHT(dlgVoice.m_nVoiceRepeat,					pController->m_nVoiceRepeat);
	SET_LEFT_FROM_RIGHT(dlgVoice.m_nVoiceInterval,					pController->m_nVoiceInterval);
	SET_LEFT_FROM_RIGHT(dlgVoice.m_strVoiceFormat,					pController->m_strVoiceFormat);

	SET_LEFT_FROM_RIGHT(dlgVoice.m_bpromptVoiceEnable,				pController->m_bpromptVoiceEnable);
	SET_LEFT_FROM_RIGHT(dlgVoice.m_bUseKdfx,			            pController->m_bUseKdfx);
    SET_LEFT_FROM_RIGHT(dlgVoice.m_strSeriesId,			            pController->m_strSeriesId);


	switch (pController->m_nControllerMode)
	{
	case EC_MODE0_GENERAL:
		break;
	case EC_MODE1_REPORT:
		SET_LEFT_FROM_RIGHT(dlgMode1Report.m_nMode1TimeRange,				pController->m_nMode1TimeRange);
		SET_LEFT_FROM_RIGHT(dlgMode1Report.m_nMode1TimeDelay,				pController->m_nMode1TimeDelay);
		SET_LEFT_FROM_RIGHT(dlgMode1Report.m_nMode1RefreshIdle,				pController->m_nMode1RefreshIdle);
		SET_LEFT_FROM_RIGHT(dlgMode1Report.m_nMode1RefreshScreen,			pController->m_nMode1RefreshScreen);
		SET_LEFT_FROM_RIGHT(dlgMode1Report.m_nMode1OrderMode,				pController->m_nMode1OrderMode);
		break;
	case EC_MODE2_SINGLE_QUEUE:
		SET_LEFT_FROM_RIGHT(dlgMode2SingleQueue.m_nMode2DeviceIndex,		pController->m_nMode2DeviceIndex);
		SET_LEFT_FROM_RIGHT(dlgMode2SingleQueue.m_nMode2RefreshIdle,		pController->m_nMode2RefreshIdle);
		break;
	case EC_MODE3_SINGLE_QUEUE_SHOWALL:
		SET_LEFT_FROM_RIGHT(dlgMode3SingleQueueShowALL.m_MODE3QueueIndex,		pController->m_MODE3QueueIndex);
		SET_LEFT_FROM_RIGHT(dlgMode3SingleQueueShowALL.m_MODE3RenovateTime,		pController->m_MODE3RenovateTime);
		SET_LEFT_FROM_RIGHT(dlgMode3SingleQueueShowALL.m_bShowHorizontal,       pController->m_bShowHorizontal);


       break;
	}

	if (dlgSheet.DoModal() == IDOK)
	{
		SET_RIGHT_FROM_LEFT(dlgVoice.m_bVoiceEnable,				pController->m_bVoiceEnable);
		SET_RIGHT_FROM_LEFT(dlgVoice.m_nVoiceRepeat,				pController->m_nVoiceRepeat);
		SET_RIGHT_FROM_LEFT(dlgVoice.m_nVoiceInterval,				pController->m_nVoiceInterval);
		SET_RIGHT_FROM_LEFT(dlgVoice.m_strVoiceFormat,				pController->m_strVoiceFormat);

        SET_RIGHT_FROM_LEFT(dlgVoice.m_bpromptVoiceEnable,			pController->m_bpromptVoiceEnable);
	    SET_RIGHT_FROM_LEFT(dlgVoice.m_bUseKdfx,			            pController->m_bUseKdfx);
		SET_RIGHT_FROM_LEFT(dlgVoice.m_strSeriesId,			            pController->m_strSeriesId);


		switch (pController->m_nControllerMode)
		{
		case EC_MODE0_GENERAL:
			break;
		case EC_MODE1_REPORT:
			SET_RIGHT_FROM_LEFT(dlgMode1Report.m_nMode1TimeRange,			pController->m_nMode1TimeRange);
			SET_RIGHT_FROM_LEFT(dlgMode1Report.m_nMode1TimeDelay,			pController->m_nMode1TimeDelay);
			SET_RIGHT_FROM_LEFT(dlgMode1Report.m_nMode1RefreshIdle,			pController->m_nMode1RefreshIdle);
			SET_RIGHT_FROM_LEFT(dlgMode1Report.m_nMode1RefreshScreen,		pController->m_nMode1RefreshScreen);
			SET_RIGHT_FROM_LEFT(dlgMode1Report.m_nMode1OrderMode,			pController->m_nMode1OrderMode);
			break;
		case EC_MODE2_SINGLE_QUEUE:
			SET_RIGHT_FROM_LEFT(dlgMode2SingleQueue.m_nMode2DeviceIndex,	pController->m_nMode2DeviceIndex);
			SET_RIGHT_FROM_LEFT(dlgMode2SingleQueue.m_nMode2RefreshIdle,	pController->m_nMode2RefreshIdle);
			break;
		case EC_MODE3_SINGLE_QUEUE_SHOWALL:
			SET_RIGHT_FROM_LEFT(dlgMode3SingleQueueShowALL.m_MODE3QueueIndex,		pController->m_MODE3QueueIndex);
		    SET_RIGHT_FROM_LEFT(dlgMode3SingleQueueShowALL.m_MODE3RenovateTime,		pController->m_MODE3RenovateTime);
			SET_RIGHT_FROM_LEFT(dlgMode3SingleQueueShowALL.m_bShowHorizontal,       pController->m_bShowHorizontal);

			break;
		}
	}

	*pResult = 0;
}

void CPageController::OnButtonControllerBackground() 
{
	// TODO: Add your control notification handler code here

	CColorDialog dlgColor(this->m_clrControllerBackground, 0, this);
	if (dlgColor.DoModal() == IDOK)
	{
		this->m_clrControllerBackground = dlgColor.GetColor();

		this->ShowPreview();
	}
}

void CPageController::OnButtonControllerFont() 
{
	// TODO: Add your control notification handler code here

	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	strcpy(lf.lfFaceName, this->m_strControllerFontName);
	lf.lfHeight = this->m_nControllerFontSize;

	CFontDialog dlgFont(&lf, CF_EFFECTS | CF_SCREENFONTS, NULL, this);
	if (dlgFont.DoModal() == IDOK)
	{
		dlgFont.GetCurrentFont(&lf);
		this->m_strControllerFontName = lf.lfFaceName;
		this->m_nControllerFontSize = lf.lfHeight;

		this->ShowPreview();
	}
}

void CPageController::OnButtonScrollBackground() 
{
	// TODO: Add your control notification handler code here

	CColorDialog dlgColor(this->m_clrScrollBackground, 0, this);
	if (dlgColor.DoModal() == IDOK)
	{
		this->m_clrScrollBackground = dlgColor.GetColor();

		this->ShowPreview();
	}
}

void CPageController::OnButtonScrollForeground() 
{
	// TODO: Add your control notification handler code here

	CColorDialog dlgColor(this->m_clrScrollForeground, 0, this);
	if (dlgColor.DoModal() == IDOK)
	{
		this->m_clrScrollForeground = dlgColor.GetColor();

		this->ShowPreview();
	}
}

void CPageController::OnButtonScrollFont() 
{
	// TODO: Add your control notification handler code here

	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	strcpy(lf.lfFaceName, this->m_strScrollFontName);
	lf.lfHeight = this->m_nScrollFontSize;

	CFontDialog dlgFont(&lf, CF_EFFECTS | CF_SCREENFONTS, NULL, this);
	if (dlgFont.DoModal() == IDOK)
	{
		dlgFont.GetCurrentFont(&lf);
		this->m_strScrollFontName = lf.lfFaceName;
		this->m_nScrollFontSize = lf.lfHeight;

		this->ShowPreview();
	}
}

void CPageController::OnButtonTitleBackground() 
{
	// TODO: Add your control notification handler code here

	CColorDialog dlgColor(this->m_clrTitleBackground, 0, this);
	if (dlgColor.DoModal() == IDOK)
	{
		this->m_clrTitleBackground = dlgColor.GetColor();

		this->ShowPreview();
	}
}

void CPageController::OnButtonTitleForeground() 
{
	// TODO: Add your control notification handler code here

	CColorDialog dlgColor(this->m_clrTitleForeground, 0, this);
	if (dlgColor.DoModal() == IDOK)
	{
		this->m_clrTitleForeground = dlgColor.GetColor();

		this->ShowPreview();
	}
}

void CPageController::OnButtonTitleFont() 
{
	// TODO: Add your control notification handler code here

	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	strcpy(lf.lfFaceName, this->m_strTitleFontName);
	lf.lfHeight = this->m_nTitleFontSize;

	CFontDialog dlgFont(&lf, CF_EFFECTS | CF_SCREENFONTS, NULL, this);
	if (dlgFont.DoModal() == IDOK)
	{
		dlgFont.GetCurrentFont(&lf);
		this->m_strTitleFontName = lf.lfFaceName;
		this->m_nTitleFontSize = lf.lfHeight;

		this->ShowPreview();
	}
}

BOOL CPageController::Initialize()
{
	this->m_nControllerNode = 0;
	this->m_strControllerName = _T("");
	this->m_nControllerMode = 0;
	this->m_nControllerLeft = 0;
	this->m_nControllerTop = 0;
	this->m_nControllerWidth = 0;
	this->m_nControllerHeight = 0;
	this->m_nControllerRows = 8;
	this->m_bControllerFromTop = TRUE;
	this->m_bScrollEnable = FALSE;
	this->m_nScrollHeight = 100;
	this->m_nScrollSpeed = 10;
	this->m_nQueueScrollSpeed = 10;
	this->m_strScrollContent = _T("");
	this->m_bTitleEnable = FALSE;
	this->m_strTitleContent = _T("");
	this->m_nTitleHeight = 100;
	this->m_nControllerCols = 1;
	

	this->m_pController = NULL;

	LOGFONT lf;
	this->GetFont()->GetLogFont(&lf);

	this->m_strControllerFontName	= lf.lfFaceName;
	this->m_nControllerFontSize		= lf.lfHeight;
	this->m_clrControllerBackground	= RGB(0, 0, 255);
	this->m_strScrollFontName		= lf.lfFaceName;
	this->m_nScrollFontSize			= lf.lfHeight;
	this->m_clrScrollBackground		= RGB(0, 0, 0);
	this->m_clrScrollForeground		= RGB(255, 0, 0);
	this->m_strTitleFontName		= lf.lfFaceName;
	this->m_nTitleFontSize			= lf.lfHeight;
	this->m_clrTitleBackground		= RGB(0, 0, 0);
	this->m_clrTitleForeground		= RGB(255, 0, 0);
	this->m_bDesc = FALSE;
	this->m_bScroll = FALSE;

	this->UpdateData(FALSE);

	this->ShowPreview();

	return TRUE;
}

BOOL CPageController::DoValidate(BOOL bInsert)
{
	this->UpdateData();

	return TRUE;
}

BOOL CPageController::ShowPreview()
{
	this->m_brushController = CreateSolidBrush(this->m_clrControllerBackground);

	if (this->m_pFontController != NULL)
		delete this->m_pFontController;
	this->m_pFontController = new CFont;
	LOGFONT lf1;
	memset(&lf1, 0, sizeof(LOGFONT));
	strcpy(lf1.lfFaceName, this->m_strControllerFontName);
	lf1.lfHeight = this->m_nControllerFontSize;
	this->m_pFontController->CreateFontIndirect(&lf1);
	this->GetDlgItem(IDC_STATIC_CONTROLLER)->SetFont(this->m_pFontController);
	this->GetDlgItem(IDC_STATIC_CONTROLLER)->Invalidate();

	this->m_brushScroll = CreateSolidBrush(this->m_clrScrollBackground);

	if (this->m_pFontScroll != NULL)
		delete this->m_pFontScroll;
	this->m_pFontScroll = new CFont;
	LOGFONT lf2;
	memset(&lf2, 0, sizeof(LOGFONT));
	strcpy(lf2.lfFaceName, this->m_strScrollFontName);
	lf2.lfHeight = this->m_nScrollFontSize;
	this->m_pFontScroll->CreateFontIndirect(&lf2);
	this->GetDlgItem(IDC_STATIC_SCROLL)->SetFont(this->m_pFontScroll);
	this->GetDlgItem(IDC_STATIC_SCROLL)->Invalidate();

	this->m_brushTitle = CreateSolidBrush(this->m_clrTitleBackground);

	if (this->m_pFontTitle != NULL)
		delete this->m_pFontTitle;
	this->m_pFontTitle = new CFont;
	LOGFONT lf3;
	memset(&lf3, 0, sizeof(LOGFONT));
	strcpy(lf3.lfFaceName, this->m_strTitleFontName);
	lf3.lfHeight = this->m_nTitleFontSize;
	this->m_pFontTitle->CreateFontIndirect(&lf3);
	this->GetDlgItem(IDC_STATIC_TITLE)->SetFont(this->m_pFontTitle);
	this->GetDlgItem(IDC_STATIC_TITLE)->Invalidate();

	return TRUE;
}

void CPageController::OnRefreshList(WPARAM wParam, LPARAM lParam)
{
	if (this->m_listController.m_nIdentifier == wParam) RefreshController();
}

void CPageController::RefreshController()
{
	this->m_listController.DeleteAllItems();

	OBPOS POS = NULL;
	for (CRunTime::CITEMController* IT = CRunTime::GetLstController()->GetHead(POS); IT != NULL; IT = CRunTime::GetLstController()->GetNext(POS))
	{
		LONG nIndex = this->m_listController.InsertItem(0, _T(""));

		this->RefreshController(nIndex, IT);
	}

	this->m_listController.SortListCtrl();
}

void CPageController::RefreshController(LONG nIndex, CRunTime::CITEMController* pController)
{
	this->m_listController.SetItemText(nIndex, 0, pController->m_nControllerNode);
	this->m_listController.SetItemText(nIndex, 1, pController->m_strControllerName);

	this->m_listController.SetItemData(nIndex, (DWORD) (LPVOID) pController);
}
