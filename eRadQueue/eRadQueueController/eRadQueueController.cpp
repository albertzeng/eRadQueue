// eRadQueueController.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "eRadQueueController.h"
#include "eRadQueueControllerDlg.h"
#include <initguid.h>
#include "ERadQueueController_i.c"
#include "DlgLogin.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CeRadQueueController

BEGIN_MESSAGE_MAP(CeRadQueueController, CWinApp)
	//{{AFX_MSG_MAP(CeRadQueueController)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CeRadQueueController construction

CeRadQueueController::CeRadQueueController()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CeRadQueueController object

CeRadQueueController theApp;

/////////////////////////////////////////////////////////////////////////////
// CeRadQueueController initialization

BOOL CeRadQueueController::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	if (!InitATL())
		return FALSE;

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Parse the command line to see if launched as OLE server
	if (RunEmbedded() || RunAutomated())
	{
		// Register all OLE server (factories) as running.  This enables the
		//  OLE libraries to create objects from other applications.
		COleTemplateServer::RegisterAll();
	_Module.RegisterClassObjects(CLSCTX_LOCAL_SERVER, 
		REGCLS_MULTIPLEUSE);

	}
	else
	{
		// When a server application is launched stand-alone, it is a good idea
		//  to update the system registry in case it has been damaged.
		COleObjectFactory::UpdateRegistryAll();
	}

	char lpModule[_MAX_PATH];
	::GetModuleFileName(NULL, lpModule, sizeof(lpModule));

	char lpDrive[_MAX_PATH], lpDir[_MAX_PATH];
	::_splitpath(lpModule, lpDrive, lpDir, NULL, NULL);

	strcat(lpDrive, lpDir);
	::SetCurrentDirectory(lpDrive);

	CLOG::SetParameter(LL_MASK);
	MRET rc = CLOG::Initialize();
	if (rc != ME_OK)
	{
		AfxMessageBox(IDS_ERROR_LOG_INITIALIZE, MB_OK | MB_ICONERROR);
		LOG_ERROR(LL_ERROR | LD_FILE, rc);
		return FALSE;
	}

	rc = CRunTime::Load();
	if (rc != ME_OK)
	{
		AfxMessageBox(IDS_ERROR_LOAD_CONFIGURATION, MB_OK | MB_ICONERROR);
		LOG_ERROR(LL_ERROR | LD_FILE, rc);
		return FALSE;
	}

	CLOG::SetParameter(CRunTime::GetLogLevel());


	//20110509  begin  login
	if (!CRunTime::GetGeneral()->m_bAutoLogin)
	{
		CDlgLogin dlgLogin;
		if (dlgLogin.DoModal() != IDOK)
			return FALSE;
	}
	else
	{
		rc = CDlgLogin::AutoLogin(CRunTime::GetGeneral()->m_strAutoDoctorCode);
		if (rc != ME_OK)
			return FALSE;
	}
   //20110509 end
	
	CDlgQueueController dlgQueueController;
	this->m_pMainWnd = &dlgQueueController;
	dlgQueueController.DoModal();

//	CeRadQueueControllerDlg dlg;
//	m_pMainWnd = &dlg;
//	int nResponse = dlg.DoModal();
//	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
//	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

	
CERadQueueControllerModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
END_OBJECT_MAP()

LONG CERadQueueControllerModule::Unlock()
{
	AfxOleUnlockApp();
	return 0;
}

LONG CERadQueueControllerModule::Lock()
{
	AfxOleLockApp();
	return 1;
}


int CeRadQueueController::ExitInstance()
{
	if (m_bATLInited)
	{
		_Module.RevokeClassObjects();
		_Module.Term();
	}

	return CWinApp::ExitInstance();

}

BOOL CeRadQueueController::InitATL()
{
	m_bATLInited = TRUE;

	_Module.Init(ObjectMap, AfxGetInstanceHandle());
	_Module.dwThreadID = GetCurrentThreadId();

	return TRUE;

}
