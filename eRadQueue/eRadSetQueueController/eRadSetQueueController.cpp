// eRadSetQueueController.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "eRadSetQueueController.h"
#include <initguid.h>
#include "ERadSetQueueController_i.c"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CERadSetQueueControllerApp

BEGIN_MESSAGE_MAP(CERadSetQueueControllerApp, CWinApp)
	//{{AFX_MSG_MAP(CERadSetQueueControllerApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CERadSetQueueControllerApp construction

CERadSetQueueControllerApp::CERadSetQueueControllerApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CERadSetQueueControllerApp object

CERadSetQueueControllerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CERadSetQueueControllerApp initialization

BOOL CERadSetQueueControllerApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	// Register all OLE server (factories) as running.  This enables the
	//  OLE libraries to create objects from other applications.
	COleObjectFactory::RegisterAll();
	if (!InitATL())
		return FALSE;


	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// Special entry points required for inproc servers

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (SUCCEEDED(_Module.GetClassObject(rclsid, riid, ppv)))
		return S_OK;


	return AfxDllGetClassObject(rclsid, riid, ppv);
}

STDAPI DllCanUnloadNow(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return (AfxDllCanUnloadNow()==S_OK && _Module.GetLockCount()==0) ? S_OK : S_FALSE;

	return AfxDllCanUnloadNow();
}

// by exporting DllRegisterServer, you can use regsvr.exe
STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	COleObjectFactory::UpdateRegistryAll();
	return _Module.RegisterServer(TRUE);

	return S_OK;
}

	
CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
END_OBJECT_MAP()

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return SELFREG_E_CLASS;
	_Module.UnregisterServer(TRUE); //TRUE indicates that typelib is unreg'd
	return S_OK;
}

int CERadSetQueueControllerApp::ExitInstance()
{
	_Module.Term();

	return CWinApp::ExitInstance();

}

BOOL CERadSetQueueControllerApp::InitATL()
{
	_Module.Init(ObjectMap, AfxGetInstanceHandle());
	return TRUE;

}

/////////////////////////////////////////////////////////////////////////////

BOOL LoadConfiguration()
{
	CSetSheet dlgSheet(IDR_MAINFRAME);
	dlgSheet.m_psh.dwFlags &= ~PSH_HASHELP;
	dlgSheet.m_psh.dwFlags |= PSH_NOAPPLYNOW;
	dlgSheet.m_psh.dwFlags |= PSH_PROPTITLE;

	CPageGeneral				dlgGeneral;
	CPageController				dlgController;

	dlgGeneral					.m_psp.dwFlags &= ~PSP_HASHELP;
	dlgController				.m_psp.dwFlags &= ~PSP_HASHELP;

	dlgSheet.AddPage(&dlgGeneral);
	dlgSheet.AddPage(&dlgController);

	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bLogTRACK,					CRunTime::GetGeneral()->m_bLogTRACK);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bLogDEBUG,					CRunTime::GetGeneral()->m_bLogDEBUG);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bLogERROR,					CRunTime::GetGeneral()->m_bLogERROR);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bLogMESSAGE,				CRunTime::GetGeneral()->m_bLogMESSAGE);

	SET_LEFT_FROM_RIGHT(dlgGeneral.m_nVoiceRate,				CRunTime::GetGeneral()->m_nVoiceRate);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_nVoiceVolume,				CRunTime::GetGeneral()->m_nVoiceVolume);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_strVoicePlay,				CRunTime::GetGeneral()->m_strVoicePlay);

	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bAutoLogin,				CRunTime::GetGeneral()->m_bAutoLogin);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_strAutoDoctorCode,			CRunTime::GetGeneral()->m_strAutoDoctorCode);
	SET_LEFT_FROM_RIGHT(dlgGeneral.m_bHideName,				    CRunTime::GetGeneral()->m_bHideName);

	if (dlgSheet.DoModal() == IDOK)
	{
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bLogTRACK,				CRunTime::GetGeneral()->m_bLogTRACK);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bLogDEBUG,				CRunTime::GetGeneral()->m_bLogDEBUG);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bLogERROR,				CRunTime::GetGeneral()->m_bLogERROR);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bLogMESSAGE,			CRunTime::GetGeneral()->m_bLogMESSAGE);

		SET_RIGHT_FROM_LEFT(dlgGeneral.m_nVoiceRate,			CRunTime::GetGeneral()->m_nVoiceRate);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_nVoiceVolume,			CRunTime::GetGeneral()->m_nVoiceVolume);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_strVoicePlay,			CRunTime::GetGeneral()->m_strVoicePlay);

		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bAutoLogin,			CRunTime::GetGeneral()->m_bAutoLogin);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_strAutoDoctorCode,		CRunTime::GetGeneral()->m_strAutoDoctorCode);
		SET_RIGHT_FROM_LEFT(dlgGeneral.m_bHideName,			    CRunTime::GetGeneral()->m_bHideName);

		CRunTime::ExchangeXML(TRUE);
	}

	return TRUE;
}

MRET DCMConfigurationSelect()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		LOG_RET_ERROR_MINOR(LL_ERROR | LD_ALL, ME_ERR_COINITIALIZE, hr);
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
		CoUninitialize();
		LOG_RET_ERROR(LL_ERROR | LD_ALL, rc);
	}

	rc = CRunTime::ExchangeXML();
	if (rc != ME_OK)
	{
		CoUninitialize();
		LOG_RET_ERROR(LL_ERROR | LD_ALL, rc);
	}

	LoadConfiguration();

	CoUninitialize();

	return ME_OK;
}

MRET DCMConfigurationTarget(LPCTSTR lpDatabase, LONG nNodeIndex, LPCTSTR lpNodeName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		LOG_RET_ERROR_MINOR(LL_ERROR | LD_ALL, ME_ERR_COINITIALIZE, hr);
	}

	CoUninitialize();

	return ME_OK;
}
