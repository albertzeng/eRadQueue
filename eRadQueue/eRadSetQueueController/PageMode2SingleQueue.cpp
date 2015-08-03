// PageMode2SingleQueue.cpp : implementation file
//

#include "stdafx.h"
#include "eRadSetQueueController.h"
#include "PageMode2SingleQueue.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageMode2SingleQueue property page

IMPLEMENT_DYNCREATE(CPageMode2SingleQueue, CPropertyPage)

CPageMode2SingleQueue::CPageMode2SingleQueue() : CPropertyPage(CPageMode2SingleQueue::IDD)
{
	//{{AFX_DATA_INIT(CPageMode2SingleQueue)
	m_nMode2DeviceIndex = 0;
	m_nMode2RefreshIdle = 60;
	//}}AFX_DATA_INIT

	this->m_pController			= NULL;
}

CPageMode2SingleQueue::~CPageMode2SingleQueue()
{
}

void CPageMode2SingleQueue::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageMode2SingleQueue)
	DDX_Control(pDX, IDC_LIST_DEVICE, m_listDevice);
	DDX_Text(pDX, IDC_EDIT_MODE2_DEVICE_INDEX, m_nMode2DeviceIndex);
	DDX_Text(pDX, IDC_EDIT_MODE2_REFRESH_IDLE, m_nMode2RefreshIdle);
	DDV_MinMaxUInt(pDX, m_nMode2RefreshIdle, 10, 100000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageMode2SingleQueue, CPropertyPage)
	//{{AFX_MSG_MAP(CPageMode2SingleQueue)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_DEVICE, OnDblclkListDevice)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageMode2SingleQueue message handlers

BOOL CPageMode2SingleQueue::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here

	this->m_listDevice.ModifyStyle(0, LVS_REPORT | LVS_SHOWSELALWAYS | LVS_SINGLESEL);
	this->m_listDevice.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP);
	this->m_listDevice.LoadSave(_T("eRadConfiguration.eRadSetQueueController.Device"), FALSE, _T(""), REGISTER_LOCATION);

	BEGIN_LISTCOLUMNMAP(m_listDevice, 2)
		LISTCOLUMNMAP(IDS_DEVICE_INDEX,		100,		LVCFMT_LEFT,	ELCT_INTEGER)
		LISTCOLUMNMAP(IDS_DEVICE_NAME,		200,		LVCFMT_LEFT,	ELCT_STRING_CASE)
	END_LISTCOLUMNMAP()

	MRET rc = this->LoadDevice();
	if (rc != ME_OK)
	{
		LOG_ERROR(LL_ERROR | LD_ALL, rc);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPageMode2SingleQueue::OnDblclkListDevice(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	this->UpdateData();

	LONG nIndex = this->m_listDevice.GetNextItem(-1, LVNI_SELECTED);
	if (nIndex != -1)
		this->m_nMode2DeviceIndex = this->m_listDevice.GetItemData(nIndex);

	this->UpdateData(FALSE);

	*pResult = 0;
}

MRET CPageMode2SingleQueue::LoadDevice()
{
	this->m_listDevice.DeleteAllItems();

	if (!CRunTime::GetGeneral()->m_strEISDatabase.IsEmpty())
	{
		COleSession dbSession;
		COleSession* pSession = CRunTime::GetEISSession(&dbSession);
		if (pSession == NULL)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_SESSION);
		}

		CString strFilter;
		strFilter.Format(_T("WHERE DeviceDepartment = %d"), CRunTime::GetGeneral()->m_nUseDepartment);

		CdboMGRDevice dboDevice;
		dboDevice.SetDataSource(pSession);
		if (FAILED(dboDevice.Open(strFilter)))
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE);
		}

		LONG nIndex = 0;
		while (dboDevice.MoveNext() == S_OK)
		{
			nIndex = this->m_listDevice.InsertItem(0,		_T(""));
			this->m_listDevice.SetItemText(nIndex, 0,		dboDevice.m_DeviceIndex);
			this->m_listDevice.SetItemText(nIndex, 1,		dboDevice.m_DeviceName);

			this->m_listDevice.SetItemData(nIndex++, dboDevice.m_DeviceIndex);
		}

		dboDevice.Close();
	}

	return ME_OK;
}
