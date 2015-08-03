// eRadQueueCall.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "eRadQueueCall.h"
#include <initguid.h>
#include "ERadQueueCall_i.c"

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
// CERadQueueCallApp

BEGIN_MESSAGE_MAP(CERadQueueCallApp, CWinApp)
	//{{AFX_MSG_MAP(CERadQueueCallApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CERadQueueCallApp construction

CERadQueueCallApp::CERadQueueCallApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CERadQueueCallApp object

CERadQueueCallApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CERadQueueCallApp initialization

BOOL CERadQueueCallApp::InitInstance()
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

	HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		LOG_ERROR_MINOR(LL_ERROR | LD_FILE, ME_ERR_COINITIALIZE, hr);
		return FALSE;
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
		LOG_ERROR(LL_ERROR | LD_FILE, rc);
		return FALSE;
	}

	rc = CRunTime::ExchangeXML();
	if (rc != ME_OK)
	{
		CoUninitialize();
		LOG_ERROR(LL_ERROR | LD_FILE, rc);
		return FALSE;
	}

	CoUninitialize();

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

int CERadQueueCallApp::ExitInstance()
{
	_Module.Term();

	return CWinApp::ExitInstance();

}

BOOL CERadQueueCallApp::InitATL()
{
	_Module.Init(ObjectMap, AfxGetInstanceHandle());
	return TRUE;

}
