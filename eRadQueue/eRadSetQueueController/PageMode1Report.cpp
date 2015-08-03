// PageMode1Report.cpp : implementation file
//

#include "stdafx.h"
#include "eRadSetQueueController.h"
#include "PageMode1Report.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPageMode1Report property page

IMPLEMENT_DYNCREATE(CPageMode1Report, CPropertyPage)

CPageMode1Report::CPageMode1Report() : CPropertyPage(CPageMode1Report::IDD)
{
	//{{AFX_DATA_INIT(CPageMode1Report)
	m_nMode1TimeRange = 0;
	m_nMode1TimeDelay = 0;
	m_nMode1RefreshIdle = 0;
	m_nMode1RefreshScreen = 0;
	m_nMode1OrderMode = 0;
	//}}AFX_DATA_INIT

	this->m_pController = NULL;
}

CPageMode1Report::~CPageMode1Report()
{
}

void CPageMode1Report::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageMode1Report)
	DDX_Control(pDX, IDC_COMBO_MODE1_EXCLUDE_OUT_STATUS, m_cboMode1ExcludeOutStatus);
	DDX_Control(pDX, IDC_COMBO_MODE1_ADMISSION_SOURCE, m_cboMode1AdmissionSource);
	DDX_Control(pDX, IDC_COMBO_MODE1_SOURCE_HOSPITAL, m_cboMode1SourceHospital);
	DDX_Text(pDX, IDC_EDIT_MODE1_TIME_RANGE, m_nMode1TimeRange);
	DDV_MinMaxUInt(pDX, m_nMode1TimeRange, 2, 100000);
	DDX_Text(pDX, IDC_EDIT_MODE1_TIME_DELAY, m_nMode1TimeDelay);
	DDV_MinMaxUInt(pDX, m_nMode1TimeDelay, 0, 100000);
	DDX_Text(pDX, IDC_EDIT_MODE1_REFRESH_IDLE, m_nMode1RefreshIdle);
	DDX_Text(pDX, IDC_EDIT_MODE1_REFRESH_SCREEN, m_nMode1RefreshScreen);
	DDX_CBIndex(pDX, IDC_COMBO_MODE1_ORDER_MODE, m_nMode1OrderMode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageMode1Report, CPropertyPage)
	//{{AFX_MSG_MAP(CPageMode1Report)
	ON_CBN_SELCHANGE(IDC_COMBO_MODE1_ADMISSION_SOURCE, OnSelchangeComboMode1AdmissionSource)
	ON_CBN_SELCHANGE(IDC_COMBO_MODE1_EXCLUDE_OUT_STATUS, OnSelchangeComboMode1ExcludeOutStatus)
	ON_CBN_SELCHANGE(IDC_COMBO_MODE1_SOURCE_HOSPITAL, OnSelchangeComboMode1SourceHospital)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageMode1Report message handlers

BOOL CPageMode1Report::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here

	for (UINT i = 0; i < CToolsEx::GetAdmissionSourceTXT()->GetSize() - 1; i++)
	{
		LONG nIndex = this->m_cboMode1AdmissionSource.AddString(CToolsEx::GetAdmissionSourceTXT()->GetValue(i));
		this->m_cboMode1AdmissionSource.SetItemData(nIndex, CToolsEx::GetAdmissionSourceTXT()->GetKey(i));
	}

	this->m_cboMode1AdmissionSource.LoadSave(_T("eRadConfiguration.eRadSetQueueController.AdmissionSource"), FALSE, _T(""), REGISTER_LOCATION);
	this->m_cboMode1AdmissionSource.SelectAll();

	for (i = 0; i < this->m_cboMode1AdmissionSource.GetCount(); i++)
	{
		CString strBuffer;
		strBuffer.Format(_T("\\%d\\"), this->m_cboMode1AdmissionSource.GetItemData(i));

		if (this->m_pController->m_strMode1AdmissionSource.Find(strBuffer, 0) != -1)
			this->m_cboMode1AdmissionSource.SetCheck(i, TRUE);
	}

	for (i = 0; i < CToolsEx::GetReportsOutStatus()->GetSize(); i++)
	{
		LONG nIndex = this->m_cboMode1ExcludeOutStatus.AddString(CToolsEx::GetReportsOutStatus()->GetValue(i));
		this->m_cboMode1ExcludeOutStatus.SetItemData(nIndex, CToolsEx::GetReportsOutStatus()->GetKey(i));
	}

	this->m_cboMode1ExcludeOutStatus.LoadSave(_T("eRadConfiguration.eRadSetQueueController.ExcludeOutStatus"), FALSE, _T(""), REGISTER_LOCATION);
	this->m_cboMode1ExcludeOutStatus.SelectAll();

	for (i = 0; i < this->m_cboMode1ExcludeOutStatus.GetCount(); i++)
	{
		CString strBuffer;
		strBuffer.Format(_T("\\%d\\"), this->m_cboMode1ExcludeOutStatus.GetItemData(i));

		if (this->m_pController->m_strMode1ExcludeOutStatus.Find(strBuffer, 0) != -1)
			this->m_cboMode1ExcludeOutStatus.SetCheck(i, TRUE);
	}

	COleSession dbSession;
	COleSession *pSession = CRunTime::GetEISSession(&dbSession);
	if (pSession == NULL)			
	{
		LOG_ERROR(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_SESSION);
		return FALSE;
	}

	CdboMGRHospital dboHospital;
	dboHospital.SetDataSource(pSession);
	
	CString strFilter;
	strFilter.Format("WHERE 1=1");
	if (FAILED(dboHospital.Open(strFilter)))
	{
		LOG_ERROR_MESSAGE(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_TABLE, "TBL: 'MGRHospital'.");
		return FALSE;
	}
	while (dboHospital.MoveNext() == S_OK)
	{
		this->m_cboMode1SourceHospital.AddString(dboHospital.m_HospitalName);
	}	
	this->m_cboMode1SourceHospital.LoadSave(_T("eRadConfiguration.eRadSetQueueController.AdmissionSourceHospital"), TRUE, _T(""), REGISTER_LOCATION);
	this->m_cboMode1SourceHospital.SelectAll();

	for (i = 0; i < this->m_cboMode1SourceHospital.GetCount(); i++)
	{
		CString strBuffer, strTXT;
		this->m_cboMode1SourceHospital.GetLBText(i, strTXT);
		strBuffer.Format(_T("\\%s\\"), strTXT);
		
		if (this->m_pController->m_strMode1SourceHospital.Find(strBuffer, 0) != -1)
			this->m_cboMode1SourceHospital.SetCheck(i, TRUE);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPageMode1Report::OnSelchangeComboMode1AdmissionSource() 
{
	// TODO: Add your control notification handler code here

	this->m_pController->m_strMode1AdmissionSource.Empty();
	if (this->m_cboMode1AdmissionSource.GetSelectCount() > 0)
	{
		for (LONG i = 0; i < this->m_cboMode1AdmissionSource.GetCount(); i++)
		{
			if (this->m_cboMode1AdmissionSource.GetCheck(i))
			{
				CString strBuffer;
				strBuffer.Format(_T("\\%d\\"), this->m_cboMode1AdmissionSource.GetItemData(i));
				this->m_pController->m_strMode1AdmissionSource += strBuffer;
			}
		}
	}
}

void CPageMode1Report::OnSelchangeComboMode1ExcludeOutStatus() 
{
	// TODO: Add your control notification handler code here

	this->m_pController->m_strMode1ExcludeOutStatus.Empty();
	if (this->m_cboMode1ExcludeOutStatus.GetSelectCount() > 0)
	{
		for (LONG i = 0; i < this->m_cboMode1ExcludeOutStatus.GetCount(); i++)
		{
			if (this->m_cboMode1ExcludeOutStatus.GetCheck(i))
			{
				CString strBuffer;
				strBuffer.Format(_T("\\%d\\"), this->m_cboMode1ExcludeOutStatus.GetItemData(i));
				this->m_pController->m_strMode1ExcludeOutStatus += strBuffer;
			}
		}
	}
}

void CPageMode1Report::OnSelchangeComboMode1SourceHospital() 
{
	// TODO: Add your control notification handler code here
	this->m_pController->m_strMode1SourceHospital.Empty();
	if (this->m_cboMode1SourceHospital.GetSelectCount() > 0)
	{
		for (LONG i = 0; i < this->m_cboMode1SourceHospital.GetCount(); i++)
		{
			if (this->m_cboMode1SourceHospital.GetCheck(i))
			{
				CString strBuffer, strTXT;
				this->m_cboMode1SourceHospital.GetLBText(i, strTXT);
				strBuffer.Format(_T("\\%s\\"), strTXT);
				this->m_pController->m_strMode1SourceHospital += strBuffer;
			}
		}
	}
}
