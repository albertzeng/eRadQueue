// PageVideo.cpp : implementation file
//

#include "stdafx.h"
#include "eRadSetQueueController.h"
#include "PageVideo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageVideo property page

IMPLEMENT_DYNCREATE(CPageVideo, CPropertyPage)

CPageVideo::CPageVideo() : CPropertyPage(CPageVideo::IDD)
{
	//{{AFX_DATA_INIT(CPageVideo)
	m_nVideoOrder = 0;
	m_nVideoLength = 0;
	m_strVideoContent = _T("");
	//}}AFX_DATA_INIT

	this->m_pVideo			= NULL;
	this->m_pController		= NULL;
	this->m_pFontController	= NULL;
}

CPageVideo::~CPageVideo()
{
}

void CPageVideo::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageVideo)
	DDX_Control(pDX, IDC_LIST_VIDEO, m_listVideo);
	DDX_Text(pDX, IDC_EDIT_VIDEO_ORDER, m_nVideoOrder);
	DDX_Text(pDX, IDC_EDIT_VIDEO_LENGTH, m_nVideoLength);
	DDX_Text(pDX, IDC_EDIT_VIDEO_CONTENT, m_strVideoContent);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageVideo, CPropertyPage)
	//{{AFX_MSG_MAP(CPageVideo)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_INSERT, OnButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_NOTIFY(NM_CLICK, IDC_LIST_VIDEO, OnClickListVideo)
	ON_BN_CLICKED(IDC_BUTTON_VIDEO_FOREGROUND, OnButtonVideoForeground)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageVideo message handlers

BOOL CPageVideo::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here

	this->m_listVideo.ModifyStyle(0, LVS_REPORT | LVS_SHOWSELALWAYS | LVS_SINGLESEL);
	this->m_listVideo.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP);
	this->m_listVideo.LoadSave(_T("eRadConfiguration.eRadSetQueueController.Video"), FALSE, _T(""), REGISTER_LOCATION);

	BEGIN_LISTCOLUMNMAP(m_listVideo, 3)
		LISTCOLUMNMAP(IDS_VIDEO_ORDER,			100,		LVCFMT_LEFT,	ELCT_INTEGER)
		LISTCOLUMNMAP(IDS_VIDEO_LENGTH,			100,		LVCFMT_LEFT,	ELCT_INTEGER)
		LISTCOLUMNMAP(IDS_VIDEO_CONTENT,		200,		LVCFMT_LEFT,	ELCT_STRING_CASE)
	END_LISTCOLUMNMAP()

	this->RefreshVideo();

	this->m_brushController = CreateSolidBrush(this->m_pController->m_clrControllerBackground);

	this->m_pFontController = new CFont;
	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	strcpy(lf.lfFaceName, this->m_pController->m_strControllerFontName);
	lf.lfHeight = this->m_pController->m_nControllerFontSize;
	this->m_pFontController->CreateFontIndirect(&lf);
	this->GetDlgItem(IDC_STATIC_CONTROLLER)->SetFont(this->m_pFontController);

	this->Initialize();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CPageVideo::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CPropertyPage::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	switch (pWnd->GetDlgCtrlID())
	{
	case IDC_STATIC_CONTROLLER:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetBkColor(this->m_pController->m_clrControllerBackground);
		pDC->SetTextColor(this->m_clrVideoForeground);
		return this->m_brushController;
	}

	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CPageVideo::OnButtonInsert() 
{
	// TODO: Add your control notification handler code here

	if (!this->DoValidate())
		return;

	this->m_pVideo = new CRunTime::CITEMVideo;

	SET_RIGHT_FROM_LEFT(this->m_nVideoOrder,				this->m_pVideo->m_nVideoOrder);
	SET_RIGHT_FROM_LEFT(this->m_nVideoLength,				this->m_pVideo->m_nVideoLength);
	SET_RIGHT_FROM_LEFT(this->m_strVideoContent,			this->m_pVideo->m_strVideoContent);
	SET_RIGHT_FROM_LEFT(this->m_clrVideoForeground,			this->m_pVideo->m_clrVideoForeground);

	this->m_pController->m_lstVideo.AddTail(this->m_pVideo);

	LONG nIndex = this->m_listVideo.InsertItem(0, _T(""));

	this->RefreshVideo(nIndex, this->m_pVideo);

	this->Initialize();
}

void CPageVideo::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here

	if (this->m_pVideo != NULL)
	{
		OBPOS POS = NULL;
		for (CRunTime::CITEMVideo* IT = this->m_pController->m_lstVideo.GetHead(POS); IT != NULL; IT = this->m_pController->m_lstVideo.GetNext(POS))
			if (IT == this->m_pVideo)
				break;

		if (IT != NULL)
		{
			delete this->m_pController->m_lstVideo.Remove(POS);

			LVFINDINFO lvFindInfo;
			lvFindInfo.flags = LVFI_PARAM;
			lvFindInfo.lParam = (DWORD) (LPVOID) this->m_pVideo;

			LONG nIndex = this->m_listVideo.FindItem(&lvFindInfo);
			if (nIndex != -1) this->m_listVideo.DeleteItem(nIndex);
		}
	}

	this->Initialize();
}

void CPageVideo::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here

	if (this->m_pVideo == NULL)
	{
		this->OnButtonInsert();
		return;
	}

	if (!this->DoValidate(FALSE))
		return;

	SET_RIGHT_FROM_LEFT(this->m_nVideoOrder,				this->m_pVideo->m_nVideoOrder);
	SET_RIGHT_FROM_LEFT(this->m_nVideoLength,				this->m_pVideo->m_nVideoLength);
	SET_RIGHT_FROM_LEFT(this->m_strVideoContent,			this->m_pVideo->m_strVideoContent);
	SET_RIGHT_FROM_LEFT(this->m_clrVideoForeground,			this->m_pVideo->m_clrVideoForeground);

	LVFINDINFO lvFindInfo;
	lvFindInfo.flags = LVFI_PARAM;
	lvFindInfo.lParam = (DWORD) (LPVOID) this->m_pVideo;

	LONG nIndex = this->m_listVideo.FindItem(&lvFindInfo);

	if (nIndex != -1) this->RefreshVideo(nIndex, this->m_pVideo);

	this->Initialize();
}

void CPageVideo::OnClickListVideo(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	LONG nIndex = this->m_listVideo.GetNextItem(-1, LVNI_SELECTED);
	if (nIndex == -1)
		return;

	this->Initialize();

	this->m_pVideo = (CRunTime::CITEMVideo*) this->m_listVideo.GetItemData(nIndex);

	SET_LEFT_FROM_RIGHT(this->m_nVideoOrder,				this->m_pVideo->m_nVideoOrder);
	SET_LEFT_FROM_RIGHT(this->m_nVideoLength,				this->m_pVideo->m_nVideoLength);
	SET_LEFT_FROM_RIGHT(this->m_strVideoContent,			this->m_pVideo->m_strVideoContent);
	SET_LEFT_FROM_RIGHT(this->m_clrVideoForeground,			this->m_pVideo->m_clrVideoForeground);

	this->UpdateData(FALSE);

	this->GetDlgItem(IDC_STATIC_CONTROLLER)->Invalidate();

	*pResult = 0;
}

void CPageVideo::OnButtonVideoForeground() 
{
	// TODO: Add your control notification handler code here

	CColorDialog dlgColor(this->m_clrVideoForeground, 0, this);
	if (dlgColor.DoModal() == IDOK)
	{
		this->m_clrVideoForeground = dlgColor.GetColor();

		this->GetDlgItem(IDC_STATIC_CONTROLLER)->Invalidate();
	}
}

BOOL CPageVideo::Initialize()
{
	this->m_nVideoOrder = 0;
	this->m_nVideoLength = 1;
	this->m_strVideoContent = _T("");

	this->m_pVideo = NULL;

	this->m_clrVideoForeground = RGB(255, 255, 255);

	this->UpdateData(FALSE);

	this->GetDlgItem(IDC_STATIC_CONTROLLER)->Invalidate();

	return TRUE;
}

BOOL CPageVideo::DoValidate(BOOL bInsert)
{
	this->UpdateData();

	return TRUE;
}

void CPageVideo::OnRefreshList(WPARAM wParam, LPARAM lParam)
{
	if (this->m_listVideo.m_nIdentifier == wParam) RefreshVideo();
}

void CPageVideo::RefreshVideo()
{
	this->m_listVideo.DeleteAllItems();

	OBPOS POS = NULL;
	for (CRunTime::CITEMVideo* IT = this->m_pController->m_lstVideo.GetHead(POS); IT != NULL; IT = this->m_pController->m_lstVideo.GetNext(POS))
	{
		LONG nIndex = this->m_listVideo.InsertItem(0, _T(""));
		
		this->RefreshVideo(nIndex, IT);
	}
	
	this->m_listVideo.SortListCtrl();
}

void CPageVideo::RefreshVideo(LONG nIndex, CRunTime::CITEMVideo* pVideo)
{
	this->m_listVideo.SetItemText(nIndex, 0, pVideo->m_nVideoOrder);
	this->m_listVideo.SetItemText(nIndex, 1, pVideo->m_nVideoLength);
	this->m_listVideo.SetItemText(nIndex, 2, pVideo->m_strVideoContent);

	this->m_listVideo.SetItemData(nIndex, (DWORD) (LPVOID) pVideo);
}
