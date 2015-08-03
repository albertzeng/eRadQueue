// DlgLogin.cpp : implementation file
//

#include "stdafx.h"
#include "ERadQueueController.h"
#include "DlgLogin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgLogin dialog

CDlgLogin::CDlgLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgLogin)
	m_strCode = _T("");
	m_strDepartment = _T("");
	m_strName = _T("");
	m_strPassword = _T("");
	//}}AFX_DATA_INIT

	this->m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	this->m_nDoctorIndex		= 0;
	this->m_nDoctorPrivilege	= 0;
	this->m_nDoctorDepartment	= 0;
}


void CDlgLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgLogin)
	DDX_Control(pDX, IDC_BUTTON_LOGIN, m_ibLogin);
	DDX_Text(pDX, IDC_EDIT_CODE, m_strCode);
	DDX_Text(pDX, IDC_EDIT_DEPARTMENT, m_strDepartment);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgLogin, CDialog)
	//{{AFX_MSG_MAP(CDlgLogin)
	ON_EN_KILLFOCUS(IDC_EDIT_CODE, OnKillfocusEditCode)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, OnButtonLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgLogin message handlers

BOOL CDlgLogin::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CRect recClient;
	this->GetClientRect(&recClient);

	this->m_strCode = CRunTime::GetUser()->m_strDoctorCode;

	this->UpdateData(FALSE);

	HBITMAP hBitmap = (HBITMAP) LoadImage(NULL, _T("InterFace\\Login.bmp"), IMAGE_BITMAP, 420, 280, LR_LOADFROMFILE);
	if (hBitmap == NULL)
	{
		LOG_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_RESERVED, GetLastError());
	}

	CStatic* pCtrl = (CStatic*) this->GetDlgItem(IDC_STATIC_LOGIN);
	pCtrl->SetBitmap(hBitmap);
	pCtrl->SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE);
	pCtrl->MoveWindow(&recClient);

//	SET_IMAGEBOX_PARAMETER(this->m_ibLogin, 1, 48, 48, _T("InterFace\\Login-1.ico"), _T("InterFace\\Login-2.ico"), _T("InterFace\\Login-3.ico"));

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgLogin::OnOK() 
{
	// TODO: Add extra validation here
	
	CWnd* pCtrl = this->GetFocus();
	switch (pCtrl->GetDlgCtrlID())
	{
	case (IDC_EDIT_PASSWORD):
		this->OnButtonLogin();
		return;

	default:
		this->GetNextDlgTabItem(pCtrl)->SetFocus();
		return;
	}

	CDialog::OnOK();
}

void CDlgLogin::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CDlgLogin::OnKillfocusEditCode() 
{
	// TODO: Add your control notification handler code here
	
	this->UpdateData();

	COleSession dbSession;
	COleSession* pSession = CRunTime::GetEISSession(&dbSession);
	if (pSession == NULL)
	{
		LOG_ERROR(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_SESSION);
		return;
	}

	CString strFilter;
	strFilter.Format(_T("WHERE DoctorCode = '%s' AND DoctorDisable = 0"), this->m_strCode);

	CdbovMGRDoctor dbovDoctor;
	dbovDoctor.SetDataSource(pSession);
	if (FAILED(dbovDoctor.Open(strFilter)))
	{
		LOG_ERROR(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_TABLE);
		return;
	}

	if (dbovDoctor.MoveNext() != S_OK)
	{
		this->m_strName				= _T("");
		this->m_strDepartment		= _T("");

		this->m_nDoctorIndex		= 0;
		this->m_nDoctorDepartment	= 0;
		this->m_nDoctorPrivilege	= 0;
		this->m_strDoctorPassword	= _T("");
	}
	else
	{
		this->m_strName				= dbovDoctor.m_DoctorName;
		this->m_strDepartment		= dbovDoctor.m_DepartmentName;

		this->m_nDoctorIndex		= dbovDoctor.m_DoctorIndex;
		if (dbovDoctor.m_DoctorDepartmentExamine == 0)
			this->m_nDoctorDepartment	= dbovDoctor.m_DoctorDepartment;
		else
			this->m_nDoctorDepartment	= dbovDoctor.m_DoctorDepartmentExamine;
		this->m_nDoctorPrivilege	= dbovDoctor.m_DoctorPrivilege;

		CString strEncoded(dbovDoctor.m_DoctorPassword);

		CToolsEx::Decode(strEncoded, this->m_strDoctorPassword);
	}

	dbovDoctor.Close();

	this->UpdateData(FALSE);
}

void CDlgLogin::OnButtonLogin() 
{
	// TODO: Add your control notification handler code here
	
	this->UpdateData();

	CRunTime::GetUser()->m_nDoctorPrivilege = this->m_nDoctorPrivilege;

	if (this->m_nDoctorIndex == 0)
	{
		AfxMessageBox(IDS_ERROR_DOCTOR_CODE, MB_OK | MB_ICONERROR);

		this->GetDlgItem(IDC_EDIT_CODE)->SetFocus();
		((CEdit*) this->GetDlgItem(IDC_EDIT_CODE))->SetSel(0, -1);
	}
	else if ((this->m_strPassword.GetLength() == 0) || (this->m_strDoctorPassword != this->m_strPassword))
	{
		AfxMessageBox(IDS_ERROR_DOCTOR_PASSWORD, MB_OK | MB_ICONERROR);

		this->GetDlgItem(IDC_EDIT_PASSWORD)->SetFocus();
		((CEdit*) this->GetDlgItem(IDC_EDIT_PASSWORD))->SetSel(0, -1);
	}
	else if (!(PRIVILEGE_ADMINISTRATION | PRIVILEGE_REGISTER | PRIVILEGE_PERFORMER | PRIVILEGE_PACS))
	{
		AfxMessageBox(IDS_ERROR_NO_PRIVILEGE, MB_OK | MB_ICONERROR);

		this->GetDlgItem(IDC_EDIT_CODE)->SetFocus();
		((CEdit*) this->GetDlgItem(IDC_EDIT_CODE))->SetSel(0, -1);
	}
	else
	{
		CRunTime::GetUser()->m_nDoctorIndex			= this->m_nDoctorIndex;
		CRunTime::GetUser()->m_nDoctorDepartment	= this->m_nDoctorDepartment;
		CRunTime::GetUser()->m_nDoctorPrivilege		= this->m_nDoctorPrivilege;
		CRunTime::GetUser()->m_strDoctorCode		= this->m_strCode;
		CRunTime::GetUser()->m_strDoctorName		= this->m_strName;
		CRunTime::GetUser()->m_strDoctorPassword	= this->m_strDoctorPassword;
		CRunTime::GetUser()->m_strDepartmentName	= this->m_strDepartment;

		CString strMessage;
		strMessage.Format(_T("LOG IN: Code: %s, Name: %s, Department: %s"), CRunTime::GetUser()->m_strDoctorCode, CRunTime::GetUser()->m_strDoctorName, CRunTime::GetUser()->m_strDepartmentName);
		LOG_MESSAGE(LL_DEBUG | LD_FILE, strMessage);

		char lpModule[_MAX_PATH];
		::GetModuleFileName(NULL, lpModule, sizeof(lpModule));

		char lpDrive[_MAX_PATH], lpDir[_MAX_PATH];
		::_splitpath(lpModule, lpDrive, lpDir, NULL, NULL);

		strcat(lpDrive, lpDir);
		::SetCurrentDirectory(lpDrive);
/*
		CRunTime::GetUser()->m_strPrivateSaveToFile.Format(_T("%sINI\\%s%s"), lpDrive, this->m_strCode, _T(".ini"));

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
*/
		CRunTime::ExchangePublic(TRUE);
		CRunTime::ExchangePrivate();

		CDialog::OnOK();
	}
}

MRET CDlgLogin::AutoLogin(CString strDoctorCode)
{
	COleSession dbSession;
	COleSession* pSession = CRunTime::GetEISSession(&dbSession);
	if (pSession == NULL)
	{
		LOG_RET_ERROR(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_SESSION);
	}

	CString strFilter;
	strFilter.Format(_T("WHERE DoctorCode = '%s' AND DoctorDisable = 0"), strDoctorCode);

	CdbovMGRDoctor dbovDoctor;
	dbovDoctor.SetDataSource(pSession);
	if (FAILED(dbovDoctor.Open(strFilter)))
	{
		LOG_RET_ERROR(LL_ERROR | LD_ALL, ME_ERR_DB_OPEN_TABLE);
	}

	if (dbovDoctor.MoveNext() != S_OK)
	{
		dbovDoctor.Close();
		AfxMessageBox(IDS_ERROR_AUTO_LOGIN_CODE, MB_OK | MB_ICONERROR);
		LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_DB_FIND_RECORD, strFilter);
	}
/*
	if (dbovDoctor.m_DoctorPrivilege & OP_PASSWORD)
	{
		AfxMessageBox(IDS_ERROR_AUTO_LOGIN_PASSWORD, MB_OK | MB_ICONERROR);

		LOG_RET_ERROR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_RESERVED, strFilter);
	}
*/
	CRunTime::GetUser()->m_nDoctorIndex			= dbovDoctor.m_DoctorIndex;
	CRunTime::GetUser()->m_nDoctorDepartment	= dbovDoctor.m_DoctorDepartment;
	CRunTime::GetUser()->m_nDoctorPrivilege		= dbovDoctor.m_DoctorPrivilege & (~OP_PASSWORD);
	CRunTime::GetUser()->m_strDoctorCode		= dbovDoctor.m_DoctorCode;
	CRunTime::GetUser()->m_strDoctorName		= dbovDoctor.m_DoctorName;
	CRunTime::GetUser()->m_strDepartmentName	= dbovDoctor.m_DepartmentName;

	CString strEncoded(dbovDoctor.m_DoctorPassword);

	CToolsEx::Decode(strEncoded, CRunTime::GetUser()->m_strDoctorPassword);

	dbovDoctor.Close();

	CString strMessage;
	strMessage.Format(_T("LOG IN: Code: %s, Name: %s, Department: %s"), CRunTime::GetUser()->m_strDoctorCode, CRunTime::GetUser()->m_strDoctorName, CRunTime::GetUser()->m_strDepartmentName);
	LOG_MESSAGE(LL_DEBUG | LD_FILE, strMessage);

	char lpModule[_MAX_PATH];
	::GetModuleFileName(NULL, lpModule, sizeof(lpModule));

	char lpDrive[_MAX_PATH], lpDir[_MAX_PATH];
	::_splitpath(lpModule, lpDrive, lpDir, NULL, NULL);

	strcat(lpDrive, lpDir);
	::SetCurrentDirectory(lpDrive);

/*	CRunTime::GetUser()->m_strPrivateSaveToFile.Format(_T("%sINI\\%s%s"), lpDrive, strDoctorCode, _T(".ini"));

	if (CRunTime::GetGeneral()->m_bPrivateSaveToFile)
	{
		FILE* file = fopen(CRunTime::GetUser()->m_strPrivateSaveToFile, _T("a"));
		if (file != NULL)                       //20100601?
			fclose(file);
		else
		{
			LOG_ERROR_MINOR_MESSAGE(LL_ERROR | LD_FILE, ME_ERR_OPEN_FILE, ::GetLastError(), CRunTime::GetUser()->m_strPrivateSaveToFile);
		}
	}
*/
	CRunTime::ExchangePrivate();

	return ME_OK;
}
