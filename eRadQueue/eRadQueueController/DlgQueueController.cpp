// DlgQueueController.cpp : implementation file
//

#include "stdafx.h"
#include "eRadQueueController.h"
#include "DlgQueueController.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgQueueController dialog


CDlgQueueController::CDlgQueueController(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgQueueController::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgQueueController)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	this->m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	InitializeCriticalSection(&this->m_CriticalSection);

	memset(&this->m_pDlgController, 0, sizeof(this->m_pDlgController));
}


void CDlgQueueController::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgQueueController)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgQueueController, CDialog)
	//{{AFX_MSG_MAP(CDlgQueueController)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_HIDE, OnButtonHide)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, OnButtonExit)
	ON_COMMAND(IDM_SHOW_HIDE, OnShowHide)
	ON_COMMAND(IDM_EXIT, OnExit)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_TRAY_ICON, OnTrayIcon)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgQueueController message handlers

BOOL CDlgQueueController::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	this->SetIcon(m_hIcon, TRUE);
	this->SetIcon(m_hIcon, FALSE);

	NOTIFYICONDATA TRAYICON;
	memset(&TRAYICON, 0, sizeof(NOTIFYICONDATA));
	TRAYICON.cbSize				= (DWORD) sizeof(NOTIFYICONDATA);
	TRAYICON.hWnd				= this->m_hWnd;
	TRAYICON.uID				= IDR_MAINFRAME;
	TRAYICON.uFlags				= NIF_ICON | NIF_MESSAGE | NIF_TIP;
	TRAYICON.uCallbackMessage	= WM_TRAY_ICON;
	TRAYICON.hIcon				= this->m_hIcon;

	CString strTitle;
	this->GetWindowText(strTitle);
	strcpy(TRAYICON.szTip, strTitle);

	Shell_NotifyIcon(NIM_ADD, &TRAYICON);

	OBPOS POS = NULL;
	CRunTime::CITEMController* IT = CRunTime::GetLstController()->GetHead(POS);
	for (LONG i = 0; (i < MAX_CONTROLLER_COUNT) && (IT != NULL); i++, IT = CRunTime::GetLstController()->GetNext(POS))
	{
		switch (IT->m_nControllerMode)
		{
		case EC_MODE0_GENERAL:
			this->m_pDlgController[i] = new CDlgControllerMode0;
			break;
		case EC_MODE1_REPORT:
			this->m_pDlgController[i] = new CDlgControllerMode1;
			break;
		case EC_MODE2_SINGLE_QUEUE:
			this->m_pDlgController[i] = new CDlgControllerMode2;
			break;
		case EC_MODE3_SINGLE_QUEUE_SHOWALL:
			this->m_pDlgController[i] = new CDlgControllerMode3;
			break;
		}

		this->m_pDlgController[i]->m_pParent = this;
		this->m_pDlgController[i]->m_pController = IT;
		this->m_pDlgController[i]->Create(CDlgController::IDD,	this);

		this->m_pDlgController[i]->ShowWindow(SW_SHOW);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgQueueController::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CDlgQueueController::OnCancel() 
{
	// TODO: Add extra cleanup here
	
//	CDialog::OnCancel();
}

void CDlgQueueController::OnClose() 
{
	// TODO: Add your message handler code here and/or call default

	CString strTitle, strText;
	this->GetWindowText(strTitle);
	strText.LoadString(IDS_CONFIRM_CLOSE);
	if ((this->MessageBox(strText, strTitle, MB_OKCANCEL | MB_ICONEXCLAMATION)) != IDOK)
		return;

	CDialog::OnOK();

//	CDialog::OnClose();
}

void CDlgQueueController::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here

	NOTIFYICONDATA TRAYICON;
	memset(&TRAYICON, 0, sizeof(NOTIFYICONDATA));
	TRAYICON.cbSize	= (DWORD) sizeof(NOTIFYICONDATA);
	TRAYICON.hWnd	= this->m_hWnd;
	TRAYICON.uID	= IDR_MAINFRAME;

	Shell_NotifyIcon(NIM_DELETE, &TRAYICON);

	for (LONG i = 0; i < MAX_CONTROLLER_COUNT; i++)
	{
		if (this->m_pDlgController[i] != NULL)
		{
			this->m_pDlgController[i]->DestroyWindow();

			delete this->m_pDlgController[i];
			this->m_pDlgController[i] = NULL;
		}
	}

	DeleteCriticalSection(&this->m_CriticalSection);
}

HBRUSH CDlgQueueController::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

void CDlgQueueController::OnButtonHide() 
{
	// TODO: Add your control notification handler code here

	this->ShowWindow(SW_HIDE);
}

void CDlgQueueController::OnButtonExit() 
{
	// TODO: Add your control notification handler code here

	this->PostMessage(WM_CLOSE);
}

void CDlgQueueController::OnShowHide() 
{
	// TODO: Add your command handler code here

	this->ShowWindow((this->IsWindowVisible()) ? SW_HIDE : SW_SHOW);
}

void CDlgQueueController::OnExit() 
{
	// TODO: Add your command handler code here

	this->PostMessage(WM_CLOSE);
}

void CDlgQueueController::OnTrayIcon(WPARAM wParam, LPARAM lParam)
{
	switch (lParam)
	{
	case WM_RBUTTONDOWN:
		{
			CMenu menu;
			if (menu.LoadMenu(IDR_MENU_TRAY_ICON))
			{
				CMenu* pSubMenu = menu.GetSubMenu(0);
				if (this->IsWindowVisible())
				{
					CString strMenu;
					this->GetDlgItem(IDC_BUTTON_HIDE)->GetWindowText(strMenu);
					menu.ModifyMenu(IDM_SHOW_HIDE, MF_BYCOMMAND, IDM_SHOW_HIDE, strMenu);
				}
				
				CPoint pt;
				::GetCursorPos(&pt);
				
				pSubMenu->TrackPopupMenu(0, pt.x, pt.y, this);
			}
		}
		break;

	case WM_LBUTTONDBLCLK:
	case WM_LBUTTONDOWN:
		this->ShowWindow(SW_SHOW);
		break;
	}
}
