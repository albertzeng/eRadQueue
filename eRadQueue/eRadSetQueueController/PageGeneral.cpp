// PageGeneral.cpp : implementation file
//

#include "stdafx.h"
#include "eRadSetQueueController.h"
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
	m_nVoiceRate = 0;
	m_nVoiceVolume = 0;
	m_strVoicePlay = _T("");
	m_bAutoLogin = FALSE;
	m_strAutoDoctorCode = _T("");
	m_bHideName = FALSE;
	//}}AFX_DATA_INIT
}

CPageGeneral::~CPageGeneral()
{
}

void CPageGeneral::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageGeneral)
	DDX_Control(pDX, IDC_COMBO_VOICE_CLASS, m_cboVoiceClass);
	DDX_Control(pDX, IDC_COMBO_DEPARTMENT, m_cboDepartment);
	DDX_Check(pDX, IDC_CHECK_LOG_TRACK, m_bLogTRACK);
	DDX_Check(pDX, IDC_CHECK_LOG_DEBUG, m_bLogDEBUG);
	DDX_Check(pDX, IDC_CHECK_LOG_ERROR, m_bLogERROR);
	DDX_Check(pDX, IDC_CHECK_LOG_MESSAGE, m_bLogMESSAGE);
	DDX_Text(pDX, IDC_EDIT_VOICE_RATE, m_nVoiceRate);
	DDV_MinMaxLong(pDX, m_nVoiceRate, -500, 500);
	DDX_Text(pDX, IDC_EDIT_VOICE_VOLUME, m_nVoiceVolume);
	DDV_MinMaxLong(pDX, m_nVoiceVolume, -20, 100);
	DDX_Text(pDX, IDC_EDIT_VOICE_PLAY, m_strVoicePlay);
	DDX_Check(pDX, IDC_CHECK_AUTO_LOGIN, m_bAutoLogin);
	DDX_Check(pDX, IDC_CHECK_HIDE_NAME, m_bHideName);
	DDX_Text(pDX, IDC_EDIT_AUTO_DOCTOR_CODE, m_strAutoDoctorCode);

	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageGeneral, CPropertyPage)
	//{{AFX_MSG_MAP(CPageGeneral)
	ON_BN_CLICKED(IDC_BUTTON_EIS_DATABASE, OnButtonEISDatabase)
	ON_CBN_SELCHANGE(IDC_COMBO_DEPARTMENT, OnSelchangeComboDepartment)
	ON_CBN_SELCHANGE(IDC_COMBO_VOICE_CLASS, OnSelchangeComboVoiceClass)
	ON_BN_CLICKED(IDC_BUTTON_VOICE_PLAY, OnButtonVoicePlay)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageGeneral message handlers

BOOL CPageGeneral::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	this->GetDlgItem(IDC_EDIT_EIS_DATABASE)->SetWindowText(this->GetDatabaseTXT(CRunTime::GetGeneral()->m_strEISDatabase));

	MRET rc = this->LoadDepartment();
	if (rc != ME_OK)
	{
		LOG_ERROR(LL_ERROR | LD_ALL, rc);
	}

	CStringArray aVoiceClass;
	this->m_ModuleTTS.GetVoiceList(&aVoiceClass);
	
	LONG nIndex;
	for (LONG i = 0; i < aVoiceClass.GetSize(); i++)
		nIndex = this->m_cboVoiceClass.AddString(aVoiceClass.ElementAt(i));

	CString strVoiceDescription;
	if (this->m_cboVoiceClass.GetCount() > CRunTime::GetGeneral()->m_nVoiceClass)
		this->m_cboVoiceClass.GetLBText(CRunTime::GetGeneral()->m_nVoiceClass, strVoiceDescription);
	if (!strVoiceDescription.IsEmpty() && strVoiceDescription == CRunTime::GetGeneral()->m_strVoiceDescription)
		this->m_cboVoiceClass.SetCurSel(CRunTime::GetGeneral()->m_nVoiceClass);
	else
	{
		for (i = 0; i < this->m_cboVoiceClass.GetCount(); i++)
		{
			this->m_cboVoiceClass.GetLBText(i, strVoiceDescription);
			if (strVoiceDescription == CRunTime::GetGeneral()->m_strVoiceDescription)
			{
				this->m_cboVoiceClass.SetCurSel(i);
				CRunTime::GetGeneral()->m_nVoiceClass = i;
			}
		}
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
	}
}

void CPageGeneral::OnButtonVoicePlay() 
{
	// TODO: Add your control notification handler code here

	this->UpdateData();

	this->m_ModuleTTS.SpeakText(this->m_strVoicePlay, this->m_nVoiceRate, this->m_nVoiceVolume, CRunTime::GetGeneral()->m_nVoiceClass, CRunTime::GetGeneral()->m_strVoiceDescription);

	this->UpdateData();
}

void CPageGeneral::OnSelchangeComboDepartment() 
{
	// TODO: Add your control notification handler code here

	this->UpdateData();

	LONG nIndex = this->m_cboDepartment.GetCurSel();
	if (nIndex != CB_ERR)
		CRunTime::GetGeneral()->m_nUseDepartment = this->m_cboDepartment.GetItemData(nIndex);
}

void CPageGeneral::OnSelchangeComboVoiceClass() 
{
	// TODO: Add your control notification handler code here
	
	LONG nIndex = this->m_cboVoiceClass.GetCurSel();
	if (nIndex == CB_ERR)
		return;

	CRunTime::GetGeneral()->m_nVoiceClass = nIndex;
	this->m_cboVoiceClass.GetLBText(nIndex, CRunTime::GetGeneral()->m_strVoiceDescription);
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

			if (CRunTime::GetGeneral()->m_nUseDepartment == dboDepartment.m_DepartmentIndex)
				this->m_cboDepartment.SetCurSel(nIndex);
		}

		dboDepartment.Close();
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
