// PageGeneral.cpp : implementation file
//

#include "stdafx.h"
#include "eRadQueueCall.h"
#include "PageGeneral.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageGeneral property page

IMPLEMENT_DYNCREATE(CPageGeneral, CPropertyPage)

CPageGeneral::CPageGeneral() : CPropertyPage(CPageGeneral::IDD)
{
	//{{AFX_DATA_INIT(CPageGeneral)
	m_bLogTRACK = FALSE;
	m_bLogDEBUG = FALSE;
	m_bLogERROR = FALSE;
	m_bLogMESSAGE = FALSE;
	m_nCallNode = 0;
	m_strCallName = _T("");
	m_strCallConsole = _T("");
	m_strCallDevice = _T("");
	m_strMZQueue = _T("");
	m_strZYQueue = _T("");
	m_strCallRoom = _T("");
	m_strCallRoomNode = _T("");
	m_bCallPriority = FALSE;
	m_bCallOrder = FALSE;
	m_bCallCaptureReport = FALSE;
	m_bCallCapture = FALSE;
	m_bCallReport = FALSE;
	m_bPrivateSaveToFile = FALSE;
	m_bCallComplete = FALSE;
	m_bCallReset = FALSE;
	m_nCallIncrement = 0;
	m_bCallCancel = FALSE;
	m_bCallWait = FALSE;
	m_bAfternoon = FALSE;
	m_strAfternoonTime = _T("");
	m_nAutoRefresh = 0;
	m_bCallUnready = FALSE;
	m_bCallOrderNoReport = FALSE;
	m_bCallIQueueRoom = FALSE;
	m_bCallQueuePatientKind = FALSE;
	m_bNoPopOrderCall = FALSE;
	m_bCallPre = FALSE;
	//}}AFX_DATA_INIT

	this->m_nCallDepartment = 0;
}

CPageGeneral::~CPageGeneral()
{
}

void CPageGeneral::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageGeneral)
	DDX_Control(pDX, IDC_LIST_DEVICE, m_listDevice);
	DDX_Control(pDX, IDC_COMBO_DEPARTMENT, m_cboDepartment);
	DDX_Check(pDX, IDC_CHECK_LOG_TRACK, m_bLogTRACK);
	DDX_Check(pDX, IDC_CHECK_LOG_DEBUG, m_bLogDEBUG);
	DDX_Check(pDX, IDC_CHECK_LOG_ERROR, m_bLogERROR);
	DDX_Check(pDX, IDC_CHECK_LOG_MESSAGE, m_bLogMESSAGE);
	DDX_Text(pDX, IDC_EDIT_CALL_NODE, m_nCallNode);
	DDX_Text(pDX, IDC_EDIT_CALL_NAME, m_strCallName);
	DDX_Text(pDX, IDC_EDIT_CALL_CONSOLE, m_strCallConsole);
	DDX_Text(pDX, IDC_EDIT_CALL_DEVICE, m_strCallDevice);
	DDX_Text(pDX, IDC_EDIT_MZ_QUEUE, m_strMZQueue);
	DDX_Text(pDX, IDC_EDIT_ZY_QUEUE, m_strZYQueue);
	DDX_Text(pDX, IDC_EDIT_CALL_ROOM, m_strCallRoom);
	DDX_Text(pDX, IDC_EDIT_CALL_ROOMNODE, m_strCallRoomNode);
	DDX_Check(pDX, IDC_CHECK_CALL_PRIORITY, m_bCallPriority);
	DDX_Check(pDX, IDC_CHECK_CALL_ORDER, m_bCallOrder);
	DDX_Check(pDX, IDC_CHECK_CALL_CAPTURE_REPORT, m_bCallCaptureReport);
	DDX_Check(pDX, IDC_CHECK_CALL_CAPTURE, m_bCallCapture);
	DDX_Check(pDX, IDC_CHECK_CALL_REPORT, m_bCallReport);
	DDX_Check(pDX, IDC_CHECK_PRIVATE_SAVE_TO_FILE, m_bPrivateSaveToFile);
	DDX_Check(pDX, IDC_CHECK_CALL_COMPLETE, m_bCallComplete);
	DDX_Check(pDX, IDC_CHECK_CALL_RESET, m_bCallReset);
	DDX_Text(pDX, IDC_EDIT_CALL_INCREMENT, m_nCallIncrement);
	DDV_MinMaxUInt(pDX, m_nCallIncrement, 1, 100);
	DDX_Check(pDX, IDC_CHECK_CALL_CANCEL, m_bCallCancel);
	DDX_Check(pDX, IDC_CHECK_CALL_WAIT, m_bCallWait);
	DDX_Check(pDX, IDC_CHECK_AFTERNOON, m_bAfternoon);
	DDX_Text(pDX, IDC_EDIT_AFTERNOON_TIME, m_strAfternoonTime);
	DDX_Text(pDX, IDC_EDIT_AUTO_REFRESH, m_nAutoRefresh);
	DDX_Check(pDX, IDC_CHECK_CALL_UNREADY, m_bCallUnready);
	DDX_Check(pDX, IDC_CHECK_CALL_ORDER_NO_REPORT, m_bCallOrderNoReport);
	DDX_Check(pDX, IDC_CHECK_CALL_QUEUEROOM, m_bCallIQueueRoom);
	DDX_Check(pDX, IDC_CHECK_CALL_QUEUE_PATIENT_KIND, m_bCallQueuePatientKind);
	DDX_Check(pDX, IDC_CHECK_NO_POPMENU_ORDERCALL, m_bNoPopOrderCall);
	DDX_Check(pDX, IDC_CHECK_CALL_PRE, m_bCallPre);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageGeneral, CPropertyPage)
	//{{AFX_MSG_MAP(CPageGeneral)
	ON_BN_CLICKED(IDC_BUTTON_EIS_DATABASE, OnButtonEISDatabase)
	ON_CBN_SELCHANGE(IDC_COMBO_DEPARTMENT, OnSelchangeComboDepartment)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_DEVICE, OnDblclkListDevice)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageGeneral message handlers

BOOL CPageGeneral::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	this->GetDlgItem(IDC_EDIT_EIS_DATABASE)->SetWindowText(this->GetDatabaseTXT(CRunTime::GetGeneral()->m_strEISDatabase));

	this->m_listDevice.ModifyStyle(0, LVS_REPORT | LVS_SHOWSELALWAYS | LVS_SINGLESEL);
	this->m_listDevice.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP);
	this->m_listDevice.LoadSave(_T("eRadConfiguration.eRadQueueCall.Device"), FALSE, _T(""), REGISTER_LOCATION);

	BEGIN_LISTCOLUMNMAP(m_listDevice, 2)
		LISTCOLUMNMAP(IDS_DEVICE_INDEX,		100,		LVCFMT_LEFT,	ELCT_INTEGER)
		LISTCOLUMNMAP(IDS_DEVICE_NAME,		200,		LVCFMT_LEFT,	ELCT_STRING_CASE)
	END_LISTCOLUMNMAP()

	MRET rc = this->LoadDepartment();
	if (rc != ME_OK)
	{
		LOG_ERROR(LL_ERROR | LD_ALL, rc);
	}

	rc = this->LoadDevice();
	if (rc != ME_OK)
	{
		LOG_ERROR(LL_ERROR | LD_ALL, rc);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPageGeneral::OnButtonEISDatabase() 
{
	// TODO: Add your control notification handler code here

	CDataSource	dbDataSource;
	if (dbDataSource.Open() == S_OK)
	{
		BSTR bstrConnect;
		dbDataSource.GetInitializationString(&bstrConnect, TRUE);

		CRunTime::GetGeneral()->m_strEISDatabase = bstrConnect;

		this->GetDlgItem(IDC_EDIT_EIS_DATABASE)->SetWindowText(this->GetDatabaseTXT(CRunTime::GetGeneral()->m_strEISDatabase));

		MRET rc = this->LoadDepartment();
		if (rc != ME_OK)
		{
			LOG_ERROR(LL_ERROR | LD_ALL, rc);
		}

		rc = this->LoadDevice();
		if (rc != ME_OK)
		{
			LOG_ERROR(LL_ERROR | LD_ALL, rc);
		}
	}
}

void CPageGeneral::OnSelchangeComboDepartment() 
{
	// TODO: Add your control notification handler code here

	this->UpdateData();

	LONG nIndex = this->m_cboDepartment.GetCurSel();
	if (nIndex != CB_ERR)
	{
		this->m_nCallDepartment = this->m_cboDepartment.GetItemData(nIndex);
        MRET rc = this->LoadDevice();
		if (rc != ME_OK)
		{
			LOG_ERROR(LL_ERROR | LD_ALL, rc);
		}
	}
}

void CPageGeneral::OnDblclkListDevice(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	this->UpdateData();

	LONG nIndex = this->m_listDevice.GetNextItem(-1, LVNI_SELECTED);
	if (nIndex != -1)
	{
		LONG nDeviceIndex = this->m_listDevice.GetItemData(nIndex);

		CString strBuffer;
		strBuffer.Format(_T("\\%d\\"), nDeviceIndex);
		this->m_strCallDevice += strBuffer;
	}

	this->UpdateData(FALSE);

	*pResult = 0;
}

MRET CPageGeneral::LoadDepartment()
{
	this->m_cboDepartment.ResetContent();

	if (!CRunTime::GetGeneral()->m_strEISDatabase.IsEmpty())
	{
		COleSession dbSession;
		COleSession* pSession = CRunTime::GetEISSession(&dbSession);
		if (pSession == NULL)
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_SESSION);
		}

		CdboMGRDepartment dboDepartment;
		dboDepartment.SetDataSource(pSession);
		if (FAILED(dboDepartment.Open()))
		{
			LOG_RET_ERROR(LL_ERROR | LD_FILE, ME_ERR_DB_OPEN_TABLE);
		}

		while (dboDepartment.MoveNext() == S_OK)
		{
			CString strBuffer;
			strBuffer.Format(_T("%s  (%d)"), dboDepartment.m_DepartmentName, dboDepartment.m_DepartmentIndex);
			LONG nIndex = this->m_cboDepartment.AddString(strBuffer);
			this->m_cboDepartment.SetItemData(nIndex, dboDepartment.m_DepartmentIndex);

			if (this->m_nCallDepartment == dboDepartment.m_DepartmentIndex)
				this->m_cboDepartment.SetCurSel(nIndex);
		}

		dboDepartment.Close();
	}

	return ME_OK;
}

MRET CPageGeneral::LoadDevice()
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
		strFilter.Format(_T("WHERE DeviceDepartment = %d"), this->m_nCallDepartment);

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

CString CPageGeneral::GetDatabaseTXT(CString strConnect)
{
	CString strTXT;

	if (!strConnect.IsEmpty())
	{
		LONG nPos = 0;

		nPos = strConnect.Find(_T("Data Source="));
		if (nPos > 0)
		{
			nPos += 12;
			strTXT += _T(" DBS:");
			strTXT += strConnect.Mid(nPos, strConnect.Find(_T(";"), nPos) - nPos + 1);
		}

		nPos = strConnect.Find(_T("User ID="));
		if (nPos > 0)
		{
			nPos += 8;
			strTXT += _T(" USER:");
			strTXT += strConnect.Mid(nPos, strConnect.Find(_T(";"), nPos) - nPos + 1);
		}

		nPos = strConnect.Find(_T("Initial Catalog="));
		if (nPos > 0)
		{
			nPos += 16;
			strTXT += _T(" DB:");
			strTXT += strConnect.Mid(nPos, strConnect.Find(_T(";"), nPos) - nPos + 1);
		}
	}

	strTXT.TrimLeft();

	return strTXT;
}
