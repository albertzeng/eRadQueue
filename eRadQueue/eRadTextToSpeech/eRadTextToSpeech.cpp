// eRadTextToSpeech.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "eRadTextToSpeech.h"
#include "sapi.h"

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
// CERadTextToSpeechApp

BEGIN_MESSAGE_MAP(CERadTextToSpeechApp, CWinApp)
	//{{AFX_MSG_MAP(CERadTextToSpeechApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CERadTextToSpeechApp construction

CERadTextToSpeechApp::CERadTextToSpeechApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CERadTextToSpeechApp object

CERadTextToSpeechApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CERadTextToSpeechApp initialization

BOOL CERadTextToSpeechApp::InitInstance()
{
	// Register all OLE server (factories) as running.  This enables the
	//  OLE libraries to create objects from other applications.
	COleObjectFactory::RegisterAll();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// Special entry points required for inproc servers

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllGetClassObject(rclsid, riid, ppv);
}

STDAPI DllCanUnloadNow(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllCanUnloadNow();
}

// by exporting DllRegisterServer, you can use regsvr.exe
STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	COleObjectFactory::UpdateRegistryAll();
	return S_OK;
}


/////////////////////////////////////////////////////////////////////////////

MRET API_SpeakText(LPCTSTR lpSpeakContent, LONG nVoiceRate, LONG nVoiceVolume, LONG nVoiceClass, CString strVoiceDescription)
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

	ISpeechVoice pSpeechVoice;
	CLSID CLSID_SpVoice;
	LPDISPATCH pDispatch;
	CLSIDFromProgID(L"SAPI.SpVoice", &CLSID_SpVoice);
	ISpeechObjectTokens listVoice;

	pSpeechVoice.CreateDispatch(CLSID_SpVoice); 
	pDispatch = pSpeechVoice.m_lpDispatch; 
		
	hr = pDispatch->QueryInterface(CLSID_SpVoice, (void**)&pSpeechVoice.m_lpDispatch); 
		
	if (hr == S_OK) 
		pDispatch->Release(); 
	else		
		pSpeechVoice.AttachDispatch(pDispatch, TRUE); 

	pSpeechVoice.SetRate(nVoiceRate);
	pSpeechVoice.SetVolume(nVoiceVolume);

	listVoice = pSpeechVoice.GetVoices(NULL, NULL);
	ISpeechObjectToken itemVoice = listVoice.Item(nVoiceClass);
	if (strVoiceDescription != itemVoice.GetDescription(0))
	{
		for (LONG i = 0; i < listVoice.GetCount(); i++)
		{
			itemVoice = listVoice.Item(i);
			if (strVoiceDescription == itemVoice.GetDescription(0))
				break;
		}
	}

	pSpeechVoice.SetRefVoice(itemVoice);

	CString strSpeakContent = lpSpeakContent, strBuffer;
	LONG nStart = 0, nClose = 0;
	while (TRUE)
	{
		nStart = strSpeakContent.Find('<', 0);
		if (nStart == -1)
			break;

		nClose = strSpeakContent.Find('>', nStart + 1);
		if (nClose == -1)
			break;

		strBuffer = strSpeakContent.Left(nStart);
		pSpeechVoice.Speak(strBuffer, 0);

		strBuffer = strSpeakContent.Mid(nStart + 1, nClose - nStart - 1);
		if (!strBuffer.IsEmpty())
			::Sleep(atoi(strBuffer));

		strSpeakContent = strSpeakContent.Mid(nClose + 1);

	}

	pSpeechVoice.Speak(strSpeakContent, 0);

	CoUninitialize();

	return ME_OK;
}

MRET API_GetVoiceList(CStringArray *pArray)
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

	ISpeechVoice pSpeechVoice;
	CLSID CLSID_SpVoice;
	LPDISPATCH pDispatch;
	CLSIDFromProgID(L"SAPI.SpVoice", &CLSID_SpVoice);
	ISpeechObjectTokens listVoice;

	pSpeechVoice.CreateDispatch(CLSID_SpVoice); 
	pDispatch = pSpeechVoice.m_lpDispatch; 
		
	hr = pDispatch->QueryInterface(CLSID_SpVoice, (void**)&pSpeechVoice.m_lpDispatch); 
		
	if (hr == S_OK) 
		pDispatch->Release(); 
	else		
		pSpeechVoice.AttachDispatch(pDispatch, TRUE); 

	listVoice = pSpeechVoice.GetVoices(NULL, NULL);
	pArray->RemoveAll();

	for (LONG i = 0; i < listVoice.GetCount(); i++)
	{
		ISpeechObjectToken itemVoice = listVoice.Item(i);
		pArray->Add(itemVoice.GetDescription(0));
	}

	CoUninitialize();

	return ME_OK;
}